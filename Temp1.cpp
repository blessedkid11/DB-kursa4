#include "Func.h"


class Menu
{
private:
	int case1action;
	int StateMenu;
	int amountofdata = 0;
	unsigned short ot = 0;
	unsigned short to = 0;
	string filename;

public:
	void PrintMenu()
	{
		cout << "�������� ��������:" << endl
			<< "(0) ����� �� ���������" << endl
			<< "(1) �������� / ������� ���� ������" << endl
			<< "(2) ������� ������" << endl
			<< "(3) �������� ������" << endl
			<< "(4) ������� ������" << endl
			<< "(5) �������� ������" << endl
			<< "(6) ��������� ���������" << endl
			<< "(7) ��������� ������� (89 �������)" << endl
			<< "��� �����: ";
		cin >> StateMenu; //������ � ���������� ������ ������������

	}

	void WorkMenu()
	{
		Student* d = new Student[amountofdata];

		while (StateMenu != 0)
		{
			switch (StateMenu)
			{
			case 1:
				system("cls");//������� �������
				cout << "�� ������ �������� ������ � ���� ������ (1) ��� ������� ����� (2)?: ";
				cin >> case1action;

				if (case1action == 1)
				{
					cout << "������� �������� �����: ";
					cin >> filename;
					DataRead(d, amountofdata, filename);
				}
				if (case1action == 2)
				{
					DataEnter(d, amountofdata); //���� ������
				}


				system("pause");//�������� �������
				system("cls");//������� �������
				PrintMenu();
				break;
				//////////////////////////////////
			case 2:
				system("cls");//������� �������

				if (amountofdata != 0) {
					DataPrint(d, amountofdata);
				}
				else
					cout << "������ �����������!" << endl;
				system("pause");//�������� �������
				system("cls");//������� �������
				PrintMenu();
				break;
				///////////////////////////////////
			case 3:
				system("cls");//������� �������

				if (amountofdata != 0) {
					DataChange(d, amountofdata);
				}
				else
					cout << "������ �����������!" << endl;
				system("pause");//�������� �������
				system("cls");//������� �������
				PrintMenu();
				break;
				///////////////////////////////////
			case 4:
				system("cls");//������� �������

				if (amountofdata != 0) {
					DataDelete(d, amountofdata);
				}
				else
					cout << "������ �����������!" << endl;
				system("pause");//�������� �������
				system("cls");//������� �������
				PrintMenu();
				break;
				/////////////////////////////////////
			case 5:
				system("cls");//������� �������

				if (amountofdata != 0) {
					DataAdd(d, amountofdata);
					amountofdata++;
				}
				else
					cout << "������ �����������!" << endl;
				system("pause");//�������� �������
				system("cls");//������� �������
				PrintMenu();
				break;
				/////////////////////////////////////
			case 6:
				system("cls");//������� �������

				cout << "������� �������� �����: ";
				cin >> filename;

				if (amountofdata != 0)
				{
					DataSave(d, amountofdata, filename);
				}
				else
					cout << "������ �����������!" << endl;
				system("pause");//�������� �������
				system("cls");//������� �������
				PrintMenu();
				break;
			case 7:
				system("cls");//������� �������

				Zadanie(d, amountofdata);
				system("pause");//�������� �������
				system("cls");//������� �������
				PrintMenu();
				break;
			default:
				cout << "������� ������ ����� �������� �� ����!";

				system("pause");//�������� �������
				system("cls");//������� �������
				PrintMenu();
				break;
			}



		}
	}

};



void main()
{
	SetConsoleCP(1251); //����������� �����
	SetConsoleOutputCP(1251); //����������� ������

	Menu Menuu;
	Menuu.PrintMenu();
	Menuu.WorkMenu();
}