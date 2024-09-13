#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "Utils.h"

class UserDatabase {
public:
    bool userExists(const std::string& username) const;
    void createUser(const std::string& username, const std::vector<Currency>& init_user_amount);
    const std::vector<Currency>& getUserBalance(const std::string& username);
    double userBalanceCurrency(const std::string& username, const std::string& currency_name);
    void addToUserBalance(const std::string& username, const Currency& adder);

private:
    std::unordered_map<std::string, std::vector<Currency>> users;
    Currency* findUserCurrency(const std::string& username, const std::string& currency_name);
};