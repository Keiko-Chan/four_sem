#!/usr/bin/python3
	
def gcd(a, b):
	if a < 0 :
		a = a * (-1)
	
	while a != b :
		if a > b :
			a -= b
		else:
			b -= a
	return a;


class Fraction:

	def __init__(self, numerator, denominator):
		"""constructor"""
		if denominator == 0 :
        		print('denominator can`t be zero')
        		self.denominator = 1
        		denominator = 1
		if denominator < 0 :
        		numerator = numerator * (-1)
        		denominator = denominator * (-1)
        		
		nod = gcd(numerator, denominator)
		self.numerator = numerator / nod
		self.denominator = denominator / nod
        	
        	
	def __add__(self, other):
		"""operator+"""
		num = self.numerator * other.denominator + other.numerator * self.denominator
		den = other.denominator * self.denominator
		return Fraction(num, den)
	
	def __sub__(self, other):
		"""operator-"""
		num = self.numerator * other.denominator - other.numerator * self.denominator
		den = other.denominator * self.denominator
		return Fraction(num, den)
		
	def __mul__(self, other):
		"""operator*"""
		num = self.numerator * other.numerator
		den = other.denominator * self.denominator
		return Fraction(num, den)
			
	def __truediv__(self, other):
		"""operator/"""
		num = self.numerator * other.denominator
		den = other.numerator * self.denominator
		return Fraction(num, den)
	
	def __lt__(self, other):
		"""operator<"""
		if self.numerator * other.denominator < other.numerator * self.denominator :
			return true
		return false
		
	def __le__(self, other):
		"""operator<="""
		if self.numerator * other.denominator <= other.numerator * self.denominator :
			return true
		return false
		
	def __gt__(self, other):
		"""operator>"""
		if self.numerator * other.denominator > other.numerator * self.denominator :
			return true
		return false
        
	def __ge__(self, other):
		"""operator>="""
		if self.numerator * other.denominator >= other.numerator * self.denominator :
			return true
		return false
	
	def __eq__(self, other):
		"""operator=="""
		if self.numerator * other.denominator == other.numerator * self.denominator :
			return true
		return false
	
	def __ne__(self, other):
		"""operator!="""
		if self.numerator * other.denominator != other.numerator * self.denominator :
			return true
		return false
	
	def print(self):
		print('numerator: ', self.numerator)
		print('denominator: ', self.denominator)
