#include "utils.h"

// ─────────────────────────────────────────────────────────────
// STUDENT CARD
// ─────────────────────────────────────────────────────────────
void ALSA::student_card() {
    clear_screen();
    gotoxy(50, 0);
    string current_time = Time();
    cout << WHITE << "Current Time's : " << CYAN << current_time << WHITE;

    Student new_student;
    gotoxy(18, 1);
    cout << BLUE_REV << " Card Request " << DEFAULT << WHITE;
    gotoxy(18, 3);
    cout << GREEN << "Fields With " << RED << "(*)" << GREEN << " are required" << WHITE;
    gotoxy(18, 5);
    cout << WHITE << "School Level : Primaire / College / Lycee / University / OFPPT";
    gotoxy(18, 7);
    cout << RED << "(*) " << BLUE << "Select option : " << WHITE;
    cin >> new_student.etablish;

    if (new_student.etablish == "Primaire" || new_student.etablish == "PRIMAIRE" || new_student.etablish == "primaire") {
        gotoxy(18, 9);
        cout << WHITE << "Establishment : E 20 Aout / E 2 Mars / ANNEXE E ENNAHDA / E 18 NOVEMBRE / E ADRAR / E AGDAL / Another";
        gotoxy(18, 11);
        cout << RED << "(*) " << BLUE << "Select option : " << WHITE;
        cin.ignore();
        getline(cin, new_student.etablish);
        if (new_student.etablish == "another" || new_student.etablish == "ANOTHER" || new_student.etablish == "Another") {
            gotoxy(18, 13);
            cout << RED << "(*) " << BLUE << "Another Establishment : " << WHITE;
            cin >> new_student.etablish;
        }
    }
    else if (new_student.etablish == "College" || new_student.etablish == "COLLEGE" || new_student.etablish == "college") {
        gotoxy(18, 9);
        cout << WHITE << "Establishment : C AL AMANE / C ALLAL EL FASSI / C 20 AOUT / C AL FIRDAOUS / C ATLAS / C AL NAHDA / Another";
        gotoxy(18, 11);
        cout << RED << "(*) " << BLUE << "Select option : " << WHITE;
        cin.ignore();
        getline(cin, new_student.etablish);
        if (new_student.etablish == "another" || new_student.etablish == "ANOTHER" || new_student.etablish == "Another") {
            gotoxy(18, 13);
            cout << RED << "(*) " << BLUE << "Another Establishment : " << WHITE;
            cin >> new_student.etablish;
        }
    }
    else if (new_student.etablish == "Lycee" || new_student.etablish == "LYCEE" || new_student.etablish == "lycee") {
        gotoxy(18, 9);
        cout << WHITE << "Establishment : L AL FADILA / L AL QODS / L AL KHAWARIZMI / L IBN SINA / L AJDIR / L 06 NOVEMBRE / Another";
        gotoxy(18, 11);
        cout << RED << "(*) " << BLUE << "Select option : " << WHITE;
        cin.ignore();
        getline(cin, new_student.etablish);
        if (new_student.etablish == "another" || new_student.etablish == "ANOTHER" || new_student.etablish == "Another") {
            gotoxy(18, 13);
            cout << RED << "(*) " << BLUE << "Another Establishment : " << WHITE;
            cin >> new_student.etablish;
        }
    }
    else if (new_student.etablish == "University" || new_student.etablish == "UNIVERSITY" || new_student.etablish == "university") {
        gotoxy(18, 9);
        cout << WHITE << "Establishment : ENAA / ENSA / FS / ENCG / EST / BTS / FS Lettres / FS Economie / CMC / Another";
        gotoxy(18, 11);
        cout << RED << "(*) " << BLUE << "Select option : " << WHITE;
        cin.ignore();
        getline(cin, new_student.etablish);
        if (new_student.etablish == "another" || new_student.etablish == "ANOTHER" || new_student.etablish == "Another") {
            gotoxy(18, 13);
            cout << RED << "(*) " << BLUE << "Another Establishment : " << WHITE;
            cin >> new_student.etablish;
        }
    }
    else if (new_student.etablish == "OFPPT" || new_student.etablish == "ofppt" || new_student.etablish == "Ofppt") {
        gotoxy(18, 9);
        cout << WHITE << "Establishment : CMC / CENTRE ASSISTANCE ET INSERTION TILILA / ISTA AGADIR / ISTA INZGAN / ISTA ASSAKA / Another";
        gotoxy(18, 11);
        cout << RED << "(*) " << BLUE << "Select option : " << WHITE;
        cin.ignore();
        getline(cin, new_student.etablish);
        if (new_student.etablish == "another" || new_student.etablish == "ANOTHER" || new_student.etablish == "Another") {
            gotoxy(18, 13);
            cout << RED << "(*) " << BLUE << "Another Establishment : " << WHITE;
            cin >> new_student.etablish;
        }
    }

    gotoxy(18, 13);
    cout << RED << "(*)" << WHITE << " First Name : ";
    cin >> new_student.first_name;
    gotoxy(18, 15);
    cout << RED << "(*)" << WHITE << " Last Name : ";
    cin >> new_student.last_name;
    gotoxy(18, 17);
    cout << RED << "(*)" << WHITE << " Phone number : ";
    cin >> new_student.phone_no;
    gotoxy(18, 19);
    cout << RED << "(*)" << WHITE << " Email : ";
    cin >> new_student.email;
    gotoxy(18, 21);
    cout << RED << "(*)" << WHITE << " Date of Birth (DD/MM/YYYY) : ";
    cin >> new_student.dt_of_birth;
    gotoxy(18, 23);
    cout << RED << "(*)" << WHITE << " CNI : ";
    char ch;
    new_student.CNI.clear();

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
        new_student.CNI += ch;
        cout << (i == 0 ? ch : '*') << flush;
        i++;
    }

    gotoxy(18, 25);
    cout << BLUE_REV << " To Ask For A Date " << DEFAULT << WHITE;
    gotoxy(18, 27);
    cout << GREEN << "Fields With " << RED << "(*)" << GREEN << " are required" << WHITE;
    gotoxy(18, 29);
    cout << "WILAYA VALLEE / PLACE SALAM D'AGADIR / PLACE MASSIRA D'INZGANE";
    gotoxy(18, 31);
    cout << RED << "(*) " << BLUE << "Agency : " << WHITE;
    cin.ignore();
    getline(cin, new_student.agency);
    gotoxy(18, 33);
    cout << RED << "(*)" << WHITE << " ( If you can go today, write today ) "
        << BLUE << "OR" << WHITE << " Select Date : ";
    cin >> new_student.date;

    if (new_student.date == "today" || new_student.date == "TODAY") {
        gotoxy(18, 35);
        cout << RED << "(*)" << WHITE << " Current Time's : " << CYAN << Time() << WHITE;
        gotoxy(18, 37);
        cout << RED << "(*)" << WHITE
            << " Schedule : Open at this time from 8:30 am to 6:30 pm daily, otherwise closed on Sunday all day.";
    }

    students.push_back(new_student);
    gotoxy(50, 40);
    Pause();
    cout << DEFAULT;
}