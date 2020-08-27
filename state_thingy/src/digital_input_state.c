#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct ctx
{
    char xml_content[1024];
};

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *context)
{
    printf("in write callback\n");
    struct ctx *my_context = (struct ctx*)context;
    memcpy(my_context->xml_content, contents, size);
}

int digital_input_state()
{
    printf("in digtial input state\n");
    CURL *curl;
    printf("curl pointer there\n");
    CURLcode res;
    char iostate[2];
    char *ptr;

    printf("almost ctx\n");
    struct ctx context;
    context.xml_content[0] = '\0';
    printf("ctx\n");

    curl = curl_easy_init();
    printf("curl initted\n");
    if(curl)
    {
        printf("curl legit\n");
        curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.1.2/state.xml");
        printf("curl connected\n");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        printf("curl callback set\n");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, context);
        printf("curl written\n");
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

    printf("xml content: %s\n",context.xml_content);
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
