#include<iostream>

#define cut 1

namespace my 
{
	//template <typename T>
	long gcd(long a, long b)
	{
		if(a < 0)
			a = a * (-1);
		if(b < 0)
			b = b * (-1);
	
		
		while (a != b)
		{
			if (a > b) 
				a -= b;
			else 
				b -= a;
		}
		return a;
	}
}

class Fraction
{
	long numerator;
	long denominator;
	
public:
///---------------------------------------------------------------------------------------------------------------------------------
///--constructors-------------------------------------------------------------------------------------------------------------------	
	Fraction()
	{
		numerator = 1;
		denominator = 1;
	}
	
	Fraction(long num, long den) : numerator(num), denominator(den)
	{
		if(den == 0)
		{
			std::cout << "denominator can`t be zero" << std::endl;
			this->~Fraction();
		}
		
		denominator = den;
		
		#if cut == 1
			long nod = my::gcd(num, den);
			//std::cout << nod << std::endl;
			numerator = num / nod;
			denominator = den / nod;
		#endif	
		
		if(den < 0)
		{
			numerator = -1 * numerator;
			denominator = -1 * denominator;
		}
	}
///---------------------------------------------------------------------------------------------------------------------------------
///--get----------------------------------------------------------------------------------------------------------------------------	
	long get_num() const
	{
		return numerator;
	}
	
	long get_den() const
	{
		return denominator;
	}
///---------------------------------------------------------------------------------------------------------------------------------
///--negate-------------------------------------------------------------------------------------------------------------------------
	Fraction negate() const
	{
		if(numerator == 0)
		{
			std::cout << "denominator can`t be zero" << std::endl;
			return *this;
		}
		
		Fraction res{denominator, numerator};
		return res;
	}	
///---------------------------------------------------------------------------------------------------------------------------------
///--operators----------------------------------------------------------------------------------------------------------------------	
	Fraction operator+ (const Fraction& rhs) const
	{
		Fraction drob{rhs.get_den() * numerator + denominator * rhs.get_num(), rhs.get_den() * denominator};		
		return drob;
	}
	
	Fraction operator- (const Fraction& rhs) const
	{
		Fraction drob{rhs.get_den() * numerator - denominator * rhs.get_num(), rhs.get_den() * denominator};		
		return drob;
	}
	
	Fraction operator* (const Fraction& rhs) const
	{
		Fraction drob{ numerator * rhs.get_num(), rhs.get_den() * denominator};		
		return drob;
	}
	
	Fraction operator/ (const Fraction& rhs) const
	{
		Fraction drob{ numerator * rhs.get_den(), rhs.get_num() * denominator};		
		return drob;
	}
	
	bool operator> (const Fraction& rhs) const
	{
		if((numerator * rhs.get_den() - denominator * rhs.get_num()) > 0)			
			return true;
			
		return false;
	}
	
	bool operator>= (const Fraction& rhs) const
	{
		if((numerator * rhs.get_den() - denominator * rhs.get_num()) >= 0)			
			return true;
			
		return false;
	}
	
	bool operator< (const Fraction& rhs) const
	{
		if((numerator * rhs.get_den() - denominator * rhs.get_num()) < 0)			
			return true;
			
		return false;
	}
	
	bool operator<= (const Fraction& rhs) const
	{
		if((numerator * rhs.get_den() - denominator * rhs.get_num()) <= 0)			
			return true;
			
		return false;
	}
	
	bool operator== (const Fraction& rhs) const
	{
		if((numerator * rhs.get_den() - denominator * rhs.get_num()) == 0)			
			return true;
			
		return false;
	}
	
	bool operator!= (const Fraction& rhs) const
	{
		if((numerator * rhs.get_den() - denominator * rhs.get_num()) != 0)			
			return true;
			
		return false;
	}
///---------------------------------------------------------------------------------------------------------------------------------
///--print--------------------------------------------------------------------------------------------------------------------------	
	void print() const
	{
		std::cout << numerator <<'/';
		std::cout << denominator;
		std::cout << std::endl;
		
		return;
	}
///---------------------------------------------------------------------------------------------------------------------------------
///--put----------------------------------------------------------------------------------------------------------------------------	
	int put_fr(long a, long b)
	{
		if(b == 0)
		{
			std::cout << "denominator can`t be zero" << std::endl;			
			return 1;
		}
		
		if(b < 0)
		{
			a = -1 * a;
			b = -1 * b;
		}
		
		numerator = a;
		denominator = b;
		
		#if cut == 1
			long nod = my::gcd(a, b);
			//std::cout << nod << std::endl;
			numerator = a / nod;
			denominator = b / nod;
		#endif
		
		return 0;
	}
	

};

int main(void)
{
	Fraction a{12 ,4};
	a.print();
	
	int c = 50, d = 22;
	
	Fraction fr{22, 50};
	fr.print();
	
	Fraction res{};
	
	res = fr + a;
	res.print();
	
	res = fr - a;
	res.print();
	
	res = fr * a;
	res.print();
	
	res = fr / a;
	res.print();
	
	if(a > fr)
		std::cout << "a > fr" << std::endl;
	
	if(a < fr)
		std::cout << "a < fr" << std::endl;
		
	if(fr < a)
		std::cout << "a < fr" << std::endl;
		
	if(a == a)
		std::cout << "a == a" << std::endl;	
	
	if(fr != a)
		std::cout << "a != fr" << std::endl;
		
	a = a.negate();
	a.print();	
	
	return 0;
}
