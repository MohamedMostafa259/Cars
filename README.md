# Cars Project
**A Simple C++ Console Application has Two Tasks**

## Table of Contents
- [Introduction](#introduction)
- [Task 1: Car Dealership Management](#Task-1:-Car-Dealership-Management)
  - [1.1 Add a Car](#1.1-Add-a-Car)
  - [1.2 Remove a Car](#1.2-Remove-a-Car)
  - [1.3 Search for a Car](#1.3-Search-for-a-Car)
  - [1.4 Display all Cars](#1.4-Display-all-Cars)
- [Task 2: Stack and Queue Operations](#Task-2:-Stack-and-Queue-Operations)
  - [2.1 Copy a Stack](#2.1-Copy-a-Stack)
  - [2.2 Convert Decimal to Another Base](#2.2-Convert-Decimal-to-Another-Base)
  - [2.3 Subtract 2 Big Integers](#2.3-Subtract-2-Big-Integers)
  - [2.4 Move Nth Element to Front in a Queue of Strings](#2.4-Move-Nth-Element-to-Front-in-a-Queue-of-Strings)
  - [2.5 Reverse Elements of a Queue](#2.5-Reverse-Elements-of-a-Queue)
- [Bonus](#Bonus)
- [Execution](#Execution)
- [Assumptions and Limitations](#Assumptions-and-Limitations)

## Introduction
This project encompasses two distinct tasks. The first task involves the creation of an application for Drive Smart Motors, a car dealership business. 
The application manages a list of available cars, implementing an ordered unique linked list for efficient tracking. 
The second task involves the implementation of Stack and Queue classes based on the STL list, along with various global functions utilizing these classes.

## Task 1: Car Dealership Management
### 1.1 Add a Car
To add a car to the list, the program inserts a new node into the ordered unique linked list. 
The insertion ensures that the list remains ordered by the car's make and model. 
If the car is already in the list, the count (carsNum) is incremented; otherwise, a new node is created.

### 1.2 Remove a Car
To remove a car from the list, the program searches for the car by make and model. 
If the car is found and has only one instance, the node is completely removed. 
If the car has multiple instances, the count (carsNum) is decremented. If the car is not found, an appropriate message is displayed.

### 1.3 Search for a Car
The program allows users to search for a car by specifying the make and model. 
If the car is found, the program displays the number of available cars with that make and model; otherwise, a message is shown indicating that the car was not found.

### 1.4 Display all Cars
This option displays the entire list of cars, including their make, model, and the quantity available.

## Task 2: Stack and Queue Operations
### 2.1 Copy a Stack
This option copies the elements of one stack to another while maintaining the order. 
The program utilizes recursion, instead of an additional STL stack or array, to achieve this.

### 2.2 Convert Decimal to Another Base
Users can input a decimal number and a desired base (between 2 and 20), and the program converts the decimal number to the specified base.

### 2.3 Subtract 2 Big Integers
Users can input two large integers, and the program performs subtraction, returning the result.

### 2.4 Move Nth Element to Front in a Queue of Strings
This option moves the Nth element to the front in a queue of strings, where N is a user-inputted index (1-based index).

### 2.5 Reverse Elements of a Queue
This option reverses the order of elements in a queue.

## Bonus
This bonus feature provides a convenient way to manage and display book records within the program.
#### Execution
When prompted, select option 3 in the main menu.
Enter the file name (including its extension) when prompted.
The program will read the books from the file and display the authors and titles.

## Execution
#### Navigate Through Tasks:
Once the program is running, you will see a menu with task options. Follow the on-screen prompts to navigate through the tasks and select options.

#### Input Validation:
The program includes input validation to ensure correct usage. Follow the instructions and provide valid input when prompted.

#### Exit the Program:
To exit the program, follow the on-screen instructions. Typically, there will be an option to exit or return to the main menu.

#### Review Output:
Depending on the tasks selected, the program will display relevant information, such as car details, stack or queue operations, etc.

## Assumptions and Limitations
- The program assumes valid inputs when dealing with integers rather than strings. However, it is designed to handle the allowed ranges for specific data types. 
For instance, when accepting integer inputs, the program ensures that the entered values fall within the valid range for the respective data type.
- The implementation of Stack and Queue classes uses the STL list.

