class complex { 
public:
	double real;
	double imaginary;

	complex();
	complex(const complex&);
	complex(double);
	complex(double, double);
	~complex();


}; 

const complex& operator + (const complex&, const complex&);
const complex& operator - (const complex&, const complex&);
const complex& operator * (const complex&, const complex&);
const complex& operator / (const complex&, const complex&);
const complex& operator = (const complex&, const complex&);

const complex& operator + (const complex&, double num);
const complex& operator - (const complex&, double num);
const complex& operator * (const complex&, double num);
const complex& operator / (const complex&, double num);

const complex& absol(cosnt complex&);

double re(const complex&);
double im(const complex&);