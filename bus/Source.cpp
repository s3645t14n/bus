#include <iostream>
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
		EnterDrop();
		cout << "\nВведите имя водителя: ";
		getline(cin, s_name);
		cout << "\nВведите марку автобуса: ";
		getline(cin, s_brand);
		cout << "\nВведите номер автобуса: ";
		cin >> i_number;
		cout << "\nВведите маршрут автобуса: ";
		cin >> i_route;
		cout << "\nВведите год выпуска автобуса: ";
		cin >> i_year;
		cout << "\nВведите пробег автобуса: ";
		cin >> i_race;
	}

	void print();
	void print_route(int i_key);
	void print_age(int i_key);
	void print_race(int i_key);
};

void driver::print()
{
	cout << "\nИмя: " << s_name;
	cout << "\nМарка: " << s_brand;
	cout << "\nНомер: " << i_number;
	cout << "\nМаршрут: " << i_route;
	cout << "\nГод: " << i_year;
	cout << "\nПробег: " << i_race;
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
	if (i_race > i_key) print();
}

void main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i, i_quant, i_key;
	cout << "\nВведите число водителей: ";
	cin >> i_quant;
	driver *list = new driver[i_quant];
	for (i = 0; i < i_quant; i++)
	{
		cout << "\n==============================" << endl;
		list[i].print();

	}

	cout << "\nНомер маршрута? ";
	cin >> i_key;
	cout << "\nАвтобусы с маршрутом " << i_key << " :";
	for (i = 0; i < i_quant; i++)
	{
		cout << "\n==============================" << endl;
		list[i].print_route(i_key);

	}

	cout << "\nГод? ";
	cin >> i_key;
	cout << "\nАвтобусы с пробегом больше 10 лет к " << i_key << " году:";
	for (i = 0; i < i_quant; i++)
	{
		cout << "\n==============================" << endl;
		list[i].print_age(i_key);

	}

	cout << "\nПробег? ";
	cin >> i_key;
	cout << "\nАвтобусы с пробегом больше " << i_key << " км.:";
	for (i = 0; i < i_quant; i++)
	{
		cout << "\n==============================" << endl;
		list[i].print_race(i_key);

	}

	delete[] list;
	system("@pause");
}