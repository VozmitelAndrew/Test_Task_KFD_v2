#include "UserDatabase.h"

bool UserDatabase::userExists(const std::string& username) const {
    return users.find(username) != users.end();
}

void UserDatabase::createUser(const std::string& username, const std::vector<Currency>& init_user_amount) {
    users[username] = init_user_amount;
}

const std::vector<Currency>& UserDatabase::getUserBalance(const std::string& username) {
    return users[username];
}

double UserDatabase::userBalanceCurrency(const std::string& username, const std::string& currency_name){
    Currency* found = findUserCurrency(username, currency_name);
    if(found != nullptr){
        return found->amount;
    }
    return 0;
}

void UserDatabase::addToUserBalance(const std::string& username, const Currency& adder) {
    Currency* found = findUserCurrency(username, adder.name);
    if(found != nullptr){
        found->amount += adder.amount;
    }
    else{
        users[username].push_back(adder);
    }
}

Currency* UserDatabase::findUserCurrency(const std::string& username, const std::string& currency_name) {
    if (userExists(username)) {
        for (Currency& currency : users[username]) {
            if (currency.name == currency_name) {
                return &currency;
            }
        }
    }
    return nullptr;
}