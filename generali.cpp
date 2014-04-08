#include <iostream>
#include <fstream>


using namespace std;

int generals, arrows;

int main(int argc, char *argv[]){

	int i = 0;
	int links[10];
	ifstream in ("input.txt");
	in >> generals >> arrows;

	while(!in.eof()){
		in >> links[i];
		i++;
	}


	cout << "*****************************************************" << endl;
	cout << "Generals: " << generals << " Arrows: " << arrows << " Elements of the links: " << i << endl;
	cout << "*****************************************************" << endl;

	for(int k=0;k<i-1;k=k+2){
		cout << "Link: " << links[k] << " to " << links[k+1] << endl;
	}
}