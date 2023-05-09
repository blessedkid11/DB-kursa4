#include "Func.h"

void Copy(Student* (&d_n), Student* (&d_o), int n) //����������� � ����� ������
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}
}

void DataEnter(Student* (&d), int& n) //���� ������ �������
{
	cout << "������� ���������� ���������, ��� ������� ������ ������ ����������: ";
	cin >> n;

	d = new Student[n];

	for (int i = 0; i < n; i++)
	{
		cout << "������� �������: ";
		cin >> d[i].fio.Familia;
		cout << "������� ���: ";
		cin >> d[i].fio.Imya;
		cout << "������� ��������: ";
		cin >> d[i].fio.Papa;

		cout << "������� ���: ";
		cin >> d[i].pol;

		cout << "������� ���� �������� (�����): ";
		cin >> d[i].date.Rday;
		cout << "������� ���� �������� (�����): ";
		cin >> d[i].date.Rmonth;
		cout << "������� ���� �������� (���): ";
		cin >> d[i].date.Ryear;

		cout << "������� ���� ����������� (�����): ";
		cin >> d[i].dateIN.Pday;
		cout << "������� ���� ����������� (�����): ";
		cin >> d[i].dateIN.Pmonth;
		cout << "������� ���� ����������� (���): ";
		cin >> d[i].dateIN.Pyear;

		cout << "������� �������� ����������: ";
		cin >> d[i].facult;

		cout << "������� �������� �������: ";
		cin >> d[i].kafedra;

		cout << "������� ����� ������: ";
		cin >> d[i].gruppa;

		cout << "������� ����� �������� ������: ";
		cin >> d[i].idzachet;

		cout << "� ������� ������� ������ ������ ����������?: ";
		cin >> d[i].kolvosess;

		for (int j = 0; j < d[i].kolvosess; j++)
		{
			cout << "� ������� ��������� � ������ ������ ������ ����������? (������ N" << j + 1 << "): ";
			cin >> d[i].sess[j].kolvo;

			for (int m = 0; m < d[i].sess[j].kolvo; m++)
			{
				cout << "������� �������� ��������: ";
				cin >> d[i].sess[j].proc[m].predmet;
				cout << "������� ������: ";
				cin >> d[i].sess[j].proc[m].ocenka;
			}
		}

		cout << "_______________________________________" << endl;
	}
}

void DataRead(Student* (&d), int& n, string filename)
{
	ifstream reading(filename); //������� ����� ��� ������ �� �����

	if (reading)
	{
		reading.read((char*)&n, sizeof(n));;

		//�������� ������
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
		cout << "������ �������!" << endl;

	}
	else
		cout << "������ ������� �����!" << endl;

	reading.close();
}

void DataPrint(Student* d, int n)//����� ������
{
	for (int i = 0; i < n; i++)
	{
		cout << "������ N" << i + 1 << endl;

		cout << "��� ��������: " << d[i].fio.Familia << " " << d[i].fio.Imya << " " << d[i].fio.Papa << endl;

		cout << "���: " << d[i].pol << endl;

		cout << "���� ��������: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear << endl;

		cout << "���� �����������: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear << endl;

		cout << "�������� ���������� : " << d[i].facult << endl;

		cout << "�������� �������: " << d[i].kafedra << endl;

		cout << "����� ������: " << d[i].gruppa << endl;

		cout << "����� �������� ������: " << d[i].idzachet << endl;

		for (int j = 0; j < d[i].kolvosess; j++)
		{
			cout << "������ N";
			cout << j + 1 << ":" << endl;

			for (int m = 0; m < d[i].sess[j].kolvo; m++)
			{
				cout << "�������� ��������: " << d[i].sess[j].proc[m].predmet;
				cout << "   ";
				cout << "������: " << d[i].sess[j].proc[m].ocenka << endl;
			}
		}

		cout << "_______________________________________" << endl;
	}
}

void DataChange(Student* (&d), int n) //��������� ������
{
	int nn;
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> nn;
	nn--;

	system("cls");//������� �������

	//�������� ��� �������� ������� �����
	if (nn >= 0 && nn < n)
	{
		cout << "������� �������: ";
		cin >> d[nn].fio.Familia;
		cout << "������� ���: ";
		cin >> d[nn].fio.Imya;
		cout << "������� ��������: ";
		cin >> d[nn].fio.Papa;

		cout << "������� ���: ";
		cin >> d[nn].pol;

		cout << "������� ���� �������� (�����): ";
		cin >> d[nn].date.Rday;
		cout << "������� ���� �������� (�����): ";
		cin >> d[nn].date.Rmonth;
		cout << "������� ���� �������� (���): ";
		cin >> d[nn].date.Ryear;

		cout << "������� ���� ����������� (�����): ";
		cin >> d[nn].dateIN.Pday;
		cout << "������� ���� ����������� (�����): ";
		cin >> d[nn].dateIN.Pmonth;
		cout << "������� ���� ����������� (���): ";
		cin >> d[nn].dateIN.Pyear;

		cout << "������� �������� ����������: ";
		cin >> d[nn].facult;

		cout << "������� �������� �������: ";
		cin >> d[nn].kafedra;

		cout << "������� ����� ������: ";
		cin >> d[nn].gruppa;

		cout << "������� ����� �������� ������: ";
		cin >> d[nn].idzachet;

		cout << "� ������� ������� ������ ������ ����������?: ";
		cin >> d[nn].kolvosess;

		for (int j = 0; j < d[nn].kolvosess; j++)
		{
			cout << "� ������� ��������� � ������ ������ ������ ����������? (������ N" << j + 1 << "): ";
			cin >> d[nn].sess[j].kolvo;

			for (int m = 0; m < d[nn].sess[j].kolvo; m++)
			{
				cout << "������� �������� ��������: ";
				cin >> d[nn].sess[j].proc[m].predmet;
				cout << "������� ������: ";
				cin >> d[nn].sess[j].proc[m].ocenka;
			}
		}

		system("cls");//������� �������

		cout << "������ ��������!" << endl;
	}
	else
		cout << "����� ������ ������ ��������!" << endl;

}

void DataDelete(Student* (&d), int& n) //�������� ������
{
	int nn;
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> nn;
	nn--;

	system("cls");//������� �������

	//�������� ��� �������� ������� �����
	if (nn >= 0 && nn < n)
	{
		Student* TempMas = new Student[n]; //��������� ������

		Copy(TempMas, d, n);

		--n;
		d = new Student[n]; //����� ������

		int q = 0;

		//���������� ������
		for (int i = 0; i <= n; i++)
		{
			if (i != nn)
			{
				d[q] = TempMas[i];
				++q;
			}
		}

		system("cls");//������� �������
		delete[]TempMas;//������� ���������� �������

		cout << "������ �������!" << endl;
	}
	else
		cout << "����� ������ ������ ��������!" << endl;
}

void DataAdd(Student* (&d), int& n) //���������� ������
{
	Student* TempMas = new Student[n]; //��������� ������

	Copy(TempMas, d, n); //��������� ������ � ��������� ������

	n++;
	d = new Student[n]; //����� ������

	Copy(d, TempMas, --n); //���������� ������

	cout << "������� �������: ";
	cin >> d[n].fio.Familia;
	cout << "������� ���: ";
	cin >> d[n].fio.Imya;
	cout << "������� ��������: ";
	cin >> d[n].fio.Papa;

	cout << "������� ���: ";
	cin >> d[n].pol;

	cout << "������� ���� ��������(�����): ";
	cin >> d[n].date.Rday;
	cout << "������� ���� ��������(�����): ";
	cin >> d[n].date.Rmonth;
	cout << "������� ���� ��������(���): ";
	cin >> d[n].date.Ryear;

	cout << "������� ���� �����������(�����): ";
	cin >> d[n].dateIN.Pday;
	cout << "������� ���� �����������(�����): ";
	cin >> d[n].dateIN.Pmonth;
	cout << "������� ���� �����������(���): ";
	cin >> d[n].dateIN.Pyear;

	cout << "������� �������� ����������: ";
	cin >> d[n].facult;

	cout << "������� �������� �������: ";
	cin >> d[n].kafedra;

	cout << "������� ����� ������: ";
	cin >> d[n].gruppa;

	cout << "������� ����� �������� ������: ";
	cin >> d[n].idzachet;

	cout << "� ������� ������� ������ ������ ����������?: ";
	cin >> d[n].kolvosess;

	for (int j = 0; j < d[n].kolvosess; j++)
	{
		cout << "� ������� ��������� � ������ ������ ������ ����������? (������ N" << j + 1 << "): ";
		cin >> d[n].sess[j].kolvo;

		for (int m = 0; m < d[n].sess[j].kolvo; m++)
		{
			cout << "������� �������� ��������: ";
			cin >> d[n].sess[j].proc[m].predmet;
			cout << "������� ������: ";
			cin >> d[n].sess[j].proc[m].ocenka;
		}
	}

	delete[]TempMas;
}

void DataSave(Student* d, int n, string filename) //���������� ������
{
	ofstream record(filename, ios::binary); //�������� ������ ��� ������ �������

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
		cout << "������ ���������� �����!" << endl;
	record.close();
}

void Zadanie(Student* d, int n)
{
	unsigned short a, b;
	cout << "������� �������� ���� �������� (��): ";
	cin >> a;
	cout << "������� �������� ���� �������� (��): ";
	cin >> b;

	int choice;
	cout << "�� ������ ������ ������������ �� ��� ������ (1) ��� �� ������������ (2)?: ";
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
					cout << "������ N" << i + 1 << endl;

					cout << "��� ��������: " << d[i].fio.Familia << " " << d[i].fio.Imya << " " << d[i].fio.Papa << endl;

					cout << "���: " << d[i].pol << endl;

					cout << "���� ��������: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear << endl;

					cout << "���� �����������: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear << endl;

					cout << "�������� ���������� : " << d[i].facult << endl;

					cout << "�������� �������: " << d[i].kafedra << endl;

					cout << "����� ������: " << d[i].gruppa << endl;

					cout << "����� �������� ������: " << d[i].idzachet << endl;

					for (int l = 0; l < d[i].kolvosess; l++)
					{
						cout << "������ N";
						cout << l + 1 << ":";

						for (int v = 0; v < d[i].sess[l].kolvo; v++)
						{
							cout << "�������� ��������: ";
							cout << d[i].sess[l].proc[v].predmet;
							cout << "   ";
							cout << "������: ";
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
		cout << "������� ����� ������: ";
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
					cout << "������ N" << i + 1 << endl;

					cout << "��� ��������: " << d[i].fio.Familia << " " << d[i].fio.Imya << " " << d[i].fio.Papa << endl;

					cout << "���: " << d[i].pol << endl;

					cout << "���� ��������: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear << endl;

					cout << "���� �����������: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear << endl;

					cout << "�������� ���������� : " << d[i].facult << endl;

					cout << "�������� �������: " << d[i].kafedra << endl;

					cout << "����� ������: " << d[i].gruppa << endl;

					cout << "����� �������� ������: " << d[i].idzachet << endl;

					for (int l = 0; l < d[i].kolvosess; l++)
					{
						cout << "������ N";
						cout << l + 1 << ":";

						for (int v = 0; v < d[i].sess[l].kolvo; v++)
						{
							cout << "�������� ��������: ";
							cout << d[i].sess[l].proc[v].predmet;
							cout << "   ";
							cout << "������: ";
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