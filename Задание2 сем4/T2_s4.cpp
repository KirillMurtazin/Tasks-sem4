#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <locale>
#include <iterator>

using namespace std;

void printVector(const vector<int>& v, const string& message)
{
    cout << message;
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

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

    // Проверяем, что введены только целые числа
    if (V.empty()) {
        cerr << "Ошибка: не введено ни одного числа" << endl;
        return 1;
    }

    printVector(V, "Исходный вектор: ");
    cout << "Размер вектора: " << V.size() << endl;

    // Проверяем условия задачи
    if (V.size() < 5) {
        cerr << "Ошибка: вектор должен содержать минимум 5 элементов" << endl;
        return 1;
    }

    if (V.size() % 2 == 0) {
        cerr << "Ошибка: вектор должен иметь нечетное количество элементов" << endl;
        return 1;
    }

    // Находим позицию среднего элемента
    int middleIndex = V.size() / 2;

    // Удаляем три средних элемента одним вызовом erase
    V.erase(V.begin() + (middleIndex - 1), V.begin() + (middleIndex + 2));

    printVector(V, "Вектор после удаления трех средних элементов: ");
    cout << "Новый размер вектора: " << V.size() << endl;

    return 0;
}