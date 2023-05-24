#include "Func.h"

#include <Windows.h>
#include <iostream>
#include <conio.h>



int main() {
    SetConsoleCP(1251); //русификация ввода
    SetConsoleOutputCP(1251); //русификация вывода

    int case1action;
    int StateMenu;
    int amountofdata = 0;
    unsigned short ot = 0;
    unsigned short to = 0;
    string filename;
    Student* d = new Student[amountofdata];

    Menu menu;
    menu.addItem("Выйти из программы");
    menu.addItem("Считать / создать базу данных");
    menu.addItem("Вывести данные");
    menu.addItem("Изменить данные");
    menu.addItem("Удалить данные");
    menu.addItem("Добавить данные");
    menu.addItem("Сохранить изменения");
    menu.addItem("Выполнить задание (89 вариант)");

    char key;
    while (true) 
    {
        menu.display();

        key = _getch();
        if (key == 72) 
        {  // Клавиша вверх
            menu.selectPrevItem();
        }
        else if (key == 80) 
        {  // Клавиша вниз
            menu.selectNextItem();
        }
        else if (key == 13) 
        {  // Клавиша Enter
           
            string selectedOption = menu.getSelectedItem();
            if (selectedOption == "Выйти из программы")
            {
                break;
            }
            if (selectedOption == "Считать / создать базу данных")
            {
                system("cls");//очистка консоли
                cout << "Вы хотите считать данные из файла (1) или создать новую базу данных (2)?: ";
                while (!(cin >> case1action))
                {
                    cout << "Некорректный ввод. Пожалуйста, выберите верный пункт: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                if (case1action == 1)
                {
                    cout << "Введите название файла: ";
                    cin >> filename;
                    DataInteraction::DataRead(d, amountofdata, filename);
                }
                if (case1action == 2)
                {
                    DataInteraction::DataEnter(d, amountofdata); //ввод данных
                }


                system("pause");//задержка консоли
                system("cls");//очистка консоли
                menu.display();
            }
            if (selectedOption == "Вывести данные")
            {
                system("cls");//очистка консоли

                if (amountofdata != 0) {
                    DataInteraction::DataPrint(d, amountofdata);
                }
                else
                    cout << "Данные отсутствуют!" << endl;
                system("pause");//задержка консоли
                system("cls");//очистка консоли
                menu.display();
            }
            if (selectedOption == "Изменить данные")
            {
                system("cls");//очистка консоли

                if (amountofdata != 0) {
                    DataInteraction::DataChange(d, amountofdata);
                }
                else
                    cout << "Данные отсутствуют!" << endl;
                system("pause");//задержка консоли
                system("cls");//очистка консоли
                menu.display();
            }
            if (selectedOption == "Удалить данные")
            {
                system("cls");//очистка консоли

                if (amountofdata != 0) {
                    DataInteraction::DataDelete(d, amountofdata);
                }
                else
                    cout << "Данные отсутствуют!" << endl;
                system("pause");//задержка консоли
                system("cls");//очистка консоли
                menu.display();
            }
            if (selectedOption == "Добавить данные")
            {
                system("cls");//очистка консоли

                if (amountofdata != 0) {
                    DataInteraction::DataAdd(d, amountofdata);
                    amountofdata++;
                }
                else
                    cout << "Данные отсутствуют!" << endl;
                system("pause");//задержка консоли
                system("cls");//очистка консоли
                menu.display();
            }
            if (selectedOption == "Сохранить изменения")
            {
                system("cls");//очистка консоли

                cout << "Введите название файла: ";
                cin >> filename;

                if (amountofdata != 0)
                {
                    DataInteraction::DataSave(d, amountofdata, filename);
                }
                else
                    cout << "Данные отсутствуют!" << endl;
                system("pause");//задержка консоли
                system("cls");//очистка консоли
                menu.display();
            }
            if (selectedOption == "Выполнить задание (89 вариант)")
            {
                system("cls");//очистка консоли

                DataInteraction::Zadanie(d, amountofdata);
                system("pause");//задержка консоли
                system("cls");//очистка консоли
                menu.display();
            }

            
        }
    }

    return 0;
}
