//
// Created by tomislav on 3/22/21.
//

#include <cstdio>
#include <iostream>
#include "menu.h"

int menu() {
    int choice;
    std::cout << "\nStudent Database Management System";
    std::cout << "\n";
    std::cout << "\n\n1. Create Student Record";
    std::cout << "\n\n2. View All Student Records";
    std::cout << "\n\n3. Search Student Record";
    std::cout << "\n\n4. Update Student Record";
    std::cout << "\n\n5. Delete Student Record";
    std::cout << "\n\n6. Exit";

    std::cout << "\n\nSelect Option <1-6>: ";
    std::cin >> choice;
    return choice;
}
