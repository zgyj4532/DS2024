# 将main.cpp编译成可执行文件
add_executable(main1 main1.cpp)


# 链接外部库和内部库到可执行目标
target_link_libraries(main1 
    PRIVATE         #不会传播
            Vector  #外部库
)