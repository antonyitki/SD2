/*
######################################################################################################################

YIT19488399, BSc Compuer Science, Year 1, Term 2. Full Time.
Software development 2, Coursework 2. University of Roehampton, London (UK).
Do it before 12 of March 2021. 20% total mark module.

######################################################################################################################
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void convert_upper(char* INPUT_FILE, char* OUTPUT_FILEUPPER) {
    // 1. Open a file with fopen() predefined function from stdio header.
    FILE* inputFile = fopen(INPUT_FILE, "rt");
    if (NULL == inputFile) {
        printf("ERROR: cannot open the file: %s\n", INPUT_FILE);
    }
    // 2. Open another file to write in upper case.
    FILE* outputFile = fopen(OUTPUT_FILEUPPER, "wt");
    if (NULL == inputFile) {
        printf("ERROR: cannot open the file: %s\n", OUTPUT_FILEUPPER);
    }
    // 3. Read the content of the input file, make it UPPERCASE and write result to new text file.
    int c;
    while (EOF != (c = fgetc(inputFile)))
    {
/**********************************************************************************************************************    	
	__asm
	{
		toUpper:
	        mov al, ecx      //; ecx is the pointer, so [ecx] the current char
	        cmp al, 0x0 
	        je done
	        cmp al,'a'
	        jb next_please
	        cmp al,'z'
	        ja next_please
	        sub al,0x20       //; move AL upper case and
            mov [ecx],al      //; write it back to string
	    next_please:
	        inc ecx           //; not al, that's the character. ecx has to
	        jmp toUpper       //; be increased, to point to next char jmp toUpper
	    done:   ret
	}
************************************************************************************************************************/
        fputc(toupper(c), outputFile);
    }
    // 4. Close all file files for save changes.
    fclose(inputFile);
    fclose(outputFile);
}


void convert_lower(char* INPUT_FILE, char* OUTPUT_FILELOWER) {
    FILE* inputFile = fopen(INPUT_FILE, "rt");
    if (NULL == inputFile) {
        printf("ERROR: cannot open the file: %s\n", INPUT_FILE);
    }
    FILE* outputFile = fopen(OUTPUT_FILELOWER, "wt");
    if (NULL == inputFile) {
        printf("ERROR: cannot open the file: %s\n", OUTPUT_FILELOWER);
    }
    //Read the content of the input file, make it lowercase and write result to new text file.
	int c;
    while (EOF != (c = fgetc(inputFile))) {
        fputc(tolower(c), outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
}


int count_words(char* INPUT_FILE) {
    FILE* fp;
    char ch;
    int linecount, wordcount, charcount;
    // Initialize counter variables. Lines and words start with -1 because of compiler.
    linecount = -1; wordcount = -1; charcount = 0;
/**********************************************************************************************************************
    __asm
    {
    	mov eax, 0     //;
    	mov ebx, 0     //;Initiate registers for line, word and characters with precission
    	mov ecx, 0     //;	
	}
************************************************************************************************************************/  
    // Open file in read-only mode
    fp = fopen(INPUT_FILE, "r");
    // If file opened successfully, then write the string to file
    if (fp) {
        //Repeat until End Of File character is reached.
        while ((ch = getc(fp)) != EOF) {
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
    else {
        printf("Failed to open the file\n");
    }
    printf("Lines : %d \n", linecount);
    printf("Words : %d \n", wordcount);
    printf("Characters : %d \n", charcount);
/**********************************************************************************************************************
    __asm
    {
    	push eax, linecount
    	call printf
    	pop eax                 //;inline assembly for print message
    	push eax, wordcount     //;on screen about line, words
    	call printf             //;and characters
    	pop eax
    	push eax, charcount
    	call printf
    	pop eax
	}
************************************************************************************************************************/    
    getchar();
    return(0);
}


int main(int argc, char** argv)
{
    //filenames can change in name in this program
	char inputfilename[20];
	char outputfilename[20];
	char Cmd[10];//cmd is command line
	int count = 0 ;
    strcpy(Cmd,argv[1]);
    if(!strcmp(argv[2],"-i") && !strcmp(argv[4],"-o")){
	    strcpy(inputfilename,argv[3]);
    	strcpy(outputfilename,argv[5]);
	}
	else{
		printf("error1 \n");//if not i or o, error in screen.	
	}
	printf("inputfilename : %s \n", &inputfilename);
	printf("outputfilename : %s \n", &outputfilename);
	printf("Cmd : %s \n", &Cmd);
	if(!strcmp(Cmd,"-u")){
		convert_upper(inputfilename, outputfilename);
	}
	else if(!strcmp(Cmd,"-l")){
		convert_lower(inputfilename, outputfilename);
	}
	else if(!strcmp(Cmd,"-c")){
		count_words(inputfilename);
	}
	else{
		printf("error2 \n");//if not u, l or c, error will be printed on screen.	
	}
return 0;
}

/**********************************************************************************************************************
Any line in this code can be written in inline assembly for optimization and better performance. Here an example of
incrementing counter for line, word and character counter:
__asm{
	push eax     //;put register on the stack
	mov eax, 0
	inc eax     //;by 1
	call printf
	pop eax     //;clean stack
}
These 6 lines can be used 3 times in each counter
***********************************************************************************************************************/




