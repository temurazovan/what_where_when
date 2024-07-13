#include <iostream>
#include <fstream>
#include <vector>

int main() {
    int offset = 1;
    int input;
    std::ifstream fileQ;
    std::ifstream fileA;
    std::string question;
    std::string answer;
    std::string expersAnswer;
    fileQ.open("../questions.txt");
    fileA.open("../answers.txt");

    std::vector<int> played;
    int expertPoints = 0;
    int viewerPoints = 0;

    while (expertPoints != 13 || viewerPoints != 13) {
        std::cout << "Choose sector:" << std::endl;
        std::cin >> input;
        while (offset < 1 || offset > 13) {
            std::cout << "Error input. Try again." << std::endl;
            std::cin >> offset;
        }

        offset += input;

        if (offset > 13) {
            offset -= 13;
        }

        for (int i = 0; i < offset; i++) {
            getline(fileQ, question);
            getline(fileA, answer);
        }
        std::cout << question << std::endl;

        std::cout << "Please enter your answer in one word";
        std::cin >> expersAnswer;
        if (expersAnswer == answer) {
            expertPoints++;
        } else {
            viewerPoints++;
        }
    }
    fileQ.close();
    fileQ.close();

    return 0;
}
