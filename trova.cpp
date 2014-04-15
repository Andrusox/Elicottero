#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
 
int main(void)
{
// list container
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
 
// do the find() operation
result = find(lst.begin(), lst.end(), i);
 
// print the result
if(result == lst.end()){
cout<<"There is no " << i << " in list lst."<<endl;
}else{
    cout<<"There is a "<< i << " in list lst" << endl;
}
return 0;
}