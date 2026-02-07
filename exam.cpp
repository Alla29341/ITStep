#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct Request {
    int id;
    string district;
    string type;   
    int daysOpen;
    bool critical;
};

list<Request> requests;

bool isCritical(int days) {
    return days >= 3;
}

void loadFromFile() {
    ifstream file("city.txt");
    if (!file) {
        cout << "Помилка: файл city.txt не знайдено\n";
        return;
    }

    requests.clear(); 
    string line;

    while (getline(file, line)) {
        string parts[4];
        int index = 0;
        size_t pos;

        while ((pos = line.find(';')) != string::npos && index < 3) {
            parts[index++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        parts[index] = line;

        if (index != 3) continue; 

        try {
            Request r;
            r.id = stoi(parts[0]);
            r.district = parts[1];
            r.type = parts[2];
            r.daysOpen = stoi(parts[3]);
            r.critical = isCritical(r.daysOpen);

            requests.push_back(r);
        } catch (...) {
            continue;
        }
    }

    file.close();
    cout << "Завантажено заявок: " << requests.size() << endl;
}

void showAll() {
    if (requests.empty()) {
        cout << "Даних немає\n";
        return;
    }

    for (const Request& r : requests) {
        cout << "ID: " << r.id
             << ", Район: " << r.district
             << ", Тип: " << r.type
             << ", Днів: " << r.daysOpen
             << ", Критична: " << (r.critical ? "Так" : "Ні")
             << endl;
    }
}

void countCritical() {
    int count = 0;
    for (const Request& r : requests) {
        if (r.critical) count++;
    }
    cout << "Кількість критичних заявок: " << count << endl;
}

void averageDays() {
    if (requests.empty()) {
        cout << "Даних немає\n";
        return;
    }

    int sum = 0;
    for (const Request& r : requests) {
        sum += r.daysOpen;
    }

    cout << "Середня кількість днів: "
         << (double)sum / requests.size() << endl;
}

void countByDistrict() {
    if (requests.empty()) {
        cout << "Даних немає\n";
        return;
    }

    string district;
    cout << "Введіть район: ";
    cin >> district;

    int count = 0;
    for (const Request& r : requests) {
        if (r.district == district) count++;
    }

    cout << "Заявок у районі " << district << ": " << count << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- City Repair Request System ---\n";
        cout << "1 - Завантажити заявки з файлу\n";
        cout << "2 - Показати всі заявки\n";
        cout << "3 - Кількість критичних заявок\n";
        cout << "4 - Середня кількість днів\n";
        cout << "5 - Кількість заявок у районі\n";
        cout << "0 - Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: loadFromFile(); break;
        case 2: showAll(); break;
        case 3: countCritical(); break;
        case 4: averageDays(); break;
        case 5: countByDistrict(); break;
        case 0: cout << "Вихід...\n"; break;
        default: cout << "Невірний вибір\n";
        }
    } while (choice != 0);

    return 0;
}
