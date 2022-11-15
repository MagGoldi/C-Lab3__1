#include<stdio.h>
#include <windows.h>
#include <iostream>
#include "Class.h"
#include "functions.h"

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

	while (1) {
		if (current < 1) current = 7; 
		if (current > 7) current = 1;
		menu(current);
		list_line(arr, n);
		keyboard(&current, &key);

		try {
			if (key == -1) break;

			if (key == 1 && current == 1) {
				if (n >= size) allocate(&arr, &size);

				system("CLS");
				init_cap(&n, arr);
				init_polyline(n, arr);
			}

			if (key == 1 && current == 2) {
				if (n >= size) allocate(&arr, &size);

				item_2_5(&a, &b, n);
				arr[n] = arr[a] + arr[b];
				n++;
			}

			if (key == 1 && current == 3) { arr[a] << item_3_4(&a, n); }

			if (key == 1 && current == 4) { arr[a] >> item_3_4(&a, n); }

			if (key == 1 && current == 5) {
				item_2_5(&a, &b, n);
				printf("\n\nThe variable polyline is the number of the first polyline you enter");
				arr[a] += arr[b];
			}

			if (key == 1 && current == 6) { 
				arr[a][b] = item_6(&a, &b, n, arr); 
			}

			if (key == 1 && current == 7) { 
				if (n >= size) allocate(&arr, &size);

				system("CLS");
				init_cap(&n, arr);
				item_7(n, arr);	
			}
		}

		catch (const char* ex) { printf("%s", ex); }
	}

	delete[] arr;
}

