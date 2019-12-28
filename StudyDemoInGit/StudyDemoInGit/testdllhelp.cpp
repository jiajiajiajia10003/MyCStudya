#include "stdafx.h"
#include "testdllhelp.h"

void test_dll_help()
{
    int sum = ExcecuteFunc<int(int, int)>("GetSum", 5, 8);
    printf("sum : %d\n", sum);

    std::string append = ExcecuteFunc<std::string(std::string, std::string)>("AppendString", "hello", "world");
    printf("Append : %s\n", append.c_str());
}

int GetSum(int i, int j)
{
    return i + j;
}
std::string AppendString(std::string s1, std::string s2)
{
    return s1 + s2;
}

template<typename T>
std::function<T> GetFunction(const std::string& funcname)
{
    // 此处需要使用GetProcessAddress接口，获取dll的函数地址。
    // 暂时先用这个，进行测试
    if (funcname.compare("GetSum"))
    {
        return std::function<T>((T*)(AppendString));
    }
    else
    {
        return std::function<T>((T*)(GetSum));
    }
}

template<typename T, typename... Args>
typename std::result_of<std::function<T>(Args...)>::type
ExcecuteFunc(const std::string& funcname, Args... args)
{
    return GetFunction<T>(funcname)(args...);
}