// C program for a menu-driven student management system
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable to keep track of the number of students
int student_count = 0;

// Structure to store student information
struct StudentInfo {
    char fname[50];
    char lname[50];
    int roll;
} students[55];

// Function to add a student
void add_student() {
    printf("Add Student Details\n");
    printf("--------------------\n");
    // Input first name
    printf("Enter the first name of the student: ");
    scanf("%s", students[student_count].fname);
    // Input last name
    printf("Enter the last name of the student: ");
    scanf("%s", students[student_count].lname);
    // Input roll number
    printf("Enter the roll number: ");
    scanf("%d", &students[student_count].roll);
    student_count++;
}

// Function to find a student by roll number
void find_by_roll() {
    int roll_number;
    printf("Enter the roll number of the student: ");
    scanf("%d", &roll_number);
    for (int j = 0; j < student_count; j++) {
        if (roll_number == students[j].roll) {
            // Display student details
            printf("Student Details:\n");
            printf("First name: %s\n", students[j].fname);
            printf("Last name: %s\n", students[j].lname);
            printf("Roll number: %d\n", students[j].roll);
            return;
        }
    }
    // Roll number not found
    printf("Roll number not found.\n");
}

// Function to find a student by first name
void find_by_first_name() {
    char first_name[50];
    printf("Enter the first name of the student: ");
    scanf("%s", first_name);
    for (int j = 0; j < student_count; j++) {
        if (strcmp(students[j].fname, first_name) == 0) {
            // Display student details
            printf("Student Details:\n");
            printf("First name: %s\n", students[j].fname);
            printf("Last name: %s\n", students[j].lname);
            printf("Roll number: %d\n", students[j].roll);
            return;
        }
    }
    // First name not found
    printf("First name not found.\n");
}

// Function to print the total number of students
void total_students() {
    printf("Total number of students: %d\n", student_count);
    printf("Maximum number of students allowed: 50\n");
    printf("You can add %d more students.\n", 50 - student_count);
}

// Function to delete a student by roll number
void delete_student() {
    int roll_number;
    printf("Enter the roll number to delete: ");
    scanf("%d", &roll_number);
    for (int j = 0; j < student_count; j++) {
        if (roll_number == students[j].roll) {
            // Shift students left to fill the gap
            for (int k = j; k < student_count - 1; k++) {
                students[k] = students[k + 1];
            }
            student_count--;
            printf("Student removed successfully.\n");
            return;
        }
    }
    // Roll number not found
    printf("Roll number not found.\n");
}

// Function to update student data
void update_student() {
    int roll_number;
    printf("Enter the roll number to update: ");
    scanf("%d", &roll_number);
    for (int j = 0; j < student_count; j++) {
        if (students[j].roll == roll_number) {
            printf("Select field to update:\n");
            printf("1. First name\n");
            printf("2. Last name\n");
            printf("3. Roll number\n");
            int choice;
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    // Update first name
                    printf("Enter new first name: ");
                    scanf("%s", students[j].fname);
                    break;
                case 2:
                    // Update last name
                    printf("Enter new last name: ");
                    scanf("%s", students[j].lname);
                    break;
                case 3:
                    // Update roll number
                    printf("Enter new roll number: ");
                    scanf("%d", &students[j].roll);
                    break;
                default:
                    printf("Invalid choice.\n");
                    return;
            }
            printf("Student details updated successfully.\n");
            return;
        }
    }
    // Roll number not found
    printf("Roll number not found.\n");
}

// Function to save students to file
void save_to_file() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    for (int j = 0; j < student_count; j++) {
        fprintf(file, "%s %s %d\n", students[j].fname, students[j].lname, students[j].roll);
    }
    fclose(file);
    printf("Students saved to file successfully.\n");
}

// Function to load students from file
void load_from_file() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }
    student_count = 0;
    while (fscanf(file, "%s %s %d", students[student_count].fname, students[student_count].lname, &students[student_count].roll) != EOF) {
        student_count++;
    }
    fclose(file);
    printf("\nStudents loaded from file successfully.\n");
}

// Main function
int main() {
    int choice;
    load_from_file(); // Load students from file at the start
    while (1) {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Find Student by Roll Number\n");
        printf("3. Find Student by First Name\n");
        printf("4. Total Number of Students\n");
        printf("5. Delete Student by Roll Number\n");
        printf("6. Update Student by Roll Number\n");
        printf("7. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Perform action based on user choice
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                find_by_roll();
                break;
            case 3:
                find_by_first_name();
                break;
            case 4:
                total_students();
                break;
            case 5:
                delete_student();
                break;
            case 6:
                update_student();
                break;
            case 7:
                save_to_file();
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}