#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//Every student has a unique Academic Record, no Academic 
//Record can be of two different students
class AcademicRecord
{
private:
	string programme_name; //Like B.TECH CSE
	int admission_no;
	int enroll_no;
	pair<int,int> session_time_period; //duration of program like (2020-2024)
	float CGPA;
	int total_credits;
public:
	AcademicRecord()=default;
	~AcademicRecord()=default;
	//setters
	void set_CGPA(float);
	void set_total_credits(int);
	void set_program_name(string);
	void set_admission_no(int);
	void set_enroll_no(int);
	void set_session(int,int);
	//getters
	float get_student_marks(int);
	char get_student_grades(int);
	float get_CGPA();
	int get_total_credits();
	string get_program_name();
	int get_admission_no();
	int get_enroll_no();
	pair<int,int> get_session();
};

//defining setters
void AcademicRecord::set_CGPA(float cgpa)
{
	this->CGPA = cgpa;
}
void AcademicRecord::set_total_credits(int cre)
{
	this->total_credits = cre;
}
void AcademicRecord::set_program_name(string name)
{
	this->programme_name = name;
}
void AcademicRecord::set_admission_no(int num)
{
	this->admission_no = num;
};
void AcademicRecord::set_enroll_no(int num)
{
	this->enroll_no = num;
};
void AcademicRecord::set_session(int a,int b)
{
	this->session_time_period = pair<int,int>(a,b);
};

//defining getters
float AcademicRecord::get_CGPA()
{
	return this->CGPA;
}
int AcademicRecord::get_total_credits()
{
	return this->total_credits;
}
string AcademicRecord::get_program_name()
{
	return this->programme_name;
}
int AcademicRecord::get_admission_no()
{
	return this->admission_no;
};
int AcademicRecord::get_enroll_no()
{
	return this->enroll_no;
};
pair<int,int> AcademicRecord::get_session()
{
	return this->session_time_period;
};

