#include "include/functions.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdint>

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

        //Sorting into alphabetical order.
        std::sort(name_vec.begin(), name_vec.end());

        return name_vec;
    }

    int64_t sum_of_letters_in(std::string name_str) {
        const std::string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int64_t result = 0;
        for (int i = 0; i < static_cast<int>(name_str.size()); i++) {
            result += static_cast<int>(str.find(name_str.substr(i, 1)) + 1);
        }
        return result;
    }

    int64_t total_of_all_name_scores_in(std::vector<std::string> names_vec) {
        int64_t sum_of_all_name_scores = 0;
        for (int i = 0; i < static_cast<int>(names_vec.size()); i++) {
            std::string single_name = names_vec[i];
            sum_of_all_name_scores += func::sum_of_letters_in(single_name) * (i + 1); //'(i + 1)' gives the place value instead of index.
        }
        return sum_of_all_name_scores;
    }
}