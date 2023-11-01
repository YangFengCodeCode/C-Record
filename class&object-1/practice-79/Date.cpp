#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"


int Date::GetMonthDay(int year, int month)
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = days[month];
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) && (year % 100 == 0))
	{
		day += 1;
	}

	return day;
}

//构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print() const  //后面加个const
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

//赋值运算符
Date& Date::operator=(const Date& d) 
{
	if (*this != d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;
}
//赋值运算符如果不显式实现，编译器会生成一个默认的。此时用户再在类外自己实现一个全局的赋值运算符重载，
//就和编译器在类中生成的默认赋值运算符重载冲突了，故赋值运算符重载只能是类的成员函数

bool Date::operator==(const Date& d) const
{
	return (_day == d._day && _month == d._month && _year == d._year);
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

bool Date::operator>(const Date& d) const
{
	if (_year > d._year)
	{
		return true;
	}

	else if (_year == d._year && _month > d._month)
	{
		return true;
	}

	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}

	else
	{
		return false;
	}

}

bool Date:: operator>=(const Date& d) const
{
	return (*this == d) || (*this > d);
}


bool Date::operator<(const Date& d) const
{
	return !(*this >= d);
}

bool Date:: operator<=(const Date& d) const
{
	return !(*this > d);
}


//在类里面是不用区分函数顺序的
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day = _day + day;

	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Date Date:: operator+(int day) const
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}


Date& Date:: operator-=(int day)
{
	if (day < 0)
	{
		*this += (-day);
	}

	_day -= day;
	while (_day < 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}


Date Date:: operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

//++d1
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//d1++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

//--d1
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

//d1--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

//d1 -100
int Date::operator-(const Date& d) const
{
	//假设左大右小
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		flag = -1;
		min = *this;
		max = d;
	}
	int n = 0;
	while (min != max)
	{
		min++;
		n++;
	}
	return n * flag;
}


ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
