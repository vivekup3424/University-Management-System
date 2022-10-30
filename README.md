# OOPS-Project

This contains the University Management System Project for my OOPS Course.

Courses header file contains all information of Courses that a student has picked.

Courses is in composition with Student class.
Courses contains:-
1.course_enrolled - a vector of course names
2.course_wise_attandance_percentage - a vector of float

What we can do with our university management system?
We can:-

1. Add new student in the university(add his name,email,and all other data members from Person and
   Student class),
   also we can add information about the courses chosen by him simultaneuosly,
   we should also add Academic Record information of the student
2. Add a new faculty in the university(add data members in Person,Faculties,Department
   in whic the faculty belongs to) and, also input information for the Accounts of the faculty
3. Add a new employee in the university(add data members in Employee,Person),
   and also add information
   
   Explanation:-
We are building a University Management System, in which we have functionalities for:-
1.Add a new student in the university
2.Show the details of all students
3.Show the Academic Record of all students
4.Show the Courses opted by a particular student
5.Add a new faculty in the university
6.Show the details of all faculties in university
7.Show the details of accounts of all faculties
8.Add a new employee in the university
9.Show the details of all employees in university
10.Show the details of accounts of a particular employee


For this we have a :-
1. Person class:-
    • Person class is in Person.h header file.
    • This is a parent class to Student, Faculties and Employees class as every person has the common characteristics and actions of a Person instance.
    • Data Members are:-  
        ◦ - id : string
        ◦ - name: string
        ◦ -emaill:string
        ◦ -contact_number: string
        ◦ -address:string
          All these data members are in private scope.
    • Member functions are the usual setters and getters for these data members in public scope.
    • There is a Generalization from Student,Faculties and Employees to Person class.
2.Department:- 
    • Department class is in Department.h header file.
    • Department class has a dependency to Student and Faculties class, there can’t exist a Department with 0 student or 0 Faculty in it.
    • Department hence is a abstract class in this sense.
    • Data Members are:- 
        ◦ string departmentName;
        ◦ string departmentHOD;
        ◦ string departmentID; //ID of the department
        ◦ int departmentStrength; 
          All data members are in private scope.
3. Academic Record:-
    • AcademicRecord is being inherited by Student class.
    • Every student has a unique Academic Record, no Academic Record can be same of two different students
    • Data Members are:-
        ◦ string programme_name; //Like B.TECH CSE
        ◦ int admission_no;
        ◦ int enroll_no;
        ◦ pair<int,int> session_time_period; //duration of program like (2020-2024)
        ◦ float CGPA;
        ◦ int total_credits;
4. Courses :-
    • Courses contain the information regarding the courses picked by a unique student in the university
5. Student:-
    • Student class is in Student.h header file.
    • The parent class of Student class are Academic Record,Person and Department.
    • Student class has a composition to Courses class, as every student has some select courses opted by him.
    • The Addition Data Member:-
        ◦ Institute_Mail: string
        ◦ A :Course class
6. Accounts
    • Accounts is in Accounts.h header file.
    • Accounts contain all infomation regarding salary,payment method for a employee/faculty of the University.
    • Data Members:-
        ◦ float decidedSalary;
        ◦ string paymentMethod;
        ◦ float deductedSalary;
        ◦ float bonusSalary;
        ◦ float paidSalary;//to be calculated from other data members
        ◦ float totalWorkingHours;
7. Faculties
    • Faculties class is for storing all the characteristics and functionalities regarding various function managing faculties in a university.
    • Faculties has a composition to Accounts, as every has unique account details associated to them.
    • Data Members:-
        ◦ string faculty_type;
        ◦ string faculty_description;
        ◦ Accounts accounts;
    • All data members are in private scope.
8. Employee
    • Employee class is for storing all the characteristics and functionalities regarding various function managing employees in a university.
    • Employee has a composition to Accounts, as every has unique account details associated to them.
    • Data Members:-
        ◦ string employee_job;
        ◦ Accounts accounts;
    • All data members are in private scope.
9. Classroom
    • This class contains information of a unique class in the university
    • Data Members:-
        ◦ int strength; //total num of students
        ◦ vector<string> students_id; //list of ID of students in the class
        ◦ vector<string> faculties_id;//list of ID of faculties in the class
        ◦ int classroom_id; //used as unique identifier for a classroom
          These data members are in private scope.
    • 
10. Display
    • This is the central class for our management system, which contains most of the functionality for University Management System.
    • Data Members:-
        ◦ vector<Student> students;
        ◦ Courses courses; //this data members is extra
        ◦ vector<Faculties> faculties;
        ◦ vector<Employee> employees;
        ◦ vector<Classroom> classrooms;
          Above data members are in private scope.
        ◦ int total_students = 0;
        ◦ int total_faculties = 0;
          These data members are in public scope.
