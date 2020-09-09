#include <iostream>
#include <complex>
#include <math.h>
#include <fstream>

#define SIDE 2048
#define ITER_MAX 2048
#define PREC 15

typedef unsigned int u32;
typedef unsigned char u8;
typedef float db;

//checked for bugs
db setP(db num, u8 p) {
	int n = (int)(num * pow(10,p));
	db res = (db)(n / pow(10,p));
	return res;
}


//checked for bugs
db calcStep() {
	u32 side = SIDE;
	db step = 4.0 / side;
	return step;
}

//checked for bugs
u32 calcPt(db p) {
	u32 res = (u32)((p+2)*(SIDE/4));
	return res;
}


u32 mandelbrot(const std::complex<float>& zorc) {

	//for julia set
	//std::complex<float> c(0.355,0.355);
	//std::complex<float> z(zorc);

	//for mandelbrot set
	std::complex<float> c(zorc);
	std::complex<float> z(0,0);

	u32 n = 0;

	while(std::abs(z) <= 2 && n < ITER_MAX) {
		//debug
		//std::cout << real(z) << " " << imag(z) << "i" << std::endl;

		z = z*z + c;
		db r = setP(real(z),PREC);
		db i = setP(imag(z),PREC);
		std::complex<float> z(r,i);

		n++;
	}
	return n;
}

//checked for bugs
void plot(db x, db y, u32 n, std::ofstream& out) {
	u32 X = calcPt(x);
	u32 Y = calcPt(y);
	u8 r = 0;
	u8 g = n*15 + 42 % 255;
	u8 b = 75;
	if(n == ITER_MAX)
		out << "0 0 0" << std::endl;
	else
		out << (int)r << " " << (int)g << " " << (int)b << std::endl;

	//debug
	//std::cout << (int)r << " " << (int)g << " " << (int)b << std::endl;
}

//checked for bugs
db step = calcStep();
u32 side = SIDE;

int main() {

	std::ofstream out("mandelbrot2.ppm");
	out << "P3" << std::endl;
	out << SIDE << " " << SIDE << std::endl;
	out << "255" << std::endl;

	//std::complex<float> a(0.5,-0.5);
	//std::cout << mandelbrot(a) << std::endl;

	for(db y = -2; y < 2; y+=step) {
		if(y > SIDE)
			break;
		for(db x = -2; x < 2; x+=step) {
			if(x > SIDE)
				break;
			u32 n = mandelbrot(std::complex<float>(x,y));
			plot(x,y,n,out);
		}
	}
}