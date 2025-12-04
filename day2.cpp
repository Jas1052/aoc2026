#include <cstddef>
#include <iostream>
#include <fstream> // For ifstream
#include <string>  // For std::string and getline
#include <vector>  // For std::vector

std::vector<std::string> splitString(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t lastPos = 0;
    size_t nextPos = 0;

    while ((nextPos = str.find(delimiter, lastPos)) != std::string::npos) {
        tokens.push_back(str.substr(lastPos, nextPos - lastPos));
        lastPos = nextPos + delimiter.length();
    }
    // Add the last token
    tokens.push_back(str.substr(lastPos));
    return tokens;
}

long long part1(std::vector<std::string> input) {
    long long sum = 0;
    std::vector<std::string> ranges = splitString(input[0], ",");
    for(std::string range : ranges) {
        // std::cout << "range: " << range << "\n";
        std::vector<std::string> item = splitString(range, "-");
        long long front = std::stoll(item[0]);
        long long back = std::stoll(item[1]);
        for(long long i = front; i <= back; i++) {
            // std::cout << "num: " << i << "\n";
            std::string numString = std::to_string(i);
            if(numString.size() % 2 == 0 && numString.substr(0, numString.size()/2) == numString.substr(numString.size() / 2, numString.size())) {
                sum += i;
            }
        }
    }
    return sum;
}

bool isRepeat(std::string num) {
    // std::cout << "num: " << num << "\n";
    for(size_t i = 1; i < num.length() / 2 + 1; i++) {
        if(num.length() % i == 0) {
            size_t repeats = num.length() / i;
            std::string pattern = num.substr(0, i);
            std::string check;
            for(size_t j = 0; j < repeats; j++) {
                check.append(pattern);
            }
            // std::cout << "pattern: " << pattern << " : " << check << "\n" ;
            if(check == num) {
                // std::cout << "added: " << num << "\n";
                return true;
            }
        }
    }
    return false;
}

long long part2(std::vector<std::string> input) {
    long long sum = 0;
    std::vector<std::string> ranges = splitString(input[0], ",");
    for(std::string range : ranges) {
        std::cout << "range: " << range << "\n";
        std::vector<std::string> item = splitString(range, "-");
        long long front = std::stoll(item[0]);
        long long back = std::stoll(item[1]);
        for(long long i = front; i <= back; i++) {
            std::string numString = std::to_string(i);
            if(isRepeat(numString)) {
                sum += i;
            }
        }
    }
    return sum;
}

// int part2(const std::string& input) {
//     return 0;
// }

int main() {
    std::ifstream inputFile("day2_input.txt");
    std::vector<std::string> input;
    std::string line;
    while(std::getline(inputFile, line)) {
        input.push_back(line);
    }
    std::cout << "total: " << part2(input) << "\n";
    return 0;
}


