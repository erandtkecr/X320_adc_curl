#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct ctx
{
    char xml_content[4096];
};

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
    int real_size = size*nmemb;
    struct ctx *context = (struct ctx*)userp;
    memcpy(context->xml_content, contents, real_size);
}

int digital_input_state()
{
    CURL *curl;
    CURLcode res;
    char iostate[2];
    char *ptr;

    struct ctx context;
    context.xml_content[0] = '\0';

    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.1.2/state.xml");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &context);
        res = curl_easy_perform(curl);
    }
    else
    {
        printf("curl failed to initialize.\n");
        return -1;
    }

    if(strlen(context.xml_content) == 0)
    {
        printf("xml content empty\n");
        return -1;
    }

    ptr = strstr(context.xml_content,"<io1state>");

    if(*ptr == NULL)
    {
        printf("<io1state> not found\n");
        return -1;
    }

    ptr+=10;

    memcpy(iostate,ptr,1);
    iostate[1] = '\0';
    
    return atoi(iostate);
}
