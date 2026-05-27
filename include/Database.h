#pragma once
#include <vector>
#include <fstream>
#include "Transport.h"


#pragma once

#include <vector>
#include <fstream>
#include "Transport.h"

using namespace std;

class Database
{
private:
    vector<Transport> transports;

public:
    void loadFromFile(string filename);
    void saveToFile(string filename);
    void showDatabase() const;
    void addTransport();
    void deleteTransport(unsigned int index);
    void sortByRouteNumber();
    void findByRouteNumber(unsigned int routeNumber) const;
    void filterByPrice(float minPrice, float maxPrice) const;
    void taskMinimumStops() const;
    void taskTravelTime(CTime maxTime) const;
};