# 🚌 ALSA — Agadir Public Transport Management System

A console-based C++ application for managing student transport cards for **ALSA City Agadir**,
covering card registration, purchasing, and receipt generation.

---

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Build & Run](#build--run)
- [Usage](#usage)
- [Data Structures](#data-structures)
- [Color Theme](#color-theme)

---

## About

**ALSA City Agadir** is a public transport operator serving the Greater Agadir region.
This system allows agency staff to:

- Present company information to customers
- Register student transport card requests
- Process card purchases (Inside / Outside city pricing)
- Print receipts with automatically computed card validity dates

> Network: 45 lines · 220 buses · 700 employees · ~55,000 km/day
> Coverage: Tamri (North) · Ouled Teima (East) · Massa 67km (South)

---

## Features

| # | Feature | Description |
|:---:|:---------:|:-------------:|
| 1 | **About Us** | Displays company mission, services, and environmental commitments |
| 2 | **Student Card** | Registers a new student with school level, personal info, CNI, and preferred agency |
| 3 | **Shopping Cart** | Authenticates a registered student and processes a card purchase |
| 4 | **Receipt Card** | Authenticates a student and prints a full receipt with validity dates |

### Card Pricing
| Zone | Price |
|:------:|:-------:|
| Inside city  | **60.00 DH** |
| Outside city | **80.00 DH** |

### Card Validity
The card is valid from the **start date** entered at purchase until the **last day of the following month**.

Examples:
| Start Date | End Date |
|:------------:|:----------:|
| 22/05/2026 | 30/06/2026 |
| 31/01/2026 | 28/02/2026 |
| 15/12/2026 | 31/01/2027 |

Leap years are handled automatically (e.g. 2024 → Feb 29).

---

## Project Structure

```
ALSA/
├── main.cpp      — All class methods + main() entry point
├── utils.h       — Class declaration (ALSA), structs, color macros, utility prototypes
└── utils.cpp     — Utility function implementations (gotoxy, Time, get_ch, etc.)
```

### Key Classes & Structs

#### `class ALSA` (in `utils.h`)
```
├── struct Student
│   ├── first_name, last_name, CNI
│   ├── etablish, school_level
│   ├── phone_no, email, dt_of_birth
│   ├── province, city, adress, gender
│   └── agency, date
│
└── struct Shop
    ├── start_day, start_month, start_year
    └── price
```

---

## Requirements

| Tool | Version |
|:------:|:---------:|
| C++ Compiler | C++17 or later |
| OS | Windows or Linux/macOS |

### Dependencies
- **Windows:** `<windows.h>`, `<conio.h>` (built-in)
- **Linux/macOS:** `<termios.h>`, `<unistd.h>` (built-in)

No external libraries required.

---

## Build & Run

### Linux / macOS
```bash
g++ -o ALSA main.cpp utils.cpp -std=c++17
./ALSA
```

### Windows (MinGW)
```bash
g++ -o ALSA.exe main.cpp utils.cpp -std=c++17
ALSA.exe
```

### Windows (MSVC)
```bash
cl /std:c++17 main.cpp utils.cpp /Fe:ALSA.exe
ALSA.exe
```

---

## Usage

On launch the main menu appears:

```
─────────────────────────────────────
  1.  About Us.
  2.  Student Card.
  3.  Shopping Cart.
  4.  Receipt Card.
  5.  Exit.
─────────────────────────────────────
Select Option :
```

### Typical workflow

```
1. Student Card    → Register the student (fills the students list)
2. Shopping Cart   → Authenticate student → choose Inside/Outside → card saved
3. Receipt Card    → Authenticate student → receipt printed with dates & price
```

> ⚠️ Steps must be followed in order — Shopping Cart and Receipt require
> a student to be registered first.

### CNI Input
The CNI field masks input with `*` for privacy.
The **first character** is shown in plain text; the rest appear as `*`.
Press **Enter** to confirm.

### Supported School Levels & Establishments

| Level | Example Establishments |
|:-------:|:----------------------:|
| Primaire | E 20 Aout, E 2 Mars, E 18 NOVEMBRE, E ADRAR, E AGDAL |
| College | C AL AMANE, C ALLAL EL FASSI, C AL FIRDAOUS, C ATLAS |
| Lycee | L AL FADILA, L AL QODS, L AL KHAWARIZMI, L IBN SINA |
| University | ENAA, ENSA, FS, ENCG, EST, BTS, CMC |
| OFPPT | ISTA AGADIR, ISTA INZGAN, ISTA ASSAKA, CMC |

Type `Another` at any level to enter a custom establishment name.

### Agency Locations
```
- WILAYA VALLEE
- PLACE SALAM D'AGADIR
- PLACE MASSIRA D'INZGANE
```

---

## Data Structures

### Student
```cpp
struct Student {
    string first_name, last_name, CNI;
    string school_level, etablish;
    string phone_no, email, dt_of_birth;
    string gender, province, city, adress;
    string agency, date;
};
```

### Shop
```cpp
struct Shop {
    int   start_day, start_month, start_year;
    float price;
};
```
> End date is computed dynamically at receipt time — not stored.

---

## Color Theme

| Color | ANSI Code | Used For |
|:-------:|:-----------:|:----------:|
| `WHITE` | `\033[1;37m` | General text |
| `CYAN` | `\033[1;36m` | Time display, menu numbers |
| `BLUE` | `\033[1;34m` | Labels, section headers |
| `BLUE_REV` | `\033[1;7;34m` | Section title banners |
| `GREEN` | `\033[1;32m` | Success messages, start date |
| `RED` | `\033[1;31m` | Required field markers, errors, end date |
| `GRAY` | `\033[1;30m` | Pause prompt |
| `DEFAULT` | `\033[0m` | Reset to terminal default |

---

## Author

Developed for **ALSA City Agadir** — Agadir, Morocco.
