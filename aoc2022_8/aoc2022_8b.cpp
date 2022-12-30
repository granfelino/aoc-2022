#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> get_input();
int check_left(int row, int col, vector<string> input);
int check_right(int row, int col, vector<string> input);
int check_up(int row, int col, vector<string> input);
int check_down(int row, int col, vector<string> input);
int scenic_score(int row, int col, vector<string> input);
int solution();


vector<string> get_input() {
    ifstream file("/home/granfelino/own/aoc2022/aoc2022_8/input.txt");
    string line;
    vector<string> input;
    while(getline(file, line)) {
        if(line.size() > 0) {
            input.push_back(line);
        }
    }
    file.close();
    return input;
}


int check_left(int row, int col, vector<string> input) {
    int score = 0;
    char height_as_char = input[row].at(col);
    int checked_tree = height_as_char - '0';

    for(int i = col - 1; i >= 0; i--) {
        char temp_height = input[row].at(i) ;
        int current_tree = temp_height - '0';
        if(current_tree < checked_tree) {
            ++score;
        } else if ((current_tree == checked_tree) || (current_tree > checked_tree)) {
            ++score;
            break;
        }
    }    
    
    return score;
}

int check_right(int row, int col, vector<string> input) {
    int score = 0;
    char height_as_char = input[row].at(col);
    int checked_tree = height_as_char - '0';

    for(int i = col + 1; i < input[row].size(); i++) {
        int current_tree = input[row].at(i) - '0';
        if(current_tree < checked_tree) {
            ++score;
        } else if ((current_tree == checked_tree) || (current_tree > checked_tree)) {
            ++score;
            break;
        }
    }    
    
    return score;
}

int check_up(int row, int col, vector<string> input) {
    int score = 0;
    char height_as_char = input[row].at(col);
    int checked_tree = height_as_char - '0';

    for(int i = row - 1; i >= 0; i--) {
        int current_tree = input[i].at(col) - '0';
        if(current_tree < checked_tree) {
            ++score;
        } else if ((current_tree == checked_tree) || (current_tree > checked_tree)) {
            ++score;
            break;
        }
    }    
    
    return score;
}

int check_down(int row, int col, vector<string> input) {
    int score = 0;
    char height_as_char = input[row].at(col);
    int checked_tree = height_as_char - '0';

    for(int i = row + 1; i < input.size(); i++) {
        int current_tree = input[i].at(col) - '0';
        
        if(current_tree < checked_tree) {
            ++score;
        } else if ((current_tree == checked_tree) || (current_tree > checked_tree)) {
            ++score;
            break;
        }
    }    
    
    return score;
}


int scenic_score(int row, int col, vector<string> input) {
    int left = check_left(row, col, input);
    int right = check_right(row, col, input);
    int up = check_up(row, col, input);
    int down = check_down(row, col, input);
    int temp_score = left * right * up * down;
    return temp_score;
}


int solution() {
    vector<string> input = get_input();
    int max_score = 0;
    
    for(int row = 0; row < input.size(); row++) {
        string line = input[row];
        bool up = (row == 0);
        bool down = (row == input.size() - 1);

        for(int col = 0; col < line.size(); col++) {
            bool left = (col == 0);
            bool right = (col == line.size() - 1);
            int temp_score = 0;

            if(!(up || down || left || right)) {
                temp_score = scenic_score(row, col, input);
            }

            if(temp_score > max_score) {
                max_score = temp_score;
            }
            cout << "We're at (" << row << ", " << col << ") now." << "\n";
        }
    }

    return max_score;
}


int main() {
    cout << solution() << "\n";
    return 0;
}