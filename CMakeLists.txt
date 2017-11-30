cmake_minimum_required(VERSION 3.8)
project(leetCode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp 461.cpp 657.cpp 617.cpp 561.cpp 476.cpp 500.cpp 557.cpp 344.cpp 575.cpp 566.cpp 412.cpp 463.cpp 496.cpp 637.cpp 669.cpp 521.cpp 001.cpp 002.cpp 003.cpp 004.cpp 005.cpp 010.cpp head.h LCS.cpp 011.cpp 015.cpp 017.cpp 019.cpp 020.cpp 021.cpp 022.cpp 053.cpp 448.cpp 070.cpp 023.cpp testBug.cpp 033.cpp 034.cpp 136.cpp 226.cpp 283.cpp 169.cpp 206.cpp 121.cpp 198.cpp 141.cpp 338.cpp 406.cpp 647.cpp 238.cpp 538.cpp 547.cpp 347.cpp 094.cpp 046.cpp 543.cpp 287.cpp buildTree.h binaryTreeCode.cpp 337.cpp 494.cpp 312.cpp 078.cpp 621.cpp 062.cpp 394.cpp 096.cpp 102.cpp 572.cpp 309.cpp 048.cpp 437.cpp 560.cpp 039.cpp)
add_executable(leetCode ${SOURCE_FILES})