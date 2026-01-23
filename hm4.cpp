#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    string role;

    Employee(string r) {
        name = r;
        role = r;
    }

    void doWork() {
        if (role == "Адміністратор") {
            cout << name << " перевіряє документацію та керує магазином.\n";
        }
        else if (role == "Продавець") {
            cout << name << " продає товар покупцю.\n";
        }
        else if (role == "Охоронець") {
            cout << name << " слідкує за порядком у магазині.\n";
        }
    }
};

class Settings {
public:
    bool documentationOk;
    int admins;
    int sellers;
    int guards;

    Settings(bool doc, int a, int s, int g) {
        documentationOk = doc;
        admins = a;
        sellers = s;
        guards = g;
    }

    void showSettings() {
        cout << "\n--- НАЛАШТУВАННЯ МАГАЗИНУ ---\n";
        cout << "Документація: " << (documentationOk ? "в порядку\n" : "є проблеми\n");
        cout << "Адміністраторів: " << admins << endl;
        cout << "Продавців: " << sellers << endl;
        cout << "Охоронців: " << guards << endl;
    }
};

string currentEvents[3] = {"Поставка товарів", "Оплата оренди", "Виплата зарплати"};
string pastEvents[2] = {"Перевірка фінансів", "Звіт за минулий місяць"};
string futureEvents[2] = {"Планові перевірки", "План закупівлі товарів"};

int main() {
    int balance = 1000;
    string products[3] = {"Яблуко", "Молоко", "Шоколад"};
    int prices[3] = {50, 30, 80};
    int stock[3] = {10, 10, 10}; 
    int choice;

    Settings shopSettings(true, 1, 2, 1);
    shopSettings.showSettings();

    Employee admin("Адміністратор");
    Employee seller("Продавець");
    Employee guard("Охоронець");

    cout << "\nПрацівники виконують свою роботу:\n";
    admin.doWork();
    seller.doWork();
    guard.doWork();

    while (true) {
        cout << "\nВиберіть роль:\n1 - Адміністратор\n2 - Продавець\n3 - Охоронець\n0 - Вийти\nВаш вибір: ";
        cin >> choice;

        if (choice == 0) {
            cout << "До побачення!\n";
            break;
        }

        else if (choice == 1) {
            cout << "\n--- Адміністратор: Перегляд подій ---\n";
            cout << "Поточні події:\n";
            for (string e : currentEvents) cout << "- " << e << endl;

            cout << "Минулі події:\n";
            for (string e : pastEvents) cout << "- " << e << endl;

            cout << "Майбутні події:\n";
            for (string e : futureEvents) cout << "- " << e << endl;
        }

        else if (choice == 2) {
            int sellerChoice;
            cout << "\n--- Продавець: Меню ---\n";
            cout << "1 - Продати товар\n2 - Обміняти товар\n0 - Назад\nВаш вибір: ";
            cin >> sellerChoice;

            if (sellerChoice == 1) {
                cout << "\nСписок товарів:\n";
                for (int i = 0; i < 3; i++)
                    cout << i + 1 << ". " << products[i] << " - " << prices[i] << " грн (на складі: " << stock[i] << ")\n";

                int prod;
                cout << "Введіть номер товару для продажу: ";
                cin >> prod;
                int idx = prod - 1;

                if (idx >= 0 && idx < 3) {
                    if (stock[idx] > 0) {
                        stock[idx]--;
                        balance += prices[idx];
                        cout << "Товар продано успішно!\n";
                        cout << "Баланс магазину: " << balance << " грн\n";
                    } else {
                        cout << "Товару немає в наявності!\n";
                    }
                } else {
                    cout << "Неправильний вибір!\n";
                }
            }
            else if (sellerChoice == 2) {
                int prod;
                cout << "Введіть номер товару для обміну (зменшить склад на 1): ";
                cin >> prod;
                int idx = prod - 1;

                if (idx >= 0 && idx < 3) {
                    if (stock[idx] > 0) {
                        stock[idx]--; 
                        balance += prices[idx]; 
                        cout << "Товар обміняно успішно!\n";
                        cout << "Баланс магазину: " << balance << " грн\n";
                    } else {
                        cout << "Товару немає для обміну!\n";
                    }
                } else {
                    cout << "Неправильний вибір!\n";
                }
            }
        }

        else if (choice == 3) {
            int guardChoice;
            cout << "\n--- Охоронець: Меню ---\n";
            cout << "1 - Переглянути події з людьми\n2 - Переглянути камери\n0 - Назад\nВаш вибір: ";
            cin >> guardChoice;

            if (guardChoice == 1) {
                string situations[3] = {"Підозріла поведінка", "Конфлікт", "Нічого не відбувається"};
                cout << "Події з людьми:\n";
                for (string s : situations) cout << "- " << s << endl;
            }
            else if (guardChoice == 2) {
                string camera[3] = {"Нічого не відбувається", "Хтось підозріло ходить", "Конфлікт у коридорі"};
                cout << "Події з камер:\n";
                for (string c : camera) cout << "- " << c << endl;
            }
        }

        else {
            cout << "Невірний вибір ролі!\n";
        }
    }

    return 0;
}
