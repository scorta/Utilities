#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <string>

using namespace std;

string full_chars{"ĂÂĐÊÔƠƯaăâbcdđeêghiklmnoôơpqrstuưvxyáảàãắẳằẵấẩẩẫứừửữếềểễúùủũýỹỳỷ"};

char random_char(){
    return full_chars[rand() % full_chars.size()];
}

int main(int argc, char** argv){
    long long mem_limit = 104'857'600;
    long l = stol(argv[1]);
    long line_len = stol(argv[2]);
    bool use_unicode = argv[4] == "y" ? true : false;
    int ascii_range = 206;

    ofstream of{argv[3]};

    if(of){
        srand(time(0));
        string s{""};
        while(l-->0){
            int len = line_len;
            len += rand() % line_len;
            
            while(len-->0){
                char c = '0' + rand() % ascii_range;
                if (c == '0' + 79){
                    c = '0' + 80;
                }
                s.push_back(c);
                if(use_unicode){
                    s.push_back(random_char());
                }
            }
            s.push_back('\n');
            // s.shrink_to_fit();
            if(s.capacity() >= mem_limit){
                of << s;
                s = "";
            }
        }
        of << s;
        of.close();
        cout << "Done writing file!\n";
    } else {
        cout << "Error open file\n";
    }
    return 0;
}