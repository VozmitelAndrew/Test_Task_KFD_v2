#include "CurrencyExchangeTerminal.h"

INITIAL init_data = {
        { {"RUB", 1000000.0} }, //при регистрации пользователя
        { {"RUB", 10000.0}, {"USD", 1000.0}, {"EUR", 1000.0}, {"USDT", 1000.0}, {"BTC", 1.5} }, //купюры в машине
        { {"USD", "RUB", 91.1}, {"EUR", "RUB", 100.1}, {"USD", "EUR", 0.9}, {"USD", "USDT", 1.0}, {"BTC", "USD", 58000} } //курс
};

int main() {
    CurrencyExchangeTerminal terminal(init_data);
    terminal.processUserInput();
    return 0;
}
