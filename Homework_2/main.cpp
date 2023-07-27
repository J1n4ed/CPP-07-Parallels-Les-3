// Задание 2
// for_each

// includes

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <algorithm>
// #include <iomanip>
#include <random>
#include "for_each.h"

// functions

void dummy_f_i(int input)
{
	std::cout << input * 2 << '\t';
}

void dummy_f_d(double input)
{
	std::cout << input * 2 << '\t';
}

// globals

using namespace std::chrono_literals;

int main(int argc, char** argv)
{
	// vars

	std::vector<int> vector;
	std::list<double> list;
	using clock = std::chrono::steady_clock;
	clock::time_point time_start;
	clock::time_point time_end;
	clock::duration time_elapsed;
	std::mt19937 rng;
	std::uniform_int_distribution<int> dist(1, 9);
	const int size = 15;

	// std::cout.precision(4);

	// body

	std::cout << "Test program. dummy function prints container element multed by 2.\n\n";

	// - fill containers with some stuff

	for (int i = 0; i < size; ++i)
	{
		vector.push_back(dist(rng));
	}

	for (int i = 0; i < size; ++i)
	{
		list.push_back(dist(rng));
	}
	
	// - result	

	std::cout << "Test containers.\nVector:\n";

	for (const auto & element : vector)
	{
		std::cout << element << '\t';
	}
	
	std::cout << "\nList:\n";

	for (const auto& element : list)
	{
		std::cout << element << '\t';
	}
	
	// -------- executing standard for_each

	std::cout << "\n\nExecuting standard library for_each...\n";

	time_start = clock::now();

	std::cout << "Vector:\n";
	std::for_each(vector.begin(), vector.end(), dummy_f_i);
	std::cout << '\n';
	std::cout << "List:\n";
	std::for_each(list.begin(), list.end(), dummy_f_d);	

	time_end = clock::now();
	time_elapsed = time_end - time_start;

	std::cout << "\nExecuted. Time elapsed: " << time_elapsed.count() << "ms";

	// -------- executing custom for_each

	std::cout << "\n\nExecuting homework example for_each...\n";

	time_start = clock::now();

	std::cout << "Vector:\n";
	jinx::for_each(vector.begin(), vector.end(), dummy_f_i);
	std::cout << '\n';
	std::cout << "List:\n";
	jinx::for_each(list.begin(), list.end(), dummy_f_d);

	time_end = clock::now();
	time_elapsed = time_end - time_start;

	std::cout << "\nExecuted. Time elapsed: " << time_elapsed.count() << "ms";	

	// exit

	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}