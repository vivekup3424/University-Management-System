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
    int classroom_id; //used as unique identifier for a classroom
public:
    Classroom();
    //Setters
    void add_student(string);
    void add_faculty(string);
    void add_id(int);
    //Getters
    vector<string> get_students();
    vector<string> get_faculties();
    int get_strength();
    int get_id();
    ~Classroom();
};

Classroom::Classroom()
{
    this->strength = 0;//default value is 0
    this->faculties_id = {};
    this->students_id = {};
    classroom_id = 0;
}

Classroom::~Classroom()
{
    ;
}
void Classroom::add_student(string id)
{
    this->students_id.push_back(id);
    strength++;
}
void Classroom::add_faculty(string id)
{
    this->faculties_id.push_back(id);
}
void Classroom::add_id(int id)
{
    classroom_id = id;
}
//prints the list of student in the classroom
vector<string> Classroom::get_students()
{
    cout<<"Students' IDs are: \n";
    for(int i = 0; i < students_id.size(); i++)
    {
        cout<<students_id[i]<<"\t";
    }
    
    return this->students_id;
}
//prints the list of faculties for the classroom
vector<string> Classroom::get_faculties()
{
    cout<<"Faculties' IDs are: \n";
    for(int i = 0; i < faculties_id.size(); i++)
    {
        cout<<faculties_id[i]<<"\t";
    }
    return this->faculties_id;
}
int Classroom::get_strength()
{
    return this->strength;
}
int Classroom::get_id()
{
    return classroom_id;
}