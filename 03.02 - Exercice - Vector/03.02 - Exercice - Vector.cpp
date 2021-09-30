#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> vec(12);
void CreateVec() 
{
	//gets random seed to output random numbers [1-20]
	srand(time(0));
	for (size_t n = 0; n < vec.size(); n++)
	{
		vec[n] = (1 + rand() % 20);
	}
}
void DisplayVec() 
{
	//prints the vector
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i != vec.size()) 
		{
			std::cout << vec[i] << " : ";
		}
	}
	std::cout << std::endl;
}
void InsertAtSmallestPosition() 
{

	std::vector<int>::iterator position;
	int temp = 20;
	
	for (std::vector<int>::iterator minValue = vec.begin(); minValue < vec.end(); minValue++)
	{
		if (*minValue < temp) 
		{
			temp = *minValue;
			position = minValue;
		}
	}
	std::cout << "\n" << "Min value is : " << *position << "\n\n";
	vec.insert(position+1, 0);
}

int main()
{
	CreateVec();
	DisplayVec();
	InsertAtSmallestPosition();
	DisplayVec();
}