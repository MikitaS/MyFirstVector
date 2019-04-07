#pragma once

//Bit functions:
bool OneBitFromInt(int integer, unsigned int position);
void OneBitToInt(int * integer, bool bit, unsigned int position);

template <>
class vector <bool>
{
public:
//Constructors and destructor:
	vector();
	vector(const vector & other);
	~vector();

//Methods:
	bool is_empty() const;
	size_t size() const ;
	size_t capacity() const;
	void push_back(bool object);
	
//Operators:
	
private:
	static const size_t INIT_VECTOR_CAPACITY_ = 5;
		
	int *data_;
	size_t capacity_;
	size_t counter_;
};

vector<bool>::vector() : 
	data_(new int[INIT_VECTOR_CAPACITY_]), 
	capacity_(INIT_VECTOR_CAPACITY_), 
	counter_(0) {}
	
vector<bool>::vector(const vector<bool> & other) : 
	data_(new int[other.capacity_]),
	capacity_(other.capacity_), 
	counter_(other.counter_)
{
	memcpy<int>(data_, other.data_, (int)(counter_ / (8 * sizeof(int))) + 1);
}

vector<bool>::~vector()
{
	capacity_ = 0;
	counter_ = 0;
	delete [] data_;
}

size_t vector<bool>::capacity() const
{
	return (8 * sizeof(int) * capacity_);
}

size_t vector<bool>::size() const
{
	return counter_;
}

bool vector<bool>::is_empty() const
{
	return !counter_;
}

void vector<bool>::push_back(bool object)
{
	if((int)(counter_ / (8 * sizeof(int))) + 1 >= capacity_)
	{
		capacity_ *= 2;
		this->data_ = resize<int>(data_, counter_, capacity_);
	}
	
	unsigned int position = counter_ % (8 * sizeof(int));
	unsigned int number = counter_ / (8 * sizeof(int));
	
	OneBitToInt(&data_[number], object, position + 1);
	
	++counter_;
	
	return;
}

//Bit Functions:

bool OneBitFromInt(int integer, unsigned int position)
{
	int result = (integer >> (position - 1)); 

	if(result % 2)
		return true;
	else 
		return false;
}

void OneBitToInt(int * integer, bool bit, unsigned int position)
{
	int copy = *integer;
	
	if(OneBitFromInt(copy, position))
	{
		*integer = (copy & ((int)bit << (position - 1)));
	}
	else
	{
		*integer = (copy | ((int)bit << (position - 1)));
	}
} 
