#include "komiwojazer.h"

class fileReader
{
public:
	string fileName;
	vector<vector<int>> tablica;
	vector <przedmiot> zbiorPrzedmiotow;
	int miasta;
	int pojemnosc;
	int ilPrzedmiotow;
public:
	fileReader();
	fileReader(int a);

	bool file_read_line(ifstream &file, int tab[], int size);
	void file_read_graph(string file_name);
	void file_read_backpack(string file_name);
};

