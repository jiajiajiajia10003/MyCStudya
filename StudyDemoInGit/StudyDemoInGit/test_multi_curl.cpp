#include "stdafx.h"


#include "test_multi_curl.h"
#include <iostream>
#include <string>

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#ifndef WIN32
#  include <unistd.h>
#endif

#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

int progress_callback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
	CURL *easy_handle = static_cast<CURL *>(clientp);
	char timeFormat[9] = "Unknow";

	// Defaults to bytes/second
	double speed;
	std::string unit = "B";

	curl_easy_getinfo(easy_handle, CURLINFO_SPEED_DOWNLOAD, &speed); // curl_get_info必须在curl_easy_perform之后调用

	if (speed > 1024 * 1024 * 1024)
	{
		unit = "G";
		speed /= 1024 * 1024 * 1024;
	}
	else if (speed > 1024 * 1024)
	{
		unit = "M";
		speed /= 1024 * 1024;
	}
	else if (speed > 1024)
	{
		unit = "kB";
		speed /= 1024;
	}

	//printf("download:(%10lld/%10lld), speed:%.2f%s/s\n", dlnow, dltotal,speed, unit.c_str());
	if (dltotal != 0)
	{
		double percent = dlnow * 1.0 / dltotal * 100.0;
		printf("progress: %f\n", percent);
	}

	return 0;
}

static size_t cb(char* d, size_t n, size_t l, void* p)
{
    /* take care of the data here, ignored in this example */
    (void)d;
    (void)p;
    return n * l;
}

static void init(CURLM* cm, int i)
{
	if (i >= CNT)
	{
		return;
	}
    CURL* eh = curl_easy_init();

    curl_easy_setopt(eh, CURLOPT_WRITEFUNCTION, cb);
    curl_easy_setopt(eh, CURLOPT_HEADER, 0L);
    curl_easy_setopt(eh, CURLOPT_URL, urls[i]);
    curl_easy_setopt(eh, CURLOPT_PRIVATE, urls[i]);
    curl_easy_setopt(eh, CURLOPT_VERBOSE, 0L);

	curl_easy_setopt(eh, CURLOPT_MAX_RECV_SPEED_LARGE, (curl_off_t)(300*1000));
	// 打开下载进度功能
	curl_easy_setopt(eh, CURLOPT_NOPROGRESS, 0L);
	curl_easy_setopt(eh, CURLOPT_XFERINFOFUNCTION, progress_callback);

	// 将 easy interface 所产生的句柄信息加入到了 multi interface 的管理中
    curl_multi_add_handle(cm, eh);
}

int NewFunction(bool& retflag)
{
    retflag = true;
    CURLM* cm;
    CURLMsg* msg;
    long L;
    unsigned int C = 0;
    int M, Q, U = -1;
    fd_set R, W, E;
    struct timeval T;

    curl_global_init(CURL_GLOBAL_ALL);

    cm = curl_multi_init();

    /* we can optionally limit the total amount of connections this multi handle
    uses */
	// 设置了 multi interface 在传输时候的最大同步数量为 MAX=10
    curl_multi_setopt(cm, CURLMOPT_MAXCONNECTS, (long)MAX);

    for (C = 0; C < MAX; ++C) {
        init(cm, C);
    }

    while (U) {
		// 传输任务开始执行.其中， 第二个参数U,是开始只想的任务个数,一般是10
        curl_multi_perform(cm, &U);

        if (U) {
            FD_ZERO(&R);
            FD_ZERO(&W);
            FD_ZERO(&E);

			// 从multi_handle中提取文件描述符  第5个参数，返回最大的文件描述符的个数，如果没有找到，则返回-1.
            if (curl_multi_fdset(cm, &R, &W, &E, &M)) {
                fprintf(stderr, "E: curl_multi_fdset\n");
                return EXIT_FAILURE;
            }

            if (curl_multi_timeout(cm, &L)) {
                fprintf(stderr, "E: curl_multi_timeout\n");
                return EXIT_FAILURE;
            }
            if (L == -1)
                L = 100;

            if (M == -1) {
#ifdef WIN32
                Sleep(L);
#else
                sleep(L / 1000);
#endif
            }
            else {
                T.tv_sec = L / 1000;
                T.tv_usec = (L % 1000) * 1000;

                if (0 > select(M + 1, &R, &W, &E, &T)) {
                    //fprintf(stderr, "E: select(%i,,,,%li): %i: %s\n",
                     //   M + 1, L, errno, strerror(errno));
                    return EXIT_FAILURE;
                }
            }
        }

        while ((msg = curl_multi_info_read(cm, &Q))) {
            if (msg->msg == CURLMSG_DONE) {
                char* url;
                CURL* e = msg->easy_handle;
                curl_easy_getinfo(msg->easy_handle, CURLINFO_PRIVATE, &url);
                fprintf(stderr, "R: %d - %s <%s>\n",
                    msg->data.result, curl_easy_strerror(msg->data.result), url);
                curl_multi_remove_handle(cm, e);
                curl_easy_cleanup(e);
            }
            else {
                fprintf(stderr, "E: CURLMsg (%d)\n", msg->msg);
            }
            if (C < CNT) {
                init(cm, C++);
                U++; /* just to prevent it from remaining at 0 if there are more
                     URLs to get */
            }
        }
    }

    curl_multi_cleanup(cm);
    curl_global_cleanup();
    retflag = false;
    return {};
}
