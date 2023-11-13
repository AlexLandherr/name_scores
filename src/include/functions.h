#include <string>
#include <vector>
#include <cstdint>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    std::vector<std::string> txt_file_to_vector(std::string file_path);
    int64_t sum_of_letters_in(std::string name_str);
    int64_t total_of_all_name_scores_in(std::vector<std::string> names_vec);
}

#endif