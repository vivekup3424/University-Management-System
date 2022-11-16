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

    //deletion
    void remove_student(string id);//find the iterator having this id from vector and erase it
    void remove_faculty(string id);
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
    cout<<"\n";
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
    cout<<"\n";
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
void Classroom::remove_student(string id){
    vector<string>::iterator student_iterator = students_id.end();
    for (auto i = students_id.begin(); i !=students_id.end(); i++)
    {
        if(*i == id){
            //match found hence removing it
            student_iterator = i;
            students_id.erase(student_iterator);
            cout<<"Removed Student ID: "<<*student_iterator<<"\n";
        }
    }
}
void Classroom::remove_faculty(string id){
    vector<string>::iterator faculty_iterator = faculties_id.end();
    for (auto i = faculties_id.begin(); i !=faculties_id.end(); i++)
    {
        if(*i == id){
            //match found hence removing it
            faculty_iterator = i;
            faculties_id.erase(faculty_iterator);
            cout<<"Removed Faculty ID: "<<*faculty_iterator<<"\n";
        }
    }
}