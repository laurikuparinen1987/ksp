/* KIVI, SAKSET & PAPERI
Copyright 2007 Lauri Kuparinen

M‰‰rittelytiedosto.

*/

#include <iostream>
#include <string>

using namespace std;

#define UP_ARROW    72				// M‰‰ritell‰‰n tarvittavien n‰pp‰imien nimet
#define DOWN_ARROW  80				//

// Globaalien muuttujien esittely

extern int p_score, cpu_score, draw;		// Pelaajan pisteet, tietokoneen pisteet, tasapelit
extern int p_c, cpu_c;						// Pelaajan valinta, tietokoneen valinta
// string pl_input;					// Pelaajan syˆte (K, S tai P)
extern bool yesno;							// Pelataanko uusi er‰
extern int rounds;							// Erien lukum‰‰r‰
extern int ps_t;							// K‰ytt‰j‰n valinta valikossa

// Funktioiden esim‰‰rittely/prototyypit

void intro();						// Pelin alkuintro				
int p_select();						// Funktio, joka kysyy pelaajalta syˆtett‰.
int cpu_select();					// Funktio, jossa arvotaan tietokoneelle kivi, sakset tai paperi.
void winner();						// Ja voittaja on...
void score();						// Er‰t, voitot...
bool again();						// Pelataanko uusi er‰?
void dr_menu(int valinta);			// Piirt‰‰ valikon.