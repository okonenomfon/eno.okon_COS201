#include <iostream>
using namespace std;

union unionJob {
	char name[32];
	float salary;
	int workerNo;
} uJob;

struct structJob{
	char name[32];
	float salary;
	int workerNo;
} sJob;

int main(){
	cout << "Size of union in bytes " << sizeof(uJob) << endl;
	cout << "Size of Structure in bytes " << sizeof(sJob) << endl;
	
	return 0;
}
