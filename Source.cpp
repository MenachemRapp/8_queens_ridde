//creates a chessboard with 8 queens by using a recursion

#include <iostream>
using namespace std;



//tests if the chess board is possible
bool test_chess(int* array, int first, int last) {
	if (last == first)
		return true;

	if (array[last] == array[first])
		return false;
	if (array[last] + last == array[first] + first)
		return false;
	if (array[last] - last == array[first] - first)
		return false;


	test_chess(array, first + 1, last);
}


//fixes the row if it's possible
bool fix_row(int* array, int first, int last) {
	if (array[last] > 7)
		return false;

	if (test_chess(array, first, last))
		return true;
	else {
		array[last]++;
		fix_row(array, first, last);
	}
}

//creates a vector of  8 queens
//where each index represents a row and each value represents a column
void create_chess(int* array, int first = 0, int last = 0) {
	if (last < 8) {
		if (fix_row(array, first, last))
			create_chess(array, first, last + 1);

		else
		{
			array[last] = 0;
			array[last - 1]++;
			create_chess(array, first, last - 1);
		}

	}
}

//prints a row
void print_row(int row, int length = 7) {
	if (length >= 0) {
		print_row(row, length - 1);
		if (length == row)
			cout << "1 ";
		else
			cout << "0 ";
	}
}


//prints the board
void print_board(int* board, int length = 7) {
	if (length >= 0) {
		print_board(board, length - 1);
		print_row(board[length]);
		cout << endl;
	}
}

int main() {
	int chess[8] = { 0 };

	create_chess(chess);

	print_board(chess);

	return 0;
}

/*

example:

1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0
0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0

*/