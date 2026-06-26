#include "utils.h"
#include <iostream>

using namespace std;

// ─────────────────────────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────────────────────────
int main() {
    clear_screen();
    ALSA bus;  // FIX: was ALSA bus
    int option;

    while (true) {
        clear_screen();
        gotoxy(50, 0);
        string current_time = Time();
        cout << WHITE << " Current Time's : " << CYAN << current_time << WHITE;

        gotoxy(18, 1);
        cout << BLUE_REV << " ALSA \033[3;7;34mAGADIR " << DEFAULT; // FIX: was ALSA
        gotoxy(18, 2);
        cout << WHITE << "Welcome To ALSA Agadir" << DEFAULT;                         // FIX: was ALSA
        gotoxy(12, 4);
        cout << CYAN << "---------------------------------";
        gotoxy(16, 6);
        cout << CYAN << "1. " << WHITE << "About Us.";
        gotoxy(16, 8);
        cout << CYAN << "2. " << WHITE << "Student Card.";
        gotoxy(16, 10);
        cout << CYAN << "3. " << WHITE << "Shopping Cart.";
        gotoxy(16, 12);
        cout << CYAN << "4. " << WHITE << "Receipt Card.";
        gotoxy(16, 14);
        cout << CYAN << "5. " << WHITE << "Exit.";
        gotoxy(12, 16);
        cout << CYAN << "---------------------------------";
        gotoxy(15, 18);
        cout << WHITE << "Select Option : ";
        cin >> option;
        cout << DEFAULT;

        switch (option) {
            case 1: bus.about_us();     break;
            case 2: bus.student_card(); break;
            case 3: bus.shop_card();    break;
            case 4: bus.receipt_card(); break;
            case 5:
                gotoxy(20, 21);
                cout << CYAN << "Exiting ALSA System...\n\n" << DEFAULT;  // FIX: was ALSA
                exit(0);
            default:
                gotoxy(20, 21);
                cout << RED << "Invalid Option !!\n\n" << DEFAULT;
                gotoxy(14, 23);
                Pause();
                break;
        }
    }
    return 0;
}