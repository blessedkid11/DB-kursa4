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
		cout << "Âûáåðèòå äåéñòâèå:" << endl
			<< "(0) Âûéòè èç ïðîãðàììû" << endl
			<< "(1) Èçìåíèòü / ñîçäàòü áàçó äàííûõ" << endl
			<< "(2) Âûâåñòè äàííûå" << endl
			<< "(3) Èçìåíèòü äàííûå" << endl
			<< "(4) Óäàëèòü äàííûå" << endl
			<< "(5) Äîáàâèòü äàííûå" << endl
			<< "(6) Ñîõðàíèòü èçìåíåíèÿ" << endl
			<< "(7) Âûïîëíèòü çàäàíèå (89 âàðèàíò)" << endl
			<< "Âàø âûáîð: ";
		cin >> StateMenu; 

	}

	void WorkMenu()
	{
		Student* d = new Student[amountofdata];

		while (StateMenu != 0)
		{
			switch (StateMenu)
			{
			case 1:
				system("cls");//î÷èñòêà êîíñîëè
				cout << "Âû õîòèòå èçìåíèòü äàííûå â áàçå äàííûõ (1) èëè ñîçäàòü íîâóþ (2)?: ";
				cin >> case1action;

				if (case1action == 1)
				{
					cout << "Ââåäèòå íàçâàíèå ôàéëà: ";
					cin >> filename;
					DataRead(d, amountofdata, filename);
				}
				if (case1action == 2)
				{
					DataEnter(d, amountofdata); //ââîä äàííûõ
				}


				system("pause");//çàäåðæêà êîíñîëè
				system("cls");//î÷èñòêà êîíñîëè
				PrintMenu();
				break;
				//////////////////////////////////
			case 2:
				system("cls");//î÷èñòêà êîíñîëè

				if (amountofdata != 0) {
					DataPrint(d, amountofdata);
				}
				else
					cout << "Äàííûå îòñóòñòâóþò!" << endl;
				system("pause");//çàäåðæêà êîíñîëè
				system("cls");//î÷èñòêà êîíñîëè
				PrintMenu();
				break;
				///////////////////////////////////
			case 3:
				system("cls");//î÷èñòêà êîíñîëè

				if (amountofdata != 0) {
					DataChange(d, amountofdata);
				}
				else
					cout << "Äàííûå îòñóòñòâóþò!" << endl;
				system("pause");//çàäåðæêà êîíñîëè
				system("cls");//î÷èñòêà êîíñîëè
				PrintMenu();
				break;
				///////////////////////////////////
			case 4:
				system("cls");//î÷èñòêà êîíñîëè

				if (amountofdata != 0) {
					DataDelete(d, amountofdata);
				}
				else
					cout << "Äàííûå îòñóòñòâóþò!" << endl;
				system("pause");//çàäåðæêà êîíñîëè
				system("cls");//î÷èñòêà êîíñîëè
				PrintMenu();
				break;
				/////////////////////////////////////
			case 5:
				system("cls");//î÷èñòêà êîíñîëè

				if (amountofdata != 0) {
					DataAdd(d, amountofdata);
					amountofdata++;
				}
				else
					cout << "Äàííûå îòñóòñòâóþò!" << endl;
				system("pause");//çàäåðæêà êîíñîëè
				system("cls");//î÷èñòêà êîíñîëè
				PrintMenu();
				break;
				/////////////////////////////////////
			case 6:
				system("cls");//î÷èñòêà êîíñîëè

				cout << "Ââåäèòå íàçâàíèå ôàéëà: ";
				cin >> filename;

				if (amountofdata != 0)
				{
					DataSave(d, amountofdata, filename);
				}
				else
					cout << "Äàííûå îòñóòñòâóþò!" << endl;
				system("pause");//çàäåðæêà êîíñîëè
				system("cls");//î÷èñòêà êîíñîëè
				PrintMenu();
				break;
			case 7:
				system("cls");//î÷èñòêà êîíñîëè

				Zadanie(d, amountofdata);
				system("pause");//çàäåðæêà êîíñîëè
				system("cls");//î÷èñòêà êîíñîëè
				PrintMenu();
				break;
			default:
				cout << "Íåâåðíî ââåäåí íîìåð äåéñòâèÿ èç ìåíþ!";

				system("pause");//çàäåðæêà êîíñîëè
				system("cls");//î÷èñòêà êîíñîëè
				PrintMenu();
				break;
			}



		}
	}

};



void main()
{
	SetConsoleCP(1251); //ðóñèôèêàöèÿ ââîäà
	SetConsoleOutputCP(1251); //ðóñèôèêàöèÿ âûâîäà

	Menu Menuu;
	Menuu.PrintMenu();
	Menuu.WorkMenu();
}
