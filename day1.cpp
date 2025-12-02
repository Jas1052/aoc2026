#include <iostream>
#include <fstream> // For ifstream
#include <string>  // For std::string and getline
#include <vector>  // For std::vector
#include <cmath> // Or <cstdlib> for integer types


int part1(std::vector<std::string> input) {
    int total = 0;
    int dial = 50;
    for(std::string line: input) {
        int steps = std::stoi(line.substr(1));
        std::cout << "steps: " << steps << "\n";
        if(line[0] == 'L') {
            dial -= steps;
            if(dial < 0) {
                dial = 100 + (dial % 100);
            }
        }
        else if(line[0] == 'R') {
            dial += steps;
            if(dial > 99) {
                dial = (dial % 100);
            }
        }
        if(dial == 100) {
            dial = 0;
        }
        if (dial == 0) {
            total += 1;
        }
        std::cout << dial  << " : " << total << "\n";
    }
    return total;
}

int part2(std::vector<std::string> input) {
    int total = 0;
    int dial = 50;
    for(std::string line: input) {
        int steps = std::stoi(line.substr(1));
        std::cout << line << ": steps: " << steps << "\n";
        if(line[0] == 'L') {
            if(dial == 0) {
                total -= 1;
            }
            dial -= steps;
            if(dial <= 0) {
                total += 1;
                total += (std::abs(dial / 100));
            }
            if(dial < 0) {
                dial = 100 + (dial % 100);
            }

        }
        else if(line[0] == 'R') {
            dial += steps;
            if(dial > 99) {
                total += (std::abs(dial / 100));
                dial = (dial % 100);
            }
        }
        if(dial == 100) {
            dial = 0;
        }
        // if (dial == 0) {
        //     total += 1;
        // }
        std::cout << dial  << " : " << total << "\n";
    }
    return total;
}

// int part2(const std::string& input) {
//     return 0;
// }

int main() {
    std::ifstream inputFile("day1_input.txt");
    std::vector<std::string> input;
    std::string line;
    while(std::getline(inputFile, line)) {
        input.push_back(line);
    }
    std::cout << "total: " << part2(input) << "\n";
    return 0;
}


