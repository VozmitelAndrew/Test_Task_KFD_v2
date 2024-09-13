#include "Utils.h"

std::string ShowDouble::format(const Currency& currency) {
    std::ostringstream oss;
    if (currency.name == "BTC") {
        oss << currency.amount;
    } else {
        if (std::floor(currency.amount) == currency.amount) {
            oss << std::fixed << std::setprecision(0) << currency.amount;
        } else {
            oss << std::fixed << std::setprecision(2) << currency.amount;
        }
    }
    return oss.str();
}

// Function implementation
bool isNumber(const std::string& s) {
    bool decimal_point_found = false;
    for (char const& ch : s) {
        if (ch == '.') {
            if (decimal_point_found) return false;
            decimal_point_found = true;
        } else if (!std::isdigit(ch)) {
            return false;
        }
    }
    return true;
}
