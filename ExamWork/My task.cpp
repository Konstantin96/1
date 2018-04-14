#include<iostream>
#include <ctime>  
#include <stdlib.h> 
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct person
{
	string surname;
	string name;
	string patronymic;
	string position;
	int age;
	double wages;
};
vector <person> mas;
int razmer = 0;

void Read()
{
	system("pause");
	system("cls");

	int n;
	cout << "������� �������� ����������� ����� �������? "; cin >> n;
	razmer = n;
	person temp;
	for (int i = 0; i<n; i++)
	{
		cout << "��� ����� ����� ������ ������: ������, ���, ��������, ���������, ��� ��������, ��������. " << endl;
		cout << "����� ���������� ���������� ���������, ������� ���������� � ���������� �������� ������. " << endl;
		cout << "��������� � " << (i + 1) << endl;
		cout << "������� �������: ";    
		cin >> temp.surname;
		cout << "������� ���: ";
		cin >> temp.name;
		cout << "������� ��������: ";
		cin >> temp.patronymic;
		cout << "������� ���������: ";
		cin >> temp.position;
		cout << "������� ���� ��������: ";
		cin >> temp.age;
		cout << "������� ��������: ";
		cin >> temp.wages;
		mas.push_back(temp);
		system("cls");
	}

}

void ToFail(vector<person> &mas, string &name)
{
	std::ofstream fs(name, std::ios::binary);

	if (!fs.is_open())
	{
		std::cout << "���� " << name << "�� ��� ������ ��� ������";
		return;
	}


	int size = mas.size();
	cout << "���-�� �����������: " << size << endl;
	if (size == 0)
	{
		cout << " ������ ����." << endl;
		return;
	}
	else
		for (int i = 0; i<size; i++)
		{

			fs << mas[i].surname << " "
				<< mas[i].name << " "
				<< mas[i].patronymic << " "
				<< mas[i].position << " " << mas[i].age
				<< " " << mas[i].wages << endl;
		}

	fs.close();
}


void Display(string &name, int&razmer)
{
	person tmp;
	ifstream fs(name, ios::binary);
	if (!fs.is_open())
	{
		std::cout << "���� " << name << "�� ��� ������ ��� ������";
		return;
	}
	
	for (int i = 0; i < razmer; i++)
	{
		fs >> tmp.surname;
		fs >> tmp.name;
		fs >> tmp.patronymic;
		fs >> tmp.position;
		fs >> tmp.age;
		fs >> tmp.wages;
		cout << "===========================" << endl;
		cout << "��������� �" << (i + 1) << endl << "�������: " << tmp.surname << endl << " ���: " << tmp.name << endl << " ��������: " << tmp.patronymic << endl << " ���������: " << tmp.position << endl << " ���� ��������: " << tmp.age << endl << " ��������: " << tmp.wages << "\n";
		if (fs.eof())break;
	}
	fs.close();
}

void Delet(string &name, string name2, int&razmer)
{
	string fam;
	cout << "������� ������� ��� ��������: "; cin >> fam; cout << endl;
	person tmp;
	ifstream fs(name, ios::binary);
	if (!fs.is_open())
	{
		std::cout << "���� " << name << "�� ��� ������ ��� ������";
		return;
	}
	for (int i = 0; i < razmer; i++)
	{
		fs >> tmp.surname;
		fs >> tmp.name;
		fs >> tmp.patronymic;
		fs >> tmp.position;
		fs >> tmp.age;
		fs >> tmp.wages;
		if (fs.eof())break;
	}
	fs.close();
}




int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "Russian");

	string name, name2, fam;
	Read(); 
	cout << "������� �������� ����� � ������� ����� ��������� ���������: "; cin >> name; cout << endl;
	ToFail(mas, name);
	Display(name, razmer);
	cout << "������� �������� ����� � ������� ����� ��������� ��������� ����������: "; cin >> name; cout << endl;
	Delet(name,name2,razmer);

	system("pause");
	return 0;
}
