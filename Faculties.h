#pragma once
#include "Accounts.h"
#include "Department.h"
#include "Person.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//this header contains information about all the faculties that are currently 
//teaching at the institute

//Faculties has a data member of Accounts class
//this implies there is a composition between Accounts and Faculties

class Faculties:public Department,public Person
{
private:
	string faculty_type;
	string faculty_description;
    Accounts accounts;
public:
	Faculties()=default;
	~Faculties()=default;
	//Polymorphism - virtual function overriding
	
	//Setters
	void set_payments(float, string, float);
	void set_faculty_type(string);
	void set_faculty_desc(string);
	//Getters
	//for showing payments
	void showPaymentDetails();
	string get_faculty_type();
	string get_faculty_desc();
};
Faculties::Faculties()
{
	faculty_type = "";
	faculty_description = "";
	accounts = Accounts();
}
Faculties::~Faculties()
{
	;
}
void Faculties::set_payments(float decidedSalary, string payment_method, float total_working_hours)
{
	//Using composition
	accounts.set_decided_salary(decidedSalary);
	accounts.set_payment_method(payment_method);
	accounts.set_total_working_hours(total_working_hours);
}
void Faculties::showPaymentDetails()
{
	cout<<"For Faculty: \n";
	cout<<"Name: "<<this->get_name()<<"\n";
	cout << "\nThe decided salary  : " << accounts.get_decided_salary();
	cout << "\nThe payment method  : " << accounts.get_payment_method();
	cout << "\nThe deducted salary : " << accounts.get_deducted_salary();
	cout << "\nThe paid salary     : " << accounts.get_paid_salary();
	cout << "\nThe bonus salary    : " << accounts.get_decided_salary()<<"\n";
}
void Faculties::set_faculty_type(string type)
{
	this->faculty_type = type;
}
void Faculties::set_faculty_desc(string desc)
{
	this->faculty_description = desc;
}
string Faculties::get_faculty_type()
{
	return this->faculty_type;
}
string Faculties::get_faculty_desc()
{
	return this->faculty_description;
}