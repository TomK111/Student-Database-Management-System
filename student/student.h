//
// Created by tomislav on 3/22/21.
//

#ifndef STUDENT_MANAGEMENT_SYSTEM_STUDENT_H
#define STUDENT_MANAGEMENT_SYSTEM_STUDENT_H

#include <cstring>

class Student {
private:
    int identification_number;
    char first_name[20];
    char last_name[20];
public:
    Student(){
        identification_number= 0;
        strcpy(first_name, "N/A");
        strcpy(last_name, "N/A");
    }

    void get_student_data();

    void show_student_data();

    int store_student_data();

    void view_all_students();

    void search_student(char *);

    void update_student(char *);

    void delete_student(char *);
};

#endif //STUDENT_MANAGEMENT_SYSTEM_STUDENT_H
