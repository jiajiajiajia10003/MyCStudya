#include "stdafx.h"
#include <thread>

#include "test_easy_curl.h"

#include "curl/curl.h"

static const char* urls[] = {
	"http://sdk.fifo.site/chfs/shared/client/windows-uikit-demo/release/demo_1.0.2.13_8189c7cc_Release.zip",
	"http://sdk.fifo.site/chfs/shared/client/windows-uikit-demo/release/demo_1.0.2.13_8189c7cc_ReleasePDB.zip",
	"http://sdk.fifo.site/chfs/shared/client/windows-uikit-demo/release/demo_1.0.2.13_8189c7cc_Debug.zip"
};

FILE *fp;  //定义FILE类型指针
//这个函数是为了符合CURLOPT_WRITEFUNCTION而构造的
//完成数据保存功能
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	int written = fwrite(ptr, size, nmemb, (FILE *)fp);
	return written;
}

// 使用函数直接调用easycurl，同步模式---------保存的是网页
void test_easy_url()
{
	CURL *curl;

	char* url = "www.baidu.com";
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, url);

	if ((fp = fopen("test_url_file.html", "w")) == NULL)
	{
		curl_easy_cleanup(curl);
		exit(1);
	}
	////CURLOPT_WRITEFUNCTION 将后继的动作交给write_data函数处理
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	// 等待curl传输完成
	curl_easy_perform(curl);

	fclose(fp);
	curl_easy_cleanup(curl);
}

//libcurl的同步模式------保存的是文件
CURL *curl2;
void test_easy_url_to_file()
{
	curl_global_init(CURL_GLOBAL_ALL);
	curl2 = curl_easy_init();
	curl_easy_setopt(curl2, CURLOPT_URL, urls[0]);

	if ((fp = fopen("test_dl_file.zip", "w")) == NULL)
	{
		curl_easy_cleanup(curl2);
		exit(1);
	}
	////CURLOPT_WRITEFUNCTION 将后继的动作交给write_data函数处理
	curl_easy_setopt(curl2, CURLOPT_WRITEFUNCTION, write_data);
	printf("begin perform curl:\n");

	// 等待curl传输完成
	curl_easy_perform(curl2);

	printf("end   perform curl:\n");

	fclose(fp);
	curl_easy_cleanup(curl2);
}
// 使用线程完成，easycurl的同步模式
void test_easy_curl_by_thread()
{
	std::thread th(test_easy_url_to_file);
	printf("begin thread :\n");
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// 暂停curl下载
	printf("pause curl\n");
	curl_easy_pause(curl2, CURLPAUSE_RECV);
	std::this_thread::sleep_for(std::chrono::seconds(20));

	// 恢复curl下载
	printf("resume curl\n");
	curl_easy_pause(curl2, CURLPAUSE_RECV_CONT);

	// 等待curl下载完成
	th.join();
	printf("begin thread :\n");
	system("pause");
}