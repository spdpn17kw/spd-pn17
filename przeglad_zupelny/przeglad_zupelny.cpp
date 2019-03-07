#include "pch.h"
#include <iostream>
#include "przeglad_zupelny.h"
#include <algorithm>
#include <fstream>

using namespace std;


int Cmax(int ex[4], int tm1[4], int tm2[4], int tm3[4]) {
	int i=1, j=1;
	int Cij = tm1[ex[0]];
	for (i; i < 4; i++) {
		int Cj[4];
		Cj
	}
}
int main()
{
	int number_of_ex,n_m,ex[100],t_m1[10],t_m2[10],t_m3[10];
	ifstream data("data.txt");
	data >> number_of_ex;
	data >> n_m;
	for (int i = 1; i <= number_of_ex; i++) {
		ex[i - 1] = i;
		data >> t_m1[i - 1] >> t_m2[i - 1] >> t_m3[i - 1];
	}
	data.close();

		cout << "The 3! possible permutations with 3 elements:\n";
		do {
			for (int i = 0; i < number_of_ex; i++) cout << ex[i]<<' ';
			int Cmax;
			Cmax = t_m3[ex[0]]
			cout << '\n';
		} while (next_permutation(ex, ex + number_of_ex));
}

