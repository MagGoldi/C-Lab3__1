#include "Class.h"
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include <iostream>
#include <math.h>
#define PI 3.14159265    
using namespace std;


void PrintMenu1() {
	cout << "1. Create polyline\n";
	cout << "2. Create a polyline that is the sum of two polylines\n";
	cout << "3. Add a vertex to the end of a polyline\n";
	cout << "4. Add a vertex to the beginning of the polyline\n";
	cout << "5. Add vertices from another polyline to the end of a polyline\n";
	cout << "6. Change vertex to some polyline\n";
	cout << "7. Do an extra task\n";
}

short get_key() {
	short key = _getch();
	cout << key;
	if (key == 0 || key == 224)
	{
		return _getch();
	}
}


void allocate(Broken** arr, int* size) {
	*size += 20;
	*arr = new Broken[*size];
}

void init_cap(int* n, Broken* arr) {
	int cap = 50;
	arr[*n] = Broken(cap);
	*n += 1;
}

void init_polyline(const int n, Broken* arr) {
	int a = 0;
	Points p = { 0.0, 0.0 };

	do {
		printf("\nHow many points do you want to set NOW in the %d polyline: ", n);
		scanf_s("%d", &a);
	} while (a <= 0 || a > arr[n - 1].get_cap());
	for (int i = 0; i < a; i++) {
		printf("Enter the %d - th vertex:\n", i + 1);
		printf("\tEnter x: ");
		scanf_s("%lf", &p.x);
		printf("\tEnter y: ");
		scanf_s("%lf", &p.y);
		printf("\n");
		arr[n - 1][i] = p;
		arr[n - 1].set_n();
	}
}

void item_7(const int n, Broken* arr) {    
	
	//Enter the number N - the number of vertices in the polyline (N>2)

	int a = 0;
	double len = 0;
	double angle = 0, result_x = 0, result_y = 0;
	Points p = { 0.0, 0.0 };
	do {
		cout<<"\nEnter the number N - the number of vertices in the polyline (N>2): ";
		cin >> a;
		cout<<"\nEnter the length of the polyline: ";
		cin >> len;
	} while (a <= 2 || a > arr[n - 1].get_cap());  

	angle = ((a - 2) * 180) / a;

	std::cout << "\npoint: 0" << endl;
	std::cout << "x = " << result_x << "\n";
	std::cout << "y = " << result_y << "\n";
	arr[n - 1][0] = p;
	arr[n - 1].set_n();

	for (int i = 1; i < a; i++) {
		result_x = (result_x + len * cos((i-1) * ((180 - angle) * PI / 180)));
		result_y = (result_y + len * sin((i-1) * ((180 - angle) * PI / 180)));
		p.x = result_x;
		p.y = result_y;

		std::cout << "\npoint: " << i << "\n";
		std::cout << "x = " << result_x << "\n";
		std::cout << "y = " << result_y << "\n";
		arr[n - 1][i] = p;
		arr[n - 1].set_n();
	}
	p.x = 0;
	p.y = 0;
	arr[n - 1][a] = p;
	arr[n - 1].set_n();

}

Points item_3_4(int* a, int n) {
	Points p = { 0.0, 0.0 };

	system("CLS");
	do {
		printf("Select available polyline: ");
		scanf_s("%d", a);
		if (*a < 0 || *a > n - 1) printf("Error. You have typed an unavailable polyline number.\n\n");

	} while (*a < 0 || *a > n - 1);

	printf("\tEnter x: ");
	scanf_s("%lf", &p.x);
	printf("\tEnter y: ");
	scanf_s("%lf", &p.y);
	printf("\n");

	return p;
}

void item_2_5(int* a, int* b, int n) {
	system("CLS");
	do {
		printf("Select the FIRST available polyline: ");
		scanf_s("%d", a);
		printf("Select the SECOND available polyline: ");
		scanf_s("%d", b);
		if (*a < 0 || *a > n - 1 || *b < 0 || *b > n - 1) printf("Error. You have typed an unavailable polyline number.\n\n");

	} while (*a < 0 || *a > n - 1 || *b < 0 || *b > n - 1);

}

void list_line(Broken* arr, int n) {
	Points p = { 0.0, 0.0 };

	for (int i = 0; i < n; i++) {
		printf("\nPolyline number %d\n", i + 1);
		p = arr[i][0];
		printf("\tVertex: (%.3lf, %.3lf)", p.x, p.y);
		for (int j = 1; j < arr[i].get_n(); j++) {
			p = arr[i][j];
			printf(" -> (%.3lf, %.3lf)", p.x, p.y);
		}
		printf("\nPolyline length: %.3lf\n\n", arr[i].len_broken());
	}
}

Points item_6(int* a, int* b, int n, Broken* arr) {
	Points p = { 0.0, 0.0 };

	system("CLS");
	do {
		printf("In which polyline do you want to change the vertex?: ");
		scanf_s("%d", a);
		printf("Which vertex do you want to change?: ");
		scanf_s("%d", b);
		if (*a < 0 || *b < 0 || *a > n || *b > arr[*a].get_n()) {
			printf("Error. You entered unreachable values somewhere.\n\n");
		}
	} while (*a < 0 || *b < 0 || *a > n - 1 || *b > arr[*a].get_n() - 1);

	printf("\nPolyline number %d\n", *a);
	p = arr[*a][0];
	printf("\tVertex: (%.3lf, %.3lf)\n", p.x, p.y);
	int answerd = 0;
	bool Flag = false;
	do {
		cout << "\nDo you want to change the value ? " << endl;
		cout << "\tChange - 1" << endl;
		cout << "\tNo - 2" << endl;
		cout << "Answerd:";
		cin >> answerd;
		if (answerd == 1 or answerd == 2) { Flag = true; }
	} while (Flag = false);
	if (answerd == 1) {
		printf("\tEnter x: ");
		scanf_s("%lf", &p.x);
		printf("\tEnter y: ");
		scanf_s("%lf", &p.y);
		return p;
	}
	if (answerd == 2) { }
	return p;
}
