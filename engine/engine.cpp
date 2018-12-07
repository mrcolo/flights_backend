//
// Created by Francesco Colonnese on 12/5/18.
//

#include "engine.h"
#include <vector>
#include <sstream>
#include <fstream>
engine::engine(){


    std::cout<<"Starting to load the engine..."<<std::endl;
    loadData(AIRPORTS);
    loadData(ROUTES);

    adj_matrix = new int*[airport_size];

    for(int i = 0; i < airport_size; ++i)
        adj_matrix[i] = new int[airport_size];

    for (int j = 0; j < airport_size; ++j) {
        for (int v = 0; v < airport_size; ++v) {
            adj_matrix[j][v] = INT_MAX;
        }
    }

    loadGraph();
    std::cout<<"Processed data..."<<std::endl;
    //airports_json = processJsonAirports();
    std::cout<<"Json is ready."<<std::endl;

}

engine::~engine(){
    for(int i = 0; i < airport_size; ++i)
        delete [] adj_matrix[i];

    delete [] adj_matrix;
}

engine::engine( const engine& a ){

}

void engine::getMe(std::string start, std::string end){

}

std::string engine::getAirports(){
    return airports_json;
}

void engine::openAirports(std::ifstream& i){
    i.open("../data/airports_iata.csv");
}

void engine::openRoutes(std::ifstream& i){
    i.open("../data/routes_final.csv");
}

void engine::loadAirports(std::vector<std::vector<std::string>>& airports){
    airport_size = airports.size();
    for (int j = 0; j < airports.size(); ++j) {
        std::stringstream ss;
        if(airports[j].size() == 7){
            ss<<airports[j][2].substr(0,10);
            double lat;
            ss>>lat;

            ss.clear();

            ss<<airports[j][3].substr(0,10);
            double lng;
            ss>>lng;

            airport_pos[j] = airports[j][0];
            airport_name[airports[j][0]] = j;
            //v_airports.emplace_back(Airport(airports[j][0],airports[j][1],lat,lng));
        }

    }
}

void engine::loadRoutes(std::vector<std::vector<std::string>>& routes){
    //0 -> airline_name,
    // 1 -> airline_iata,
    // 2 -> source_name,
    // 3 -> source_iata,
    // x 4 -> source_lat,
    // x 5 -> source_lng,
    // 6 -> destination_name,
    // 7 -> destination_iata,
    // x 8 -> destination_lat,
    // x 9 -> destination_lng,
    // x 10 -> distances_mi,
    // x 11 -> times_hr


    for (int j = 0; j < routes.size(); ++j) {
        std::stringstream ss;

        if(routes[j].size() == 12){
            ss<<routes[j][4].substr(0,10);
            double s_lat;
            ss>>s_lat;

            ss.clear();

            ss<<routes[j][5].substr(0,10);
            double s_lng;
            ss>>s_lng;

            ss.clear();

            ss<<routes[j][8].substr(0,10);
            double d_lat;
            ss>>d_lat;

            ss.clear();

            ss<<routes[j][9].substr(0,10);
            double d_lng;
            ss>>d_lng;

            ss.clear();

            ss<<routes[j][10].substr(0,10);
            double dis;
            ss>>dis;

            ss.clear();

            ss<<routes[j][11].substr(0,10);
            double hrs;
            ss>>hrs;

            v_routes.emplace_back(Route(routes[j][0],
                                        routes[j][1],
                                        routes[j][2],
                                        routes[j][3],
                                        s_lat,
                                        s_lng,
                                        routes[j][6],
                                        routes[j][7],
                                        d_lat,
                                        d_lng,
                                        dis,
                                        hrs
            ));
        }
    }
}

void engine::loadGraph(){

    for(int j = 0; j < v_routes.size(); ++j){
        int from = airport_name[v_routes[j].getFrom()];
        int to = airport_name[v_routes[j].getTo()];

        adj_matrix[from][to] = (int)(v_routes[j].getTime()*100);
        adj_matrix[to][from] = (int)(v_routes[j].getTime()*100);
    }

    printGraph();
}

void engine::printGraph(){
    int one = airport_name["LAX"], two = airport_name["JFK"];
    std::cout<<"DEMO: "<<adj_matrix[one][two]<<std::endl;
    std::cout<<'\t';

    for (int v = two - 8; v < two + 4; ++v){
        std::cout<<std::setw(5)<<airport_pos[v];
    }

    std::cout<<'\n';

    for (int v = one - 1; v < one + 11; ++v){
        std::cout <<std::setw(5)<<airport_pos[v];
        for (int j = two - 8; j < two + 4; ++j){
            if(adj_matrix[v][j] != INT_MAX)
                std::cout<< std::setw(5) <<adj_matrix[v][j];
            else
                std::cout<< std::setw(5)<< 'X';

        }

        printf("\n");
    }

}

std::string engine::processJsonAirports(){
    ptree arr;

    for (int j = 0; j < v_airports.size(); ++j) {
        ptree temp;
        temp.put<std::string>("iata_code", v_airports[j].Iata());
        temp.put<std::string>("name", v_airports[j].Name());
        temp.put<double>("lat", v_airports[j].Lat());
        temp.put<double>("lng",v_airports[j].Long());

        arr.push_back( std::make_pair(std::to_string(j), temp));
    }

    std::stringstream ss;

    write_json(ss, arr);
    return ss.str();
}


std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str){
    std::vector<std::string>   result;
    std::string                line;
    std::getline(str,line);

    std::stringstream          lineStream(line);
    std::string                cell;

    while(std::getline(lineStream,cell, ','))
    {
        result.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty())
    {
        // If there was a trailing comma then add an empty element.
        result.push_back("");
    }

    return result;
}

void engine::loadData(DATASET d){

    std::ifstream i;
    if(d)
        openRoutes(i);
    else
        openAirports(i);

    if(i){
        std::vector<std::vector<std::string>> data;

        std::string line;
        std::stringstream ss;

        while(std::getline(i, line)){
            ss << line;
            data.push_back(getNextLineAndSplitIntoTokens(ss));
            ss.clear();
        }


        if(d)
            loadRoutes(data);
        else
            loadAirports(data);
    }

    i.close();
}

void engine::computeDijkstra(double s_lat, double s_lng, double e_lat, double e_lng){
//    int dist[airport_size];     // The output array.  dist[i] will hold the shortest
//    // distance from src to i
//
//    bool sptSet[airport_size]; // sptSet[i] will be true if vertex i is included in shortest
//    // path tree or shortest distance from src to i is finalized
//
//    // Initialize all distances as INFINITE and stpSet[] as false
//    for (int i = 0; i < airport_size; i++)
//        dist[i] = INT_MAX, sptSet[i] = false;
//
//    // Distance of source vertex from itself is always 0
//    dist[src] = 0;
//
//    // Find shortest path for all vertices
//    for (int count = 0; count < airport_size-1; count++)
//    {
//        // Pick the minimum distance vertex from the set of vertices not
//        // yet processed. u is always equal to src in the first iteration.
//        int u = minDistance(dist, sptSet);
//
//        // Mark the picked vertex as processed
//        sptSet[u] = true;
//
//        // Update dist value of the adjacent vertices of the picked vertex.
//        for (int v = 0; v < airport_size; v++)
//
//            // Update dist[v] only if is not in sptSet, there is an edge from
//            // u to v, and total weight of path from src to  v through u is
//            // smaller than current value of dist[v]
//            if (!sptSet[v] && adj_matrix[u][v] && dist[u] != INT_MAX
//                && dist[u]+ adj_matrix[u][v] < dist[v])
//                dist[v] = dist[u] + adj_matrix[u][v];
//    }

    // print the constructed distance array
    //printSolution(dist, V);
}