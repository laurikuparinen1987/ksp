/* KIVI, SAKSET & PAPERI
Copyright 2007 Lauri Kuparinen

Kaikki valintoihin liittyv�t koodit ovat t�ss� tiedostossa.

*/

#include "ksp_def.h"
#include <cstdlib>					// Arvonta-rutiinia varten...
#include <ctime>					// ...kuin my�s(?)
#include <stdlib.h>					// System-kutsut (tekstin v�rit & ruudun tyhjennykset...)
#include <conio.h>					// N�pp�inkutsuja varten.
												
int ps_t;				

int p_select()
{
	system("color A");				// Vihre� teksti, muuten toisen er�n alkaessa teksti olisi punainen!

	int ps;							// Palautettava arvo.
	char KeyStroke;					// V�lit�nt� n�pp�inpainallusta varten.

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
		dr_menu(ps_t);					// Piirret��n valikko
		KeyStroke = getch();			// Luetaan n�pp�inpainalluksia.

			switch (KeyStroke)
			{
				case DOWN_ARROW:		// K�ytt�j� valitsee "alas"
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
				case UP_ARROW:			// K�ytt�j� valitsee "yl�s"
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

	} while (KeyStroke != 13);		// 13 = ENTER! L�ytyi pienen tutkinnan j�lkeen

	ps = ps_t;						// Palautettava arvo saa k�ytt�j�n valinnan.
	return ps;						// Palautetaan pelaajan valinta-arvo.
}


int cpu_select()
{
	int cpus;
	
	// Arvonta-rutiini

	srand((unsigned)time(0)); 
    cpus = (rand()%3)+1;			// Arvotaan luku 1:n ja 3:n v�lilt�(?)

	return cpus;
}

bool again()
{
	string usr_choice;
	//char usr_choice;
	bool usr;

Kysy:								// T�nne GoTo-meid�t heitt��...
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
		goto Kysy;					// Pahamaineinen goto-k�sky kelpaa t�h�n hyvin.
	}

	return usr;						// Palautetaan k�ytt�j�n valinnan arvo.
}
