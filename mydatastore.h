#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "util.h"

class MyDataStore : public DataStore{
	public:
		MyDataStore();
		~MyDataStore();
		virtual void addProduct(Product* p);
		virtual void addUser(User* u);
		virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);
		void displayCart(std::string username);
		void purchaseCart(std::string username);
		void addToCart(std::string username, Product* p);
		virtual void dump(std::ostream& ofile);

	private:
		std::set<Product*> product;
		std::map<std::string, User*> user;
		std::set<User*> userSet;
		std::map<std::string, std::vector<Product*>> cart;
		std::map<std::string, std::set<Product*>> productKeywordMap;
};
