#include <iostream>

using namespace std;

union pointer{
	int num;
	char a;
};

int main(){
	
	union pointer p1;
	
	p1.num = 90;
	
	union pointer* p2 = &p1;
	
	cout << "p2->num : " << p2->num << "  p2->num : " << p2->a << endl;

	return 0;
}
