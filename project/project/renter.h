
#include<string>
#include <iostream>
using namespace std;
class renter
{
private:
	string id, name, age, gender, license_numper;
public:
	renter();
	renter(string i, string n, string a, string g, string l);
	void set_id(string u);
	void set_name(string t);
	void set_age(string j);
	void set_gender(string i);
	void set_license_numper(string p);
	string get_id();
	string get_name();
	string get_age();
	string get_gender();
	string get_license_numper();

};

