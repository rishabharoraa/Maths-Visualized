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

const complex& operator + (const complex& a, const complex& b) {
	complex res();
	res.r = a.r + b.r;
	res.i = a.i + b.i;
	return res;
}

const complex& operator - (const complex& a, const complex& b) {
	complex res();
	res.r = a.r - b.r;
	res.i = a.i - b.i;
	return res;
}

const complex& operator * (const complex& a, const complex& b) {
	complex res();
	res.r = (a.r*b.r) - (a.i*b.i);
	res.i = (a.i*b.r) + (a.r*b.i);
	return res;
}