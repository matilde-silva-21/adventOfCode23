//
// Created by matilde on 06-12-2023.
//
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> getInput(std::string inputPath){
    std::ifstream myfile;
    myfile.open(inputPath);

    std::vector<std::string> result;
    std::string line = "";

    if ( myfile.is_open() ) {
        while (myfile) {
            myfile >> line;
            if(myfile) result.push_back(line);
        }
    }
    myfile.close();

    return result;
}

int countString(std::string word){
    int firstDigit = 0, lastDigit = 0;

    for(char i : word){
        int n;
        try {
            std::string strChar(1, i);
            n = std::stoi(strChar);
        }
        catch(...){
            continue;
        }
        firstDigit = n;
        break;
    }

    std::reverse(word.begin(), word.end());

    for(char i : word){
        int n;
        try {
            std::string strChar(1, i);
            n = std::stoi(strChar);
        }
        catch(...){
            continue;
        }
        lastDigit = n;
        break;
    }

    return firstDigit*10 + lastDigit;
}


int day1_first() {
    std::vector<std::string> strings = getInput("./input/day1_first.txt");

    int total = 0;

    for (const std::string& i: strings){
        total += countString(i);
    }

    return total;
}

void convertTextDigitToIntDigit(std::string &word) {
    std::vector<std::string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::vector<std::string> numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for(int i=0; i < digits.size(); i++){
        std::string digit = digits[i];
        size_t pos = word.find(digit);
        while (pos != std::string::npos){
            word.insert(pos+1, numbers[i]);
            pos = word.find(digit);
        }
    }
}

int day1_second(){
    std::vector<std::string> strings = getInput("./input/day1_first.txt");
    int total = 0;

    for (const std::string& i: strings){
        convertTextDigitToIntDigit((std::string &) i);
        total += countString(i);
    }

    return total;
}