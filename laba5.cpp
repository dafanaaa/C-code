#include <cstdlib> //заголовок для стандартной библиотеки С
#include <iostream> //заголовок для поддержки системы ввода-вывода в С++
#include <Windows.h> //заголовок для поддержки Windows API в С и С++
#include <string.h>

using namespace std;

class Massive {
public:
	int n, m;
	Massive() : n(10), m(10) {}
	Massive(int a, int b) : n(a), m(b) {}
	
	int** A = new int* [n];
	void createmassive()
	{
		for (int i = 0; i < n; i++) {
			A[i] = new int[m];
		}
	}
	void filling() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				A[i][j] = rand() % 10;
			}
		}
	}
	void output() {
		cout << "Исходная матрица:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << A[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
};
class Additions:public Massive {
public:
	int B[10];
	void createmassive2()
	{
		for (int i = 0; i < 10; i++) {
			B[i] = 0;
		}
	}
	int l, h;
	Additions() : l(6), h(2) {}
	Additions(int c, int d) : l(c), h(d) {}
};
class Search :public Additions {
public:
	void expectedvalue() {
		float summ = 0;
		float M;
		float k = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (A[i][j] < h && A[i][j] > l) {
					summ = summ + A[i][j];
					k++;
				}
		M = summ / k;
		cout << "Математическое ожидание равно: " << M << "\n";
	}
	void searchmod() {
		int moda = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (A[i][j] > l && A[i][j] < h) {
					switch (A[i][j]) {
					case 0: B[0] = B[0] + 1; break;
					case 1: B[1] = B[1] + 1; break;
					case 2: B[2] = B[2] + 1; break;
					case 3: B[3] = B[3] + 1; break;
					case 4: B[4] = B[4] + 1; break;
					case 5: B[5] = B[5] + 1; break;
					case 6: B[6] = B[6] + 1; break;
					case 7: B[7] = B[7] + 1; break;
					case 8: B[8] = B[8] + 1; break;
					case 9: B[9] = B[9] + 1; break;
					}
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			if (B[i] > moda)
				moda = i;
		}
		cout << "Мода равна: " << moda << "\n";
	}
};
class Results : public Search{
public:
	int a, b, c, d;
	Results(int A, int B, int C, int D):a(A), b(B), c(C), d(D) {}
	void main(void) {
		Search mass;
		Additions* mass1 = &mass;
		Massive* mass2 = &mass;
		mass.n = a;
		mass.m = b;
		mass.l = c;
		mass.h = d;
		mass.createmassive();
		mass.filling();

		mass.output();
		mass.createmassive2();
		mass.expectedvalue();
		mass.searchmod();
	}
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int A, B;
	do {  //начало цикла с постусловием
		cout << "Введите целое число, количество строк матрицы(не более 15):";  //вывод подсказки для пользователя
		cin >> A;  //ввод значения для переменной n
	} while (A > 15);  //проверка условия
	do {
		cout << "Введите целое число, количество столбцов матрицы(не более 20):";
		cin >> B;
	} while (B > 20);
	int C, D;
	cout << "Введите нижнюю границу нужного интервала:";
	cin >> C;
	do {
		cout << "Введите верхнюю границу нужного интервала:";
		cin >> D;
	} while (C >= D);

	Results result(A, B, C, D);
	result.main();


	
	system("PAUSE");
	return 0;
}