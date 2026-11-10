#include <arpa/inet.h>
#include <asm-generic/errno-base.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <poll.h>
#include <pthread.h>
#include <signal.h>
#include <stdint.h>
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

// What's the purpose of the progam
// It is a socket sever
//
// What does it have?
// It has a Register to registe a new socket
// It have to bind a port on this machine
// It have to Listen

void socket_register(int32_t* skfd, uint32_t* port, struct sockaddr_in* addr_in)
{
  // What does it need?
  // it need a socket
  *skfd = socket(AF_INET, SOCK_STREAM, 0);
  assert(*skfd != -1);
  // it need to bind
  addr_in->sin_family = AF_INET,
  addr_in->sin_addr.s_addr = ntohl(INADDR_ANY),
  addr_in->sin_port = ntohs(*port);
  socklen_t sklen = sizeof(*addr_in);
  int32_t ret_bind = bind(*skfd, (struct sockaddr*)addr_in, sklen);
  perror("bind");
  assert(ret_bind != -1);
  int32_t ret_listen = listen(*skfd, 64);
  assert(ret_listen != -1);
}

void recv4connfd(int32_t* connfd, char* buffrecv)
{
  ssize_t byten;
  if (fork() == 0) {
    perror("fork");
    while ((byten = recv(*connfd, buffrecv, 254, 0)) > 0) {
      if (buffrecv[0] == '\0') {
        continue;
      }
      printf("Received: %ld bytes, message is  %s\n", strlen(buffrecv), buffrecv);
      fflush(stdout);
    };
  }
}

void send4connfd(int32_t* connfd, char* buffsend)
{
  if (fork() == 0) {
    while (1) {
      printf("Send message: ");
      fgets(buffsend, sizeof(buffsend), stdin);
      send(*connfd, buffsend, strlen(buffsend), 0);
    }
  }
}

int main(int argc, char** argv)
{
  fd_t listenfd, connfd;
  ssize_t byten;
  char buff[255];
  char buffrecv[255];
  char buffsend[255];
  uint32_t port = 8090;
  struct sockaddr_in addr_cli, addr_in;
  memset(&addr_in, 0, sizeof(addr_in));
  memset(&addr_cli, 0, sizeof(addr_cli));
  socket_register(&listenfd, &port, &addr_in);
  printf("Listen: %d\n", port);
  for (;;) {
    socklen_t len = sizeof(addr_cli);
    connfd = accept(listenfd, (struct sockaddr*)&addr_cli, &len);
    printf("Connection from %s, port: %d\n", inet_ntop(AF_INET, &addr_cli.sin_addr, buff, 255), htons(addr_cli.sin_port));
    recv4connfd(&connfd, buffrecv);
    send4connfd(&connfd, buffsend);

    if (errno == EINTR) {
      close(listenfd);
    }
  }

  return (EXIT_SUCCESS);
}
