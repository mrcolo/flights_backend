//
// Created by Francesco Colonnese on 12/5/18.
//

#ifndef SIMPLE_WEB_SERVER_ENGINE_H
#define SIMPLE_WEB_SERVER_ENGINE_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include "./objects/Airport.h"
#include "./objects/Route.h"

class engine;

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

enum DATASET {AIRPORTS, ROUTES};

class engine {
public:
    engine();
    ~engine();

    std::string getMe(std::string start, std::string end);
    std::string getAirports();
    friend int minDistance(engine* e, int dist[], bool sptSet[]);

private:
    //std::vector<Airport> v_airports;
    std::vector<Route> v_routes;
    std::string airports_json;
    std::map<size_t, std::string> airport_pos;
    std::map<std::string, size_t> airport_name;

    int** adj_matrix;
    Airport** v_airports;
    size_t airport_size;

    void loadData(DATASET d);

    std::string processJsonAirports();
    void openAirports(std::ifstream& i);
    void openRoutes(std::ifstream& i);
    void loadAirports(std::vector<std::vector<std::string>>& airports);
    void loadRoutes(std::vector<std::vector<std::string>>& routes);

    void printSolution(int dist[]);
    void loadGraph();
    void printGraph();
    void computeDijkstra(int src, int* &directions);

    // alternate implementation
    std::vector<std::pair<int, int>> d; // distances (first = dist, second = prev index)
    int minDistance(bool sptSet[]); // uses vector of pairs "d"
    void dijkstra(int src); // uses adj_matrix
};

#endif //SIMPLE_WEB_SERVER_ENGINE_H
