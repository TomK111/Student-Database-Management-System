#include <iostream>
#include "menu/menu.h"
#include "student/student.h"

int main() {
    Student student;
    char last_name[20];

    while(1) {
        switch(menu()) {
            case 1:
                student.get_student_data();
                student.store_student_data();
                std::cout << "\nStudent Record Created.";
                break;
            case 2:
                student.view_all_students();
                break;
            case 3:
                std::cout << "\nEnter the last name of the student to search: ";
                std::cin.ignore();
                std::cin.getline(last_name, 19);
                student.search_student(last_name);
                break;
            case 4:
                std::cout << "\nEnter the last name of the student to update: ";
                std::cin.ignore();
                std::cin.getline(last_name, 19);
                student.update_student(last_name);
                break;
            case 5:
                std::cout << "\nEnter the last name of the student to delete: ";
                std::cin.ignore();
                std::cin.getline(last_name, 19);
                student.delete_student(last_name);
                break;
            case 6:
                std::cout << "\nThank you and have a nice day!";
                exit(0);
            default:
                std::cout << "\nInvalid Input";
        }
    }

}
