/*  fileparser.cpp
    Implementation for the fileparser class.
*/

#include "fileparser.hpp"
#include <fstream>

namespace slocounter{
    Fileparser::Fileparser(char *pfilename){
        filename = pfilename;
        sloc = 0;
        comments = 0;
        commentlines = 0;
    }

    void Fileparser::parsefile(){
        std::ifstream file(filename);

        file.close();
    }
}
