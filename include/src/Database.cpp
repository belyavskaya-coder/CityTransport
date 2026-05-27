#include "../Database.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

void Database::loadFromFile(string filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Файл не найден!" << endl;
        return;
    }

    transports.clear();

    unsigned int routeNumber;
    string transportType;
    float price;

    CTime travelTime;

    unsigned int stops;

    string departure;
    string destination;

    while (
        file >> routeNumber
        >> transportType
        >> price
        >> travelTime.hour
        >> travelTime.minute
        >> travelTime.second
        >> stops
        >> departure
        >> destination
    )
    {
        Transport transport(
            routeNumber,
            transportType,
            price,
            travelTime,
            stops,
            departure,
            destination
        );

        transports.push_back(transport);
    }

    cout << "База данных загружена!" << endl;

    file.close();
}

void Database::saveToFile(string filename)
{
    ofstream file(filename);

    for (const auto& transport : transports)
    {
        CTime time = transport.getTravelTime();

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
            << endl;
    }

    file.close();

    cout << "База данных сохранена!" << endl;
}

void Database::showDatabase() const
{
    cout << left;

    cout
        << setw(10) << "Рейс"
        << setw(15) << "Тип"
        << setw(10) << "Цена"
        << setw(15) << "Время"
        << setw(10) << "Ост."
        << setw(15) << "Откуда"
        << setw(15) << "Куда"
        << endl;

    for (const auto& transport : transports)
    {
        transport.print();
    }
}

void Database::addTransport()
{
    unsigned int routeNumber;
    string transportType;
    float price;

    CTime travelTime;

    unsigned int stops;

    string departure;
    string destination;

    cout << "Номер рейса: ";
    cin >> routeNumber;

    cout << "Тип транспорта: ";
    cin >> transportType;

    cout << "Стоимость: ";
    cin >> price;

    cout << "Часы: ";
    cin >> travelTime.hour;

    cout << "Минуты: ";
    cin >> travelTime.minute;

    cout << "Секунды: ";
    cin >> travelTime.second;

    cout << "Количество остановок: ";
    cin >> stops;

    cout << "Пункт отправления: ";
    cin >> departure;

    cout << "Пункт прибытия: ";
    cin >> destination;

    Transport transport(
        routeNumber,
        transportType,
        price,
        travelTime,
        stops,
        departure,
        destination
    );

    transports.push_back(transport);

    cout << "Рейс добавлен!" << endl;
}

void Database::deleteTransport(unsigned int index)
{
    if (index >= transports.size())
    {
        cout << "Неверный номер!" << endl;
        return;
    }

    transports.erase(transports.begin() + index);

    cout << "Рейс удалён!" << endl;
}

void Database::sortByRouteNumber()
{
    sort(
        transports.begin(),
        transports.end(),
        [](const Transport& a, const Transport& b)
        {
            return a.getRouteNumber() < b.getRouteNumber();
        }
    );

    cout << "Сортировка выполнена!" << endl;
}

void Database::findByRouteNumber(unsigned int routeNumber) const
{
    for (const auto& transport : transports)
    {
        if (transport.getRouteNumber() == routeNumber)
        {
            transport.print();
            return;
        }
    }

    cout << "Рейс не найден!" << endl;
}

void Database::filterByPrice(float minPrice, float maxPrice) const
{
    for (const auto& transport : transports)
    {
        if (transport.getPrice() >= minPrice &&
            transport.getPrice() <= maxPrice
        )
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
            if (
                transports[i].getDeparture() ==
                transports[j].getDeparture()
                &&
                transports[i].getDestination() ==
                transports[j].getDestination()
                &&
                transports[j].getStops() <
                transports[i].getStops()
            )
            {
                minimum = false;
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
                << endl;
        }
    }

    file.close();

    cout << "Новая база данных создана!" << endl;
}