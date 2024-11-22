# 将main.cpp编译成可执行文件
add_executable(main main.cpp)


# 链接外部库和内部库到可执行目标
target_link_libraries(main 
    PRIVATE         #不会传播
                     #外部库
            Huff
            
)

