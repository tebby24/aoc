#include <iostream>
#include <fstream>
#include <string>

int part_1(std::ifstream& fin) {
	int pos = 50;
	int rotation = 0;
	int zero_count = 0;
	std::string line = "";

	while(std::getline(fin, line)) {
		rotation = std::stoi(line.substr(1));
		if (line.substr(0, 1) == "R") {
			// right rotation
			pos += rotation;
		}
		else {
			// left rotation
			pos -= rotation;
		}

		if (pos % 100 == 0) {
			zero_count++;
		}
	}
	return zero_count;
}

int part_2(std::ifstream& fin) {
	int pos = 50;
	int rotation = 0;
	int zero_count = 0;
	std::string line = "";

	while(std::getline(fin, line)) {
		if (line.substr(0, 1) == "R") {
			// right rotation
		} else {
			// left rotation
		}

	}
}



int main(int argc, char* argv[]) {
	std::ifstream fin("input.txt");

	std::cout << "part 1: " << part_1(fin) << std::endl;

	return 0;
}
