/* KIVI, SAKSET & PAPERI
Copyright 2007 Lauri Kuparinen

Kaikki valintoihin liittyvät koodit ovat tässä tiedostossa.

*/

#include "ksp_def.h"
#include <cstdlib>					// Arvonta-rutiinia varten...
#include <ctime>					// ...kuin myös(?)
#include <stdlib.h>					// System-kutsut (tekstin värit & ruudun tyhjennykset...)
#include <conio.h>					// Näppäinkutsuja varten.
												
int ps_t;				

int p_select()
{
	system("color A");				// Vihreä teksti, muuten toisen erän alkaessa teksti olisi punainen!

	int ps;							// Palautettava arvo.
	char KeyStroke;					// Välitöntä näppäinpainallusta varten.

	ps_t = 1;						// Alustetaan arvo: kivi.

	/*	*VANHA VALINTAKOODI!*
	do
	{
		cout << "\nMik\204 on valintasi: [1] = Kivi [2] = Sakset [3] = Paperi\n";
		cin >> ps;
	} while (ps > 3 || ps < 0);		// Pelin salliman arvon tutkiminen.
	*/

	do	// UUSI VALINTAKOODI!
	{
		dr_menu(ps_t);					// Piirretään valikko
		KeyStroke = getch();			// Luetaan näppäinpainalluksia.

			switch (KeyStroke)
			{
				case DOWN_ARROW:		// Käyttäjä valitsee "alas"
					{
						if (ps_t == 1 || ps_t == 2)	// Kivi tai sakset.
						{
							ps_t++;	
						}
						else if (ps_t == 3)			// Paperi
						{
							ps_t = 1;
						}
						break;
					}
				case UP_ARROW:			// Käyttäjä valitsee "ylös"
					{
						if (ps_t == 2 || ps_t == 3)	// Sakset tai paperi.
						{
							ps_t--;
						}
						else if (ps_t == 1)			// Kivi
						{
							ps_t = 3;
						}
						break;
				default:
					{
						// Ei lasketa!
					}
					}
			} 

	} while (KeyStroke != 13);		// 13 = ENTER! Löytyi pienen tutkinnan jälkeen

	ps = ps_t;						// Palautettava arvo saa käyttäjän valinnan.
	return ps;						// Palautetaan pelaajan valinta-arvo.
}


int cpu_select()
{
	int cpus;
	
	// Arvonta-rutiini

	srand((unsigned)time(0)); 
    cpus = (rand()%3)+1;			// Arvotaan luku 1:n ja 3:n väliltä(?)

	return cpus;
}

bool again()
{
	string usr_choice;
	//char usr_choice;
	bool usr;

Kysy:								// Tänne GoTo-meidät heittää...
	cout << "\n\nPelataanko uusi er\204? (k / e)\n";
	cin >> usr_choice;
	
	if (usr_choice == "k" || usr_choice == "K")
	{
		usr = true;
	}
	else if (usr_choice == "e" || usr_choice == "E")
	{
		usr = false;
	}
	else
	{
		cout << "\nVirheellinen sy\366te!\n";
		goto Kysy;					// Pahamaineinen goto-käsky kelpaa tähän hyvin.
	}

	return usr;						// Palautetaan käyttäjän valinnan arvo.
}
