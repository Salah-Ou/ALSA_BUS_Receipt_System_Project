#include "utils.h"

// ─────────────────────────────────────────────────────────────
// SHOP CARD
// ─────────────────────────────────────────────────────────────
void ALSA::shop_card() {
    clear_screen();
    gotoxy(50, 0);
    string current_time = Time();
    cout << WHITE << " Current Time's : " << CYAN << current_time << WHITE;

    if (students.empty()) {
        gotoxy(25, 5);
        cout << RED << "No one was found on the list !";
        gotoxy(27, 7);
        cout << RED << "Please Add A Student First";
        gotoxy(26, 9);
        Pause();
        cin.ignore();
    }
    else {
        gotoxy(18, 1);
        cout << BLUE_REV << " Shopping Card " << DEFAULT << WHITE;
        gotoxy(18, 3);
        cout << GREEN << "Fields With " << RED << "(*)" << GREEN << " are required " << WHITE;

        // FIX: ask for both first_name AND last_name so the match condition can succeed
        string first_name, last_name, CNI;
        Shop new_shop;

        gotoxy(18, 5); cout << RED << "(*) " << WHITE << "Please Enter your first name : " << BLUE;
        cin.ignore();
        getline(cin, first_name);
        gotoxy(18, 7); cout << RED << "(*) " << WHITE << "Please Enter your last name  : " << BLUE;
        getline(cin, last_name);
        gotoxy(18, 9); cout << RED << "(*) " << WHITE << "Please Enter your CNI        : " << BLUE;
        char ch;
        CNI.clear();

        // Flush leftover '\n' left by previous cin >>
        #ifdef _WIN32
            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        #else
            tcflush(STDIN_FILENO, TCIFLUSH);
        #endif

        for (int i = 0; i < 7; ) {       // note: i only increments on valid input
            ch = _getch();
            if (ch == 13) break;          // Enter = done
            if (ch < 32)  continue;       // skip \n, \r and any other control chars
            CNI += ch;
            cout << (i == 0 ? ch : '*') << flush;
            i++;
        }

        int found = 0;
        for (int i = 0; i < (int)students.size(); i++) {
            if (first_name == students[i].first_name &&
                last_name  == students[i].last_name  &&
                CNI        == students[i].CNI) {
                found = 1;
                gotoxy(27, 11);
                cout << GREEN << " Keep Shopping ..." << WHITE;

                gotoxy(18, 13);
                cout << RED << "(*) " << WHITE << "Card Start Date (DD MM YYYY) : ";
                cin >> new_shop.start_day >> new_shop.start_month >> new_shop.start_year;
                gotoxy(18, 15);
                cout << RED << "(*) " << WHITE << "Are you Inside the city or Outside (I/O) ? ";
                char location;
                cin >> location;
                if (location == 'I' || location == 'i'){
                    new_shop.price = 60.00;
                }
                else if (location == 'O' || location == 'o'){
                    new_shop.price = 80.00;
                }
                gotoxy(18, 17);
                cout << fixed << RED << "(*) " << WHITE << "Your Card Price : " << setprecision(2) << new_shop.price << " DH" << WHITE;

                shops.push_back(new_shop);
                gotoxy(24, 19);
                cout << GREEN << "You Have Successfully Shopped.";
                gotoxy(23, 21);
                cout << WHITE << "Thank You For Shopping With ALSA.";
                gotoxy(26, 23);
                Pause();
                cin.ignore();
                cout << DEFAULT;
                break;
            }
            else if (i == (int)students.size() - 1) {
                gotoxy(27, 11);
                cout << RED << "No one was found on the list!";
                gotoxy(26, 13);
                Pause();
                cin.ignore();
            }
        }
    }
}