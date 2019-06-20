// StudyDemoInGit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ServiceLocator/TestLocator.h"
#include "Factory3Mode/TestFactory.h"
#include "CommandMode/TestCommand.h"

#include "ThreadPool/TestThreadPool.h"

//void test()
//{
//    //TestLocator testlocator;
//    //testlocator.testFun();
//
//    // //测试简单工厂模式
//    //TestFactory testFac;
//    //testFac.testSimpleFactory();
//    ////测试工厂模式
//    //testFac.testFactory();
//    ////测试抽象工厂模式
//    //testFac.testAbstractFactory();
//
//    //测试命令模式
//    //TestCommand testCmd;
//    //testCmd.TestFunc();
//}
int _tmain(int argc, _TCHAR* argv[])
{
    TestThreadPoolFunction();

	return 0;
}

