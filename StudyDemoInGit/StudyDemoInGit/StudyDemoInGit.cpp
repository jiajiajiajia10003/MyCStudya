// StudyDemoInGit.cpp : �������̨Ӧ�ó������ڵ㡣
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
//    // //���Լ򵥹���ģʽ
//    //TestFactory testFac;
//    //testFac.testSimpleFactory();
//    ////���Թ���ģʽ
//    //testFac.testFactory();
//    ////���Գ��󹤳�ģʽ
//    //testFac.testAbstractFactory();
//
//    //��������ģʽ
//    //TestCommand testCmd;
//    //testCmd.TestFunc();
//}

#include "SimpleAOP/TestAspect.h"
#include <gtest/gtest.h>

#include <thread>
#include "testmutex.h"
#include "testtimemutex.h"
#include "testconditionvariable.h"
#include "testcallonce.h"
#include "testpackagetask.h"
#include "testsharedfuture.h"
#include "testargstemplate.h"
#include "testargstemplateclass.h"
#include "testdllhelp.h"
#include "test_multi_curl.h"
#include "test_easy_curl.h"
#include "TimeSpan.h"

int _tmain(int argc, _TCHAR* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    
    //test_mutex();
    //test_time_mutex();
    //test_conditionvariable();
    //test_call_once();
    //test_package_task();
    //test_shared_future();
    //test_args_template();
    //test_args_template_class();
    //test_template_factory();
    //test_dll_help();

	//bool retflag = false;
	//NewFunction(retflag);

	//TestThreadPoolFunction();
	//test_easy_curl_by_thread();
	//test_easy_curl_by_thread_pool();

	TimeSpan span;
	std::this_thread::sleep_for(std::chrono::microseconds(1000));
	int sp = span.elapsed_micro();

	
	TimeSpan span2;
	std::this_thread::sleep_for(std::chrono::milliseconds(20));
	int sp2 = span2.elapsed_milli();



	return RUN_ALL_TESTS();;
}

