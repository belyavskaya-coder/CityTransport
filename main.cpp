#include "include/Database.h"

int main()
{
    Database db;

    int choice;

    do
    {
        cout << endl;

        cout << "1. Загрузить БД из файла" << endl;
        cout << "2. Показать БД" << endl;
        cout << "3. Добавить рейс" << endl;
        cout << "4. Удалить рейс" << endl;
        cout << "5. Сохранить БД" << endl;
        cout << "6. Сортировка по номеру рейса" << endl;
        cout << "7. Поиск по номеру рейса" << endl;
        cout << "8. Выборка по стоимости" << endl;
        cout << "9. Минимальное количество остановок" << endl;
        cout << "10. Создать новую БД по времени" << endl;
        cout << "0. Выход" << endl;

        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            db.loadFromFile("data/transport.txt");
            break;
        }

        case 2:
        {
            db.showDatabase();
            break;
        }

        case 3:
        {
            db.addTransport();
            break;
        }

        case 4:
        {
            unsigned int index;

            cout << "Введите номер записи: ";
            cin >> index;

            db.deleteTransport(index);

            break;
        }

        case 5:
        {
            db.saveToFile("includ/src/data/transport.txt");
            break;
        }

        case 6:
        {
            db.sortByRouteNumber();
            break;
        }

        case 7:
        {
            unsigned int routeNumber;

            cout << "Введите номер рейса: ";
            cin >> routeNumber;

            db.findByRouteNumber(routeNumber);

            break;
        }

        case 8:
        {
            float minPrice;
            float maxPrice;

            cout << "Минимальная цена: ";
            cin >> minPrice;

            cout << "Максимальная цена: ";
            cin >> maxPrice;

            db.filterByPrice(minPrice, maxPrice);

            break;
        }

        case 9:
        {
            db.taskMinimumStops();
            break;
        }

        case 10:
{
    CTime maxTime;

    cout << "Часы: ";
    cin >> maxTime.hour;

    cout << "Минуты: ";
    cin >> maxTime.minute;

    cout << "Секунды: ";
    cin >> maxTime.second;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка ввода времени!" << endl;
        break;
    }

    db.taskTravelTime(maxTime);
    break;
}

        case 0:
        {
            cout << "Выход..." << endl;
            break;
        }

        default:
        {
            cout << "Неверный пункт меню!" << endl;
        }
        }

    } while (choice != 0);

    return 0;
}