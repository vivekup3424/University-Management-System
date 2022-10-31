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

	Display();//default constructor

	int total_students = 0;
	int total_faculties = 0;
	//setter
	void setStudentData();
	void setStudentAcademicRecord(Student *temp,int counter, string program_name, int admission_no, int enroll_no, int begin_year, int end_year, float CGPA, int credits);
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
Display::Display()
{
	students = {};
	courses = Courses();
	faculties = {};
	employees = {};
	classrooms = {};
}

//For stundents
void Display::setStudentAcademicRecord(Student *temp,int counter,string program_name, int admission_no, int enroll_no, int begin_year,int end_year, float CGPA, int credits)
{
	temp->set_program_name(program_name);
	temp->set_admission_no(admission_no);
	temp->set_enroll_no(enroll_no);
	temp->set_session(begin_year,end_year);
	temp->set_CGPA(CGPA);
	temp->set_total_credits(credits);
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
	string dummy; //used for dummy calls
	Student *temp =new Student(); //temp Student
	for (int i = 0; i < size; i++)
	{
	cout<<"For student "<<i+1<<"\nEnter the following: \n";//For general details
	string ID,Name,EMail,Address,insti_email, contact_number;
	cout<<"ID: "; cin>>ID;
	cout<<"Name: "; cin>>Name;
	cout<<"EMail: "; cin>>EMail;
	cout<<"Contact Number: "; cin>>contact_number;
	cout<<"Address: "; cin>>Address;
	cout<<"Institute EMail: "; cin>>insti_email;
	temp->set_id(ID);
	temp->set_name(Name);
	temp->set_email(EMail);
	temp->set_contact_number(contact_number);
	temp->set_address(Address);
	temp->set_institute_email(insti_email);
	cout<<"\n-------------COURSES--------------\n";
	cout<<"Enter the Course Details: \n";//For Course Details
	int size_course;
	cout<<"Enter the number of courses: ";
	cin>>size_course;
	string name;
	int marks;
	float attendance;
	
	for (int i = 0; i < size_course; i++)
	{
		cout<<"Enter the following for each course "<<i+1<<" : \n";
		cout<<"Course Name: "; cin>>name;
		cout<<"Marks: "; cin>>marks;
		cout<<"Attendance Percentage: "; cin>>attendance;
	}
	cout<<"\n-------------ACADEMIC RECORD--------------\n";
	cout<<"Enter the Academic Record Details: \n";//For Academic Record Details
	string program_name; int admission_no, enroll_no, begin_year, end_year, credits; float CGPA;
	cout<<"Program_name: "; cin>>program_name;
	cout<<"Admission Number: "; cin>>admission_no;
	cout<<"Erollment Number: "; cin>>enroll_no;
	cout<<"Course Begin Year: ";cin>>begin_year;
	cout<<"Course End Year: "; cin>>end_year;
	cout<<"Credits: "; cin>>credits;
	cout<<"CGPA: "; cin>>CGPA; 
	setStudentAcademicRecord(temp,i,program_name,admission_no,enroll_no,begin_year,end_year,credits,CGPA);

	students.push_back(*temp); //adding a new student
	}

	
};

void Display::ShowStudentsRecord()
{
	int size  = students.size();
	cout<<"ID\tName\t\tEmail\t\tContact_Number\t\tAddress\t\tInsti_EMail\t\t\n";
	for (int i = 0; i < size; i++)
	{
		cout<<students[i].get_id()<<"\t"<<students[i].get_name()<<"\t"<<students[i].get_email()<<"\t"<<students[i].get_contact_number()<<"\t"<<students[i].get_address()<<"\t"<<students[i].get_institute_email()<<"\n";
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
		cout<<"\n-------------COURSES INFO--------------\n";
		Courses subjects = students[index].A;
		int size = subjects.get_total_no_courses();
		cout<<"Course_Name\tMarks\tAttendance_Percentage\n";
		for (int i = 0; i < size; i++)
		{
			cout<<subjects.get_courses_enrolled(i)<<"  "<<subjects.get_course_wise_marks(i)<<"  "<<subjects.get_coursewise_attendance_percentage(i)<<"\n";
		}
	}
}
void Display::ShowStudentsAcademicRecord()
{
	int size = students.size();
	cout<<"\n-------------ACADEMIC RECORD--------------\n";
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
		Faculties *temp = new Faculties();
		cout<<"For faculty "<<i+1<<" Enter the following: \n";
		string id,name,email,address,F_type,desc, contact_num;
		cout<<"ID: "; cin>>id;
		cout<<"Name: "; cin>>name;
		cout<<"EMail: "; cin>>email;
		cout<<"Contact Number"; cin>>contact_num;
		cout<<"Address: "; cin>>address;
		cout<<"Faculty Type: "; cin>>F_type;
		cout<<"Faculty Description: "; cin>>desc;
		temp->set_id(id);
		temp->set_name(name);
		temp->set_email(email);
		temp->set_contact_number(contact_num);
		temp->set_address(address);
		temp->set_faculty_type(F_type);
		temp->set_faculty_desc(desc);
		cout<<"\n-------------ACCOUNTS--------------\n";
		cout<<"Enter Accounts details: \n";
		cout<<"Decided_Salary  Payment_Method  Total_Working_Hours\n";
		string method;
		int hours;
		float salary;
		cout<<"Decided_Salary: "; cin>>salary;
		cout<<"Payment_Method: "; cin>>method;
		cout<<"Total_Working_Hours: "; cin>>hours;
		//settinh up account details
		temp->set_payments(salary,method,hours);
		faculties.push_back(*temp);
	}
}
void Display::ShowFacultiesDetails()
{
	int total = faculties.size();
	cout<<"\n-------------FACULTIES DETAIL--------------\n";
	cout<<"ID  Name  EMail  Contact-Number  Address  \tFaculty-Type  Faculty-Desc\n";
	Faculties *current; //current faculty
	for (int i = 0; i < total; i++)
	{
		current = &faculties[i];
		cout<<current->get_id()<<"  "<<current->get_name()<<"  "<<current->get_email()<<" "<<current->get_contact_number()<<"  "<<
		current->get_address()<<"  "<<current->get_faculty_type()<<"  "<<current->get_faculty_desc()<<"\n";
	}
}
void Display::ShowFacultiesAccountDetails()
{
	int total = faculties.size();
	Faculties current; //current faculty
	cout<<"\n-------------FACULTIES' ACCOUNTS--------------\n";
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
		Employee *temp = new Employee();
		cout<<"For employee "<<i+1<<" Enter the following: \n";
		string id,name,email,address,job, contact_num;
		cout<<"ID: "; cin>>id;
		cout<<"Name: "; cin>>name;
		cout<<"EMail: "; cin>>email;
		cout<<"Contact Number"; cin>>contact_num;
		cout<<"Address: "; cin>>address;;
		cout<<"Employee Job: "; cin>>job;
		temp->set_id(id);
		temp->set_name(name);
		temp->set_email(email);
		temp->set_contact_number(contact_num);
		temp->set_address(address);
		temp->set_employee_job(job);
		cout<<"Enter Accounts details: \n";
		cout<<"Decided_Salary  Payment_Method  Total_Working_Hours\n";
		string method;
		int hours;
		float salary;
		cout<<"Decided_Salary: "; cin>>salary;
		cout<<"Payment_Method: "; cin>>method;
		cout<<"Total_Working_Hours: "; cin>>hours;
		//settinh up account details
		temp->set_payments(salary,method,hours);

		employees.push_back(*temp);
	}
}
void Display::ShowEmployeesDetails()
{
	int total = employees.size();
	cout<<"\n-------------EMPLOYEES' DETAIL--------------\n";
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
	cout<<"\n-------------EMPLOYEES' ACCOUNTS--------------\n";
	for (int i = 0; i < total; i++)
	{
		current.showPaymentDetails(); //shows the payment details
	}
}

//For classroom
void Display::setClassroomInfo()
{
	int num_class;
	cout<<"\n-------------CLASSROOMS--------------\n";
	cout<<"Enter the number of classes in university: ";
	cin>>num_class;
	for (int i = 0; i < num_class; i++)
	{
		Classroom *temp = new Classroom(); //current class pointer
		cout<<"For classroom "<<i+1<<" enter the id of classroom: ";
		int id_classroom;
		cin>>id_classroom;
		temp->add_id(id_classroom);
		int strength;
		cout<<"Enter the number of students in classroom: ";
		cin>>strength;
		cout<<"Enter the id of student inside classroom: \n";
		for (int i = 0; i < strength; i++)
		{
			string id_student;
			cin>>id_student;
			temp->add_student(id_student);
		}
		cout<<"Enter the number of teachers in classroom: ";
		cin>>strength;
		cout<<"Enter the id of teacher inside classroom: \n";
		for (int i = 0; i < strength; i++)
		{
			string id_teacher;
			cin>>id_teacher;
			temp->add_faculty(id_teacher);
		}	
		classrooms.push_back(*temp);
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