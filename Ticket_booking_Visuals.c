#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 5
#define MAX_COLS 5

// Structure for a ticket
typedef struct {
    int isBooked;          // 0 = Not booked, 1 = Booked
    char customerName[50]; // Customer name for the booked seat
} Ticket;

void initializeSeats(Ticket seats[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            seats[i][j].isBooked = 0;              // Mark seat as not booked
            strcpy(seats[i][j].customerName, "");  // Clear customer name
        }
    }
}

void displaySeats(Ticket seats[MAX_ROWS][MAX_COLS]) {
    printf("\nSeating Arrangement:\n");
    printf("Legend: [ ] = Available, [X] = Booked\n\n");

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (seats[i][j].isBooked) {
                printf("[X] ");  // Booked seat
            } else {
                printf("[ ] ");  // Available seat
            }
        }
        printf("\n"); // Move to the next row
    }
}

void bookSeat(Ticket seats[MAX_ROWS][MAX_COLS]) {
    int row, col;
    char name[50];

    printf("\nEnter row and column to book (1-%d for row and 1-%d for column): ", MAX_ROWS, MAX_COLS);
    scanf("%d %d", &row, &col);

    // Validate input
    if (row < 1 || row > MAX_ROWS || col < 1 || col > MAX_COLS) {
        printf("Invalid seat selection! Please try again.\n");
        return;
    }

    // Convert 1-based index to 0-based
    row--;
    col--;

    // Check if the seat is already booked
    if (seats[row][col].isBooked) {
        printf("Seat [%d][%d] is already booked. Please choose another seat.\n", row + 1, col + 1);
    } else {
        printf("Enter your name: ");
        scanf(" %[^\n]", name);
        seats[row][col].isBooked = 1;
        strcpy(seats[row][col].customerName, name);
        printf("Seat [%d][%d] has been successfully booked for %s.\n", row + 1, col + 1, name);
    }
}

void displayBookingDetails(Ticket seats[MAX_ROWS][MAX_COLS]) {
    printf("\nBooked Seats:\n");

    int booked = 0; // To track if any seat is booked
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (seats[i][j].isBooked) {
                printf("Seat [%d][%d]: %s\n", i + 1, j + 1, seats[i][j].customerName);
                booked = 1;
            }
        }
    }

    if (!booked) {
        printf("No seats are booked yet.\n");
    }
}

int main() {
    Ticket seats[MAX_ROWS][MAX_COLS];
    int choice;

    initializeSeats(seats);

    while (1) {
        printf("\nDigital Ticket Booking System\n");
        printf("1. View Seating Arrangement\n");
        printf("2. Book a Seat\n");
        printf("3. View Booking Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                bookSeat(seats);
                break;
            case 3:
                displayBookingDetails(seats);
                break;
            case 4:
                printf("Thank you for using the ticket booking system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

//Initial View
// Seating Arrangement:
// Legend: [ ] = Available, [X] = Booked

// [ ] [ ] [ ] [ ] [ ]
// [ ] [ ] [ ] [ ] [ ]
// [ ] [ ] [ ] [ ] [ ]
// [ ] [ ] [ ] [ ] [ ]
// [ ] [ ] [ ] [ ] [ ]


//booking a seat
// Enter row and column to book (1-5 for row and 1-5 for column): 2 3
// Enter your name: Alice
// Seat [2][3] has been successfully booked for Alice.


//After Booking
// Seating Arrangement:
// Legend: [ ] = Available, [X] = Booked

// [ ] [ ] [ ] [ ] [ ]
// [ ] [ ] [X] [ ] [ ]
// [ ] [ ] [ ] [ ] [ ]
// [ ] [ ] [ ] [ ] [ ]
// [ ] [ ] [ ] [ ] [ ]
