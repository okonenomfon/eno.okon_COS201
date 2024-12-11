#include <iostream>
using namespace std;

int main (){
	int n = 10;
	
	loop:
		cout << n << ", ";
		n--;
		if (n>0) goto loop;
		cout << "End of loop!\n";
	
	return 0;
}

int grade() {
    int score = 40;

    int range = score / 10;

    switch (range) {
        case 10:
            cout << "Excellent" << endl;
            break;
        case 9:
            cout << "Excellent" << endl;
            break;
        case 8:
            cout << "Excellent" << endl;
            break;
        case 7:
            cout << "Excellent" << endl;
            break;
        case 6:
            cout << "Very Good" << endl;
            break;
        case 5:
            cout << "Good" << endl;
            break;
        case 4:
            cout << "Pass" << endl;
            break;
        case 0:
            cout << "Carry Over" << endl;
            break;
        case 1:
            cout << "Carry Over" << endl;
            break;
        case 2:
            cout << "Carry Over" << endl;
            break;
        case 3:
            cout << "Carry Over" << endl;
            break;
        default:
            cout << "Invalid" << endl;
            break;
    }

    return 0;
}