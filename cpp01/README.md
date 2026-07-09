# 42 Cursus - C++ Module 01
# Description
The C++ Module 01 is designed to introduce more advanced features of C++, focusing on the foundational topics that every C++ programmer needs to master. In this module, we learned about classes, dynamic memory allocation, constructors, destructors, and object-oriented programming principles.

# Topics Covered
Classes: Defining and using classes, constructors, destructors.
Encapsulation: Access control with private, public, and protected members.
Dynamic Memory Allocation: Using new, delete, and new[].
Copy Constructor and Assignment Operator: How to copy objects correctly.
Overloading: Operator overloading and function overloading.
Memory Management: Smart pointers, RAII, and avoiding memory leaks.
Object-Oriented Programming: Principles like abstraction and inheritance.

# Exercises

📌 Exercise 00 - BraiiiiiiinnnzzzZ
In this exercise, the Zombie class manages a private name attribute and can announce itself with a specific message. It includes two functions: newZombie for creating a heap-allocated zombie, and randomChump for stack-allocated zombies that announce immediately, with destructors handling cleanup.

📌 Exercise 01 - Moar brainz!
The zombieHorde function allocates N Zombie objects in a single memory block, names them, and returns a pointer to the first zombie. The zombies should announce themselves, and proper memory management must be ensured by deleting the zombies and checking for memory leaks.

📌 Exercise 02 - HI THIS IS BRAIN
The program initializes a string and demonstrates the use of a pointer and a reference to that string. It then prints the memory addresses and values of the string, pointer, and reference, showcasing how address manipulation works.

📌 Exercise 03 - Unnecessary violence
The program involves creating a Weapon class with methods to get and set its type, followed by two classes, HumanA and HumanB, each equipped with a weapon and a name. The main task is to model the differences in how HumanA and HumanB manage their weapons (with HumanA always armed and HumanB potentially not), while ensuring correct memory management and handling potential memory leaks.

📌 Exercise 04 - Sed is for losers
The program takes a filename and two strings, opens the file, and creates a new file with the name .replace. It then copies the content from the original file, replacing every occurrence of s1 with s2 without using C file manipulation functions or std::string::replace. Proper error handling for unexpected inputs and file operations is required.

📌 Exercise 05 - Harl 2.0
The program creates a Harl class with private member functions for each complaint level (debug, info, warning, error). The public function complain takes a level string as a parameter and calls the corresponding private function without using multiple if/else statements, but instead using pointers to member functions to automate the complaints.

📌 Exercise 06 - Harl filter
he program implements a filtering system for Harl's complaints based on a given log level. The program takes one of the four levels as a parameter and displays all complaints from that level and above. It uses a switch statement to filter out messages, and if an invalid level is passed, it displays a default message about insignificant complaints

# Conclusion
Module 01 builds on the concepts introduced in Module 00 and dives deeper into object-oriented programming in C++. By the end of this module, we had a good understanding of how to use classes, manage dynamic memory, and apply basic OOP principles in your C++ programs.
