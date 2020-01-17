#include "stdafx.h"
#include <thread>

#include "test_easy_curl.h"


#include "ThreadPool/ThreadPool.h"

char* urls[] = {
	"http://sdk.fifo.site/chfs/shared/client/windows-uikit-demo/release/demo_1.0.2.13_8189c7cc_Release.zip",    //177.44MB
	"http://sdk.fifo.site/chfs/shared/client/windows-uikit-demo/release/demo_1.0.2.13_8189c7cc_ReleasePDB.zip", //50.26MB
	"http://sdk.fifo.site/chfs/shared/client/windows-uikit-demo/release/demo_1.0.2.13_8189c7cc_Debug.zip"		//53.18MB
};

char* filenames[] = {
	"Release.zip",
	"ReleasePDB.zip",
	"Debug.zip"
};

// ��Ҫ�����ļ����
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	int written = fwrite(ptr, size, nmemb, (FILE *)stream);
	return written;
}

void test_easy_url(CURL *curl, char* url, char* file_name)
{
	if (!url || !file_name)
	{
		return;
	}

	//CURL *curl;
	FILE *fp;  //����FILE����ָ��

	curl_global_init(CURL_GLOBAL_ALL);
	//curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, url);

	if ((fp = fopen(file_name, "wb")) == NULL)
	{
		curl_easy_cleanup(curl);
		exit(1);
	}
	////CURLOPT_WRITEFUNCTION ����̵Ķ�������write_data��������
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
	// �ȴ�curl�������
	curl_easy_perform(curl);

	printf("%s finished.\n", file_name);

	fclose(fp);
	curl_easy_cleanup(curl);
}

// ʹ���߳���ɣ�easycurl��ͬ��ģʽ
void test_easy_curl_by_thread()
{
	CURL *pCurl = curl_easy_init();;
	std::thread th(test_easy_url, pCurl, urls[2], filenames[2]);
	printf("begin thread :\n");
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// ��ͣcurl����
	printf("pause curl\n");
	curl_easy_pause(pCurl, CURLPAUSE_RECV);
	std::this_thread::sleep_for(std::chrono::seconds(20));

	// �ָ�curl����
	printf("resume curl\n");
	curl_easy_pause(pCurl, CURLPAUSE_RECV_CONT);

	// �ȴ�curl�������
	th.join();
	printf("begin thread :\n");
	system("pause");
}

void test_easy_curl_by_thread_pool()
{
	const int MAX_QUEUE = sizeof(urls) / sizeof(char*);
	ThreadPool pool;
	pool.setMaxQueueSize(MAX_QUEUE);
	pool.start(2);

	for (int Index = 0; Index < MAX_QUEUE; Index++) {
		CURL *pCurl = curl_easy_init();;
		auto task = std::bind(test_easy_url, pCurl, urls[Index], filenames[Index]);
		printf("insert ----------------%d\n", Index);
		pool.run(task);
	}
	getchar();
}