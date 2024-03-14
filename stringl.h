#pragma once
#include <cstring> // Для strlen, strcpy
#include <iostream>

class Stringl {
private:
    int len;
    char* str;
public:
    // Конструкторы и деструктор
    Stringl(int ln);
    Stringl(char* s);
    ~Stringl();
    
    // Операторы
    char& operator[] (int index);
    void operator= (Stringl& stringl);
    void operator+= (Stringl& stringl);
    bool operator==(Stringl& stringl);
    bool operator!=(Stringl& stringl);

    // Дружественная функция для вывода
    friend std::ostream& operator<<(std::ostream& os, const Stringl& stringl);
    friend std::istream& operator>>(std::istream& is, Stringl& stringl);

    // Методы
    int find_str(Stringl& stringl);
    int length();
    void insert(int pos, Stringl& stringl);

    // Конструктор копирования
    Stringl(Stringl& stringl);
};