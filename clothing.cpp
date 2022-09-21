#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include "clothing.h"
#include "util.h"
#include <sstream>
using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand):
	Product(category, name, price, qty), sizex(size), brandx(brand)
{

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
		
	stringstream doubleprice;
	doubleprice << price_;
	string price = doubleprice.str();

	stringstream intqauntity;
	intqauntity << qty_;
	string qty = intqauntity.str();

	string newString = "";
	newString += name_;
	newString += "\n";
	newString += "Size: ";
	newString += sizex;
	newString += " Brand: ";
	newString += brandx;
	newString += "\n";
	newString += price;
	newString += " ";
	newString += qty;
	newString += " left.";
	return newString;
}

void Clothing::dump(std::ostream& os) const {
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << sizex << "\n" << brandx << endl;
}