#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <locale.h>

using namespace std;

bool isPositive(const string& str) {
    try {
        double number = stod(str);
        return number > 0;
    }
    catch (const exception&) {
        // Если строка не может быть преобразована в число, считаем её неположительной
        return false;
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    // Открываем файл с именем "name"
    ifstream file("name.txt");

    if (!file.is_open()) {
        cerr << "Не удалось открыть файл 'name'" << endl;
        return 1;
    }

    // Создаем итератор для чтения строк из файла
    istream_iterator<string> fileIterator(file);
    istream_iterator<string> endIterator;

    // Используем count_if для подсчета положительных чисел
    int positiveCount = count_if(fileIterator, endIterator, isPositive);

    cout << "Количество положительных чисел: " << positiveCount << endl;

    file.close();
    return 0;
}