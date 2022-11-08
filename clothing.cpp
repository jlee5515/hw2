
#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include "clothing.h"
#include "util.h"
#include <sstream>
#include <iomanip>
using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand):
	Product(category, name, price, qty)
{
	sizex = size;
	brandx = brand;
}

Clothing::~Clothing()
{

}

set<string> Clothing::keywords() const {

	set<string> nameofclothing = parseStringToWords(name_);
	set<string> nameofbrand = parseStringToWords(brandx);
	set<string> totalkeywords = setUnion(nameofclothing, nameofbrand);

	return totalkeywords;
}
string Clothing::displayString() const {
	ostringstream ss;
	ss << fixed << setprecision(2) << price_;
	string outPut = ss.str();
	return name_ + "\nSize: " + sizex + " Brand: " + brandx +"\n" + outPut + " " + to_string(qty_) + " left."; 
}

void Clothing::dump(std::ostream& os) const {
	os << category_ << endl << name_ << endl << price_ << endl << qty_ << endl << sizex << endl << brandx << endl;
}