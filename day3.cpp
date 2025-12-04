#include <algorithm>
#include <cstddef>
#include <iostream>
#include <fstream> // For ifstream
#include <string>  // For std::string and getline
#include <vector>  // For std::vector

using namespace std;

int part1(std::vector<std::string> input) {
    int sum = 0;
    for(std::string row : input) {
        int tens = 0;
        int ones = 0;
        for(size_t i = 0; i < row.length(); i++) {
            int joltage = row[i] - '0';
            // std::cout << joltage << std::endl;
            if(joltage > tens && i <= row.length() - 2) {
                tens = joltage;
                ones = row[i + 1] - '0';
            } else if (joltage > ones) {
                ones = joltage;
            }
            std::cout << "digits: " << tens << " : " << ones << std::endl;
        }
        int val = (tens * 10) + ones;
        std::cout << "val: " << val << std::endl;
        sum += val;
    }
    return sum;
}


long long part2(std::vector<std::string> input) {
    long long sum = 0;
    for(std::string row : input) {
        cout << "row: " << row << endl;
        int digits[] = {0, 0, 0, 0, 0, 0 , 0, 0,0,0,0, 0};
        for(size_t i = 0; i < row.length(); i++) {
            int joltage = row[i] - '0';
            for(size_t j = 0; j < 12; j++) {
                if(i + j >= row.length()) {
                    continue;
                }
                int currentDigit = digits[j];

                if(row[i + j] - '0' > currentDigit && ((long long) row.length() - (long long) i - (long long) j - (12 - (long long) j) >= 0)) {
                    for(size_t replaceIndex = j; replaceIndex < 12; replaceIndex++) {
                        digits[replaceIndex] = row[i + replaceIndex] - '0';
                    }
                    continue;
                } 
            }

        }
        long long val = 0;
        for(int i = 0; i <= 11; i++) {
            val += (digits[i] * pow( 10, 11 - i));
        }
        // std::cout << "val: " << val << std::endl;
        sum += val;
    }
    return sum;
}

// int part2(const std::string& input) {
//     return 0;
// }

int main() {
    std::ifstream inputFile("day3_input.txt");
    std::vector<std::string> input;
    std::string line;
    while(std::getline(inputFile, line)) {
        input.push_back(line);
    }
    std::cout << "total: " << part2(input) << "\n";
    return 0;
}


