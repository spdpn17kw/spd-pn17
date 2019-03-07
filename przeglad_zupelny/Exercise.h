#pragma once
class Exercise
{
public:
	int num_ex = 0; //numer zadania
	int t_m1 = 0;  //czas wykonywania zadania przez maszyne 1
	int t_m2 = 0;
	int t_m3 = 0;
	Exercise();
	Exercise(int t1, int t2, int t3) {
		t_m1 = t1;
		t_m2 = t2;
		t_m3 = t3;
	}
	~Exercise();
};

