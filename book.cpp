#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include "book.h"
#include "util.h"
#include <sstream>

using namespace std;

Book::Book(const string category, const string name, double price, int qty, string ISBN, string Author) : 
	Product(category, name, price, qty)
{
	authorx = Author;
	isbnx = ISBN;
}

Book::~Book()
{

}
set<string> Book::keywords() const {

	set<string> nameofbook = parseStringToWords(name_);
	set<string> authors = parseStringToWords(authorx);
	set<string> totalkeywords = setUnion(authors, nameofbook);
	totalkeywords.insert(isbnx);

	return totalkeywords;
}

string Book::displayString() const {

	stringstream doubleprice;
	doubleprice << price_;
	string price = doubleprice.str();

	stringstream intqauntity;
	intqauntity << qty_;
	string qty = intqauntity.str();

	string newString = "";
	newString += name_;
	newString += "\n";
	newString += "Author: ";
	newString += authorx;
	newString += " ISBN: ";
	newString += isbnx;
	newString += "\n";
	newString += price;
	newString += " ";
	newString += qty;
	newString += " left.";
	return newString;
}

void Book::dump(std::ostream& os) const {
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbnx << "\n" << authorx << endl;
}