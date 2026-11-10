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

// What's the purpose of the progam
// It is a socket sever
//
// What does it have?
// It has a Register to registe a new socket
// It have to bind a port on this machine
// It have to Listen

volatile sig_atomic_t running = 1;

typedef struct TinyServer TinyServer;
typedef struct SocketHelper SocketHelper;

struct SocketHelper {
  int32_t listenfd, connfd, clientfd;
  uint16_t port;
  struct sockaddr_in addrserver, addrclient;
  void (*createlisten)(struct SocketHelper* self);
  void (*acceptclients)(struct SocketHelper* self, struct TinyServer* server);
  void (*connecttoserver)(struct SocketHelper* self);
};

struct TinyServer {
  char name[255];
  int32_t listenfd;
  uint32_t port;
  void (*recv)(struct SocketHelper* skhelper);
  void (*send)(struct SocketHelper* skhelper);
};

void createlisten(struct SocketHelper* self)
{
  self->listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (self->listenfd == -1) {
    perror("sokcet");
    exit(1);
  }
  memset(&self->addrserver, 0, sizeof(self->addrserver));
  memset(&self->addrclient, 0, sizeof(self->addrclient));

  self->addrserver.sin_addr.s_addr = htonl(INADDR_ANY);
  self->addrserver.sin_port = htons(self->port);
  self->addrserver.sin_family = AF_INET;
  socklen_t len = sizeof(self->addrserver);

  if ((bind(self->listenfd, (struct sockaddr*)&self->addrserver, len)) == -1) {
    perror("bind");
    exit(1);
  }

  if ((listen(self->listenfd, 32)) == -1) {
    perror("listen");
    exit(1);
  }

  printf("Listen: %d\n", self->port);
}

void acceptclients(SocketHelper* self, TinyServer* server)
{

  char buff[255];
  while (running) {
    puts("Wating to connect...");
    socklen_t len = sizeof(self->addrclient);
    self->connfd = accept(self->listenfd, (struct sockaddr*)&self->addrclient, &len);
    inet_ntop(AF_INET, &self->addrclient.sin_addr, buff, 255);
    uint16_t port = ntohs(self->addrclient.sin_port);
    printf("Connection from: %s, port %d\n", buff, port);
    server->recv(self);
    server->send(self);
  }
  puts("Closing the server...");
}

void sockethelper_init(struct SocketHelper* self, uint16_t port)
{
  self->port = port;
  self->createlisten = createlisten;
  self->acceptclients = acceptclients;
}

void tinyrecv(struct SocketHelper* skhelper)
{
  if (fork() == 0) {
    char buff[255];
    ssize_t nbytes;

    while ((nbytes = recv(skhelper->connfd, buff, 254, 0)) > 0) {

      if (nbytes == 0) {
        puts("Client disconnected");
        break;
      } else if (nbytes == -1) {
        if (errno == EINTR) {
          continue;
        }
        perror("recv");
        break;
      }

      if (buff[0] == '\0') {
        continue;
      }

      printf("Received bytes : %ld, message : %s\n", strlen(buff), buff);
    }
  }
}

void tinysend(struct SocketHelper* skhelper)
{
  char buff[255];
  if (fork() == 0) {
    while (1) {
      printf("Send Message: ");
      fgets(buff, 255, stdin);
      int32_t ret_send = send(skhelper->connfd, buff, strlen(buff), 0);
      if (ret_send == -1) {
        if (errno == EINTR) {
          continue;
        }
        puts("Send: client disconnected.");
        break;
      }
    }
  }
}

void tinyserver_init(struct TinyServer* self, uint16_t port)
{
  self->port = port;
  self->recv = tinyrecv;
  self->send = tinysend;
}

void signal_handler(int32_t signo)
{
  switch (signo) {
  case SIGINT:
    running = 0;
    printf("Receive signal: %s\n", strsignal(signo));
    break;
  }
}

#define LISTEN_PORT 8090

int main(int argc, char** argv)
{
  struct TinyServer* tiny = malloc(sizeof(struct TinyServer));
  struct SocketHelper* skhelper = malloc(sizeof(struct SocketHelper));
  struct sigaction* sa = malloc(sizeof(struct sigaction));
  sa->sa_handler = signal_handler;
  sa->sa_flags = 0;
  sigemptyset(&sa->sa_mask);
  sigaction(SIGINT, sa, NULL);
  tinyserver_init(tiny, LISTEN_PORT);
  sockethelper_init(skhelper, LISTEN_PORT);
  skhelper->createlisten(skhelper);
  skhelper->acceptclients(skhelper, tiny);
  free(sa);
  free(skhelper);
  free(tiny);

  return (EXIT_SUCCESS);
}
