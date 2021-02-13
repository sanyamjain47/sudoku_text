#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> board( 9 , vector<int> (9, 0));


/**
 * Takes the input from the user in 2D vector of int type
 */
void take_input();

/**
 * Returns 1 if there is an empty block in the sudoku.
 * If there exists an empty block the location is copied to empty_x and empty_y
 */
int get_empty(int *empty_x,int * empty_y);

/**
 * Checks if inserting a value at a certain (x_location, y_location) is possible.
 * i.e. that number doesn't exist in the row, column or the small box
 */
int check_valid(int num, int x_location, int y_location);

/**
 * Recursive function that solves the sudoku with the help of backtracking
 */
int sudoku_solver();

/**
 * A Simple Print funciton to display sudoku
 */
void print_sudoku();


void take_input() {
    for(int i = 0; i< 9;i++) {
        for(int j = 0; j < 9;j++) {
            cin>>board.at(i).at(j);
        }
    }
}

int get_empty(int *empty_x,int * empty_y) {
    for (int i = 0; i < 9 ; i++) {
        for (int j = 0; j< 9; j++) {
            if (board.at(i).at(j) == 0) {
                *empty_x = i;
                *empty_y = j;
                return 1;
            }
        }
    }
    return 0;
}

int check_valid(int num, int x_location, int y_location) {
    
    //Checks in the column
    for(int i = 0; i < 9; i++) {
        if(board.at(x_location).at(i) == num) {
            return 0;
        }
    }
    //Checks in the row
    for(int i = 0; i < 9; i++) {
        if(board.at(i).at(y_location) == num) {
            return 0;
        }
    }
    //Checks in the small 3x3 box that the location is part of
    int temp_x = x_location/3;
    temp_x *= 3;
    int temp_y = y_location/3;
    temp_y *= 3;
    for(int i = temp_x; i < (temp_x + 3); i++) {
        for(int j = temp_y; j < (temp_y+3);j++) {
            if(board.at(i).at(j) == num) {
                return 0;
            }
        }
    }
    return 1;

}

int sudoku_solver() {
    int empty_x, empty_y;
    //Gets an empty square on sudoku
    if(get_empty(&empty_x, &empty_y) == 0) {
        return 1;
    }
    //Tries all numbers from 1-9
    for(int try_num = 1; try_num < 10;try_num++) {
        //Checks if the number is possible
        if(check_valid(try_num, empty_x, empty_y) == 1) {
            //Inserts the number
            board.at(empty_x).at(empty_y) = try_num;
            //Checks if the sudoku is solvable using this number
            if (sudoku_solver() == 1) {
                return 1;
            }
            // Set the value back to zero
            board.at(empty_x).at(empty_y) = 0;
        }
        
    }
    return 0;
}

void print_sudoku() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0 ; j< 9 ;j++) {
            cout<<board.at(i).at(j)<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    take_input();
    sudoku_solver();
    print_sudoku();
    return 1;
}