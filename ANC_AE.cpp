/*

Mihnea Maldaianu 2289803M

*/
#include <iostream>
#include <fstream>
#include <string>


using string = std::string;

int main()
{
    string line;
    std::ifstream inputFile("inputNodes.txt");
    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    }
    else std::cout << "Unable to open input file";
}
