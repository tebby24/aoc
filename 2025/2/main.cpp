#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

int invalid_ids(long long start, long long end) {
    
}


int main(int argc, char* argv[]) {    
    std::ifstream fin("test.txt");

    std::string line;
    std::getline(fin, line);

    std::stringstream ss(line);
    std::string token;

    while(std::getline(ss, token, ',')){
        auto pos = token.find('-');
        long long start = std::stoll(token.substr(0, pos));
        long long end = std::stoll(token.substr(pos+1));


    }


    return 0;
}