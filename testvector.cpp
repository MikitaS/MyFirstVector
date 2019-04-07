#include <iostream>
#include <cstdio>
#include "vector.hpp"

using namespace std;

bool TestBitFunctions();
bool FirstTestVector();
bool TestBoolVector();

bool FirstTestVector()
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
	
	int * ptr = (int*)vec1;
	vector<int> vec3(ptr, 60);
	delete [] ptr;
	
	
	if(vec3.capacity() < 60)
	{
		return false;
	}
	if(vec3.size() != 60)
	{
		return false;
	}
	
	int i = 0;
	
	if(vec3[i] != 10)
	{
		return false;
	}
	
	++i;
	
	if(vec3[i] != 40)
	{
		return false;
	}
	
	i++;
	
	if(vec3[i] != 100)
	{
		return false;
	}
	
	i++;
	
	for(; i < 60; ++i)
	{
		if(vec3[i] != 112)
		{
			return false;
		}
	}

	return true;

}

bool TestBitFunctions()
{
	int data1 = 0;
	bool bit = 0;
	
	for(int i = 1; i < (8 * sizeof(int) - 1); ++i)
	{
		if(i % 2)
		{
			bit = 1;
		}
		else
		{
			bit = 0;
		}
		
		OneBitToInt(&data1, bit, i);
		if(OneBitFromInt(data1, i) != bit)
		{
			return false;
		}  
	}
	
		for(int i = 1; i < (8 * sizeof(int) - 1); ++i)
	{
		if(i % 2)
		{
			bit = 1;
		}
		else
		{
			bit = 0;
		}
		if(OneBitFromInt(data1, i) != bit)
		{
			return false;
		}  
	}
	return true;
}

bool TestBoolVector()
{
	vector<bool> bector;
	vector<bool> bector2 = bector;
	
	
	if(!bector.capacity())
	{
		return false;
	}
	
	if(bector.size())
	{
		return false;
	}
	
	if(!bector.is_empty())
	{
		return false;
	}
	
	
	
	return true;
}

int main()
{
	cout << "_____________________________________________" << endl;
	cout << "VECTOR LIBRARY TEST STARTES" << endl << endl << endl;
	
	if(FirstTestVector())
		cout << "+ first test vector passed correctly" << endl;
	else
		cout << "- first test vector passed failed" << endl;

	
	if(TestBitFunctions())
		cout << "+ bit data functions work correctly" << endl;
	else
		cout << "- bit data function's test failed" << endl;
		
	if(TestBoolVector())
		cout << "+ bool test vector passed correctly" << endl;
	else
		cout << "- bool data function's test failed" << endl;
		
	cout << endl << endl << "VECTOR LIBRARY TEST FINISHED" << endl;
	cout << "_____________________________________________" << endl;
	return 0;
}
