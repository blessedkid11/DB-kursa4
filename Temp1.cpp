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
		cout << "Выберите действие:" << endl
			<< "(0) Выйти из программы" << endl
			<< "(1) Изменить / создать базу данных" << endl
			<< "(2) Вывести данные" << endl
			<< "(3) Изменить данные" << endl
			<< "(4) Удалить данные" << endl
			<< "(5) Добавить данные" << endl
			<< "(6) Сохранить изменения" << endl
			<< "(7) Выполнить задание (89 вариант)" << endl
			<< "Ваш выбор: ";
		cin >> StateMenu; //запись в переменную выбора пользователя

	}

	void WorkMenu()
	{
		Student* d = new Student[amountofdata];

		while (StateMenu != 0)
		{
			switch (StateMenu)
			{
			case 1:
				system("cls");//очистка консоли
				cout << "Вы хотите изменить данные в базе данных (1) или создать новую (2)?: ";
				cin >> case1action;

				if (case1action == 1)
				{
					cout << "Введите название файла: ";
					cin >> filename;
					DataRead(d, amountofdata, filename);
				}
				if (case1action == 2)
				{
					DataEnter(d, amountofdata); //ввод данных
				}


				system("pause");//задержка консоли
				system("cls");//очистка консоли
				PrintMenu();
				break;
				//////////////////////////////////
			case 2:
				system("cls");//очистка консоли

				if (amountofdata != 0) {
					DataPrint(d, amountofdata);
				}
				else
					cout << "Данные отсутствуют!" << endl;
				system("pause");//задержка консоли
				system("cls");//очистка консоли
				PrintMenu();
				break;
				///////////////////////////////////
			case 3:
				system("cls");//очистка консоли

				if (amountofdata != 0) {
					DataChange(d, amountofdata);
				}
				else
					cout << "Данные отсутствуют!" << endl;
				system("pause");//задержка консоли
				system("cls");//очистка консоли
				PrintMenu();
				break;
				///////////////////////////////////
			case 4:
				system("cls");//очистка консоли

				if (amountofdata != 0) {
					DataDelete(d, amountofdata);
				}
				else
					cout << "Данные отсутствуют!" << endl;
				system("pause");//задержка консоли
				system("cls");//очистка консоли
				PrintMenu();
				break;
				/////////////////////////////////////
			case 5:
				system("cls");//очистка консоли

				if (amountofdata != 0) {
					DataAdd(d, amountofdata);
					amountofdata++;
				}
				else
					cout << "Данные отсутствуют!" << endl;
				system("pause");//задержка консоли
				system("cls");//очистка консоли
				PrintMenu();
				break;
				/////////////////////////////////////
			case 6:
				system("cls");//очистка консоли

				cout << "Введите название файла: ";
				cin >> filename;

				if (amountofdata != 0)
				{
					DataSave(d, amountofdata, filename);
				}
				else
					cout << "Данные отсутствуют!" << endl;
				system("pause");//задержка консоли
				system("cls");//очистка консоли
				PrintMenu();
				break;
			case 7:
				system("cls");//очистка консоли

				Zadanie(d, amountofdata);
				system("pause");//задержка консоли
				system("cls");//очистка консоли
				PrintMenu();
				break;
			default:
				cout << "Неверно введен номер действия из меню!";

				system("pause");//задержка консоли
				system("cls");//очистка консоли
				PrintMenu();
				break;
			}



		}
	}

};



void main()
{
	SetConsoleCP(1251); //русификация ввода
	SetConsoleOutputCP(1251); //русификация вывода

	Menu Menuu;
	Menuu.PrintMenu();
	Menuu.WorkMenu();
}