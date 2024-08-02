
#include<string>
#include <iostream>
using namespace std;
class car
{
private:
	string model, license_numper, owner, renter;

public:
	car();
	car(string m, string l, string o);
	void set_model(string u);
	void set_license_numper(string t);
	void set_owner(string j);
	void set_renter(string i);
	string get_model();
	string get_license_numper();
	string get_owner();
	string get_renter();
	bool is_avaliable();
	
};

