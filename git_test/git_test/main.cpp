#include <iostream>

using namespace std;

void print_second_commit();

int main()
{
	
	print_second_commit();

	cout << "first commit test" << endl;
}

void print_second_commit()
{
	for(int i=0;i<10;i++)
		cout << "second commit " << endl;
}