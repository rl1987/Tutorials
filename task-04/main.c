#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "thread.h"
#include <xtimer.h>

char stack[THREAD_STACKSIZE_MAIN];

void *thread_handler(void *arg)
{
    xtimer_ticks32_t now;
    (void)arg;

    xtimer_init();

    while (1) {
      now = xtimer_now();
      printf("%d\n", now.ticks32);
      xtimer_sleep(2);
    }

    return NULL;
}

int main(void)
{
    puts("This is Task-04");

    kernel_pid_t pid = thread_create(stack, sizeof(stack),
                                     THREAD_PRIORITY_MAIN - 1,
                                     THREAD_CREATE_STACKTEST,
                                     thread_handler, NULL,
                                     "thread");

    (void)pid;

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
