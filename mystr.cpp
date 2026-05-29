#include<iostream>
#include "mystr.h"
using namespace std;
mystr::mystr()
{
	str = nullptr;
	length = 0;
}
mystr::mystr(const char* str1, int len)
{
	length = len;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = str1[i];
	}
	str[length] = '\0';
}
mystr::mystr(const char* str1)
{
	length = lengthcheck(str1);
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = str1[i];
	}
	str[length] = '\0';
}
mystr::mystr(char* str1)
{
	length = lengthcheck1(str1);
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = str1[i];
	}
	str[length] = '\0';
}
mystr::mystr(const mystr& other)
{
	length = other.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = other.str[i];
	}
	str[length] = '\0';
}
mystr::~mystr()
{
	delete[] this->str;
}
mystr& mystr::operator=(const mystr& other)
{
	if (this != &other)
	{
		delete[] this->str;
		this->length = other.length;
		this->str = new char[other.length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		str[other.length] = '\0';
	}
	return *this;
}
mystr& mystr::assign(const mystr& other)
{
	if (this != &other)
	{
		delete[] this->str;
		this->length = other.length;
		this->str = new char[other.length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		str[other.length] = '\0';
	}
	return *this;
}
char& mystr::at(int pos)
{
	if (pos >= 0 && pos < this->length)
	{
		for (int i = 0; i < this->length; i++)
		{
			if (pos == i)
			{
				return str[i];
			}
		}
	}
	else
	{
		char c = '^';
		return c;
	}
}
char& mystr::operator[](int pos)
{
	for (int i = 0; i < this->length; i++)
	{
		if (pos == i)
		{
			return str[i];
		}
	}
	char c = '^';

	return c;
}
char mystr::operator[](int pos)const
{

	for (int i = 0; i < this->length; i++)
	{
		if (pos == i)
		{
			return str[i];
		}
	}
	char c = '^';
	return c;
}
void mystr::replacefirst(char c)
{
	this->str[0] = c;

}
char& mystr::front()
{
	return str[0];
}
char& mystr::back()
{
	return str[length - 1];
}
bool mystr::empty()const {
	for (int i = 0; i < length; i++)
	{
		if (str[i] != ' ')
		{
			return false;
		}
	}
	return true;
}
int mystr::size()const {
	int size = 0;
	size = this->length;
	return size;
}
mystr mystr::trim()
{
	mystr res;
	int a = 0;
	char ch[100];
	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] == ' ' || this->str[i] == '\n')
		{
			continue;
		}
		ch[a] = str[i];
		a++;
	}
	res.length = a;
	res.str = new char[res.length + 1];
	for (int i = 0; i < res.length; i++)
	{
		res.str[i] = ch[i];
	}
	return res;
}
mystr& mystr::insert(int pos, const char other)
{
	mystr res;
	int a = 0;
	char temp = '0', temp1 = '0';
	res.length = length + 1;
	res.str = new char[res.length + 1];
	for (int i = 0; i < res.length; i++)
	{
		if (i < pos)
		{
			res.str[a] = str[i];
			a++;
		}
		if (pos == i)
		{
			res.str[a] = other;
			a++;
		}
		else if (i > pos)
		{
			res.str[a] = str[i - 1];
			a++;
		}

	}
	res.str[res.length] = '\0';
	*this = res;
	return *this;
}
mystr& mystr::insert(int pos, const char* other)
{
	mystr res;
	int a = 0;
	int charlength = lengthcheck(other);
	res.length = charlength + this->length;
	res.str = new char[res.length + 1];
	for (int i = 0; i < length; i++)
	{

		if (i = pos)
		{
			for (int j = 0; j < charlength; j++)
			{
				res.str[a] = other[j];
				a++;
			}
		}
		else
		{
			res.str[a] = this->str[i];
			a++;
		}
	}
	res.str[a] = '\0';
	*this = res;
	return *this;
}
mystr& mystr::operator+=(const mystr& other)
{
	mystr res;
	int a = 0;
	res.length = this->length + other.length;
	res.str = new char[res.length + 1];
	for (int i = 0; i < this->length; i++)
	{
		if (i <= this->length)
		{
			res.str[i] = this->str[i];
			a = i;
		}
	}
	a++;
	for (int i = 0; i < other.length; i++)
	{
		res.str[a] = other.str[i];
		a++;
	}
	res.str[a] = '\0';
	*this = res;
	return *this;
}
int mystr::stoi(const mystr& s)
{
	mystr res;
	int ans = 0;
	int num = 0;
	char* ptr = s.str;
	res.length = res.lengthcheck1(ptr);
	for (int i = 0; i < res.length; i++)
	{
		if (s.str[i] > 47 && s.str[i] <= 57)
		{
			num = s.str[i] - 48;
			ans = ans * 10 + num;
		}
		else
		{
			cout << "INVALID INPUT: THIS IS NOT AN INTEGER";
			return -1;
		}
	}
	return ans;
}
mystr mystr::itos(int num)
{
	mystr res;
	int pos = num;
	int count = 0;
	int div = 1;
	while (pos != 0)
	{
		pos = pos / 10;
		count++;
	}
	res.length = count;
	res.str = new char[res.length + 1];
	for (int i = 0; i < count - 1; i++)
	{
		div = div * 10;
	}
	for (int i = 0; i < count; i++)
	{
		pos = num / div;
		num = num % div;
		div = div / 10;
		res.str[i] = pos + '0';
	}
	return res;
}
mystr& mystr::operator+=(char c)
{
	mystr res;
	res.length = this->length + 1;
	res.str = new char[res.length + 1];
	for (int i = 0; i < length; i++)
	{
		res.str[i] = str[i];
	}
	res.str[res.length - 1] = c;
	res.str[res.length] = '\0';
	*this = res;
	return *this;
}
istream& operator>>(istream& in, mystr& other)
{
	char c;
	other.length = 1;
	other.str = new char[other.length];
	for (int i = 0; ; i++)
	{
		in.get(c);
		if (c == '\n' || in.eof() || c == 32)
		{
			break;
		}
		if (i == other.length)
		{
			other.regrow();
		}
		other.str[i] = c;
	}
	other.regrow();
	other.str[other.length - 1] = '\0';
	return in;
}
ostream& operator<<(ostream& cout, const mystr& other)
{
	for (int i = 0; i < other.length - 1; i++)
	{
		cout << other.str[i];
	}
	return cout;
}
void mystr::regrow()
{
	char* ptr = new char[this->length + 1];
	for (int i = 0; i < length; i++)
	{
		ptr[i] = this->str[i];
	}
	delete[] this->str;
	this->str = ptr;
	ptr = nullptr;
	this->length = this->length + 1;
}
void mystr::input(istream& in)
{
	char c;
	this->length = 1;
	this->str = new char[this->length];
	for (int i = 0; ; i++)
	{
		in.get(c);
		if (c == '\n' || in.eof() || c == ',')
		{
			break;
		}
		if (i == this->length)
		{
			this->regrow();
		}
		str[i] = c;
	}
	this->regrow();
	this->str[this->length - 1] = '\0';
}
void mystr::print()
{
	for (int i = 0; i < this->length; i++)
	{
		cout << this->str[i];
	}
}
bool operator==(const mystr& lhs, const mystr& rhs)
{
	if (rhs.length == lhs.length)
	{
		for (int i = 0; i < lhs.length; i++)
		{
			if (rhs.str[i] != lhs.str[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
bool mystr::equalto(const mystr& rhs)
{
	if (rhs.length == length)
	{
		for (int i = 0; i < length; i++)
		{
			if (rhs.str[i] != str[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!=(const mystr& lhs, const mystr& rhs)
{
	if (rhs.length == lhs.length)
	{
		for (int i = 0; i < lhs.length; i++)
		{
			if (rhs.str[i] == lhs.str[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return true;
	}
}
bool mystr::notequal(const mystr& rhs)
{
	if (rhs.length == length)
	{
		for (int i = 0; i < length; i++)
		{
			if (rhs.str[i] == str[i])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return true;
	}
}
mystr* mystr::split(char c, int& count)
{
	count = 1;
	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] == c)
		{
			count++;
		}
	}
	mystr* res = new mystr[count];
	int a = 0;
	int b = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	for (int i = 0; i < this->length; i++)
	{
		if (str[i] == c || i == this->length - 1)
		{
			d = i - f;
			res[b].str = new char[d + 1];
			res[b].length = d;
			e = 0;
			for (int j = a; j < i; j++)
			{
				res[b].str[e] = str[j];
				e++;
			}
			a = i + 1;
			res[b].str[d] = '\0';
			b++;
			f = i + 1;
		}
	}
	return res;
}
void mystr::remove_at(int pos)
{
	for (int i = 0; i < length; i++)
	{
		if (i == pos)
		{
			for (int j = i; j < length - 1; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
	length = length - 1;
}
void mystr::insert_at(int pos, char& c)
{
	for (int i = 0; i < length; i++)
	{
		if (i == pos)
		{
			str[i] = c;
		}
	}
}
void mystr::insert_at(int pos, const mystr& other)
{
	mystr res;
	int a = 0;
	res.length = other.length + this->length;
	res.str = new char[res.length + 1];
	for (int i = 0; i < length; i++)
	{

		if (i == pos)
		{
			for (int j = 0; j < other.length; j++)
			{
				res.str[a] = other.str[j];
				a++;
			}
		}
		else
		{
			res.str[a] = this->str[i];
			a++;
		}
	}
	res.str[a] = '\0';

	*this = res;
}
int* mystr::find_all(char c, int& count)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			count++;
		}
	}
	int a = 0;
	int* ptr = new int[count];
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			ptr[a] = i;
			a++;
		}
	}
	return ptr;
}
int* mystr::find_all(const char* c, int& count)
{
	int clength = lengthcheck(c);
	int b = 0;
	int a = 0;
	int d = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c[a])
		{
			a++;
			if (c[a] == str[i + 1])
			{
				if (a == clength - 1)
				{
					count++;
					a = 0;
				}
				else
				{
					continue;
				}
			}
			else
			{
				a = 0;
			}

		}
	}
	int* res = new int[count];
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c[a])
		{
			a++;
			if (c[a] == str[i + 1])
			{
				if (a == clength - 1)
				{
					b = i - a;
					res[d] = b;
					d++;
					a = 0;
				}
				else
				{
					continue;
				}
			}
			else
			{
				a = 0;
			}

		}
	}
	return res;
}
int* mystr::sub_searching(const char* c, int& count)
{
	int clength = lengthcheck(c);
	int b = 0;
	int a = 0;
	int d = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c[a])
		{
			a++;
			if (c[a] == str[i + 1])
			{
				if (a == clength - 1)
				{
					count++;
					a = 0;
				}
				else
				{
					continue;
				}
			}
			else
			{
				a = 0;
			}

		}
	}
	int* res = new int[count];
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c[a])
		{
			a++;
			if (c[a] == str[i + 1])
			{
				if (a == clength - 1)
				{
					b = i - a;
					res[d] = b;
					d++;
					a = 0;
				}
				else
				{
					continue;
				}
			}
			else
			{
				a = 0;
			}

		}
	}
	return res;
}
mystr* mystr::tokenize(const char* c, int& count)
{
	int clength = lengthcheck(c);
	count = 1;
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < clength; j++)
		{
			if (str[i] == c[j])
			{
				count++;
			}
		}
	}
	mystr* res = new mystr[count];
	int a = 0;
	int b = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int z = 0;
	for (int i = 0; i < this->length; i++)
	{
		z = 0;
		for (int j = 0; j < clength; j++)
		{
			if (str[i] == c[j])
			{
				z = 1;
			}
		}
		if (z == 1 || i == this->length - 1)
		{
			d = i - f;
			res[b].str = new char[d + 1];
			res[b].length = d;
			e = 0;
			for (int j = a; j < i; j++)
			{
				res[b].str[e] = str[j];
				e++;
			}
			a = i + 1;
			res[b].str[d] = '\0';
			b++;
			f = i + 1;
		}
	}
	return res;
}
bool operator<(const mystr& lhs, const mystr& rhs)
{
	int a = 0;
	for (int i = 0; i < lhs.length; i++)
	{
		if (lhs.str[i] < rhs.str[i])
		{
			a = 1;
			break;
		}
		else if (lhs.str[i] == rhs.str[i])
		{
			continue;
		}
		else if (lhs.str[i] > rhs.str[i])
		{
			return false;
		}
	}
	if (a == 1)
	{
		return true;
	}
}
bool mystr::lessthan(const mystr& rhs)
{
	int a = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] < rhs.str[i])
		{
			a = 1;
			break;
		}
		else if (str[i] == rhs.str[i])
		{
			continue;
		}
		else if (str[i] > rhs.str[i])
		{
			return false;
		}
	}
	if (a == 1)
	{
		return true;
	}
}
bool operator>(const mystr& lhs, const mystr& rhs)
{
	int a = 0;
	for (int i = 0; i < rhs.length; i++)
	{
		if (rhs.str[i] < lhs.str[i])
		{
			a = 1;
			break;
		}
		else if (lhs.str[i] == rhs.str[i])
		{
			continue;
		}
		else if (rhs.str[i] > lhs.str[i])
		{
			return false;
		}
	}
	if (a == 1)
	{
		return true;
	}
}
bool mystr::greaterthan(const mystr& rhs)
{
	int a = 0;
	for (int i = 0; i < rhs.length; i++)
	{
		if (rhs.str[i] < str[i])
		{
			a = 1;
			break;
		}
		else if (str[i] == rhs.str[i])
		{
			continue;
		}
		else if (rhs.str[i] > str[i])
		{
			return false;
		}
	}
	if (a == 1)
	{
		return true;
	}
}
bool operator>=(const mystr& lhs, const mystr& rhs)
{
	int a = 0;

	for (int i = 0; i < rhs.length; i++)
	{
		if (rhs.str[i] <= lhs.str[i])
		{
			a = 1;
			break;
		}
		else if (rhs.str[i] > lhs.str[i])
		{
			return false;
		}
	}
	if (a == 1)
	{
		return true;
	}
}
bool mystr::greaterthanequalto(const mystr& rhs)
{
	int a = 0;
	for (int i = 0; i < rhs.length; i++)
	{
		if (rhs.str[i] <= str[i])
		{
			a = 1;
			break;
		}
		else if (rhs.str[i] > str[i])
		{
			return false;
		}
	}
	if (a == 1)
	{
		return true;
	}
}
bool operator<=(const mystr& lhs, const mystr& rhs)
{
	int a = 0;
	for (int i = 0; i < lhs.length; i++)
	{
		if (lhs.str[i] <= rhs.str[i])
		{
			a = 1;
			break;
		}
		else if (lhs.str[i] > rhs.str[i])
		{
			return false;
		}
	}
	if (a == 1)
	{
		return true;
	}
}
bool mystr::lessthanequalto(const mystr& rhs)
{
	int a = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] <= rhs.str[i])
		{
			a = 1;
			break;
		}
		else if (str[i] > rhs.str[i])
		{
			return false;
		}
	}
	if (a == 1)
	{
		return true;
	}
}
mystr operator+(const mystr& m1, const mystr& m2)
{
	mystr res;
	int a = 0;
	res.length = m1.length + m2.length;
	res.str = new char[res.length + 1];
	for (int i = 0; i < m1.length; i++)
	{
		res.str[i] = m1.str[i];
		a = i;
	}
	a++;
	for (int i = 0; i < m2.length; i++)
	{
		res.str[a] = m2.str[i];
		a++;
	}
	res.str[res.length] = '\0';
	return res;
}
mystr mystr::concat(const mystr& m2)
{
	mystr res;
	int a = 0;
	res.length = length + m2.length;
	res.str = new char[res.length + 1];
	for (int i = 0; i < length; i++)
	{
		res.str[i] = str[i];
		a = i;
	}
	a++;
	for (int i = 0; i < m2.length; i++)
	{
		res.str[a] = m2.str[i];
		a++;
	}
	res.str[res.length] = '\0';
	return res;
}
int mystr::findfirst(char c)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			return str[i];
		}
	}
}
int mystr::findfirst(const mystr& other)const
{
	int a = 0;
	int b = 0;
	int d = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == other.str[a])
		{
			a++;
			if (other.str[a] == str[i + 1])
			{
				if (a == other.length - 1)
				{
					b = i - a;
					return b;
					d++;
					a = 0;
				}
				else
				{
					continue;
				}
			}
			else
			{
				a = 0;
			}

		}
	}
}
int mystr::findlast(char c)
{
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] == c)
		{
			return str[i];
		}
	}
}
int mystr::findlast(const mystr& other)const {
	int a = other.length - 1;
	int b = 0;
	int d = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] == other.str[a])
		{
			a--;
			if (other.str[a] == str[i - 1])
			{
				if (a == 0)
				{
					b = i + a;
					return b;
					d++;
					a = other.length - 1;
				}
				else
				{
					continue;
				}
			}
			else
			{
				a = 0;
			}

		}
	}
}
void mystr::remove_first(char c)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			for (int j = i; j < length - 1; j++)
			{
				str[j] = str[j + 1];
			}
			length--;
			break;
		}
	}
}
void mystr::remove_last(char c)
{
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] == c)
		{
			for (int j = i; j < length - 1; j++)
			{
				str[j] = str[j + 1];
			}
			length--;
			break;
		}
	}

}
void mystr::remove_all(char c)
{
	int a = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			for (int j = i; j < length - 1; j++)
			{
				str[j] = str[j + 1];
			}
			a++;
		}
	}
	length = length - a;
}
void mystr::upper()
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] = str[i] - 32;
		}
	}
}
void mystr::lower()
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
	}
}
void mystr::clear()
{
	delete[]  this;
	this->length = 0;
	this->str = nullptr;
}