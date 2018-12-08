//
// Created by Francesco Colonnese on 12/5/18.
//

#include "engine.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <queue>

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

engine::engine() {

    std::cout << "Starting to load the engine..." << std::endl;
    loadData(AIRPORTS);

    loadData(ROUTES);

    adj_matrix = new int*[airport_size];

    for (size_t i = 0; i < airport_size; ++i)
        adj_matrix[i] = new int[airport_size];

    for (size_t j = 0; j < airport_size; ++j) {
        for (size_t v = 0; v < airport_size; ++v) {
            adj_matrix[j][v] = 0;
        }
    }

    loadGraph();

    std::cout<<"Processed data..."<<std::endl;
    //airports_json = processJsonAirports();
    std::cout<<"Json is ready."<<std::endl;

}

engine::~engine() {
    for (size_t i = 0; i < airport_size; ++i)
        delete [] adj_matrix[i];

    delete [] v_airports;

    delete [] adj_matrix;

}

std::string engine::getMe(std::string start, std::string end){
        //printProgress((100*x)/airport_size);
    if(start.length() == 3 && end.length() == 3){
        auto previous = new int[airport_size];

        for(int i = 0; i < airport_size; i++)
            previous[i] = -1;

        unsigned long source = airport_name[start];

        computeDijkstra(source, previous);

        std::vector<int> results;

        unsigned long target = airport_name[end];

        //Push the itinerary.
        for (int i = target; i != source; i = previous[i]) {
            if (!airport_pos[i].empty())
                results.push_back(i);
            else {
                results.clear();
                break;
            }
        }

        if (!results.empty()) {

            //Finally, push the source in the stack.
            results.push_back(source);

            ptree arr;
            ptree temp;
            //out result.
            int count = 0;
            for (unsigned long i = results.size() - 1; i > 0; --i) {

                temp.put<std::string>("iata_code", v_airports[results[i]]->Iata());
                temp.put<std::string>("name", v_airports[results[i]]->Name());
                temp.put<double>("lat", v_airports[results[i]]->Lat());
                temp.put<double>("lng", v_airports[results[i]]->Long());

                arr.push_back(std::make_pair(std::to_string(count), temp));
                count++;
                //DEBUG: std::cout<<"("<<airport_pos[results[i]]<<")"<<" -> ";
            }

            temp.put<std::string>("iata_code", v_airports[target]->Iata());
            temp.put<std::string>("name", v_airports[target]->Name());
            temp.put<double>("lat", v_airports[target]->Lat());
            temp.put<double>("lng", v_airports[target]->Long());
            arr.push_back(std::make_pair(std::to_string(results.size() - 1), temp));
            std::stringstream ss;

            write_json(ss, arr);
            std::string JSON = ss.str();

            return JSON;

        }

    }
    else{
        ptree temp;
        std::stringstream ss;
        temp.put<std::string>("auth", "false");
        write_json(ss, temp);
        std::string JSON = ss.str();

        return JSON;
    }

}

std::string engine::getAirports() {
    return airports_json;
}

void engine::openAirports(std::ifstream& i){
//WHEN EXECUTING FROM MAIN    i.open("../data/airports_iata.csv");
/*WHEN EXECUTING FROM WEBSERVER*/    i.open("./data/airports_iata.csv");
}

void engine::openRoutes(std::ifstream& i) {
    //WHEN EXECUTING FROM MAIN    i.open("../data/routes_final.csv");
/*WHEN EXECUTING FROM WEBSERVER*/    i.open("./data/routes_final.csv");
}

void engine::loadAirports(std::vector<std::vector<std::string>>& airports) {
    airport_size = airports.size();

    v_airports = new Airport*[airport_size];

    for (size_t i = 0; i < airports.size(); ++i) {

        std::stringstream ss;
        if (airports[i].size() == 7){
            ss<<airports[i][2].substr(0,10);
            double lat;
            ss>>lat;

            ss.clear();

            ss<<airports[i][3].substr(0,10);
            double lng;
            ss>>lng;

            airport_pos[i] = airports[i][0];
            airport_name[airports[i][0]] = i;
            v_airports[i] = new Airport(airports[i][0], airports[i][1], lat, lng);;
        }
    }
}

void engine::loadRoutes(std::vector<std::vector<std::string>>& routes){
    // 0 -> airline_name,
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

    for (auto &route : routes) {
        std::stringstream ss;

        if (route.size() == 12) {
            ss << route[4].substr(0,10);
            double s_lat;
            ss >> s_lat;
            ss.clear();

            ss << route[5].substr(0,10);
            double s_lng;
            ss >> s_lng;
            ss.clear();

            ss << route[8].substr(0,10);
            double d_lat;
            ss >> d_lat;
            ss.clear();

            ss << route[9].substr(0,10);
            double d_lng;
            ss >> d_lng;
            ss.clear();

            ss << route[10].substr(0,10);
            double dis;
            ss >> dis;
            ss.clear();

            ss << route[11].substr(0,10);
            double hrs;
            ss>>hrs;

            v_routes.emplace_back(Route(
                    route[0], route[1],
                    route[2], route[3],
                    s_lat, s_lng,
                    route[6], route[7],
                    d_lat, d_lng,
                    dis, hrs));
        }
    }
}

void printProgress (double percentage)
{
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf ("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush (stdout);
}

void engine::loadGraph(){

    for (auto &route : v_routes) {
        size_t from = airport_name[route.getFrom()];
        size_t to = airport_name[route.getTo()];
        adj_matrix[from][to] = (int)(route.getTime()*100);
        adj_matrix[to][from] = (int)(route.getTime()*100);
    }

    //printGraph();
}

void engine::printGraph() {
    size_t one = airport_name["LAX"], two = airport_name["MEL"];
    std::cout << "DEMO: " << adj_matrix[one][two] << std::endl;

    for (size_t v = two - 8; v < two + 4; ++v) {
        std::cout << std::setw(5) << airport_pos[v];
    }

    std::cout << std::endl;

    for (size_t v = one - 1; v < one + 11; ++v) {
        std::cout << std::setw(5) << airport_pos[v];

        for (size_t j = two - 8; j < two + 4; ++j) {
            if (adj_matrix[v][j] != INT_MAX)
                std::cout << std::setw(5) << adj_matrix[v][j];
            else
                std::cout << std::setw(5) << 'X';
        }
        std::cout << std::endl;
    }
}

std::string engine::processJsonAirports() {
    ptree arr;


    for (size_t j = 0; j < airport_size; ++j) {
        ptree temp;
        temp.put<std::string>("iata_code", v_airports[j]->Iata());
        temp.put<std::string>("name", v_airports[j]->Name());
        temp.put<double>("lat", v_airports[j]->Lat());
        temp.put<double>("lng",v_airports[j]->Long());

        arr.push_back( std::make_pair(std::to_string(j), temp));
    }
    std::stringstream ss;
    write_json(ss, arr);

    return ss.str();
}

std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str) {
    std::vector<std::string> result;
    std::string line, cell;

    std::getline(str,line);
    std::stringstream lineStream(line);

    while (std::getline(lineStream, cell, ',')) {
        result.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty()) {
        // If there was a trailing comma then add an empty element.
        result.emplace_back("");
    }
    return result;
}

void engine::loadData(DATASET d) {
    std::ifstream i;
    d ? openRoutes(i) : openAirports(i);

    if (i) {
        std::vector<std::vector<std::string>> data;
        std::string line;
//        std::string header;
        std::stringstream ss;

        // first get rid of header line
//        std::getline(i, header);

        while(std::getline(i, line)) {
            ss << line;
            data.push_back(getNextLineAndSplitIntoTokens(ss));
            ss.clear();
        }
        d ? loadRoutes(data) : loadAirports(data);
    }

    i.close();
}

int minDistance(engine* e, int dist[], bool sptSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index = 0;

    for (int v = 0; v < e->airport_size; ++v) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void engine::printSolution(int dist[]) {
    for (size_t i = 0; i < airport_size; i++) {
        if (dist[i] != INT_MAX) {
            std::cout << "For " << airport_pos[i] << std::endl
                      << "\tApproximately " << dist[i] / 100 << " hours."
                      << std::endl;
        }
    }
}

void engine::computeDijkstra(int src,int* &previous) {

    //shortest path tree
    int distances[airport_size];

    //true if it was visited
    bool sptSet[airport_size];

    //All vertexes are initialized as infinite. nothing is visited.
    for (size_t i = 0; i < airport_size; ++i) {
        distances[i] = INT_MAX;
        sptSet[i] = false;
    }

    //First distance is 0...we are already here.
    distances[src] = 0;

    //Iterate through all the airports.

//TODO think about the -1 in airport_size

    for (int count = 0; count < airport_size - 1; ++count) {
        //pick adjacent vertex with the minimum distance.
        //This is the current node.

        int current = minDistance(this, distances, sptSet);
        // Mark the picked vertex as processed
        sptSet[current] = true;

        // Visit adjacent vertices and change their values
        // (such as from infinite to another number).
        for (int adj = 0; adj < airport_size; ++adj) {
            // Assign new value to adjacent if:
            //   1. The vertex was not visited yet.
            //   2. The path is actually shorter than the one that was already there.
            if (!sptSet[adj] &&
                adj_matrix[current][adj] &&
                distances[adj] == INT_MAX &&
                distances[current] + adj_matrix[current][adj] < distances[adj]){
                previous[adj] = current;
                // change the value!
                distances[adj] = distances[current] + adj_matrix[current][adj];
            }
        }
    }
    //printSolution(distances);
}