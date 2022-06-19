//
// Created by Lu Jun on 1/14/22.
//

#ifndef UDP2RAW_PORT_MANAGER_H
#define UDP2RAW_PORT_MANAGER_H

#include <vector>
#include <string.h>

class PortsManager {

    std::vector<int> ports;
    int index;
    char raw_ports[1000];

public:
    PortsManager(const char* ports){
        this->load(ports);
    }

    PortsManager(){
        this->index = 0;
    }

    void load(const char* ports){
        strcpy(this->raw_ports, ports);
        this->ports.clear();
        char tmp[1000];

        strcpy(tmp, ports);
        char * token = strtok(tmp, ",");
        while( token != NULL ) {
            int port = atoi(token);
            this->ports.push_back(port);
            token = strtok(NULL, ",");
        }
        this->index = 0;
    }

    int getNextPort() {
        const int length = this->ports.size();
        this->index = (this->index + 1) % length;
        return this->ports[this->index];
    }

    const char* getPorts() {
        return this->raw_ports;
    }

};

#endif //UDP2RAW_PORT_MANAGER_H
