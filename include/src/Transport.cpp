#include "../Transport.h"
#include <iomanip>
#include <sstream>

Transport::Transport()
{

}Transport::Transport(
    unsigned int routeNumber,
    string transportType,
    float price,
    CTime travelTime,
    unsigned stops,
    string departure,
    string destination
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
    cout << left;

    cout << setw(10) << routeNumber;
    cout << setw(15) << transportType;
    cout << setw(10) << price;

    cout << travelTime.hour << ":";
    cout << travelTime.minute << ":";
    cout << setw(10) << travelTime.second;

    cout << setw(10) << stops;
    cout << setw(15) << departure;
    cout << setw(15) << destination;

    cout << endl;
}

unsigned int Transport::getRouteNumber() const
{
    return routeNumber;
}

string Transport::getTransportType() const
{
    return transportType;
}

float Transport::getPrice() const
{
    return price;
}

CTime Transport::getTravelTime() const
{
    return travelTime;
}

unsigned int Transport::getStops() const
{
    return stops;
}

string Transport::getDeparture() const
{
    return departure;
}

string Transport::getDestination() const
{
    return destination;
}
