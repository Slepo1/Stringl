#include <iostream>
#include "stringl.h"

using namespace std;

int main()
{
	char s[] = "Stroka";
	char s1[] = "ok";
	Stringl str(s);
	Stringl str1(s1);
	Stringl strNew(20);
	//str = str1; // тест оператора присваивания
	//int index = str.find_str(str1); // тест функции поиска подстроки
	//str += str1; // сложение строк
	//str == str1;//bool operator==(Stringl& stringl);
	//str!=str1//bool operator!=(Stringl& stringl);
	//cout << str.length(); // метод для определния длины строки

	//cout << str << '\n'; теперь вывод работает для Stringl

	//cin >> strNew; Теперь работает ввод для Stringl

	//str.insert(2, str1); // Вставка подстроки в строки в определенный участок строки

	//Stringl copy(str); // Тест конструктора копий


	return 0;
}