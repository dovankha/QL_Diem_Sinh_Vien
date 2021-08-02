#pragma once
#include "declare_menu.h"

void add_student();
void remove_student();
void modify_student();
void show_student();

void menu_student()
{
    while (1)
    {
        system("cls");
        SetColor(Color::YELLOW);
        cout << "\n\t+---------------------------------------+";
        cout << "\n\t|       ***** MENU STUDENT *****        |";
        cout << "\n\t|            1. Add student             |";
        cout << "\n\t|            2. Delete student          |";
        cout << "\n\t|            3. Modify student          |";
        cout << "\n\t|            4. Show student list       |";
        cout << "\n\t|            0. Exit                    |";
        cout << "\n\t+---------------------------------------+";
        SetColor(Color::WHITE);
        do
        {
            cout << "\n\nMake a choice: ";
            cin >> choice;
            if (choice < 0 || choice > 4)
            {
                cout << "Unhappy choice!" << endl;
                getch();
            }
        } while (choice < 0 || choice > 4);

        if (choice == 1)
        {
            add_student();
        }
        else if (choice == 2)
        {
            remove_student();
        }
        else if (choice == 3)
        {
            modify_student();
        }

        else if (choice == 4)
        {
            show_student();
        }
        else
        {
            break;
        }
    }
}

void add_student()
{
    string classId;
    cout << "Enter class ID: ";
    cin.ignore();
    getline(cin, classId);

    try
    {
        Student_linked_list *studentList = class_list->get_students_linked(classId);
        if (studentList == nullptr)
        {
            cout << "\nStudent list is empty!\n";
            studentList = new Student_linked_list();
        }
        Student student;
        student.getDataFromInput();

        if (studentList->is_contain_id(student.get_id()) != -1)
        {
            throw string("id existed!!");
        }

        studentList->push_back(student);
        class_list->set_students_linked(classId, studentList);

        Student_linked_list *studentList2 = class_list->get_students_linked(classId);
        studentList2->ssort();
    }
    catch (string &e)
    {
        cout << "error: " << e << "\n";
    }
    getch();
}

void remove_student()
{
    string classId;
    cout << "Enter class ID: ";
    cin.ignore();
    getline(cin, classId);
    string student_ID;
    cout << "\nEnter student ID to delete: ";
    cin.ignore();
    getline(cin, student_ID);

    try
    {
        Student_linked_list *studentList = class_list->get_students_linked(classId);
        if (studentList == nullptr)
        {
            cout << "\nStudent list is empty!\n";
            studentList = new Student_linked_list();
        }
        studentList->remove_by_id(student_ID);
        class_list->set_students_linked(classId, studentList);
        Student_linked_list *studentList2 = class_list->get_students_linked(classId);
    }
    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "error: " << e << "\n";
    }
    SetColor(Color::WHITE);
    cout << "\nSuccessful!" << endl;
    getch();
}

void modify_student()
{
    string classId;
    cout << "Enter class ID: ";
    cin.ignore();
    getline(cin, classId);
    string student_ID;
    cout << "\nEnter student ID to modify: ";
    cin.ignore();
    getline(cin, student_ID);

    try
    {
        Student_linked_list *studentList = class_list->get_students_linked(classId);
        if (studentList == nullptr)
        {
            cout << "\nStudent list is empty!\n";
            studentList = new Student_linked_list();
        }
        studentList->replace_student_by_id(student_ID);
        cout << "a";
        class_list->set_students_linked(classId, studentList);
        // Student_linked_list *studentList2 = class_list->get_students_linked(classId);
    }
    catch (string &e)
    {
        SetColor(Color::RED);
        cout << "error: " << e << "\n";
    }
    SetColor(Color::WHITE);
    getch();
}

void show_student()
{
    // bị bug - chỗ đọc file (có id lop nhung ko doc duoc sinh vien).
    string classId;
    cout << "Enter class id: ";
    cin.ignore();
    getline(cin, classId);
    try
    {
        Student_linked_list *studentList = class_list->get_students_linked(classId);
        if (studentList == nullptr)
        {
            cout << "\nStudent list is empty!\n";
            studentList = new Student_linked_list();
        }
        studentList->show_data();
        studentList->ssort();
    }
    catch (string &e)
    {
        std::cout << e << "\nID class don't exist.\n";
    }
    getch();
}
