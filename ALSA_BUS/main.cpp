#include "utils.h"
#include <iostream>

using namespace std;

// ─────────────────────────────────────────────────────────────
// ABOUT US
// ─────────────────────────────────────────────────────────────
void ALSA::about_us(){
    clear_screen();
    gotoxy(55,0);
    string current_time = Time();
    cout << WHITE << " Current Time's : " << CYAN << current_time ;  
    gotoxy(38,3);
    cout << BLUE << "** OUR MISSION " << DEFAULT ;
    gotoxy(38,5);
    cout << WHITE << "Our mission at \033[1;34mALSA City Agadir" << DEFAULT << WHITE << " is to transport our customers safely with a high quality of" ;
    gotoxy(35,7);
    cout << "service. Since January 1, 2024, we have started the delegated management of public transport " ;
    gotoxy(35,9);
    cout << "in the greater Agadir. By applying our experience in the field of transport, we have assisted and ";
    gotoxy(35,11);
    cout << "collaborated in the development of the entire region by moving citizens to their destinations " ;
    gotoxy(35,13); 
    cout << "through a network that consists of 45 lines with a fleet of 220 buses and a staff of 700 employees, " ;
    gotoxy(35,15);
    cout << "traveling an average of 55,000 km every day." ;
    gotoxy(38,18);
    cout << BLUE << "** \033[1;7;34m OUR SERVICES " << DEFAULT ;
    gotoxy(38,20);
    cout << WHITE << "Regarding our services, we offer a wide network that extends over \033[1;32m60 kilometers " << WHITE << "from the North " ;
    gotoxy(35,22);
    cout << "to Tamri," << GREEN << "50km" << WHITE << " to the East to Ouled Teima and to the South, up to  " << GREEN << "Massa 67km (Agadir-Inezgane +40km)." ;
    gotoxy(35,24);
    cout << WHITE << "\033[1;34mALSA City Agadir " << WHITE << " also offers you student cards and NextCard loyalty cards to facilitate your travel with" ;
    gotoxy(35,26);
    cout << "a reduced price. It also offers free travel to children under 6 years old." ;
    gotoxy(38,31);
    cout << BLUE << "** \033[1;7;34m OUR ENVIRONMENT " << DEFAULT ;
    gotoxy(38,33);
    cout << WHITE << "As pollution has an impact on our daily lives, and transport contributes significantly to it," ;
    gotoxy(35,35);
    cout << "we have trained our drivers in economical, efficient and non-polluting driving. This demonstrates " ;
    gotoxy(35,37);
    cout << "our involvement in reducing the amount of CO2 emitted in the Greater Agadir region. Software that " ;
    gotoxy(35,39);
    cout << "intervenes on the driver's behavior and emphasizes economical driving is also implemented. At " ;
    gotoxy(35,41);
    cout << "\033[1;34mALSA" << WHITE << " Agadir, we are committed to sustainable development and a greener future." ;
    gotoxy(63,43); Pause(); cout << DEFAULT ;
    return ;
}

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
        cout << RED << "No one was found on the list!";
        gotoxy(27, 7);
        cout << RED << "Please Add A Student First";
        gotoxy(26, 9);
        Pause();
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
                cout << DEFAULT;
                break;
            }
            else if (i == (int)students.size() - 1) {
                gotoxy(27, 11);
                cout << RED << "No one was found on the list!";
                gotoxy(26, 13);
                Pause();
            }
        }
    }
}

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

                    int end_month = (shops[j].start_month == 12) ? 1 : shops[j].start_month + 1;
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
}

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