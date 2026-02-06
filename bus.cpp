#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

const int MAX_VEHICLES = 10; 
const int MAX_ROUTES = 10;    

class Vehicle {
private:
    int id;
    string type;
    int capacity;
    int currentPassengers;

public:
    Vehicle() : id(0), type(""), capacity(0), currentPassengers(0) {}

    Vehicle(int id, const string& type, int capacity)
        : id(id), type(type), capacity(capacity), currentPassengers(0) {}

    int getId() const { return id; }
    int getPassengers() const { return currentPassengers; }

    void board(int count) {
        if (count < 0) throw invalid_argument("Кількість пасажирів не може бути від’ємною");
        if (currentPassengers + count > capacity) throw overflow_error("Переповнення транспорту");
        currentPassengers += count;
    }

    void unboard(int count) {
        if (count < 0) throw invalid_argument("Кількість пасажирів не може бути від’ємною");
        if (count > currentPassengers) throw runtime_error("Недостатньо пасажирів для висадки");
        currentPassengers -= count;
    }

    void print() const {
        cout << "Транспорт ID: " << id << ", Тип: " << type
             << ", Пасажири: " << currentPassengers
             << "/" << capacity << endl;
    }

    void save(ofstream& file) const {
        file << id << " " << type << " " << capacity << " " << currentPassengers << endl;
    }

    void load(ifstream& file) {
        file >> id >> type >> capacity >> currentPassengers;
    }
};

class Route {
private:
    int routeNumber;
    Vehicle vehicles[MAX_VEHICLES];
    int vehicleCount;

public:
    Route() : routeNumber(0), vehicleCount(0) {}
    Route(int num) : routeNumber(num), vehicleCount(0) {}

    int getNumber() const { return routeNumber; }

    void addVehicle(const Vehicle& v) {
        if (vehicleCount >= MAX_VEHICLES)
            throw runtime_error("Максимальна кількість транспорту досягнута");
        vehicles[vehicleCount++] = v;
    }

    Vehicle& getVehicle(int index) {
        if (index < 0 || index >= vehicleCount)
            throw out_of_range("Неправильний індекс транспорту");
        return vehicles[index];
    }

    int totalPassengers() const {
        int sum = 0;
        for (int i = 0; i < vehicleCount; i++)
            sum += vehicles[i].getPassengers();
        return sum;
    }

    void printRoute() const {
        cout << "\nМаршрут №" << routeNumber << endl;
        for (int i = 0; i < vehicleCount; i++)
            vehicles[i].print();
    }

    void save(ofstream& file) const {
        file << routeNumber << " " << vehicleCount << endl;
        for (int i = 0; i < vehicleCount; i++)
            vehicles[i].save(file);
    }

    void load(ifstream& file) {
        file >> routeNumber >> vehicleCount;
        for (int i = 0; i < vehicleCount; i++)
            vehicles[i].load(file);
    }

    int getVehicleCount() const { return vehicleCount; }
};

class CityTransportSystem {
private:
    Route routes[MAX_ROUTES];
    int routeCount;

public:
    CityTransportSystem() : routeCount(0) {}

    void addRoute(const Route& r) {
        if (routeCount >= MAX_ROUTES)
            throw runtime_error("Максимальна кількість маршрутів досягнута");
        routes[routeCount++] = r;
    }

    Route& findRoute(int number) {
        for (int i = 0; i < routeCount; i++)
            if (routes[i].getNumber() == number)
                return routes[i];
        throw runtime_error("Маршрут не знайдено");
    }

    int cityLoad() const {
        int sum = 0;
        for (int i = 0; i < routeCount; i++)
            sum += routes[i].totalPassengers();
        return sum;
    }

    void printAllRoutes() const {
        for (int i = 0; i < routeCount; i++)
            routes[i].printRoute();
    }
    
    void saveToFile(const string& filename) const {
        ofstream file(filename);
        file << routeCount << endl;
        for (int i = 0; i < routeCount; i++)
            routes[i].save(file);
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        file >> routeCount;
        for (int i = 0; i < routeCount; i++)
            routes[i].load(file);
    }

    int getRouteCount() const { return routeCount; }
};

int main() {
    CityTransportSystem system;
    int choice;

    do {
        cout << "\n=== SMART CITY TRANSPORT ===\n";
        cout << "1 - Додати маршрут\n";
        cout << "2 - Додати транспорт до маршруту\n";
        cout << "3 - Посадити пасажирів\n";
        cout << "4 - Висадити пасажирів\n";
        cout << "5 - Показати всі маршрути\n";
        cout << "6 - Загальне навантаження міста\n";
        cout << "7 - Зберегти у файл\n";
        cout << "8 - Завантажити з файлу\n";
        cout << "0 - Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        try {
            if (choice == 1) {
                int num;
                cout << "Номер маршруту: ";
                cin >> num;
                system.addRoute(Route(num));
            }

            else if (choice == 2) {
                int routeNum, id, cap;
                string type;
                cout << "Номер маршруту: ";
                cin >> routeNum;
                cout << "ID транспорту: ";
                cin >> id;
                cout << "Тип (bus/tram/metro): ";
                cin >> type;
                cout << "Місткість: ";
                cin >> cap;

                system.findRoute(routeNum).addVehicle(Vehicle(id, type, cap));
            }

            else if (choice == 3) {
                int routeNum, vehIndex, count;
                cout << "Номер маршруту: ";
                cin >> routeNum;
                cout << "Індекс транспорту (з 0): ";
                cin >> vehIndex;
                cout << "Кількість пасажирів: ";
                cin >> count;

                system.findRoute(routeNum).getVehicle(vehIndex).board(count);
            }

            else if (choice == 4) {
                int routeNum, vehIndex, count;
                cout << "Номер маршруту: ";
                cin >> routeNum;
                cout << "Індекс транспорту (з 0): ";
                cin >> vehIndex;
                cout << "Кількість пасажирів: ";
                cin >> count;

                system.findRoute(routeNum).getVehicle(vehIndex).unboard(count);
            }

            else if (choice == 5) {
                system.printAllRoutes();
            }

            else if (choice == 6) {
                cout << "Загальне навантаження міста: "
                     << system.cityLoad() << endl;
            }

            else if (choice == 7) {
                system.saveToFile("city.txt");
                cout << "Дані збережено\n";
            }

            else if (choice == 8) {
                system.loadFromFile("city.txt");
                cout << "Дані завантажено\n";
            }
        }
        catch (exception& e) {
            cout << "ПОМИЛКА: " << e.what() << endl;
        }

    } while (choice != 0);

    return 0;
}
