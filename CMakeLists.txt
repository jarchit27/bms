cmake_minimum_required(VERSION 3.15)

project(BankSystem
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(bank_core
    src/Account.cpp
    src/Bank.cpp
    src/CurrentAccount.cpp
    src/SavingsAccount.cpp
)

target_include_directories(bank_core
    PUBLIC include
)

add_executable(bank_app
    src/main.cpp
)

target_link_libraries(bank_app
    PRIVATE bank_core
)
