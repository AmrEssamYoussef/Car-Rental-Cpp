#include "renter.h"

renter::renter() :id(""), name(""), age(""), gender(""), license_numper("")
{
}

renter::renter(string i, string n, string a, string g, string l) : id(i), name(n), age(a), gender(g), license_numper(l)
{
}

void renter::set_id(string u)
{
	id = u;
}

void renter::set_name(string t)
{
	name = t;
}

void renter::set_age(string j)
{
	age = j;
}

void renter::set_gender(string i)
{
	gender = i;
}

void renter::set_license_numper(string p)
{
	license_numper = p;
}

string renter::get_id()
{
	return id;
}

string renter::get_name()
{
	return name;
}

string renter::get_age()
{
	return age;
}

string renter::get_gender()
{
	return gender;
}

string renter::get_license_numper()
{
	return license_numper;
}
