#ifndef UTILS_H 
#define UTILS_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <limits>
#include <cstring>
#include <iomanip>
#include <vector>
#include <ctime>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
    #include <cstdlib>
#endif

// ── Color codes ──────────────────────────────────────────────
#define RED      "\033[1;31m"
#define GREEN    "\033[1;32m"
#define ORANGE   "\033[1;33m"
#define BLUE     "\033[1;34m"
#define BLUE_REV "\033[1;7;34m"
#define CYAN     "\033[1;36m"
#define WHITE    "\033[1;37m"
#define GRAY     "\033[1;30m"
#define DEFAULT  "\033[0m"

using namespace std;

// ── ALSA class ─────────────────────────────────────────────
class ALSA {
private:
    struct Student {
        string first_name , last_name , CNI;
        string school_level, etablish;
        string phone_no;
        string dt_of_birth;
        string gender;
        string province, city, adress;
        string email;
        string agency, date;
    };
    vector<Student> students;

    struct Shop {
        int start_day , start_month , start_year;
        int end_day = 1 , end_month , end_year;
        float price ;
    };
    vector<Shop> shops;

public:
    void about_us();
    void student_card();
    void shop_card();
    void receipt_card();
};

// ── Utility functions ─────────────────────────────────────────
void   gotoxy(int x, int y);
void   Pause();
string Time();
char   _getch();        // renamed from _getch to avoid Win32 conflict
void   Sleep_ms(int milliseconds);  // renamed from Sleep to avoid Win32 conflict
void   clear_screen();

#endif

