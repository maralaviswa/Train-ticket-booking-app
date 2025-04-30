#include"header.h"

TRAIN* add_trains(TRAIN *info) {
    int day, month, year;
    printf("Enter the day, month and year for seat information: ");
    scanf("%d %d %d", &day, &month, &year);

    srand(time(NULL));
    TRAIN *nu = calloc(1, sizeof(TRAIN));
    if (!nu) {
        printf("%sMemory allocation failed!%s\n", RED, RESET);
        return info;
    }

    SEAT *nu1 = calloc(3, sizeof(SEAT));
    if (!nu1) {
        printf("%sMemory allocation failed!%s\n", RED, RESET);
        free(nu);
        return info;
    }

    nu->train_number = rand() % 10000 + 99999;
    nu->train = nu1;

    printf("Enter the train name: ");
     while(getchar() != '\n'); // Clear buffer
    nu->train_name = get_string();

    printf("Enter the source location: ");
    nu->source = get_string();

    printf("Enter the destination location: ");
    nu->dest = get_string();

    for(int i = 0; i < 3; i++) {
        nu1[i].day = day++;
        nu1[i].month = month;
        nu1[i].year = year;
        nu1[i].total_seats = MAX_SEATS;
        nu1[i].w_list = 0;
        nu1[i].c_b_status = 0;
        nu1[i].array_seat_status = 0;
    }

    if(info == NULL) {
        info = nu;
    } else {
        nu->link = info;
        info = nu;
    }

    save_file(info);
    print_header("TRAIN ADDED SUCCESSFULLY", GREEN);
    print_train_info(info);
    return info;
}

void print_train_info(TRAIN *info) {
    TRAIN *temp = info;

    print_header("AVAILABLE TRAINS", GREEN);
    printf("│ %-10s │ %-25s │ %-15s │ %-15s │\n",
           "Train No.", "Train Name", "Source", "Destination");
    print_line('-', BOX_WIDTH);

    if(info == NULL) {
        printf("│ %-76s │\n", "No trains are available");
        print_line('-', BOX_WIDTH);
        return;
    }

    while(info) {
        print_train_row(info);
        info = info->link;
    }

    print_header("SEATS INFORMATION", GREEN);
    info = temp;
    while(info) {
        printf("│ %-15s: %-60d │\n","Train Number", info->train_number);
        printf("│ %-15s: %-60s │\n", "Train Name", info->train_name);
        print_line('-', BOX_WIDTH);

        for(int i=0; i<3; i++) {
            printf("│ %-10s: %02d-%02d-%-62d │\n", "Date",
                   info->train[i].day, info->train[i].month, info->train[i].year);
            printf("│ %-10s: %-65d │\n","Total Seats", MAX_SEATS);
            printf("│ %-10s: %-65d │\n", "Available Seats", info->train[i].total_seats);
            printf("│ %-10s: %-65d │\n", "Wait List", info->train[i].w_list);
            print_line('-', BOX_WIDTH);
        }
        info = info->link;
    }
}