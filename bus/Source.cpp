#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

void EnterDrop()
{
	cin.clear();
	while (cin.get() != '\n');
}

class driver
{
	string s_name, s_brand;
	int i_number, i_route, i_year, i_race;
public:
	driver()
	{
		s_name = "none";
		s_brand = "none";
		i_number = 0;
		i_route = 0;
		i_year = 0;
		i_race = 0;
	}

	void file_read(fstream &ifs);
	void print();
	void print_route(int i_key);
	void print_age(int i_key);
	void print_race(int i_key);
};

void driver::file_read(fstream &ifs)
{
	getline(ifs, s_name);
	getline(ifs, s_brand);
	ifs >> i_number;
	ifs >> i_route;
	ifs >> i_year;
	ifs >> i_race;
}

void driver::print()
{
	cout << "\nИмя: " << s_name;
	cout << "\nМарка: " << s_brand;
	cout << "\nНомер: " << i_number;
	cout << "\nМаршрут: " << i_route;
	cout << "\nГод: " << i_year;
	cout << "\nПробег: " << i_race;
	cout << "\n==============================" << endl;
}

void driver::print_route(int i_key)
{
	if (i_route == i_key) print();
}

void driver::print_age(int i_key)
{
	if ((i_key - 10) > i_year) print();
}

void driver::print_race(int i_key)
{
	if (i_race > i_key)	print();
}

void main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "СПИСОК МАРШРУТОВ\n";
	fstream ifs;
	int i, i_quant, i_key;
	ifs.open("file.txt", ios::in);
	ifs >> i_quant;
	driver *list = new driver[i_quant];
	for (i = 0; i < i_quant; i++) list[i].file_read(ifs);

	for (i = 0; i < i_quant; i++)
	{
		list[i].print();
	}

	cout << "\n==============================\nВведите номер маршрута для вывода: ";
	cin >> i_key;
	cout << "Автобусы с маршрутом " << i_key << ": ";
	for (i = 0; i < i_quant; i++)
	{
		list[i].print_route(i_key);
	}

	cout << "\n==============================\nВведите год для проверки пробега: ";
	cin >> i_key;
	cout << "Автобусы с пробегом больше 10 лет к " << i_key << " году:";

	for (i = 0; i < i_quant; i++)
	{
		list[i].print_age(i_key);
	}

	cout << "\n==============================\nВведите предел пробега (в км.): ";
	cin >> i_key;
	cout << "Автобусы с пробегом больше " << i_key << " км.:";
	for (i = 0; i < i_quant; i++)
	{
		list[i].print_race(i_key);
	}

	cout << endl << endl;
	delete[] list;
	system("@pause");
}