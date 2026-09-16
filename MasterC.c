// This => // is used to represent comments comments wont compile when you compile so they dont execute

// program => compiler compiles it into an executable or runnable file => compiled file is executed for output
// Note: you must compile your code when ever you save your file, you must save when ever you change your file

#include <stdio.h>
// we include this header file to our program for printf(), scanf() etc

#include <stdarg.h>
// we include this header file for the augument list va_list va_start etc

#include <unistd.h>
//we include this for STDOUT_FILENO

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
int input(const char *format, ...){ // the format and ...(trail of args) is passed to function so we can use them inside function
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
    // puts is also used same as printf but it is cleaner and faster than printf and also adds \n which is a newline

    char msg3 = 'C';
    putchar(msg3);
    putchar('\n');
    // put char is the efficient way to print only a single character

    FILE *file = fopen("msg.txt", "w");
    // FILE is used to specify a variable of type file and *file represents file is a pointer points towards the file
    // fopen is used to open a file here msg.txt is the file and you can see it in the repo we are goin to write into it , w is the mode which is  write
    
    if(file != NULL){
        fputs("Hello this is a fputs Command \n", file);
        // fputs is used to write the given string variable to file but you must specify which file to write

        fprintf(file, "This is a %s command \n", "fprintf");
        // fprintf also used same as fputs

        // fputc also one of them

        fclose(file);
        // fclose is used to clean our pointer which is pointing towards our file
    }
    // if() is used to check if a condition is true here file != NULL NULL means nothing here the code inside {} which belongs to if executes only if the file given is not nothing

    char username[] = "King";
    char filename[50];
    int userid = 24;
    // we declare variables so that it would be easier for others to update the values without reading and updating every function

    snprintf(filename, sizeof(filename), "MasterC_%s_%d.txt", username, userid);
    // saves the text into the given string 

    printf("%s\n", filename);

    puts("King: ");

    va_list args; // args are pointed here

    va_start(args, format); // this initializes argument list

    vprintf(format, args); // pass the format and arguments to the vprintf for output

    va_end(args); // this cleans the augument list

    puts("");

    char msg4[] = "This is printed using write\n";

    write(STDOUT_FILENO/*u can also use 1*/ , msg4, sizeof(msg4) - 1); // write is used when communication with kernel is necessary

    //Upcoming Is Assembly

    char msg5[] = "This is Using raw assembly!\n";
    
    asm(
        "mov $1, %%rax\n"    // System call number 1 is sys_write
        "mov $1, %%rdi\n"    // File descriptor 1 is stdout
        "mov %0, %%rsi\n"    // Pointer to our message string
        "mov $28, %%rdx\n"   // Length of our string /n is considered as 1 character
        "syscall\n"          // Trigger kernel execution
        :
        : "r"(msg5)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );

    return 0;
    // since your function is an int it returns an 0 value when executed this value doesnt appear generally but appears when assigned the fuction to a variable
}

// Upnext input functions - 17-09-2026 03:46:50

int main(){
    // this main block is where we take our functions to execute

    input("This is a message");
    // since we created a function named print so we represent it as print();

    return 0;
} 