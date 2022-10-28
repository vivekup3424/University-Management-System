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

    //Using Polymorphism
	Department* department=new Faculties();

public:
	vector<Student> students;
	Courses courses; //this data members is extra

	vector<Faculties> faculties;

	vector<Employee> employees;

	vector<Classroom> classrooms;
	int total_students = 0;
	int total_faculties = 0;
	int courses_counter = 0;
	//setter
	void setStudentData();
	void setStudentAcademicRecord(int counter, string program_name, int admission_no, int enroll_no, int begin_year, int end_year, float CGPA, int credits);
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
	void AddStudentInClassroom(int classroomID,string studentID);
	void AddFacultyInClassroom(int classroomID,string facltyID);
};

//For stundents
void Display::setStudentAcademicRecord(int counter,string program_name, int admission_no, int enroll_no, int begin_year,int end_year, float CGPA, int credits)
{
	students[counter].set_program_name(program_name);
	students[counter].set_admission_no(admission_no);
	students[counter].set_enroll_no(enroll_no);
	students[counter].set_session(begin_year,end_year);
	students[counter].set_CGPA(CGPA);
	students[counter].set_total_credits(credits);
};
//setting up all the data for a particulat student
//I am inputting Course directly
//By first asking for the Course details separately
void Display::setStudentData()
{
	int size;
	cout<<"Enter the number of students: ";
	cin>>size;
	total_students += size;
	Student *current; //current Student
	for (int i = 0; i < size; i++)
	{
	current = &students[i];
	cout<<"For student "<<i+1<<"\nEnter the following: \n";//For general details
	cout<<"ID  Name  Email  Contact_Number  Address Faculty_Type  Faculty_Description\n";
	string ID,Name,EMail,Address,insti_email;
	int contact_number;
	cin>>ID>>Name>>EMail>>contact_number>>Address>>insti_email;
	current->set_id(ID);
	current->set_name(Name);
	current->set_email(EMail);
	current->set_contact_number(contact_number);
	current->set_address(Address);
	current->set_institute_email(insti_email);

	cout<<"Enter the Course Details: \n";//For Course Details
	int size_course;
	cout<<"Enter the number of courses: ";
	cin>>size_course;
	cout<<"Enter the following for each course: \n";
	cout<<"Course_Name  Marks  Attendance Percentage \n";
	string name;
	int marks;
	float attendance;
	for (int i = 0; i < size_course; i++)
	{
		cin>>name>>marks>>attendance;
		current->A.set_courses_enrolled(name);
		current->A.set_course_wise_marks(marks);
		current->A.set_coursewise_attendance_percentage(attendance);
	}
	cout<<"Enter the Academic Record Details: \n";//For Academic Record Details
	string program_name; int admission_no, enroll_no, begin_year, end_year, credits; float CGPA;
	cout<<"Enter Program_name, admission_no enroll_no begin_year end_year credits CGPA";
	cin>>program_name>>admission_no>>enroll_no>>begin_year>>end_year>>credits>>CGPA;
	setStudentAcademicRecord(i,program_name,admission_no,enroll_no,begin_year,end_year,credits,CGPA);
	}

	
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
	total_faculties += size;
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
	Faculties *current; //current faculty
	for (int i = 0; i < total; i++)
	{
		current = &faculties[i];
		cout<<current->get_id()<<"  "<<current->get_name()<<"  "<<current->get_contact_number()<<"  "<<
		current->get_address()<<"  "<<current->get_faculty_type()<<"  "<<current->get_faculty_desc()<<"\n";
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

//For classroom
void Display::setClassroomInfo()
{
	int num_class;
	cout<<"Enter the number of classes in university: ";
	cin>>num_class;
	for (int i = 0; i < num_class; i++)
	{
		cout<<"For classroom "<<i+1<<" enter the id of classroom: ";
		int id_classroom;
		cin>>id_classroom;
		Classroom *current = &classrooms[i]; //current class pointer
		current->add_id(id_classroom);
		int strength;
		cout<<"Enter the number of students in classroom: ";
		cin>>strength;
		cout<<"Enter the id of student inside classroom: \n";
		for (int i = 0; i < strength; i++)
		{
			string id_student;
			cin>>id_student;
			current->add_student(id_student);
		}
		cout<<"Enter the number of teachers in classroom: ";
		cin>>strength;
		cout<<"Enter the id of teacher inside classroom: \n";
		for (int i = 0; i < strength; i++)
		{
			string id_teacher;
			cin>>id_teacher;
			current->add_faculty(id_teacher);
		}	
	}
	
}
void Display::ShowClassroomDetails()
{
	int total_classrooms = classrooms.size();
	Classroom *current; //current classroom pointer
	for (int i = 0; i < total_classrooms; i++)
	{
		current = &classrooms[i];
		cout<<"For classroom with id: "<<current->get_id()<<"\n";
		cout<<"No of students: "<<current->get_strength()<<"\n";
		cout<<"ID of students in classroom are: \n";
		current->get_students();
		cout<<"\n";
		cout<<"ID of teachers in classroom are: \n";
		current->get_faculties();
		cout<<"\n";
	}	
}
void Display::AddStudentInClassroom(int classroomID,string studentID)
{
	int resultantIndex = -1;
	for (int i = 0; i < classrooms.size(); i++)
	{
		if(classrooms[i].get_id()==classroomID)
		{
			resultantIndex = i;
			break;
		}
	}
	if(resultantIndex==-1)//no class is found for the given ID
	{
		cout<<"no class is found for the given ID";
	}
	else
	{
		classrooms[resultantIndex].add_student(studentID);
	}
}
void Display::AddFacultyInClassroom(int classroomID,string facltyID)
{
	int resultantIndex = -1;
	for (int i = 0; i < faculties.size(); i++)
	{
		if(faculties[i].get_id()==facltyID)
		{
			resultantIndex = i;
			break;
		}
	}
	if(resultantIndex==-1)//no class is found for the given ID
	{
		cout<<"no class is found for the given ID";
	}
	else
	{
		classrooms[resultantIndex].add_faculty(facltyID);
	}

}