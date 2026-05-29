#ifndef mystr_h_
#define mystr_h_
#include<iostream>
using namespace std;
class mystr {
public:
	char* str;
	int length;
	int lengthcheck(const char*& str1)
	{
		int count = 0;
		for (int i = 0; str1[i] != '\0'; i++)
		{
			count++;
		}
		return count;
	}
	int lengthcheck1(char* str1)
	{
		int count = 0;
		for (int i = 0; str1[i] != '\0'; i++)
		{
			count++;
		}
		return count;
	}

	mystr();

	mystr(const char*, int);
	mystr(const char* str1);
	mystr(char* str1);
	mystr(const mystr& other);

	~mystr();
	mystr& operator=(const mystr& other);

	mystr& assign(const mystr& other);
	char& at(int pos);
	char& operator[](int pos);
	char operator[](int pos)const;
	void replacefirst(char c);
	char& front();
	char& back();
	bool empty()const;
	int size()const;
	mystr trim();
	mystr& insert(int pos, const char other);
	mystr& insert(int pos, const char* other);
	mystr& operator+=(const mystr& other);
	int stoi(const mystr& s);
	mystr itos(int num);
	mystr& operator+=(char c);
	friend istream& operator>>(istream& in, mystr& other);
	friend ostream& operator<<(ostream& cout, const mystr& other);
	void regrow();
	void input(istream& in);
	void print();
	friend bool operator==(const mystr& lhs, const mystr& rhs);
	bool equalto(const mystr& rhs);
	friend bool operator!=(const mystr& lhs, const mystr& rhs);
	bool notequal(const mystr& rhs);
	mystr* split(char c, int& count);
	void remove_at(int pos);
	void insert_at(int pos, char& c);
	void insert_at(int pos, const mystr& other);
	int* find_all(char c, int& count);
	int* find_all(const char* c, int& count);
	int* sub_searching(const char* c, int& count);
	mystr* tokenize(const char* c, int& count);
	friend bool operator<(const mystr& lhs, const mystr& rhs);
	bool lessthan(const mystr& rhs);
	friend bool operator>(const mystr& lhs, const mystr& rhs);
	bool greaterthan(const mystr& rhs);
	friend bool operator>=(const mystr& lhs, const mystr& rhs);
	bool greaterthanequalto(const mystr& rhs);
	friend bool operator<=(const mystr& lhs, const mystr& rhs);

	bool lessthanequalto(const mystr& rhs);
	friend mystr operator+(const mystr& m1, const mystr& m2);
	mystr concat(const mystr& m2);
	int findfirst(char c);
	int findfirst(const mystr& other)const;
	int findlast(char c);
	int findlast(const mystr& other)const;
	void remove_first(char c);
	void remove_last(char c);
	void remove_all(char c);
	void upper();
	void lower();
	void clear();
};
#endif



