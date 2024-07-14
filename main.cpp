#include <iostream>
#include <fstream>
#include <vector>

std::string readXLine(std::ifstream &file, int numberLine) {
    file.seekg(0, std::ifstream::beg);
    std::string buffer;
    for (int i = 0; i < numberLine; i++) {
        getline(file, buffer);
    }

    return buffer;
}

int main() {
    int offset = 1;
    int input;
    std::ifstream fileQ;
    std::ifstream fileA;
    std::string question;
    std::string answer;
    std::string expersAnswer;


    std::vector<int> played;
    int expertPoints = 0;
    int viewerPoints = 0;
    fileQ.open("../questions.txt");
    fileA.open("../answers.txt");

    while (expertPoints != 13 || viewerPoints != 13) {

        std::cout << "Choose sector:" << std::endl;
        std::cin >> input;
        while (input < 1 || input > 13) {
            std::cout << "Error input. Try again." << std::endl;
            std::cin >> input;
        }
        if (expertPoints == 0 && viewerPoints == 0) {
            offset = 1;
        }
        offset += input;

        if (offset > 13) {
            offset -= 13;
        }
        question = readXLine(fileQ, offset);
        answer = readXLine(fileA, offset);

        std::cout << question << std::endl;
        std::cout << "we are here:  " << fileQ.tellg() << std::endl;


         std::cout << "Please enter your answer in one word" << std::endl;
         std::cin >> expersAnswer;
         if (expersAnswer == answer) {
             expertPoints++;
         } else {
             viewerPoints++;
         }
    }
    fileQ.close();
    fileA.close();

    return 0;
}
