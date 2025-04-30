#include"header.h"
void save_file(TRAIN *info) {
    FILE *fp = fopen("trains.dat", "w");
    FILE *fp1 = fopen("seats.dat", "w");

    if(fp == NULL || fp1 == NULL) {
        printf("%sError opening files for writing!%s\n", RED, RESET);
        if(fp) fclose(fp);
        if(fp1) fclose(fp1);
        return;
    }

    while(info) {
        // Save seat info
        for(int i = 0; i < 3; i++) {
            fprintf(fp1, "%d %d %d %d %d %d %d\n",
                   info->train[i].day,
                   info->train[i].month,
                   info->train[i].year,
                   info->train[i].total_seats,
                   info->train[i].w_list,
                   info->train[i].c_b_status,
                   info->train[i].array_seat_status);
        }

        // Save train info
        fprintf(fp, "%d %s %s %s\n",
                info->train_number,
                info->train_name,
                info->source,
                info->dest);

        info = info->link;
        printf("save to file is successfully completed\n");
    }
    fclose(fp);
    fclose(fp1);
}