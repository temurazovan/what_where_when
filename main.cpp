#include <iostream>
#include <fstream>
#include <vector>

int main() {
    int offset = 1;
    int input;
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


    }

    return 0;
}
