#include<iostream>
#include"Display.h"
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
	cout<<"1.Go to Student Menu\n";
	cout<<"2.Go to Faculty Menu\n";
	cout<<"3.Go to Employee Menu\n";
	cout<<"4.Go to Classroom Menu\n";
	cout<<"----------------------------------------------\n";
	cin>>option;

	switch (option)
	{
	case 1:
	{
		cout<<"Student Menu:-\n";
		cout<<"5.Add a new student in the university\n";
		cout<<"6.Show the details of all students\n";
		cout<<"7.Show the Academic Record of all students\n";
		cout<<"8.Show the Courses opted by a particular student\n";
		cout<<"9.Remove Student from the university\n";
		cin>>option;
		switch (option)
		{
		case 5:
		{
			//cout<<"5.Add a new student in the university\n";
			display.setStudentData();
			break;
		}
		case 6:
		{
			//cout<<"6.Show the details of all students\n";
			display.ShowStudentsRecord();
			break;
		}
		case 7:
		{
			//cout<<"7.Show the Academic Record of all students\n";
			display.ShowStudentsAcademicRecord();
			break;
		}
		case 8:
		{
			//cout<<"8.Show the Courses opted by a particular student\n";
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
		case 9:
			{
				//cout<<"9.Remove Student from the university\n";
				cout<<"Enter the ID of student to be deleted: ";
				string id;
				cin>>id;
				display.deleteStudentData(id);
				break;
			}
		default:
			break;
		}
		break;
	}
	
	case 2:
	{
		cout<<"Faculty Menu:-\n";
		cout<<"10.Add a new faculty in the university\n";
		cout<<"11.Show the details of all faculties in university\n";
		cout<<"12.Show the details of accounts of all faculties\n";
		cout<<"13.Remove Faculty from the university\n";
		cin>>option;
		switch (option)
		{
		case 10:
		{
			//cout<<"10.Add a new faculty in the university\n";
			display.setFacultiesInfo();
			break;
		}
		case 11:
		{
			//cout<<"11.Show the details of all faculties in university\n";
			display.ShowFacultiesDetails();
			break;
		}
		case 12:
		{
			//cout<<"12.Show the details of accounts of all faculties\n";
			display.ShowFacultiesAccountDetails();
			break;
		}
		case 13:
		{
			//cout<<"13.Remove Faculty from the university\n";
			cout<<"Enter the ID of faculty to be deleted: ";
			string id;
			cin>>id;
			display.deleteFacultyData(id);
			break;
		}
		default:
			break;
		}
		break;
	}
	
	case 3:
	{
		cout<<"Employee Menu:-\n";
		cout<<"14.Add a new employee in the university\n";
		cout<<"15.Show the details of all employees in university\n";
		cout<<"16.Show the details of accounts of all employees\n";
		cout<<"17.Remove employee from the university\n";
		cin>>option;
		switch (option)
		{
		case 14:
		{
			//cout<<"14.Add a new employee in the university\n";
			display.setEmployeesInfo();
			break;
		}
		case 15:
		{
			//cout<<"15.Show the details of all employees in university\n";
			display.ShowEmployeesDetails();
			break;
		}
		case 16:
		{
			//cout<<"16.Show the details of accounts of all faculties\n";
			display.ShowEmployeesAccountDetails();
			break;
		}
		case 17:
		{
			//cout<<"17.Remove employee from the university\n";
			cout<<"Enter the ID of employee to be deleted: ";
			string id;
			cin>>id;
			display.deleteEmployeeData(id);
			break;
		}
		default:
			break;
		}
		break;
	}
	
	case 4:
	{
		cout<<"17.Add a new classroom in the university\n";
		cout<<"18.Add a new student in a classroom\n";
		cout<<"19.Add a new faculty in a classroom\n";
		cout<<"20.Show all the classrooms in the university\n";
		cout<<"21.Remove a student from a classroom\n";
		cout<<"22.Remove a faculty from a classroom\n";
		cin>>option;
		switch (option)
		{
		case 17:
	{
		//out<<"17.Add a new classroom in the university\n";
		display.setClassroomInfo();
		break;
	}
		case 18:
	{
		//cout<<"18.Add a new student in a classroom.\n";
		int ClassroomID; string StudentID;
		cout<<"Enter the ID of classroom: ";
		cin>>ClassroomID;
		cout<<"Enter the ID of student to be added in classroom: ";
		cin>>StudentID;
		display.AddStudentInClassroom(ClassroomID,StudentID);
		break;
	}
	case 19:
	{
		//out<<"19.Add a new faculty in a classroom.\n";
		int ClassroomID; string FacultyID;
		cout<<"Enter the ID of classroom: ";
		cin>>ClassroomID;
		cout<<"Enter the ID of Faculty to be added in classroom: ";
		cin>>FacultyID;
		display.AddFacultyInClassroom(ClassroomID,FacultyID);
		break;
	}
	case 20:
	{
		//cout<<"14.Show all the classrooms in the university\n";
		display.ShowClassroomDetails();
		break;
	}
	case 21:
	{
		//out<<"21.Remove a new student in a classroom.\n";
		int ClassroomID; string StudentID;
		cout<<"Enter the ID of classroom: ";
		cin>>ClassroomID;
		cout<<"Enter the ID of Student to be removed from classroom: ";
		cin>>StudentID;
		display.removeStudentFromClassroom(ClassroomID,StudentID);
		break;
	}
	case 22:
	{
		//out<<"22.Remove a faculty from classroom.\n";
		int ClassroomID; string FacultyID;
		cout<<"Enter the ID of classroom: ";
		cin>>ClassroomID;
		cout<<"Enter the ID of Faculty to be removed in classroom: ";
		cin>>FacultyID;
		display.removeFacultyFromClassroom(ClassroomID,FacultyID);
		break;
	}
		default:
			break;
		}
		break;
	}
	break;
	}
	
	cout<<"Enter 'y' to continue or Enter 'n' to exit the program.\n";
	cin>>choice;
	}while (choice=='y'||choice=='Y');
	return 0;
}