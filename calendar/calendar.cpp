#include <iostream>
#include <string>
using namespace std;

struct Event {
    string name;     
    string time;     
    string format;   
    string place;  
    string date;     
};

int main() {
    Event events[10];  
    int eventCount = 0; 
    int choice;

    do {
        cout << "\n=== КАЛЕНДАР ПОДІЙ ===\n";
        cout << "1. Додати подію\n";
        cout << "2. Переглянути всі події\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (eventCount < 10) {
                cout << "Назва події: ";
                getline(cin, events[eventCount].name);

                cout << "Дата (наприклад 12.05.2026): ";
                getline(cin, events[eventCount].date);

                cout << "Час (наприклад 14:00): ";
                getline(cin, events[eventCount].time);

                cout << "Формат (онлайн / офлайн): ";
                getline(cin, events[eventCount].format);

                cout << "Місце проведення: ";
                getline(cin, events[eventCount].place);

                eventCount++;
                cout << "Подію додано \n";
            } else {
                cout << "Календар заповнений!\n";
            }
        }

        else if (choice == 2) {
            if (eventCount == 0) {
                cout << "Подій поки немає.\n";
            } else {
                for (int i = 0; i < eventCount; i++) {
                    cout << "\nПодія #" << i + 1 << endl;
                    cout << "Назва: " << events[i].name << endl;
                    cout << "Дата: " << events[i].date << endl;
                    cout << "Час: " << events[i].time << endl;
                    cout << "Формат: " << events[i].format << endl;
                    cout << "Місце: " << events[i].place << endl;
                }
            }
        }

    } while (choice != 0);

    cout << "Програма завершена.\n";
    return 0;
}
