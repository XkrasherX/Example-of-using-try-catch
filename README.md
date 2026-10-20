# 📦 Custom Deque with Windows Forms (C++/CLI)

<p align="center">
  <img src="https://img.shields.io/badge/C++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++"/>
  <img src="https://img.shields.io/badge/.NET-512BD4?style=for-the-badge&logo=dotnet&logoColor=white" alt=".NET"/>
  <img src="https://img.shields.io/badge/Visual%20Studio-5C2D91?style=for-the-badge&logo=visual-studio&logoColor=white" alt="Visual Studio"/>
  <img src="https://img.shields.io/badge/OOP-Operator%20Overloading-orange?style=for-the-badge" alt="OOP and Operator Overloading"/>
  <img src="https://img.shields.io/badge/Windows%20Forms-0078D4?style=for-the-badge&logo=windows&logoColor=white" alt="Windows Forms"/>
</p>

---

## 📖 Project Overview

This application is a practical demonstration of **Object-Oriented Programming (OOP)** in **C++/CLI** using Windows Forms. It implements a custom double-ended queue, `CDeque`, backed by a dynamically allocated array of `double` values.

The application provides a graphical interface for adding and removing elements at either end of the deque, inspecting its properties, clearing its contents, and testing overloaded operators. The class also demonstrates copy and move semantics, stream input/output operators, and custom exception handling.

---

## ✨ Features

- ⬅️➡️ Add elements to the left or right side of the deque.
- 🗑️ Remove elements from either end.
- 📏 Get the number of elements and check whether the deque is empty.
- 📊 Calculate the average of the stored values.
- 🧹 Clear the entire deque.
- ➕➖ Perform element-by-element addition and subtraction between deques of equal size.
- ✖️ Multiply every element by a scalar.
- 📋 Demonstrate copy assignment and move assignment.
- 🔄 Demonstrate stream insertion (`<<`) and extraction (`>>`) operators.
- ⚠️ Handle errors such as invalid input, empty-deque operations, size mismatches, and memory-allocation failures.

---

## 🕹️ Visual Guide & Usage

### 1️⃣ Step 1: Add Elements

Enter a numeric value in the **Enter value** field. Use the left arrow (`<-`) to add it to the beginning of the deque or the right arrow (`->`) to add it to the end.

The current deque is displayed in the result area after a successful operation.

### 2️⃣ Step 2: Choose an Operation

Select an operation from the **Select Option** dropdown and click **Get Result** to execute it.

Available options include `GetSize`, `GetAvg`, `IsEmpty`, `ClearAll`, `operator+`, `operator-`, `operator*`, copy assignment, move assignment, stream operators, deletion from either end, and a memory-allocation test.

### 3️⃣ Step 3: View Results and Errors

The application displays the current deque in the result area and reports handled errors in the error label. Some operator demonstrations (`operator+`, `operator-`, copy assignment, and stream output) write their results to the Visual Studio debug/console output rather than displaying the full result in the form.

### 4️⃣ Step 4: Test Input and Edge Cases

Try calculating the average of an empty deque, removing an element from an empty deque, or entering an invalid value to see the error-handling behavior.

For the stream extraction (`operator>>`) option, enter values in this format:

```text
size value1 value2 value3 ...
```

For example:

```text
3 1.5 2.0 4.5
```

---

## 🧠 Implementation Details

### `CDeque`

The `CDeque` class manages a dynamic array and its current size. It includes:

- Default and size/value constructors.
- Copy constructor and move constructor.
- Copy assignment and move assignment operators.
- Methods for inserting and removing elements at both ends.
- Size, emptiness, average, and clear operations.
- Overloaded arithmetic and stream operators.

### Custom Exception Handling

`MyError.h` defines a common `MyErrorClass` exception and specialized exceptions for memory allocation, empty-deque operations, average calculation, mismatched sizes, and input/output errors.

---

## 🛠️ Tech Stack

- **Language:** C++/CLI and native C++
- **GUI Framework:** Windows Forms
- **Data Storage:** Dynamically allocated array (`double*`)
- **Libraries:** C++ Standard Library (`iostream`, `sstream`, `exception`)
- **IDE:** Visual Studio

---

## 📂 Key Project Files

- `CDeque.h` — Declaration of the `CDeque` class, constructors, methods, and overloaded operators.
- `CDeque.cpp` — Implementations of deque operations and arithmetic/stream operators.
- `MyError.h` — Custom exception classes used for error reporting.
- `MyForm.h` — Windows Forms interface, event handlers, and integration with `CDeque`.
- `MyForm.cpp` — Application entry point and Windows Forms startup.

---

## 🚀 How to Run

1. Clone your repository:

   ```bash
   git clone https://github.com/XkrasherX/Example-of-using-try-catch.git
   ```

2. Open the solution (`.sln`) in **Visual Studio**.
3. Ensure that the project is configured for **C++/CLI** and Windows Forms.
4. Build the solution and run the application.
5. Enter values, add elements to the deque, and select operations from the dropdown.

---

## 👤 Author

**XkrasherX**

<p>
  <a href="https://github.com/XkrasherX">
    <img src="https://img.shields.io/badge/GitHub-gray?style=for-the-badge&logo=github" alt="GitHub"/>
  </a>
</p>

---

<p align="center">
  ✨ <i>If you found this project helpful for learning data structures, operator overloading, and C++/CLI, feel free to give it a star!</i> ✨
</p>
