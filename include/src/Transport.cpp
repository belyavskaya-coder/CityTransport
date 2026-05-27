#include "../Transport.h"
#include <iostream>
#include <iomanip>
#include <string>

Transport::Transport() = default;

Transport::Transport(
    unsigned int routeNumber,
    std::string transportType,
    float price,
    CTime travelTime,
    unsigned int stops,
    std::string departure,
    std::string destination
)
{
    this->routeNumber = routeNumber;
    this->transportType = transportType;
    this->price = price;

    this->travelTime = travelTime;
    this->stops = stops;
    this->departure = departure;
    this->destination = destination;
}

void Transport::print() const
{
    std::cout << std::left;

    std::cout << std::setw(10) << routeNumber;
    std::cout << std::setw(15) << transportType;
    std::cout << std::setw(10) << price;

    std::cout << travelTime.hour << ":"
              << travelTime.minute << ":"
              << travelTime.second;

    std::cout << std::setw(10) << " "
              << std::setw(10) << stops;

    std::cout << std::setw(15) << departure;
    std::cout << std::setw(15) << destination;

    std::cout << std::endl;
}

unsigned int Transport::getRouteNumber() const { return routeNumber; }
std::string Transport::getTransportType() const { return transportType; }
float Transport::getPrice() const { return price; }
CTime Transport::getTravelTime() const { return travelTime; }
unsigned int Transport::getStops() const { return stops; }
std::string Transport::getDeparture() const { return departure; }
std::string Transport::getDestination() const { return destination; }
