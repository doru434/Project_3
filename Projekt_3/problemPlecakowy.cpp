#include "fileReader.h"



problemPlecakowy::problemPlecakowy(int pojemnosc, vector <przedmiot> &zbiorPrzedmiotow)
{
	wartoscPlecaka = 0;
	rozmiar = pojemnosc;
	przedmioty = zbiorPrzedmiotow;

	//bruteforce();
	//zachlanny();
	//showB();
	//showZ();
}
void problemPlecakowy::bruteforce()
{

	vector<przedmiot> empty;
	podzbiory.push_back(empty);

	int twaga,temp=0,index;
	for (int i = 0; i < przedmioty.size(); i++)
	{
		vector< vector<przedmiot> > subsetTemp = podzbiory;

		twaga = 0;
		for (int j = 0; j < subsetTemp.size(); j++)
		{
			subsetTemp[j].push_back(przedmioty[i]);
		}

		for (int j = 0; j < subsetTemp.size(); j++)
		{
			twaga = 0;
			for (int x = 0; x < subsetTemp[j].size(); x++)
			{
				twaga = twaga + subsetTemp[j][x].waga;
			}
			if (twaga <= rozmiar)
			{
				podzbiory.push_back(subsetTemp[j]);
			}
		}
	}
}

void problemPlecakowy::showB()
{
	cout << endl << "Przeglad zupelny" << endl<<endl;
	int temp = 0,temp1=0, index = 0;
	wartoscPlecaka = 0;
	cout << "Pojemnosc:  " << rozmiar << endl;
	cout << "Przedmioty: " << przedmioty.size() << endl;
	
	cout << "Rozmiar		Wartosc" << endl;
	cout << "-------------------------------" << endl;
	for (int i = 0; i < przedmioty.size(); i++)
	{
		cout << przedmioty[i].waga << "		" << przedmioty[i].wartosc << endl;
	}

	cout <<endl<< "Rozwiazanie" << endl;
	cout << "-------------------------------" << endl;
	cout << "Rozmiar		Wartosc" << endl;
	cout << "-------------------------------" << endl;
	
	for (int i = 0; i < podzbiory.size(); i++)
	{
		for (int j = 0; j < podzbiory[i].size(); j++)
		{
			temp += podzbiory[i][j].wartosc;	
		}
		if (temp > wartoscPlecaka)
		{
			wartoscPlecaka = temp;
			index = i;
		}
		temp = 0;
	}

	for (int i = 0; i < podzbiory[index].size(); i++)
	{
		cout << podzbiory[index][i].waga << "		" << podzbiory[index][i].wartosc << endl;
		temp1 += podzbiory[index][i].waga;
	}
	cout << "-------------------------------" << endl;
	cout << temp1<<"		"<< wartoscPlecaka << endl;
}
void problemPlecakowy::zachlanny()
{
	int tempWaga = 0;

	sort(przedmioty.begin(), przedmioty.end(), [](const przedmiot& lhs, const przedmiot& rhs)
	{
		double a = (lhs.wartosc / lhs.waga);
		double b = (rhs.wartosc / rhs.waga);
		return a > b;
	});
	for (int i = 0; i < przedmioty.size(); i++)
	{
		if (tempWaga + przedmioty[i].waga <= rozmiar)
		{
			tempWaga += przedmioty[i].waga;
			zach.push_back(przedmioty[i]);
		}
		else if (tempWaga == rozmiar)
			break;
	}
}

void problemPlecakowy::showZ()
{
	cout << endl << "Zachlanny" << endl<<endl;
	wartoscPlecaka = 0;
	int temp1 = 0;
	cout << "Pojemnosc:  " << rozmiar << endl;
	cout << "Przedmioty: " << przedmioty.size() << endl;

	cout << "Rozmiar		Wartosc" << endl;
	cout << "-------------------------------" << endl;
	for (int i = 0; i < przedmioty.size(); i++)
	{
		cout << przedmioty[i].waga << "		" << przedmioty[i].wartosc << endl;
	}

	cout << endl << "Rozwiazanie" << endl;
	cout << "-------------------------------" << endl;
	cout << "Rozmiar		Wartosc" << endl;
	cout << "-------------------------------" << endl;

	for (int i = 0; i < zach.size(); i++)
	{
		cout << zach[i].waga << "		" << zach[i].wartosc << endl;
		temp1 += zach[i].waga;
		wartoscPlecaka += zach[i].wartosc;
	}
	cout << "-------------------------------" << endl;
	cout << temp1 << "		" << wartoscPlecaka << endl;
}