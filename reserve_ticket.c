#include"header.h"

void reserve_ticket(TRAIN *info, char *username) {
    int tnum, d, m, y, found = 0;
    char name[50];

    print_header("TICKET RESERVATION", GREEN);
    printf("Enter your name: ");
    scanf(" %[^\n]", name);
    printf("Enter train number: ");
    scanf("%d", &tnum);
    printf("Enter travel date (dd mm yyyy): ");
    scanf("%d %d %d", &d, &m, &y);

    TRAIN *current = info;
    while(current) {
        if(current->train_number == tnum) {
            for(int i = 0; i < 3; i++) {
                if(current->train[i].day == d &&
                   current->train[i].month == m &&
                   current->train[i].year == y) {
                    found = 1;
                    if(current->train[i].total_seats > 0) {
                        int seat_number = MAX_SEATS - current->train[i].total_seats + 1;
                        current->train[i].total_seats--;

                        FILE *fp = fopen("bookings.dat", "a");
                        if(fp) {
                            fprintf(fp, "%s %d %s %d %d %d %d %s\n",
                                   username, tnum, current->train_name, d, m, y, seat_number, name);
                            fclose(fp);

                            print_header("BOOKING CONFIRMED", GREEN);
                            printf("│ %-15s: %-60s │\n", "Train Name", current->train_name);
                            printf("│ %-15s: %02d-%02d-%-58d │\n", "Travel Date", d, m, y);
                            printf("│ %-15s: %-60d │\n", "Seat Number", seat_number);
                            printf("│ %-15s: %-60d │\n", "Available Seats", current->train[i].total_seats);
                            print_line('=', BOX_WIDTH);

                            save_file(info);
                        } else {
                            printf("%sError saving booking!%s\n", RED, RESET);
                        }
                        return;
                    } else {
                        current->train[i].w_list++;
                        print_header("WAITING LIST", GREEN);
                        printf("│ %-76s │\n", "All seats are booked");
                        printf("│ %-15s: %-60d │\n", "Your waitlist position", current->train[i].w_list);
                        print_line('=', BOX_WIDTH);
                        save_file(info);
                        return;
                    }
                }
            }
        }
        current = current->link;
    }

    if(!found) {
        print_header("ERROR", RED);
        printf("│ %-76s │\n", "Train or date not found!");
        print_line('=', BOX_WIDTH);
    }
}