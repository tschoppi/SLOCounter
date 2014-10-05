/* main.cpp
   2014 (c) Jan Tschopp
*/

#include <iostream>

int main(int argc, char* argv[]){
    if(argc == 1){
        std::cerr << "Error: Not enough arguments." << std::endl << std::endl;
        std::cerr << "Program usage:" << std::endl
            << argv[0] << " file_1.cpp file_2.hpp ... file33.cpp" << std::endl;
    }
    return 0;
}
