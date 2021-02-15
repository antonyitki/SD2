/*
######################################################################################################################

YIT19488399, Undergraduate Year 1, Term 2. Full Time.
Software development 2, Coursework 1. University of Roehampton, London (UK).
Do it before 19 of February 2021. 20% total mark module.
######################################################################################################################
*/


//Headers necessary for basic code functions like printf, switch or if else statements.
#include <stdlib.h> //.h meand Header.
#include <stdio.h>
#include<time.h> //Only necessary in random number generation without repetition ("srand(...)").


// This function displays the main user menu with good presentation. No return required on this function ("void").
//It will run forever until 0 is selected from user.
void display_menu(){
    printf("\n\nMain Menu\n"); //This is the first line printed in each loop. \n\n make it nice in screen.
    printf("=========\n");
    printf("1. Guessing game\n");
    printf("2. Temperature conversion\n");
    printf("3. Find smallest\n");
    printf("4. Find largest\n");
    printf("5. Number to English\n");
    printf("0. Exit\n");
}


// This function gets the user's choice. Returns - the number chosen by the user (int = integer (whole number)).
int get_choice(){
    int buffer; //from original char to int because user will enter number between 0 to 5. [2] not necessary...
    do { //starting validating user input.
        printf("Enter choice (one number only and press Enter): ");//repeats everytime until right integer entered.
        scanf("%d",&buffer); //& because locating to memory. 2s = d because is integer  datatype. And % because specifier.
    } while (buffer > 5 || buffer < 0);//ending validating user input, between 0 to 5 inclusives.
    return buffer; //not necessary convert or specify type of variable.
}
//The only problem here if user enter a character or string. Code get unlimited loop.


// This function runs the guess the number game.
void guess_the_number(){ //datatype of all function "guess_the_number" is void.
    // Generate a random number.
    srand ( time(NULL) ); //this line helps generate new number each time. It initialize random seed.
    int number = rand(); // Predefined function in C. Generate and return an integer from 0 to RAND_MAX.
    /* For apply limits to rand(), "int number = rand() % 155;". This will give an integer
     between 0 to 155. Unlimited guesses will be provided in future code with indicative help to user.*/
    int guess = -1; //Any number that is not the selected in the guess function.
    // Ask the student to guess the number
    while (guess != number){ //Loop asking user for # until target the # with indicative help on screen.
        printf("Guess the number: ");
        scanf("%d", &guess);
        if (guess < number){
            printf("Too low!\n");}
        else if (guess > number){
            printf("Too high!\n");}
    }
    printf("Well done!\n");//Exit the program because user target the #.
}//Return not necessary because declaration is void at the start (datatype of all function "guess_the_number").


void fahrenheit_to_celsius(){ //Function to convert fahrenheit to celsius from user input.
    float  fahrenheit, celsius;
    printf("Temperature in F: \n");
    scanf("%f", &fahrenheit); //Decimal values accepted. Float.
    celsius = (5.0/9.0)*(fahrenheit - 32); //Scientific formula for conversion.
    printf("%.2f°F is same as %.2f°C", fahrenheit, celsius); //Limiting to 2 decimals on screen printed.
} //Return is just a print statement. Not necessary and this is why void datatype all this function declared.

void celsius_to_fahrenheit(){ //Function to convert celsius to fahrenheit from user input.
    float  farenheit, celsius;
    printf("Enter temperature in Celsius: \n");
    scanf("%f", &celsius); //Decimal values accepted. Float.
    farenheit = (celsius * 9 / 5) + 32; //Scientific formula for conversion.
    printf("%.2f Celsius = %.2f Fahrenheit", celsius, farenheit); //Limiting to 2 decimals on screen printed.
} //Return is just a print statement. Not necessary and this is why void datatype all this function declared.

// Function to run the temperature conversion system. This function uses both previous functions together.
void temperature_conversion(){ //Nice presentation menu on screen displayed.
    printf("Conversion Menu\n");
    printf("===============\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
    int choice = get_choice(); //Calling function for user input. 0, 1 and 2 is inside 0 to 5. Reusing code.
    do { //starting validating user input. Repetition validating input (double validation).
        printf("Enter 0, 1 or 2 and press Enter: ");//repeats everytime until right integer entered.
        scanf("%d",&choice); //& because locating to memory. 2s = d because is integer  datatype. And % because specifier.
    } while (choice > 2 || choice < 0); //condition until right number entered by user.
    if (choice == 1) {
        fahrenheit_to_celsius();
    }
    else if (choice == 2){
        celsius_to_fahrenheit();
    }
    else if (choice == 0){
        printf("OK");
    }
} //Return not necessary, just a print statement. Void datatype declaration at the beginning of this function.


// Function to ask the user for 10 numbers and printing the smallest entered.
void find_smallest(){ //datatype declaration void because no return at the end necessary.
    int numbers[10]; //Array declaration of 10 integers.
    for (int i = 0; i < 10; ++i){ //Remember that loops start from 0. Not 1.
        printf("Enter a number: ");
        scanf("%d", &numbers[i]);
    }
    int smallest = numbers[0]; //Initialization of smallest # to the first # entered by user.
    for (int i = 1; i <= 10; ++i){ //loop to check all 10 numbers.
        if (numbers[i] < numbers[0]) //Compare all 10 numbers in the loop. Keeping smallest in "numbers[i]".
        {smallest = numbers[i];} //Exit from the loop with the smallest #.
    }
    printf("The smallest number is: %d\n", smallest);
}

// Function to ask the user for 10 numbers and printing the largest entered.
void find_largest(){ //datatype declaration void because no return at the end necessary.
    int numbers[10]; //Array declaration of 10 integers (whole numbers).
    for (int i = 0; i < 10; ++i){ //Remember that loops start from 0.
        printf("Enter a number: ");
        scanf("%d", &numbers[i]);
    }
    int largest = numbers[0];
    for (int i = 1; i <= 10; ++i){
        if (numbers[i] > numbers[0]){
            largest = numbers[i];}
    }
    printf("The largest number is: %d\n", largest); //same code like smallest function, but opposite...
}


// Function to ask the user for a number and then printing it out in English.
// For example, 105 = One hundred and five.
// 1456 = One thousand, four hundred, and fifty six.
void number_to_english(){
    long num, div, n1;
    int flag, digit, pos, tot_dig;
    printf("\nEnter a number POSITIVE, WHOLE between 0 to 100K: \nNo Floats!\n");
    scanf("%ld", &num); //ld is for long integers values.
    if(num == 0) {
        printf("Zero\n");
    }
    if(num > 99999) { //Limit user input from 0 to 100K only. If big number entered (>100K), finish program!
        printf("please enter a number between 0 and 100000\n\n");
        exit(0);
    }
    tot_dig = 0;
    div = 1;
    n1 = num;
    while ( n1 > 9 ) {
        n1 = n1 / 10;
        div = div * 10;
        tot_dig++;
    }
    tot_dig++;
    pos = tot_dig;
    while ( num != 0 ) {
        digit = num / div;
        num = num % div;
        div = div / 10;
        switch(pos) {
            case 2:
            case 5:
                if ( digit == 1 )
                    flag = 1;
                else {
                    flag = 0;
                    switch(digit) {
                        case 2: printf("twenty ");break;
                        case 3: printf("thirty ");break;
                        case 4: printf("forty ");break;
                        case 5: printf("fifty ");break;
                        case 6: printf("sixty ");break;
                        case 7: printf("seventy ");break;
                        case 8: printf("eighty ");break;
                        case 9: printf("ninty ");
                    }
                }
                break;
            case 1:
            case 4:
                if (flag == 1) {
                    flag = 0;
                    switch(digit) {
                        case 0 : printf("ten ");break;
                        case 1 : printf("eleven ");break;
                        case 2 : printf("twelve ");break;
                        case 3 : printf("thirteen ");break;
                        case 4 : printf("fourteen ");break;
                        case 5 : printf("fifteen ");break;
                        case 6 : printf("sixteen ");break;
                        case 7 : printf("seventeen ");break;
                        case 8 : printf("eighteen ");break;
                        case 9 : printf("nineteen ");
                    }
                } else {
                    switch(digit) {
                        case 1 : printf("one ");break;
                        case 2 : printf("two ");break;
                        case 3 : printf("three ");break;
                        case 4 : printf("four ");break;
                        case 5 : printf("five ");break;
                        case 6 : printf("six ");break;
                        case 7 : printf("seven ");break;
                        case 8 : printf("eight ");break;
                        case 9 : printf("nine ");
                    }
                }
                if (pos == 4)
                    printf("thousand ");
                break;
            case 3:
                if (digit > 0) {
                    switch(digit) {
                        case 1 : printf("one ");break;
                        case 2 : printf("two ");break;
                        case 3 : printf("three ");break;
                        case 4 : printf("four ");break;
                        case 5 : printf("five ");break;
                        case 6 : printf("six ");break;
                        case 7 : printf("seven ");break;
                        case 8 : printf("eight ");break;
                        case 9 : printf("nine ");
                    }
                    printf("hundred ");
                }
                break;
        }
        pos--;
    }
    if (pos == 4 && flag == 0)
        printf("thousand");
    else if (pos == 4 && flag == 1)
        printf("ten thousand");
    if (pos == 1 && flag == 1)
        printf("ten ");}
/*Really long and confusing function to implement in C. Void datatype of the function declared at the start
and no return required or necessary. Just a complicated print statement to see a number on screen.
If user enter a big number (>100k), all the program will exit and finish execution of main as well. Before,
will be printed warning on screen. With 0 input, program will work OK, because program will loop and
ask user for choice with "ZERO" printed on screen. Whit negative numbers, print will NOT be displayed and
program can loop again or just finish with the warning to user.
Floats are accepted for input, but program can loop forever,finish and warning user on screen.
This is why a good print statement is done for specify user input are OK*/


// Function to execute the given choice from the menu.
void run_menu(int choice){ //Function takes one parameter (choice). No return value at the end.
    scanf("%d", &choice);
    switch (choice) //Depends on choice, this function will call previous functions declared here before..
    {
        case 1:
            guess_the_number(); break;
        case 2:
            temperature_conversion(); break;
        case 3:
            find_smallest(); break;
        case 4:
            find_largest(); break;
        case 5:
            number_to_english(); break;
        case 0:
            printf("Goodbye!\n"); exit(0); break; //The most important line! It exit
            //from all the program if 0 is entered by user.
        default: //this case is covering every possibility except: 1,2,3,4,5 or 0.
            printf("Error. Enter a number between 0 and 5.");
            break;
    }// each break; is necessary for stop executing code in this function.
}

// Main application
int main(int argc, char **argv) {
    int choice = -1;
    while (choice != 0) {
        display_menu();
        get_choice();
        run_menu(choice);
    } //return not necessary even if function declaration datatype in int.
}


/*
Be carefully when user input from keyboard!!!!!!!!!!!!!!!!!!!   (;-])   !!
 */