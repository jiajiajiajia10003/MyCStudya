// StudyDemoInGit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ServiceLocator/TestLocator.h"
#include "Factory3Mode/TestFactory.h"

int _tmain(int argc, _TCHAR* argv[])
{
    //TestLocator testlocator;
    //testlocator.testFun();

    //测试简单工厂模式
   TestFactory testFac;
   testFac.testSimpleFactory();
   //测试工厂模式
   testFac.testFactory();
   //测试抽象工厂模式
   testFac.testAbstractFactory();

	return 0;
}

