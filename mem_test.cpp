#include <iostream>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>


using namespace std;

int parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

int getValue(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int result = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            result = parseLine(line);
            break;
        }
    }
    fclose(file);
    return result;
}

void view(){
    struct sysinfo memInfo;
    sysinfo (&memInfo);
    long long totalPhysMem = memInfo.totalram;
    //Multiply in next statement to avoid int overflow on right hand side...
    totalPhysMem *= memInfo.mem_unit;
    long long physMemUsed = memInfo.totalram - memInfo.freeram;
    //Multiply in next statement to avoid int overflow on right hand side...
    physMemUsed *= memInfo.mem_unit;

    cout << "Total mem " << totalPhysMem << "\nUsed " << physMemUsed << endl;
}

int main(int argc, char** argv){
    // Generate_Random_Text_File("duc4.txt", 1024 * 1024 * 4);
    int x;
    auto y = 'ắ';
    auto yy = "ấốếứa";
    cout << y << " " << sizeof(y) << "\n";
    cout << yy << " " << sizeof(yy) << " " << "\n";
    // view();
    cout << "Ram used " << getValue() << endl;

    vector<string> vec, vec2, vec3, vec4;

    std::ifstream f;
    f.open(argv[1]);

    if(f){
        string s;
        long r_used = 0;
        while(getline(f, s)){
            r_used += s.size();
            vec.push_back(s); 
        }
        cout << "R used: " << r_used << " kb: " << r_used / 1024 << "\n";
    } else {
        cout << "Cannot open file!\n";
    }
    
    f.close();
    
    long ram_used = 0, r_used2 = 0;
    for(const auto& v : vec){
        ram_used += v.capacity();
        for(const auto& vv : v){
            r_used2 += sizeof(vv);
        }
    }
    ram_used /= 1024;
    r_used2 /= 1024;
    cout << "Ram used (kb) " << getValue() << " " << ram_used << " " << r_used2 << endl;
    vec4 = vec3 = vec2 = vec;
    cout << "Ram used " << getValue() << " " << ram_used * 4 << endl;
    return 0;
}
// 3653935104
// 3715690496