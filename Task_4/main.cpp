#include <iostream>
#include "vector.h"

void print_vector(const Vector<int>& v) {
    std::cout << "Содержимое вектора: ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "\n";
}

void print_iterators(const Vector<int>& v) {
    std::cout << "Через итераторы (прямой обход): ";
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "Через итераторы (обратный обход): ";
    for (auto it = v.rbegin(); it != v.rend(); --it)
        std::cout << *it << " ";
    std::cout << "\n";
}

int main() {
    Vector<int> v;

    std::cout << "== Тест push_back ==\n";
    for (int i = 1; i <= 5; ++i)
        v.push_back(i * 10);
    print_vector(v);

    std::cout << "\n== Тест insert ==\n";
    v.insert(2, 25);  // вставка в середину
    v.insert(0, 5);   // вставка в начало
    v.insert(v.size(), 100);  // вставка в конец
    print_vector(v);

    std::cout << "\n== Тест erase(index) ==\n";
    v.erase(0);  // удалить первый
    v.erase(v.size() - 1);  // удалить последний
    print_vector(v);

    std::cout << "\n== Тест erase(from, to) ==\n";
    v.erase(2, 4);  // удалить диапазон
    print_vector(v);

    std::cout << "\n== Тест at() и back() ==\n";
    std::cout << "Элемент по индексу 1: " << v.at(1) << "\n";
    std::cout << "Последний элемент: " << v.back() << "\n";

    std::cout << "\n== Тест emplace/emplace_back ==\n";
    v.emplace(1, 77);
    v.emplace_back(88);
    print_vector(v);

    std::cout << "\n== Тест clear ==\n";
    v.clear();
    std::cout << "Размер после clear: " << v.size() << "\n";

    std::cout << "\n== Тест assign ==\n";
    Vector<int> v2;
    for (int i = 0; i < 3; ++i)
        v2.push_back(i + 1);
    v.assign(v2);
    std::cout << "Вектор v после assign из v2: ";
    print_vector(v);
    std::cout << "Вектор v2 (должен быть пустым): размер = " << v2.size() << "\n";

    std::cout << "\n== Тест итераторов ==\n";
    print_iterators(v);

    std::cout << "\n== Тест swap ==\n";
    Vector<int> v3;
    v3.push_back(99);
    v3.push_back(100);
    std::cout << "До swap:\n";
    std::cout << "v: "; print_vector(v);
    std::cout << "v3: "; print_vector(v3);
    v.swap(v3);
    std::cout << "После swap:\n";
    std::cout << "v: "; print_vector(v);
    std::cout << "v3: "; print_vector(v3);

    return 0;
}
