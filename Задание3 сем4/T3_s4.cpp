/**
 * @brief Используемые библиотеки
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <locale.h>

using namespace std;

/**
 * @brief Выводит содержимое вектора
 * @param v Вектор для вывода
 * @param message Сообщение перед выводом
 */
void printVector(const vector<int>& v, const string& message)
{
    cout << message;
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * @brief Выводит содержимое мультиотображения
 * @param m Мультиотображение для вывода
 * @param message Заголовочное сообщение
 */
void printMultimap(const multimap<int, int>& m, const string& message)
{
    cout << message << endl;
    cout << "Ключ (последняя цифра) -> Значение (элемент)" << endl;
    cout << "\n" << "********************************************" << endl;

    for (multimap<int, int>::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " -> " << it->second << endl;
    }
    cout << "********************************************" << endl;
}

/**
 * @brief Главная функция
 */
int main()
{
    setlocale(LC_ALL, "RU");
    vector<int> V;
    string input;

    cout << "Введите целые числа через пробел: ";
    getline(cin, input);

    istringstream iss(input);
    istream_iterator<int> start(iss), end;
    V.assign(start, end);

    if (V.empty())
    {
        cerr << "Ошибка: не введено ни одного числа" << endl;
        return 1;
    }

    printVector(V, "Исходный вектор: ");
    cout << endl;

    // Создаем мультиотображение для группировки по последней цифре
    multimap<int, int> M;

    // Заполняем мультиотображение
    for (vector<int>::const_iterator it = V.begin(); it != V.end(); ++it)
    {
        int lastDigit = abs(*it) % 10;  // Последняя цифра (берем абсолютное значение для отрицательных чисел)
        M.insert(make_pair(lastDigit, *it));
    }

    printMultimap(M, "Результат группировки (multimap):");

    return 0;
}