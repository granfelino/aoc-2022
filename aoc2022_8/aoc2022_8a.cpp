#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> get_input();
bool check_left(int row, int col, vector<string> input);
bool check_right(int row, int col, vector<string> input);
bool check_up(int row, int col, vector<string> input);
bool check_down(int row, int col, vector<string> input);
bool is_visible(int row, int col, vector<string> input);
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


bool check_left(int row, int col, vector<string> input) {
    bool visible = 1;
    char height_as_char = input[row].at(col);
    int checked_tree = height_as_char - '0';

    for(int i = 0; i < col; i++) {
        int current_tree = input[row].at(i) - '0';
        if(current_tree >= checked_tree) {
            visible = 0;
            break;
        }
    }

    return visible;
}


bool check_right(int row, int col, vector<string> input) {
    bool visible = 1;
    char height_as_char = input[row].at(col);
    int checked_tree = height_as_char - '0';

    for(int i = input[row].size() - 1; i > col; i--) {
        int current_tree = input[row].at(i) - '0';
        if(current_tree >= checked_tree) {
            visible = 0;
            break;
        }
    }

    return visible;
}


bool check_up(int row, int col, vector<string> input) {
    bool visible = 1;
    char height_as_char = input[row].at(col);
    int checked_tree = height_as_char - '0';

    for(int i = 0; i < row; i++) {
        int current_tree = input[i].at(col) - '0';
        if(current_tree >= checked_tree) {
            visible = 0;
            break;
        }
    }

    return visible;
}


bool check_down(int row, int col, vector<string> input) {
    bool visible = 1;
    char height_as_char = input[row].at(col);
    int checked_tree = height_as_char - '0';
    int size = input.size();

    for(int i = input.size() - 1; i > row; i--) {
        int current_tree = input[i].at(col) - '0';
        if(current_tree >= checked_tree) {
            visible = 0;
            break;
        }
    }

    return visible;
}


bool is_visible(int row, int col, vector<string> input) {
    bool visible;
    if(check_left(row, col, input)) {
        visible = 1;
    } else if(check_right(row, col, input)) {
        visible = 1;
    } else if(check_up(row, col, input)) {
        visible = 1;
    } else if(check_down(row, col, input)) {
        visible = 1;
    } else {
        visible = 0;
    }
    return visible;
}


int solution() {
    vector<string> input = get_input();
    int visible_count = 0;
    
    for(int row = 0; row < input.size(); row++) {
        string line = input[row];
        bool up = (row == 0);
        bool down = (row == input.size() - 1);

        for(int col = 0; col < line.size(); col++) {
            bool left = (col == 0);
            bool right = (col == line.size() - 1);

            if(!(up || down || left || right)) {
                visible_count += is_visible(row, col, input);
            } else {
                ++visible_count;
            }

            cout << "We're at (" << row << ", " << col << ") now." << "\n";
        }
    }

    return visible_count;
}


int main() {
    cout << solution() << "\n";
    return 0;
}