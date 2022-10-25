#pragma once
#include <string>
using namespace std;
class Person
{
private:
    string id;
    string name;
    string email;
    int contact_number;
    string address;
public:
    Person();
    ~Person();
    void set_id(string);
    void set_name(string);
    void set_email(string);
    void set_contact_number(int);
    void set_address(string);
    string get_id();
    string get_name();
    string get_email();
    int get_contact_number();
    string get_address();
};

Person::Person()
{
    this->id = "";
    this->name = "";
    this->email = "";
    this->contact_number = 0;
    this->address = "";
}

Person::~Person()
{
}
void Person::set_id(string id)
{
    this->id =id;
}
void Person::set_name(string name)
{
    this->name =name;
}
void Person::set_email(string email)
{
    this->email =email;
}
void Person::set_address(string address)
{
    this->address =address;
}
void Person::set_contact_number(int contact_number)
{
    this->contact_number =contact_number;
}
string Person::get_id()
{
    return this->id;
}
string Person::get_address()
{
    return this->address;
}
string Person::get_email()
{
    return this->email;
}
string Person::get_name()
{
    return this->name;
}
int Person::get_contact_number()
{
    return this->contact_number;
}