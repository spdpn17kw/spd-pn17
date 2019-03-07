#include "pch.h"
#include <iostream>
#include "przeglad_zupelny.h"
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	int number_of_ex,ex[100];
	ifstream data("data.txt");
	data >> number_of_ex;
	for (int i = 1; i <= number_of_ex; i++) {
		ex[i - 1] = i;
	}
	//for (int i = 0; i < number_of_ex; i++) cout << ex[i];

		cout << "The 3! possible permutations with 3 elements:\n";
		do {
			for (int i = 0; i < number_of_ex; i++) cout << ex[i]<<' ';
			cout << '\n';
		} while (next_permutation(ex, ex + number_of_ex));
}

