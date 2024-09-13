#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>

#include "UserDatabase.h"
#include "Utils.h"

class CurrencyExchangeTerminal {
public:
    CurrencyExchangeTerminal(const INITIAL& data);
    void processUserInput();

private:
    UserDatabase user_database;
    std::string current_user;
    std::vector<Currency> money_to_new_user;
    std::vector<Currency> terminal_balance;
    std::vector<ExchangeStruct> exchange_rates;

    void loginUser();
    void updateAllExchangeRates();
    const std::vector<ExchangeStruct>& displayExchangeRates() const;
    double terminalBalanceCurrency(const std::string& currency_name, double amount_difference = 0);
    double findRate(const std::string& from_currency, const std::string& to_currency);
    double performExchange(const std::string& from_currency, const std::string& to_currency, double amount);
};