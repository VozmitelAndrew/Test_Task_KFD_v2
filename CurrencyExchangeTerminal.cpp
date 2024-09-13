#include "CurrencyExchangeTerminal.h"


CurrencyExchangeTerminal::CurrencyExchangeTerminal(const INITIAL& data) {
    money_to_new_user = data.initial_balance_new_user;
    terminal_balance = data.initial_balance_ATM;
    exchange_rates = data.initial_exchange_rates;
}

void CurrencyExchangeTerminal::loginUser() {
    std::cout << "Enter your username: ";
    std::cin >> current_user;

    if (user_database.userExists(current_user)) {
        std::cout << "Welcome back, " << current_user << "!\n";
    } else {
        std::cout << "New user created: " << current_user << "\n";

        user_database.createUser(current_user, money_to_new_user);
    }
}

void CurrencyExchangeTerminal::processUserInput() {
    loginUser();
    coutline;
    std::cout << "Available commands: 'exchange', 'balance', 'exit', 'rates'.\n";

    std::string command;
    while (true) {
        std::cout << "Enter command: ";
        std::cin >> command;
        coutline;
        if (command == "exit") {
            std::cout << "Thank you for using the terminal! Goodbye.\n";
            break;
        } else if (command == "balance") {
            std::cout << "You have: \n";
            for (const Currency& iter : user_database.getUserBalance(current_user)) {
                std::cout << ShowDouble::format({iter.name, iter.amount}) + " " + iter.name + "\n";
            }
        } else if (command == "exchange") {
            std::string from_currency, to_currency, string_amount;
            double amount;
            std::cout << "Enter the currency you want to exchange: ";
            std::cin >> from_currency;
            std::cout << "Enter the amount you want to exchange to: ";

            std::cin >> string_amount;
            if (!isNumber(string_amount)) {
                std::cout << "Error: Amount is not a valid number. Please try again.\n";
                coutline;
                continue;
            }

            amount = std::stod(string_amount);
            std::cout << "Enter the currency you want to receive: ";
            std::cin >> to_currency;
            try {
                double result = performExchange(from_currency, to_currency, amount);
                std::cout << "Exchange successful: -" + ShowDouble::format({from_currency, amount}) + " " + from_currency +
                             + "     +" + ShowDouble::format({to_currency, result}) + " " + to_currency + "\n";
            }
            catch (std::string& error_msg) {
                std::cout << "Error: " + error_msg + "\n";
                //break;
            }
        } else if(command == "rates"){
            for(const auto& i : this->displayExchangeRates()){
                std::cout << i.first + " to " + i.second +" = " + std::to_string(i.exchange_rate) +   "\n";
            }
        } else {
            std::cout << "Error: Unknown command. Please try again.\n";
            std::cout << "Available commands: 'exchange', 'balance', 'exit'.\n";
        }



        coutline;
    }
}

void CurrencyExchangeTerminal::updateAllExchangeRates() {
    for (ExchangeStruct& rate : exchange_rates) {
        rate.exchange_rate *= (1.0 + (rand() % 1001 - 500) / 10000.0);
        rate.exchange_rate = std::round(rate.exchange_rate * 1000.0) / 1000.0;
    }
}

double CurrencyExchangeTerminal::terminalBalanceCurrency(const std::string& currency_name, double amount_difference) {
    for (Currency& iter : terminal_balance) {
        if (iter.name == currency_name) {
            if (amount_difference != 0) {
                iter.amount += amount_difference;
            }
            return iter.amount;
        }
    }
    return 0;
}

double CurrencyExchangeTerminal::findRate(const std::string& from_currency, const std::string& to_currency) {
    for (ExchangeStruct& iter : exchange_rates) {
        if (iter.first == from_currency && iter.second == to_currency) {
            return iter.exchange_rate;
        } else if (iter.first == to_currency && iter.second == from_currency) {
            return 1 / iter.exchange_rate;
        }
    }
    return -1;
}

double CurrencyExchangeTerminal::performExchange(const std::string& from_currency, const std::string& to_currency, double amount) {
    double rate = findRate(from_currency, to_currency);
    if (rate == -1) {
        throw std::string{"Invalid currency pair"};
    }

    if (user_database.userBalanceCurrency(current_user, from_currency) < amount) {
        throw std::string{"Insufficient funds for this operation"};
    }

    double to_amount = amount * rate;
    if (terminalBalanceCurrency(to_currency) < to_amount) {
        throw std::string{"Terminal does not have enough funds for this operation"};
    }

    user_database.addToUserBalance(current_user, Currency{from_currency, -amount});
    terminalBalanceCurrency(from_currency, +amount);

    user_database.addToUserBalance(current_user, Currency{to_currency, to_amount});
    terminalBalanceCurrency(to_currency, -to_amount);

    updateAllExchangeRates();
    return to_amount;
}

const std::vector<ExchangeStruct>&CurrencyExchangeTerminal::displayExchangeRates() const {
    return this->exchange_rates;
}
