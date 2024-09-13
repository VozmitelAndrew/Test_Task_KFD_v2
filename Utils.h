#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>

#define coutline std::cout<< "---------------------------------------------------------\n"

// Struct definitions
struct Currency {
    std::string name;
    double amount;
};

struct ExchangeStruct {
    std::string first, second;
    double exchange_rate;
};

struct INITIAL {
    std::vector<Currency> initial_balance_new_user;
    std::vector<Currency> initial_balance_ATM;
    std::vector<ExchangeStruct> initial_exchange_rates;
};

class ShowDouble {
public:
    static std::string format(const Currency& currency);
};


bool isNumber(const std::string& s);