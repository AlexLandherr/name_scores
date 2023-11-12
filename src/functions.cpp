#include "include/functions.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

/*
Using 'names.txt' (renamed to 'p022_names.txt'), a 46K text file containing over five-thousand first names, begin by
sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical
position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th
name in the list. So, COLIN would obtain a score of 938 x 53 = 49714.

What is the total of all the name scores in the file?
*/

namespace func {
    std::vector<std::string> txt_file_to_vector(std::string file_path) {
        std::vector<std::string> name_vec;
        std::fstream triangle_file(file_path);
        std::string single_line;

        while (std::getline(triangle_file, single_line)) {
            //Variable to hold each extracted token from a single line of the text file.
            std::string token;

            //Constructing std::stringstream from single_line std::string.
            std::stringstream s_stream(single_line);

            /*Read the std::stringstream and split it when ',' char is encountered,
            then put the split-off string in token, remove irrelevant chars from token and put it in name_vec.*/
            while (getline(s_stream, token, ',')) {
                //Remove irrelevant chars from token.
                token.erase(std::remove(token.begin(), token.end(), '"'), token.cend());

                name_vec.push_back(token);
            }
        }

        return name_vec;
    }
}