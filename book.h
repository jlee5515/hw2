#define BOOK_H

#include <string>
#include <iostream>
#include <set>
#include "product.h"
#include "util.h"

class Book: public Product{
public:
	Book(std::string category, std::string name, double price, int qty, std::string ISBN, std::string author);
	~Book();
	std::set<std::string> keywords() const;
	std::string displayString() const;
	void dump(std::ostream& os) const;

private:
	std::string isbnx;
	std::string authorx;

};