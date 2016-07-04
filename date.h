#pragma once

class date
{
protected:
	int year_;
	int month_;
	int day_;
public:
	date();
	date(const int& d, const int& m, const int& y);

	bool valid() const;

	int day() const;
	int month() const;
	int year() const;

	void set_day(const int& d);
	void set_month(const int& m);
	void set_year(const int& y);

	date operator++(); // prefix. Pour faire ++maDate
	date operator++(int); // postfix. Pour faire maDate++

	void print();
};
bool operator==(const date&, const date&);
bool operator<(const date&, const date&);
bool operator<=(const date&, const date&);
bool operator>(const date&, const date&);
bool operator>=(const date&, const date&);
