#include "../Database.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

void Database::loadFromFile(std::string filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Ошибка открытия файла для чтения: " << filename << endl;
        return;
    }
    transports.clear();
    unsigned int routeNumber;
    std::string transportType;
    float price;
    CTime travelTime;
    unsigned int stops;
    std::string departure;
    std::string destination;

    while (inFile >> routeNumber >> transportType >> price 
                  >> travelTime.hour >> travelTime.minute >> travelTime.second 
                  >> stops >> departure >> destination) 
    {
        Transport temp(routeNumber, transportType, price, travelTime, stops, departure, destination);
        transports.push_back(temp);
    }
    inFile.close();
    cout << "База данных успешно загружена!" << endl;
}

void Database::saveToFile(std::string filename)
{
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Ошибка открытия файла для записи: " << filename << endl;
        return;
    }
    for (const auto& t : transports) {
        CTime time = t.getTravelTime();
        outFile << t.getRouteNumber() << " "
                << t.getTransportType() << " "
                << t.getPrice() << " "
                << time.hour << " " << time.minute << " " << time.second << " "
                << t.getStops() << " "
                << t.getDeparture() << " "
                << t.getDestination() << "\n";
    }
    outFile.close();
    cout << "База данных успешно сохранена!" << endl;
}

void Database::showDatabase() const
{
    if (transports.empty()) {
        cout << "База данных пуста." << endl;
        return;
    }
    cout << "\n--------------------------------------------------------------------------------------\n";
    cout << "№ Рейса   Тип            Цена      Время       Остановки  Откуда         Куда\n";
    cout << "--------------------------------------------------------------------------------------\n";
    for (const auto& t : transports) {
        t.print();
    }
    cout << "--------------------------------------------------------------------------------------\n";
}

void Database::addTransport()
{
    unsigned int routeNumber;
    std::string transportType;
    float price;
    CTime travelTime;
    unsigned int stops;
    std::string departure;
    std::string destination;

    cout << "Введите номер рейса: "; std::cin >> routeNumber;
    cout << "Введите тип транспорта: "; std::cin >> transportType;
    cout << "Введите стоимость проезда: "; std::cin >> price;
    cout << "Введите время в пути (Часы Минуты Секунды): "; 
    std::cin >> travelTime.hour >> travelTime.minute >> travelTime.second;
    cout << "Введите количество остановок: "; std::cin >> stops;
    cout << "Введите пункт отправления: "; std::cin >> departure;
    cout << "Введите пункт назначения: "; std::cin >> destination;

    Transport temp(routeNumber, transportType, price, travelTime, stops, departure, destination);
    transports.push_back(temp);
}

void Database::deleteTransport(unsigned int index)
{
    if (index > 0 && index <= transports.size()) {
        transports.erase(transports.begin() + (index - 1));
        cout << "Запись успешно удалена." << endl;
    } else {
        cout << "Ошибка! Неверный номер записи." << endl;
    }
}

void Database::sortByRouteNumber()
{
    std::sort(transports.begin(), transports.end(), [](const Transport& a, const Transport& b) {
        return a.getRouteNumber() < b.getRouteNumber();
    });
    cout << "База данных отсортирована по номеру рейса." << endl;
}

void Database::findByRouteNumber(unsigned int routeNumber) const
{
    bool found = false;
    for (const auto& t : transports) {
        if (t.getRouteNumber() == routeNumber) {
            t.print();
            found = true;
        }
    }
    if (!found) {
        cout << "Рейс с номером " << routeNumber << " не найден." << endl;
    }
}

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
        int currentSeconds = time.hour * 3600 + time.minute * 60 + time.second;
        int maxSeconds = maxTime.hour * 3600 + maxTime.minute * 60 + maxTime.second;

        if (currentSeconds <= maxSeconds)
        {
            file << transport.getRouteNumber() << " "
                 << transport.getTransportType() << " "
                 << transport.getPrice() << " "
                 << time.hour << " "
                 << time.minute << " "
                 << time.second << " "
                 << transport.getStops() << " "
                 << transport.getDeparture() << " "
                 << transport.getDestination() << "\n";
        }
    }
    cout << "Новая база данных создана!" << endl;
}
