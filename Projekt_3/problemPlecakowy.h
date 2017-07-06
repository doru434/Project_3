#include <chrono>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm> 

#include <cstdlib>
#include <ctime>

using namespace std;

struct przedmiot {
	int waga;
	int wartosc;
};
class problemPlecakowy
{
public:
	int rozmiar;
	int wartoscPlecaka;
	vector < vector <przedmiot>> podzbiory;
	vector <przedmiot> przedmioty;

	vector <przedmiot> zach;

public:
	problemPlecakowy(int pojemnosc,vector <przedmiot> &zbiorPrzedmiotow);
	void showB();
	void showZ();
	void bruteforce();
	void zachlanny();
};

