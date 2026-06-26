#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

void gotoxy(int x, int y) {
#ifdef _WIN32
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
#else
    cout << "\033[" << y + 1 << ";" << x + 1 << "H";
#endif
}

void Pause() {
#ifdef _WIN32
    system("pause");
#else
    cout << GRAY << "Press ENTER to continue...";
    // cin.ignore();
    cin.get();
#endif
}

string Time() {
    time_t now = time(NULL);
    tm *local = localtime(&now);
    string t = asctime(local);
    // asctime adds a trailing newline — remove it
    if (!t.empty() && t.back() == '\n') t.pop_back();
    return t;
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Renamed from _getch() to get_ch() to avoid infinite recursion
// on Windows (where _getch is already defined in <conio.h>).
char _getch() {
#ifdef _WIN32
    return (char)::_getch();   // call the conio.h version explicitly
#else
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return (char)ch;
#endif
}

// Renamed from Sleep() to Sleep_ms() to avoid Win32 macro conflict
void Sleep_ms(int milliseconds) {
#ifdef _WIN32
    ::Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}