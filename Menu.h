#pragma one
#include "Menu_class.h"
#include "Menu_student.h"
#include "Menu_subject.h"


void menu()
{
    while (1)
    {
        system("cls");
        SetColor(Color::CYAN);
        cout << "\t\t+---------------------------------------+" << endl
             << "\t\t|             ****MENU****              |" << endl
             << "\t\t|               1. Class                |" << endl
             << "\t\t|               2. Student              |" << endl
             << "\t\t|               3. Subject              |" << endl
             << "\t\t|               4. Point                |" << endl
             << "\t\t|               0. Exit                 |" << endl
             << "\t\t+---------------------------------------+" << endl
             << endl
             << endl;
        SetColor(Color::WHITE);
        do
        {
            cout << "\n\nMake a choice: ";
            cin >> choice;
            if (choice < 0 || choice > 5)
            {
                cout << "Unhappy choice!" << endl;
                getch();
            }
        } while (choice < 0 || choice > 5);

        if (choice == 1)
        {
            menu_class();
        }
        else if (choice == 2)
        {
            menu_student();
        }
        else if (choice == 3)
        {
            menu_subject();
        }
        else if (choice == 4)
        {
            // menu_point();
        }
        else
        {
            break;
        }
    }
}

// nhap lop id
// nhap lan thi
// nhap ma sinh vien
// tim co sinh vien : nhap diem cho no