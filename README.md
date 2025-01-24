Test task for Cpp Developer vacancy 

В качестве источников использовал:
# Как запускать
    ```
        make
    ```

    В одном окне терминала 
    `sudo ./main_server`

    В другомм окне терминала 
    `sudo ./main_client < JSON_Strings`

    Можно изменить файл ввода, если угодно
    Плюс, логику обработки можно проверить на unit тестах


# Тренировался в отдельных репозиториях
https://github.com/SwedishHouse/cpp-simple-server
https://github.com/SwedishHouse/my-cpp-genetlink
https://github.com/SwedishHouse/netlink-userspace-experience
https://github.com/SwedishHouse/cpp-json-experience

# Реализацию данного задания на языке С:
https://github.com/ProProperDev/Generic_Netlink_Communication - Вот где взял идею с PID
https://github.com/argonlaser/talk-with-linux/tree/master  - здесь надо обнулить структуры, тогда unicast заработает
https://github.com/dandurisrihari/Generic-Netlink-Socket-and-SPI-Device-Programming/tree/master

# Информацию о протоколе получал здесь:
## Советы от людей, которые хотят сделать userspce-userspace commmunication
https://stackoverflow.com/questions/3027119/netlink-user-space-and-kernel-space-communication?rq=3

https://stackoverflow.com/questions/4440584/kernel-space-user-space-communication-with-netlink?rq=3

https://stackoverflow.com/questions/44273066/is-there-a-way-i-can-use-netlink-for-inter-process-communication-ipc-between-t

## Стаьи с примером приложения
https://habr.com/ru/articles/121254/

https://www.yaroslavps.com/ru/weblog/genl-intro/

https://www.electronicsfaq.com/2014/02/generic-netlink-sockets-example-code.html

## Документация на протокол
https://www.kernel.org/doc/html/v6.7/userspace-api/netlink/index.html
https://teowabo.wordpress.com/2014/03/17/netlink-socket/
https://wiki.linuxfoundation.org/networking/generic_netlink_howto#userspace_communication

## Программирование на сокетах
https://www.geeksforgeeks.org/socket-programming-in-cpp/


## Библиотеки Netlink
https://www.infradead.org/~tgr/libnl/
https://www.infradead.org/~tgr/libnl/doc/api/group__genl.

## О клиент-серверном взаимодействии:
https://www.bogotobogo.com/cplusplus/sockets_server_client.php

## О JSON в C++:
https://www.studyplan.dev/pro-cpp/json
https://json.nlohmann.me/

# Заметки

## Где работает
    Тестировал работу кода на:
    - WSL Ubuntu версии Linux MSI 5.15.167.4-microsoft-standard-WSL2 #1 SMP Tue Nov 5 00:21:55 UTC 2024 x86_64 x86_64 x86_64 GNU/Linux
    - BTT Pi V1.2 с дистрибутивом Debian (https://github.com/bigtreetech/BTT-Pi/blob/master/BIGTREETECH%20Pi%20V1.2%20User%20Manual.pdf)


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
    !тестовое_NDM_C++ .jpeg
     
## Тип данных
    Считаю, что для пересылки данных используются целочисленные знаковые и вещественные числа. Прочие не используются
