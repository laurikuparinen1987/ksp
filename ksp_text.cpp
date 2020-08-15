/* KIVI, SAKSET & PAPERI
Copyright 2007 Lauri Kuparinen

Kaikki erilaiset tulostusteht�v�t l�ytyv�t t��lt�.

*/

#include "ksp_def.h"
#include <stdlib.h>					// System-kutsut (tekstin v�rit & ruudun tyhjennykset...)

int p_score, cpu_score, draw;								
int rounds;										

void intro()
{
	// Jotta ��kk�set n�kyisiv�t tarvitsemme umlaut-merkist�n k�ytt��n.
	//
	// Umlaut-merkist�-koodit: 
	// 204 = � 
	// 366 = � 
	
	system("color A");				// Vihre� teksti jotta peli n�ytt�� Matrixilta

	cout << "KIVI, SAKSET & PAPERI\n\n";
	cout << "Kivi tylsytt\204\204 sakset,\n";
	cout << "sakset leikkaavat paperin ja\n";
	cout << "paperi pussittaa kiven.\n\n";
	cout << "Esineesi voit valita k\204ytt\204m\204ll\204 nuolin\204pp\204imi\204\n";
	cout << "'yl\366s' ja 'alas' selataksesi vaihtoehtoja.\n\n";
	system("PAUSE");				// Tauko ohjelman toistossa.	
}

void winner()						// Voittajan tarkistus ja julistus.
{
	string game_winner;

	switch (p_c)
	{
	case 1:							// Pelaaja kivi
		{
			if (cpu_c == 2)			// Kone sakset
			{
				game_winner = "Pelaaja voitti!";
				p_score++;
				break;
			}
			else if (cpu_c == 3)	// Kone paperi
			{
				game_winner = "Tietokone voitti.";
				cpu_score++;
				break;
			}
			else
			{
				game_winner = "Tasapeli.";
				draw++;
				break;
			}
		}
	case 2:							// Pelaaja sakset
		{
			if (cpu_c == 3)			// Kone paperi
			{
				game_winner = "Pelaaja voitti!";
				p_score++;
				break;
			}
			else if (cpu_c == 1)	// Kone kivi
			{
				game_winner = "Tietokone voitti.";
				cpu_score++;
				break;
			}
			else
			{
				game_winner = "Tasapeli.";
				draw++;
				break;
			}
		}
	case 3:							// Pelaaja paperi
		{
			if (cpu_c == 1)			// Kone kivi
			{
				game_winner = "Pelaaja voitti!";
				p_score++;
				break;
			}
			else if (cpu_c == 2)	// Kone sakset
			{
				game_winner = "Tietokone voitti.";
				cpu_score++;
				break;
			}
			else
			{
				game_winner = "Tasapeli.";
				draw++;
				break;
			}
		}
	}

	rounds++;						// Yksi er� lis�� pelattu.

	// Voittajan julistus.
	cout << "\nPelaaja valitsi: ";
	if (p_c == 1)
		cout << "kiven.";
	else if (p_c == 2)
		cout << "sakset.";
	else
		cout << "paperin.";
	
	cout << "\nTietokone valitsi: ";
	if (cpu_c == 1)
		cout << "kiven.";
	else if (cpu_c == 2)
		cout << "sakset.";
	else
		cout << "paperin.";

	// *T�h�n kun saisi jonkun yhden sekunnin viiveen...*

	cout << "\n\nJoten tulos on:\n";
	cout << "... " << game_winner << "\n\n";
	
	system("PAUSE");
}

void score()
{
	system("cls");					// Johtuen kaiken tiedon esitt�misest� yhdell� ruudulla, kokeillaan
									// tiedon levitt�mist� kahdelle ruudulle.
	system("color C");				// Punainen teksti

	cout << "\n\nJa kun " << rounds;
	
	if (rounds == 1)				// Yksikk� ja monikko
	{
		cout << " er\204 on pelattu, on\n";
	}
	else
	{
		cout << " er\204\204 on pelattu, on\n";
	}

	cout << "tilanne seuraava:\n\n";
	cout << "Pelaajan voitot: " << p_score;
	
	if (p_score == 1)				// Yksikk� ja monikko
	{
		cout << " er\204.\n";
	}
	else
	{
		cout << " er\204\204.\n";
	}

	cout << "Tietokoneen voitot: " << cpu_score;

	if (cpu_score == 1)				// Yksikk� ja monikko...j�lleen
	{
		cout << " er\204.\n";
	}
	else
	{
		cout << " er\204\204.\n";
	}

	cout << "Tasapelit: " << draw;
}

void dr_menu(int valinta)			// Piirret��n valikko
{
	system("cls");					// Puhdistamme/p�ivit�mme ruudun.

	switch(valinta)
	{
	case 1:		// Kivi
		{
			cout << "Mik\204 on valintasi?\n\n";
			cout << "* KIVI *\n";
			cout << "  SAKSET\n";
			cout << "  PAPERI\n";
			break;
		}
	case 2:		// Sakset
		{
			cout << "Mik\204 on valintasi?\n\n";
			cout << "  KIVI\n";
			cout << "* SAKSET *\n";
			cout << "  PAPERI\n";
			break;
		}
	case 3:		// Paperi
		{
			cout << "Mik\204 on valintasi?\n\n";
			cout << "  KIVI \n";
			cout << "  SAKSET\n";
			cout << "* PAPERI *\n";
			break;
		}
	}
}
