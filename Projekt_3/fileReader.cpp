#include "fileReader.h"


fileReader::fileReader()
{
	cout << "Podaj nazwe pliku dla problemu komiwojazera" << endl;
	cin >> fileName;
	file_read_graph(fileName);
}
fileReader::fileReader(int a)
{
	cout << "Podaj nazwe pliku dla problemu plecakowego" << endl;
	cin >> fileName;
	file_read_backpack(fileName);
}
bool fileReader::file_read_line(ifstream &file, int tab[], int size)
{
	string s;
	getline(file, s);

	if (file.fail() || s.empty())
		return(false);

	istringstream in_ss(s);

	for (int i = 0; i < size; i++)
	{
		in_ss >> tab[i];
		if (in_ss.fail())
			return(false);
	}
	return(true);
}

void fileReader::file_read_graph(string file_name)
{
	ifstream file;
	int tab[4];
	vector <int> vec;
	file.open(file_name.c_str());

	if (file.is_open())
	{
		if (file_read_line(file, tab, 1))
		{
			miasta = tab[0];				//miasta
			int *tab = new int[miasta];
			for (int i = 0; i < miasta; i++)
			{
				tablica.push_back(vec);
				if (file_read_line(file, tab, miasta))
				{
					for (int j = 0; j < miasta; j++)
					{
						tablica[i].push_back(tab[j]);
					}
				}
				else
				{
					cout << "File error - READ EDGE" << endl;
					break;
				}
			}
		}
		else
			cout << "File error - READ INFO" << endl;
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}
void fileReader::file_read_backpack(string file_name)
{
	przedmiot a;
	ifstream file;
	int tab[2];
	file.open(file_name.c_str());

	if (file.is_open())
	{
		if (file_read_line(file, tab, 2))
		{
			pojemnosc = tab[0];				//pojemnosc plecaka
			ilPrzedmiotow = tab[1];			//ilosc przedmiotow

			for (int i = 0; i <ilPrzedmiotow; i++)
				if (file_read_line(file, tab, 2))
				{
					zbiorPrzedmiotow.push_back(a = { tab[0],tab[1]});
				}
				else
				{
					cout << "File error - READ EDGE" << endl;
					break;
				}
		}
		else
			cout << "File error - READ INFO" << endl;
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}

