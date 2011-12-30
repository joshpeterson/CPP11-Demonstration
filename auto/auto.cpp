#include <vector>
#include <iostream>

void main()
{
	std::vector<int> numbers;
	numbers.push_back(42);
	numbers.push_back(314);
	numbers.push_back(13);

	// C++ 98 for loop:
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	// C++11 for loop with auto:
	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}