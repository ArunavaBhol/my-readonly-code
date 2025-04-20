#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 100

// Structure for a ticket
typedef struct {
    int seatNumber;
    char customerName[50];
    int isBooked;
} Ticket;

void initializeSeats(Ticket seats[], int totalSeats) {
    for (int i = 0; i < totalSeats; i++) {
        seats[i].seatNumber = i + 1;  // Assign a seat number starting from 1.
        seats[i].isBooked = 0; // Set the initial booking status to 'not booked' (0).
        strcpy(seats[i].customerName, "");  //The customer names for all seats are initialized to an empty string.
    }
}
//Example:- Seat 1: seatNumber = 1, isBooked = 0, customerName = ""

void displayAvailableSeats(Ticket seats[], int totalSeats) {
    printf("\nAvailable Seats:\n");
    for (int i = 0; i < totalSeats; i++) {
        if (!seats[i].isBooked) {    // Check if the seat is not booked (isBooked == 0).
            printf("Seat %d ", seats[i].seatNumber);  // Print the seat number.
        }
    }
    printf("\n");
}

void bookTicket(Ticket seats[], int totalSeats) {
    int seatNumber;
    char name[50];

    printf("\nEnter seat number to book (1-%d): ", totalSeats);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > totalSeats) {
        printf("Invalid seat number! Please try again.\n");
        return;
    }

    if (seats[seatNumber - 1].isBooked) {
        printf("Seat %d is already booked. Please choose another seat.\n", seatNumber);
    } else {
        printf("Enter your name: ");
        scanf(" %[^\n]", name);
        seats[seatNumber - 1].isBooked = 1;
        strcpy(seats[seatNumber - 1].customerName, name);
        printf("Seat %d has been successfully booked for %s.\n", seatNumber, name);
    }
}

void displayBookingDetails(Ticket seats[], int totalSeats) {
    printf("\nBooking Details:\n");
    for (int i = 0; i < totalSeats; i++) {
        if (seats[i].isBooked) {
            printf("Seat %d: %s\n", seats[i].seatNumber, seats[i].customerName);
        }
    }
}

int main() {
    Ticket seats[MAX_SEATS];
    int totalSeats = 20; // You can set the total number of seats here
    int choice;

    initializeSeats(seats, totalSeats);

    while (1) {
        printf("\nDigital Ticket Booking System\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. View Booking Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableSeats(seats, totalSeats);
                break;
            case 2:
                bookTicket(seats, totalSeats);
                break;
            case 3:
                displayBookingDetails(seats, totalSeats);
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
