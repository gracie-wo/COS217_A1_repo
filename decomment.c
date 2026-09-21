#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
enum Statetype {NOT_COMMENT, SLASH, SLASH_STAR, SLASH_STAR_STAR, STRING, BACKSLASH_STRING, BACKSLASH_CHAR, CHAR};

enum Statetype handleNotCommentState(int c){
    if(c == '/'){
        return SLASH;
    } else if(c == '"'){
        putchar(c);
        return STRING;
    } else if(c == '\''){
        putchar(c);
        return CHAR;
    } else {
        putchar(c);
        return NOT_COMMENT;
    }
}

enum Statetype handleSlashState(int c){
    if(c == '*'){
        putchar(' ');
        return SLASH_STAR;
    } else if(c == '/'){
        putchar(c);
        return SLASH;
    } else if(c == '"'){
        putchar('/');
        putchar(c);
        return STRING;
    } else if(c == '\''){
        putchar('/');
        putchar(c);
        return CHAR;
    } else {
        putchar('/');
        putchar(c);
        return NOT_COMMENT;
    }
}

enum Statetype handleSlashStarState(int c){
    if(c == '*'){
        return SLASH_STAR_STAR;
    } else if(c == '\n'){
        putchar(c);
        return SLASH_STAR;
    } else {
        return SLASH_STAR;
    }
}

enum Statetype handleSlashStarStarState(int c){
    if(c == '/'){
        return NOT_COMMENT;
    } else if(c == '*'){
        return SLASH_STAR_STAR;
    } else {
        return SLASH_STAR;
    }
}

enum Statetype handleStringState(int c){
    if(c == '"'){
        putchar(c);
        return NOT_COMMENT;
    } else if(c == '\\'){
        putchar(c);
        return BACKSLASH_STRING;
    } else {
        putchar(c);
        return STRING;
    }
}

enum Statetype handleBackslashStringState(int c){
    putchar(c);
    return STRING;
}

enum Statetype handleBackslashCharState(int c){
    putchar(c);
    return CHAR;
}

enum Statetype handleCharState(int c){
    if(c == '\''){
        putchar(c);
        return NOT_COMMENT;
    } else if(c == '\\'){
        putchar(c);
        return BACKSLASH_CHAR;
    } else {
        putchar(c);
        return CHAR;
    }
}

int main(void){
    int c;
    int LINE_START = 1; 
    int linenum = LINE_START;
    int status = EXIT_SUCCESS;
    enum Statetype state = NOT_COMMENT;

    while((c = getchar()) != EOF){
        switch(state){
            case NOT_COMMENT:
                state = handleNotCommentState(c);
                status = EXIT_SUCCESS;
                break;
            case SLASH:
                state = handleSlashState(c);
                status = EXIT_SUCCESS;
                break;
            case SLASH_STAR:
                state = handleSlashStarState(c);
                status = EXIT_FAILURE;
                break;
            case SLASH_STAR_STAR:
                state = handleSlashStarStarState(c);
                status = EXIT_FAILURE;
                break;
            case STRING:
                state = handleStringState(c);
                status = EXIT_SUCCESS;
                break;
            case BACKSLASH_STRING:
                state = handleBackslashStringState(c);
                status = EXIT_SUCCESS;
                break;
            case BACKSLASH_CHAR:
                state = handleBackslashCharState(c);
                status = EXIT_SUCCESS;
                break;
            case CHAR:
                state = handleCharState(c);
                status = EXIT_SUCCESS;
                break;
        }

        if(c == '\n' && status != EXIT_FAILURE){
            linenum++;
        }
    } 
    
    if(status == EXIT_FAILURE){
        fprintf(stderr, "Error: lines %d: unterminated comment", linenum);
    }

    return status;
}