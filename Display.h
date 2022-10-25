/*#pragma once
#include"Department.h"
#include"Student.h"
#include"Courses.h"
#include"Faculties.h"
#include"Employee.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Display
{
private:
	vector<Student> *student;
	Courses courses;
	vector<Faculties> *faculties;

    //Using Polymorphism
	//Department* department=new Faculties();	
public:
	Display()=default;
	~Display();

	//void setEmployeesInfo(string name, int id, string address, string email, float decidedSalary, string payment_method, float total_working_hours);

	void ShowStudentCoursesInfo();

	void ShowStudentRecord(int);

	void ShowFacultiesDetails(int);

};

void Display::ShowStudentRecord(int id)
{
	
	
	
	cout<<"\nThe name of student is equal to "<<student->getName(id);
	cout << "\nThe Id of student is equal to " << student->get_id(id);
	cout << "\nThe Email of student is equal to " << student->getEmail(id);
	cout << "\nThe Adress of student is equal to " << student->get_address(id);

	//Now showing the student academic records
	student->ShowStudentAcademicRecord(id);

}
void Display::ShowStudentCoursesInfo()
{
	//Passing the courses object to the courses info
	student->ShowStudentCoursesInfo(courses);
}
void Display::ShowFacultiesDetails(int id)
{
	cout<<"\nThe id of department faculty is "<<department->get_id(id);
	cout << "\nThe Name of department faculty is " << department->getName(id);
	cout << "\nThe Email of department faculty is " << department->getEmail(id);
	cout << "\nThe Address of department faculty is " << department->get_address(id);
	cout << "\nThe Department faculty strength is " << department->getDepartmentStrength();
}
void Display::ShowEmployeesDetails(int id)
{
	cout << "\nThe id of Employee is " << department->get_id(id);
	cout << "\nThe Name of Employee is " << department->getName(id);
	cout << "\nThe Email of Employee is " << department->getEmail(id);
	cout << "\nThe Address of Employee is " << department->get_address(id);
	cout << "\nThe Department Employee strength is " << department->getDepartmentStrength();
}
Display::~Display()
{
	delete department;
	delete student;
}*/
