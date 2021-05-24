#include "fraction.h"

fraction::fraction(int numer, int denom)
{
	this->numer = numer;
	this->denom = denom;
}

fraction::fraction()
{
	numer = 0;
	denom = 1;
}

fraction::fraction(int numer)
{
	this->numer = numer;
	this->denom = 1;
}

fraction::~fraction()
{

}

fraction fraction::simpli()
{
	int a = abs(numer);
	int b = abs(denom);
	int r = 0;
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	numer /= a;
	denom /= a;
	return *this;
}

bool fraction::isLegal()
{
	if (denom != 0) { return true; }
	return false;
}

fraction operator +(fraction A, fraction B)
{
	fraction C;
	if (A.denom == B.denom)
	{
		C.denom = A.denom;
		C.numer = A.numer + B.numer;
		return C;
	}
	C.denom = A.denom * B.denom;
	C.numer = A.numer * B.denom + B.numer * A.denom;
	return C;
}

fraction operator -(fraction A, fraction B)
{
	fraction C;
	if (A.denom == B.denom)
	{
		C.denom = A.denom;
		C.numer = A.numer - B.numer;
		return C;
	}
	C.denom = A.denom * B.denom;
	C.numer = A.numer * B.denom - B.numer * A.denom;
	return C;
}

fraction operator *(fraction A, fraction B)
{
	fraction C;
	C.numer = A.numer * B.numer;
	C.denom = A.denom * B.denom;
	return C;
}

fraction operator /(fraction A, fraction B)
{
	fraction C;
	C.numer = A.numer * B.denom;
	C.denom = A.denom * B.numer;
	return C;
}

istream& operator >>(istream& in, fraction& A)
{
	cout << "Numer: ";
	in >> A.numer;
	cout << "Denom: ";
	in >> A.denom;
	return in;
}

ostream& operator<<(ostream& out, fraction& A)
{
	out << A.numer << "/" << A.denom << endl;
	return out;
}

bool operator==(fraction A, fraction B)
{
	fraction C = A.simpli();
	fraction D = B.simpli();
	if (C.denom == D.denom && C.numer == D.numer)
	{
		return true;
	}
	return false;
}

bool operator!=(fraction A, fraction B)
{
	if (!(A == B)) { return true; }
	return false;
}

bool operator >(fraction A, fraction B)
{
	fraction C = A - B;
	if (C.numer * C.denom > 0)
	{
		return true;
	}
	return false;
}

bool operator <(fraction A, fraction B)
{
	fraction C = A - B;
	if (C.numer * C.denom < 0) { return true; }
	return false;
}

bool operator >= (fraction A, fraction B)
{
	if (A == B || A > B) { return true; }
	return false;
}

bool operator <=(fraction A, fraction B)
{
	if (A == B || A < B) { return true; }
	return false;
}