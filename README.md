# dmstringtest

## 如何引用已经cmake模块化的项目

1. 将项目中 cmake 目录整个copy到你的项目中
2. 在你的CMakeLists.txt中 project的下方加入以下代码
```cmake
include(cmake/ModuleImport.cmake)
include(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

ModuleImportAll("thirdparty")
```
3. 以dmstring 这个简单的项目为例, 在项目的根目录执行下面命令添加子模块
```bash
git submodule add -f https://github.com/brinkqiang/dmstring ./thirdparty/dmstring
```
4. 你在项目中指定链接这个库, 如果你是非模块化的项目, 可以用target_link_libraries指定

```
cmake_minimum_required(VERSION 3.21)

PROJECT(dmstringtest)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ModuleImportAll("thirdparty")

if(PROJECT_IS_TOP_LEVEL)
    ExeImport("test" "dmtest;dmstring")
endif()

```
