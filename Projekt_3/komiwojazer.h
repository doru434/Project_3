#include "problemPlecakowy.h"
class komiwojazer
{
public:
	int miasta;

	int droga;
	vector <int> show;

	vector<vector <int>> komi;
	komiwojazer(vector<vector <int>> &tab, int mias);
	void przegladZupelny();
	void zachlanny();
	void showZ();
	void showZach();
};

