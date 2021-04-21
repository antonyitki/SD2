
/*
Software Development TWO, Coursework THREE, Second term, BSc year ONE.
Student: YIT19488399
20% value and deliver until 23 Aptil 2020.
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

//headers.
#include <iostream>//name_validator,phone_validator,
#include <string>
#include <regex>//phone_validator,
#include <iomanip>//setw(2) << setfill('0')
#include <sstream>
#include <fstream> //working with files

using namespace std;

//function that valiate name. Numbers will be allowed. As well punctuations like ;:@#¬\/_-...
string name_validator() {

	const int size = 80;//name of 80 characters should be ok
	char sentence[size];

	cout << "Please enter your name: \n";
	cin.getline(sentence, size); // make sure limit is not excedded
	sentence[0] = toupper(sentence[0]);// first character, make it capital
	for (int i = 1; i < size; i++)
	{	
		//char 39 is ' in ASCII. Here code to manipulate user input
		if (sentence[i - 1] == ' ' || sentence[i - 1] == '-' || sentence[i - 1] == char(39))
			sentence[i] = toupper(sentence[i]);
		else
			sentence[i] = tolower(sentence[i]);
	}

	cout << sentence << endl;
	return sentence;
}


string dob_validator() {

	std::stringstream ss; //necessary for setw and setfill
	int dd = 0 , mm = 0, yy = 0; //declaration and initialization of variables type int

	//validationg only YEAR
	do {
		cout << "Enter a year of birth (YYYY) :" << endl;
		cin >> yy;
		if (yy >= 1900 && yy <= 9999) //program will accpent any year from 1900 to 9999. For future generations...
		{
			printf("A Year is valid.\n");
			break;
		}
		else
		{
			printf("A Year is not valid. Please try again\n");
		}

	} while (1); //always true, infinite loop

	//validating month only
	do {
		cout << "Enter a month of birth (MM) :" << endl;
		cin >> mm;
		if (mm >= 1 && mm <= 12)
		{
			printf("A Month is valid.\n");
			break;
		}
		else
		{
			printf("A Month is not valid, please try again.\n");
		}
	} while (1);

	// validating day. fabruary and 31 included
	do {
		cout << "Enter a day of birth (DD) :" << endl;
		cin >> dd;
		if  (((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)) ||
			 ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))									  ||
			 ((dd >= 1 && dd <= 28) && (mm == 2))																	  ||
			 ((dd == 29 && mm == 2 && (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)))))
		{
			printf("A Day is valid.\n");
			break;
		}
		else
		{
			printf("A Day is not valid. Please try again\n");
		}
	} while (1);

	// manipulating the format of the output
	ss << setw(4) << setfill('0') << yy << "/" << setw(2) << setfill('0') << mm << '/' << setw(2) << setfill('0') << dd;

	return ss.str();
}


// validating phone number. NO SPACE/S!! Only 11 numbers and starting with zero.
string phone_validator() {
	//regex exprsion do NOT include space. IMPROVE!!
	const regex pattern("^(0)?[0-9]{10}$");
	string s;
	do{		
	    cin.clear(); // cleaning stack for new data input
	    string s;
	    cout<<"Number (without spaces): "<<endl;
	    cin>> s;
	
		if(regex_match(s, pattern))
		{
		  cout << "Valid" << endl;
		  cout << s <<endl;
		  return s;
		}
		else
		{
		  cout<<"Invalid. Start ALWAYS with 0 and 11 digits. "<< endl<<endl;
		}
	// loop until phone number match regex pattern/s	
    }while(!regex_match(s, pattern));
}


// function to validate post code entered by user from keyboard
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
		cin >> s; // only UK style postcode allowed.

		if (regex_match(s, pattern))
		{
			cout << "Valid" << endl;
			cout << s << endl;
			return s;
		}
		else
		{
			cout << "Invalid. Postcodes must follow the correct format." << endl;
			cout << "That is one to two CAPITAL letters, one to two numbers, a space, a number, then two CAPITAL letters " << endl;
		}
	// s(data from user input) and pattern (regex expression) should match for exit infinite loop	
	} while (!regex_match(s, pattern));
}


//__MAIN__
//at the end of the program is better...

int main(int argc, char** argv) {

	//variables declaration to allocate return of previous functions (string).
	//name of these variables similar but not same as function names!
	string name;
	string dob;
	string phone;
	string post_code;
	string input_exit = "";

	while (1) //always true, infinite loop
	{
		cout << "Enter q for exit or Enter for continue \n ";
		getline(cin, input_exit);
		if (input_exit == "q" || input_exit == "Q")
		{
			break; // exit program.
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

			//This data type represents the output file stream and is used to create
			//files and to write information to files. Name of file "output.txt"
			ofstream myfile;
			myfile.open("output.txt", ios::app);

			//Writing this to a file.\n order inputs in a legible way to humans";
			myfile << "Name: " << name << ", ";
			myfile << "DOB: " << dob << ", ";
			myfile << "Phone: " << phone << ", ";
			myfile << "ZIP: " << post_code << ";\n";

			//compiler automatically close files to save data but is
			//very good habit close it with explicit code.
			myfile.close();
		}

		cout << "Enter q for exit or Enter for continue \n ";
		getline(cin, input_exit);
		if (input_exit == "q" || input_exit == "Q")
		{
			break; //finish program
		}
	}

	//if user enter q or Q, here is the next step: print a goodbye message.
	cout << "\n\n\nEND.\nHave a good day!";
	return 0;
}


//PLEASE, SPECIAL ATTENTION TO POST CODE VALIDATOR FOUND ON INTERNET.
//CODE IS NOT LEGIBLE AND VERY CONFUSING. 
//BUT WORKS 100% VERY VERY GOOD. Researching...

/*

#######################################################################################################################
#include <iostream>
#include <string>
using namespace std;

bool isNum(char letter)
{
    bool isNum = false;
        if(letter>= '0' && letter <= '9')
        {
            isNum = true;
        }

        return isNum;
}
bool isLetter(char letter)
{
    bool isLetter = false;

    if(letter>= 'A' && letter <= 'Z')
    {
        isLetter = true;
    }

    return isLetter;
}

bool isValidLastChars(char first, char second, char third)
{
    bool isValid = false;

    if((isNum(first) == true) && (isLetter(second) == true) && (isLetter(third) == true))
    {
        isValid = true;
    }
    if((second == 'C') || (second == 'I') || (second == 'K') || (second == 'M') || (second == 'O') || (second == 'V') || (third == 'C') || (third == 'I') || (third == 'K') || (third == 'M') || (third == 'O') || (third == 'V'))
    {
        isValid = false;
    }

    return isValid;
}

bool thirdPos(char letter)
{
  if((letter == 'A') || (letter == 'B') || (letter == 'C') || (letter == 'D') || (letter == 'E') || (letter == 'F') || (letter == 'G' ) || (letter == 'H') || (letter == 'J') || (letter == 'K') || (letter == 'K') || (letter == 'S') || (letter == 'T') || (letter == 'U') || (letter == 'W'))
  {
      return true;
  }

  return false;
}

bool firstCharValid(char letter)
{
    if((isLetter(letter) == true) && (letter != 'Q') && (letter != 'V') && (letter != 'X'))
    {
        return true;
    }
    return false;
}

bool secondCharValid(char letter)
{
    if((isLetter(letter) == true) && (letter != 'I') && (letter != 'J') && (letter != 'Z'))
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
	
    string postcode;

    while(true)
    {
        cout<<"Postcode Checker. Write a postcode and the program will determine if it is valid."<<endl;
        getline(cin, postcode);
        if(postcode.length() == 8)
        {
            char first = postcode[0];
            char second = postcode[1];
            char third = postcode[2];
            char fourth = postcode[3];
            char space = postcode[4];
            char fifth = postcode[5];
            char sixth = postcode[6];
            char seventh = postcode[7];

            if((firstCharValid(first) == true) && (secondCharValid(second) == true) && (isNum(third) == true) && (isNum(fourth) == true) && (isValidLastChars(fifth, sixth, seventh) == true))
            {
                cout<<"This is a valid postcode"<<endl;
                return false;
            }
            else if((firstCharValid(first) == true) && (secondCharValid(second) == true) && (isNum(third) == true) && (isLetter(fourth) == true) && (isValidLastChars(fifth, sixth, seventh) == true))
            {
                cout<<"This is a valid postcode"<<endl;
                return false;
            }
            else
            {
                cout<<"This is not a valid postcode"<<endl;
            }
        }
        else if(postcode.length() == 7)
        {
            char first = postcode[0];
            char second = postcode[1];
            char third = postcode[2];
            char space = postcode[3];
            char fourth = postcode[4];
            char fifth = postcode[5];
            char sixth = postcode[6];

            if((firstCharValid(first) == true) && (isNum(second) == true) && (isNum(third) == true) && (isValidLastChars(fourth, fifth, sixth) == true))
            {
                cout<<"This is a valid postcode"<<endl;
                return false;
            }
            else if((firstCharValid(first) == true) && (secondCharValid(second) == true) && (isNum(third) == true) && (isValidLastChars(fourth, fifth, sixth) == true))
            {
                cout<<"This is a valid postcode"<<endl;
                return false;
            }
            else if((firstCharValid(first) == true) && (isNum(second) == true) && (thirdPos(third) == true) && (isValidLastChars(fourth, fifth, sixth) == true))
            {
                cout<<"This is a valid postcode"<<endl;
                return false;
            }
            else
            {
                cout<<"This is not a valid postcode"<<endl;
            }
        }
        else if(postcode.length() == 6)
        {
            char first = postcode[0];
            char second = postcode[1];
            char space = postcode[2];
            char third = postcode[3];
            char fourth = postcode[4];
            char fifth = postcode[5];

            if((firstCharValid(first) == true) && (isNum(second) == true) && (isValidLastChars(third, fourth, fifth) == true))
            {
                cout<<"This is an valid postcode"<<endl;
                return false;
            }
            else
            {
                cout<<"This in an invalid postcode"<<endl;
            }
        }
        else
        {
            cout<<"This is an invalid postcode"<<endl;
        }
    }
}

#######################################################################################################################

*/

//Many thanks.
//Softkanton Ltd. 