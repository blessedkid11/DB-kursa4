#include "Func.h"

void Copy(Student* (&d_n), Student* (&d_o), int n) //копирование в новый массив
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}
}

void DataEnter(Student* (&d), int& n) //ввод данных вручную
{
	cout << "Введите количество студентов, про которых хотите внести информацию: ";
	cin >> n;

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
		cin >> d[i].date.Rday;
		cout << "Введите дату рождения (месяц): ";
		cin >> d[i].date.Rmonth;
		cout << "Введите дату рождения (год): ";
		cin >> d[i].date.Ryear;

		cout << "Введите дату поступления (число): ";
		cin >> d[i].dateIN.Pday;
		cout << "Введите дату поступления (месяц): ";
		cin >> d[i].dateIN.Pmonth;
		cout << "Введите дату поступления (год): ";
		cin >> d[i].dateIN.Pyear;

		cout << "Введите название факультета: ";
		cin >> d[i].facult;

		cout << "Введите название кафедры: ";
		cin >> d[i].kafedra;

		cout << "Введите номер группы: ";
		cin >> d[i].gruppa;

		cout << "Введите номер зачетной книжки: ";
		cin >> d[i].idzachet;

		cout << "О скольки сессиях хотите внести информацию?: ";
		cin >> d[i].kolvosess;

		for (int j = 0; j < d[i].kolvosess; j++)
		{
			cout << "О скольки предметах в сессии хотите внести информацию? (сессия N" << j + 1 << "): ";
			cin >> d[i].sess[j].kolvo;

			for (int m = 0; m < d[i].sess[j].kolvo; m++)
			{
				cout << "Введите название предмета: ";
				cin >> d[i].sess[j].proc[m].predmet;
				cout << "Введите оценку: ";
				cin >> d[i].sess[j].proc[m].ocenka;
			}
		}

		cout << "_______________________________________" << endl;
	}
}

void DataRead(Student* (&d), int& n, string filename)
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

			reading.read((char*)&d[i].dateIN.Pday, sizeof(d[i].dateIN.Pday));
			reading.read((char*)&d[i].dateIN.Pmonth, sizeof(d[i].dateIN.Pmonth));
			reading.read((char*)&d[i].dateIN.Pyear, sizeof(d[i].dateIN.Pyear));

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

void DataPrint(Student* d, int n)//вывод данных
{
	for (int i = 0; i < n; i++)
	{
		cout << "Данные N" << i + 1 << endl;

		cout << "ФИО студента: " << d[i].fio.Familia << " " << d[i].fio.Imya << " " << d[i].fio.Papa << endl;

		cout << "Пол: " << d[i].pol << endl;

		cout << "Дата рождения: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear << endl;

		cout << "Дата поступления: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear << endl;

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

void DataChange(Student* (&d), int n) //изменение данных
{
	int nn;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> nn;
	nn--;

	system("cls");//очистка консоли

	//проверка что значение введено верно
	if (nn >= 0 && nn < n)
	{
		cout << "Введите фамилию: ";
		cin >> d[nn].fio.Familia;
		cout << "Введите имя: ";
		cin >> d[nn].fio.Imya;
		cout << "Введите отчество: ";
		cin >> d[nn].fio.Papa;

		cout << "Введите пол: ";
		cin >> d[nn].pol;

		cout << "Введите дату рождения (число): ";
		cin >> d[nn].date.Rday;
		cout << "Введите дату рождения (месяц): ";
		cin >> d[nn].date.Rmonth;
		cout << "Введите дату рождения (год): ";
		cin >> d[nn].date.Ryear;

		cout << "Введите дату поступления (число): ";
		cin >> d[nn].dateIN.Pday;
		cout << "Введите дату поступления (месяц): ";
		cin >> d[nn].dateIN.Pmonth;
		cout << "Введите дату поступления (год): ";
		cin >> d[nn].dateIN.Pyear;

		cout << "Введите название факультета: ";
		cin >> d[nn].facult;

		cout << "Введите название кафедры: ";
		cin >> d[nn].kafedra;

		cout << "Введите номер группы: ";
		cin >> d[nn].gruppa;

		cout << "Введите номер зачетной книжки: ";
		cin >> d[nn].idzachet;

		cout << "О скольки сессиях хотите внести информацию?: ";
		cin >> d[nn].kolvosess;

		for (int j = 0; j < d[nn].kolvosess; j++)
		{
			cout << "О скольки предметах в сессии хотите внести информацию? (сессия N" << j + 1 << "): ";
			cin >> d[nn].sess[j].kolvo;

			for (int m = 0; m < d[nn].sess[j].kolvo; m++)
			{
				cout << "Введите название предмета: ";
				cin >> d[nn].sess[j].proc[m].predmet;
				cout << "Введите оценку: ";
				cin >> d[nn].sess[j].proc[m].ocenka;
			}
		}

		system("cls");//очистка консоли

		cout << "Данные изменены!" << endl;
	}
	else
		cout << "Номер записи введен невероно!" << endl;

}

void DataDelete(Student* (&d), int& n) //удаление данных
{
	int nn;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> nn;
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

void DataAdd(Student* (&d), int& n) //добавление данных
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

	cout << "Введите дату рождения(число): ";
	cin >> d[n].date.Rday;
	cout << "Введите дату рождения(месяц): ";
	cin >> d[n].date.Rmonth;
	cout << "Введите дату рождения(год): ";
	cin >> d[n].date.Ryear;

	cout << "Введите дату поступления(число): ";
	cin >> d[n].dateIN.Pday;
	cout << "Введите дату поступления(месяц): ";
	cin >> d[n].dateIN.Pmonth;
	cout << "Введите дату поступления(год): ";
	cin >> d[n].dateIN.Pyear;

	cout << "Введите название факультета: ";
	cin >> d[n].facult;

	cout << "Введите название кафедры: ";
	cin >> d[n].kafedra;

	cout << "Введите номер группы: ";
	cin >> d[n].gruppa;

	cout << "Введите номер зачетной книжки: ";
	cin >> d[n].idzachet;

	cout << "О скольки сессиях хотите внести информацию?: ";
	cin >> d[n].kolvosess;

	for (int j = 0; j < d[n].kolvosess; j++)
	{
		cout << "О скольки предметах в сессии хотите внести информацию? (сессия N" << j + 1 << "): ";
		cin >> d[n].sess[j].kolvo;

		for (int m = 0; m < d[n].sess[j].kolvo; m++)
		{
			cout << "Введите название предмета: ";
			cin >> d[n].sess[j].proc[m].predmet;
			cout << "Введите оценку: ";
			cin >> d[n].sess[j].proc[m].ocenka;
		}
	}

	delete[]TempMas;
}

void DataSave(Student* d, int n, string filename) //сохранение данных
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

			record.write((char*)&d[i].dateIN.Pday, sizeof(d[i].dateIN.Pday));
			record.write((char*)&d[i].dateIN.Pmonth, sizeof(d[i].dateIN.Pmonth));
			record.write((char*)&d[i].dateIN.Pyear, sizeof(d[i].dateIN.Pyear));

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
	}
	else
		cout << "Ошибка сохранения файла!" << endl;
	record.close();
}

void Zadanie(Student* d, int n)
{
	unsigned short a, b;
	cout << "Введите интервал года рождения (от): ";
	cin >> a;
	cout << "Введите интервал года рождения (до): ";
	cin >> b;

	int choice;
	cout << "Вы хотите узнать успеваемость за все сессии (1) или за определенную (2)?: ";
	cin >> choice;

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

					cout << "Дата поступления: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear << endl;

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
		cin >> choice1;

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

					cout << "Дата поступления: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear << endl;

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