//
// Created by Francesco Colonnese on 12/5/18.
//

#ifndef SIMPLE_WEB_SERVER_ENGINE_H
#define SIMPLE_WEB_SERVER_ENGINE_H
#include <iostream>
#include <vector>
#include "./objects/Airport.h"
#include "./objects/Route.h"
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class engine;

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

enum DATASET {AIRPORTS, ROUTES};
class engine {

    public:
        engine();
        ~engine();
        engine( const engine& a );

        void getMe(std::string start, std::string end);

        std::string getAirports();
    private:
        std::vector<Airport> v_airports;
        std::vector<Route> v_routes;
        std::string airports_json;

        void loadData(DATASET d);

        std::string processJsonAirports();
        void openAirports(std::ifstream& i);
        void openRoutes(std::ifstream& i);
        void loadAirports(std::vector<std::vector<std::string>>& airports);
        void loadRoutes(std::vector<std::vector<std::string>>& routes);

        void computeDijkstra(double s_lat, double s_lng, double e_lat, double e_lng);

};


#endif //SIMPLE_WEB_SERVER_ENGINE_H
