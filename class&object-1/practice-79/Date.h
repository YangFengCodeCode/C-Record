#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1);

	void Print() const;
	int GetMonthDay(int year, int month);
	Date& operator=(const Date& y);
	bool operator==(const Date& y) const;
	bool operator!=(const Date& y) const;
	bool operator>(const Date& y) const;
	bool operator<(const Date& y) const;
	bool operator>=(const Date& y) const;
	bool operator<=(const Date& y) const;

	int operator-(const Date& d) const;
	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);
	Date operator-(int day) const;

	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);


	Date* operator&() //��������Ϊ Date*
	{
		cout << "Date* operator&()" << endl;
		return this;
	}

	const Date* operator&()const//��������Ϊ const Date*
	{
		cout << "const Date* operator&()const" << endl;
		return this;
	}

	// ��Ԫ����
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);

// ���ز�����������һ�������Ͳ���->����ͨ���������㣬�ı��������͵��������
// int operator+(int i, int j)


