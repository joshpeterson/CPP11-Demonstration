#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

void save(const std::vector<int> to_save, std::ostream& stream)
{
	for (auto it = to_save.begin(); it != to_save.end(); ++it)
	{
		stream << *it;
	}
}

void save_with_lambda(const std::vector<int> to_save, std::ostream& stream)
{
	std::for_each(to_save.begin(), to_save.end(), [&stream](int value) { stream << value; });
}

template<typename T>
std::vector<T> filter(const std::vector<T> input, std::function<bool (const T&)> predicate)
{
	std::vector<T> output;
	std::for_each(input.cbegin(), input.cend(), [&output, predicate](T value) { if (predicate(value)) output.push_back(value); });
	return output;
}

template <typename T>
void print_vector(const std::vector<T>& to_print)
{
	std::for_each(to_print.begin(), to_print.end(), [](T value) { std::cout << value << " "; });
	std::cout << std::endl;
}

void main()
{
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);

	std::stringstream persisted;
	save(numbers, persisted);
	std::cout << persisted.str() << std::endl;

	std::stringstream persisted_with_lamda;
	save_with_lambda(numbers, persisted_with_lamda);
	std::cout << persisted_with_lamda.str() << std::endl;

	// Capture total by reference
	int total = 0;
	std::for_each(numbers.begin(), numbers.end(), [&total](int number) { total += number; });
	std::cout << total << std::endl;

	// Capture total by reference and multiplier by value
	int multiplier = 2;
	total = 0;
	std::for_each(numbers.begin(), numbers.end(), [&total, multiplier](int number) { total += number * multiplier; });
	std::cout << total << std::endl;

	// Name the lambda and use it later
	total = 0;
	auto summer = [&total](int number) { total += number; };
	std::for_each(numbers.begin(), numbers.end(), summer);
	std::cout << total << std::endl;

	// Get all even numbers
	print_vector(filter<int>(numbers, [](int n) { return n % 2 == 0 ? true : false; } ));

	// Get all odd numbers
	print_vector(filter<int>(numbers, [](int n) { return n % 2 == 0 ? false : true; } ));
}