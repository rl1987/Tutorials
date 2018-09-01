#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "thread.h"

char stack[THREAD_STACKSIZE_MAIN];

void *thread_handler(void *arg)
{
    (void) arg;
    puts("I'm in \"thread\" now");
    return NULL;
}

int main(void)
{
    kernel_pid_t pid;
    char line_buf[SHELL_DEFAULT_BUFSIZE];

    puts("This is Task-03");

    pid = thread_create(stack, sizeof(stack),
                    THREAD_PRIORITY_MAIN - 1,
                    THREAD_CREATE_STACKTEST,
                    thread_handler,
                    NULL, "thread");


    printf("Created thread with pid %d\n", pid);

    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
