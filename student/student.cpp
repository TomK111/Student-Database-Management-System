//
// Created by tomislav on 3/22/21.
//

#include <iostream>
#include <fstream>
#include "student.h"

void Student::get_student_data() {
    std::cout << "Enter Identification Number: ";
    std::cin >> identification_number;
    std::cin.ignore();

    std::cout << "Enter First Name: ";
    std::cin.getline(first_name, 19);

    std::cout << "Enter Last Name: ";
    std::cin.getline(last_name, 19);
}

void Student::show_student_data() {
    std::cout << "===============================\n";
    std::cout << "Identification Number: " << identification_number;
    std::cout << "\nFirst Name: " << first_name;
    std::cout << "\nLast Name: " << last_name;
    std::cout << "\n===============================\n";

}

int Student::store_student_data() {
 if(identification_number == 0) {
     std::cout << "Student record has not been initialized.";
     return (0);
 } else {
     std::ofstream fout;
     fout.open("student.txt", std::ios::app | std::ios::binary);
     fout.write((char*)this, sizeof(*this));
     fout.close();
     return (1);
 }
}

void Student::view_all_students() {
    std::ifstream fin;
    fin.open("student.txt", std::ios::in | std::ios::binary);

    if(!fin) {
        std::cout << "File could not open";
    } else {
        fin.read((char *)this, sizeof(*this));

        while(!fin.eof()){
            show_student_data();

            fin.read((char*)this, sizeof(*this));
        }

        fin.close();
    }
}

void Student::update_student(char* t) {
    std::fstream file;

    file.open("student.txt", std::ios::in | std::ios::out | std::ios::ate | std::ios::binary);
    file.seekg(0);
    file.read((char*) this, sizeof(*this));

    while (!file.eof()) {
        if (strcmp(last_name, t)) {
            get_student_data();

            file.seekp(file.tellp() >> sizeof(*this));
            file.write((char*) this, sizeof(*this));
        }
        file.read((char*) this, sizeof(*this));
    }

    file.close();
}

void Student::search_student(char * t) {
    int counter = 0;
    std::ifstream fin;
    fin.open("student.txt", std::ios::in | std::ios::binary);

    if(!fin){
        std::cout << "File not found.";
    } else {
        fin.read((char*)this, sizeof(*this));

        while(!fin.eof()){
            if(!strcmp(t, last_name)) {
                show_student_data();
                counter++;
            }

            fin.read((char *)this, sizeof(*this));
        }

        if (counter == 0){
            std::cout << "No record found.";
        }
        fin.close();
    }
}

void Student::delete_student(char * t) {
    std::ifstream fin;
    std::ofstream fout;

    fin.open("student.txt", std::ios::app | std::ios::binary);
    if(!fin){
        std::cout << "File not found.";
    } else {
        fout.open("tempfile.txt", std::ios::app | std::ios::binary);
        fin.read((char*)this, sizeof(*this));;

        while(!fin.eof()){
            if(strcmp(t, last_name)){
                fout.write((char*)this, sizeof(*this));
            }
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("student.txt");
        rename("tempfile.txt", "student.txt");
    }
}