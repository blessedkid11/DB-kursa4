#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <typeinfo>

using namespace std;


//Фамилия
struct FIO
{
	char Familia[20];
	char Imya[20];
	char Papa[20];
};

//Дата рождения
struct ROJDENIE
{
	unsigned short Rday;
	unsigned short Rmonth;
	unsigned short Ryear;
};

//Предмет и оценка
struct PredmetOcenka
{
	char predmet[20];
	int ocenka;
};

struct Session
{
	PredmetOcenka proc[11];
	int kolvo;
};



//Структура данных
struct Student
{
	struct FIO fio;
	struct ROJDENIE date;
	int datapost;
	char facult[30];
	char kafedra[20];
	char gruppa[20];
	char idzachet[20];
	char pol;
	int kolvosess;
	Session sess[100];
};



struct MenuItem
{
	string text;
	MenuItem* next;
	MenuItem* prev;

	MenuItem(string text) : text(text), next(nullptr), prev(nullptr) {}
};

class Menu {
private:
	MenuItem* firstItem;
	MenuItem* lastItem;
	MenuItem* selectedItem;

public:
	Menu() : firstItem(nullptr), lastItem(nullptr), selectedItem(nullptr) {}

	void addItem(const string& text) {
		MenuItem* newItem = new MenuItem(text);
		if (firstItem == nullptr) {
			firstItem = newItem;
			lastItem = newItem;
		}
		else {
			lastItem->next = newItem;
			newItem->prev = lastItem;
			lastItem = newItem;
		}
		if (selectedItem == nullptr) {
			selectedItem = newItem;
		}
	}

	void display() {
		system("cls");  // Очистить консоль
		MenuItem* currentItem = firstItem;
		while (currentItem != nullptr) {
			if (currentItem == selectedItem) {
				std::cout << "> " << currentItem->text << std::endl;
			}
			else {
				std::cout << "  " << currentItem->text << std::endl;
			}
			currentItem = currentItem->next;
		}
	}

	void selectNextItem() {
		if (selectedItem != nullptr && selectedItem->next != nullptr) {
			selectedItem = selectedItem->next;
		}
	}

	void selectPrevItem() {
		if (selectedItem != nullptr && selectedItem->prev != nullptr) {
			selectedItem = selectedItem->prev;
		}
	}

	string getSelectedItem() {
		if (selectedItem != nullptr) {
			return selectedItem->text;
		}
		return "";
	}
};

class DataInteraction
{
public:
	static void Copy(Student* (&d_n), Student* (&d_o), int n)
	{
		for (int i = 0; i < n; i++)
		{
			d_n[i] = d_o[i];
		}
	}
	static void DataEnter(Student* (&d), int& n) //ввод данных вручную
	{
		cout << "Введите количество студентов, про которых хотите внести информацию: ";
		while (!(cin >> n))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		d = new Student[n];

		for (int i = 0; i < n; i++)
		{
			cout << "Введите фамилию: ";
			cin >> d[i].fio.Familia;
			cout << "Введите имя: ";
			cin >> d[i].fio.Imya;
			cout << "Введите отчество: ";
			cin >> d[i].fio.Papa;

			cout << "Введите пол: ";
			cin >> d[i].pol;

			cout << "Введите дату рождения (число): ";
			while (!(cin >> d[i].date.Rday))
			{
				cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Введите дату рождения (месяц): ";
			while (!(cin >> d[i].date.Rmonth))
			{
				cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "Введите дату рождения (год): ";
			while (!(cin >> d[i].date.Ryear))
			{
				cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}

			cout << "Введите год поступления: ";
			while (!(cin >> d[i].datapost))
			{
				cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}

			cout << "Введите название факультета: ";
			cin >> d[i].facult;

			cout << "Введите название кафедры: ";
			cin >> d[i].kafedra;

			cout << "Введите номер группы: ";
			cin >> d[i].gruppa;

			cout << "Введите номер зачетной книжки: ";
			cin >> d[i].idzachet;

			cout << "О скольки сессиях хотите внести информацию?: ";
			while (!(cin >> d[i].kolvosess))
			{
				cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}

			for (int j = 0; j < d[i].kolvosess; j++)
			{
				cout << "О скольки предметах в сессии хотите внести информацию? (сессия N" << j + 1 << "): ";
				while (!(cin >> d[i].sess[j].kolvo))
				{
					cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
					cin.clear();
					cin.ignore(1000, '\n');
				}

				for (int m = 0; m < d[i].sess[j].kolvo; m++)
				{
					cout << "Введите название предмета: ";
					cin.ignore();
					cin.getline(d[i].sess[j].proc[m].predmet, 20);

					cout << "Введите оценку: ";
					while (!(cin >> d[i].sess[j].proc[m].ocenka))
					{
						cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
						cin.clear();
						cin.ignore(1000, '\n');
					}

				}
			}

			cout << "_______________________________________" << endl;
		}
	}
	static void DataRead(Student* (&d), int& n, string filename)
	{
		ifstream reading(filename); //создаем поток для чтения из файла

		if (reading)
		{
			reading.read((char*)&n, sizeof(n));;

			//выделяем память
			d = new Student[n];

			for (int i = 0; i < n; i++)
			{

				reading.read(d[i].fio.Familia, sizeof(d[i].fio.Familia));
				reading.read(d[i].fio.Imya, sizeof(d[i].fio.Imya));
				reading.read(d[i].fio.Papa, sizeof(d[i].fio.Papa));

				reading.read((char*)&d[i].pol, sizeof(d[i].pol));

				reading.read((char*)&d[i].date.Rday, sizeof(d[i].date.Rday));
				reading.read((char*)&d[i].date.Rmonth, sizeof(d[i].date.Rmonth));
				reading.read((char*)&d[i].date.Ryear, sizeof(d[i].date.Ryear));

				reading.read((char*)&d[i].datapost, sizeof(d[i].datapost));

				reading.read(d[i].facult, sizeof(d[i].facult));

				reading.read(d[i].kafedra, sizeof(d[i].kafedra));

				reading.read(d[i].gruppa, sizeof(d[i].gruppa));

				reading.read(d[i].idzachet, sizeof(d[i].idzachet));;

				reading.read((char*)&d[i].kolvosess, sizeof(d[i].kolvosess));;

				for (int j = 0; j < d[i].kolvosess; j++)
				{
					reading.read((char*)&d[i].sess[j].kolvo, sizeof(d[i].sess[j].kolvo));

					for (int m = 0; m < d[i].sess[j].kolvo; m++)
					{
						reading.read((char*)&d[i].sess[j].proc[m].predmet, sizeof(d[i].sess[j].proc[m].predmet));
						reading.read((char*)&d[i].sess[j].proc[m].ocenka, sizeof(d[i].sess[j].proc[m].ocenka));
					}
				}


			}
			cout << "Данные считаны!" << endl;

		}
		else
			cout << "Ошибка открыти файла!" << endl;

		reading.close();
	}
	static void DataPrint(Student* d, int n)//вывод данных
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Данные N" << i + 1 << endl;

			cout << "ФИО студента: " << d[i].fio.Familia << " " << d[i].fio.Imya << " " << d[i].fio.Papa << endl;

			cout << "Пол: " << d[i].pol << endl;

			cout << "Дата рождения: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear << endl;

			cout << "Год поступления: " << d[i].datapost << endl;

			cout << "Название факультета : " << d[i].facult << endl;

			cout << "Название кафедры: " << d[i].kafedra << endl;

			cout << "Номер группы: " << d[i].gruppa << endl;

			cout << "Номер зачетной книжки: " << d[i].idzachet << endl;

			for (int j = 0; j < d[i].kolvosess; j++)
			{
				cout << "Сессия N";
				cout << j + 1 << ":" << endl;

				for (int m = 0; m < d[i].sess[j].kolvo; m++)
				{
					cout << "Название предмета: " << d[i].sess[j].proc[m].predmet;
					cout << "   ";
					cout << "Оценка: " << d[i].sess[j].proc[m].ocenka << endl;
				}
			}

			cout << "_______________________________________" << endl;
		}
	}
	static void DataChange(Student* (&d), int n) //изменение данных
	{
		int nn;
		cout << "Введите номер элемента (от 1 до " << n << "): ";
		while (!(cin >> nn))
		{
			cout << "Некорректный ввод. Пожалуйста, введите номер записи: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		nn--;

		string sMenu;
		int iMenu = -99;

		system("cls");//очистка консоли

		//проверка что значение введено верно
		if (nn >= 0 && nn < n)
		{
			for (int i = 0; i < n; i++)
			{
				for (; iMenu != 0;)
				{
					cout << "Укажите: \n";
					cout << "1: Изменить ФИО \n";
					cout << "2: Изменить пол \n";
					cout << "3: Изменить дату рождения \n";
					cout << "4: Изменить год поступления\n";
					cout << "5: Изменить дату рождения \n";
					cout << "6. Изменить название института \n";
					cout << "7: Изменить название кафедры \n";
					cout << "8: Изменить номер группы \n";
					cout << "9: Изменить номер зачетной книжки \n";
					cout << "10: Изменить информацию о сессиях \n";
					cout << "0: Выход \n";
					cout << "Введите номер пункта меню: ";
					cin >> sMenu;
					iMenu = stoi(sMenu);

					switch (iMenu)
					{
					case 0:
						break;

					case 1:
						system("cls");//очистка консоли
						cout << "Введите фамилию: ";
						cin >> d[nn].fio.Familia;
						cout << "Введите имя: ";
						cin >> d[nn].fio.Imya;
						cout << "Введите отчество: ";
						cin >> d[nn].fio.Papa;
						system("cls");//очистка консоли
						break;

					case 2:
						system("cls");//очистка консоли
						cout << "Введите пол: ";
						cin >> d[nn].pol;
						system("cls");//очистка консоли
						break;

					case 3:
						system("cls");//очистка консоли
						cout << "Введите дату рождения (число): ";
						while (!(cin >> d[nn].date.Rday))
						{
							cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
							cin.clear();
							cin.ignore(1000, '\n');
						}
						cout << "Введите дату рождения (месяц): ";
						while (!(cin >> d[nn].date.Rmonth))
						{
							cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
							cin.clear();
							cin.ignore(1000, '\n');
						}
						cout << "Введите дату рождения (год): ";
						while (!(cin >> d[nn].date.Ryear))
						{
							cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
							cin.clear();
							cin.ignore(1000, '\n');
						}
						system("cls");//очистка консоли
						break;

					case 4:
						system("cls");//очистка консоли
						cout << "Введите год поступления: ";
						while (!(cin >> d[nn].datapost))
						{
							cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
							cin.clear();
							cin.ignore(1000, '\n');
						}
						system("cls");//очистка консоли
						break;

					case 5:
						system("cls");//очистка консоли
						cout << "Введите название факультета: ";
						cin >> d[nn].facult;
						system("cls");//очистка консоли
						break;

					case 6:
						system("cls");//очистка консоли
						cout << "Введите название института: ";
						cin >> d[nn].facult;
						system("cls");//очистка консоли
						break;

					case 7:
						system("cls");//очистка консоли
						cout << "Введите название кафедры: ";
						cin >> d[nn].kafedra;
						system("cls");//очистка консоли
						break;
					case 8:
						system("cls");//очистка консоли
						cout << "Введите номер группы: ";
						cin >> d[nn].gruppa;
						system("cls");//очистка консоли
						break;
					case 9:
						system("cls");//очистка консоли
						cout << "Введите номер зачетной книжки: ";
						cin >> d[nn].idzachet;
						system("cls");//очистка консоли
						break;
					case 10:
						system("cls");//очистка консоли
						cout << "О скольки сессиях хотите внести информацию?: ";
						while (!(cin >> d[nn].kolvosess))
						{
							cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
							cin.clear();
							cin.ignore(1000, '\n');
						}

						for (int j = 0; j < d[nn].kolvosess; j++)
						{
							cout << "О скольки предметах в сессии хотите внести информацию? (сессия N" << j + 1 << "): ";
							while (!(cin >> d[nn].sess[j].kolvo))
							{
								cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
								cin.clear();
								cin.ignore(1000, '\n');
							}

							for (int m = 0; m < d[nn].sess[j].kolvo; m++)
							{
								cout << "Введите название предмета: ";
								cin.ignore();
								cin.getline(d[nn].sess[j].proc[m].predmet, 20);

								cout << "Введите оценку: ";
								while (!(cin >> d[nn].sess[j].proc[m].ocenka))
								{
									cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
									cin.clear();
									cin.ignore(1000, '\n');
								}

							}
						}
						system("cls");//очистка консоли
						break;
					}
				}
			}
			system("cls");//очистка консоли

			cout << "Данные изменены!" << endl;
		}
		else
			cout << "Номер записи введен невероно!" << endl;

	}
	static void DataDelete(Student* (&d), int& n) //удаление данных
	{
		int nn;
		cout << "Введите номер элемента (от 1 до " << n << "): ";
		while (!(cin >> nn))
		{
			cout << "Некорректный ввод. Пожалуйста, введите номер записи: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		nn--;

		system("cls");//очистка консоли

		//проверка что значение введено верно
		if (nn >= 0 && nn < n)
		{
			Student* TempMas = new Student[n]; //временный массив

			Copy(TempMas, d, n);

			--n;
			d = new Student[n]; //новая память

			int q = 0;

			//запоминаем данные
			for (int i = 0; i <= n; i++)
			{
				if (i != nn)
				{
					d[q] = TempMas[i];
					++q;
				}
			}

			system("cls");//очистка консоли
			delete[]TempMas;//очистка временного массива

			cout << "Данные удалены!" << endl;
		}
		else
			cout << "Номер записи введен невероно!" << endl;
	}
	static void DataAdd(Student* (&d), int& n) //добавление данных
	{
		Student* TempMas = new Student[n]; //временный массив

		Copy(TempMas, d, n); //сохраняем данные в временный массив

		n++;
		d = new Student[n]; //новая память

		Copy(d, TempMas, --n); //возвращаем данные

		cout << "Введите фамилию: ";
		cin >> d[n].fio.Familia;
		cout << "Введите имя: ";
		cin >> d[n].fio.Imya;
		cout << "Введите отчество: ";
		cin >> d[n].fio.Papa;

		cout << "Введите пол: ";
		cin >> d[n].pol;

		cout << "Введите дату рождения (число): ";
		while (!(cin >> d[n].date.Rday))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Введите дату рождения (месяц): ";
		while (!(cin >> d[n].date.Rmonth))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Введите дату рождения (год): ";
		while (!(cin >> d[n].date.Ryear))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "Введите год поступления: ";
		while (!(cin >> d[n].datapost))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "Введите название факультета: ";
		cin >> d[n].facult;

		cout << "Введите название кафедры: ";
		cin >> d[n].kafedra;

		cout << "Введите номер группы: ";
		cin >> d[n].gruppa;

		cout << "Введите номер зачетной книжки: ";
		cin >> d[n].idzachet;

		cout << "О скольки сессиях хотите внести информацию?: ";
		while (!(cin >> d[n].kolvosess))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		for (int j = 0; j < d[n].kolvosess; j++)
		{
			cout << "О скольки предметах в сессии хотите внести информацию? (сессия N" << j + 1 << "): ";
			while (!(cin >> d[n].sess[j].kolvo))
			{
				cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}

			for (int m = 0; m < d[n].sess[j].kolvo; m++)
			{
				cout << "Введите название предмета: ";
				cin.ignore();
				cin.getline(d[n].sess[j].proc[m].predmet, 20);

				cout << "Введите оценку: ";
				while (!(cin >> d[n].sess[j].proc[m].ocenka))
				{
					cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
					cin.clear();
					cin.ignore(1000, '\n');
				}

			}
		}

		delete[]TempMas;
	}
	static void DataSave(Student* d, int n, string filename) //сохранение данных
	{
		ofstream record(filename, ios::binary); //создание потока для записи пустого

		if (record)
		{
			record.write((char*)&n, sizeof(n));
			for (int i = 0; i < n; i++)
			{

				record.write(d[i].fio.Familia, sizeof(d[i].fio.Familia));
				record.write(d[i].fio.Imya, sizeof(d[i].fio.Imya));
				record.write(d[i].fio.Papa, sizeof(d[i].fio.Papa));

				record.write((char*)&d[i].pol, sizeof(d[i].pol));

				record.write((char*)&d[i].date.Rday, sizeof(d[i].date.Rday));
				record.write((char*)&d[i].date.Rmonth, sizeof(d[i].date.Rmonth));
				record.write((char*)&d[i].date.Ryear, sizeof(d[i].date.Ryear));

				record.write((char*)&d[i].datapost, sizeof(d[i].datapost));

				record.write(d[i].facult, sizeof(d[i].facult));

				record.write(d[i].kafedra, sizeof(d[i].kafedra));

				record.write(d[i].gruppa, sizeof(d[i].gruppa));

				record.write(d[i].idzachet, sizeof(d[i].idzachet));;

				record.write((char*)&d[i].kolvosess, sizeof(d[i].kolvosess));;

				for (int j = 0; j < d[i].kolvosess; j++)
				{
					record.write((char*)&d[i].sess[j].kolvo, sizeof(d[i].sess[j].kolvo));

					for (int m = 0; m < d[i].sess[j].kolvo; m++)
					{
						record.write((char*)&d[i].sess[j].proc[m].predmet, sizeof(d[i].sess[j].proc[m].predmet));
						record.write((char*)&d[i].sess[j].proc[m].ocenka, sizeof(d[i].sess[j].proc[m].ocenka));
					}
				}
			}
			cout << "Данные сохранены!" << endl;
		}
		else
			cout << "Ошибка сохранения файла!" << endl;
		record.close();
	}
	static void Zadanie(Student* d, int n)
	{
		unsigned short a, b;
		a = -111;
		b = -111;
		cout << "Введите интервал года рождения (от): ";
		while (!(cin >> a))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Введите интервал года рождения (до): ";
		while (!(cin >> b))
		{
			cout << "Некорректный ввод. Пожалуйста, введите целое число: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		int choice;
		cout << "Вы хотите узнать успеваемость за все сессии (1) или за определенную (2)?: ";
		while (!(cin >> choice))
		{
			cout << "Некорректный ввод. Пожалуйста, выберите пункт меню: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		if (choice == 1)
		{
			for (int i = 0; i < n; i++)
			{
				float k = 0;
				for (int f = 0; f < d[i].kolvosess; f++)
				{
					k += d[i].sess[f].kolvo;
				}

				float c = 0;
				if (a <= d[i].date.Ryear && d[i].date.Ryear <= b)
				{
					for (int j = 0; j < d[i].kolvosess; j++)
					{
						for (int h = 0; h < d[i].sess[j].kolvo; h++)
						{
							if (d[i].sess[j].proc[h].ocenka == 3)
							{
								c += 1;
							}
						}
					}

					if (c / k <= 0.25)
					{
						cout << "Данные N" << i + 1 << endl;

						cout << "ФИО студента: " << d[i].fio.Familia << " " << d[i].fio.Imya << " " << d[i].fio.Papa << endl;

						cout << "Пол: " << d[i].pol << endl;

						cout << "Дата рождения: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear << endl;

						cout << "Год поступления: " << d[i].datapost << endl;

						cout << "Название факультета : " << d[i].facult << endl;

						cout << "Название кафедры: " << d[i].kafedra << endl;

						cout << "Номер группы: " << d[i].gruppa << endl;

						cout << "Номер зачетной книжки: " << d[i].idzachet << endl;

						for (int l = 0; l < d[i].kolvosess; l++)
						{
							cout << "Сессия N";
							cout << l + 1 << ":";

							for (int v = 0; v < d[i].sess[l].kolvo; v++)
							{
								cout << "Название предмета: ";
								cout << d[i].sess[l].proc[v].predmet;
								cout << "   ";
								cout << "Оценка: ";
								cout << d[i].sess[l].proc[v].ocenka << endl;
							}
						}
					}


				}

				else
				{

				}
			}
		}

		if (choice == 2)
		{
			int choice1;
			cout << "Введите номер сессии: ";
			while (!(cin >> choice1))
			{
				cout << "Некорректный ввод. Пожалуйста, введите номер сессии: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}

			for (int i = 0; i < n; i++)
			{
				float k = 0;
				k += d[i].sess[choice1 - 1].kolvo;


				float c = 0;
				if (a <= d[i].date.Ryear && d[i].date.Ryear <= b)
				{

					for (int h = 0; h < d[i].sess[choice1 - 1].kolvo; h++)
					{
						if (d[i].sess[choice1 - 1].proc[h].ocenka == 3)
						{
							c += 1;
						}
					}

					if (c / k <= 0.25 && choice1 <= d[i].kolvosess)
					{
						cout << "Данные N" << i + 1 << endl;

						cout << "ФИО студента: " << d[i].fio.Familia << " " << d[i].fio.Imya << " " << d[i].fio.Papa << endl;

						cout << "Пол: " << d[i].pol << endl;

						cout << "Дата рождения: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear << endl;

						cout << "Год поступления: " << d[i].datapost << endl;

						cout << "Название факультета : " << d[i].facult << endl;

						cout << "Название кафедры: " << d[i].kafedra << endl;

						cout << "Номер группы: " << d[i].gruppa << endl;

						cout << "Номер зачетной книжки: " << d[i].idzachet << endl;

						for (int l = 0; l < d[i].kolvosess; l++)
						{
							cout << "Сессия N";
							cout << l + 1 << ":";

							for (int v = 0; v < d[i].sess[l].kolvo; v++)
							{
								cout << "Название предмета: ";
								cout << d[i].sess[l].proc[v].predmet;
								cout << "   ";
								cout << "Оценка: ";
								cout << d[i].sess[l].proc[v].ocenka << endl;
							}
						}

						cout << "_______________________________________________________________" << endl;
					}


				}

				else
				{

				}
			}
		}

	}
};
