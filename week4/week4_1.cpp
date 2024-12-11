#include <iostream>
using namespace std;

int main (){

int up,low;
cout<< "Enter upper limit:";
cin >> up;
cout<< "Enter lower limit:";
cin >> low;

int result = 0;
if (up > low){
	for (int i=low;i<up ; i++)	{
		if (i%2!=0)
		
		{
		cout << i << "\t";
		result += i;
		}else
		{
			continue;
		}
		
	}
	cout << "\nThe sum of all odd numbers between " << low << " and " << up << " is: " << result << endl;
}
}