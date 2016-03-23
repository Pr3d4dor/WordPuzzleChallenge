#include <iostream>
#include <ifstream>
#include <string>

using namespace std;

bool wordSearch(int row, int col, int d_row, int d_col, string word){
	for (int i = 0; i < word.size(); i++){
		if (word[i] != puzzle[row][col]){
			return false
		}
		row += d_row;
		col += d_col;
	}
	return true;
}


int main(int argc, char const *argv[]){
	

	return 0;
}