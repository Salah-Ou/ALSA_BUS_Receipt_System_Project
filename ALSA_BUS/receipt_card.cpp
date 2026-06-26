#include "utils.h"

// ─────────────────────────────────────────────────────────────
// RECEIPT CARD
// ─────────────────────────────────────────────────────────────
void ALSA::receipt_card() {
    clear_screen();
    gotoxy(50, 0);
    string current_time = Time();
    cout << WHITE << " Current Time's : " << CYAN << current_time << WHITE;

    if (!students.empty()) {
        string first_name, last_name, CNI;
        gotoxy(18, 1);
        cout << BLUE_REV << " Receipt Card" << DEFAULT << WHITE;
        gotoxy(18, 3);
        cout << GREEN << "Fields With " << RED << "(*)" << GREEN << " are required " << WHITE;
        gotoxy(18, 5);
        cout << RED << "(*) " << WHITE << "Please Enter your first name : " << BLUE;
        cin.ignore();
        getline(cin, first_name);
        gotoxy(18, 7);
        cout << RED << "(*) " << WHITE << "Please Enter your last name  : " << BLUE;
        getline(cin, last_name);
        gotoxy(18, 9);
        cout << RED << "(*) " << WHITE << "Please Enter your CNI        : " << BLUE;
        char ch;
        CNI.clear();

        #ifdef _WIN32
            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
        #else
            tcflush(STDIN_FILENO, TCIFLUSH);
        #endif

        for (int i = 0; i < 7; ) {
            ch = _getch();              // FIX: was _getch()
            if (ch == 13) break;
            if (ch < 32)  continue;
            CNI += ch;
            cout << (i == 0 ? ch : '*') << flush;
            i++;
        }

        bool found = false;
        for (int i = 0; i < (int)students.size(); i++) {
            if (students[i].first_name == first_name &&
                students[i].last_name  == last_name  &&
                students[i].CNI        == CNI) {
                found = true;

                clear_screen();
                gotoxy(50, 0);
                cout << WHITE << " Current Time's : " << CYAN << Time() << WHITE;

                gotoxy(24, 3);
                cout << BLUE_REV << " A . L . S . A " << DEFAULT;
                gotoxy(21
                    , 4);
                cout << WHITE << "ALSA CITY AGADIR S.A.";   // FIX: was ALSA

                gotoxy(18, 6);
                char numbers[] = "0123456789";
                char random_number[6];
                cout << BLUE << "Payment Number  :    " << DEFAULT << WHITE << "NB";
                for (int k = 0; k < 5; k++) {
                    random_number[k] = numbers[rand() % 10];
                    cout << random_number[k];
                }

                if (shops.empty()) {
                    gotoxy(18, 10);
                    cout << RED << "No purchase found for this student.";
                }
                else {
                    int j = (int)shops.size() - 1;

                    gotoxy(18, 9);
                    cout << BLUE << "Card Type       :    " << DEFAULT << WHITE << "Normal";
                    gotoxy(18, 11);
                    cout << BLUE << "Recharge        :    " << DEFAULT << WHITE << "E-Recharge Month";

                    // Start date
                    gotoxy(18, 13);
                    cout << BLUE << "Card Start Date :    " << DEFAULT << GREEN
                        << ((shops[j].start_day   < 10) ? "0" : "") << shops[j].start_day   << "/"
                        << ((shops[j].start_month < 10) ? "0" : "") << shops[j].start_month << "/"
                        << shops[j].start_year << "   00:00:00 " << DEFAULT;

                    // Compute end date = LAST DAY of next month
                    auto last_day_of_month = [](int month, int year) -> int {
                        if (month == 2) {
                            bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
                            return leap ? 29 : 28;
                        }
                        if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
                        return 31;
                    };

                    int end_month = (shops[j].start_month == 12) ? 1 : shops[j].start_month;
                    int end_year  = (shops[j].start_month == 12) ? shops[j].start_year + 1 : shops[j].start_year;
                    int end_day   = last_day_of_month(end_month, end_year); // always last day of next month

                    // End date
                    gotoxy(18, 15);
                    cout << BLUE << "Card End Date   :    " << DEFAULT << RED
                        << ((end_day   < 10) ? "0" : "") << end_day   << "/"
                        << ((end_month < 10) ? "0" : "") << end_month << "/"
                        << end_year << "   23:59:59 " << DEFAULT;

                    gotoxy(18, 17);
                    cout << fixed << BLUE << "Card Price      :    " << DEFAULT << WHITE
                        << setprecision(2) << shops[j].price << " DH";
                }

                gotoxy(23, 19);
                cout << GREEN << "Thank You For Shopping With ALSA." << WHITE; // FIX: was ALSA

                time_t now = time(0);
                tm *t = localtime(&now);
                gotoxy(28, 21);
                cout << BLUE_REV << " "
                    << ((t->tm_mday < 10) ? "0" : "") << t->tm_mday << "/"
                    << ((t->tm_mon  < 10) ? "0" : "") << t->tm_mon + 1 << "/"
                    << t->tm_year + 1900 << "  "
                    << ((t->tm_hour < 10) ? "0" : "") << t->tm_hour << ":"
                    << ((t->tm_min  < 10) ? "0" : "") << t->tm_min  << ":"
                    << ((t->tm_sec  < 10) ? "0" : "") << t->tm_sec
                    << " " << DEFAULT;

                gotoxy(26, 23);
                break;
            }
        }
        if (!found) {
            gotoxy(24, 12);
            cout << RED << "The person isn't present...!";
            gotoxy(29, 14);
            cout << WHITE << "Please Try Again";
            gotoxy(24, 16);
        }
    }
    else {
        clear_screen();
        gotoxy(25, 5);
        cout << RED << "No one was found on the list!";
        gotoxy(26, 7);
    }
    Pause();
    cin.ignore();
}
