#include"header.h"

void sign_up(void) {
    char *name, password[100];

    print_header("CREATE NEW ACCOUNT", GREEN);
    printf("Enter the user name: ");
    while(getchar() != '\n'); // Clear buffer
    name = get_string();

    printf("Enter the 8 digits password that contains at least one capital letter, special character, lowercase letter and digit: ");
    scanf("%s", password);

    int cnt = 0;
    while(1) {
        if(check_password(password)) {
            FILE *p = fopen("users.dat", "a");
            if(p) {
                fprintf(p, "%s %s\n", name, password);
                fclose(p);
                print_header("ACCOUNT CREATED", GREEN);
                printf("│ %-76s │\n", "Account created successfully!");
                print_line('=', BOX_WIDTH);
                free(name);
                return;
            } else {
                printf("%sError saving account information!%s\n", RED, RESET);
                free(name);
                return;
            }
        } else {
            printf("%sIncorrect password format. Enter again: %s", RED, RESET);
            scanf("%s", password);
            cnt++;
            if(cnt > 5) {
                printf("%sToo many attempts. Please try later.%s\n", RED, RESET);
                free(name);
                return;
            }
        }
    }
}