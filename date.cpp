#include "date.h"
#include <iostream>

date::date()
{
	day_ = 0;
	month_ = 0;
	year_ = 0;
}

date::date(const int& d, const int& m, const int& y) :day_(d), month_(m), year_(y)
{
}

int date::day() const
{
	return day_;
}
int date::month() const
{
	return month_;
}
int date::year() const
{
	return year_;
}

void date::set_day(const int& d)
{
	day_ = d;
}
void date::set_month(const int& m)
{
	month_ = m;
}
void date::set_year(const int& y)
{
	year_ = y;
}

bool date::valid() const
{
	if (year_ < 0) return false;
	if (month_ < 1 || month_>12) return false;
	if (day_ < 1 || day_>31) return false;
	if (day_ > 30 && ((month_ % 2 == 0 && month_<=7)||(month_%2==1 && month_>=8))) return false;
	if (day_ > 29 && month_ == 2) return false;
	return true;
}

bool operator==(const date& d1, const date& d2)
{
	return (d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year());
}
bool operator<(const date& d1, const date& d2)
{
	if (d1.year() == d2.year()) {
		if (d1.month() == d2.month())
			return (d1.day() < d2.day());
		else
			return (d1.month() < d2.month());
	}
	else
		return (d1.year() < d2.year());
}
bool operator<=(const date& d1, const date& d2)
{
	return (d1 < d2 || d1 == d2);
}
bool operator>(const date& d1, const date& d2)
{
	return (!(d1 <= d2));
}
bool operator>=(const date& d1, const date& d2)
{
	return (d1 > d2 || d1 == d2);
}


date date::operator++()
{
	/*
	Incrementation prefix : ++maDate.
	Il faut retourner maDate deja incrementé.
	*/
	if (!(this->valid())) return *this;
	else
	{
		day_++;
		if (this->valid()) return *this;
		else
		{
			day_ = 1;
			month_++;
			if (this->valid()) return *this;
			else
			{
				day_ = 1;
				month_ = 1;
				year_++;
				return *this;
			}
		}
	}
}
date date::operator++(int)
{
	/*
	Incrementation postfix : maDate++.
	Il faut retourner une date qui vaut maDate avant incrementation mais incrementer maDate quand meme.
	*/
	date dbis = *this;
	if (!(this->valid())) return *this;
	else
	{
		day_++;
		if (!this->valid())
		{
			day_ = 1;
			month_++;
			if (!this->valid())
			{
				day_ = 1;
				month_ = 1;
				year_++;
			}
		}
	}
	return dbis;
}


void date::print()
{
	std::cout << "(" << day_ << ", " << month_ << ", " << year_ << ")" << std::endl;
}