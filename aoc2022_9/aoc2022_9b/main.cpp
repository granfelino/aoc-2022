#include <iostream>
#include <vector>
#include "CreateRope.hpp"
#include "GetInput.hpp"
using namespace std;

array<int, 2> parse_line(string line);
int get_direction(char dir);
int main();

array<int, 2> parse_line(string line)
{
    array<int, 2> move_info;
    move_info[0] = get_direction(line.at(0));
    
    if (line.size() == 3) move_info[1] = stoi(line.substr(2, 1));  
    else move_info[1] = stoi(line.substr(2,2));

    return move_info; 
}

int get_direction(char dir)
{
    if (dir == 'U') return 0;
    else if (dir == 'R') return 1;
    else if (dir == 'D') return 2;
    else if (dir == 'L') return 3;
    else throw "bad direction";
}


int main() 
{
    vector<string> input = get_input();
    CreateRope *rope = new CreateRope();
    for (int i = 0; i < input.size(); ++i)
    {
        array<int, 2> move_info = parse_line(input[i]);
        rope->head->move(move_info);
    }

    cout << rope->tail->get_places_count() << endl; 

    // delete the CreateRope object
    delete rope;   
}