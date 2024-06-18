

---

# Student Management System

This C program implements a menu-driven student management system. It allows users to add, find, delete, and update student details. The program can handle up to 50 students and includes functionalities to save and load student data from a file.

## Features

- **Add Student Details**: Add a new student's first name, last name, and roll number.
- **Find Student by Roll Number**: Search for a student using their roll number.
- **Find Student by First Name**: Search for a student using their first name.
- **Total Number of Students**: Display the total number of students and the remaining capacity.
- **Delete Student by Roll Number**: Remove a student's details using their roll number.
- **Update Student Details**: Update a student's first name, last name, or roll number.
- **Save and Load**: Save the student details to a file and load them back into the system.

## Code Overview

The main parts of the code are:

- **Structure Definition**: Defines the `StudentInfo` structure to store student details.
- **Functions**:
  - `add_student()`: Adds a new student to the system.
  - `find_by_roll()`: Finds a student by their roll number.
  - `find_by_first_name()`: Finds a student by their first name.
  - `total_students()`: Displays the total number of students.
  - `delete_student()`: Deletes a student by their roll number.
  - `update_student()`: Updates a student's details.
  - `save_to_file()`: Saves the student details to a file.
  - `load_from_file()`: Loads student details from a file.
- **Main Function**: The driver code that displays the menu and handles user input.

## Example Usage

```plaintext
--- Student Management System ---
1. Add Student
2. Find Student by Roll Number
3. Find Student by First Name
4. Total Number of Students
5. Delete Student by Roll Number
6. Update Student by Roll Number
7. Save and Exit
Enter your choice: 1

--- Add Student Details ---
Enter the first name of the student: John
Enter the last name of the student: Doe
Enter the roll number: 123
Student added successfully!

--- Student Management System ---
1. Add Student
2. Find Student by Roll Number
3. Find Student by First Name
4. Total Number of Students
5. Delete Student by Roll Number
6. Update Student by Roll Number
7. Save and Exit
Enter your choice: 7
Students saved to file successfully.
```

## Notes

- Ensure that the program has read/write permissions to the directory where `students.txt` will be created.
- The maximum number of students is limited to 50.
