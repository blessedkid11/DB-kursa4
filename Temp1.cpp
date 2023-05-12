#include "Func.h"

#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct MenuItem {
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
                cout << "> " << currentItem->text << endl;
            }
            else {
                cout << "  " << currentItem->text << endl;
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
    menu.addItem("Изменить / создать базу данных");
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
            if (selectedOption == "Изменить / создать базу данных")
            {
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
                menu.display();
                

            }
            if (selectedOption == "Вывести данные")
            {
                system("cls");//очистка консоли

                if (amountofdata != 0) {
                    DataPrint(d, amountofdata);
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
                    DataChange(d, amountofdata);
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
                    DataDelete(d, amountofdata);
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
                    DataAdd(d, amountofdata);
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
                    DataSave(d, amountofdata, filename);
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

                Zadanie(d, amountofdata);
                system("pause");//задержка консоли
                system("cls");//очистка консоли
                menu.display();
            }

            
        }
    }

    return 0;
}
