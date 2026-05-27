#pragma once
#include <string>

struct CTime
{
    unsigned short hour;
    unsigned short minute;
    unsigned short second;
};

class Transport
{
private:
    unsigned int routeNumber;
    std::string transportType;
    float price;
    CTime travelTime;
    unsigned int stops;
    std::string departure;
    std::string destination;

public:
    Transport();

    Transport(
        unsigned int routeNumber,
        std::string transportType,
        float price,
        CTime travelTime,
        unsigned int stops,
        std::string departure,
        std::string destination
    );

    void print() const;

    unsigned int getRouteNumber() const;
    std::string getTransportType() const;
    float getPrice() const;
    CTime getTravelTime() const;
    unsigned int getStops() const;
    std::string getDeparture() const;
    std::string getDestination() const;
};