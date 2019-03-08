#include "pch.h"
#include <iostream>
#include "przeglad_zupelny.h"
#include <algorithm>
#include <fstream>

using namespace std;


int cmax(int ex[],int **macierz, int **Cm, int number_of_ex,int n_m) {
	int n_ex=number_of_ex+1;
	for (int i = 0; i <= n_m; i++) Cm[0][i] = 0;
	for (int i = 0; i < n_ex; i++) Cm[i][0] = 0;
	for (int i = 1; i <= n_m; i++){ //vdvdc
		for (int j = 1; j <= number_of_ex; j++) {
			Cm[j][i] = max(Cm[j][i - 1], Cm[j-1][i]) + macierz[ex[j - 1]-1][i-1];
			//cout << "Cm[" << j << "][" << i << "] = " << Cm[j][i];
		}
		
	}
		return Cm[n_ex-1][n_m];
	
}
int main()
{
	int number_of_ex, n_m;
	ifstream data("data.txt");
	data >> number_of_ex;
	int * ex = new int[number_of_ex];
	data >> n_m;
	int **macierz = new int * [number_of_ex];
	int **Cm = new int *[number_of_ex + 1];
	for (int j = 0; j < number_of_ex+1; j++) Cm[j] = new int[n_m+1];
	for (int j = 0; j < number_of_ex; j++) {
		ex[j] = j+1;
		macierz[j] = new int[n_m];
		for(int i=0;i<n_m;i++)
		data >> macierz[j][i];
	}
	data.close();
	// wyswietlenie
	/*for (int i = 0; i < number_of_ex; ++i)
	{
		for (int j = 0; j < n_m; ++j)
			cout << macierz[i][j] << " ";
		cout << "\n";
	}*/int number=1;
		cout << "The 3! possible permutations with 3 elements:\n";
		do {
			cout << number << ". ";
			for (int i = 0; i < number_of_ex; i++) cout << ex[i]<<' ';
			int Cmax;
			Cmax = cmax(ex,macierz,Cm,number_of_ex,n_m);
			cout << "Cmax= " << Cmax;
			cout << '\n';
			number++;
		} while (next_permutation(ex, ex + number_of_ex));
}


