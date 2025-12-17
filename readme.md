# C++ Modules (CPP00 - CPP04)

This repository contains C++ exercises covering fundamental to advanced concepts in object-oriented programming. Each module progressively builds upon previous concepts, from basic syntax to polymorphism and abstract classes.

## 📚 Table of Contents

- [Overview](#overview)
- [Modules](#modules)
  - [CPP Module 00](#cpp-module-00---namespaces-classes-member-functions)
  - [CPP Module 01](#cpp-module-01---memory-allocation-pointers-references)
  - [CPP Module 02](#cpp-module-02---ad-hoc-polymorphism-operator-overloading)
  - [CPP Module 03](#cpp-module-03---inheritance)
  - [CPP Module 04](#cpp-module-04---subtype-polymorphism-abstract-classes)
- [Compilation](#compilation)
- [Usage](#usage)

---

## Overview

These modules are designed to teach C++ programming from the ground up, following the C++98 standard. Each exercise focuses on specific concepts and best practices in C++ development.

**Key Learning Objectives:**
- Understanding C++ syntax and semantics
- Object-oriented programming principles
- Memory management (stack vs heap)
- Operator overloading
- Inheritance and polymorphism
- Abstract classes and interfaces

---

## Modules

### CPP Module 00 - Namespaces, Classes, Member Functions

Introduction to C++ basics including namespaces, classes, and member functions.

#### Exercises:

**ex00: Megaphone**
- Simple program that converts arguments to uppercase
- Introduction to C++ I/O streams
- String manipulation in C++

**ex01: PhoneBook**
- Interactive phonebook application
- Classes: `PhoneBook`, `Contact`
- Private/public member attributes and methods
- Data encapsulation and basic class design
- Handling user input and formatted output

**ex02: Account**
- Bank account management system
- Static member variables and functions
- Timestamps and logging
- Understanding const member functions

---

### CPP Module 01 - Memory Allocation, Pointers, References

Deep dive into memory management, pointers to members, references, and switch statements.

#### Exercises:

**ex00: BraiiiiiiinnnzzzZ**
- Classes: `Zombie`
- Heap vs stack allocation
- Understanding object lifecycle
- Functions: `newZombie()` (heap), `randomChump()` (stack)

**ex01: Moar brainz!**
- Classes: `Zombie`
- Dynamic array allocation
- Function: `zombieHorde()` - creates N zombies
- Proper memory management and cleanup

**ex02: HI THIS IS BRAIN**
- Understanding pointers and references
- Memory addresses
- Demonstrating the difference between pointers and references

**ex03: Unnecessary violence**
- Classes: `Weapon`, `HumanA`, `HumanB`
- References vs pointers usage
- When to use references (HumanA) vs pointers (HumanB)
- Object composition

**ex04: Sed is for losers**
- File I/O operations
- String replacement implementation
- Command-line argument parsing
- Creating a custom sed-like tool

**ex05: Harl 2.0**
- Classes: `Harl`
- Pointers to member functions
- Function dispatch patterns
- Logging system implementation

**ex06: Harl filter**
- Classes: `Harl`
- Switch statements
- Log level filtering
- Building upon ex05

---

### CPP Module 02 - Ad-hoc Polymorphism, Operator Overloading

Understanding fixed-point numbers and operator overloading.

#### Exercises:

**ex00: My First Class in Orthodox Canonical Form**
- Classes: `Fixed`
- Orthodox Canonical Form (OCF):
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor
- Fixed-point number representation
- Raw bits manipulation

**ex01: Towards a more useful fixed-point number class**
- Classes: `Fixed`
- Additional constructors (int, float)
- Conversion functions (toInt, toFloat)
- Insertion operator overload (<<)
- Understanding floating-point to fixed-point conversion

**ex02: Now we're talking**
- Classes: `Fixed`
- Arithmetic operators: +, -, *, /
- Comparison operators: >, <, >=, <=, ==, !=
- Increment/decrement operators: ++, --
- Static member functions: min, max
- Full-featured fixed-point class

---

### CPP Module 03 - Inheritance

Introduction to inheritance in C++.

#### Exercises:

**ex00: Aaaaand... OPEN!**
- Classes: `ClapTrap`
- Basic class with attributes and methods
- Constructor/destructor chains
- Attack, take damage, and repair mechanics

**ex01: Serena, my love!**
- Classes: `ClapTrap`, `ScavTrap`
- Single inheritance
- Constructor/destructor order
- Method overriding
- Derived class specialization

**ex02: Repetitive work**
- Classes: `ClapTrap`, `ScavTrap`, `FragTrap`
- Multiple derived classes
- Understanding inheritance hierarchy
- Special abilities for different trap types

**ex03: Now it's weird!**
- Classes: `ClapTrap`, `ScavTrap`, `FragTrap`, `DiamondTrap`
- Diamond inheritance problem
- Virtual inheritance
- Name ambiguity resolution
- Complex inheritance scenarios

---

### CPP Module 04 - Subtype Polymorphism, Abstract Classes

Advanced polymorphism concepts, abstract classes, and interfaces.

#### Exercises:

**ex00: Polymorphism**
- Classes: `Animal`, `Dog`, `Cat`, `WrongAnimal`, `WrongCat`
- Virtual functions
- Runtime polymorphism
- Virtual destructors importance
- Demonstrating correct vs incorrect polymorphism

**ex01: I don't want to set the world on fire**
- Classes: `Animal`, `Dog`, `Cat`, `Brain`
- Deep copy vs shallow copy
- Copy constructor and assignment operator
- Dynamic memory in derived classes
- Preventing memory leaks

**ex02: Abstract class**
- Classes: `Animal` (abstract), `Dog`, `Cat`, `Brain`
- Pure virtual functions
- Abstract base classes
- Preventing instantiation of base class
- Interface design

**ex03: Interface & recap**
- Classes: `AMateria`, `Ice`, `Cure`, `ICharacter`, `Character`, `IMateriaSource`, `MateriaSource`
- Multiple interfaces
- Abstract classes and concrete implementations
- Materia system (RPG-like)
- Complex object interactions
- Inventory management

---

## Compilation

Each exercise includes a Makefile with standard rules:

```bash
# Compile the project
make

# Clean object files
make clean

# Clean object files and executable
make fclean

# Recompile everything
make re
```

**Compilation Flags:**
- Compiler: `c++`
- Standard: `-std=c++98`
- Flags: `-Wall -Wextra -Werror`

---

## Usage

Navigate to any exercise directory and compile:

```bash
# Example: CPP00 - ex01
cd cpp00/ex01
make
./phonebook

# Example: CPP03 - ex03
cd cpp03/ex03
make
./diamondtrap

# Example: CPP04 - ex03
cd cpp04/ex03
make
./materia
```

---

## 📝 Notes

- All code follows the **C++98 standard**
- **Orthodox Canonical Form** is implemented where required
- Memory leaks are checked and prevented
- Code follows best practices for const correctness
- Proper encapsulation and information hiding

---

## 🎓 Learning Resources

- [C++ Reference](https://en.cppreference.com/)
- [Learn C++](https://www.learncpp.com/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

---

**Author:** [Your Name]  
**Last Updated:** December 2025