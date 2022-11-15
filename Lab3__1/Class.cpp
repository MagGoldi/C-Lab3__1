#include<math.h>
#include "Class.h"
#include <iostream>

Broken::Broken() :cap(0), n(0), data(NULL) {}

Broken::Broken(const int cap) : cap(cap), n(0) {
	data = new Points[cap];
}

Broken::~Broken() { delete[] data; }

Broken::Broken(const Broken& obj) : cap(obj.cap), n(obj.n) {
	data = new Points[cap];

	for (int i = 0; i < n; i++) {
		if (i < cap) data[i] = obj.data[i];
		else throw "Ошибка! Доступ за пределы выделенной памяти.";
	}
}

void Broken::memory() {
	cap += 4;
	Points* tmp_data = new Points[cap];

	for (int i = 0; i < n; i++) {
		if (i < cap) tmp_data[i] = data[i];
		else throw "Ошибка! Доступ за пределы выделенной памяти.";
	}

	delete[] data;
	data = tmp_data;
}

double Broken::len_broken() {
	double sum = 0;

	for (int i = 0; i < n - 1; i++) {
		//double x = 0, y = 0;
		//x = pow(data[i].x - data[i + 1].x, 2);
		//y = pow(data[i].x - data[i + 1].x, 2);
		sum += sqrt(pow(data[i].x - data[i + 1].x, 2) + pow(data[i].y - data[i + 1].y, 2));
	}

	return sum;
}

Broken Broken:: operator +(const Broken& obj) {
	Broken tmp_obj(cap + obj.cap);
	int tmp_cap = cap + obj.cap;
	tmp_obj.n = n + obj.n;

	for (int i = 0; i < n; i++) {
		if (i < tmp_cap) tmp_obj.data[i] = data[i];
		else throw "Ошибка! Доступ за пределы выделенной памяти.";
	}

	for (int i = n; i < tmp_obj.n; i++) {
		if (i < tmp_cap) tmp_obj.data[i] = obj.data[i - n];
		else throw "Ошибка! Доступ за пределы выделенной памяти.";
	}

	return tmp_obj;
}

void Broken:: operator +=(const Broken& obj) {
	if (cap <= n + obj.n) cap += obj.cap;

	Points* tmp_data = new Points[cap];

	for (short i = 0; i < n; i++) {
		if (i < cap) tmp_data[i] = data[i];
		else throw "Ошибка! Доступ за пределы выделенной памяти.";
	}

	for (short i = n; i < n + obj.n; i++) {
		if (i < cap) tmp_data[i] = obj.data[i - n];
		else throw "Ошибка! Доступ за пределы выделенной памяти.";
	}

	delete[] data;

	data = tmp_data;
	n += obj.n;
}

void Broken:: operator <<(const Points& str) {
	if (cap <= n) memory();
	data[n++] = str;
}

void Broken:: operator >>(const Points& str) {
	if (cap <= n) memory();

	Points* tmp_data = new Points[cap];

	for (int i = 0; i < n; i++) {
		if (i < cap) tmp_data[i + 1] = data[i];
		else throw "Ошибка! Доступ за пределы выделенной памяти.";
	}

	tmp_data[0] = str;

	delete[] data;
	data = tmp_data;
	n++;
}

Points& Broken:: operator [](int i) { return data[i]; }

int Broken::get_cap() const { return cap; }

int Broken::get_n() const { return n; }

void Broken::set_n() { n++; }

void Broken:: operator =(const Broken& obj) {
	data = new Points[obj.cap];
	n = obj.n;
	cap = obj.cap;
	for (int i = 0; i < n; i++) {
		if (i < cap) data[i] = obj.data[i];
		else throw "Ошибка! Доступ за пределы выделенной памяти.";
	}
}