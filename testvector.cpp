#include <iostream>
#include "vector.hpp"

using namespace std;

int main()
{
	vector<int> vec1;
	for(int i = 0; i < 155; i++)
		vec1.push_back(50);
		
	vector<int> vec2 = vec1;
	cout << vec2;
	return 0;
}
