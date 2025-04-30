#include"header.h"

int check_password(char *str) {
    int lower=0, upper=0, digit=0, special=0;
    while(*str) {
        if(islower(*str)) lower=1;
        else if(isupper(*str)) upper=1;
        else if(isdigit(*str)) digit=1;
        else if(!isalpha(*str)) special=1;
        str++;
    }
    return (lower && upper && digit && special);
}

// Get dynamic string input
char *get_string() {
    char *name = NULL;
    int cnt = 0;
    do {
        name = realloc(name, (cnt+1)*sizeof(char));
        name[cnt] = getchar();
    } while(name[cnt++] != '\n');
    name[cnt-1] = '\0';
    return name;
}