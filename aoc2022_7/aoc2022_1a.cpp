#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> sum_all(string path) {
    ifstream file(path);
    string line;
    vector<int> summed;

    int temp_sum;
    while(getline(file, line)) {
        if(line == "") {
            summed.push_back(temp_sum);
            temp_sum = 0;
            continue;
        }
        temp_sum += stoi(line);
    }
    
    file.close();
    return summed;
}

int get_max(vector<int> sol) {
    int max;
    int current;
    for(int i = 0; i < sol.size(); i++) {
        current = sol[i];
        if(current > max) {
            max = current;
        }
    }
    
    return max;
}

int main() {
    vector<int> sol = sum_all("/home/granfelino/own/aoc2022/aoc2022_1/input.txt");
    cout << get_max(sol) << "\n";
    return 0;
}