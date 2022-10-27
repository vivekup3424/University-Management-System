//This class works as a major setter and getter function
//for all the classes.
/*This will have all the data of our university inside
it, as its data memebers also, this will set and get the data*/
#pragma once
#include "Department.h"
#include "Student.h"
#include "Courses.h"
#include "Faculties.h"
#include "Employee.h"
#include "Classroom.h"
#include <vector>
#include <string>
using namespace std;
class Display
{
private:
	//Using Inheritance
	vector<Student> students;
	Courses courses; //this data members is extra

	vector<Faculties> faculties;

	vector<Employee> employees;

	vector<Classroom> classrooms;

    //Using Polymorphism
	Department* department=new Faculties();

public:
	int student_counter = 0;
	int faculties_counter = 0;
	int courses_counter = 0;
	//setter
	void setStudentData(string id, string name, string email, int contact_number, string address, string institute_email, Courses A);
	void setStudentAcademicRecord(string program_name, int admission_no, int enroll_no, int begin_year, int end_year, float CGPA, int credits);
	void setFacultiesInfo();
	void setEmployeesInfo();
	void setClassroomInfo();
	//getter
	//showd the record of all students
	void ShowStudentsRecord();
	void ShowStudentCoursesInfo(int n); //n is the index number
	void ShowStudentsAcademicRecord();
	void ShowFacultiesDetails();//view the details of the all faculties except account detail
	void ShowFacultiesAccountDetails();//view the account details of all faculties
	void ShowEmployeesDetails();
	void ShowEmployeesAccountDetails();
	void ShowClassroomDetails(); //view the details of all classrooms
};

void Display::setStudentAcademicRecord(string program_name, int admission_no, int enroll_no, int begin_year,int end_year, float CGPA, int credits)
{
	students[student_counter].set_program_name(program_name);
	students[student_counter].set_admission_no(admission_no);
	students[student_counter].set_enroll_no(enroll_no);
	students[student_counter].set_session(begin_year,end_year);
	students[student_counter].set_CGPA(CGPA);
	students[student_counter].set_total_credits(credits);
};
//setting up all the data for a particulat student
//I am inputting Course directly
//By first asking for the Course details separately
void Display::setStudentData(string id, string name, string email, int contact_number, string address, string institute_email, Courses A)
{
	students[student_counter].set_id(id);
	students[student_counter].set_name(name);
	students[student_counter].set_email(email);
	students[student_counter].set_contact_number(contact_number);
	students[student_counter].set_address(address);
	students[student_counter].set_institute_email(institute_email);
	students[student_counter].A = A;
};

void Display::ShowStudentsRecord()
{
	int size  = students.size();
	cout<<"ID\tName\tEmail\tContact_Number\tAddress\tInsti_EMail\t\n";
	for (int i = 0; i < size; i++)
	{
		cout<<students[i].get_id()<<" "<<students[i].get_name()<<" "<<students[i].get_email()<<" "<<students[i].get_contact_number()<<" "<<students[i].get_address()<<students[i].get_institute_email()<<"\n";
	}
}
void Display::ShowStudentCoursesInfo(int index)
{
	if(index>=students.size())
	{
		cout<<"Enter correct input\n";
	}
	else
	{
		Courses subjects = students[index].A;
		int size = subjects.get_total_no_courses();
		cout<<"Course_Name\tMarks\tAttendance_Percentage\n";
		for (int i = 0; i < size; i++)
		{
			cout<<subjects.get_courses_enrolled(i)<<" "<<subjects.get_course_wise_marks(i)<<" "<<subjects.get_coursewise_attendance_percentage(i)<<"\n";
		}
	}
}
void Display::ShowStudentsAcademicRecord()
{
	int size = students.size();
	cout<<"Program Name  Admission_No  Enroll_No  Session_Time  CGPA  Total_Credits\n";
	for (int i = 0; i < size; i++)
	{
		cout<<students[i].get_program_name()<<"  "<<students[i].get_admission_no()<<"  "<<students[i].get_enroll_no()<<"  ("<<students[i].get_session().first<<" , "<<students[i].get_session().second<<")  "<<students[i].get_CGPA()<<"  "<<students[i].get_total_credits()<<"\n";
	}
	
}

//For faculties
void Display::setFacultiesInfo()
{
	int size;
	cout<<"Enter the number of faculties: ";
	cin>>size;
	for (int i = 0; i < size; i++)
	{
		cout<<"For faculty "<<i+1<<" Enter the following: \n";
		cout<<"ID  Name  Email  Contact_Number  Address Faculty_Type  Faculty_Description\n";
		string id,name,email,address,F_type,desc;
		int contact_num;
		cin>>id>>name>>email>>contact_num>>address>>F_type>>desc;
		faculties[i].set_id(id);
		faculties[i].set_name(name);
		faculties[i].set_email(email);
		faculties[i].set_contact_number(contact_num);
		faculties[i].set_address(address);
		faculties[i].set_faculty_type(F_type);
		faculties[i].set_faculty_desc(desc);
		cout<<"Enter Accounts details: \n";
		cout<<"Decided_Salary  Payment_Method  Total_Working_Hours\n";
		string method;
		int hours;
		float salary;
		cin>>salary>>method>>hours;
		//settinh up account details
		faculties[i].set_payments(salary,method,hours);
	}
}
void Display::ShowFacultiesDetails()
{
	int total = faculties.size();
	cout<<"ID  Name  EMail  Contact-Number  Address  Faculty-Type  Faculty-Desc\n";
	Faculties current; //current faculty
	for (int i = 0; i < total; i++)
	{
		current = faculties[i];
		cout<<current.get_id()<<"  "<<current.get_name()<<"  "<<current.get_contact_number()<<"  "<<
		current.get_address()<<"  "<<current.get_faculty_type()<<"  "<<current.get_faculty_desc()<<"\n";
	}
}
void Display::ShowFacultiesAccountDetails()
{
	int total = faculties.size();
	Faculties current; //current faculty
	for (int i = 0; i < total; i++)
	{
		current.showPaymentDetails(); //shows the payment details
	}
}

//For Employees
void Display::setEmployeesInfo()
{
	int size;
	cout<<"Enter the number of employees: ";
	cin>>size;
	for (int i = 0; i < size; i++)
	{
		cout<<"For employee "<<i+1<<" Enter the following: \n";
		cout<<"ID  Name  Email  Contact_Number  Address Employee-Job\n";
		string id,name,email,address,job;
		int contact_num;
		cin>>id>>name>>email>>contact_num>>address>>job;
		employees[i].set_id(id);
		employees[i].set_name(name);
		employees[i].set_email(email);
		employees[i].set_contact_number(contact_num);
		employees[i].set_address(address);
		employees[i].set_employee_job(job);
		cout<<"Enter Accounts details: \n";
		cout<<"Decided_Salary  Payment_Method  Total_Working_Hours\n";
		string method;
		int hours;
		float salary;
		cin>>salary>>method>>hours;
		//settinh up account details
		employees[i].set_payments(salary,method,hours);
	}
}
void Display::ShowEmployeesDetails()
{
	int total = employees.size();
	cout<<"ID  Name  EMail  Contact-Number  Address  Employee-Job\n";
	Employee current; //current employee
	for (int i = 0; i < total; i++)
	{
		current = employees[i];
		cout<<current.get_id()<<"  "<<current.get_name()<<"  "<<current.get_contact_number()<<"  "<<
		current.get_address()<<"  "<<current.get_employee_job()<<"\n";
	}
}
void Display::ShowEmployeesAccountDetails()
{
	int total = employees.size();
	Employee current; //current employee
	for (int i = 0; i < total; i++)
	{
		current.showPaymentDetails(); //shows the payment details
	}
}

