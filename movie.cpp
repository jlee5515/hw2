#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include "movie.h"
#include "util.h"
#include <sstream>

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating):
	Product(category, name, price, qty)
{
	genrex = genre;
	ratingx = rating;
}
Movie::~Movie()
{

}

set<string> Movie::keywords() const {
	
	set<string> nameofmovie = parseStringToWords(name_);
	set<string> typeofgenre = parseStringToWords(genrex);
	set<string> totalkeywords = setUnion(nameofmovie, typeofgenre);

	return totalkeywords;
}

string Movie::displayString() const {

	string newString = "";
	stringstream doubleprice;
	doubleprice << price_;
	string price = doubleprice.str();

	stringstream intqauntity;
	intqauntity << qty_;
	string qty = intqauntity.str();

	newString += name_;
	newString += "\n";
	newString += "Genre: ";
	newString += genrex;
	newString += " Rating: ";
	newString += ratingx;
	newString += "\n";
	newString += price;
	newString += " ";
	newString += qty;
	newString += " left.";
	return newString;
}

void Movie::dump(std::ostream& os) const {
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genrex << "\n" << ratingx << endl;
}