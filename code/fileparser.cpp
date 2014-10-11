/*  fileparser.cpp
    Implementation for the fileparser class.
*/

#include "fileparser.hpp"
#include <fstream>
#include <string>
// #include <regex>  // Available only in C++11

namespace slocounter{
    Fileparser::Fileparser(char *pfilename){
        filename = pfilename;
        sloc = 0;
        comments = 0;
        commentlines = 0;
    }

    void Fileparser::parsefile(){
        /* Parse the file

        Open the file with the name given in the constructor.
        Then parse it line by line and decide whether it is a line of code,
        a line in a block comment or a single line comment, and, if it is
        a line of code, whether it also contains a line comment.
        */
        std::ifstream file(filename);

        // Switch to tell us if we are in a block comment
        bool blockcomment = false;

        // String with our line
        std::string line;

        // Read in line by line
        while(std::getline(file, line)){
            bool foundcode = false;
            bool foundcomment = false;
            bool foundcommline = false;
            bool linecomment = false;

            // Go through the line character by character
            for(unsigned int i = 1; i < line.length() - 1; i++){
                if(line[i] == '/'){
                    if(line[i+1] == '*'){
                        // Found "/*"
                        blockcomment = true;
                        foundcomment = true;
                        i++;
                        continue;
                    }
                    else if(line[i+1] == '/'){
                        // Found "//"
                        linecomment = true;
                        foundcomment = true;
                        i++;
                        continue;
                    }
                    foundcode = true; /* This only works if you program nicely
                        i.e. don't put a '/' alone on a single line...*/
                } else if(line[i] == '*' && line[i+1] == '/'){
                    // Found "*/"
                    blockcomment = false;
                    i++;
                    continue;
                } else if(line[i] != ' '){
                    /* If we found something code-y
                     1. Find out if we are in a comment of sorts -> found
                        commline. Then find end of comment on same line or EOL
                     2. Else: found code! Then find out if a comment follows
                     3. Set i to the start of the comment
                    */
                    if(blockcomment || linecomment){
                        foundcommline = true;
                        // Find end of comment
                        if(line.find("*/", i) != std::string::npos){
                            blockcomment = false;
                            i = line.find("*/", i);
                            continue;
                        }
                        // Comment goes to EOL
                        else {
                            // Break out of line parsing to evaluate the bools
                            break;
                        }
                    } else {
                        // No comment, we found code!
                        foundcode = true;
                        // Now, find some comments that start later on
                        std::string::size_type blockpos = line.find("/*", i);
                        std::string::size_type linepos = line.find("//", i);
                        if(blockpos != std::string::npos){
                            i = blockpos;
                            continue;
                        } else if(linepos != std::string::npos){
                            i = linepos;
                            continue;
                        } else {
                            // Break out of line parsing to evaluate booleans
                            break;
                        }
                    }

                }
            }

            if(foundcode){
                sloc++;
            }
            if(foundcommline){
                commentlines++;
            }
            if(foundcomment){
                comments++;
            }
        }

        file.close();
    }

    int Fileparser::getSLOC(){
        return sloc;
    }

    int Fileparser::getComments(){
        return comments;
    }

    int Fileparser::getCommentLines(){
        return commentlines;
    }
}
