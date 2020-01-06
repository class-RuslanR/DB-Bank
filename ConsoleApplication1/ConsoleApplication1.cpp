#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Custominfo;
template <typename B, typename Bcount>
class Bank;

class Custominfo
{
	string name;
	string surname;
	string secondname;
	int number;
public:
	Custominfo();
	Custominfo(string varName, string varSurname, string varSecondname, int varNumber)
	{
		name = varName;
		surname = varSurname;
		secondname = varSecondname;
		number = varNumber;
	}
	string getName();
	string getSurname();
	string getSecondname();
	int getCount();
	void * operator new (size_t size);
	void operator delete (void * m);
	void printMan();
};

Custominfo::Custominfo()
{
	name = "Name";
	surname = "Surname";
	secondname = "Secondname";
	number = 0;
}

string Custominfo::getName()
{
	cout << "Имя: ";
	cin >> name;
	return name;
}

string Custominfo::getSurname()
{
	cout << "Фамилия: ";
	cin >> surname;
	return surname;
}

string Custominfo::getSecondname()
{
	cout << "Отчество: ";
	cin >> secondname;
	return secondname;
}

int Custominfo::getCount()
{
	cout << "Номер счета: ";
	cin >> number;
	return number;
}

/////////////////////////////////////////////////////////////////////

template <typename B, typename Bcount>
class Bank
{
	B name;
	B surname;
	B secondname;
	Bcount number;
public:

	friend Custominfo;
	Bank();
	Bank(B enterName, B enterSurname, B enterSecondname, Bcount enterNumber);
	friend void * Custominfo :: operator new (size_t size);
	friend void Custominfo :: operator delete (void * m);
	void printMan()
	{
		for (int i = 1; i <= 5; i++)
		{
			cout << "\n\nИмя: " << name << endl;
			cout << "Фамилия: " << surname << endl;
			cout << "Отчество: " << secondname << endl;
			cout << "Номер счета: " << number << endl;
		}
	}
	friend Bank sortAlphabet(Bank *sortSurname, int size)
	{
		string buf;
		for (int j = 1; j < size; j++)
		{
			for (int i = 0; i < size - j; i++)
			{
				if (strcmp(sortSurname.surname[i], sortSurname.surname[i + 1]) == 1)
				{
					strcpy(buf, sortSurname.surname[i]);
					strcpy(sortSurname.surname[i], sortSurname.surname[i + 1]);
					strcpy(sortSurname.surname[i + 1], buf);
				}
			}
		}
		friend void Custominfo::printMan();
	}


	/*void printMan1()
	{
		cout << "\n\nИмя: " << name << endl;
		cout << "Фамилия: " << surname << endl;
		cout << "Отчество: " << secondname << endl;
		cout << "Номер счета: " << number << endl;
	}

	void printMan2()
	{
		cout << "\n\nИмя: " << name << endl;
		cout << "Фамилия: " << surname << endl;
		cout << "Отчество: " << secondname << endl;
		cout << "Номер счета: " << number << endl;
	}

	void printMan3()
	{
		cout << "\n\nИмя: " << name << endl;
		cout << "Фамилия: " << surname << endl;
		cout << "Отчество: " << secondname << endl;
		cout << "Номер счета: " << number << endl;
	}

	void printMan4()
	{
		cout << "\n\nИмя: " << name << endl;
		cout << "Фамилия: " << surname << endl;
		cout << "Отчество: " << secondname << endl;
		cout << "Номер счета: " << number << endl;
	}

	void printMan5()
	{
		cout << "\n\nИмя: " << name << endl;
		cout << "Фамилия: " << surname << endl;
		cout << "Отчество: " << secondname << endl;
		cout << "Номер счета: " << number << endl;
	}*/
};

template <typename B, typename Bcount> Bank <B, Bcount> ::Bank()
{

}

template <typename B, typename Bcount> Bank <B, Bcount> ::Bank(B enterName, B enterSurname, B enterSecondname, Bcount enterNumber)
{
	name = enterName;
	surname = enterSurname;
	secondname = enterSecondname;
	number = enterNumber;
}

void * Custominfo :: operator new (size_t size)
{
	void *m;
	m = malloc(size);
	if (m == 0)
	{
		cout << "Память не выделена" << endl;
		return 0;
	}
	else
	{
		return m;
	}
}

void Custominfo :: operator delete (void * m)
{
	free(m);
}

//void Custominfo :: printMan()



int main()
{
	setlocale(LC_ALL, "ru");

	string Name, Surname, Secondname;
	int count;

	Custominfo *man[5];
	Custominfo maninfo;

	for (int i = 1; i <= 5; i++)
	{
		cout << "\n\tКлиент № " << i << "\n" << endl;
		Name = maninfo.getName();
		Surname = maninfo.getSurname();
		Secondname = maninfo.getSecondname();
		count = maninfo.getCount();
		man[i] = new Custominfo(Name, Surname, Secondname, count);
		Bank <string, int> enterMan(Name, Surname, Secondname, count);
		delete man[i];
	}

	Bank <string, int> showMan(Name, Surname, Secondname, count);
	showMan.printMan();


	//Custominfo fromTemplShow;
	//fromTemplShow.printMan();

	//Custominfo sortSurname;
	//sortSurname.sortAlphabet(Surname[5], 5);




	/*cout << "\n\tКлиент №1\n" << endl;
		Name = maninfo.getName();
		Surname = maninfo.getSurname();
		Secondname = maninfo.getSecondname();
		count = maninfo.getCount();
		man[1] = new Custominfo(Name, Surname, Secondname, count);
		Bank <string, int> man1 (Name, Surname, Secondname, count);
		delete man[1];

	cout << "\n\tКлиент №2\n" << endl;

		Name = maninfo.getName();
		Surname = maninfo.getSurname();
		Secondname = maninfo.getSecondname();
		count = maninfo.getCount();
		man[2] = new Custominfo(Name, Surname, Secondname, count);
		Bank <string, int> man2(Name, Surname, Secondname, count);
		delete man[2];

	cout << "\n\tКлиент №3\n" << endl;

		Name = maninfo.getName();
		Surname = maninfo.getSurname();
		Secondname = maninfo.getSecondname();
		count = maninfo.getCount();
		man[3] = new Custominfo(Name, Surname, Secondname, count);
		Bank <string, int> man3(Name, Surname, Secondname, count);
		delete man[3];

	cout << "\n\tКлиент №4\n" << endl;

		Name = maninfo.getName();
		Surname = maninfo.getSurname();
		Secondname = maninfo.getSecondname();
		count = maninfo.getCount();
		man[4] = new Custominfo(Name, Surname, Secondname, count);
		Bank <string, int> man4(Name, Surname, Secondname, count);
		delete man[4];

	cout << "\n\tКлиент №5\n" << endl;

		Name = maninfo.getName();
		Surname = maninfo.getSurname();
		Secondname = maninfo.getSecondname();
		count = maninfo.getCount();
		man[5] = new Custominfo(Name, Surname, Secondname, count);
		Bank <string, int> man5(Name, Surname, Secondname, count);
		delete man[5];*/

		/*man1.printMan1();
		man2.printMan2();
		man3.printMan3();
		man4.printMan4();
		man5.printMan5();*/
	return 0;
}
