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

		cout << "_______________________________________" << endl;
	}
}

void DataRead(Student* (&d), int& n, string filename)
{
	ifstream reading(filename); //������� ����� ��� ������ �� �����

	if (reading)
	{
		reading >> n;

		//�������� ������
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
		
		cout << "���� ��������: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear <<  endl;
	
		cout << "���� �����������: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear <<  endl;

		cout << "�������� ���������� : " << d[i].facult << endl;

		cout << "�������� �������: " << d[i].kafedra << endl;

		cout << "����� ������: " << d[i].gruppa << endl;

		cout << "������� ����� �������� ������: " << d[i].idzachet << endl;
		
		cout << "_______________________________________" << endl;
	}
}

void DataChange(Student* (&d), int n) //��������� ������
{
	int nn;
	cout << "������� ����� �������� (�� 1 �� "<< n << "): ";
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

	cout << "������� ���� ��������(�����): ";
	cin >> d[n].date.Rday;
	cout << "������� ���� ��������(�����): ";
	cin >> d[n].date.Rmonth;
	cout << "������� ���� ��������(���): ";
	cin >> d[n].date.Ryear;

	cout << "������� ���� ��������(�����): ";
	cin >> d[n].dateIN.Pday;
	cout << "������� ���� ��������(�����): ";
	cin >> d[n].dateIN.Pmonth;
	cout << "������� ���� ��������(���): ";
	cin >> d[n].dateIN.Pyear;

	cout << "������� �������� ����������: ";
	cin >> d[n].facult;

	cout << "������� �������� �������: ";
	cin >> d[n].kafedra;

	cout << "������� ����� ������: ";
	cin >> d[n].gruppa;

	cout << "������� ����� �������� ������: ";
	cin >> d[n].idzachet;

	cout << "������ ���������!" << endl;

	delete[]TempMas;
}

void DataSave(Student* d, int n, string filename) //���������� ������
{
	ofstream record(filename, ios::out); //�������� ������ ��� ������ �������

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
		cout << "������ ���������� �����!" << endl;
	record.close();
}	
