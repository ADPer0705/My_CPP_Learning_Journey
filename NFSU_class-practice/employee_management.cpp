// This program aims at managing employee information.
// The goal is to practice multilevel inheritence

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class person
{
    private :
        string name;
        int age; 

    public :
        void setName(string name)
        {
            this->name = name;
        }

        void setAge(int age)
        {
            this->age = age;
        }

        string getName()
        {
            return this->name;
        }

        int getAge()
        {
            return this->age;
        }

        void displayPersonalInfo()
        {
            cout << setw(10) << right << "name : " << this->name << endl;
            cout << setw(10) << right << "age : " << this->age << endl;
        }
};

class employee : private person
{
    private :
        int employeeId;
        string position;

    public :
        void setId(int Id)
        {
            this->employeeId = Id;
        }

        void setPosition(string position)
        {
            this->position = position;
        }
        
        int getId()
        {
            return this->employeeId;
        }

        string getPosition()
        {
            return this->position;
        }

        void displayEmployeeInfo()
        {
            cout << setw(10) << right << "emp Id : " << this->employeeId;
            cout << setw(10) << right << "position : " << this->position;
        }
};

class manager : private employee
{
    private :
        int teamSize;

    public :
};