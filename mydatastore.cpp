#include "mydatastore.h"
#include "util.h"

using namespace std;

MyDataStore::MyDataStore(){

}

MyDataStore::~MyDataStore(){
	for(set<User*>::iterator it = userSet.begin(); it != userSet.end(); ++it){
		delete *it;
	}
	for(set<Product*>::iterator it2 = product.begin(); it2 != product.end(); ++it2){
		delete *it2;
	}
}

//Mapping products to keywords
void MyDataStore::addProduct(Product* p){
	product.insert(p);
	set<string> keyWordList = p->keywords();

	for(set<string>::iterator it = keyWordList.begin(); it != keyWordList.end(); ++it){
		if(productKeywordMap.find(*it) == productKeywordMap.end()){ //keyword does not exist; map the keyword to a product set, and insert that mapping into the map of all keywords and sets
			set<Product*> insertProduct;
			insertProduct.insert(p);
			productKeywordMap.insert(make_pair((*it), insertProduct));
		}
		else{ 															//A keyword for the product exists, insert the product into the map of keywords and their
			productKeywordMap[*it].insert(p);	// corresponding product set
		}
	}
}

//Adds user to the map of username-user object, and adds username to list of all users
void MyDataStore::addUser(User* u){
	string usersname = u->getName();
 	user.insert(make_pair(usersname, u));
	userSet.insert(u);
}


//Performs a search of products whose keywords match the given "terms" 
//type 0 = AND search (intersection of results for each term) while
//type 1 = OR search (union of results for each term)
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
	vector<Product*> hits_;
	set<Product*> results;
	set<Product*> keys;

	if (productKeywordMap.find(terms[0]) != productKeywordMap.end()){
    results = productKeywordMap.find(terms[0])->second;
  }
	for(vector<string>::iterator it = terms.begin(); it != terms.end(); ++it) {
    if(productKeywordMap.count(*it) == 1){
      if(type == 0){
        keys = productKeywordMap.find(*it)->second;
        results = setIntersection(results, keys);
      }
			else{
        keys = productKeywordMap.find(*it)->second;
        results = setUnion(results, keys);
      }
    }
  }
	for(set<Product*>::iterator it2 = results.begin(); it2 != results.end(); ++it2){
		hits_.push_back(*it2);
	}
	return hits_;
}

//Display the user's cart, if user is valid
void MyDataStore::displayCart(string username){
	if(cart.find(username) == cart.end()){
		cout << "No username was found/invalid username. Please enter a valid username." << endl;
	}
	else{
		cout << username << "'s cart:" << endl;
		for(unsigned int i = 0; i < cart[username].size(); i++){
			cout << "Item " << i + 1 << ": " << (cart[username].at(i))->displayString() <<endl;
		}
	}
}

//Adds products to user's cart, if valid username and product. Will also create a mapping of username and cart if none exists
void MyDataStore::addToCart(string username, Product* p){
	if(cart.find(username) == cart.end()){ //No cart exists for the user, make one
		if((p->getQty()) > 0){
			vector<Product*> products;
			products.push_back(p);
			cart.insert(make_pair(username, products));
			cout << "Added to cart." << endl;
		}
		else{
			cout << "Item out of stock." << endl;
		}
	}
	else{ //User cart exists
		if((p->getQty()) > 0){
			cart[username].push_back(p);
			cout << "Added to cart." << endl;
		}
		else{
			cout << "Item out of stock." << endl;
		}
	}
}

//Purchases all purchasable items in user's cart, if user is valid. Reduces quantity of product and total balance of user, and removes item from cart
void MyDataStore::purchaseCart(string username){
	if(cart.find(username) != cart.end()){
		vector<Product*> userItems = cart[username];
		for(unsigned int i = 0; i < cart[username].size(); i++){
			if(((userItems[i])->getQty()) > 0 && ((user[username])->getBalance()) >= ((userItems[i])->getPrice())){
				(userItems[i])->subtractQty(1);
				user[username]->deductAmount(((userItems[i])->getPrice()));
				userItems.erase(userItems.begin()); //deletes item from temp vector
				cart[username].erase(cart[username].begin()); //deletes item from the cart vector
			}
		}
		cart[username] = userItems;
		cout << "Possible purchases complete." << endl;
	}
	else{
		cout << "Invalid Username" << endl;
	}
}

//Outputs all data related to users and products 
void MyDataStore::dump(std::ostream& ofile) {
	ofile << "<products>" << endl;
	for(set<Product*>::iterator it = product.begin(); it != product.end(); ++it){
    (*it)->dump(ofile);
  }
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
  for(set<User*>::iterator it = userSet.begin(); it != userSet.end(); ++it) {
    (*it)->dump(ofile);
  }
  ofile << "</users>" << endl;
}