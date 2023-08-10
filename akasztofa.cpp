#define _CRT_SECURE_NO_WARNINGS
#include "circular_linked_list.cpp"
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;

// jatekosok szama megadasa, majd ezek nevei, ezaltal megadva a listat
void Stage1(int &PlayersNr, CircularLinkedList<string> &Names, ifstream& fin)
{
	cout << "Number of players: ";
	fin >> PlayersNr;
	
	cout << PlayersNr << '\n';
	string PlayerName;

	for (int i = 0; i < PlayersNr; i++)
	{
		cout << "Player" << i + 1 << ": ";
		fin >> PlayerName;
		cout << PlayerName << '\n';
		Names.AddBack(PlayerName);
	}

}
// talalgatos resz
void Stage4(CircularLinkedList<string>& Names, char Temp[], string ActivePlayer, ofstream &fout)
{
	char Characters[41];
	char Tip[1]; // a tip mindig egy karakter kell legyen, de strstr miatt karakterlancnak deklaralt
	int n = strlen(Temp);
	int CorrectNr = 0;
	char Used[21] = "";

	for (int i = 0; i < n * 2 ; i+= 2)
	{
		Characters[i] = '_';
		Characters[i + 1] = ' ';
	}

	Characters[n * 2] = '\0';

	cout << Characters;
	

	cout << '\n';

	int Count = 5;
	while(CorrectNr != n && Count > 0)
	{
		cout << "\nYou have " << Count << " tries" << "\nChoose a character from the english alphabet:";
		cin >> Tip[0];

		for (int i = 0; i < n; i++)
		{
			if (Temp[i] == Tip[0] &&  ! strstr(Used, Tip))
			{
				CorrectNr++;
				Characters[i * 2] = Tip[0];
			}
		}

		if (!strstr(Used, Tip))
		{
			strcat(Used, Tip);
		}

		for (int i = 0; i < n * 2; i++)
		{
			cout << Characters[i];
		}

		Count--;
		
		if (CorrectNr == n)
		{
			cout << "\nGood Game\n";
			fout << ActivePlayer << " +5\n";
		}
	}
	cout << "\nGo Next\n";

}
//minden jatekosnak kulon sora a jatekban
void Stage3(CircularLinkedList<string>&Names, ofstream &fout)
{
	int Round = 1;
	char Input[21], Temp[21];
	string ActivePlayer = "";
	do
	{
		int i = 0;
		strcpy_s(Temp, "");
		ActivePlayer = Names.GoThrough();
		cout << "ROUND " << Round++ << '\n' << ActivePlayer << "'s turn:\n";
		while ((Input[i] = _getch()) != '\r')
		{
			Temp[i] = Input[i++];
			cout << '*';
		}
		cout << '\n';
		Temp[i] = '\0';

		if (strcmp(Temp, "stop") == 0)
		{
			return;
		}
		Stage4(Names, Temp, ActivePlayer, fout);
		cout << '\n';
	}while (strcmp(Temp, "stop"));

}
//menu
void Stage2(CircularLinkedList<string> &Names, ofstream &fout)
{
	char choice = ' ';
	string PlayerName;

	while (choice != 'q')
	{
		cout << "Select an option:\n" << "p (play)\n" << "a (add a new player to the game)\n" << "r (remove an existing player)\n" << "l (list existing players)\n" << "q (quit)\n";
		cin >> choice;

		switch (choice)
		{
		case 'p':
			if (Names.GetSize() == 0)
			{
				cout << "No players available\n";
				continue;
			}
			Stage3(Names, fout);
			break;
		case 'a':
			cout << "Player Name: ";
			cin >> PlayerName;
			Names.AddBack(PlayerName);
			continue;

		case 'r':
			cout << "Player Name: ";
			cin >> PlayerName;
			Names.Remove(PlayerName);
			continue;
		case 'l':
			if (Names.GetSize() == 0)
			{
				cout << "No players available\n";
				continue;
			}
			Names.Kiir();
			continue;
		case 'q':
			break;
		default:
			cout << "Select a valid option\n";
		}

	}
}

int main()
{	
	int PlayersNr;
	CircularLinkedList<string>Names;
	ifstream fin("be1.txt");
	ofstream fout("ki1.txt");
	Stage1(PlayersNr, Names, fin);
	Stage2(Names, fout);
	return 0;
}
