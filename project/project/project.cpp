#include<string>
#include <iostream>
#include <fstream>
#include<sstream>
#include "car.h"
#include "renter.h"
using namespace std;
int main_menu();
void import_renters();
void export_renters();
void import_cars();
void export_cars();
void add_renter();
void remove_renter();
void add_car();
void remove_car();
void display_available_cars();
void rent_car();
const int max_num_of_cars = 15;
const int max_num_of_renters = 10;
car cars[max_num_of_cars];
renter renters[max_num_of_renters];
int main()
{
 main_menu();
}
int main_menu()
{
	cout << '\n';
	cout << "Hello, please enter \n "
		<< "\"1\" to import renters data \n"
		<< " \"2\" to export renters data \n"
		<< " \"3\" to import cars data \n"
		<< " \"4\" to export cars data \n"
		<< " \"5\" to add a renter data \n"
		<< " \"6\" to remove a renter data \n"
		<< " \"7\" to add a car data \n"
		<< " \"8\" to remove a car data \n"
		<< " \"9\" to display available cars \n"
		<< " \"10\" to rent a car  \n"
		<< " \"0\" to quit \n";
	int n; cin >> n;
	switch (n)
	{
	case 0:
		return 0;
		break;
	case 1:
		import_renters();
		break;
	case 2:
		export_renters();
		break;
	case 3:
		import_cars();
		break;
	case 4:
		export_cars();
		break;
	case 5:
		add_renter();
		break;
	case 6:
		remove_renter();
		break;
	case 7:
		add_car();
		break;
	case 8:
		remove_car();
		break;
	case 9:
		display_available_cars();
		break;
	case 10:
		rent_car();
		break;
	default:
		cout << "please enter valid nomper \n";
	}
	main_menu();
	return 0;
}
void import_renters()
{
	cout << "\n";
	cout << "please enter file name as \"filename.csv\" \n";
	string file_name;
	cin>>file_name;
	ifstream data;
	data.open(file_name);
	if (data.fail()) {
		cout << "import faild \n"; import_renters();
	}
	string id, name, age, gender, licensenum,labels;
	getline(data, labels, '\n');
	int n = 0;
	while (data.good())
	{
		getline(data, id, ';');
		getline(data, name, ';');
		getline(data, age, ';');
		getline(data, gender, ';');
		getline(data, licensenum, '\n');
		renters[n].set_id(id);
		renters[n].set_name(name);
		renters[n].set_age(age);
		renters[n].set_gender(gender);
		renters[n].set_license_numper(licensenum);
		n++;
	}
	cout << "renters data is imported successfully \n";
	data.close();
}
void export_renters()
{
	cout << "\n";
cout << "please enter the file name u want to export to as \"filename.csv\" \n";
	string file_name;
	cin >> file_name;
	ofstream data;
	data.open(file_name);
	if (data.fail()) { cout << "export faild "; export_renters; }
	data << "id" << ';' << "name" << ';' << "age" << ';' << "gender" << ';' << "license numper" << '\n';
	for (int i = 0; i < max_num_of_renters; i++)
	{
		data << renters[i].get_id() << ';' << renters[i].get_name() << ';' << renters[i].get_age() << ';' << renters[i].get_gender() << ';' << renters[i].get_license_numper() << '\n';
	}
	data.close();
}
void import_cars()
{

	cout << "\n";
	cout << "please enter the file name as \"filename.csv\" \n";
	string file_name;
	cin >> file_name;
	ifstream data;
	data.open(file_name);
	if (data.fail()) {
		cout << "import faild \n"; import_cars();
	}
	string model, owner, renter,  licensenum, labels;
	getline(data, labels, '\n');
	int n = 0;
	while (data.good())
	{
		getline(data, model, ';');
		getline(data, licensenum, ';');
		getline(data, owner, ';');
		getline(data, renter, '\n');
		cars[n].set_model(model);
		cars[n].set_license_numper(licensenum);
		cars[n].set_owner(owner);
		cars[n].set_renter(renter);
		n++;
	}
	cout << "cars data is imported successfully \n";
	data.close();
}
void export_cars()
{
	cout << "\n";
	cout << "please enter the file name u want to export to as \"filename.csv\" \n";
	string file_name;
	cin >> file_name;
	ofstream data;
	data.open(file_name);
	if (data.fail()) { cout << "export faild "; export_cars; }
	data << "model" << ';' << "license numper" << ';' << "owner" << ';' << "renter" << '\n';
	for (int i = 0; i < max_num_of_cars; i++)
	{
		data << cars[i].get_model() << ';' << cars[i].get_license_numper() 
			 << ';' << cars[i].get_owner() << ';' << cars[i].get_renter() << '\n';
	}
	data.close();
}
void add_renter()
{
	cout << "\n";
	cout << "please enter the file name u want to add to as \"filename.csv\" \n";
	string file_name;
	cin >> file_name;
	cout << "please enter the renter data with the sequence (national id,name,age,gender,license numper\n)";
	string a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	fstream data;
	data.open(file_name);
	if (data.fail()) { cout << "add faild "; add_renter; }
	data.seekg(0, ios::end);
	data.seekp(0, ios::end);
	data << a << ';' << b << ';' << c << ';' << d << ';' << e << '\n';
	data.close();
}
void remove_renter()
{
	import_renters();
	cout << "please enter the national id of the renter u want to remove \n";
	string s;
	bool x = false;
	cin >> s;
	for (int i = 0; i < max_num_of_renters; i++)
	{
		if (renters[i].get_id() == s)
		{
			for (int j = i; j < (max_num_of_renters-1); j++)
			{
				renters[j].set_id(renters[j + 1].get_id());
				renters[j].set_name(renters[j + 1].get_name());
				renters[j].set_age(renters[j + 1].get_age());
				renters[j].set_gender(renters[j + 1].get_gender());
				renters[j].set_license_numper(renters[j + 1].get_license_numper());
			}
			x = true;
		}

	}
	if (!x) { cout << "this id is not exist\n"; }
	export_renters();
}
void add_car()
{
	cout << "\n";
	cout << "please enter the file name u want to add to as \"filename.csv\" \n";
	string file_name;
	cin >> file_name;
	cout << "please enter the car data with the sequence (model,license numper,owner)\n";
	string a, b, c;
	fstream data;
	data.open(file_name);
	if (data.fail()) { cout << "add faild "; add_car; }
	cin >> a >> b >> c;
	int p=0;
	for (int i = 0; i < max_num_of_cars; i++)
	{
		if (cars[i].get_model() != "")p++;
		else
		{
			cars[p].set_model(a);
			cars[p].set_license_numper(b);
		    cars[p].set_owner(c);
			break;
		}
	}
	data.seekg(0, ios::end);
	data.seekp(0, ios::end);
	data << cars[p].get_model() << ';' << cars[p].get_license_numper()
		<< ';' << cars[p].get_owner() << '\n';
	data.close();
}
void remove_car()
{
	import_cars();
	cout << "please enter the license numper of the car u want to remove \n";
	string s;
	bool x = false;
	cin >> s;
	for (int i = 0; i < max_num_of_cars-1; i++)
	{
		if (cars[i].get_license_numper() == s)
		{
			for (int j = i; j < (max_num_of_cars - 1); j++)
			{
				cars[j].set_license_numper(cars[j + 1].get_license_numper());
				cars[j].set_model(cars[j + 1].get_model());
				cars[j].set_owner(cars[j + 1].get_owner());
				cars[j].set_renter(cars[j + 1].get_renter());
			}
			x = true;
		}

	}
	if (!x) { cout << "this license numper is not exist\n"; }
	export_cars();
}
void display_available_cars()
{
	import_cars();
	cout << '\n';
	cout << "the available cars are\n";
	for (int i = 0; i < max_num_of_cars; i++)
	{
		if (cars[i].get_renter() == "" && cars[i].get_model() != "")
		{
			cout <<"the car model is " << cars[i].get_model() <<" and the license numper is "
				 <<cars[i].get_license_numper()<<" and the owner is "<<cars[i].get_owner()<<'\n';
		}
	}
}
void rent_car()
{
	cout << "please enter the index of the renter at the table \n";
	int u;
	cin >> u;
	cout << "please enter the license numper of the available car u want to rent \n";
	string  r;
	cin >> r;
	for (int i = 0; i < max_num_of_cars; i++)
	{
		if (cars[i].get_renter() == "" && cars[i].get_model() != "" &&cars[i].get_license_numper()==r)
		{
			cars[i].set_renter(renters[u].get_name());
			export_cars();
		}
		
	}
	
}