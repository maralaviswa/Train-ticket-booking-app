#include"header.h"

void book_ticket(TRAIN *info, char *username) {
    FILE *fp = fopen("bookings.dat", "r");
    if(!fp) {
        print_header("BOOKING DETAILS", GREEN);
        printf("│ %-76s │\n", "No bookings found!");
        print_line('=', BOX_WIDTH);
        return;
    }

    BOOKING b;
    int found = 0;

    print_header("YOUR BOOKINGS", GREEN);
    while(fscanf(fp, "%s %d %s %d %d %d %d %[^\n]",
                b.username, &b.train_number, b.train_name,
                &b.day, &b.month, &b.year, &b.seat_number, b.name) != EOF) {
        if(strcmp(b.username, username) == 0) {
            found = 1;
            print_booking_details(&b, info);
        }
    }

    if(!found) {
        printf("│ %-76s │\n", "No bookings found for this user!");
        print_line('=', BOX_WIDTH);
    }

    fclose(fp);
}