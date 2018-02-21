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
		cout << "\n������� ��� ��������: ";
		getline(cin, s_name);
		cout << "\n������� ����� ��������: ";
		getline(cin, s_brand);
		cout << "\n������� ����� ��������: ";
		cin >> i_number;
		cout << "\n������� ������� ��������: ";
		cin >> i_route;
		cout << "\n������� ��� ������� ��������: ";
		cin >> i_year;
		cout << "\n������� ������ ��������: ";
		cin >> i_race;
	}

	void print();
	void print_route(int i_key);
	void print_age(int i_key);
	void print_race(int i_key);
};

void driver::print()
{
	cout << "\n���: " << s_name;
	cout << "\n�����: " << s_brand;
	cout << "\n�����: " << i_number;
	cout << "\n�������: " << i_route;
	cout << "\n���: " << i_year;
	cout << "\n������: " << i_race;
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
	cout << "\n������� ����� ���������: ";
	cin >> i_quant;
	driver *list = new driver[i_quant];
	for (i = 0; i < i_quant; i++)
	{
		cout << "\n==============================" << endl;
		list[i].print();

	}

	cout << "\n����� ��������? ";
	cin >> i_key;
	cout << "\n�������� � ��������� " << i_key << " :";
	for (i = 0; i < i_quant; i++)
	{
		cout << "\n==============================" << endl;
		list[i].print_route(i_key);

	}

	cout << "\n���? ";
	cin >> i_key;
	cout << "\n�������� � �������� ������ 10 ��� � " << i_key << " ����:";
	for (i = 0; i < i_quant; i++)
	{
		cout << "\n==============================" << endl;
		list[i].print_age(i_key);

	}

	cout << "\n������? ";
	cin >> i_key;
	cout << "\n�������� � �������� ������ " << i_key << " ��.:";
	for (i = 0; i < i_quant; i++)
	{
		cout << "\n==============================" << endl;
		list[i].print_race(i_key);

	}

	delete[] list;
	system("@pause");
}