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
	cout << "Сколько карточек сотрудников будет создано? "; cin >> n;
	razmer = n;
	person temp;
	for (int i = 0; i<n; i++)
	{
		cout << "Вам нужно будет ввести данные: Фамили, имя, отчество, должность, год рождения, зарплату. " << endl;
		cout << "После заполнения последнего параметра, консоль очиститься и заполнение начнется заного. " << endl;
		cout << "Сотрудник № " << (i + 1) << endl;
		cout << "Введите Фамилию: ";    
		cin >> temp.surname;
		cout << "Введите Имя: ";
		cin >> temp.name;
		cout << "Введите Отчество: ";
		cin >> temp.patronymic;
		cout << "Введите Должность: ";
		cin >> temp.position;
		cout << "Введите Дату рождения: ";
		cin >> temp.age;
		cout << "Введите зарплату: ";
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
		std::cout << "Файл " << name << "не был открыт для записи";
		return;
	}


	int size = mas.size();
	cout << "Кол-во Сотрудников: " << size << endl;
	if (size == 0)
	{
		cout << " Вектор пуст." << endl;
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
		std::cout << "Файл " << name << "не был открыт для чтения";
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
		cout << "Сотрудник №" << (i + 1) << endl << "Фамилия: " << tmp.surname << endl << " Имя: " << tmp.name << endl << " Отчество: " << tmp.patronymic << endl << " Должность: " << tmp.position << endl << " Дата рождения: " << tmp.age << endl << " Зарплата: " << tmp.wages << "\n";
		if (fs.eof())break;
	}
	fs.close();
}

void Delet(string &name, string name2, int&razmer)
{
	string fam;
	cout << "Введите Фамилию для удаления: "; cin >> fam; cout << endl;
	person tmp;
	ifstream fs(name, ios::binary);
	if (!fs.is_open())
	{
		std::cout << "Файл " << name << "не был открыт для чтения";
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
	cout << "Введите название файла в который будет сохранена структура: "; cin >> name; cout << endl;
	ToFail(mas, name);
	Display(name, razmer);
	cout << "Введите название файла в который будет сохранена удаляемая информация: "; cin >> name; cout << endl;
	Delet(name,name2,razmer);

	system("pause");
	return 0;
}
