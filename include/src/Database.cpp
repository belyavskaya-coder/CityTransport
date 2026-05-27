#include "Database.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

void Database::filterByPrice(float minPrice, float maxPrice) const
{
    for (const auto& transport : transports)
    {
        if (transport.getPrice() >= minPrice &&
            transport.getPrice() <= maxPrice)
        {
            transport.print();
        }
    }
}

void Database::taskMinimumStops() const
{
    for (size_t i = 0; i < transports.size(); i++)
    {
        bool minimum = true;

        for (size_t j = 0; j < transports.size(); j++)
        {
            if (i != j &&
                transports[i].getDeparture() == transports[j].getDeparture() &&
                transports[i].getDestination() == transports[j].getDestination() &&
                transports[j].getStops() < transports[i].getStops())
            {
                minimum = false;
                break;
            }
        }

        if (minimum)
        {
            transports[i].print();
        }
    }
}

void Database::taskTravelTime(CTime maxTime) const
{
    ofstream file("data/new_database.txt");

    if (!file.is_open())
    {
        cout << "Ошибка создания файла!" << endl;
        return;
    }

    for (const auto& transport : transports)
    {
        CTime time = transport.getTravelTime();

        int currentSeconds =
            time.hour * 3600 +
            time.minute * 60 +
            time.second;

        int maxSeconds =
            maxTime.hour * 3600 +
            maxTime.minute * 60 +
            maxTime.second;

        if (currentSeconds <= maxSeconds)
        {
            file
                << transport.getRouteNumber() << " "
                << transport.getTransportType() << " "
                << transport.getPrice() << " "
                << time.hour << " "
                << time.minute << " "
                << time.second << " "
                << transport.getStops() << " "
                << transport.getDeparture() << " "
                << transport.getDestination()
                << "\n";
        }
    }

    cout << "Новая база данных создана!" << endl;
}
