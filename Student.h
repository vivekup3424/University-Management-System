#pragma once
#include"Courses.h" //course is aggregating to a student
#include"AcademicRecord.h"
#include "Person.h"
#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
using namespace std;

//We are using composition for courses because two students can have a 
//set of course record, hence I am not using inheritance between Student and
//Courses
class Student:public AcademicRecord,public Person
{
private:
	
	string institute_email;

public:
	Courses A;//A contains all information about the courses a student has opt for.
	//int index; //I might remove this one
	Student();
	~Student();
	//Using polymorphism between methods
	void ShowStudentAcademicRecord(); //shows the academic record of current student
	void ShowStudentCoursesInfo(); //getting the information for all courses of student
	
	//setter
	void set_institute_email(string email);
	void setDepartmentID(string);

	//getter
	string get_institute_email();

};
Student::Student()
{
	institute_email = "";
}
Student::~Student()
{
	;
}
void Student::ShowStudentAcademicRecord()
{
	//cout<<"\nProgramme name  : "<<this->get_program_name()<<"\n";
	//cout<<"\nAdmission num: "<<this->get_admission_no()<<"\n";
	//cout<<"\nEnroll number: "<<this->get_enroll_no()<<"\n";
	//cout<<"\nThe Session of student: ( "<<this->get_session().first<<","<<this->get_session().second<<" ).\n";
	//cout<<"\nThe CGPA of student: "<<this->get_CGPA()<<"\n";
	//cout<<"\nThe total credits of student: "<<this->get_total_credits()<<"\n";

	cout<<setw(12)<<this->get_program_name()<<" "
	<<setw(14)<<this->get_admission_no()<<" "
	<<setw(14)<<this->get_enroll_no()<<" "
	<<setw(4)<<"("<<this->get_session().first<<","<<this->get_session().second<<" )"<<" "//4+4+1
	<<setw(4)<<this->get_CGPA()<<" "
	<<setw(7)<<this->get_total_credits()<<"\n";
}
void Student::ShowStudentCoursesInfo()
{

	int size = this->A.get_total_no_courses();
	cout<<"Course Name    Attendance Percentage    Marks\n";
	for (int i = 0; i < size; i++)
	{
		cout<<setw(11)<<this->A.get_courses_enrolled(i)<<"\t";
		cout<<setw(22)<<this->A.get_coursewise_attendance_percentage(i)<<"\t";
		cout<<setw(5)<<this->A.get_course_wise_marks(i)<<"\t";
		cout<<"\n";
	}	
	cout << "\nThe total number of courses are " << this->A.get_total_no_courses()<<endl;
}

void Student::set_institute_email(string email)
{
	this->institute_email = email;
}
string Student::get_institute_email()
{
	return this->institute_email;
}