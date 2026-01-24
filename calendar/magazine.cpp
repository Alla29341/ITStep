#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

class Employee {
public:
    string role;

    Employee(string r) {
        role = r;
    }

    void doWork() {
        if (role == "Адміністратор") {
            cout << role << " перевіряє документацію та керує магазином.\n";
        }
        else if (role == "Продавець") {
            cout << role << " продає товар покупцю.\n";
        }
        else if (role == "Охоронець") {
            cout << role << " слідкує за порядком у магазині.\n";
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

int main() {
    int balance = 1000;

    string products[3] = { "Яблуко", "Молоко", "Шоколад" };
    int prices[3] = { 50, 30, 80 };

    Settings shopSettings(true, 1, 2, 1);
    shopSettings.showSettings();

    Employee admin("Адміністратор");
    Employee seller("Продавець");
    Employee guard("Охоронець");

    cout << "\nПрацівники виконують свою роботу:\n";
    admin.doWork();
    seller.doWork();
    guard.doWork();

    int choice;

    do {
        cout << "\n=== МАГАЗИН ===\n";
        cout << "Баланс: " << balance << " грн\n";
        cout << "1. Подивитись товари\n";
        cout << "2. Купити товар\n";
        cout << "3. Повернути товар\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nСписок товарів:\n";
            for (int i = 0; i < 3; i++) {
                cout << i + 1 << ". " << products[i] << " - " << prices[i] << " грн" << endl;
            }
        }

        else if (choice == 2) {
            int productChoice, quantity;
            cout << "Введіть номер товару: ";
            cin >> productChoice;
            int index = productChoice - 1;

            if (index >= 0 && index < 3) {
                cout << "Введіть кількість: ";
                cin >> quantity;

                string pack;
                cout << "Бажаєте пакет? (так/ні): ";
                cin >> pack;

                int totalPrice = prices[index] * quantity;
                if (pack == "так") totalPrice += 5;

                if (balance >= totalPrice) {
                    balance -= totalPrice;

                    cout << "\n=== ЧЕК ===\n";
                    cout << left << setw(15) << "Продукт" 
                         << setw(10) << "Кількість" 
                         << setw(10) << "Ціна" 
                         << setw(10) << "Сума" << endl;

                    cout << left << setw(15) << products[index]
                         << setw(10) << quantity
                         << setw(10) << prices[index]
                         << setw(10) << totalPrice << endl;

                    cout << "Баланс після покупки: " << balance << " грн\n";
                    cout << "До побачення! Гарного дня!\n";
                } else {
                    cout << "Недостатньо коштів для покупки!\n";
                }
            } else {
                cout << "Неправильний вибір.\n";
            }
        }

        else if (choice == 3) {
            int productChoice, quantity;
            cout << "Введіть номер товару для повернення: ";
            cin >> productChoice;
            int index = productChoice - 1;
            
        if (index >= 0 && index < 3) {
                cout << "Введіть кількість для повернення: ";
                cin >> quantity;

                int refund = prices[index] * quantity;
                balance += refund;
                cout << "Товар повернено.\n";
                cout << "Баланс після повернення: " << balance << " грн\n";
            } else {
                cout << "Неправильний вибір.\n";
            }
        }

        else if (choice == 0) {
            cout << "До побачення!\n";
        }

        else {
            cout << "Невірний пункт меню.\n";
        }

    } while (choice != 0);

    return 0;
}
