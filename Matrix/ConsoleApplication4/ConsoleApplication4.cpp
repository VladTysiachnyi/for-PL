#include "stdafx.h"
#include <iostream>
#include<ctime>
using namespace std;

class Matrix
{
private:
	 int **Matr;
	 int m;
	 int n;

	void Create()
	{
		Matr = new int*[m];
		for (int i = 0; i< m; i++) {
			Matr[i] = new int[n];
			for (int j = 0; j < n; j++) {
				Matr[i][j] = rand() % 10;
			}
		}
	}

public:
	// constructors and destructor
	Matrix() : m(5), n(5) { Create(); }
	Matrix(int i) : m(i), n(i) { Create();}
	Matrix(int i, int j) : m(i), n(j) { Create();}

	~Matrix()
	{
		for (int i = 0; i<m; i++)
			delete[] Matr[i];
		delete[] Matr;
	}

	// methods
	void Display()
	{
		
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				cout.width(4);
				cout << Matr[i][j];
			}
			cout << endl;
		}
	}//

	int get(int i, int j) {
		return Matr[i][j];
	}

	int getNumRows() {
		return m;
	}

	int getNumCols() {
		return n;
	}

	//math functions
	void add( Matrix& r) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				Matr[i][j] += r.get(i, j);
			}
		}
	}//end void add

	void substract(Matrix& r) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				Matr[i][j] -= r.get(i, j);
			}
		}
	}//end substract

	void multiple(Matrix& r) {
		int **temp = new int*[m];
		for (int i = 0; i < m; i++) {
			temp[i] = new int[n];
			for (int j = 0; j < n; j++) {
				temp[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					temp[i][j] = Matr[i][k] * r.get(k, j);
				}
			}
		}
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					std::cout << temp[i][j] << " ";
					
				}
				std::cout << std::endl;
			}
	}
};


int main()
{
	srand(time(NULL));
	system("cls");
	std::cout << "Program about matrix\n\n";
	int m,n;
	
	std::cout << "\nEnter rows quantity for first matrix: ";
	std::cin >> m;
	std::cout << "Enter cols quantity for first matrix: ";
	std::cin >> n;
	Matrix mat1(m, n);
	std::cout << "\nYour matrix: \n";
	mat1.Display();
	std::cout << "\nEnter rows quantity for second matrix: ";
	std::cin >> m;
	std::cout << "Enter cols quantity for second matrix: ";
	std::cin >> n;
	Matrix mat2(m, n);
	std::cout << "\nYour matrix: \n";
	mat2.Display();
	
	int c;
	std::cout << "Choose operation:\n 1)addition - 1\n 2)substraction - 2\n 3)multiplication - 3\n";
	std::cin >> c;
	switch (c) {
	case 1: 
		mat1.add(mat2);
		std::cout << "\n\nMatrix after addition:\n";
		mat1.Display();
		break;
	
	case 2: 
		std::cout << "\n\nMatrix after substraction:\n";
		mat1.substract(mat2);
		mat1.Display();
		break;
	
	case 3: 
		std::cout << "\n\nMatrix after multiplication:\n";
		mat1.multiple(mat2);
		break;
	
	}

	std::cout << "Do you want to do something else? (1/2) ";
	int a;
	std::cin >> a;
	if (a) main();
	
	system("pause");
	return 0;
}