#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Classroom
{
private:
    int strength; //total num of students
    vector<string> students_id; //list of ID of students in the class
    vector<string> faculties_id;//list of ID of faculties in the class
public:
    Classroom();
    //Setters
    void add_student(string);
    void add_faculty(string);

    //Getters
    vector<string> get_students();
    vector<string> get_faculties();
    int get_strength();
    ~Classroom();
};

Classroom::Classroom()
{
    this->strength = 0;//default value is 0
    this->faculties_id = {};
    this->students_id = {};
}

Classroom::~Classroom()
{
}
void Classroom::add_student(string id)
{
    this->students_id.push_back(id);
}
void Classroom::add_faculty(string id)
{
    this->faculties_id.push_back(id);
}
vector<string> Classroom::get_students()
{
    return this->students_id;
}
vector<string> Classroom::get_faculties()
{
    return this->faculties_id;
}
int Classroom::get_strength()
{
    return this->strength;
}