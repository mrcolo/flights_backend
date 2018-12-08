//
// Created by Francesco Colonnese on 12/6/18.
//

#ifndef SIMPLE_WEB_SERVER_AIRPORT_H
#define SIMPLE_WEB_SERVER_AIRPORT_H
#include <iostream>

class Airport {
public:
    Airport();
    Airport(std::string& i, std::string& n, double& la, double& ln)
        : iata_code(i), name(n), lat(la), lng(ln) {}
    Airport(const Airport& a);
    Airport& operator=(const Airport& other);
    ~Airport();

    double Lat();
    double Long();
    std::string Iata();
    std::string Name();

private:
    std::string iata_code, name;
    double lat, lng;
};

#endif //SIMPLE_WEB_SERVER_AIRPORT_H
