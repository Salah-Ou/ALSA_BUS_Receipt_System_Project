#include "utis.h"

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
    gotoxy(63,43); Pause(); cin.ignore(); cout << DEFAULT ;
    return ;
}