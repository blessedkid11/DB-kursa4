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

		cout << "_______________________________________" << endl;
	}
}

void DataRead(Student* (&d), int& n, string filename)
{
	ifstream reading(filename); //создаем поток для чтения из файла

	if (reading)
	{
		reading >> n;

		//выделяем память
		d = new Student[n];

		for (int i = 0; i < n; i++)
		{

			reading >> d[i].fio.Familia;
			reading >> d[i].fio.Imya;
			reading >> d[i].fio.Papa;

			reading >> d[i].date.Rday;
			reading >> d[i].date.Rmonth;
			reading >> d[i].date.Ryear;

			reading >> d[i].dateIN.Pday;
			reading >> d[i].dateIN.Pmonth;
			reading >> d[i].dateIN.Pyear;

			reading >> d[i].facult;

			reading >> d[i].kafedra;

			reading >> d[i].gruppa;

			reading >> d[i].idzachet;

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
		
		cout << "Дата рождения: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear <<  endl;
	
		cout << "Дата поступления: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear <<  endl;

		cout << "Название факультета : " << d[i].facult << endl;

		cout << "Название кафедры: " << d[i].kafedra << endl;

		cout << "Номер группы: " << d[i].gruppa << endl;

		cout << "Введите номер зачетной книжки: " << d[i].idzachet << endl;
		
		cout << "_______________________________________" << endl;
	}
}

void DataChange(Student* (&d), int n) //изменение данных
{
	int nn;
	cout << "Введите номер элемента (от 1 до "<< n << "): ";
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

	cout << "Введите дату рождения(число): ";
	cin >> d[n].date.Rday;
	cout << "Введите дату рождения(месяц): ";
	cin >> d[n].date.Rmonth;
	cout << "Введите дату рождения(год): ";
	cin >> d[n].date.Ryear;

	cout << "Введите дату рождения(число): ";
	cin >> d[n].dateIN.Pday;
	cout << "Введите дату рождения(месяц): ";
	cin >> d[n].dateIN.Pmonth;
	cout << "Введите дату рождения(год): ";
	cin >> d[n].dateIN.Pyear;

	cout << "Введите название факультета: ";
	cin >> d[n].facult;

	cout << "Введите название кафедры: ";
	cin >> d[n].kafedra;

	cout << "Введите номер группы: ";
	cin >> d[n].gruppa;

	cout << "Введите номер зачетной книжки: ";
	cin >> d[n].idzachet;

	cout << "Данные добавлены!" << endl;

	delete[]TempMas;
}

void DataSave(Student* d, int n, string filename) //сохранение данных
{
	ofstream record(filename, ios::out); //создание потока для записи пустого

	if (record)
	{
		record << n << endl;
		for (int i = 0; i < n; i++)
		{

			record << d[i].fio.Familia << endl;
			record << d[i].fio.Imya << endl;
			record << d[i].fio.Papa << endl;

			record << d[i].date.Rday << " ";
			record << d[i].date.Rmonth << " ";
			record << d[i].date.Ryear << " ";

			record << d[i].dateIN.Pday << " ";
			record << d[i].dateIN.Pmonth << " ";
			record << d[i].dateIN.Pyear << " ";

			record << d[i].facult << endl;

			record << d[i].kafedra << endl;

			record << d[i].gruppa << endl;

			if (i < n - 1)
				record << d[i].idzachet << endl;
			else
				record << d[i].idzachet;

		}
	}
	else
		cout << "Ошибка сохранения файла!" << endl;
	record.close();
}	
