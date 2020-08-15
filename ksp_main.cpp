/* KIVI, SAKSET & PAPERI
Copyright 2007 Lauri Kuparinen

HUOM! Ohjelma on tehty ilman mink‰‰nlaista etuk‰teissuunnittelua, joten koodin
logiikka ja erilaiset ratkaisut voivat tuntua omituisilta.

Huolimatta englannikielisist‰ muuttujien ja funktioiden nimist‰, koodi on todellakin
99% omaa alusta loppuun! Ja miksi englanniksi? Jaa, johtuu varmaan netin tutoriaaleista... 
Ja se yksi prosentti on arvonta-rutiinista...
*/

#include "ksp_def.h"
#include <stdlib.h>					// System-kutsut (tekstin v‰rit & ruudun tyhjennykset...)
#include <conio.h>					// N‰pp‰inkutsuja varten.

int p_c, cpu_c;						
bool yesno;							
				
int main()							
{
	intro();						// N‰ytet‰‰n alkuintro

	do								// Pelin p‰‰silmukka.
	{
		system("cls");				// Tyhjent‰‰ ruudun.
		
		cpu_c = cpu_select();		// Annetaan tietokoneen aloittaa...
		p_c = p_select();			// ...ja jatketaan kysym‰ll‰ pelaajalta h‰nen valintaansa.

		winner();					// Ja tarkistamme annettujen syˆtteiden perusteella voittajan.
		score();					// Ja pelin tilanne on seuraava...

		yesno = again();			// Uusi er‰?

	} while (yesno != false);		// Jatkamme niin kauan kunnes pelaaja ei halua jatkaa.

	return 0;						// Ohjelman lopetus
}
