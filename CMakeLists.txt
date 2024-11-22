# cmake最低版本
cmake_minimum_required(VERSION 3.20)
# 本项目名
project(DS2024)

# # 设置C++17标准，需要满足标准，不用C++拓展语法
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
# 进入exp1文件夹下面的CMakeLists.txt
add_subdirectory(exp1)
# 进入exp2文件夹下面的CMakeLists.txt
add_subdirectory(exp2)
# 进入exp3文件夹下面的CMakeLists.txt
add_subdirectory(exp3)
# 进入exp4文件夹下面的CMakeLists.txt
add_subdirectory(exp4)
# 进入lib/Vector文件夹下面的CMakeLists.txt
add_subdirectory(lib/Vector)
# 进入lib/Stack文件夹下面的CMakeLists.txt
add_subdirectory(lib/Stack)
# 进入lib/List文件夹下面的CMakeLists.txt
add_subdirectory(lib/List)
# 进入lib/BinTree文件夹下面的CMakeLists.txt
add_subdirectory(lib/Bintree)
# 进入lib/Huff文件夹下面的CMakeLists.txt
add_subdirectory(lib/Huff)
# 进入lib/Dictionary文件夹下面的CMakeLists.txt
add_subdirectory(lib/Dictionary)
# 进入lib/Graph文件夹下面的CMakeLists.txt
add_subdirectory(lib/Graph)
# # 开启测试
# enable_testing()
# # 进入 tests 文件夹下面的CMakeLists.txt
# add_subdirectory(tests)