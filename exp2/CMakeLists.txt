# 将main.cpp编译成可执行文件
add_executable(main2 main2.cpp)


# 链接外部库和内部库到可执行目标
target_link_libraries(main2 
    PRIVATE         #不会传播
            List
            Vector  #外部库
            Stack
            
)