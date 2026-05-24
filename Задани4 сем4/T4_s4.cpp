/**
 * @brief Используемые библиотеки
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <functional>
#include <locale.h>

using namespace std;

/**
 * @brief Структура точки с координатами и именем
 */
struct point
{
    int x;
    double y;
    string name;

    point() : x(0), y(0.0), name("") {}
    point(int x_val, double y_val, const string& name_val)
        : x(x_val), y(y_val), name(name_val) {}
};

/**
 * @brief Перегрузка оператора сложения для point
 */
point operator+(const point& a, const point& b)
{
    return point(a.x + b.x, a.y + b.y, a.name + b.name);
}

/**
 * @brief Перегрузка оператора ввода для point
 */
istream& operator>>(istream& is, point& p)
{
    is >> p.x >> p.y >> p.name;
    return is;
}

/**
 * @brief Перегрузка оператора вывода для point
 */
ostream& operator<<(ostream& os, const point& p)
{
    os << p.x << " " << p.y << " " << p.name;
    return os;
}

/**
 * @brief Выводит содержимое вектора точек
 * @param v Вектор для вывода
 * @param message Сообщение перед выводом
 */
void printVector(const vector<point>& v, const string& message)
{
    cout << message;
    for (vector<point>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }
}

/**
 * @brief Главная функция
 */
int main()
{
    setlocale(LC_ALL, "RU");

    // Открываем файлы для чтения
    ifstream file1("name1.txt");
    ifstream file2("name2.txt");

    // Проверка открытия файлов
    if (!file1.is_open() || !file2.is_open())
    {
        cout << "Ошибка открытия файлов" << endl;
        return 1;
    }

    // Чтение данных в векторы с помощью итераторов
    istream_iterator<point> start1(file1), end1;
    vector<point> V1(start1, end1);

    istream_iterator<point> start2(file2), end2;
    vector<point> V2(start2, end2);

    file1.close();
    file2.close();

    cout << "Прочитано " << V1.size() << " элементов из name1" << endl;
    cout << "Прочитано " << V2.size() << " элементов из name2" << endl;

    // Проверка количества элементов
    if (V1.size() != V2.size())
    {
        cout << "Ошибка: разное количество элементов" << endl;
        return 1;
    }

    // Преобразование вектора V1 (сложение с соответствующими элементами V2)
    transform(V1.begin(), V1.end(), V2.begin(), V1.begin(), plus<point>());

    cout << "Сложение выполнено" << endl;
    cout << "Результат сложения:" << endl;
    printVector(V1, "");

    // Запись результата в файл с помощью итераторов
    ofstream outFile("name1.txt");
    if (!outFile.is_open()) {
        cout << "Ошибка открытия файла для записи" << endl;
        return 1;
    }

    ostream_iterator<point> outIt(outFile, "\n");
    copy(V1.begin(), V1.end(), outIt);

    outFile.close();

    cout << "Результат записан в name1" << endl;

    return 0;
}