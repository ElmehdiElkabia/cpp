# 🚀 C++ Modules (CPP00 - CPP09)

![C++ Version](https://img.shields.io/badge/C%2B%2B-98-blue?logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)
![License](https://img.shields.io/badge/License-MIT-green)

A comprehensive collection of C++ exercises and projects covering fundamental to advanced object-oriented programming concepts. This repository is designed as a complete learning path through modern C++ development principles.

## 📋 Table of Contents

- [Overview](#overview)
- [Quick Start](#quick-start)
- [Prerequisites](#prerequisites)
- [Project Structure](#project-structure)
- [Modules Overview](#modules-overview)
  - [CPP Module 00](#cpp-module-00---namespaces-classes-member-functions)
  - [CPP Module 01](#cpp-module-01---memory-allocation-pointers-references)
  - [CPP Module 02](#cpp-module-02---ad-hoc-polymorphism-operator-overloading)
  - [CPP Module 03](#cpp-module-03---inheritance)
  - [CPP Module 04](#cpp-module-04---subtype-polymorphism-abstract-classes)
  - [CPP Module 05](#cpp-module-05---repetition-and-exceptions)
  - [CPP Module 06](#cpp-module-06---c-casts)
  - [CPP Module 07](#cpp-module-07---c-templates)
  - [CPP Module 08](#cpp-module-08---templated-containers)
  - [CPP Module 09](#cpp-module-09---real-world-applications)
- [Compilation & Build](#compilation--build)
- [Running Exercises](#running-exercises)
- [Code Standards](#code-standards)
- [Learning Resources](#learning-resources)
- [Progress Tracker](#progress-tracker)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

This repository contains a structured curriculum of C++ programming exercises, progressively building from basic syntax to advanced object-oriented design patterns. Each module focuses on specific concepts with hands-on implementations and real-world applications.

### 🎯 Key Learning Objectives

- **Foundational Concepts**: C++ syntax, I/O streams, and basic control flow
- **Memory Management**: Stack vs heap allocation, pointers, references, and RAII principles
- **Object-Oriented Programming**: Classes, encapsulation, and design patterns
- **Operator Overloading**: Ad-hoc polymorphism and custom type semantics
- **Inheritance Hierarchies**: Single, multiple, and virtual inheritance
- **Polymorphism**: Runtime polymorphism with virtual functions
- **Abstract Classes**: Interface design and contract-based programming
- **Best Practices**: Const correctness, error handling, and code organization

---

## Quick Start

### Clone the Repository
```bash
git clone https://github.com/ElmehdiElkabia/cpp.git
cd cpp
```

### Build an Exercise
```bash
cd cpp00/ex00
make
./megaphone "Hello World"
```

### Clean Build Artifacts
```bash
make clean        # Remove object files
make fclean       # Remove everything
make re           # Clean and rebuild
```

---

## Prerequisites

### System Requirements
- **Operating System**: Linux (Ubuntu 20.04+, Debian 11+) or macOS
- **C++ Compiler**: GCC 4.9+ or Clang 3.8+
- **Build Tools**: GNU Make 4.0+
- **C++ Standard**: C++98 (ISO/IEC 14882:1998)

### Installation

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install build-essential g++ make
```

#### macOS
```bash
xcode-select --install
brew install make
```

#### Verify Installation
```bash
c++ --version
make --version
```

---

## Project Structure

```
cpp/
├── cpp00/          # Namespaces, Classes, Basic Functions
│   ├── ex00/       # Megaphone
│   ├── ex01/       # PhoneBook
│   └── ex02/       # Account Management
├── cpp01/          # Memory, Pointers, References
│   ├── ex00/       # Zombie Allocation
│   ├── ex01/       # Zombie Horde
│   ├── ex02/       # Brain Pointers
│   ├── ex03/       # Weapons System
│   ├── ex04/       # File I/O (sed)
│   └── ex05-06/    # Harl Logger
├── cpp02/          # Operator Overloading
│   ├── ex00/       # Fixed Point (Orthodox Canonical Form)
│   ├── ex01/       # Fixed Point Constructors
│   └── ex02/       # Fixed Point Operators
├── cpp03/          # Inheritance
│   ├── ex00/       # ClapTrap Base
│   ├── ex01/       # ScavTrap Derived
│   ├── ex02/       # Multiple Traps
│   └── ex03/       # Diamond Inheritance
├── cpp04/          # Polymorphism & Abstract Classes
│   ├── ex00/       # Virtual Functions
│   ├── ex01/       # Deep Copy
│   ├── ex02/       # Abstract Classes
│   └── ex03/       # Interfaces & Materia System
├── cpp05/          # Exception Handling
│   ├── ex00/       # Bureaucrat (Basic Exceptions)
│   ├── ex01/       # Form (Exception Propagation)
│   ├── ex02/       # Concrete Forms (Abstract Base)
│   └── ex03/       # Intern (Factory Pattern)
├── cpp06/          # C++ Casts
│   ├── ex00/       # Scalar Converter (static_cast)
│   ├── ex01/       # Serializer (reinterpret_cast)
│   └── ex02/       # Identify Real Type (dynamic_cast)
├── cpp07/          # Templates
│   ├── ex00/       # Template Functions
│   ├── ex01/       # Iterator Templates
│   └── ex02/       # Array Template Class
├── cpp08/          # STL & Templated Containers
│   ├── ex00/       # Easy Find
│   ├── ex01/       # Span Container
│   └── ex02/       # Mutant Stack
├── cpp09/          # Real-World Applications
│   ├── ex00/       # Bitcoin Exchange
│   ├── ex01/       # RPN Calculator
│   └── ex02/       # Merge Insert Sort
├── cpp05-cpp09/    # [Additional modules - Details coming]
└── readme.md       # This file
```

---

## Modules Overview

### CPP Module 00 - Namespaces, Classes, Member Functions

**Concepts**: Classes, member functions, access modifiers, I/O streams, encapsulation

Introduction to C++ object-oriented programming fundamentals, starting with the Standard Namespace and basic class design.

#### 📚 Detailed Exercises:

| Exercise | Topic | Learning Outcomes |
|----------|-------|------------------|
| **ex00** | Megaphone | I/O streams, `std::cout`, string manipulation, character conversion |
| **ex01** | PhoneBook | Class design, member variables, encapsulation, user interaction, formatted output |
| **ex02** | Account | Static members, static functions, const member functions, logging, timestamps |

**Key Concepts:**
- `std::string` and string operations
- `std::cin` / `std::cout` / `std::cerr`
- Public/Private access levels
- Const correctness in member functions
- Static member variables and methods

**Estimated Time**: 4-6 hours

---

### CPP Module 01 - Memory Allocation, Pointers, References

**Concepts**: Dynamic memory, pointers, references, RAII, member function pointers, file I/O

Deep exploration of memory management in C++, focusing on heap vs stack allocation and proper resource management.

#### 📚 Detailed Exercises:

| Exercise | Topic | Learning Outcomes |
|----------|-------|------------------|
| **ex00** | BraiiiiiiinnnzzzZ | Heap allocation, `new`/`delete`, object lifecycle, constructor/destructor |
| **ex01** | Moar brainz! | Dynamic arrays, multiple object allocation, cleanup patterns |
| **ex02** | HI THIS IS BRAIN | Pointers vs references, memory addresses, dereferencing |
| **ex03** | Unnecessary violence | Composition, references vs pointers usage patterns, object ownership |
| **ex04** | Sed is for losers | File I/O (`std::ifstream`, `std::ofstream`), string replacement, command-line args |
| **ex05** | Harl 2.0 | Member function pointers, function dispatch, design patterns |
| **ex06** | Harl filter | Switch statements, log levels, filtering logic |

**Key Concepts:**
- `new` and `delete` operators
- Pointer syntax and dereferencing (`*ptr`, `ptr->member`)
- References and their const semantics (`T&`, `const T&`)
- RAII principle (Resource Acquisition Is Initialization)
- Function pointers and member function pointers
- File stream operations
- Memory leak prevention

**Memory Diagram - Stack vs Heap:**
```
Stack                          Heap
┌─────────────┐               ┌──────────────┐
│ pointer ptr │─────────────→ │ Zombie obj   │
└─────────────┘               └──────────────┘
  (fast, auto-cleanup)    (manual cleanup needed)
```

**Estimated Time**: 6-8 hours

---

### CPP Module 02 - Ad-hoc Polymorphism, Operator Overloading

**Concepts**: Operator overloading, Orthodox Canonical Form (OCF), type conversion, fixed-point arithmetic

Understanding function overloading and operator overloading for creating intuitive user-defined types.

#### 📚 Detailed Exercises:

| Exercise | Topic | Learning Outcomes |
|----------|-------|------------------|
| **ex00** | My First Class in OCF | Default constructor, copy constructor, assignment operator, destructor, fixed-point class |
| **ex01** | Towards useful Fixed | Conversion constructors, conversion functions, insertion operator (`<<`) |
| **ex02** | Now we're talking | Arithmetic operators (`+`, `-`, `*`, `/`), comparison operators, increment/decrement |

**Orthodox Canonical Form (OCF) Pattern:**
```cpp
class Fixed {
public:
    Fixed();                      // Default constructor
    Fixed(const Fixed &src);      // Copy constructor
    ~Fixed();                     // Destructor
    Fixed &operator=(const Fixed &rhs);  // Copy assignment operator
};
```

**Operator Overloading Examples:**
- Arithmetic: `operator+`, `operator-`, `operator*`, `operator/`
- Comparison: `operator<`, `operator>`, `operator==`, etc.
- Increment: `operator++` (prefix & postfix), `operator--`
- Stream: `operator<<` (insertion), `operator>>` (extraction)

**Key Concepts:**
- Overloading operator methods (member vs. non-member)
- const member functions and const parameters
- Fixed-point number representation and precision
- Implicit vs. explicit type conversion
- Return by reference vs. by value

**Estimated Time**: 5-7 hours

---

### CPP Module 03 - Inheritance

**Concepts**: Single inheritance, multiple inheritance, virtual inheritance, constructor chaining, method overriding

Introduction to inheritance hierarchies and solving complex inheritance problems.

#### 📚 Detailed Exercises:

| Exercise | Topic | Learning Outcomes |
|----------|-------|------------------|
| **ex00** | Aaaaand... OPEN! | Base class design, constructor/destructor order, method encapsulation |
| **ex01** | Serena, my love! | Single inheritance, constructor initialization lists, method overriding |
| **ex02** | Repetitive work | Multiple derived classes, inheritance hierarchy design, polymorphic behavior |
| **ex03** | Now it's weird! | Diamond inheritance problem, virtual inheritance, scope resolution |

**Inheritance Hierarchy Example:**
```
        ClapTrap (Base)
        /    |    \
       /     |     \
   ScavTrap  FragTrap  (Intermediate)
       \     /
        \ /
    DiamondTrap (Diamond Problem!)
```

**Virtual Inheritance Syntax:**
```cpp
class ScavTrap : virtual public ClapTrap { /* ... */ };
class FragTrap : virtual public ClapTrap { /* ... */ };
class DiamondTrap : public ScavTrap, public FragTrap { /* ... */ };
```

**Key Concepts:**
- Base class vs. derived class relationships
- `protected` access level for inheritance
- Constructor initialization order and chaining
- Method overriding and `virtual` keyword
- Virtual destructors
- Diamond problem and virtual inheritance
- Scope resolution operator (`::`)`

**Estimated Time**: 6-8 hours

---

### CPP Module 04 - Subtype Polymorphism, Abstract Classes

**Concepts**: Virtual functions, pure virtual functions, abstract classes, polymorphism, interface design

Advanced polymorphism using virtual functions and designing abstract interfaces.

#### 📚 Detailed Exercises:

| Exercise | Topic | Learning Outcomes |
|----------|-------|------------------|
| **ex00** | Polymorphism | Virtual functions, runtime polymorphism, virtual destructors, polymorphic containers |
| **ex01** | I don't want to set the world on fire | Deep copy semantics, copy constructor with polymorphic classes, memory management |
| **ex02** | Abstract class | Pure virtual functions, abstract base classes, preventing instantiation |
| **ex03** | Interface & recap | Multiple abstract interfaces, complex polymorphic systems, design patterns |

**Virtual Functions & Polymorphism:**
```cpp
class Animal {
public:
    virtual void makeSound() = 0;  // Pure virtual
    virtual ~Animal() {}            // Virtual destructor!
};

class Dog : public Animal {
public:
    void makeSound() override { std::cout << "Woof!" << std::endl; }
};

// Runtime polymorphism
Animal *animal = new Dog();
animal->makeSound();  // Calls Dog::makeSound()
```

**Abstract Classes Pattern:**
```cpp
class Animal {  // Abstract base class
private:
    std::string type;
protected:
    Animal(const std::string &type) : type(type) {}
public:
    virtual void eat() = 0;
    virtual ~Animal() {}
};
```

**Key Concepts:**
- `virtual` keyword for late binding
- Pure virtual functions (`= 0`)
- Abstract classes and instantiation rules
- Override specifier (C++11)
- Virtual destructors importance
- Polymorphic containers (`vector<Animal*>`)
- Interface-based design
- Liskov Substitution Principle

**Estimated Time**: 6-8 hours

---

### CPP Module 05 - Repetition and Exceptions

**Concepts**: Exception handling, try-catch-throw, custom exceptions, resource management

Introduction to exception handling in C++ and error management patterns.

#### 📚 Detailed Exercises:

| Exercise | Topic | Learning Outcomes |
|----------|-------|------------------|
| **ex00** | Bureaucrat | Basic exception throwing, custom exception classes, inheritance from `std::exception` |
| **ex01** | Form | Multiple exception types, form execution, exception propagation |
| **ex02** | Concrete forms | Abstract base forms, form signing logic, exception hierarchy |
| **ex03** | Intern | Factory pattern, form creation, exception handling in factories |

**Exception Hierarchy Pattern:**
```cpp
class GradeTooHighException : public std::exception {
public:
    virtual const char *what() const throw() {
        return "Grade is too high";
    }
};

// Usage
try {
    bureaucrat.executeForm(form);
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
}
```

**Key Concepts:**
- `try`, `catch`, `throw` keywords
- Exception specifications (`throw()`)
- `std::exception` base class
- RAII with exceptions
- Exception safety guarantees
- Catching by reference
- Multiple catch blocks
- Exception hierarchy design

**Estimated Time**: 5-7 hours

---

### CPP Module 06 - C++ Casts

**Concepts**: Type casting, static_cast, dynamic_cast, reinterpret_cast, const_cast, RTTI

Understanding the four types of C++ casts and when to use each one.

#### 📚 Detailed Exercises:

| Exercise | Topic | Learning Outcomes |
|----------|-------|------------------|
| **ex00** | Scalar Conversion | `static_cast` usage, type conversions (int to float, double to int), string parsing |
| **ex01** | Serialization | `reinterpret_cast`, data pointer manipulation, pointer arithmetic |
| **ex02** | Identify real type | `dynamic_cast`, RTTI (Run-Time Type Information), inheritance checking |

**C++ Casts Comparison:**
```cpp
// static_cast: Compile-time checked, explicit conversions
int i = static_cast<int>(3.14);
Base *ptr = static_cast<Derived*>(base);

// dynamic_cast: Runtime type checking, safe downcasting
Derived *ptr = dynamic_cast<Derived*>(base);  // Returns NULL if invalid
if (ptr == NULL) { /* Handle error */ }

// reinterpret_cast: Dangerous, pointer reinterpretation
void *raw = reinterpret_cast<void*>(pointer);
int *ptr = reinterpret_cast<int*>(address);

// const_cast: Remove/add const qualifier
void func(const int *ptr);
int *mutable_ptr = const_cast<int*>(ptr);
```

**Key Concepts:**
- `static_cast` for implicit conversions
- `dynamic_cast` for safe polymorphic downcasting
- `reinterpret_cast` for low-level operations
- `const_cast` for const correctness
- RTTI and `typeid()`
- When to use each cast type
- Avoiding C-style casts

**Estimated Time**: 4-6 hours

---

### CPP Module 07 - C++ Templates

**Concepts**: Template functions, template classes, template specialization, template instantiation

Introduction to generic programming using C++ templates.

#### 📚 Detailed Exercises:

| Exercise | Topic | Learning Outcomes |
|----------|-------|------------------|
| **ex00** | Template function | Function templates, generic swap, template parameters, template instantiation |
| **ex01** | Iterator template | Function templates with iterators, template constraints, generic algorithms |
| **ex02** | Array template | Class templates, template specialization, `.hpp` file organization, template methods |

**Template Function Example:**
```cpp
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}
```

**Template Class Example:**
```cpp
template <typename T>
class Array {
private:
    T *_data;
    unsigned int _size;
public:
    Array(unsigned int size) : _size(size) {
        _data = new T[size];
    }
    T &operator[](unsigned int index) {
        return _data[index];
    }
    ~Array() { delete[] _data; }
};
```

**Key Concepts:**
- Template parameters and instantiation
- Template function specialization
- Template class implementation
- `.hpp` file organization (everything in header)
- Template constraints
- Non-type template parameters
- Template member functions
- Avoiding code duplication

**Estimated Time**: 6-8 hours

---

### CPP Module 08 - Templated Containers, Iterators, Algorithms

**Concepts**: STL containers, iterators, algorithms, template containers, function objects

Working with Standard Template Library (STL) and creating custom templated containers.

#### 📚 Detailed Exercises:

| Exercise | Topic | Learning Outcomes |
|----------|-------|------------------|
| **ex00** | Easy find | `std::vector`, iterators, `std::find` algorithm, templates with containers |
| **ex01** | Span | Custom `Span` container, storing integers, `shortest span` calculation, exception handling |
| **ex02** | Mutant stack | Stack adaptation, iterator implementation, container wrapping, template inheritance |

**STL Containers & Iterators:**
```cpp
#include <vector>
#include <algorithm>

std::vector<int> vec;
vec.push_back(42);

// Using iterators
std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 42);
if (it != vec.end()) {
    std::cout << "Found: " << *it << std::endl;
}

// Range-based operations
for (int value : vec) {
    std::cout << value << std::endl;
}
```

**Custom Container with Iterators:**
```cpp
template <typename T>
class Span {
private:
    std::vector<T> _data;
    unsigned int _size;
public:
    Span(unsigned int n) : _size(n) {}
    void addNumber(T n) { _data.push_back(n); }
    int shortestSpan() const;
    int longestSpan() const;
};
```

**Key Concepts:**
- `std::vector`, `std::stack`, `std::list`
- Iterator types (input, output, forward, bidirectional, random-access)
- `begin()`, `end()`, iterating
- STL algorithms: `std::find`, `std::sort`, `std::copy`
- Custom iterators
- Template container adaptation
- Exception-safe container operations
- Container performance characteristics

**Estimated Time**: 7-9 hours

---

### CPP Module 09 - Real-World Applications

**Concepts**: Advanced templates, file parsing, data structures, algorithm implementation, optimization

Applying all learned concepts to build real-world applications.

#### 📚 Detailed Exercises:

| Exercise | Topic | Learning Outcomes |
|----------|-------|------------------|
| **ex00** | Bitcoin Exchange | File parsing (CSV), `std::map` usage, data validation, error handling with files |
| **ex01** | RPN Calculator | Stack-based computation, Reverse Polish Notation, string parsing, expression evaluation |
| **ex02** | Merge Insert Sort | Custom sorting algorithm, `std::deque` and `std::list`, performance optimization, benchmarking |

**File Parsing & Data Processing:**
```cpp
// Bitcoin Exchange
std::map<std::string, float> rates;
std::ifstream file("data.csv");
std::string line;

while (std::getline(file, line)) {
    std::string date;
    float price;
    // Parse CSV and populate map
}

// Process input
std::ifstream input("input.txt");
while (std::getline(input, line)) {
    std::string date;
    float value;
    // Lookup rate and calculate exchange
}
```

**Reverse Polish Notation Calculator:**
```cpp
// Example: 1 2 + 3 * = (1 + 2) * 3 = 9
class RPN {
private:
    std::stack<float> _stack;
public:
    void evaluate(std::string &expression);
    float getResult() const;
    bool isOperator(std::string &token) const;
    float apply(float a, float b, std::string &op) const;
};
```

**Merge Insert Sort:**
```cpp
// Optimized sorting using merge sort + insertion sort
template <typename Container>
void mergeInsertSort(Container &container);

// Performance: O(n log n) worst case
// Uses deque for efficient operations
// Compares performance between std::deque and std::list
```

**Key Concepts:**
- File I/O with error checking
- CSV parsing and data validation
- `std::map` and associative containers
- Stack-based algorithms
- Proper error messages and exit codes
- Performance optimization and profiling
- Algorithm complexity analysis
- Real-world constraint handling
- Data structure selection for performance

**Estimated Time**: 8-10 hours

---

## Compilation & Build

### Build System: GNU Make

Each exercise includes a `Makefile` with these targets:

```bash
make              # Compile the project (default target)
make clean        # Remove object files (.o)
make fclean       # Remove object files + executable
make re           # Clean and rebuild
```

### Compilation Standards

- **C++ Standard**: C++98 (ISO/IEC 14882:1998)
- **Compiler**: `c++` (usually g++ or clang++)
- **Flags**:
  - `-Wall`: Enable all common warnings
  - `-Wextra`: Additional warnings
  - `-Werror`: Treat warnings as errors
  - `-std=c++98`: Use C++98 standard

### Makefile Example

```makefile
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = phonebook
SRCS = PhoneBook.cpp Contact.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
```

---

## Running Exercises

### Quick Start Guide

#### Build and Run CPP00 - ex00 (Megaphone)
```bash
cd cpp00/ex00
make
./megaphone "Hello World"
# Output: HELLO WORLD
```

#### Build and Run CPP01 - ex00 (Zombie)
```bash
cd cpp01/ex00
make
./zombie
```

#### Build and Run CPP02 - ex02 (Fixed Point)
```bash
cd cpp02/ex02
make
./fixed
```

#### Build and Run CPP03 - ex03 (Diamond Trap)
```bash
cd cpp03/ex03
make
./diamondtrap
```

#### Build and Run CPP04 - ex03 (Materia System)
```bash
cd cpp04/ex03
make
./materia
```

### Build Troubleshooting

**Problem**: `c++: command not found`
```bash
# Solution: Install build tools
sudo apt-get install build-essential g++
```

**Problem**: `-std=c++98` not recognized
```bash
# Try alternative flag
-std=c++03  # or use -std=gnu++98
```

**Problem**: Undefined reference errors
```bash
# Ensure all .cpp files are in SRCS
# Check Makefile compilation order
make fclean && make -B
```

---

## Code Standards

### Naming Conventions

| Type | Convention | Example |
|------|-----------|---------|
| Classes | PascalCase | `PhoneBook`, `ClapTrap`, `Animal` |
| Functions | camelCase | `makeSound()`, `takeDamage()` |
| Variables | snake_case or camelCase | `phoneBook`, `hit_points` |
| Constants | UPPER_SNAKE_CASE | `MAX_CONTACTS`, `RAW_BITS` |
| Member vars | camelCase with prefix | `_value`, `_index` |

### Const Correctness

```cpp
// Good: Const on both sides
const int *ptr1;           // Pointer to const int
int *const ptr2;           // Const pointer to int
const int *const ptr3;     // Const pointer to const int

// Good: Const member function
int getValue() const { return this->_value; }

// Good: Const parameters
void setName(const std::string &name) { /* ... */ }
```

### Header Guards

```cpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook { /* ... */ };

#endif
```

### Banned Functions & Practices

❌ **Avoid:**
- `printf()` - Use `std::cout` instead
- `scanf()` - Use `std::cin` instead
- `strlen()` - Use `std::string::length()` instead
- Raw arrays in modern code - Use containers when possible

✅ **Use Instead:**
- `std::cout` / `std::cin` for I/O
- `std::string` for string manipulation
- `new` / `delete` for dynamic memory
- `std::vector` for dynamic arrays (in later modules)

---

## Learning Resources

### 📖 Documentation & References
- **C++ Reference**: https://en.cppreference.com/
- **C++ Standard**: https://isocpp.org/std/the-standard
- **Learn C++**: https://www.learncpp.com/

### 🎓 Advanced Topics
- **C++ Core Guidelines**: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
- **Modern C++ Practices**: https://github.com/AnthonyCalandra/modern-cpp-features
- **RAII Pattern**: https://en.cppreference.com/w/cpp/language/raii

### 📚 Recommended Books
- *C++ Primer* by Stanley B. Lippman
- *Effective C++* by Scott Meyers
- *C++ How to Program* by Deitel & Deitel

### 🔧 Development Tools
- **Compiler Explorer**: https://godbolt.org/ (Visualize compilation)
- **CPPInsights**: https://cppinsights.io/ (Understand generated code)
- **Valgrind**: Memory leak detection tool
- **GDB**: GNU Debugger

---

## Progress Tracker

Track your progress through the modules:

```
✅ CPP00 - Namespaces, Classes, Member Functions
   ✅ ex00 - Megaphone
   ✅ ex01 - PhoneBook
   ✅ ex02 - Account

✅ CPP01 - Memory Allocation, Pointers, References
   ✅ ex00 - Zombie Allocation
   ✅ ex01 - Zombie Horde
   ✅ ex02 - Brain Pointers
   ✅ ex03 - Weapons
   ✅ ex04 - File I/O
   ✅ ex05 - Harl Logger
   ✅ ex06 - Harl Filter

✅ CPP02 - Operator Overloading
   ✅ ex00 - Orthodox Canonical Form
   ✅ ex01 - Fixed Constructors
   ✅ ex02 - Fixed Operators

✅ CPP03 - Inheritance
   ✅ ex00 - ClapTrap
   ✅ ex01 - ScavTrap
   ✅ ex02 - Multiple Inheritance
   ✅ ex03 - Diamond Inheritance

✅ CPP04 - Polymorphism & Abstract Classes
   ✅ ex00 - Virtual Functions
   ✅ ex01 - Deep Copy
   ✅ ex02 - Abstract Classes
   ✅ ex03 - Interfaces & Materia

✅ CPP05 - Repetition and Exceptions
   ✅ ex00 - Bureaucrat (Basic Exceptions)
   ✅ ex01 - Form (Exception Propagation)
   ✅ ex02 - Concrete Forms (Abstract Base)
   ✅ ex03 - Intern (Factory Pattern)

✅ CPP06 - C++ Casts
   ✅ ex00 - Scalar Converter (static_cast)
   ✅ ex01 - Serializer (reinterpret_cast)
   ✅ ex02 - Identify Real Type (dynamic_cast)

✅ CPP07 - C++ Templates
   ✅ ex00 - Template Functions
   ✅ ex01 - Iterator Templates
   ✅ ex02 - Array Template Class

✅ CPP08 - Templated Containers
   ✅ ex00 - Easy Find
   ✅ ex01 - Span Container
   ✅ ex02 - Mutant Stack

✅ CPP09 - Real-World Applications
   ✅ ex00 - Bitcoin Exchange
   ✅ ex01 - RPN Calculator
   ✅ ex02 - Merge Insert Sort

🎓 ALL MODULES COMPLETED - Ready for advanced C++ challenges!
```

---

## Module Difficulty & Progression

| Module | Difficulty | Focus | Prerequisites |
|--------|-----------|-------|--------------|
| CPP00 | ⭐ Beginner | Basics | None |
| CPP01 | ⭐ Beginner | Memory | CPP00 |
| CPP02 | ⭐⭐ Intermediate | Operators | CPP00-01 |
| CPP03 | ⭐⭐ Intermediate | Inheritance | CPP00-02 |
| CPP04 | ⭐⭐ Intermediate | Polymorphism | CPP00-03 |
| CPP05 | ⭐⭐⭐ Advanced | Exceptions | CPP00-04 |
| CPP06 | ⭐⭐⭐ Advanced | Casting | CPP00-05 |
| CPP07 | ⭐⭐⭐ Advanced | Templates | CPP00-06 |
| CPP08 | ⭐⭐⭐⭐ Expert | STL | CPP00-07 |
| CPP09 | ⭐⭐⭐⭐ Expert | Real-World | CPP00-08 |

### Time Investment Estimate

| Modules | Total Hours | Per Day |
|---------|-----------|---------|
| CPP00-01 | 10-14h | 2-3 hours/day = 5-7 days |
| CPP02-04 | 17-23h | 2-3 hours/day = 7-11 days |
| CPP05-06 | 9-13h | 2-3 hours/day = 4-6 days |
| CPP07-08 | 13-17h | 3-4 hours/day = 4-5 days |
| CPP09 | 8-10h | 3-4 hours/day = 2-3 days |
| **TOTAL** | **57-77 hours** | ~25-30 days (3-4 weeks) |

---

## Contributing

### Guidelines for Improvements

1. **Bug Reports**: Submit issues with:
   - Compiler version and OS
   - Error messages (full output)
   - Steps to reproduce

2. **Improvements**: 
   - Ensure code follows C++98 standard
   - Test on Linux and macOS
   - Add comments for complex logic
   - Update relevant documentation

3. **Pull Requests**:
   - One feature/fix per PR
   - Clear commit messages
   - Reference any related issues

---

## Code Quality Checklist

Before submitting code, verify:

- [ ] Compiles with `-Wall -Wextra -Werror -std=c++98`
- [ ] No memory leaks (check with valgrind)
- [ ] No undefined behavior
- [ ] Const correctness maintained
- [ ] Header guards in place
- [ ] Consistent naming conventions
- [ ] Proper encapsulation (private/public)
- [ ] Orthodox Canonical Form where required
- [ ] Comments for complex logic
- [ ] No compiler warnings

---

## Memory Management Best Practices

### RAII Pattern
```cpp
class Resource {
private:
    int *_data;
public:
    Resource() { _data = new int[100]; }      // Acquire
    ~Resource() { delete[] _data; }           // Release
    Resource(const Resource &) = delete;      // No copy
};
```

### Pointer Cleanup
```cpp
// Always pair new with delete
int *ptr = new int(42);
delete ptr;
ptr = NULL;  // Prevent dangling pointer

// Arrays need delete[]
int *arr = new int[10];
delete[] arr;  // Not delete!
```

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### Attribution

Created as part of the C++ learning curriculum.
**Author**: ElmehdiElkabia  
**Last Updated**: May 2026  
**Status**: Active Development

---

## Additional Resources

### Quick Reference Cards

#### Constructor/Destructor Order
```
1. Base class constructor
2. Member object constructors (in declaration order)
3. Derived class constructor
...
4. Derived class destructor
5. Member object destructors (reverse order)
6. Base class destructor
```

#### Function Call Resolution Order
```
1. Exact match
2. Promotion (char → int)
3. Standard conversion (int → double)
4. User-defined conversion
5. Ellipsis (...)
```

---

**Happy Coding!** 🚀

For questions or suggestions, open an issue or reach out to the maintainers.

---

## 📝 Notes