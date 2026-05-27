#include <iostream>
#include "include/Database.h"

int main()
{
    Database db;
    int choice;

    do
    {
        std::cout << "\n";
        std::cout << "1. Загрузить БД из файла\n";
        std::cout << "2. Показать БД\n";
        std::cout << "3. Добавить рейс\n";
        std::cout << "4. Удалить рейс\n";
        std::cout << "5. Сохранить БД\n";
        std::cout << "6. Сортировка по номеру рейса\n";
        std::cout << "7. Поиск по номеру рейса\n";
        std::cout << "8. Выборка по стоимости\n";
        std::cout << "9. Минимальное количество остановок\n";
        std::cout << "10. Создать новую БД по времени\n";
        std::cout << "0. Выход\n";

        std::cout << "Ваш выбор: ";

        // защита ввода меню
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка ввода! Введите число.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            db.loadFromFile("data/transport.txt");
            std::cout << "База загружена\n";
            break;

        case 2:
            db.showDatabase();
            break;

        case 3:
            db.addTransport();
            std::cout << "Рейс добавлен\n";
            break;

        case 4:
        {
            unsigned int index;
            std::cout << "Введите номер записи: ";

            if (!(std::cin >> index))
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка ввода!\n";
                break;
            }

            db.deleteTransport(index);
            break;
        }

        case 5:
            db.saveToFile("data/transport.txt");
            std::cout << "Сохранено\n";
            break;

        case 6:
            db.sortByRouteNumber();
            break;

        case 7:
        {
            unsigned int routeNumber;
            std::cout << "Введите номер рейса: ";

            if (!(std::cin >> routeNumber))
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка ввода!\n";
                break;
            }

            db.findByRouteNumber(routeNumber);
            break;
        }

        case 8:
        {
            float minPrice, maxPrice;

            std::cout << "Минимальная цена: ";
            if (!(std::cin >> minPrice))
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка ввода!\n";
                break;
            }

            std::cout << "Максимальная цена: ";
            if (!(std::cin >> maxPrice))
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка ввода!\n";
                break;
            }

            db.filterByPrice(minPrice, maxPrice);
            break;
        }

        case 9:
            db.taskMinimumStops();
            break;

        case 10:
        {
            CTime maxTime;

            std::cout << "Часы Минуты Секунды: ";

            if (!(std::cin >> maxTime.hour >> maxTime.minute >> maxTime.second))
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Ошибка ввода времени!\n";
                break;
            }

            db.taskTravelTime(maxTime);
            break;
        }

        case 0:
            std::cout << "Выход...\n";
            break;

        default:
            std::cout << "Неверный пункт меню!\n";
        }

    } while (choice != 0);

    return 0;
}