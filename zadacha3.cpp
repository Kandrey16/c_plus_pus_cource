#include <iostream>
#include <string>
using namespace std;

int main() {
    // Запрашиваем данные у пользователя
    string firstName, lastName, patronymic, groupNumber;
    cout << "Введите фамилию: ";
    getline(cin, lastName);
    cout << "Введите имя: ";
    getline(cin, firstName);
    cout << "Введите отчество: ";
    getline(cin, patronymic);
    cout << "Введите номер группы: ";
    getline(cin, groupNumber);

    // Формируем строки для вывода
    string labWork = "Лабораторная работа № 1";
    string studentInfo = "Выполнил(а): ст. гр. " + groupNumber;
    string studentName = lastName + " " + firstName + " " + patronymic;

    // Определяем длину самой длинной строки
    int maxLength = max(labWork.length(), max(studentInfo.length(), studentName.length()));

    // Увеличиваем длину рамки на 4 символа для отступов
    maxLength += 4;

    // Выводим рамку и данные
    cout << "/" << string(maxLength, '*') << "/" << endl;
    cout << "* " << labWork << string(maxLength - labWork.length() - 3, ' ') << " *" << endl;
    cout << "* " << studentInfo << string(maxLength - studentInfo.length() - 3, ' ') << " *" << endl;
    cout << "* " << studentName << string(maxLength - studentName.length() - 3, ' ') << " *" << endl;
    cout << "/" << string(maxLength, '*') << "/" << endl;

    return 0;
}