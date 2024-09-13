# Test_Task_KFD_v2
Мой код для вступительного теста

Если что-то нужно добавить/исправить: мой тг @Vozmitelka

Описание работы приложения:
Код разделён на 2 основных класса: CurrencyExchangeTerminal и UserDatabase  
Теримнал не обладает данными пользователя, вместо этого он делегирует получение данным UserDatabase


Пример работы консоли:
```
C:\Users\andre\CLionProjects\BankMasterv2\cmake-build-debug\BankMasterv2.exe
Enter your username:Andrew
New user created: Andrew
---------------------------------------------------------
Available commands: 'exchange', 'balance', 'exit', 'rates'.
Enter command:rates
---------------------------------------------------------
USD to RUB = 91.100000
EUR to RUB = 100.100000
USD to EUR = 0.900000
USD to USDT = 1.000000
BTC to USD = 58000.000000
---------------------------------------------------------
Enter command:exchange
---------------------------------------------------------
Enter the currency you want to exchange:RUB
Enter the amount you want to exchange to:10000
Enter the currency you want to receiv
e:EUR
Exchange successful: -10000 RUB     +99.90 EUR
---------------------------------------------------------
Enter command:balance
---------------------------------------------------------
You have:
990000 RUB
99.90 EUR
---------------------------------------------------------
Enter command:rates
---------------------------------------------------------
USD to RUB = 86.919000
EUR to RUB = 99.589000
USD to EUR = 0.885000
USD to USDT = 0.997000
BTC to USD = 55970.000000
---------------------------------------------------------
Enter command:exhange
---------------------------------------------------------
Error: Unknown command. Please try again.
Available commands: 'exchange', 'balance', 'exit'.
---------------------------------------------------------
Enter command:exchange
---------------------------------------------------------
Enter the currency you want to exchange:EUR
Enter the amount you want to exchange to:99
Enter the currency you want to receiv
e:RUB
Exchange successful: -99 EUR     +9859.31 RUB
---------------------------------------------------------
Enter command:exchange
---------------------------------------------------------
Enter the currency you want to exchange:RUB
Enter the amount you want to exchange to:10000
Enter the currency you want to receiv
e:BTC
Error: Invalid currency pair
---------------------------------------------------------
Enter command:exhange
---------------------------------------------------------
Error: Unknown command. Please try again.
Available commands: 'exchange', 'balance', 'exit'.
---------------------------------------------------------
Enter command:exchange
---------------------------------------------------------
Enter the currency you want to exchange:RUB
Enter the amount you want to exchange to:100000000
Enter the currency you want to receiv
e:USD
Error: Insufficient funds for this operation
---------------------------------------------------------
Enter command:exchange
---------------------------------------------------------
Enter the currency you want to exchange:RUB
Enter the amount you want to exchange to:10000
Enter the currency you want to receiv
e:BTC
Error: Invalid currency pair
---------------------------------------------------------
Thank you for using the terminal! Goodbye.
```
