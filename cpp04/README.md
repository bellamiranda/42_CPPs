# 42 Cursus - C++ Module 04
# Description
The C++ Module 04 at School 42 dives deeper into advanced object-oriented programming concepts, focusing on multiple inheritance, abstract classes, interfaces, and the proper use of dynamic polymorphism. You will learn how to manage references, type conversions, and build more robust class architectures through extensive use of base classes.

# Topics Covered
Multiple Inheritance: Combining multiple base classes into a single derived class.
Abstract Classes and Interfaces: Using pure virtual functions and interface design.
Dynamic Polymorphism: Leveraging virtual and override for runtime behavior.
Type Conversion in C++: Understanding static_cast, dynamic_cast, const_cast, and reinterpret_cast.
Base Class References and Pointers: Using pointers and references to achieve polymorphism.
Virtual Destructors: Ensuring proper cleanup in inheritance hierarchies.
Decoupling and Interface-Oriented Design: Writing flexible and maintainable code.

📌 Exercise 00 - Polymorphism
Implement a base Animal class and derive Dog and Cat from it, each overriding makeSound() to print specific sounds. Use polymorphism to test behavior, and also create WrongAnimal/WrongCat to show what happens when virtual functions are missing. Obs -> My implementation have a mistake, and i've decided to not make the correction! Try to find it where is it.

📌 Exercise 01 - I don’t want to set the world on fire
Implement a Brain class with 100 ideas, dynamically allocated in Dog and Cat via new Brain() and properly deleted in their destructors. Ensure deep copies and test polymorphic deletion of Animal pointers to avoid memory leaks.

📌 Exercise 02 - Abstract class
Make the Animal class abstract by declaring at least one pure virtual function (e.g., makeSound()), preventing direct instantiation. Rename it to AAnimal if desired—everything should still function through polymorphism as before.

📌 Exercise 03 - Interface & recap
Implement an AMateria abstract class as an interface, then define concrete classes Ice and Cure, each overriding clone() and use() to provide type-specific behavior. Create the Character class, which manages an inventory of up to 4 Materias using the ICharacter interface, with deep copying and memory-safe equip/unequip logic. Lastly, implement a MateriaSource class using the IMateriaSource interface to learn and clone Materias by type.

# Useful References
C++ Reference - Inheritance
C++ Reference - Virtual Functions
Effective C++ by Scott Meyers
C++ Primer by Stanley B. Lippman

# Conclusion
Module 04 builds a strong foundation in multiple inheritance and polymorphism, reinforcing core C++ principles like encapsulation, abstraction, and interface-driven design. By completing this module, you'll better understand how to structure and manage complex class hierarchies in a safe and efficient way.
