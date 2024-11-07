# 编译静态库，暂不添加任何源码。
add_library(BinTree "")

# 随后用target_sources添加源码。
# 这种方式更好，因为可以更细粒度地访问权限。
# 例如对cpp文件就是PRIVATE，而hpp则是PUBLIC
target_sources(BinTree
PUBLIC
    # 注：${CMAKE_CURRENT_LIST_DIR}代表当前的CMakeLists.txt文件所在的绝对路径。
    ${CMAKE_CURRENT_LIST_DIR}/BinNode.hpp
    ${CMAKE_CURRENT_LIST_DIR}/BinTree.cpp
    ${CMAKE_CURRENT_LIST_DIR}/BinNode.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Bitmap.hpp
    
)
target_link_libraries(BinTree 
    PUBLIC        #不会传播
            Vector  #外部库
            List
            Stack
            Dictionary
)
# 增加头文件目录
target_include_directories(BinTree
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)