#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/*defines constants representing the different states in the DFA*/
enum Statetype {NOT_IN_COMMENT, SLASH, IN_COMMENT, IN_COMMENT_STAR, IN_STRING, ESCAPE_IN_STRING, ESCAPE_IN_CHAR, IN_CHAR};

/*Implement the NOT_IN_COMMENT state of the DFA. c is the current DFA character. 
Unless it c is a / character, write c to stdout. Return to the next state specified by the DFA*/
enum Statetype handleNotInCommentState(int c){
    if(c == '/'){
        return SLASH;
    } else if(c == '"'){
        putchar(c);
        return IN_STRING;
    } else if(c == '\''){
        putchar(c);
        return IN_CHAR;
    } else {
        putchar(c);
        return NOT_IN_COMMENT;
    }
}

/*Implement the SLASH state of the DFA. c is the current DFA character. 
if c is a * character, write a space to stdout. If c is a / character, write the c to stdout. If c is any other character, write / and c to stdout. Return to the next state specified by the DFA*/
enum Statetype handleSlashState(int c){
    if(c == '*'){
        putchar(' ');
        return IN_COMMENT;
    } else if(c == '/'){
        putchar(c);
        return SLASH;
    } else if(c == '"'){
        putchar('/');
        putchar(c);
        return IN_STRING;
    } else if(c == '\''){
        putchar('/');
        putchar(c);
        return IN_CHAR;
    } else {
        putchar('/');
        putchar(c);
        return NOT_IN_COMMENT;
    }
}

/*Implement the IN_COMMENT state of the DFA. c is the current DFA character. 
if c is a \n character, write \n to stdout. If c is any other character, write c to stdout. Return to the next state specified by the DFA*/
enum Statetype handleInCommentState(int c){
    if(c == '*'){
        return IN_COMMENT_STAR;
    } else if(c == '\n'){
        putchar(c);
        return IN_COMMENT;
    } else {
        return IN_COMMENT;
    }
}

/*Implement the IN_COMMENT_STAR state of the DFA. c is the current DFA character. 
if c is a \n character, write \n to stdout. If c is any other character, write c to stdout. Return to the next state specified by the DFA*/
enum Statetype handleInCommentStarState(int c){
    if(c == '/'){
        return NOT_IN_COMMENT;
    } else if(c == '*'){
        return IN_COMMENT_STAR;
    } else if(c == '\n'){
        putchar(c);
        return IN_COMMENT;
    } else {
        return IN_COMMENT;
    }
}

/*Implement the IN_STRING state of the DFA. c is the current DFA character. 
Write c to stdout. Return to the next state specified by the DFA*/
enum Statetype handleInStringState(int c){
    if(c == '"'){
        putchar(c);
        return NOT_IN_COMMENT;
    } else if(c == '\\'){
        putchar(c);
        return ESCAPE_IN_STRING;
    } else {
        putchar(c);
        return IN_STRING;
    }
}

/*Implement the ESCAPE_IN_STRING state of the DFA. c is the current DFA character. 
Write c to stdout. Return to the next state specified by the DFA*/
enum Statetype handleEscapeInStringState(int c){
    putchar(c);
    return IN_STRING;
}

/*Implement the ESCAPE_IN_CHAR state of the DFA. c is the current DFA character. 
Write c to stdout. Return to the next state specified by the DFA*/
enum Statetype handleEscapeInCharState(int c){
    putchar(c);
    return IN_CHAR;
}

/*Implement the IN_CHAR state of the DFA. c is the current DFA character. 
Write c to stdout. Return to the next state specified by the DFA*/
enum Statetype handleInCharState(int c){
    if(c == '\''){
        putchar(c);
        return NOT_IN_COMMENT;
    } else if(c == '\\'){
        putchar(c);
        return ESCAPE_IN_CHAR;
    } else {
        putchar(c);
        return IN_CHAR;
    }
}

/*read text from stdin. filter out all comments, where comments are defined as text enclosed in a star+slash and a slash+a star. 
write the filtered text to stdout. return 0 on success, defined as no errors found, 
1 on failure, defined as an error of an open comment, and return the line of error to stderr*/

int main(void){
    /* c is the current character read from stdin*/
    int c;
    /*LINE_START is the starting line number of the input text*/
    const int LINE_START = 1; 
    /*linenum is the current line number of the input text*/
    int linenum = LINE_START;
    /*errorline is the line number of the most recent error*/
    int errorline = LINE_START;
    /*status is the current exit status of the program. EXIT_SUCCESS indicates no errors, EXIT_FAILURE indicates an error*/
    int status = EXIT_SUCCESS;
    /*use a DFA approach. state is the current DFA state*/
    enum Statetype state = NOT_IN_COMMENT;

    /*read characters from stdin and process them according to the DFA*/
    while((c = getchar()) != EOF){
        switch(state){
            /*process the current character according to the current DFA state and update the state and status accordingly*/
            case NOT_IN_COMMENT:
                state = handleNotInCommentState(c);
                status = EXIT_SUCCESS;
                break;
            case SLASH:
                state = handleSlashState(c);
                status = EXIT_SUCCESS;
                break;
            case IN_COMMENT:
                state = handleInCommentState(c);
                status = EXIT_FAILURE;
                break;
            case IN_COMMENT_STAR:
                state = handleInCommentStarState(c);
                status = EXIT_FAILURE;
                break;
            case IN_STRING:
                state = handleInStringState(c);
                status = EXIT_SUCCESS;
                break;
            case ESCAPE_IN_STRING:
                state = handleEscapeInStringState(c);
                status = EXIT_SUCCESS;
                break;
            case ESCAPE_IN_CHAR:
                state = handleEscapeInCharState(c);
                status = EXIT_SUCCESS;
                break;
            case IN_CHAR:
                state = handleInCharState(c);
                status = EXIT_SUCCESS;
                break;
        }

        /*update the line number. Update the error line number only if program is in an EXIT_SUCCESS state*/
        if(c == '\n'){
            linenum++;
            
            if(status == EXIT_SUCCESS){
                errorline = linenum;
            }
        }
    } 

    /*write any remaining characters to stdout*/
    if(state == SLASH){
        putchar('/');
    }
    
    /*report any errors to stderr and include the line number*/
    if(status == EXIT_FAILURE){
        fprintf(stderr, "Error: line %d: unterminated comment\n", errorline);
    }

    return status;
}