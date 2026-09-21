#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
enum Statetype {NOT_IN_COMMENT, SLASH, IN_COMMENT, IN_COMMENT_STAR, IN_STRING, ESCAPE_IN_STRING, ESCAPE_IN_CHAR, IN_CHAR};

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

enum Statetype handleEscapeInStringState(int c){
    putchar(c);
    return IN_STRING;
}

enum Statetype handleEscapeInCharState(int c){
    putchar(c);
    return IN_CHAR;
}

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

int main(void){
    int c;
    int LINE_START = 1; 
    int linenum = LINE_START;
    int errorline = LINE_START;
    int status = EXIT_SUCCESS;
    enum Statetype state = NOT_IN_COMMENT;

    while((c = getchar()) != EOF){
        switch(state){
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

        if(c == '\n'){
            linenum++;
            
            if(status == EXIT_SUCCESS){
                errorline = linenum;
            }
        }
    } 

    if(state == SLASH){
        putchar('/');
    }
    
    if(status == EXIT_FAILURE){
        fprintf(stderr, "Error: line %d: unterminated comment\n", errorline);
    }

    return status;
}