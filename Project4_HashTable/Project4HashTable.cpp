#include "stdafx.h"
#include <iostream>
#include "HashTable.h"
#include "Student.h"

using namespace std;

int main()
{
	// Start the sobriety tests

	HashTable<Student> studentTable = HashTable<Student>();

	while (1)
	{
		string action = "";

		cout << "Would you like to (I)nsert or (D)elete a record, or (S)earch for a record, or (Q)uit?" << endl;
		cout << "Enter Action: ";
		getline(cin, action);


		if (action.compare("I") == 0) // Insert 
		{
			Student s = Student();
			string insert_ln = "";
			string insert_fn = "";
			int insert_uid;
			string insert_y = "";
			int collisions = 0;

			// Get all the student info from the user 
			cout << "Inserting a new record..." << endl;
			cout << "Enter the last name of the student you want to add: ";
			getline(cin, insert_ln);
			s.lastName = insert_ln;

			cout << "Enter the first name of the student you want to add: ";
			getline(cin, insert_fn);
			s.firstName = insert_fn;

			cout << "Enter the UID of the student: ";
			cin >> insert_uid;
			s.uid = insert_uid;

			cout << "Enter the current year of the student: ";
			getline(cin, insert_y);
			s.year = insert_y;
			//cout << "\n";

			bool insertResult = studentTable.insert(studentTable.hash(insert_uid), s, collisions); // Record the result of the insert
			if (insertResult)
			{
				cout << "Record inserted successfully! " << endl;
			}
			else
			{
				cout << "Record could not be inserted. " << endl;
			}

		}
		else if (action.compare("D") == 0) // Delete
		{
			int getUID;
			cout << "Enter the UID of the student you want to delete: ";
			cin >> getUID;

			cout << "Searching for student. . . " << endl;
			bool deleteResult = studentTable.remove(studentTable.hash(getUID)); // record the result of the deletion 

			if (deleteResult)
			{
				cout << "Record deleted. " << endl;
			}
			else
				cout << "Record not found. " << endl;
		}
		else if (action.compare("S") == 0) // Search
		{
			Student s = Student();
			int getUID;
			cout << "Enter the UID of the student you want to find: ";
			cin >> getUID;

			cout << "Searching for student. . . " << endl;

			bool searchResult = studentTable.find(studentTable.hash(getUID), s); // record the result of the search

			if (searchResult)
			{
				cout << "Search Results: " << endl;
				cout << s;
			}
			else
				cout << "Student not found! " << endl;

		}
		else if (action.compare("Q") == 0) // exit if they want to quit
		{
			exit(0);
		}
		else
		{
			cout << "ERROR: Input not recognized!" << endl;
		}
	}
	

	system("pause");
	return 0;
}

