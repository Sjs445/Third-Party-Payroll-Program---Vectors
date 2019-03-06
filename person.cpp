#include "person.h"

Person::Person(){}

string Person::getFirstName()
{ return firstName; }

string Person::getLastName()
{ return lastName; }

string Person::getCompanyName()
{ return companyName; }

int Person::getEmployeeId()
{ return employeeID; }

float Person::getPayRate()
{ return payRate; }

float Person::getHoursWorked()
{ return hoursWorked; }

void Person::setFirstName(string fName)
{
  firstName=fName;
}

void Person::setLastName(string lName)
{
  lastName=lName;
}

void Person::setPayRate(float rate)
{
  payRate=rate;
}

void Person::setEmployeeId(int id)
{
  employeeID=id;
}

void Person::setCompanyName(string coName)
{
  companyName=coName;
}

void Person::setHoursWorked(float hours)
{
  hoursWorked=hours;
}

float Person::totalPay()
{
  float total=hoursWorked*payRate;
  return total;
}

string Person::fullName()
{
  string full=firstName+" "+lastName;
  return full;
}
