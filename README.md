# My Text Editor Project

## Purpose of My Project

My goal for this project is to create a simple yet functional text editor from scratch. This project gives me the opportunity to explore and implement core data structures like linked lists and stacks while working with file I/O in the C programming language.

## My Project Files

I’ve organized my project into several key files:

- **`editor_lib.h`**: This header file contains the function declarations and data structure definitions required for the text editor. I won’t need to modify this file.

- **`editor_lib.c`**: This is the primary source file where I’ll implement the editor's core functions. Most of my work will be focused here.

- **`editor.c`**: This is the main entry point of the text editor program. It handles user input and coordinates the execution of the editor's functionalities. I may modify this file to enhance the editor's features.

- **`editor_lib_test.c`**: A test suite that contains various test cases to ensure my functions behave as expected. I can modify and add more tests to validate my code thoroughly.

- **`Makefile`**: This makefile automates the process of compiling my program. It simplifies the build process, ensuring that all dependencies are correctly managed.

- **`DESIGN.md`**: A design document where I will articulate my implementation plan, pseudocode, and thought process. This file helps me organize my approach before diving into coding.

## Data Structures

My text editor relies on two primary data structures:

- **Linked List (`ll_text`)**: The text in memory is represented as a linked list where each node contains a line of text. This structure allows for efficient management and manipulation of text lines, enabling easy insertion, deletion, and modification of lines within the editor.

- **Stack (`ll_text_stack`)**: The stack is used to implement the undo functionality. Each time I make an edit, the current state of the text is pushed onto the stack. This allows for easy reversion to previous states by popping the stack, effectively undoing my most recent changes.

## Reflection

This project provides me with a hands-on experience in applying fundamental data structures to solve a real-world problem—building a text editor. By working with linked lists, I gain a deeper understanding of dynamic memory allocation and node manipulation. The stack implementation demonstrates how to manage state changes effectively, which is crucial for implementing undo functionality in software applications.

Through this project, I will not only develop a functional text editor but also enhance my problem-solving skills and gain insights into the inner workings of text manipulation and memory management in C. The experience I gain here is invaluable for deepening my understanding of low-level programming and data structures.
