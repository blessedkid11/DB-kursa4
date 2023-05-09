#include "Func.h"

void Copy(Student* (&d_n), Student* (&d_o), int n) 
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}
}

void DataEnter(Student* (&d), int& n) //ââîä äàííûõ âðó÷íóþ
{
	cout << "Ââåäèòå êîëè÷åñòâî ñòóäåíòîâ, ïðî êîòîðûõ õîòèòå âíåñòè èíôîðìàöèþ: ";
	cin >> n;

	d = new Student[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Ââåäèòå ôàìèëèþ: ";
		cin >> d[i].fio.Familia;
		cout << "Ââåäèòå èìÿ: ";
		cin >> d[i].fio.Imya;
		cout << "Ââåäèòå îò÷åñòâî: ";
		cin >> d[i].fio.Papa;

		cout << "Ââåäèòå ïîë: ";
		cin >> d[i].pol;

		cout << "Ââåäèòå äàòó ðîæäåíèÿ (÷èñëî): ";
		cin >> d[i].date.Rday;
		cout << "Ââåäèòå äàòó ðîæäåíèÿ (ìåñÿö): ";
		cin >> d[i].date.Rmonth;
		cout << "Ââåäèòå äàòó ðîæäåíèÿ (ãîä): ";
		cin >> d[i].date.Ryear;

		cout << "Ââåäèòå äàòó ïîñòóïëåíèÿ (÷èñëî): ";
		cin >> d[i].dateIN.Pday;
		cout << "Ââåäèòå äàòó ïîñòóïëåíèÿ (ìåñÿö): ";
		cin >> d[i].dateIN.Pmonth;
		cout << "Ââåäèòå äàòó ïîñòóïëåíèÿ (ãîä): ";
		cin >> d[i].dateIN.Pyear;

		cout << "Ââåäèòå íàçâàíèå ôàêóëüòåòà: ";
		cin >> d[i].facult;

		cout << "Ââåäèòå íàçâàíèå êàôåäðû: ";
		cin >> d[i].kafedra;

		cout << "Ââåäèòå íîìåð ãðóïïû: ";
		cin >> d[i].gruppa;

		cout << "Ââåäèòå íîìåð çà÷åòíîé êíèæêè: ";
		cin >> d[i].idzachet;

		cout << "Î ñêîëüêè ñåññèÿõ õîòèòå âíåñòè èíôîðìàöèþ?: ";
		cin >> d[i].kolvosess;

		for (int j = 0; j < d[i].kolvosess; j++)
		{
			cout << "Î ñêîëüêè ïðåäìåòàõ â ñåññèè õîòèòå âíåñòè èíôîðìàöèþ? (ñåññèÿ N" << j + 1 << "): ";
			cin >> d[i].sess[j].kolvo;

			for (int m = 0; m < d[i].sess[j].kolvo; m++)
			{
				cout << "Ââåäèòå íàçâàíèå ïðåäìåòà: ";
				cin >> d[i].sess[j].proc[m].predmet;
				cout << "Ââåäèòå îöåíêó: ";
				cin >> d[i].sess[j].proc[m].ocenka;
			}
		}

		cout << "_______________________________________" << endl;
	}
}

void DataRead(Student* (&d), int& n, string filename)
{
	ifstream reading(filename); //ñîçäàåì ïîòîê äëÿ ÷òåíèÿ èç ôàéëà

	if (reading)
	{
		reading.read((char*)&n, sizeof(n));;

		//âûäåëÿåì ïàìÿòü
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
		cout << "Äàííûå ñ÷èòàíû!" << endl;

	}
	else
		cout << "Îøèáêà îòêðûòè ôàéëà!" << endl;

	reading.close();
}

void DataPrint(Student* d, int n)//âûâîä äàííûõ
{
	for (int i = 0; i < n; i++)
	{
		cout << "Äàííûå N" << i + 1 << endl;

		cout << "ÔÈÎ ñòóäåíòà: " << d[i].fio.Familia << " " << d[i].fio.Imya << " " << d[i].fio.Papa << endl;

		cout << "Ïîë: " << d[i].pol << endl;

		cout << "Äàòà ðîæäåíèÿ: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear << endl;

		cout << "Äàòà ïîñòóïëåíèÿ: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear << endl;

		cout << "Íàçâàíèå ôàêóëüòåòà : " << d[i].facult << endl;

		cout << "Íàçâàíèå êàôåäðû: " << d[i].kafedra << endl;

		cout << "Íîìåð ãðóïïû: " << d[i].gruppa << endl;

		cout << "Íîìåð çà÷åòíîé êíèæêè: " << d[i].idzachet << endl;

		for (int j = 0; j < d[i].kolvosess; j++)
		{
			cout << "Ñåññèÿ N";
			cout << j + 1 << ":" << endl;

			for (int m = 0; m < d[i].sess[j].kolvo; m++)
			{
				cout << "Íàçâàíèå ïðåäìåòà: " << d[i].sess[j].proc[m].predmet;
				cout << "   ";
				cout << "Îöåíêà: " << d[i].sess[j].proc[m].ocenka << endl;
			}
		}

		cout << "_______________________________________" << endl;
	}
}

void DataChange(Student* (&d), int n) //èçìåíåíèå äàííûõ
{
	int nn;
	cout << "Ââåäèòå íîìåð ýëåìåíòà (îò 1 äî " << n << "): ";
	cin >> nn;
	nn--;

	system("cls");//î÷èñòêà êîíñîëè

	//ïðîâåðêà ÷òî çíà÷åíèå ââåäåíî âåðíî
	if (nn >= 0 && nn < n)
	{
		cout << "Ââåäèòå ôàìèëèþ: ";
		cin >> d[nn].fio.Familia;
		cout << "Ââåäèòå èìÿ: ";
		cin >> d[nn].fio.Imya;
		cout << "Ââåäèòå îò÷åñòâî: ";
		cin >> d[nn].fio.Papa;

		cout << "Ââåäèòå ïîë: ";
		cin >> d[nn].pol;

		cout << "Ââåäèòå äàòó ðîæäåíèÿ (÷èñëî): ";
		cin >> d[nn].date.Rday;
		cout << "Ââåäèòå äàòó ðîæäåíèÿ (ìåñÿö): ";
		cin >> d[nn].date.Rmonth;
		cout << "Ââåäèòå äàòó ðîæäåíèÿ (ãîä): ";
		cin >> d[nn].date.Ryear;

		cout << "Ââåäèòå äàòó ïîñòóïëåíèÿ (÷èñëî): ";
		cin >> d[nn].dateIN.Pday;
		cout << "Ââåäèòå äàòó ïîñòóïëåíèÿ (ìåñÿö): ";
		cin >> d[nn].dateIN.Pmonth;
		cout << "Ââåäèòå äàòó ïîñòóïëåíèÿ (ãîä): ";
		cin >> d[nn].dateIN.Pyear;

		cout << "Ââåäèòå íàçâàíèå ôàêóëüòåòà: ";
		cin >> d[nn].facult;

		cout << "Ââåäèòå íàçâàíèå êàôåäðû: ";
		cin >> d[nn].kafedra;

		cout << "Ââåäèòå íîìåð ãðóïïû: ";
		cin >> d[nn].gruppa;

		cout << "Ââåäèòå íîìåð çà÷åòíîé êíèæêè: ";
		cin >> d[nn].idzachet;

		cout << "Î ñêîëüêè ñåññèÿõ õîòèòå âíåñòè èíôîðìàöèþ?: ";
		cin >> d[nn].kolvosess;

		for (int j = 0; j < d[nn].kolvosess; j++)
		{
			cout << "Î ñêîëüêè ïðåäìåòàõ â ñåññèè õîòèòå âíåñòè èíôîðìàöèþ? (ñåññèÿ N" << j + 1 << "): ";
			cin >> d[nn].sess[j].kolvo;

			for (int m = 0; m < d[nn].sess[j].kolvo; m++)
			{
				cout << "Ââåäèòå íàçâàíèå ïðåäìåòà: ";
				cin >> d[nn].sess[j].proc[m].predmet;
				cout << "Ââåäèòå îöåíêó: ";
				cin >> d[nn].sess[j].proc[m].ocenka;
			}
		}

		system("cls");//î÷èñòêà êîíñîëè

		cout << "Äàííûå èçìåíåíû!" << endl;
	}
	else
		cout << "Íîìåð çàïèñè ââåäåí íåâåðîíî!" << endl;

}

void DataDelete(Student* (&d), int& n) //óäàëåíèå äàííûõ
{
	int nn;
	cout << "Ââåäèòå íîìåð ýëåìåíòà (îò 1 äî " << n << "): ";
	cin >> nn;
	nn--;

	system("cls");//î÷èñòêà êîíñîëè

	//ïðîâåðêà ÷òî çíà÷åíèå ââåäåíî âåðíî
	if (nn >= 0 && nn < n)
	{
		Student* TempMas = new Student[n]; //âðåìåííûé ìàññèâ

		Copy(TempMas, d, n);

		--n;
		d = new Student[n]; //íîâàÿ ïàìÿòü

		int q = 0;

		//çàïîìèíàåì äàííûå
		for (int i = 0; i <= n; i++)
		{
			if (i != nn)
			{
				d[q] = TempMas[i];
				++q;
			}
		}

		system("cls");//î÷èñòêà êîíñîëè
		delete[]TempMas;//î÷èñòêà âðåìåííîãî ìàññèâà

		cout << "Äàííûå óäàëåíû!" << endl;
	}
	else
		cout << "Íîìåð çàïèñè ââåäåí íåâåðîíî!" << endl;
}

void DataAdd(Student* (&d), int& n) //äîáàâëåíèå äàííûõ
{
	Student* TempMas = new Student[n]; //âðåìåííûé ìàññèâ

	Copy(TempMas, d, n); //ñîõðàíÿåì äàííûå â âðåìåííûé ìàññèâ

	n++;
	d = new Student[n]; //íîâàÿ ïàìÿòü

	Copy(d, TempMas, --n); //âîçâðàùàåì äàííûå

	cout << "Ââåäèòå ôàìèëèþ: ";
	cin >> d[n].fio.Familia;
	cout << "Ââåäèòå èìÿ: ";
	cin >> d[n].fio.Imya;
	cout << "Ââåäèòå îò÷åñòâî: ";
	cin >> d[n].fio.Papa;

	cout << "Ââåäèòå ïîë: ";
	cin >> d[n].pol;

	cout << "Ââåäèòå äàòó ðîæäåíèÿ(÷èñëî): ";
	cin >> d[n].date.Rday;
	cout << "Ââåäèòå äàòó ðîæäåíèÿ(ìåñÿö): ";
	cin >> d[n].date.Rmonth;
	cout << "Ââåäèòå äàòó ðîæäåíèÿ(ãîä): ";
	cin >> d[n].date.Ryear;

	cout << "Ââåäèòå äàòó ïîñòóïëåíèÿ(÷èñëî): ";
	cin >> d[n].dateIN.Pday;
	cout << "Ââåäèòå äàòó ïîñòóïëåíèÿ(ìåñÿö): ";
	cin >> d[n].dateIN.Pmonth;
	cout << "Ââåäèòå äàòó ïîñòóïëåíèÿ(ãîä): ";
	cin >> d[n].dateIN.Pyear;

	cout << "Ââåäèòå íàçâàíèå ôàêóëüòåòà: ";
	cin >> d[n].facult;

	cout << "Ââåäèòå íàçâàíèå êàôåäðû: ";
	cin >> d[n].kafedra;

	cout << "Ââåäèòå íîìåð ãðóïïû: ";
	cin >> d[n].gruppa;

	cout << "Ââåäèòå íîìåð çà÷åòíîé êíèæêè: ";
	cin >> d[n].idzachet;

	cout << "Î ñêîëüêè ñåññèÿõ õîòèòå âíåñòè èíôîðìàöèþ?: ";
	cin >> d[n].kolvosess;

	for (int j = 0; j < d[n].kolvosess; j++)
	{
		cout << "Î ñêîëüêè ïðåäìåòàõ â ñåññèè õîòèòå âíåñòè èíôîðìàöèþ? (ñåññèÿ N" << j + 1 << "): ";
		cin >> d[n].sess[j].kolvo;

		for (int m = 0; m < d[n].sess[j].kolvo; m++)
		{
			cout << "Ââåäèòå íàçâàíèå ïðåäìåòà: ";
			cin >> d[n].sess[j].proc[m].predmet;
			cout << "Ââåäèòå îöåíêó: ";
			cin >> d[n].sess[j].proc[m].ocenka;
		}
	}

	delete[]TempMas;
}

void DataSave(Student* d, int n, string filename) //ñîõðàíåíèå äàííûõ
{
	ofstream record(filename, ios::binary); //ñîçäàíèå ïîòîêà äëÿ çàïèñè ïóñòîãî

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
		cout << "Îøèáêà ñîõðàíåíèÿ ôàéëà!" << endl;
	record.close();
}

void Zadanie(Student* d, int n)
{
	unsigned short a, b;
	cout << "Ââåäèòå èíòåðâàë ãîäà ðîæäåíèÿ (îò): ";
	cin >> a;
	cout << "Ââåäèòå èíòåðâàë ãîäà ðîæäåíèÿ (äî): ";
	cin >> b;

	int choice;
	cout << "Âû õîòèòå óçíàòü óñïåâàåìîñòü çà âñå ñåññèè (1) èëè çà îïðåäåëåííóþ (2)?: ";
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
					cout << "Äàííûå N" << i + 1 << endl;

					cout << "ÔÈÎ ñòóäåíòà: " << d[i].fio.Familia << " " << d[i].fio.Imya << " " << d[i].fio.Papa << endl;

					cout << "Ïîë: " << d[i].pol << endl;

					cout << "Äàòà ðîæäåíèÿ: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear << endl;

					cout << "Äàòà ïîñòóïëåíèÿ: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear << endl;

					cout << "Íàçâàíèå ôàêóëüòåòà : " << d[i].facult << endl;

					cout << "Íàçâàíèå êàôåäðû: " << d[i].kafedra << endl;

					cout << "Íîìåð ãðóïïû: " << d[i].gruppa << endl;

					cout << "Íîìåð çà÷åòíîé êíèæêè: " << d[i].idzachet << endl;

					for (int l = 0; l < d[i].kolvosess; l++)
					{
						cout << "Ñåññèÿ N";
						cout << l + 1 << ":";

						for (int v = 0; v < d[i].sess[l].kolvo; v++)
						{
							cout << "Íàçâàíèå ïðåäìåòà: ";
							cout << d[i].sess[l].proc[v].predmet;
							cout << "   ";
							cout << "Îöåíêà: ";
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
		cout << "Ââåäèòå íîìåð ñåññèè: ";
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
					cout << "Äàííûå N" << i + 1 << endl;

					cout << "ÔÈÎ ñòóäåíòà: " << d[i].fio.Familia << " " << d[i].fio.Imya << " " << d[i].fio.Papa << endl;

					cout << "Ïîë: " << d[i].pol << endl;

					cout << "Äàòà ðîæäåíèÿ: " << d[i].date.Rday << "." << d[i].date.Rmonth << "." << d[i].date.Ryear << endl;

					cout << "Äàòà ïîñòóïëåíèÿ: " << d[i].dateIN.Pday << "." << d[i].dateIN.Pmonth << "." << d[i].dateIN.Pyear << endl;

					cout << "Íàçâàíèå ôàêóëüòåòà : " << d[i].facult << endl;

					cout << "Íàçâàíèå êàôåäðû: " << d[i].kafedra << endl;

					cout << "Íîìåð ãðóïïû: " << d[i].gruppa << endl;

					cout << "Íîìåð çà÷åòíîé êíèæêè: " << d[i].idzachet << endl;

					for (int l = 0; l < d[i].kolvosess; l++)
					{
						cout << "Ñåññèÿ N";
						cout << l + 1 << ":";

						for (int v = 0; v < d[i].sess[l].kolvo; v++)
						{
							cout << "Íàçâàíèå ïðåäìåòà: ";
							cout << d[i].sess[l].proc[v].predmet;
							cout << "   ";
							cout << "Îöåíêà: ";
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
