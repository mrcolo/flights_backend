//
// Created by Francesco Colonnese on 12/6/18.
//

#ifndef SIMPLE_WEB_SERVER_ROUTE_H
#define SIMPLE_WEB_SERVER_ROUTE_H
#include <iostream>

class Route {

public:
    Route(std::string& a_name,
          std::string& a_iata,
          std::string& s_name,
          std::string& s_iata,
          double& s_lat,
          double& s_lng,
          std::string& d_name,
          std::string& d_iata,
          double& d_lat,
          double& d_lng,
          double& dis, double& hrs
          );

    void output();

    ~Route();

private:
    std::string airline_name,
                airline_iata,
                source_name,
                source_iata,
                destination_name,
                destination_iata;

    double source_lat,source_lng,destination_lat,destination_lng,distances_mi,times_hr;

};


#endif //SIMPLE_WEB_SERVER_ROUTE_H
