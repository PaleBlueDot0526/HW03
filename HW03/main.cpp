#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main()
{
	SimpleVector<int> vec(1);

	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(12);
	vec.push_back(4);
	vec.push_back(5213);

	cout << "Size: " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;

	vec.pop_back();
	cout << "After pop_back -> Size: " << vec.size() << endl;

	vec.sortData();
	cout << "Sort : ";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	return 0;
}