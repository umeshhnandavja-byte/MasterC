// This => // is used to represent comments comments wont compile when you compile so they dont execute

// program => compiler compiles it into an executable or runnable file => compiled file is executed for output
// Note: you must compile your code when ever you save your file, you must save when ever you change your file

#include <stdio.h>
// we include this header file to our program for printf(), scanf() etc

/* Note: If you dont know how to execute your code here are the steps for linux users
        1. save your file in a .c format
        2. download gcc
        3. now open terminal and type

            gcc filename.c -o filename

            hit enter and your code is compiled
        4. now to run it type
            ./filename 
*/

//Ways to Display output to Terminal
int print(){
    // here we are declaring(creating) a function named print

    char msg1[] = "User"; 
    // char is used to specify a character and an array of chracters is a string and = sign is for assignment == is to tell relation "equal to"
    // in the above command th4e4 User is stored inside msg1 as string we represent characters and strings using ' and ""
    
    printf("Hello %s \n", msg1); 
    // printf() is basically used to give output such as text variables etc to terminal here you need to specify where you need to place the variable soo u use
    // %d for integers %s for strings %c for chracters %f for float etc
    // \n is used for representing a new line \t for tab etc

    char msg2[] = "How are you";
    puts(msg2);
    //puts is also used same as printf but it is cleaner and faster than printf and also adds \n which is a newline

    char msg3 = 'C';
    putchar(msg3);
    putchar('\n');
    //put char is the efficient way to print only a single character

    FILE *file = fopen("msg.txt", "w");
    //FILE is used to specify a variable of type file and *file represents file is a pointer points towards the file
    //fopen is used to open a file here msg.txt is the file and you can see it in the repo we are goin to write into it , w is the mode which is  write
    
    if(file != NULL){
        fputs("Hello this is a fputs Command \n", file);
        //fputs is used to write the given string variable to file but you must specify which file to write

        fprintf(file, "This is a %s command \n", "fprintf");
        //fprintf also used same as fputs

        fclose(file);
        //fclose is used to clean our pointer which is pointing towards our file
    } 
    //if() is used to check if a condition is true here file != NULL NULL means nothing here the code inside {} which belongs to if executes only if the file given is not nothing

    return 0;
    //since your function is an int it returns an 0 value when executed this value doesnt appear generally but appears when assigned the fuction to a variable
}

//Upnext someother print functions - 12-09-2026 01:55:35

int main(){
    //this main block is where we take our functions to execute

    print();
    //since we created a function named print so we represent it as print();

    return 0;
} 