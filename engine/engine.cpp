//
// Created by Francesco Colonnese on 12/5/18.
//

#include "engine.h"
#include <vector>
#include <sstream>
#include <fstream>
engine::engine(){
    std::cout<<"Starting to load the engine..."<<std::endl;
    loadData();
    std::cout<<"Processed data..."<<std::endl;
    airports_json = processJsonAirports();
    std::cout<<"Json is ready."<<std::endl;
}

engine::~engine(){

}

engine::engine( const engine& a ){

}

void engine::getMe(std::string start, std::string end){

}

std::string engine::getAirports(){
    return airports_json;
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


std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)
{
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

void returnAirportsJson() {
    //todo return the json of the airports.
}

void engine::loadData(){
    std::ifstream i;
    i.open("./data/airports_iata.csv");

    if(i){
        std::vector<std::vector<std::string>> airports;

        std::string line;
        std::stringstream ss;

        while(std::getline(i, line)){
            ss << line;
            airports.push_back(getNextLineAndSplitIntoTokens(ss));
            ss.clear();
        }

        for (int j = 0; j < airports.size(); ++j) {
                std::stringstream ss;
                ss<<airports[j][2].substr(0,10);
                double lat;
                ss>>lat;

                ss.clear();

                ss<<airports[j][3].substr(0,10);
                double lng;
                ss>>lng;


                v_airports.emplace_back(Airport(airports[j][0],airports[j][1],lat,lng));
                //v_airports[airports[j][0]] = a;
        }

    }
}

void engine::computeDijkstra(double s_lat, double s_lng, double e_lat, double e_lng){

}