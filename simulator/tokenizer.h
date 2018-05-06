#include <vector>
#include <sstream>
#include <iterator>

std::vector<std::string> tokens_in_vector(string args){
    std::stringstream ss(args);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end(ss);
    std::vector<std::string> vstrings(begin, end);
    return vstrings;
    }