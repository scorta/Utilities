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
using std::endl;
// using std::thread;

template <typename T>
void display(const vector<T>& v){
    cout << "ouput:\n";
    for(const auto& vv : v){
        cout << vv << endl;
    }   
    cout << "--- Output end ---\n";
}

int main(int argc, char** argv){
    cout << "sort!\n";
    vector<string> vec, vec2, vec3, vec4;

    std::ifstream f;
    f.open(argv[1]);

    if(f){
        string s;
        while(getline(f, s)){
            vec.push_back(s); 
        }
    } else {
        cout << "Cannot open file!\n";
    }
    
    f.close();

    vec4 = vec3 = vec2 = vec;

    // display(vec);
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(vec.begin(), vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto time_to_run = end - start;
    cout << "Time to run " << time_to_run.count() << endl;

    if(vec != vec2){
        cout << "Sequential\n";
        int x;
        cin >> x;
    }

    start = std::chrono::high_resolution_clock::now();
    __gnu_parallel::sort(vec2.begin(), vec2.end());
    end = std::chrono::high_resolution_clock::now();
    time_to_run = end - start;
    cout << "Time to run " << time_to_run.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    __gnu_parallel::sort(vec3.begin(), vec3.end(), __gnu_parallel::multiway_mergesort_tag());
    end = std::chrono::high_resolution_clock::now();
    time_to_run = end - start;
    cout << "Time to run " << time_to_run.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    __gnu_parallel::sort(vec4.begin(), vec4.end(), __gnu_parallel::balanced_quicksort_tag());
    end = std::chrono::high_resolution_clock::now();
    time_to_run = end - start;
    cout << "Time to run " << time_to_run.count() << endl;

    if(vec == vec2 && vec == vec3 && vec == vec4){
        cout << "Sorting done right!\n";
    }

    cout << "Good bye!\n";

    return 0;
}