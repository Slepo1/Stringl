#include "stringl.h"
#include <cstring> //для strlen, strcopy
#include <iostream>
#include <stdlib.h>
#include <algorithm>
Stringl::Stringl(int ln) 
{
    len = ln;
    str = new char[len + 1];
    str[0] = '\0'; // Завершаем строку нулевым символом
}

// Конструктор для создания строки из массива char
Stringl::Stringl(char* s) 
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s); // Копируем содержимое s в str
}

// Деструктор для освобождения памяти
Stringl::~Stringl() 
{
    delete[] str;
}

// Оператор индексации []
char& Stringl::operator[](int index) 
{
	if(index < 0 || index >= len)
	{
		std::cerr << "Index out of range\n";
		exit(-1);
	}
    return str[index];
}

// Оператор присваивания =
void Stringl::operator=(Stringl& stringl) 
{
    len = stringl.len;
    delete[] str; // Удаляем текущее содержимое строки
    str = new char[len + 1];
    strcpy(str, stringl.str); // Копируем содержимое stringl.str в str
}

// Оператор +=
void Stringl::operator+=(Stringl& stringl) 
{
    // Создаем временный буфер для объединения строк
    char* temp = new char[len + stringl.len + 1];
    // Копируем текущую строку в буфер
    strcpy(temp, str);
    // Добавляем к текущей строке строку stringl
    strcat(temp, stringl.str);
    // Освобождаем старую память и обновляем указатель
    delete[] str;
    str = temp;
    // Обновляем длину строки
    len += stringl.len;
}

// Метод для поиска подстроки в строке
int Stringl::find_str(Stringl& stringl) 
{
    char* ptr = strstr(str, stringl.str);
    if (ptr != nullptr) {
        return ptr - str;
    } else {
        return -1; // Подстрока не найдена
    }
}

bool Stringl::operator==(Stringl& stringl)
{
	if(len != stringl.len)
	{
		return false;
	}

	for(int i = 0; i < len; i++)
	{
		if(str[i] != stringl[i])
		{
			return false;
		}
	}

	return true;
}

bool Stringl::operator!=(Stringl& stringl)
{
	return !(str == stringl.str);
}

int Stringl::length()
{
	return len;
}

std::ostream& operator<<(std::ostream& os, const Stringl& stringl) {
    os << stringl.str; // Просто выводим строку
    return os;
}

// Оператор ввода >>
std::istream& operator>>(std::istream& is, Stringl& stringl) {
    // Считываем ввод пользователя во временный буфер
    char temp[1000];
    is >> temp;

    // Освобождаем предыдущее содержимое строки и копируем новое
    delete[] stringl.str;
    stringl.len = strlen(temp);
    stringl.str = new char[stringl.len + 1];
    strcpy(stringl.str, temp);

    return is;
}

void Stringl::insert(int pos, Stringl& stringl)
{
	if(pos < 0 || pos > len)
	{
		std::cerr << "Error: pos not in the range" << '\n';
		return;
	}

	char* new_str = new char[len + stringl.len + 1];

	strncpy(new_str, str, pos);

	strncpy(new_str + pos, stringl.str, stringl.len);


    strncpy(new_str + pos + stringl.len, str + pos, len - pos);

    // Освобождаем старую память
    delete[] str;
    // Обновляем указатель на новую строку
    str = new_str;
    // Обновляем длину строки
    len += stringl.len;

}

Stringl::Stringl(Stringl& stringl) { // Конструктор копий
    len = stringl.len;
    str = new char[len + 1]; // Выделяем память для новой строки
    strcpy(str, stringl.str); // Копируем содержимое строки
}




