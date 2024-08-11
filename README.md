# Text Editor Project

## Purpose of the Project

The goal of this project is to create a simple yet functional text editor from scratch. This project provides an opportunity to explore and implement core data structures like linked lists and stacks while working with file I/O in the C programming language. The text editor you build will allow you to gain practical experience with managing dynamic memory, manipulating strings, and implementing undo functionality. While the editor may not compete with modern editors, it will offer a valuable learning experience in understanding the underlying mechanics of text manipulation.

## Project Files

The project is organized into several key files:

- **`editor_lib.h`**: This header file contains the function declarations and data structure definitions required for the text editor. You will not need to modify this file.

- **`editor_lib.c`**: The primary source file where the implementation of the editor's core functions will take place. This file is where most of your work will be focused.

- **`editor.c`**: The main entry point of the text editor program. It handles user input and coordinates the execution of the editor's functionalities. You may modify this file to enhance the editor's features.

- **`editor_lib_test.c`**: A test suite that contains various test cases to ensure your functions behave as expected. You can modify and add more tests to validate your code thoroughly.

- **`Makefile`**: This makefile automates the process of compiling your program. It simplifies the build process, ensuring that all dependencies are correctly managed.

- **`DESIGN.md`**: A design document where you will articulate your implementation plan, pseudocode, and thought process. This file helps in organizing your approach before diving into coding.

## Data Structures

This text editor relies on two primary data structures:

- **Linked List (`ll_text`)**: The text in memory is represented as a linked list where each node contains a line of text. This structure allows efficient management and manipulation of text lines, enabling easy insertion, deletion, and modification of lines within the editor.

- **Stack (`ll_text_stack`)**: The stack is used to implement the undo functionality. Each time an edit is made, the current state of the text is pushed onto the stack. This allows for easy reversion to previous states by popping the stack, effectively undoing the most recent changes.

## Reflection

This project provides a hands-on experience in applying fundamental data structures to solve a real-world problem—building a text editor. By working with linked lists, you gain a deeper understanding of dynamic memory allocation and node manipulation. The stack implementation demonstrates how to manage state changes effectively, which is crucial for implementing undo functionality in software applications.

Through this project, you will not only develop a functional text editor but also enhance your problem-solving skills and gain insights into the inner workings of text manipulation and memory management in C. The experience gained is invaluable for anyone looking to deepen their understanding of low-level programming and data structures.