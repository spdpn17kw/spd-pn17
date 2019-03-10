
#include <vector>
#include <fstream>
#include <cstdio>
#include <iostream>
#include<algorithm>
#include <fstream>
#include<memory.h>

using namespace std;
int cmax(int**, int, int);

void wyswietl(int **tab,int l_zadan) {
	for (int i = 0; i < l_zadan; i++) {
		for (int j = 0; j < 3; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

void min(int **tab,int *nr_zadania,int l_zadan) {
	int min = 99999999;

	for (int i = 0; i < l_zadan; i++) {
		for (int k = 0; k < 2; k++) {
			if (min > tab[i][k]) {



				min = tab[i][k];

				nr_zadania[0] = k;
				nr_zadania[1] = i;

			}
		}
 }

	for (int i = 0; i < 2; i++) {
		tab [nr_zadania[1]][i] = 99999999;
	}


}

void johsons(int **tab,int *nr_zadania, int l_zadan)
{

	int **tab1 = new int *[l_zadan];
	for (int i = 0; i < l_zadan; i++) {
		tab1[i] = new int[2];
	}

	//int ustawienie[l_zadan] = { 0,0,0,0 };
	int *ustawienie = new int[l_zadan];
	memset(ustawienie, 0, l_zadan*sizeof(ustawienie));


	for (int i = 0; i < l_zadan; i++) {
		for (int j = 0; j < 2; j++) {
			tab1[i][j] = tab[i][j] + tab[i][j+1];

		}
	}
	for (int i = 0; i < l_zadan; i++) {
		min(tab1, nr_zadania,l_zadan);
		//cout << nr_zadania[0];
		if (nr_zadania[0] == 0) {
			for (int j = 0; j < l_zadan; j++) {
				if (ustawienie[j] == 0) {
					ustawienie[j] = nr_zadania[1]+1;
					break;
				}
			}
		}
		if (nr_zadania[0] == 1) {
			for (int j = 3; j >= 0; j--) {
				if (ustawienie[j] == 0) {
					ustawienie[j] = nr_zadania[1]+1;
					break;
				}
			}
		}
	}

	cout << endl << "ustawienie zadan:";
	for (int i = 0; i < l_zadan; i++) {
		cout <<ustawienie[i] << " ";
	}

	int ** kopia = new int *[l_zadan];
	for (int i = 0; i < l_zadan; i++) {

		kopia[i] = tab[ustawienie[i]-1];
	}

	cmax(kopia, l_zadan, 3);
	//wyswietl(kopia,l_zadan);
}



int cmax(int **tab, int N, int M) {
	int *maxy = new int[M + 1];
	for (int i = 0; i<M + 1; i++)
	{
		maxy[i] = 0;
	}

	for (int k = 0; k<N; k++) {
		for (int i = 1; i<M + 1; i++) {

			maxy[i] = max(maxy[i - 1], maxy[i]) + tab[k][i-1];
		}

	}
	cout << "cmax wynosi:";
	cout <<endl<< maxy[M]<<endl;
	return maxy[M];
}

int main()
{
	int l_zadan;
	cout << "ile zadan ma problem ?";
	cin >> l_zadan;
	int **tab = new int *[l_zadan];
	int nr_zadania[2] = { 0,0 };

	for (int i = 0; i < l_zadan; i++) {
		tab[i] = new int[3];
	}

	vector  <int> usuniete_zadania;
	ifstream data("data.txt");
	if (data.is_open())
	{
		//plik nie zosta³ otwarty

		while (true) {
			if (data.eof())
				break;

			for (int i = 0; i < l_zadan; i++) {
				for (int j = 0; j < 3; j++) {
					data >> tab[i][j];
				}
			}

		}
	}
	else {
		cout << "b³ad w otwarciu pliu";
	}

	wyswietl(tab,l_zadan);
	johsons(tab,nr_zadania,l_zadan);
	system("pause");
    return 0;
}


