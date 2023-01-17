// tail override move
// make head rope child class and override move 
// correct rest of the program

#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <fstream>
#include <assert.h>

using namespace std;


class Rope {
  public:
  Rope *next_ptr, *prev_ptr;
  Head *head_ptr;
  array<int, 2> position;

  Rope() {
    this->position = {0, 0};
    this->prev_ptr = nullptr;
    this->next_ptr = nullptr;
  }

  void move();
  array<int,2> get_offset();
};


// needs overriding the move function to be able to call add_place and get_places_count
class Tail : public Rope {
  public:
  set<array<int, 2>> tail_places;

  void add_place(array<int,2> place) {
    this->tail_places.insert(place);
  } 

  int get_places_count() {
    return this->tail_places.size();
  }
};


// make it Rope child class and overload the move method to suit Head's needs
class Head {
  public:

  Rope *next_ptr, *prev_ptr;
  array<int, 2> position;
  vector<Rope*>* rest_of_rope;

  Head(vector<Rope*>* rest) {
    this->rest_of_rope = rest;
    this->position = {0, 0};
    this->prev_ptr = nullptr;
    this->next_ptr = rest_of_rope->at(0);
    this->next_ptr->head_ptr = this;
  }

  void move_head(array<int, 2> move) {
    for(int i = 0; i < move[1]; ++i) {
      if (move[0] == 0) {
        // up
        ++this->position[1];
        this->next_ptr->move();

      } else if (move[0] == 1) {
        // right
        ++this->position[0];
        this->next_ptr->move();

      } else if (move[0] == 2) {
        // down
        --this->position[1];
        this->next_ptr->move();

      } else if (move[0] == 3) {
        // left
        --this->position[0];
        this->next_ptr->move();

      }
    }
  }

};


void Rope::move() {
  array<int, 2> offset = Rope::get_offset();

  if(abs(offset[0]) <= 1 && abs(offset[1]) <= 1) {
    // no movement
    return;

  } else if(offset[0] == 0 xor offset[1] == 0) {
    // horizontal/vertical movement

    if(offset[0] == 0) {
      // vertical

      if(offset[1] > 0) ++this->position[1]; // up
      else --this->position[0]; // down
    
    } else {
      // horizontal
      
      if(offset[0] > 0) ++this->position[0]; // right
      else --this->position[0]; // left
    
    }
  } else {
    // assert that offset is between (-2 and -1) and (1, 2) on both axes

    assert(abs(offset[0] >= 1));
    assert(abs(offset[0] <= 2));

    assert(abs(offset[1] >= 1));
    assert(abs(offset[1] <= 2));


    // left upper
    if(offset[0] < 0 && offset[1] > 0) {
      --this->position[0]; 
      ++this->position[1];
    } 
    
    // right upper
    else if(offset[0] > 0 && offset[1] > 0) {
      ++this->position[0];
      ++this->position[1];
    }

    // right lower
    else if (offset[0] > 0 && offset[1] < 0) {
      ++this->position[0];
      --this->position[1];
    }

    // left lower
    else if (offset[0] < 0 && offset[1] < 0) {
      --this->position[0];
      --this->position[1];
    }
     
  }
  

  // call the move method on the next rope piece if it is not the tail of the rope
  if (this->next_ptr != nullptr) this->next_ptr->move();
  else 
}


array<int, 2> Rope::get_offset() {
  array<int,2> offset = {};
  offset[0] = this->prev_ptr->position[0] - this->position[0];
  offset[1] = this->prev_ptr->position[1] - this->position[1];
  assert(abs(offset[0]) <= 2);
  assert(abs(offset[1]) <= 2);
  
  return offset;
}


// remainder for self to write the deletion function!!!
vector<Rope*>* create_rope() {
  vector<Rope*> rope;
  
  for (int i = 0; i < 9; ++i) {
    if (i != 8) rope.push_back(new Rope);
    else if (i == 8) rope.push_back(new Tail);
  }

  for (int i = 0; i < 9; ++i) {
    
    if(i == 0) {
      rope[0]->next_ptr = rope[1];
      continue;

    } else if (i == 8) {
      rope[9]->prev_ptr = rope[7];
      continue;

    }

    rope[i]->prev_ptr = rope[i - 1];
    rope[i]->next_ptr = rope[i + 1];
  }

  return &rope;
}


// needs testing if working properly
void delete_rope_piece(Rope* rope_piece) {
  if(rope_piece->next_ptr == nullptr) {
    delete rope_piece;
    return;

  } else {
    delete_rope_piece(rope_piece->next_ptr);
    delete rope_piece;
    return;

  }
}

vector<string> get_input() {
  vector<string> input;
  ifstream file("input.txt");
  string line;

  while(getline(file, line)) {
    if (line != "") input.push_back(line);
  }

  return input;
}

enum direction {
  up,
  right,
  down,
  left
};

array<int, 2> get_move(string line) {
  array<int, 2> move = {};
  direction dir;

  // get direction
  if(line.at(0) == 'U') dir = direction::up;
  else if(line.at(0) == 'R') dir = direction::right;
  else if(line.at(0) == 'D') dir = direction::down;
  else if(line.at(0) == 'L') dir = direction::left;
  
  // set direction in the move array
  assert(dir == 0 || dir == 1 || dir == 2 || dir == 3);
  move[0] = dir;
  assert(move[0] != NULL);


  // get number of steps based on line length
  if(line.size() == 3) move[1] = stoi(line.substr(2, 1));
  else move[1] = stoi(line.substr(2, 2));
  assert(move[1] != NULL);
  

  return move;
}


vector<Rope*>* move_rope() {
  vector<string> input = get_input(); // get moves vector
  vector<Rope*>* rope = create_rope(); // create the body of the rope with the tail
  Head *head = new Head(rope); // create the head of the rope and attach the body to it

  for(int i = 0; i < input.size(); ++i) {
    array<int, 2> move = get_move(input[i]);
    head->move_head(move);

  }

  return rope;
}


void get_tail_places_count(vector<Rope*>* rope) {

}