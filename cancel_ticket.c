#include"header.h"

void cancel_ticket(TRAIN *info, char *username) {
    int tnum, d, m, y;

    print_header("TICKET CANCELLATION", GREEN);
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

                    FILE *fp = fopen("bookings.dat", "r");
                    if(!fp) {
                        print_header("ERROR", RED);
                        printf("│ %-76s │\n", "No bookings found!");
                        print_line('=', BOX_WIDTH);
                        return;
                    }

                    FILE *temp_fp = fopen("temp_bookings.dat", "w");
                    if(!temp_fp) {
                        fclose(fp);
                        print_header("ERROR", RED);
                        printf("│ %-76s │\n", "Error processing cancellation!");
                        print_line('=', BOX_WIDTH);
                        return;
                    }
                     BOOKING b;
                    int cancelled = 0;
                    while(fscanf(fp, "%s %d %s %d %d %d %d %[^\n]",
                               b.username, &b.train_number, b.train_name,
                               &b.day, &b.month, &b.year, &b.seat_number, b.name) != EOF) {
                        if(strcmp(b.username, username) == 0 &&
                           b.train_number == tnum &&
                           b.day == d && b.month == m && b.year == y) {
                            cancelled = 1;
                            if(current->train[i].w_list > 0) {
                                current->train[i].w_list--;
                            } else {
                                current->train[i].total_seats++;
                            }
                        } else {
                            fprintf(temp_fp, "%s %d %s %d %d %d %d %s\n",
                                    b.username, b.train_number, b.train_name,
                                    b.day, b.month, b.year, b.seat_number, b.name);
                        }
                    }

                    fclose(fp);
                    fclose(temp_fp);

                    remove("bookings.dat");
                    rename("temp_bookings.dat", "bookings.dat");

                    if(cancelled) {
                        print_header("CANCELLATION CONFIRMED", GREEN);
                        printf("│ %-76s │\n", "Your ticket has been cancelled");
                        printf("│ %-15s: %-60d │\n", "Available Seats", current->train[i].total_seats);
                        printf("│ %-15s: %-60d │\n", "Wait List", current->train[i].w_list);
                        if(current->train[i].w_list > 0) {
                            printf("│ %-76s │\n", "A passenger from waiting list has been accommodated");
                        }
                        print_line('=', BOX_WIDTH);
                        save_file(info);
                    } else {
                        print_header("ERROR", RED);
                        printf("│ %-76s │\n", "No matching booking found!");
                        print_line('=', BOX_WIDTH);
                    }
                    return;
                }
            }
        }
        current = current->link;
    }

    print_header("ERROR", RED);
    printf("│ %-76s │\n", "Train or date not found!");
    print_line('=', BOX_WIDTH);
}