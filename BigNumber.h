#pragma once
#include<iostream>
#include <string>
using namespace std;
class Node
{
public:
	short int digit;
	Node* next;
	Node* prev;

	Node()
	{
		next=prev=this;
	}
	Node(int a,Node* pr)
	{
		digit=a;
		prev=pr;
		next=pr->next;
		pr->next->prev=this;
		pr->next=this;
	}

	~Node()
	{
		this->prev->next=this->next;
		this->next->prev=this->prev;
	}
};
class BigNumber
{
private:
	Node head;
	bool negative;
	__int64 lengthnum()const;
	BigNumber fun(int size);
	BigNumber operator*(int i)const;
	BigNumber del(int i);
	BigNumber append(BigNumber &other,int i);
public:
	BigNumber(const string&);
	BigNumber(void);
	BigNumber(const int num);
	~BigNumber(void);
	friend istream& operator>>(istream &c,BigNumber& B);
	friend ostream& operator<<(ostream & c,const BigNumber& B);
	BigNumber& operator=(const BigNumber&  other);
	BigNumber(const BigNumber& other);
	bool operator >(const BigNumber& other)const;
	bool operator <(const BigNumber& other)const;
	bool operator ==(const BigNumber& other)const;
	bool operator >=(const BigNumber& other)const;
	bool operator <=(const BigNumber& other)const;
	bool operator !=(const BigNumber& other)const;
	int  operator []( int i)const;
	BigNumber operator()(int i,int j)const;
	BigNumber operator+(const BigNumber& other)const;
	BigNumber operator-(const BigNumber& other)const;
	BigNumber operator/(const BigNumber& other)const;
	BigNumber operator%(const BigNumber& other)const;
	BigNumber operator*(const BigNumber& other)const;
	BigNumber operator+=(const BigNumber& other);
	BigNumber operator-=(const BigNumber& other);
	BigNumber operator/=(const BigNumber& other);
	BigNumber operator%=(const BigNumber& other);
	BigNumber operator*=(const BigNumber& other);
	BigNumber operator++();
	BigNumber operator++( int);
	BigNumber operator--();
	BigNumber operator--(int);

};

