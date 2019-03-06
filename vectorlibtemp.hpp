#pragma once

///Constructors and destructor:
template <typename Type>
vector<Type>::vector() : 
	data_(new Type[INIT_VECTOR_CAPACITY_]), 
	capacity_(INIT_VECTOR_CAPACITY_) , 
	counter_(0) {}

template <typename Type>
vector<Type>::vector(const vector<Type> & other) : 
	data_(new Type[other.capacity_]),
	capacity_(other.capacity_), 
	counter_(other.counter_)
{
	memcpy<Type>(data_, other.data_, counter_);
}

template <typename Type>
vector<Type>::~vector()
{
	capacity_ = 0;
	counter_ = 0;
	delete [] data_;
}

///Methods:

template <typename Type>
bool vector<Type>::is_empty() const
{
	return counter_;
}

template <typename Type>
size_t vector<Type>::size() const
{
	return counter_;
}

template <typename Type>
size_t vector<Type>::capacity() const
{
	return capacity_;
}

template <typename Type>
void vector<Type>::push_back(Type object)
{
	if(counter_ >= capacity_)
	{
		capacity_ *= 2;
		this->data_ = resize<Type>(data_, counter_, capacity_);
	}
	
	this->data_[counter_++] = object;
	return;
}

template <typename Type>
Type vector<Type>::pop_back()
{
	if(counter_ == 0){}
	else
	{
		return data_[--counter_];
	}
}

template <typename Type>
Type & vector<Type>::top()
{
	return data_[counter_ - 1];
}

///Operators:
template <typename Type>
vector<Type> & vector<Type>::operator = (const vector<Type> & other)
{
	capacity_ = other.capacity_;
	counter_ = other.counter_;
	
	delete [] data_;
	data_ = new Type[capacity_];
	memcpy<Type>(data_, other.data_, counter_);
	
	return *this;
}

template <typename Type>
Type & vector<Type>::operator [] (size_t number)
{
	if(number < counter_)
	{
		return data_[number];
	}
	else
	{
		return top();
	}
}

///Debug:
template <typename Type>
std::ostream & operator << (std::ostream & os, const vector<Type> & vec)
{
	os << "capacity = " << vec.capacity_ << ", counter = " << vec.counter_ << std::endl;
	for(int i = 0; i < vec.counter_; ++i)
	{
		os << i << ") " << vec.data_[i] << std::endl; 
	} 
	return os;
}
