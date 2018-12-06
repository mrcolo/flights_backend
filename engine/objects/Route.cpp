//
// Created by Francesco Colonnese on 12/6/18.
//

#include "Route.h"

Route::Route(std::string& a_name,
             std::string& a_iata,
             std::string& s_name,
             std::string& s_iata,
             double& s_lat,
             double& s_lng,
             std::string& d_name,
             std::string& d_iata,
             double& d_lat,
             double& d_lng,
             double& dis, double& hrs){

    airline_name = a_name;
    airline_iata = a_iata;
    source_name = s_name;
    source_iata = s_iata;
    source_lat = s_lat;
    source_lng = s_lng;
    destination_name = d_name;
    destination_iata = d_iata;
    destination_lat = d_lat;
    destination_lng = d_lng;
    distances_mi = dis;
    times_hr = hrs;


}

void Route::output(){
    std::cout<<source_name<<" to "<<destination_name<<std::endl;
}

Route::~Route(){

}
