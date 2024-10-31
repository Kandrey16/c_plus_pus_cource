#include <iostream>
using namespace std;

int main() {
    int limit, sum = 0;
    cout << "Введите предел: ";
    cin >> limit;

    int i = 0; // Начинаем с 0
    while (i <= limit) {
        if (i % 5 == 0) {
            sum += i; // Если число делится на 5, добавляем его к сумме
        }
        i++; // Увеличиваем счётчик
    }

    cout << "Сумма чисел, делящихся на 5 от 0 до " << limit << ": " << sum << endl;
    return 0;
}
