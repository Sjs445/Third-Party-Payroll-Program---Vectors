#include "person.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

void readData(vector<Person>&employees);
void getCompanies(vector<Person>&employees, vector<Person>& companyNames);
void printHighestPaid(vector<Person>&employees);
void seperateAndSave(vector<Person>&employees, vector<Person>& companyNames);

int main()
{
vector<Person> employees;
vector<Person> companyNames;

readData(employees);
getCompanies(employees, companyNames);
printHighestPaid(employees);
seperateAndSave(employees, companyNames);

  return 0;
}

void readData(vector<Person>&employees)
{
  ifstream inData;
  string firstName, lastName, companyName;
  int id;
  float hoursWorked, payRate;

  inData.open("input.txt");

  while(!inData.eof())
  {
    Person P;
    inData>>firstName;
    cin.clear();
    P.setFirstName(firstName);
    inData>>lastName;
    cin.clear();
    P.setLastName(lastName);
    inData>>id;
    P.setEmployeeId(id);
    inData>>companyName;
    cin.clear();
    P.setCompanyName(companyName);
    inData>>hoursWorked;
    P.setHoursWorked(hoursWorked);
    inData>>payRate;
    P.setPayRate(payRate);

    employees.push_back(P);
  }

  inData.close();
}

void getCompanies(vector<Person>&employees, vector<Person>& companyNames)
{
  string temp;
  for(int i=0; i<employees.size(); i++)
  {
  temp=employees.at(i).getCompanyName();
  Person P;
  P.setCompanyName(temp);
  companyNames.push_back(P);
}
}

void printHighestPaid(vector<Person>&employees)
{
  float highest, currentSalary;
  string name, company;
  int id;

  for(int i=0; i<employees.size(); i++)
  {
    currentSalary=employees.at(i).totalPay();
    if(highest<currentSalary)
    {
      highest=currentSalary;
      name=employees.at(i).fullName();
      company=employees.at(i).getCompanyName();
      id=employees.at(i).getEmployeeId();
    }
  }
  cout<<fixed;
  cout<<setprecision(2);
  cout<<"Highest Paid: "<<name<<endl;
  cout<<"Employee ID: "<<id<<endl;
  cout<<"Employer: "<<company<<endl;
  cout<<"Total Pay: $"<<highest<<endl;
}

void seperateAndSave(vector<Person>&employees, vector<Person>& companyNames)
{
  string current, filename;
  float sum=0;

  ofstream outData;
outData<<fixed;
outData<<setprecision(2);
for(int i=0; i<companyNames.size(); i++)
{
  sum=0;
  current=companyNames.at(i).getCompanyName();
  filename=current+".txt";
  outData.open(filename);
  for(int i=0; i<employees.size()-1; i++)
  {
    if(employees.at(i).getCompanyName()==current)
    {
      sum+=employees.at(i).totalPay();

      outData<<left<<setw(10);
      outData<<employees.at(i).getFirstName();
      outData<<setw(10);
      outData<<employees.at(i).getLastName();
      outData<<setw(5);
      outData<<employees.at(i).getEmployeeId();
      outData<<setw(1);
      outData<<"$"<<employees.at(i).totalPay()<<endl;
    }
  }
  outData<<"Total $"<<sum<<endl;
    outData.close();
}
}
