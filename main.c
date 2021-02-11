/*
######################################################################################################################
YIT19488399, Undergraduate Year 1, Term 2.
Software development, Coursework 1
do it before 19 of February 2021.
######################################################################################################################
*/


#include <stdlib.h>
#include <stdio.h>

// This function displays the main user menu.
void display_menu()
{
    printf("Main Menu\n");
    printf("=========\n");
    printf("1. Guessing game\n");
    printf("2. Temperature conversion\n");
    printf("3. Find smallest\n");
    printf("4. Find largest\n");
    printf("5. Number to English\n");
    printf("0. Exit\n");
}

// This function gets the user's choice from the main menu.
// Returns - the number chosen by the user.
int get_choice()
{
    int buffer; //from original char to int because user will enter number between 0 to 5. [2] not necessary...
    printf("Enter choice (one number only and press Enter): ");
    scanf("%d", &buffer); // & added because locating to memory. And 2s = d because is integer type
    return buffer; //not necessary convert or specify type of variable.
}

// This function runs the guess the number game.
void guess_the_number()
{
    // Generate a random number
    int number = rand(); // Memory need to be clean for no repetition if rerun code.
    int guess = -1; //Any number that is not the selected in the guess function.
    // Ask the student to guess the number
    while (guess != number)
    {
        printf("Guess the number: ");
        scanf("%d", &guess);
        if (guess < number)
        {
            printf("Too low!\n");
        }
        else if (guess > number)
        {
            printf("Too high!\n");
        }
    }
    printf("Well done!\n");//Exit the program.
}//Return not necessary because declaration is void at the start.
// Function to convert fahrenheit to celsius from user input.


void fahrenheit_to_celsius()
{
    float  farenheit, celsius;
    printf("Temperature in F: \n");
    scanf("%f", &farenheit);
    celsius = (5.0/9.0)*(farenheit-32);
    printf("%.2f°F is same as %.2f°C", farenheit, celsius);
}

// Function to convert celsius to fahrenheit from user input.
void celsius_to_fahrenheit()
{
    float  farenheit, celsius;
    printf("Enter temperature in Celsius: \n");
    scanf("%f", &celsius);
    farenheit = (celsius * 9 / 5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit", celsius, farenheit);
}

// Function to run the temperature conversion system.
void temperature_conversion()
{
    printf("Conversion Menu\n");
    printf("===============\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("0. Exit\n");
    printf("Enter choice: ");
    int choice = get_choice();

    if (choice == 1)
    {fahrenheit_to_celsius();}
    else if (choice == 2)
    {celsius_to_fahrenheit();}
    else if (choice == 0)
    {printf("OK");}
}

// Function to ask the user for 10 numbers and printing the smallest entered.
void find_smallest()
{
    int numbers[10];
    for (int i = 0; i < 10; ++i) //Remember that loops start from 0.
    {
        printf("Enter a number: ");
        scanf("%d", &numbers[i]);
    }
    int smallest = numbers[0];
    for (int i = 1; i <= 10; ++i)
    {
        if (numbers[i] < numbers[0])
        {smallest = numbers[i];}
    }
    printf("The smallest number is: %d\n", smallest);
}

// Function to ask the user for 10 numbers and printing the largest entered.
void find_largest()
{
    int numbers[10];
    for (int i = 0; i < 10; ++i) //Remember that loops start from 0.
    {
        printf("Enter a number: ");
        scanf("%d", &numbers[i]);
    }
    int largest = numbers[0];
    for (int i = 1; i <= 10; ++i)
    {
        if (numbers[i] > numbers[0])
        {
            largest = numbers[i];
        }
    }
    printf("The largest number is: %d\n", largest);
}

// Function to ask the user for a number and then printing it out in English.
// For example, 105 = One hundred and five.
// 1456 = One thousand, four hundred, and fifty six.
void number_to_english()
{
    long num, div, n1;
    int flag, digit, pos, tot_dig;

    printf("\nEnter a number: ");
    scanf("%ld", &num);

    if(num == 0) {
        printf("Zeron\n");
        exit(0);
    }

    if(num > 99999) {
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

// Function to execute the given choice from the menu.
int run_menu(int choice)
{
    scanf("%d", &choice);
    switch (choice)
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
        default:
            printf("Error. Enter a number between 0 and 5.");
            break;
    }
}

// Main application
int main(int argc, char **argv) {
    int choice = -1;
    while (choice != 0) {
        display_menu();
        get_choice();
        run_menu(choice);
    }
}