# cmake最低版本
cmake_minimum_required(VERSION 3.20)
# 本项目名
project(DS2024)

# # 设置C++17标准，需要满足标准，不用C++拓展语法
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
# 进入exp1文件夹下面的CMakeLists.txt
add_subdirectory(exp1)
# 进入exp2文件夹下面的CMakeLists.txt
add_subdirectory(exp2)
# 进入lib/Vector文件夹下面的CMakeLists.txt
add_subdirectory(lib/Vector)
# # 开启测试
# enable_testing()
# # 进入 tests 文件夹下面的CMakeLists.txt
# add_subdirectory(tests)