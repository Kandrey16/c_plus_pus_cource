#include <iostream>
#include <climits> // Добавляем этот заголовок
#include <string>
using namespace std;

int main() {
    string line;
    cout << "Введите строку: ";
    getline(cin, line);

    int maxLength = 0;       // Длина самого длинного слова
    int minLength = INT_MAX; // Длина самого короткого слова (начальное значение — максимум)
    int longestWordIndex = 0; // Порядковый номер самого длинного слова
    int shortestWordIndex = 0; // Порядковый номер самого короткого слова
    int currentLength = 0;   // Длина текущего слова
    int currentWordIndex = 1; // Порядковый номер текущего слова
    string longestWord = ""; // Самое длинное слово
    string shortestWord = ""; // Самое короткое слово

    for (size_t i = 0; i <= line.size(); i++) {
        if (line[i] != ' ' && line[i] != '\n' && line[i] != '\0') {
            currentLength++;
        } else {
            if (currentLength > 0) { // Проверка, что это не пустое слово
                // Проверка на самое длинное слово
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    longestWordIndex = currentWordIndex;
                    longestWord = line.substr(i - currentLength, currentLength);
                }
                // Проверка на самое короткое слово
                if (currentLength < minLength) {
                    minLength = currentLength;
                    shortestWordIndex = currentWordIndex;
                    shortestWord = line.substr(i - currentLength, currentLength);
                }
                currentLength = 0; // Обнуляем длину текущего слова
                currentWordIndex++; // Переходим к следующему слову
            }
        }
    }

    cout << "Самое длинное слово: " << longestWord << endl;
    cout << "Его порядковый номер: " << longestWordIndex << endl;

    cout << "Самое короткое слово: " << shortestWord << endl;
    cout << "Его порядковый номер: " << shortestWordIndex << endl;

    return 0;
}
