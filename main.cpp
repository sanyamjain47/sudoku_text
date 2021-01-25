#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> board( 9 , vector<int> (9, 0));


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

    for(int i = 0; i < 9; i++) {
        if(board.at(x_location).at(i) == num) {
            return 0;
        }
    }
    for(int i = 0; i < 9; i++) {
        if(board.at(i).at(y_location) == num) {
            return 0;
        }
    }
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
    if(get_empty(&empty_x, &empty_y) == 0) {
        return 1;
    }
    for(int try_num = 1; try_num < 10;try_num++) {
        if(check_valid(try_num, empty_x, empty_y) == 1) {
            board.at(empty_x).at(empty_y) = try_num;

            if (sudoku_solver() == 1) {
                return 1;
            }
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