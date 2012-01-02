#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include "matrix.h"
#include "matrix_no_move.h"
#include "timer.h"

template<typename MatrixType>
MatrixType make_big_matrix()
{
	srand((unsigned)time(NULL));
	MatrixType big(1000, 1000);

	for (int i = 1; i <= 1000; ++i)
	{
		for (int j = 1; j <= 1000; ++j)
		{
			// http://stackoverflow.com/questions/1340729/how-do-you-generate-a-random-double-uniformly-distributed-between-0-and-1-from-c
			big(i,j) = ((double)rand()/(double)RAND_MAX);
		}
	}

	return big;
}

void main()
{
	timer with_move;
	matrix<double> big_with_move = make_big_matrix<matrix<double>>();
	std::cout << "With move: " << with_move.elapsed() << "s\n";

	timer no_move;
	matrix_no_move<double> big_no_move = make_big_matrix<matrix_no_move<double>>();
	std::cout << "No move: " << no_move.elapsed() << "s\n";
}