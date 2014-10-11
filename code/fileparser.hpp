/*  fileparser.hpp
    Used to parse a code file.
*/

#ifndef FILEPARSER_HPP
#define FILEPARSER_HPP


namespace slocounter{
    class Fileparser{
    private:
        char *filename;
        int sloc, comments, commentlines;

    public:
        Fileparser(char *pfilename);
        void parsefile();
        int getSLOC();
        int getComments();
        int getCommentLines();
    };
}

#endif // define FILEPARSER_HPP
