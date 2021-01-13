#include <iostream> //provides basic input and allows the usage of cin and cout
#include <fstream> //open a file using ofstream and ifstream
#include <string> //allows to set a variable equal to a string

using namespace std;

bool IsLoggedIn() //To check if user is logged in
{
	string username, password, stored_username, stored_password; 

	cout << "Enter Username:"; cin >> username; //Asks the user for their desired username and sets it as the username in the database
	cout << "Enter Password:"; cin >> password; //Asks the user for their desired password and sets it as the password in the database

	ifstream read("database.txt"); //input stream to operate on a file
	(read >> stored_username >> stored_password); //stores the username and password in the text file
	if (stored_username == username && stored_password == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int choice;

	cout << "1: Register\n2: Login\nYour choice: "; cin >> choice; //Gives the user the choice of registering or signing in
	if (choice == 1)
	{
		string username, password;

		cout << "select a username: "; cin >> username;
		cout << "select a password: "; cin >> password;

		ofstream read ("database.txt",ios::app); //Creates a text file
		read << username << ' ' << password << endl;
		cout << "\nRegistration Sucessful\n";
		main();
		read.close();

			main();
	}
	else if (choice == 2)
	{
		bool status = IsLoggedIn(); 

		if (!status)
		{
			cout << "false login!" << endl;
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "Successfully logged in!" << endl;
			system("PAUSE");
			return 1;
		}

	}
}
