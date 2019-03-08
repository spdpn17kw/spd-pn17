#include "pch.h"
#include <iostream>
#include "przeglad_zupelny.h"
#include <algorithm>
#include <fstream>

using namespace std;


int cmax(int ex[4], int tm1[4], int tm2[4], int tm3[4]) {
	int Cm1[5], Cm2[5], Cm3[5];
	Cm1[0] = 0;
		//pierwsza maszyna
		for (int j = 1; j <= 4; j++) {
			Cm1[j] = max(Cm1[j - 1],0) + tm1[ex[j-1]-1];
		}
		//druga maszyna
		for (int j = 1; j <= 4; j++) {
			Cm2[j] = max(Cm2[j - 1], Cm1[j]) + tm2[ex[j - 1] - 1];
		}
		//trzecia maszyna
		for (int j = 1; j <= 4; j++) {
			Cm3[j] = max(Cm3[j - 1], Cm2[j]) + tm3[ex[j - 1] - 1];
		}
		return Cm3[4];
	
}
int main()
{
	int number_of_ex,n_m,ex[4],t_m1[10],t_m2[10],t_m3[10];
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
			Cmax = cmax(ex,t_m1,t_m2,t_m3);
			cout << "Cmax= " << Cmax;
			cout << '\n';
		} while (next_permutation(ex, ex + number_of_ex));
}

