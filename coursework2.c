/*
######################################################################################################################

YIT19488399, BSc Year 1, Term 2. Full Time.
Software development 2, Coursework 2. University of Roehampton, London (UK).
Do it before 12 of March 2021. 20% total mark module.

Read.me included separately.

######################################################################################################################
*/


#include <stdio.h>
#include <ctype.h>


#define INPUT_FILE           "input.txt"
#define OUTPUT_FILEUPPER     "uppercase.txt"
#define OUTPUT_FILELOWER     "lowercase.txt"


void convert_upper(){
    // 1. Open a file with fopen() predefined function from stdio header.
    FILE *inputFile = fopen(INPUT_FILE, "rt");
    if (NULL == inputFile) {
        printf("ERROR: cannot open the file: %s\n", INPUT_FILE);
        return -1;
    }
    // 2. Open another file to write in upper case.
    FILE *outputFile = fopen(OUTPUT_FILEUPPER, "wt");
    if (NULL == inputFile) {
        printf("ERROR: cannot open the file: %s\n", OUTPUT_FILEUPPER);
        return -1;
    }
    // 3. Read the content of the input file, make it uppercase and write result to new text file.
    int c;
    while (EOF != (c = fgetc(inputFile))) {
        fputc(toupper(c), outputFile);
    }
    // 6. Close all file files for save changes.
    fclose(inputFile);
    fclose(outputFile);
}





void convert_lower(){
    FILE *inputFile = fopen(INPUT_FILE, "rt");
    if (NULL == inputFile) {
        printf("ERROR: cannot open the file: %s\n", INPUT_FILE);
        return -1;
    }
    FILE *outputFile = fopen(OUTPUT_FILELOWER, "wt");
    if (NULL == inputFile) {
        printf("ERROR: cannot open the file: %s\n", OUTPUT_FILELOWER);
        return -1;
    }
    //Read the content of the input file, make it lowercase and write result to new text file.
    int c;
    while (EOF != (c = fgetc(inputFile))) {
        fputc(tolower(c), outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
}








int count_words()
{
    FILE *fp;
    char filename[100];
    char ch;
    int linecount, wordcount, charcount;

    // Initialize counter variables
    linecount = 0;
    wordcount = 0;
    charcount = 0;

    // Prompt user to enter filename
    printf("Enter a filename :");
    gets(filename);

    // Open file in read-only mode
    fp = fopen(filename,"r");

    // If file opened successfully, then write the string to file
    if ( fp )
    {
        //Repeat until End Of File character is reached.
        while ((ch=getc(fp)) != EOF) {
            // Increment character count if NOT new line or space
            if (ch != ' ' && ch != '\n') { ++charcount; }

            // Increment word count if new line or space character
            if (ch == ' ' || ch == '\n') { ++wordcount; }

            // Increment line count if new line character
            if (ch == '\n') { ++linecount; }



        }

        if (charcount > 0) {
            ++linecount;
            ++wordcount;
        }
    }
    else
    {
        printf("Failed to open the file\n");
    }

    printf("Lines : %d \n", linecount);
    printf("Words : %d \n", wordcount);
    printf("Characters : %d \n", charcount);

    getchar();
    return(0);
}


























int main(int argc, char **argv) {

    convert_upper();
    convert_lower();
    count_words();

    return 0;
}