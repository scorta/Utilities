#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <string>
#include <parallel/algorithm>


using std::vector;
using std::string;
using std::cout;
using std::cin;

int main(int argc, char** argv){
    std::ifstream f;
    vector<string> vec;
    string infile_name = argv[1];
    long long max_size_of_memory = std::stoll(argv[2]); //try catch?
    f.open(infile_name);

    if(f){
        string s;
        while(getline(f, s)){
            s.shrink_to_fit(); // to save memory
            vec.push_back(s);
        }
    } else {
        cout << "Cannot open file!\n";
    }
    
    f.close();
    return 0;
}
