//
// Created by Francesco Colonnese on 12/6/18.
//

#include "Airport.h"
#include <iostream>
Airport::Airport(std::string i, std::string n, double la, double ln){
    iata_code = i;
    name = n;
    lat = la;
    lng = ln;
}

Airport::~Airport(){

}



Airport::Airport( const Airport& a ){
    lat = a.lat;
    lng = a.lng;
    iata_code = a.iata_code;
    name = a.name;
}

std::string Airport::Iata(){
    return iata_code;
}
std::string Airport::Name(){
    return name;
}

Airport& Airport::operator= (const Airport &other){
    lat = other.lat;
    lng = other.lng;
    iata_code = other.iata_code;
    name = other.name;
}


double Airport::Lat(){
    return lat;
}

double Airport::Long(){
    return lng;
}
