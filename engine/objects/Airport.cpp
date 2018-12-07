//
// Created by Francesco Colonnese on 12/6/18.
//

#include "Airport.h"

Airport::Airport(const Airport& a) {
    iata_code = a.iata_code;
    name = a.name;
    lat = a.lat;
    lng = a.lng;
}

Airport& Airport::operator=(const Airport &other) {
    if (this != &other) {
        iata_code = other.iata_code;
        name = other.name;
        lat = other.lat;
        lng = other.lng;
    }
    return *this;
}

Airport::~Airport() = default;

std::string Airport::Iata() {
    return iata_code;
}

std::string Airport::Name() {
    return name;
}

double Airport::Lat(){
    return lat;
}

double Airport::Long(){
    return lng;
}
