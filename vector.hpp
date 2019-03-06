#pragma once

#include "memory.hpp"
#include <iostream>

template <typename Type>
class vector
{
public:
///Constructors and destructor:
	vector();//tested
	vector(const vector & other);//tested
	~vector();//tested
	
///Methods:
	bool is_empty() const;//tested
	size_t size() const;//tested
	size_t capacity() const;//tested
	
	void push_back(Type object);//tested
	Type pop_back();//tested
	
///Operators:
	vector & operator = (const vector & other);//tested
	
///FOR DEBUG:
template <typename type>
friend std::ostream & operator << (std::ostream & os, const vector<type> & vec);

private:
	const size_t INIT_VECTOR_CAPACITY_ = 50;

	Type * data_;
	size_t capacity_;
	size_t counter_;
};

#include "vectorlibtemp.hpp"
