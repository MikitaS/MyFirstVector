#pragma once

#include "memory.hpp"
#include <iostream>
#include <cstdio>

/*!
 * @brief Vector class
 * @details vector, realized on dynamic array 
 * @authors Mikita
 * @version 2.0.0
 * @date 8 March, 2019
 * @warning This class can't erase or add element if it not the last
 * @copyright MIT License
*/
template <typename Type>
class vector
{
public:
//Constructors and destructor:
	/*!
	 * Construct vector with init capacity
	 */
	vector();
	
	/*!
	 * make copy of other vector
	 * @param [in] other another vector
	 */
	vector(const vector & other);
	
	~vector();
	
//Methods:
	
	/*!
	 * @return true if the vector is empty
	 */
	bool is_empty() const;
	
	/*!
	 * @return current amount of elements in vector
	 */
	size_t size() const;
	
	/*!
	 * @return current capacity of vector
	 */
	size_t capacity() const;
	
	/*!
	 * add new element in the end of vector
	 * @param [in] object smth you put in vector
	 */ 
	void push_back(Type object);
	
	/*!
	 * delete the last element
	 * @return the last element
	 * @warning IF THE VECTOR IS EMPTY UNDEFINED BEHAVIOUR
	 */ 
	Type pop_back();
	
	/*!
	 * give access to the last element
	 * @return link to the last element
	 * @warning IF THE VECTOR IS EMPTY UNDEFINED BEHAVIOUR
	 */	
	Type & top();
	
	/*!
	 * sort data of vector
	 * @note in case of users class, "operator > " MUST be defined 
	 */
	void sort();
	
//Operators:
	/*!
	 * make "this" copy of other
	 * @param [in] other link to another object
	 */
	vector & operator = (const vector & other);
	
	/*!
	 * compare two vectors
	 * @param [in] other another vector
	 * @return true if the vectors are equal
	 */	
	bool operator == (const vector & other) const;
	
	/*!
	 * give access to the needed element
	 * @param [in] number of needed element
	 * @return link to needed element
	 * @warning IF THE VECTOR IS EMPTY UNDEFINED BEHAVIOUR
	 */	
	Type & operator[](size_t number);
	
//FOR DEBUG:
template <typename type>
friend std::ostream & operator << (std::ostream & os, const vector<type> & vec);


private:
	///first initialization vector capacity
	const size_t INIT_VECTOR_CAPACITY_ = 50;

	Type * data_; ///array with data
	size_t capacity_;///current max size of the vector
	size_t counter_;///current amount of elements in vector
	
};


template <class Type>
int vectorelementcompare(const void * a, const void * b)
{
	return *(Type*) a > *(Type*) b;
} 

#include "vectorlibtemp.hpp"
