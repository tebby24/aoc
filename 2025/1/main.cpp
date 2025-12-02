#include <iostream>
#include <fstream>
#include <string>

int part_1(std::ifstream& fin) {
	int pos = 50;
	int rotation = 0;
	int zero_count = 0;
	std::string line = "";

	while(std::getline(fin, line)) {
		std::string dir = line.substr(0, 1);
		rotation = std::stoi(line.substr(1));
		dir == "R" ? pos += rotation : pos -= rotation;
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
		int rotation = std::stoi(line.substr(1));
		std::string dir = line.substr(0, 1);
		if (rotation >= 100) {
			// add all the passes I'm guaranteed from rotations of 100 or more
			zero_count += rotation / 100;
			rotation %= 100;
		}
		if (dir == "R") { // right rotation
			pos += rotation;
			if (pos > 99) {
				zero_count += 1;
				pos -= 100;
			}
		} else { // left rotation
			if (pos == 0) {
				pos += (100 - rotation);
			}
			else {
				pos -= rotation;
				if (pos == 0) {
					zero_count += 1;
				}
				else if (pos < 0)
				{
					zero_count += 1;
					pos += 100;
				}
			}

		}
	}
	return zero_count;
}


int main(int argc, char* argv[]) {
	std::ifstream fin_1("input.txt");
	int sol_1 = part_1(fin_1);
	std::cout << "part 1: " << sol_1 << std::endl;

	std::ifstream fin_2("input.txt");
	int sol_2 = part_2(fin_2);
	std::cout << "part 2: " << sol_2 << std::endl;

	return 0;
}
