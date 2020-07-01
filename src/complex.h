#ifndef COMPLEX_H
#define COMPLEX_H
#include <ostream>

class complex { 
public:
	double r;
	double i;

	complex();
	complex(const complex&);
	complex(double, double);
	~complex();

	const complex& operator = (const complex&);
}; 

double re(const complex&);
double im(const complex&);

complex operator + (const complex&, const complex&);
complex operator - (const complex&, const complex&);
complex operator * (const complex&, const complex&);
complex operator / (const complex&, const complex&);

complex operator * (const complex&, double num);
complex operator / (const complex&, double num);

double distance(const complex&, const complex&);

std::ostream& operator << (std::ostream&, const complex&);

#endif