#pragma once

#include "memory.hpp"
#include <iostream>

template <typename Type>
class vector
{
public:
///Constructors and destructor:
	vector();//done
	vector(const vector & other);
	~vector();//done
	
///Methods:
	bool is_empty() const;//done
	size_t size() const;//done
	size_t capacity() const;//done
	
	void push_back(Type object);//done
	
///Operators:
	
///FOR DEBUG:
template <typename type>
friend std::ostream & operator << (std::ostream & os, const vector<type> & vec);//done

private:
	static const size_t INIT_VECTOR_CAPACITY_ = 50; 

	Type * data_;
	size_t capacity_;
	size_t counter_;
};

#include "vectorlibtemp.hpp"
