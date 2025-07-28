# 🚌 ALSA Bus Management System 🚌
## 📌 Overview 

This C++ program simulates a bus management system for ALSA City Agadir, a public transportation service in Morocco.
The system allows users to :

- Learn about ALSA's mission, services, and environmental commitment.
- Apply for student bus cards.
- Shop for bus cards and recharges.
- View receipts for purchased cards.

## 🚀 Features
### 1. About Us Section

- Displays detailed information about ALSA's :
    - Mission and operations.
    - Service network coverage.
    - Environmental initiatives.

### 2. Shopping System

 - Allows registered students to :
    - Purchase bus cards.
    - Recharge existing cards.
    - View total prices.

### 4. Receipt Generation

- Generates detailed receipts for purchases including :
    - Payment information.
    - Card validity dates.
    - Price breakdown.
    - Transaction timestamp.

### 5. Security Features
- CNI (national ID) input is masked with asterisks.
- Input validation for required fields.

## 🔧 Technical Details 
### 1. Dependencies

- `Windows.h` (for console manipulation).
- `iostream`, `string`, `vector` (standard C++ libraries).
- `conio.h` (for getch() function).
- `time.h`(for timestamp functionality).
- `iomanip` (for output formatting).

### 2. Key Functions 
- `gotoxy()` : Positions the console cursor.
- `Time()`: Gets and formats current system time.
- Student data management using vectors.
- Formatted receipt generation with random transaction numbers.

### 3. Usage 
1. Compile the program using a C++ compiler (tested on Windows).
2. Run the executable
3. Use the menu to navigate between options :
  - 1 : About ALSA.
  - 2 : Apply for student card.
  - 3 : Shop for cards/recharges.
  - 4 : View receipts.
  - 5 : Exit system.

<mark> ## 📝 Notes 📝 </mark> 
- The program is designed for Windows consoles.
- CNI numbers are limited to 8 digits in this simulation.
- All monetary values are in Moroccan Dirhams (DH).
- The system displays real-time timestamps for transactions.
