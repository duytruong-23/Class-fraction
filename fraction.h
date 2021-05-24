#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <math.h>

using namespace std;

class fraction
{
private:
	int numer;
	int denom;
public:
	fraction();
	fraction(int numer , int denom);
	fraction(int numer);
	~fraction();
	fraction simpli();
	bool isLegal();
	friend fraction operator +(fraction A, fraction B);
	friend fraction operator -(fraction A, fraction B);
	friend fraction operator *(fraction A, fraction B);
	friend fraction operator /(fraction A, fraction B);
	friend istream& operator>>(istream &in, fraction& A);
	friend ostream& operator<<(ostream& out, fraction& A);
	friend bool operator ==(fraction A, fraction B);
	friend bool operator !=(fraction A, fraction B);
	friend bool operator >(fraction A, fraction B);
	friend bool operator <(fraction A, fraction B);
	friend bool operator >=(fraction A, fraction B);
	friend bool operator <=(fraction A, fraction B);
};



#endif
