#pragma once

#include "curl/curl.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

void test_easy_url(CURL *curl, char* url, char* file_name);

void test_easy_curl_by_thread();


void test_easy_curl_by_thread_pool();
