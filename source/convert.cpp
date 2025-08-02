// convert.cpp
#include "convert.h"

#include <iomanip>
#include <sstream>

std::string formatWithCommas(double value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << value;
    std::string str = oss.str();

    size_t dot_pos = str.find('.');
    std::string int_part = str.substr(0, dot_pos);
    std::string frac_part = str.substr(dot_pos);

    std::string result;
    int count = 0;
    for (int i = static_cast<int>(int_part.size()) - 1; i >= 0; --i) {
        result.insert(result.begin(), int_part[i]);
        ++count;
        if (count % 3 == 0 && i != 0) {
            result.insert(result.begin(), ',');
        }
    }

    return result + frac_part;
}
