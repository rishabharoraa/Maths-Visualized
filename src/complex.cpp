#include "complex.h"

complex :: complex() {
	this->r = 0;
	this->i = 0;
}

complex :: complex(const complex& a) {
	this->r = a.r;
	this->i = a.i;
}

complex :: complex(double a, double b) {
	this->r = a;
	this->i = b;
}

complex :: ~complex() { };

const complex& operator + (const complex& a, const complex& b) {
	complex res;
	res.r = a.r + b.r;
	res.i = a.i + b.i;
	return res;
}

const complex& operator - (const complex& a, const complex& b) {
	complex res;
	res.r = a.r - b.r;
	res.i = a.i - b.i;
	return res;
}

const complex& operator * (const complex& a, const complex& b) {
	complex res;
	res.r = (a.r*b.r) - (a.i*b.i);
	res.i = (a.i*b.r) + (a.r*b.i);
	return res;
}

const complex& operator / (const complex& a, const complex& b) {
	complex res;
	res.r = ((a.r*b.r) + (a.i*b.i)) / ((b.r*b.r) + (b.i*b.i));
	res.i = ((a.i*b.r) - (a.r*b.i)) / ((b.r*b.r) + (b.i*b.i));
	return res;
}

const complex& operator * (const complex& a, double k) {
	complex res;
	res.r = a.r * k;
	res.i = a.i * k;
	return res;
}

const complex& operator / (const complex& a, double k) {
	complex res;
	res.r = a.r / k;
	res.i = a.i / k;
	return res;
}