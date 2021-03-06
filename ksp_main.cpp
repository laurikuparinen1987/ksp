/* KIVI, SAKSET & PAPERI
Copyright 2007 Lauri Kuparinen

HUOM! Ohjelma on tehty ilman minkäänlaista etukäteissuunnittelua, joten koodin
logiikka ja erilaiset ratkaisut voivat tuntua omituisilta.

Huolimatta englannikielisistä muuttujien ja funktioiden nimistä, koodi on todellakin
99% omaa alusta loppuun! Ja miksi englanniksi? Jaa, johtuu varmaan netin tutoriaaleista... 
Ja se yksi prosentti on arvonta-rutiinista...
*/

#include "ksp_def.h"
#include <stdlib.h>					// System-kutsut (tekstin värit & ruudun tyhjennykset...)
#include <conio.h>					// Näppäinkutsuja varten.

int p_c, cpu_c;						
bool yesno;							
				
int main()							
{
	intro();						// Näytetään alkuintro

	do								// Pelin pääsilmukka.
	{
		system("cls");				// Tyhjentää ruudun.
		
		cpu_c = cpu_select();		// Annetaan tietokoneen aloittaa...
		p_c = p_select();			// ...ja jatketaan kysymällä pelaajalta hänen valintaansa.

		winner();					// Ja tarkistamme annettujen syötteiden perusteella voittajan.
		score();					// Ja pelin tilanne on seuraava...

		yesno = again();			// Uusi erä?

	} while (yesno != false);		// Jatkamme niin kauan kunnes pelaaja ei halua jatkaa.

	return 0;						// Ohjelman lopetus
}
