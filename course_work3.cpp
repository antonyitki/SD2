/*

Software Development TWO, Coursework THREE, Second term, BSc year ONE.
Student: YIT19488399
20% value and deliver until Friday, 23 Aptil 2020.
University of Roehampton, London

###################################################################################################

Specifications of program (INPUT VALIDATION):
1. Capitalize all names with possiblity of many words as name and - or ' accepted in names.
2. Date of birth in a format: YYYY/MM/DD. Zero should be introduced if is number with only one significant character.
   Attention to months whit 30, 28 and 29 days.
3. Phone number:
   eleven digits only
   can have one space or not
   starts always with 0
4. Postcode correct format: 1 or 2 upper letter/s, 1 or 2 number/s, space, number and 2 upper letters.

"output.txt" should be generated whit correct data, previously
manipulated/cleaned from user input using this program/software.

The name of the program/software is "VALIDATE".

*/


#include <iostream>//name_validator,phone_validator
#include <string>
#include <regex>//phone_validator,
#include <iomanip>//setw(2) << setfill('0')
#include <sstream>
#include <fstream> //working with file.

using namespace std; //necessary for endl;


string name_validator() {

	const int size = 80;
	char sentence[size];
	cout << "Please enter your name: \n";
	cin.getline(sentence, size); // make sure limit is not excedded
	sentence[0] = toupper(sentence[0]); //making first letter capital
	for (int i = 1; i < size; i++)
	{
		if (sentence[i - 1] == ' ' || sentence[i - 1] == '-' || sentence[i - 1] == char(39))
			sentence[i] = toupper(sentence[i]);
		else
			sentence[i] = tolower(sentence[i]);
	}
	cout << sentence << endl;
	return sentence;
}


string dob_validator() {

	std::stringstream ss;
	int dd, mm, yy;
	cout << "Enter day of birth (YYYY MM DD) :" << endl;
	cin >> yy >> mm >> dd;
		
	if (yy >= 1900 && yy <= 9999) //check year
	{
		if (mm >= 1 && mm <= 12) //check month
		{
			//check days
			if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
				printf("Date is valid.\n");
			else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
				printf("Date is valid.\n");
			else if ((dd >= 1 && dd <= 28) && (mm == 2))
				printf("Date is valid.\n");
			else if (dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))
				printf("Date is valid.\n");
			else
				printf("Day is invalid.\n");
		}
		else
		{
			printf("Month is not valid.\n");
		}
	}
	else
	{
		printf("Year is not valid.\n");
	}
	ss << setw(4) << setfill('0') << yy << "/" << setw(2) << setfill('0') << mm << '/' << setw(2) << setfill('0') << dd;

	return ss.str();
}


string phone_validator(){
	const regex pattern("^(0)?[0-9]{10}$"); //regex exprsion do NOT include space. IMPROVE!!
	string s;
	do{		
	    cin.clear();
	    string s;
	    cout<<"Number (without spaces): "<< endl;
	    cin>> s;
	
		if(regex_match(s, pattern))
		{
		  cout << "Valid" << endl;
		  cout << s <<endl;
		  return s;
		}
		else
		{
		  cout<<"Invalid. Start ALWAYS with 0, 11 digits and no space/s. "<< endl<<endl;
		}
    }while(!regex_match(s, pattern));
}


string postcode_validotor() {
	//regex exprsion do NOT include space. IMPROVE!!
	//const regex pattern("/^[a-zA-Z]{1,2}([0-9]{1,2}|[0-9][a-zA-Z])\s*[0-9][a-zA-Z]{2}$ /");
	const regex pattern("^[A-Z]{1,2}[0-9]{1,2}\s*[0-9][A-Z]{2}$");
	//const regex pattern("^[a-zA-Z]{1,2}([0-9]{1,2}|[0-9][a-zA-Z])\s*[0-9][a-zA-Z]{2}$");
	//const regex pattern("/^[a-zA-Z]{1,2}([0-9]{1,2}|[0-9][a-zA-Z])\s*[0-9][a-zA-Z]{2}$/");
	
	string s;
	do {
		cin.clear();
		string s;
		cout << "ZIP code: " << endl;
		cin >> s;

		if (regex_match(s, pattern))
		{
			cout << "Valid" << endl;
			cout << s << endl;
			return s;
		}
		else
		{
			cout << "\nInvalid. Postcodes must follow the correct format for a postcode." << endl;
			cout << "That is one to two uppercase letters, one to two numbers, a space, a number, then two uppercase letters " << endl;
		}
	} while (!regex_match(s, pattern));
}


// Start of the program!!!!
int main(int argc, char** argv) {

	string name;
	string dob;
	string phone;
	string post_code;
	string input_exit = "";

	while (1)
	{
		cout << "Enter q for exit or Enter for continue \n ";
		getline(cin, input_exit);
		if (input_exit == "q" || input_exit == "Q")
		{
			break;
		}
		else
		{
			cout << "working on name: " << endl;
			name = (string)name_validator();

			cout << "working on DOB nummber: " << endl;
			dob = dob_validator();
			cout << dob << endl;

			cout << "working on phone number: " << endl;
			phone = phone_validator();
			cout << phone << endl;

			cout << "working on post code: " << endl;
			post_code = postcode_validotor();
			cout << post_code << endl;

			ofstream myfile;
			myfile.open("output.txt", ios::app);

			//myfile << "Writing this to a file.\n";
			myfile << "Name: " << name << ", ";
			myfile << "DOB: " << dob << ", ";
			myfile << "Phone: " << phone << ", ";
			myfile << "ZIP: " << post_code << ";\n";
			//last \n jumps to new line on the file

			myfile.close(); //saving validated data to file each time...
		}
		cout << "Enter q for exit or Enter for continue \n ";
		getline(cin, input_exit);
		if (input_exit == "q" || input_exit == "Q")
		{
			break; //exit if statement
		}
	}
	cout << "\n\n\nEND.\nHave a good day!";
	return 0;
}
