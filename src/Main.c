
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <math.h> 
#include <termios.h> 
// #include <stdbool.h> 
#include "T.c" 

// Causes A Segmentation Fault 🤠. 
/* char* conIts(double Num){ 
    char* String; 
    sprintf(String, "%f", Num); 
    return String; 
} */ 

/* static void Run(){ 
    static int XNum = 0; 
    XNum++; 
    printf("The Function \'Run()\' Was Executed %d Amount Of Times In This Program. \n", XNum);  
} */ 

void enableRawMode(){ 
    struct termios Raw; 

    tcgetattr(STDIN_FILENO, &Raw); 

    Raw.c_lflag &= ~(ECHO); 

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &Raw); 
} 

int main(){ 

    enableRawMode(); 

    char c; 
    system("clear"); 

    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q'){ 
    } 

    return 0; 

} 

