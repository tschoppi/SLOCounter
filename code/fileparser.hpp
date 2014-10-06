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
    };
}

#endif // define FILEPARSER_HPP
