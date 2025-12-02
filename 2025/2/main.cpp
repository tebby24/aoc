#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

long long sum_inval_ids(long long start, long long end) {
    long long sum = 0;

    std::string start_str = std::to_string(start);
    std::string half;

    if (start_str.length() == 1) { half = "1"; }
    else {
        int mid = start_str.length() / 2;
        half = start_str.substr(0, mid);
    }

    while (std::stoll(half+half) < start) {
        half = std::to_string(std::stoll(half)+1);
    }
    while (std::stoll(half+half) <= end) {
        sum += std::stoll(half+half);
        half = std::to_string(std::stoll(half)+1);
    }
    return sum;
}


int main(int argc, char* argv[]) {    
    std::ifstream fin("input.txt");

    std::string line;
    std::getline(fin, line);

    std::stringstream ss(line);
    std::string token;

    long long sum = 0;
    while(std::getline(ss, token, ',')){
        auto pos = token.find('-');
        long long start = std::stoll(token.substr(0, pos));
        long long end = std::stoll(token.substr(pos+1));

        sum += sum_inval_ids(start, end);
    }

    std::cout << "invalid id sum: " << sum << std::endl;

    return 0;
}