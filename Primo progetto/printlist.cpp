#include <iostream>
#include <list>
using namespace std;
int main (){

	list <int> lst;
	// list iterators
	list <int>::iterator result;
	int i=466;
	 
	// pushing data, constructing lst list
	lst.push_back(9);
	lst.push_back(21);
	lst.push_back(14);
	lst.push_back(10);
	lst.push_back(16);
	lst.push_back(31);

  cout << "mylist contains:";
  	for (list<int>::iterator it=lst.begin(); it != lst.end(); ++it){
    	cout << ' ' << *it;
	}

  cout << endl;
  cout << "Size: " << lst.size() << endl;
}