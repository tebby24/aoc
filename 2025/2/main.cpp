#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>


std::string repeat_string(std::string& str, int n) {
    std::string res = "";
    for (int i = 0; i < n; i++) {
        res += str;
    }
    return res;
}

std::vector<long long> find_invalid_ids(long long start, long long end, int repeat_count) {
    std::vector<long long> ids = {};
    std::string start_str = std::to_string(start);
    std::string sub;
    int repeat_length;
    
    if (start_str.length() == 1) {
        repeat_count = 2;
        sub = "1";
    }
    else {
        if (repeat_count > start_str.length()) {
            sub = "1";
        }
        else {
            repeat_length = start_str.length() / repeat_count;
            sub = start_str.substr(0, repeat_length);
        }
    }

    while (std::stoll(repeat_string(sub, repeat_count)) < start) {
        sub = std::to_string(std::stoll(sub) + 1);
    }

    while (std::stoll(repeat_string(sub, repeat_count)) <= end) {
        ids.push_back(std::stoll(repeat_string(sub, repeat_count)));
        sub = std::to_string(std::stoll(sub) + 1);
    }
    
    return ids;
}


int main(int argc, char* argv[]) {    
    if (argc != 2) {
        std::cerr << "useage: " << argv[0] << " <filepath>" << std::endl;
        return EXIT_FAILURE;
    }    

    std::string filepath = argv[1];
    std::ifstream fin(filepath);

    std::string line;
    std::getline(fin, line);

    std::stringstream ss(line);
    std::string token;

    std::set<long long> silver_ids = {};
    std::set<long long> gold_ids = {};
    while(std::getline(ss, token, ',')){
        auto pos = token.find('-');
        long long start = std::stoll(token.substr(0, pos));
        long long end = std::stoll(token.substr(pos+1));

        int start_digits = std::to_string(start).length();
        int end_digits = std::to_string(end).length();
        for (int i = 2; i <= end_digits; i++) {
            for (long long& id : find_invalid_ids(start, end, i)) {
                if (i == 2) {
                    silver_ids.insert(id);
                }
                gold_ids.insert(id);
            }
        }
    }

    long long silver_sum = 0;
    for (long long id : silver_ids) {
        silver_sum += id;
    }
    long long gold_sum = 0;
    for (long long id : gold_ids) {
        gold_sum += id;
    }

    std::cout << "silver ids: " << silver_sum << std::endl;
    std::cout << "gold ids: " << gold_sum << std::endl;


    return 0;
}