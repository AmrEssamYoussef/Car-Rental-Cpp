#include "car.h"

car::car():model(""), license_numper(""), owner(""), renter("")
{
}
car::car(string m, string l, string o): model(m), license_numper(l), owner(o)
{
}

void car::set_model(string u)
{
	model = u;
}

void car::set_license_numper(string t)
{
	license_numper = t;
}

void car::set_owner(string j)
{
	owner = j;
}

void car::set_renter(string i)
{
	renter = i;
}

string car::get_model()
{
	return model;
}

string car::get_license_numper()
{
	return license_numper;
}

string car::get_owner()
{
	return owner;
}

string car::get_renter()
{
	return renter;
}

bool car::is_avaliable()
{
	bool x=false;
	if (renter == "")x = true;
	return x;
}

