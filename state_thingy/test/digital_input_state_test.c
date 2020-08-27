#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "digital_input_state.h"
int main()
{
    printf("hello world\n");
    int state = digital_input_state(); 
    printf("state: %d\n",state);

    return 0;
}
