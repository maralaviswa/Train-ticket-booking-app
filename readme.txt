Train Ticket Booking System in C
================================

Description:
------------
This is a command-line based Train Ticket Booking System written in C. It allows users to register, sign in, and book or cancel train tickets. The system includes both admin and regular user roles and features a colorful, formatted terminal interface.

The application uses structured data (structs), dynamic memory allocation, and file handling to manage trains, seats, users, and bookings persistently.

Features:
---------
- User registration and login
- Admin functionality to add new trains
- Dynamic seat availability per train and date
- Table-style display of train details (with colors)
- Ticket booking with passenger name and seat number assignment
- Ticket cancellation with automatic seat reallocation
- User-specific booking history (including passenger names and seat numbers)
- File-based data persistence:
  - `trains.dat` – stores train information
  - `seats.dat` – tracks seat availability by train and date
  - `users.dat` – stores usernames and passwords
  - `bookings.dat` – stores full booking records

File Structure:
---------------
Source Files:
- `project.c` or `mini_project.c`: Main function and menu loop
- `add_trains.c`: Admin function to add trains
- `menu.c`: Displays login and role-based menus
- `sign_up.c`, `sign_in.c`: Handle user registration and login
- `check_password.c`: Authenticates user login
- `sync_file.c`: Loads/saves trains and seat data from files
- `book_ticket.c`: Handles booking logic
- `reserve_ticket.c`: Allocates seats and collects passenger info
- `cancel_ticket.c`: Cancels bookings and frees seats
- `booking_details.c`: Displays user's booking history
- `format.c`: Manages colored and styled terminal output
- `save.c`: Syncs data to files
- `header.h`: Shared structures and function declarations

How It Works:
-------------
1. **Login/Register**:
   - User starts by signing up or logging in.
   - Credentials are checked against `users.dat`.

2. **Admin Menu**:
   - Admins can add trains by entering train number, name, source, destination, and total seats.
   - Train data is stored in `trains.dat`.

3. **User Menu**:
   - Users can:
     - View all available trains with colorful table formatting.
     - Choose a train and book tickets for a specific date.
     - Enter number of passengers and their names.
     - Seat numbers are auto-assigned and saved with the booking in `bookings.dat`.
     - Booking updates the available seat count in `seats.dat`.

4. **Cancellation**:
   - Users can cancel previously booked seats by providing date and train number.
   - Seat numbers are removed, and availability is updated.

5. **Booking History**:
   - Users can view all their past bookings, including:
     - Passenger names
     - Seat numbers
     - Train and journey date
   - Fetched from `bookings.dat`.

6. **File Syncing**:
   - All data is read from and written to files (`trains.dat`, `seats.dat`, `bookings.dat`) to ensure persistence.
   - Sync occurs on startup and after every booking or cancellation.

Makefile Compilation:
---------------------
The project includes a Makefile for automated compilation.

Makefile Contents:
------------------
  a.out:  menu.o check_password.o sync_file.o book_ticket.o format.o reserve_ticket.o sign_in.o sign_up.o save.o cancel_ticket.o booking_details.o add_trains.o
        cc  menu.o check_password.o sync_file.o book_ticket.o format.o reserve_ticket.o sign_in.o sign_up.o save.o cancel_ticket.o booking_details.o  add_trains.o

add_trains.o:add_trains.c
        cc - c add_trains.c
menu.o:menu.c
        cc - c menu.c
check_password.o:check_password.c
        cc - c check_password.c
sync_file.o:sync_file.c
        cc - c sync_file.c
book_ticket.o:book_ticket.c
        cc - c book_ticket.c
format.o:format.c
        cc - c format.c
reserve_ticket.o:reserve_ticket.c
        cc - c reserve_ticket.c
sign_in.o:sign_in.c
        cc - c sign_in.c
sign_up.o:sign_up.c
        cc - c sign_up.c
save.o:save.c
        cc - c save.c
cancel_ticket.o:cancel_ticket.c
        cc - c cancel_ticket.c
booking_details.o:booking_details.c
        cc - c booking_details.c

**Targets:**

- **Build the project:**


