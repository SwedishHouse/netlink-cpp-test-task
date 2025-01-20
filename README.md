Test task for Cpp Developer vacancy 

В качестве источников использовал:

# Реализацию данного задания на языке С:
https://github.com/ProProperDev/Generic_Netlink_Communication

# Информацию о протоколе получал здесь:
https://www.kernel.org/doc/html/v6.7/userspace-api/netlink/index.html
https://habr.com/ru/articles/121254/
https://www.yaroslavps.com/ru/weblog/genl-intro/

# О клиент-серверном взаимодействии:
https://www.bogotobogo.com/cplusplus/sockets_server_client.php

# О JSON в C++:
https://www.studyplan.dev/pro-cpp/json
https://json.nlohmann.me/

# Заметки

## Где работает
    Тестировал работу кода на:
    - WSL Ubuntu версии Linux MSI 5.15.167.4-microsoft-standard-WSL2 #1 SMP Tue Nov 5 00:21:55 UTC 2024 x86_64 x86_64 x86_64 GNU/Linux


## Google Test
    Разработку веду по методу TTD, использую Google Test
    Для установки:
    ```sh
    sudo apt update
    sudo apt install cmake g++ git

    git clone https://github.com/google/googletest.git
    cd googletest

    mkdir build
    cd build
    cmake ..
    make
    sudo make install
    ```

## Задание
    Указано в прилагаемом изображении
     
## Тип данных
    Считаю, что для пересылки данных используются целочисленные знаковые и вещественные числа. Прочие не используются

## 