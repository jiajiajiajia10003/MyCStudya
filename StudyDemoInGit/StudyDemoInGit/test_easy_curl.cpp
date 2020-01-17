#include "stdafx.h"

#include "test_easy_curl.h"

#include "curl/curl.h"

static const char* urls[] = {
	"http://sdk.fifo.site/chfs/shared/client/windows-uikit-demo/release/demo_1.0.2.13_8189c7cc_Release.zip",
	"http://sdk.fifo.site/chfs/shared/client/windows-uikit-demo/release/demo_1.0.2.13_8189c7cc_ReleasePDB.zip",
	"http://sdk.fifo.site/chfs/shared/client/windows-uikit-demo/release/demo_1.0.2.13_8189c7cc_Debug.zip"
};

FILE *fp;  //����FILE����ָ��
//���������Ϊ�˷���CURLOPT_WRITEFUNCTION�������
//������ݱ��湦��
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	int written = fwrite(ptr, size, nmemb, (FILE *)fp);
	return written;
}

void test_easy_url()
{
	CURL *curl;

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, "www.baidu.com");

	if ((fp = fopen("test_url_file.html", "w")) == NULL)
	{
		curl_easy_cleanup(curl);
		exit(1);
	}
	////CURLOPT_WRITEFUNCTION ����̵Ķ�������write_data��������
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	// �ȴ�curl�������
	curl_easy_perform(curl);

	fclose(fp);
	curl_easy_cleanup(curl);
}

