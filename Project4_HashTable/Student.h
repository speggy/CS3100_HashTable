#include <string>

using namespace std;

class Student
{
public:
	string firstName;
	string lastName;
	int uid;
	string year;

	Student()
	{
		// empty constructor    
	}

	/*Paramterized constructor*/
	Student(string fn, string ln, int newuid, string y)
	{
		firstName = fn;
		lastName = ln;
		uid = uid;
		year = y;
	}

	/*Function to print out the record*/
	friend ostream& operator<<(ostream& os, const Student& s)  
	{  
		os << "----------------------------" << endl;
		os << "Last name: " << s.lastName << endl;
	    os << "First name: " << s.firstName << endl;
		os << "UID: " << s.uid << endl;
		os << "Year: " << s.year << endl;
		os << "----------------------------" << endl;

	    return os;  
	} 



};