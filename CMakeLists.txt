cmake_minimum_required(VERSION 3.27)
project(BankMasterv2)

set(CMAKE_CXX_STANDARD 20)

add_executable(BankMasterv2 main.cpp
        CurrencyExchangeTerminal.cpp
        UserDatabase.cpp
        Utils.cpp
)
