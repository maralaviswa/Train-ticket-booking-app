#include"header.h"

// Print a line of characters (for UI)
void print_line(char c, int length) {
    printf("%s", GREEN);
    for(int i = 0; i < length; i++) putchar(c);
    printf("%s\n", RESET);
}

// Print a header with title and color
void print_header(const char *title, const char *color) {
    printf("\n");
    print_line('=', BOX_WIDTH);
    int spaces = (BOX_WIDTH - strlen(title)) / 2;
    printf("%*s%s%s%*s\n", spaces, "", color, title, spaces, "");
    print_line('=', BOX_WIDTH);
}

// Print train information in a row
void print_train_row(TRAIN *train) {
    printf("│ %-10d │ %-25s │ %-15s │ %-15s │\n",
           train->train_number,
           train->train_name,
           train->source,
           train->dest);
    print_line('-', BOX_WIDTH);
}