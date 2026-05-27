#pragma once

#include <vector>
#include <fstream>
#include <string>
#include "Transport.h"

class Database
{
private:
    std::vector<Transport> transports;

public:
    void loadFromFile(std::string filename);
    void saveToFile(std::string filename);
    void showDatabase() const;
    void addTransport();
    void deleteTransport(unsigned int index);
    void sortByRouteNumber();
    void findByRouteNumber(unsigned int routeNumber) const;
    void filterByPrice(float minPrice, float maxPrice) const;
    void taskMinimumStops() const;
    void taskTravelTime(CTime maxTime) const;
};
