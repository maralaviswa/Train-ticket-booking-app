#include"header.h"

int main() {
    TRAIN *info = NULL;
    info = syn_file(info);  // Load train data
    syn_file1(info);        // Load seat data

    char choice;
    while(1) {
        print_header("RAILWAY RESERVATION SYSTEM", GREEN);
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                sign_up();
                break;
            case '2':
                sign_in(info);
                break;
            case '3':
                save_file(info); // Save before exiting
                exit(0);
            default:
                printf("%sInvalid choice!%s\n", RED, RESET);
        }
    }
    return 0;
}
void admin_menu(TRAIN **info) {
    char choice;

    while(1) {
        print_header("ADMIN MENU", GREEN);
        printf("1. Add Trains\n");
        printf("2. View Train Information\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                *info = add_trains(*info);
                break;
            case '2':
                print_train_info(*info);
                break;
            case '3':
                return;
            default:
                printf("%sInvalid choice!%s\n", RED, RESET);
        }
    }
}

// User menu
void user_menu(TRAIN *info, char *username) {
    char choice;
    BOOKING b;
    strcpy(b.username, username);

    while(1) {
        print_header("USER MENU", GREEN);
        printf("1. Reserve Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. View Booking Details\n");
        printf("4. View Train Information\n");
        printf("5. Logout\n");
        printf("6. add_train\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                reserve_ticket(info, b.username);
                break;
            case '2':
                cancel_ticket(info, b.username);
                break;
            case '3':
                book_ticket(info, b.username);
                break;
            case '4':
                print_train_info(info);
                break;
            case '5':
                return;
            case'6':
                printf("only for authorised persons\n");
                scanf("%s",username);
                if(strcmp(username,"admin")==0)
                {
                        admin_menu(&info);
                        save_file(info);
                }
                else
                        printf("invalid author\n");
                break;
            default:
                printf("%sInvalid choice!%s\n", RED, RESET);
        }
    }
}