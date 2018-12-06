//
// Created by Francesco Colonnese on 12/5/18.
//

#ifndef SIMPLE_WEB_SERVER_ENGINE_H
#define SIMPLE_WEB_SERVER_ENGINE_H
#include <iostream>

class engine {

    public:
        engine();
        ~engine();
        engine( const engine& a );

        void getMe(std::string start, std::string end);

    private:
        std::string start, end;
        void computeDijkstra(double s_lat, double s_lng, double e_lat, double e_lng);

};


#endif //SIMPLE_WEB_SERVER_ENGINE_H
