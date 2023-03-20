#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


//Фамилия
struct FIO
{
	char Familia[15];
	char Imya[15];
	char Papa[15];
};

//Дата рождения
struct ROJDENIE
{
	unsigned short Rday;
	unsigned short Rmonth;
	unsigned short Ryear;
};

struct POSTUPLENIE
{
	unsigned short Pday;
	unsigned short Pmonth;
	unsigned short Pyear;
};

//Предмет и оценка
struct PredmetOcenka
{
	char predmet;
	unsigned short ocenka;
};



//Структура данных
struct Student
{
	struct FIO fio;
	struct ROJDENIE date;
	struct POSTUPLENIE dateIN;
	char facult[30];
	char kafedra[20];
	char gruppa[20];
	char idzachet[20];
};


//Прототипы функций
void DataEnter(Student* (&d), int& n);
void DataPrint(Student* d, int n);
void DataChange(Student* (&d), int n);
void DataDelete(Student* (&d), int& n);
void DataAdd(Student* (&d), int& n);
void DataSave(Student* d, int n, string filename);
void DataRead(Student* (&d), int& n, string filename);


