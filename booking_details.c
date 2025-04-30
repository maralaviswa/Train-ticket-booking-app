#include"header.h"

void print_booking_details(BOOKING *b, TRAIN *info) {
    print_line('-', BOX_WIDTH);
    printf("│ %-15s: %-60s │\n", "Passenger Name", b->name);
    printf("│ %-15s: %-60d │\n", "Train Number", b->train_number);

    // Find train name
    TRAIN *current = info;
    char train_name[50] = "Unknown";
    while(current) {
        if(current->train_number == b->train_number) {
            strcpy(train_name, current->train_name);
            break;
        }
        current = current->link;
    }

    printf("│ %-15s: %-60s │\n", "Train Name", train_name);
    printf("│ %-15s: %02d-%02d-%-58d │\n", "Travel Date", b->day, b->month, b->year);
    printf("│ %-15s: %-60d │\n", "Seat Number", b->seat_number);
    print_line('-', BOX_WIDTH);
}