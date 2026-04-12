#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <locale.h>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    vector<int> V;
    string input;

    cout << "Введите целые числа через пробел: ";
    getline(cin, input);

    // Разбираем введенную строку
    istringstream iss(input);
    int num;
    while (iss >> num) {
        V.push_back(num);
    }

    if (V.empty()) {
        cerr << "Ошибка: не введено ни одного числа" << endl;
        return 1;
    }

    cout << "Исходный вектор: ";
    for (vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    // Создаем мультиотображение для группировки по последней цифре
    multimap<int, int> M;

    // Заполняем мультиотображение
    for (vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
        int lastDigit = abs(*it) % 10;  // Последняя цифра (берем абсолютное значение для отрицательных чисел)
        M.insert(make_pair(lastDigit, *it));
    }

    cout << "Результат группировки (multimap):" << endl;
    cout << "Ключ (последняя цифра) -> Значение (элемент)" << endl;
    cout << "\n" << "********************************************" << endl;

    // Выводим содержимое мультиотображения с помощью итераторов
    for (multimap<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    cout << "********************************************" << endl;

    return 0;
}