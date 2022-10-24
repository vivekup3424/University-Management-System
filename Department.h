#include<iostream>
#include<vector>
#include<string>
using namespace std;
//I think department should be an abstract class
//for it is having dependency to student as well as faculties
class Department
{
private:
	string departmentName;
	string departmentHOD;
	string  departmentID; //ID of the department
	int departmentStrength; //total num of students in department
public:
    Department();
	virtual ~Department()=default; //this makes it abstract class
	//Declaring the methods
	
//Setters
	void setDepartmentName(string);
	void setHODName(string);    //name of HOD
	void setDepartmentID(string);
	void setDepartmentStrength(int); //number of students in department

//getters
	string getDepartmentName();
	string getHODName();
	string getDepartmentID();
	int getDepartmentStrength();
};

Department::Department()
{
    this->departmentHOD = "";
	this->departmentID = "";
	this->departmentName = "";
	this->departmentStrength = 0;
}
void Department::setDepartmentID(string id)
{
	this->departmentID = id;
}
void Department::setDepartmentName(string name)
{
	this->departmentName = name;
}
void Department::setHODName(string name)
{
	this->departmentHOD = name;
}
void Department::setDepartmentStrength(int s)
{
	this->departmentStrength = s;
}

string Department::getDepartmentID()
{
	return this->departmentID;
}
string Department::getDepartmentName()
{
	return this->departmentName;
}
string Department::getHODName()
{
	return this->departmentHOD;
}
int Department::getDepartmentStrength()
{
	return this->departmentStrength;
}