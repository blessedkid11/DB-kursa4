#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;


struct FIO
{
	char Familia[15];
	char Imya[15];
	char Papa[15];
};

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

struct PredmetOcenka
{
	char predmet[20];
	unsigned short ocenka;
};

struct Session
{
	PredmetOcenka proc[11];
	int kolvo;
};


struct Student
{
	struct FIO fio;
	struct ROJDENIE date;
	struct POSTUPLENIE dateIN;
	char facult[30];
	char kafedra[20];
	char gruppa[20];
	char idzachet[20];
	char pol;
	int kolvosess;
	Session sess[100];
};


void DataEnter(Student* (&d), int& n);
void DataPrint(Student* d, int n);
void DataChange(Student* (&d), int n);
void DataDelete(Student* (&d), int& n);
void DataAdd(Student* (&d), int& n);
void DataSave(Student* d, int n, string filename);
void DataRead(Student* (&d), int& n, string filename);
void Zadanie(Student* d, int n);


