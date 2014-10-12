/* main.cpp
   2014 (c) Jan Tschopp
*/

#include <iostream>
#include <iomanip>
#include "fileparser.hpp"

int main(int argc, char* argv[]){
    if(argc == 1){
        std::cerr << "Error: Not enough arguments." << std::endl << std::endl;
        std::cout << "Program usage:" << std::endl
            << argv[0] << " file_1.cpp file_2.hpp ... file33.cpp"
            << std::endl << std::endl;
        std::cout << "Program output:" << std::endl
            << "SLOC Commentcount Commentlines Filename" << std::endl;
        return 1;
    }

    int totcomm = 0, totcode = 0, totcomlines = 0;

    for(int i = 1; i < argc; i++){
        // Construct the parser
        slocounter::Fileparser parser(argv[i]);
        try {
            parser.parsefile();
        }
        catch (int code) {
            // Do nothing, cerr output is already given
        }

        // Nice display
        std::cout << std::setw(5) << parser.getSLOC() << " "
            << std::setw(3) << parser.getComments() << " "
            << std::setw(3) << parser.getCommentLines() << "   "
            << argv[i] << std::endl;

        // Tally it up
        totcomm += parser.getComments();
        totcode += parser.getSLOC();
        totcomlines += parser.getCommentLines();
    }

    // Print totals
    std::cout << std::endl;
    std::cout << std::setw(5) << totcode << " "
        << std::setw(3) << totcomm << " "
        << std::setw(3) << totcomlines << "   Total" << std::endl;

    return 0;
}
