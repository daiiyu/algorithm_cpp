# algorithm_cpp

#### 介绍
记录算法题的步骤。
同时使用了[google test](https://github.com/google/googletest.git) 进行测试。
使用的是leetcode的接口命令。

#### 使用方法
命令行:

```shell script
mkdir build
cd build
# 如果没有ninja命令
#sudo apt install ninja-build
cmake ..  
make -j

# 测试, 保持在build目录下
ctest -V
```
