#include <iostream>
#include "vector.hpp"

using namespace std;

int compareint(const void * a, const void * b);

int compareint(const void * a, const void * b)
{
	return *(int*)a < *(int*)b;
}

int main()
{
	vector<int> vec1;
	for(int i = 0; i < 60; ++i)
	{
		vec1.push_back(112);
	}
	
	vec1.top() = 20;
	vec1[10] = 10;
	vec1[20] = 40;
	vec1[100] = 100;
	
	vec1.sort();
	
	vector<int> vec2;
	vec2 = vec1;
	cout << vec2 << endl;
	return 0;
}
