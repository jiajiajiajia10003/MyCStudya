#pragma once
#include <functional>
#include <string>

void test_dll_help();

int GetSum(int i, int j);
std::string AppendString(std::string s1, std::string s2);

template<typename T>
std::function<T> GetFunction(const std::string& funcname);

template<typename T, typename... Args>
typename std::result_of<std::function<T>(Args...)>::type
ExcecuteFunc(const std::string& funcname, Args... args);