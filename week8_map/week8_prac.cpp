#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main(){
	map < int, map < int, int > > m;
	
	map < int, map < int, int > > ::iterator itr;
	
	map < int, int > ::iterator ptr;
	
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				m[i][j] = i + j;
			}
		}
		
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				cout << "First key is " << i << " and Second key is " << j << " and value is " << m[i][j] << endl;
			}
		}
		
		cout << "\nNow accessing map though iterator \n\n";
		
		for (itr = m.begin(); itr != m.end(); itr++){
			for (ptr = itr-> second.begin(); ptr != itr -> second.end(); ptr++){
				cout << "First key is " << itr -> first << " and Second key is " << ptr -> first << " and value is " << ptr -> second << endl;
			}
		}
}