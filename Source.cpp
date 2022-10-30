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
	Display display;
	int option;
	char choice = 'y';
	do
	{
		cout<<"University Management System\n";
	cout<<"Click the options to do desired results:\n";
	cout<<"1.Add a new student in the university\n";
	cout<<"2.Show the details of all students\n";
	cout<<"3.Show the Academic Record of all students\n";
	cout<<"4.Show the Courses opted by a particular student\n";
	cout<<"5.Add a new faculty in the university\n";
	cout<<"6.Show the details of all faculties in university\n";
	cout<<"7.Show the details of accounts of all faculties\n";
	cout<<"8.Add a new employee in the university\n";
	cout<<"9.Show the details of all employees in university\n";
	cout<<"10.Show the details of accounts of a particular employee\n";
	cout<<"12.Show all the department in the university\n";
	cout<<"13.Add a new classroom in the university\n";
	cout<<"14.Add a new student in a classroom\n";
	cout<<"15.Add a new faculty in a classroom\n";
	cout<<"16.Show all the classrooms in the university\n";
	cout<<"17.Enter to exit program.\n";
	cout<<"----------------------------------------------\n";
	
	cin>>option;

	switch (option)
	{
	case 1:
	{
		//cout<<"1.Add a new student in the university\n";
		display.setStudentData();
		break;
	}
	case 2:
	{
		//cout<<"2.Show the details of all students\n";
		display.ShowStudentsRecord();
		break;
	}
	case 3:
	{
		//cout<<"3.Show the Academic Record of all students\n";
		display.ShowStudentsAcademicRecord();
		break;
	}
	case 4:
	{
		//cout<<"4.Show the Courses opted by a particular student\n";
		cout<<"Enter the student's Id to view courses chosen: ";
		string id;
		cin>>id;
		int resultant_index=-1;//index of student for the given id
		//searching for required student
		for (int i = 0; i < display.total_students; i++)
		{
			if(display.students[i].get_id() == id)
			{
				resultant_index = i;
				break;
			}
		}
		if(resultant_index==-1)//no student with ID found 
		{
			cout<<"No student with this ID found";
		}
		else
		{
			display.ShowStudentCoursesInfo(resultant_index);
		}
		break;
	}
	case 5:
	{
		//cout<<"5.Add a new faculty in the university\n";
		display.setFacultiesInfo();
		break;
	}
	case 6:
	{
		//cout<<"6.Show the details of all faculties in university\n";
		display.ShowFacultiesDetails();
		break;
	}
	case 7:
	{
		//cout<<"7.Show the details of accounts of a particular faculty\n";
		display.ShowFacultiesAccountDetails();
		break;
	}
	case 8:
	{
		//cout<<"8.Add a new employee in the university\n";
		display.setEmployeesInfo();
		break;
	}
	case 9:
	{
		//cout<<"9.Show the details of all employees in university\n";
		display.ShowEmployeesDetails();
		break;
	}
	case 10:
	{
		//cout<<"10.Show the details of accounts of a particular employee\n";
		display.ShowEmployeesAccountDetails();
		break;
	}

	//This functionality is missing.
	case 11:
	{
		//cout<<"11.Add a new department in the university\n";
		display.setStudentData();
		break;
	}
	case 12:
	{
		//cout<<"11.Show all the department in the university\n";
		display.setStudentData();
		break;
	}
	case 13:
	{
		//out<<"12.Add a new classroom in the university\n";
		display.setClassroomInfo();
		break;
	}

	case 14:
	{
		//out<<"14.Add a new student in a classroom.\n";
		int ClassroomID; string StudentID;
		cout<<"Enter the ID of classroom: ";
		cin>>ClassroomID;
		cout<<"Enter the ID of student to be added in classroom: ";
		cin>>StudentID;
		display.AddStudentInClassroom(ClassroomID,StudentID);
		break;
	}
	case 15:
	{
		//out<<"15.Add a new faculty in a classroom.\n";
		int ClassroomID; string FacultyID;
		cout<<"Enter the ID of classroom: ";
		cin>>ClassroomID;
		cout<<"Enter the ID of Faculty to be added in classroom: ";
		cin>>FacultyID;
		display.AddFacultyInClassroom(ClassroomID,FacultyID);
		break;
	}
	case 16:
	{
		//cout<<"14.Show all the classrooms in the university\n";
		display.ShowClassroomDetails();
		break;
	}
	case 17:
	{
		return 0;
	}
	default:
		break;
	}
	cout<<"Enter 'y' to continue or Enter 'n' to exit the program.\n";
	cin>>choice;
	} while (choice=='y'||choice=='Y');
	
	return 0;
}
