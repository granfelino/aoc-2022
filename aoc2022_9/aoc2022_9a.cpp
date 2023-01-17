#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <fstream>
#include <assert.h>

using namespace std;



class Bridge {
    public:
    array<int, 2> h_pos = {0, 0};
    array<int, 2> t_pos = {0, 0};
    int unique_tail_count = 0; 
    set<array<int, 2>> t_places;

    Bridge() {
        check_unique_tail();
    }

    void check_unique_tail() {
        this->t_places.insert(this->t_pos);
        this->unique_tail_count = this->t_places.size();
    }
    vector<string> get_input();
    void parse_line(string line, vector<int> &h_move);
    void move_tail();
    void move_head(const vector<int> &h_move);
    int solution();
};


vector<string> Bridge::get_input() {
    vector<string> input;
    ifstream file("input.txt");
    string line;
    while (getline(file, line)) {
        if (line != "") input.push_back(line);
    }

    return input;
}
                                                                               
void Bridge::parse_line(string line, vector<int> &h_move) {
    // h_move = {direction, no_of_steps}

    // parsing direction
    char direction_char = line.at(0);

    if (direction_char == 'U') h_move.push_back(0);
    else if (direction_char == 'R') h_move.push_back(1);
    else if (direction_char == 'D') h_move.push_back(2);
    else h_move.push_back(3);


    // parsing no. of steps, depending on the size of the line
    if (line.size() == 3) h_move.push_back(stoi(line.substr(2, 1)));
    else h_move.push_back(stoi(line.substr(2, 2)));
    
}


void Bridge::move_tail() {
    int offset[2];

    // check the sign of tail's and head's coordinates
    bool t_x_pos = this->t_pos[0] >= 0;
    bool t_y_pos = this->t_pos[1] >= 0;
    bool h_x_pos = this->h_pos[0] >= 0;
    bool h_y_pos = this->h_pos[1] >= 0;

    // calculate the x offset based on the above conditions 
    if((t_x_pos && h_x_pos) || (!t_x_pos && !h_x_pos)) {
        // h_x and t_x have the same sign 
        offset[0] = this->h_pos[0] - this->t_pos[0];

    } else if ((!t_x_pos && h_x_pos) || (t_x_pos && !h_x_pos)) {
        // h_x positive and t_x have different signs
        offset[0] = this->h_pos[0] - this->t_pos[0];
    } 


    // calculate the y offset based on the above conditions     
    if ((t_y_pos && h_y_pos) || (!t_y_pos && !h_y_pos)) {
        // h_y and t_y have the same sign
        offset[1] = this->h_pos[1] - this->t_pos[1];

    } else if ((!t_y_pos && h_y_pos) || (t_y_pos && !h_y_pos)) {
        //h_y and t_y have different signs
        offset[1] = this->h_pos[1] - this->t_pos[1];

    } 


    // assert that both offsets are under abs(2)
    assert(abs(offset[0]) <= 2);
    assert(abs(offset[1]) <= 2);

    cout << "offset: (" << offset[0] << ", " << offset[1] << ")\n";

    //   $ # $
    // $ 0 0 0 $
    // # 0 T 0 #
    // $ 0 0 0 $
    //   $ # $
    
    // T - tail AND 0
    // 0 - head's position does not cause tail's movement
    // # - head's position causes tail's horizontal/vertical movement:
    //      - those positions are: (2, 0) (0, 2) (-2, 0) (0, -2)
    // $ - head's position causes tail's diagonal movement
    //      - those positions are: (2, -1) (2, 1) ; (1, 2) (-1 , 2) ;
    //                           (-2, 1) (-2, -1) ; (1, -2) (-1, -2)

    if (abs(offset[0]) < 2 && abs(offset[1]) < 2) {
        // offset 0 or 1 or -1 on both axes
        return;

    } else if (offset[0] == 0 xor offset[1] == 0) {
        // horizontal/vertical movement

        //if d_x == 0 else d_y == 0
        if (offset[0] == 0) {
            if (offset[1] > 0 ) ++this->t_pos[1]; // move tail up 
            else --this->t_pos[1]; // move tail down 
        } 
        else {
            if (offset[0] > 0) ++this->t_pos[0]; // move tail right 
            else --this->t_pos[0]; // move tail left 
        }


    } else {
        // diagonal movement
        // 4 cases 
        // (-, +) - left up 
        // (+, +) - right up 
        // (+, -) - right down
        // (-, -) - left down

        // accordingly to the cases above:
        if (offset[0] < 0 && offset[1] > 0) {
            --this->t_pos[0]; // left
            ++this->t_pos[1]; // up
        } else if (offset[0] > 0 && offset[1] > 0) {
            ++this->t_pos[0]; // right
            ++this->t_pos[1]; // up
        } else if (offset[0] > 0 && offset[1] < 0) {
            ++this->t_pos[0]; // right
            --this->t_pos[1]; // down
        } else if (offset[0] < 0 && offset[1] < 0) {
            --this->t_pos[0]; // left
            --this->t_pos[1]; // down
        }
    }

    // checking for unique positions 
    this->check_unique_tail();

}

void Bridge::move_head(const vector<int> &h_move) {
    // head's postition initialized to 0,0 and 
    // then changed accordingly each function call
    

    for (int i = 0; i < h_move[1]; ++i) {
        if (h_move[0] == 0) {
            // move up
            ++this->h_pos[1];
            move_tail();
        } else if (h_move[0] == 1) {
            // move right
            ++this->h_pos[0];
            move_tail();
        } else if (h_move[0] == 2) {
            // move down
            --this->h_pos[1];
            move_tail();
        } else {
            // move left
            --this->h_pos[0];
            move_tail();
        }
    }

}

int Bridge::solution() {
    vector<string> input = this->get_input();
    for (int i = 0; i < input.size(); ++i) {
        // initalize head's move info 
        // in a vector: <direction, no_of_steps>
        vector<int> h_move; 
    
        // fill h_move array
        parse_line(input[i], h_move);


        // moving the head
        move_head(h_move);


    }
    
    // +1 because of 0,0 not counted in
    return this->unique_tail_count; 
}

int main(void) {
    Bridge bridge;
    cout << bridge.solution() << "\n";
    return 0;
}