#pragma once

template <>
class vector <bool>
{
public:
	vector() = default;
	vector(const vector & other) = default;
	~vector() = default;
private:
	int *data_;
	size_t capacity_;
	size_t counter_;
};


bool OneBitFromInt(int integer, unsigned int position);
void OneBitToInt(int * integer, bool bit, unsigned int position);

bool OneBitFromInt(int integer, unsigned int position)
{
	//std::cout << integer << std::endl;
	int result = (integer >> (position - 1)); 
	//std::cout << result << std::endl;

	if(result % 2)
		return true;
	else 
		return false;
}

void OneBitToInt(int * integer, bool bit, unsigned int position)
{
	int copy = *integer;
	int intbit = (int)bit;
	int movedbit = (intbit << (position - 1));
	
	if(OneBitFromInt(copy, position))
	{
		*integer = (copy & movedbit);
	}
	else
	{
		*integer = (copy | movedbit);
	}
} 
