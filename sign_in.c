#include"header.h"

int sign_in(TRAIN *info) {
    char *name, password[100];

    print_header("ACCOUNT LOGIN", GREEN);
    printf("Enter the user name: ");
    while(getchar() != '\n'); // Clear buffer
    name = get_string();

    printf("Enter the password: ");
    scanf("%s", password);

    FILE *fp = fopen("users.dat", "r");
    if(fp == NULL) {
        printf("%sError opening user database!%s\n", RED, RESET);
        free(name);
        return 0;
    }

    char file_name[100], file_pass[100];
    int found = 0;
    while(fscanf(fp, "%s %s", file_name, file_pass) != EOF) {
        if(strcmp(name, file_name) == 0) {
            found = 1;
            if(strcmp(password, file_pass) == 0) {
                fclose(fp);
                if(strcmp(name, "admin") == 0) {
                    admin_menu(&info);
                } else {
                    user_menu(info, name);
                }
                free(name);
                return 1;
            } else {
                int attempts = 0;
                while(attempts < 5) {
                    printf("%sIncorrect password. Attempts left: %d%s\n",
                           RED, 5 - attempts, RESET);
                    printf("Enter the password again: ");
                    scanf("%s", password);
                    if(strcmp(password, file_pass) == 0) {
                        fclose(fp);
                        if(strcmp(name, "admin") == 0) {
                            admin_menu(&info);
                        } else {
                            user_menu(info, name);
                            }
                        free(name);
                        return 1;
                    }
                    attempts++;
                }
                printf("%sToo many failed attempts. Try again later.%s\n", RED, RESET);
                fclose(fp);
                free(name);
                return 0;
            }
        }
    }

    if(!found) {
        printf("%sAccount not found. Please create a new account.%s\n", RED, RESET);
    }
    fclose(fp);
    free(name);
    return 0;
}