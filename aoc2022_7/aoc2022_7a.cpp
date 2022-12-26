#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
int ind = 0;
int file_size;
int solution;

class node {
    public:
    string name;
    int size;
    node* parent_ptr;
    vector<node*> subdirs_ptrs;
    map<string, int> files;
    node(string name_given, node* parent_ptr_given = NULL) {
        this->name = name_given;
        this->parent_ptr = parent_ptr_given;
    }
};

node* root;
node* current_node;
vector<node*> leaves;

vector<string> get_input() {
    ifstream file("/home/granfelino/own/aoc2022/aoc2022_7/input.txt");
    string line;
    vector<string> input;

    while(getline(file, line)) {
        input.push_back(line);
        ++file_size;
    }
    return input;
}


void parse_ls(vector<string> input) {
    string line = input[ind];
    while(line.substr(0, 1) != "$") {
        if(line.substr(0,1) == "d") {
            string dir_name = line.substr(4, line.size()); 
            node* child = new node(dir_name, current_node);
            current_node->subdirs_ptrs.push_back(child);
            cout << "Added directory: " << child->name << " to " << current_node->name << "\n";
        } else {
            int file_size = stoi(line.substr(0, line.find(' '))); 
            string file_name = line.substr(line.find(' ') + 1, line.size());
            current_node->files[file_name] = file_size;
            cout << "Added file: " << file_name << " to " << current_node->name << "\n";
        }
        ++ind;

        if(ind < file_size) {
            line = input[ind];
        } else {
            break;
        }
    }

}

void parse_cd(string line) {
    string dir_name = line.substr(5, line.size());
    if(dir_name.compare("..") != 0) {
        int subdirs_count = current_node->subdirs_ptrs.size();
        
        for(int i = 0; i < subdirs_count; i++) {
            node* subdir = current_node->subdirs_ptrs[i];
            string dir_name_temp = subdir->name;
            if(dir_name.compare(dir_name_temp) == 0) {
                current_node = subdir;
                cout << "Current directory: " << current_node->name << "\n";
                break;
            }
        }
    } else {
        current_node = current_node->parent_ptr;
        cout << "Changed directory to: " << current_node->name << "\n";
    }

    ++ind;
}

void parse_lines() {
    vector<string> input = get_input();
    string line;
    int size = input.size();

    while(ind < size) {
        line = input[ind];

        if(ind == 0) {
            root = new node("/");
            current_node = root;
            ++ind;
        } else if(line.at(0) == '$') {
            if(line.at(2) == 'c') {
                if(current_node->subdirs_ptrs.empty()) {
                    leaves.push_back(current_node);
                }

                parse_cd(input[ind]);
            } else if(line.at(2) == 'l') {
                ++ind;
                parse_ls(input);
            }
        }
    }
}

int get_size(node* dir) {
    int size_total = 0;
    map<string, int>::iterator it;
    for(it = dir->files.begin(); it != dir->files.end(); it++) {
        size_total += it->second;
    }

    if(!dir->subdirs_ptrs.empty()) {
        for(node* child : dir->subdirs_ptrs) {
            size_total += get_size(child);
        }
    }

    if(size_total <= 100000) {
        solution += size_total;
    }

    cout << "Total size of " << dir->name << " is " << size_total << "\n";
    return size_total;
}

int main() {
    parse_lines();
    cout << "\n\n\nCalculating the size...\n";
    get_size(root);
    cout << "The size of all directories at most of size 100 000 is: " << solution << "\n";
    return 0;
}