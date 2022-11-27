#include<stdio.h>
#include <windows.h>
#include <iostream>
#include "Class.h"
#include "functions.h"
using namespace std;

int main() {
	int size = 0, n = 0;
	Broken* arr = NULL;
	Points p = {0.0, 0.0};
	int current = 1, key = 0;
	int a = 0, b = 0;

	allocate(&arr, &size);

	init_cap(&n, arr);
	init_polyline(n, arr);
	init_cap(&n, arr);
	init_polyline(n, arr);

	int input;
	bool in1 = true;

	while (in1) {
		system("CLS");
		PrintMenu1();
		list_line(arr, n);
		cout << "Task number: ";
		cin >> input;

		switch (input)
		{
		case(1):
		{
			if (n >= size) allocate(&arr, &size);
			system("CLS");
			init_cap(&n, arr);
			init_polyline(n, arr);
			break;
		}
		case(2):
		{
			if (n >= size) allocate(&arr, &size);
			item_2_5(&a, &b, n);
			arr[n] = arr[a] + arr[b];
			n++;
			break;
		}
		case(3):
		{ arr[a] << item_3_4(&a, n);
		break; }
		case(4):
		{ arr[a] >> item_3_4(&a, n);
		break; }
		case(5): {
			item_2_5(&a, &b, n);
			cout << "\n\nThe variable polyline is the number of the first polyline you enter";
			arr[a] += arr[b];
			break;
		}
		case(6): {
			arr[a][b] = item_6(&a, &b, n, arr);
			break;
		}
		case(7): {
			if (n >= size) allocate(&arr, &size);

			system("CLS");
			init_cap(&n, arr);
			item_7(n, arr);
			break;
		}
		case(8): {
			item_2_5(&a, &b, n);
			bool tmp = arr[a] == arr[b];
			item_8(&a, &b, tmp);
		}
		}
	}

	delete[] arr;
}

