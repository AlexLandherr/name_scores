#include "include/functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdint>

/*
Using 'names.txt' (renamed to 'p022_names.txt'), a 46K text file containing over five-thousand first names, begin by
sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical
position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th
name in the list. So, COLIN would obtain a score of 938 x 53 = 49714.

What is the total of all the name scores in the file?
*/

int main() {
    std::vector<std::string> names = func::txt_file_to_vector("p022_names.txt");
    //std::cout << names[937] << '\n'; //The 938th name in the list.
    std::cout << "The total of all the name scores in the file is:" << '\n';
    std::cout << func::total_of_all_name_scores_in(names) << '\n';

    /* for (std::string str : names) {
        std::cout << str << '\n';
    } */
    /* std::sort(names.begin(), names.end());
    for (std::string str : names) {
        std::cout << str << '\n';
    }
    int64_t sum_of_all_name_scores = 0;
    for (int i = 0; i < static_cast<int>(names.size()); i++) {
        std::string single_name = names[i];
        sum_of_all_name_scores += func::sum_of_letters_in(single_name) * (i + 1); //'(i + 1)' gives the place value instead of index.
    }
    std::cout << "The total of all name scores in 'test_names.txt' is: " << sum_of_all_name_scores << '\n'; */

    /* auto name_index = std::distance(names.begin(), std::find(names.begin(), names.end(), "MARY"));
    int64_t name_score = func::sum_of_letters_in("MARY") * (name_index + 1);
    std::cout << "Name score of 'MARY': " << name_score << '\n';
    //std::cout << "Name index: " << name_index << '\n';
    std::cout << "Sum of letters in 'MARY': " << func::sum_of_letters_in("MARY") << '\n'; */

    return 0;
}