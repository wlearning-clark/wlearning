#include <arpa/inet.h>
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <poll.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/eventfd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#ifndef fd_t
#define fd_t int32_t
#endif
#define MAXLINE 4096
#define BUFFSIZE 8192

enum {
  ONE = '1',
  TWO = '2',
  THREE = '3',
  FOUR = '4',
  FiVE = '5',
  SIX = '6',
  SEVEN = '7',
  EIGHT = '8',
  NINE = '9',
  ZERO = '0',
} num;

void signal_handler(int signo)
{
  printf("I'm catch it, the signal is %d, and name is %s\n", signo, strsignal(signo));
  fflush(stdout);
  sleep(2);
  puts("signal handling finishied.");
}

int main(int argc, char** argv)
{
  struct sigaction sa = {
    .sa_handler = signal_handler,
    .sa_flags = 0
  };
  sigemptyset(&sa.sa_mask);
  sigaddset(&sa.sa_mask, SIGTERM);

  sigaction(SIGINT, &sa, NULL);
  char buff[255];
  printf("pid is : %d\n", getpid());
  while (1) {
    puts("Running...");
    sleep(10);
  }

  return (EXIT_SUCCESS);
}
