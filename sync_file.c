#include"header.h"
TRAIN *syn_file(TRAIN *info) {
    FILE *fp = fopen("trains.dat", "r");
    if(fp == NULL) return info;

    TRAIN *nu = NULL;
    char line[256];

    while(fgets(line, sizeof(line), fp)) {
        nu = calloc(1, sizeof(TRAIN));
        if(!nu) {
            printf("%sMemory allocation failed!%s\n", RED, RESET);
            fclose(fp);
            return info;
        }

        nu->train_name = malloc(50);
        nu->source = malloc(50);
        nu->dest = malloc(50);

        if(sscanf(line, "%d %s %s %s",
                 &nu->train_number,
                 nu->train_name,
                 nu->source,
                 nu->dest) != 4) {
            free(nu->train_name);
            free(nu->source);
            free(nu->dest);
            free(nu);
            continue;
        }

        if(info == NULL) {
            info = nu;
        } else {
            nu->link = info;
            info = nu;
        }
    }

    fclose(fp);
    return info;
}

// Load seat data from file
void syn_file1(TRAIN *info) {
    FILE *fp = fopen("seats.dat", "r");
    if(fp == NULL) return;

    TRAIN *current = info;
    while(current) {
        current->train = calloc(3, sizeof(SEAT));
        if(!current->train) {
            printf("%sMemory allocation failed!%s\n", RED, RESET);
            fclose(fp);
            return;
        }

        for(int i = 0; i < 3; i++) {
            if(fscanf(fp, "%d %d %d %d %d %d %d",
                     &current->train[i].day,
                     &current->train[i].month,
                     &current->train[i].year,
                     &current->train[i].total_seats,
                     &current->train[i].w_list,
                     &current->train[i].c_b_status,
                     &current->train[i].array_seat_status) != 7) {
                break;
            }
        }
        current = current->link;
    }
    fclose(fp);
}