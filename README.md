# CPP Module 06

This module is part of the 42 School C++ curriculum and is entirely focused on understanding and practically applying the different types of **Casts** in the C++98 standard. The goal is to replace the generic casts inherited from C with the specific, safer casts provided by C++.

## 🎯 Concepts Overview

In C++98, there are 4 main casts (this module focuses on the first 3):
1. **`static_cast`**: Conversion of related and scalar types (e.g., `float` to `int`). The conversion is performed at compile-time.
2. **`reinterpret_cast`**: Conversion of unrelated types (e.g., pointer to integer). It deals directly with the raw bits in memory. Extremely powerful, yet dangerous.
3. **`dynamic_cast`**: Safe downcasting conversion (from a Parent class to a Child class) at run-time. It requires the class to be polymorphic (having at least one `virtual` method).
4. **`const_cast`**: (Not covered in this module) Used to add or remove the `const` qualifier from a variable.

---

## 🛠️ Exercises

### Ex00: Scalar Converter (`static_cast`)
A program that takes a string representation of a C++ literal (`char`, `int`, `float`, or `double`) as a parameter, converts it to its actual type, and then uses `static_cast` to display it in the other three scalar data formats.
- **Challenges:** 
  - Parsing the string to identify the hidden primitive type.
  - Handling mathematical pseudo-literals (`-inf`, `+inf`, `nan`, `-inff`, `+inff`, `nanf`).
  - Handling overflows and non-displayable characters from the ASCII table.
- **Usage:** `./convert <literal>` (e.g., `./convert 42.0f`)

### Ex01: Serialization (`reinterpret_cast`)
This exercise demonstrates how to traffic memory addresses disguised as integers, simulating a basic serialization process used in APIs and low-level systems.
- **Challenges:** 
  - Using `reinterpret_cast` to convert a structure pointer (`Data*`) into a safe unsigned integer type (`uintptr_t`) and doing the reverse path without data loss (deserialization).
- **Usage:** `./serialize`

### Ex02: Identify real type (`dynamic_cast`)
A Run-Time Type Information (RTTI) identification system built strictly without using the `<typeinfo>` library.
- **Challenges:**
  - Dynamically discovering the true class (`A`, `B`, or `C`) of a randomly instantiated object hidden behind a parent class pointer (`Base*`).
  - Handling `dynamic_cast` failures on **Pointers**: safely checking for a `NULL` return.
  - Handling `dynamic_cast` failures on **References**: dealing with the `std::bad_cast` exception by implementing `try/catch` blocks to prevent the program from crashing.
- **Usage:** `./identify`

---

## ⚙️ How to compile and run

All exercises have their own `Makefile` and follow the strict compilation rules of 42 School.

To compile any of the exercises, navigate to the corresponding folder and run:
```bash
make