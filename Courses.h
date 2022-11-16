#pragma once
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Courses //this class maintains record for the courses a student is taking,
{			  //and his attadannce,marks and other records of each course.
private:
	vector<string> courses_enrolled; //name of all the courses taken by a student
	vector<float> course_wise_attandance_percentage;//coursewise attendance of students
	vector<int> course_wise_marks;// coursewise marks of students in a given semester
	int total_no_courses;
public:
	Courses();
	~Courses();
	//setters
	void set_courses_enrolled(string);
	void set_coursewise_attendance_percentage(float);
	void set_course_wise_marks(int); //I have changed this from float to int
	void change_course_enrolled(int ,string ,float ,int); //changing the details of nth course
	//getters
	string get_courses_enrolled(int);//getting the name of nth course info
	float get_coursewise_attendance_percentage(int);//getting the attendance of nth course
	float get_course_wise_marks(int);
    int get_total_no_courses();//get total number of courses
};
Courses::Courses()
{
	courses_enrolled = {};
	course_wise_attandance_percentage = {};
	course_wise_marks = {};
	total_no_courses = 0;
}
Courses::~Courses()
{
	;
}
void Courses::set_courses_enrolled(string ce)
{
	this->courses_enrolled.push_back(ce);//appending the "ce" course in course-list
	this->total_no_courses = courses_enrolled.size();
}
void Courses::set_coursewise_attendance_percentage(float cap) 
{
	this->course_wise_attandance_percentage.push_back(cap);
}
void Courses::set_course_wise_marks(int cm)//i have changed the parameters data-type from float to int
{
	this->course_wise_marks.push_back(cm);
}
void Courses::change_course_enrolled(int index,string course,float att,int marks)
{
	for (int i = 0; i < courses_enrolled.size(); i++)
	{
		cout << "The " << (i + 1) << " course is " << courses_enrolled[i] << endl;
	}
	this->courses_enrolled.at(index) = course; //changing the course at this particular index
	this->course_wise_attandance_percentage.at(index) = att;
	this->course_wise_marks.at(index) = marks;
}

//returns course name at a particular index
string Courses::get_courses_enrolled(int index) 
{
	return courses_enrolled[index];
}

float Courses::get_coursewise_attendance_percentage(int index)
{
	return course_wise_attandance_percentage[index];
}
float Courses::get_course_wise_marks(int index)
{
	return course_wise_marks[index];
}
int Courses::get_total_no_courses()
{
	return total_no_courses;
}