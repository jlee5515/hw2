#include <string>
#include <iostream>
#include <set>
#include <iostream>
#include "book.h"
#include "util.h"
#include <sstream>
#include <iomanip>

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
	ostringstream ss;
	ss << fixed << setprecision(2) << price_;
	string outPut = ss.str();
	return name_ + "\nAuthor: " + authorx + " ISBN: " + isbnx + "\n" + outPut + " " + to_string(qty_) + " left."; 
}

void Book::dump(std::ostream& os) const {
	os << category_ << endl << name_ << endl << price_ << endl << qty_ << endl << isbnx << endl << authorx << endl;
}