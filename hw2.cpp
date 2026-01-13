#include <iostream>
#include <string>
using namespace std;

int main() {
    int balance = 1000; 

    string products[3] = {"Яблуко", "Молоко", "Шоколад"};
    int prices[3] = {50, 30, 80};

    int boughtCount[3] = {0, 0, 0}; 

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
                cout << i + 1 << ". " << products[i]
                     << " - " << prices[i] << " грн"
                     << " | Куплено: " << boughtCount[i] << " раз(и)\n";
            }
        }

        else if (choice == 2) {
            int productChoice;
            cout << "Введіть номер товару для покупки: ";
            cin >> productChoice;
            int index = productChoice - 1;

            if (index >= 0 && index < 3) {
                int totalPrice = prices[index];

                string packageChoice;
                cout << "Бажаєте пакет? (так/ні): ";
                cin >> packageChoice;

                if (packageChoice == "так") {
                    totalPrice += 5;
                }

                if (balance >= totalPrice) {
                    balance -= totalPrice;
                    boughtCount[index]++;

                    cout << "Товар куплено успішно!\n";
                    cout << "До побачення! Гарного дня!\n";
                    cout << "Ваш баланс: " << balance << " грн\n";
                } else {
                    cout << "Недостатньо коштів!\n";
                }
            } else {
                cout << "Неправильний вибір товару.\n";
            }
        }

        else if (choice == 3) {
            int productChoice;
            cout << "Введіть номер товару для повернення: ";
            cin >> productChoice;
            int index = productChoice - 1;

            if (index >= 0 && index < 3) {
                if (boughtCount[index] > 0) {
                    balance += prices[index];
                    boughtCount[index]--;

                    cout << "Товар повернено успішно!\n";
                    cout << "Ваш баланс: " << balance << " грн\n";
                } else {
                    cout << "Цей товар ще не купували.\n";
                }
            } else {
                cout << "Неправильний вибір товару.\n";
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
