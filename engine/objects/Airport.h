//
// Created by Francesco Colonnese on 12/6/18.
//
#include <iostream>

#ifndef SIMPLE_WEB_SERVER_AIRPORT_H
#define SIMPLE_WEB_SERVER_AIRPORT_H


class Airport {
public:
    Airport(std::string i, std::string n, double la, double ln);
    Airport& operator= (const Airport &other);
    bool operator <(const Airport& rhs) const
    {
        return iata_code < rhs.iata_code;
    }
    ~Airport();
    Airport( const Airport& a );
    double Lat();
    double Long();
    std::string Iata();
    std::string Name();
private:
    std::string iata_code, name;
    double lat, lng;

};

#endif //SIMPLE_WEB_SERVER_AIRPORT_H
