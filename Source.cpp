#include<iostream>
#include"Display.h"
#include"Department.h"
#include"Student.h"
#include"Courses.h"
#include"Faculties.h"
#include"Employee.h"
#include<vector>
#include<string>
using namespace std;
int main()
{
	cout<<"University Management System\n";
	cout<<"Click the options to do desired results:\n";
	cout<<"1.Add a new student in the university\n";
	cout<<"2.Show the details of all students\n";
	cout<<"3.Show the Academic Record of all students\n";
	cout<<"4.Show the Courses opted by a particular student\n";
	cout<<"5.Add a new faculty in the university\n";
	cout<<"6.Show the details of all faculties in university\n";
	cout<<"7.Add a new employee in the university\n";
	cout<<"8.Show the details of all employees in university\n";
	cout<<"9.Show the details of accounts of a particular employee\n";
	cout<<"10.Add a new department in the university\n";//?
	cout<<"11.Show all the department in the university\n";
	cout<<"12.Add a new classroom in the university\n";
	cout<<"13.Add a new student in a classroom\n";
	cout<<"14.Show all the classrooms in the university\n";
	
	int choice;
	cin>>choice;

	Display display;
}