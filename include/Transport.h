#pragma once
#include <iostream>
#include <string>
using namespace std;
struct CTime
{
    unsigned short int hour;
    unsigned short int minute;
    unsigned short int second;
};

class Transport
{ 
private:

    unsigned int routeNumber;
    string transportType;
    float price;
    CTime travelTime;
    unsigned int stops;
    string departure;
    string destination;

  public:
      Transport();
      
      Transport(
        unsigned int routeNumber,
        string transportType,
        float price,
        CTime travelTime,
        unsigned int stops,
        string departure,
        string destination
      );
      void print() const;

        unsigned int getRouteNumber() const;
        string getTransportType() const;
        float getPrice() const;
        CTime getTravelTime() const;
        unsigned int getStops() const;
        string getDeparture() const;
        string getDestination() const;
        
    };


      












