# 编译静态库，暂不添加任何源码。
add_library(Stack "")

# 随后用target_sources添加源码。
# 这种方式更好，因为可以更细粒度地访问权限。
# 例如对cpp文件就是PRIVATE，而hpp则是PUBLIC
target_sources(Stack
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Stack.cpp

PUBLIC
    # 注：${CMAKE_CURRENT_LIST_DIR}代表当前的CMakeLists.txt文件所在的绝对路径。

    ${CMAKE_CURRENT_LIST_DIR}/Stack.hpp
)
target_link_libraries(Stack
    PRIVATE         #不会传播
            Vector  #外部库
            
)
# 增加头文件目录
target_include_directories(Stack
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)