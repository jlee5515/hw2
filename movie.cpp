#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include "movie.h"
#include "util.h"
#include <sstream>
#include <iomanip>

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
	ostringstream ss;
	ss << fixed << setprecision(2) << price_;
	string outPut = ss.str();
	return name_ + "\nGenre: " + genrex + " Rating: " + ratingx + "\n" + outPut + " " + to_string(qty_) + " left."; 
}

void Movie::dump(std::ostream& os) const {
	os << category_ << endl << name_ << endl << price_ << endl << qty_ << endl << genrex << endl << ratingx << endl;
}