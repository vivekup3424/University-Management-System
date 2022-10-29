#pragma once
#include"Accounts.h"
#include"Department.h"
#include "Person.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Employee:public Person 
{
private:
	string employee_job;
	Accounts accounts;
public:
	Employee();
	~Employee();
	//Setters
	void set_payments(float,string,float);
    void set_employee_job(string);

	//Getters
	//for showing payments
	void showPaymentDetails();
    string get_employee_job();
};
Employee::Employee()
{
	employee_job = "";
	accounts = Accounts();
}
Employee::~Employee()
{
	;
}
void Employee::set_payments(float decidedSalary, string payment_method, float total_working_hours)
{
	//Using composition
	accounts.set_decided_salary(decidedSalary);
	accounts.set_payment_method(payment_method);
	accounts.set_total_working_hours(total_working_hours);
}
void Employee::showPaymentDetails()
{
	cout << "For Faculty: \n";
	cout << "Name: "<<this->get_name()<<"\n";
	cout << "\nThe decided salary  : " << accounts.get_decided_salary();
	cout << "\nThe payment method  : " << accounts.get_payment_method();
	cout << "\nThe deducted salary : " << accounts.get_deducted_salary();
	cout << "\nThe paid salary     : " << accounts.get_paid_salary();
	cout << "\nThe bonus salary    : " << accounts.get_decided_salary()<<"\n";
}
void Employee::set_employee_job(string job)
{
    this->employee_job = job;
}
string Employee::get_employee_job()
{
    return this->employee_job;
}