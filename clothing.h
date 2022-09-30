#include <string>
#include <iostream>
#include <set>
#include "product.h"
#include "util.h"

class Clothing: public Product{
public:
	Clothing(std::string category, std::string name, double price, int qty, std::string size, std::string brand);
	~Clothing();
	std::set<std::string> keywords() const;
	std::string displayString() const;
	void dump(std::ostream& os) const;

private:
	std::string sizex;
	std::string brandx;

};
