# 将main.cpp编译成可执行文件
add_executable(main4 main.cpp)


# 链接外部库和内部库到可执行目标
target_link_libraries(main4 
    PUBLIC         #不会传播
                     #外部库
            Graph

)

