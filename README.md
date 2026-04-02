# C++ Library Management System

This project was developed as an academic exercise to demonstrate the practical application of File I/O and Memory Management in C++.

## Overview

The Library Manager is a console-based CRUD (Create, Read, Update, Delete) application.
It allows users to manage a collection of books with persistent local storage.
It serializes the `Book` structures directly into a binary database file (`library_db.dat`),
ensuring data is saved and loaded automatically between sessions.

## Features
* **Add/Remove Records:** Dynamically add new books or remove existing ones using index-based selection.
* **Persistent Storage:** Uses C++ `fstream` in binary mode to securely save and load the book catalog.
* **Interactive UI:** Features a clear, loop-based terminal menu that clears the screen between actions for better UX.

## Implementation Details
* **Language:** C++
* **Concepts:** Binary File I/O, Structs, Pointer Casting.

## How to Run

To run any of these files, you will need a C++ compiler installed on your system (such as GCC or Clang). 

1. Clone the repository to your local machine:
```
git clone https://github.com/mieentus/library-manager.git
cd library-manager
```
Compile the source file

`g++ library_manager.cpp -o library_manager`

Run the compiled executable:

`./library_manager`
