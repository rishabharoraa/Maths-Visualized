class complex { 
public:
	double r;
	double i;

	complex();
	complex(const complex&);
	complex(double, double);
	~complex();
}; 

const complex& operator + (const complex&, const complex&);
const complex& operator - (const complex&, const complex&);
const complex& operator * (const complex&, const complex&);
const complex& operator / (const complex&, const complex&);
//const complex& operator = (const complex&, const complex&);

const complex& operator * (const complex&, double num);
const complex& operator / (const complex&, double num);

const complex& absol(const complex&);

double re(const complex&);
double im(const complex&);