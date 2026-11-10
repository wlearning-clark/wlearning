#include <arpa/inet.h>
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

void Listen(int fd, int backlog)
{
  char* ptr;
  if ((ptr = getenv("LISTENQ")) != NULL) {
    backlog = atoi(ptr);
  }
  if (listen(fd, backlog) == -1)
    perror("Listen:");
}

int main(int argc, char** argv)
{
  /* struct sockaddr_un cli; */
  /* socklen_t len; */
  /* len = sizeof(cli); */
  /* struct in_addr in_a; */
  /* // convert IPv4 address from dotted_decimal string form to 32bit network byte order in binary value */
  /* inet_aton("127.8.8.8", &in_a); */
  /* printf("%032b\n", in_a.s_addr); */
  /* // convert IPv4 address from 32bit network byte to dotted_decimal string */
  /* char* ntoa_ret = inet_ntoa(in_a); */
  /* puts(ntoa_ret); */

  /* in_a.s_addr = inet_addr("199.2.3.53"); */
  /* printf("%032b\n", in_a.s_addr); */

  /* in_addr_t in_a_ret = inet_lnaof(in_a); */
  /* printf("%d\n", in_a_ret); */

  /* in_addr_t netof_ret = inet_netof(in_a); */
  /* printf("%032b\n", netof_ret); */

  /* char pton_buf[255]; */
  /* int8_t pton_ret = inet_pton(AF_INET, "192.168.1.3", pton_buf); */
  /* printf("pton_ret is : %d\n", pton_ret); */

  /* printf("pton_buf ret is : %032b\n", pton_buf); */

  /* fd_t sock_ret = socket(AF_LOCAL, SOCK_STREAM, IPPROTO_TCP); */
  /* char sa_data[14]; */
  /* struct sockaddr skaddr = { */
  /* .sa_family = AF_INET, */
  /* .sa_data = NULL */
  /* }; */
  /* socklen_t sklen = sizeof(skaddr); */
  /* connect(sock_ret, &skaddr, sklen); */
  /* bind(sock_ret, &skaddr,sizeof(skaddr)); */
  /* listen(sock_ret, 3081); */

  /* fd_t listenedfd, clientfd; */
  /* socklen_t len; */
  /* struct sockaddr_in server_addr, client_addr; */
  /* char buf[MAXLINE]; */
  /* time_t ticks; */
  /* listenedfd = socket(AF_INET, SOCK_STREAM, 0); */
  /* bzero(&server_addr, sizeof(server_addr)); */
  /* server_addr.sin_family = AF_INET; */
  /* server_addr.sin_addr.s_addr = htonl(INADDR_ANY); */
  /* server_addr.sin_port = htons(13); */
  /* int32_t bind_ret = bind(listenedfd, (struct sockaddr*)&server_addr, sizeof(server_addr)); */
  /* Listen(listenedfd, 8888); */
  /* for (;;) { */
  /* len = sizeof(client_addr); */
  /* clientfd = accept(listenedfd, (struct sockaddr*)&client_addr, &len); */
  /* printf("connection from %s, port %d\n", inet_ntop(AF_INET, &client_addr.sin_addr, buf, sizeof(buf)), ntohs(client_addr.sin_port)); */
  /* ticks = time(NULL); */
  /* snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks)); */
  /* write(clientfd, buf, sizeof(buf)); */
  /* close(clientfd); */
  /* } */
  /* execl("/usr/bin/ls", "-al", NULL ); */
  /* execle("/usr/bin/ls", "-a", argv); */
  /* execlp("ls", "ls", "-al", NULL); */
  /* execv("/usr/bin/echo", (char*[]) { "echo", "Hello, I'm form execv.", NULL }); */
  /* execvp("echo", (char*[]){"echo", "Hello, $YOURNAME. I'm from execvp."}); */
  /* char * envp[] = {"MYVAR='Clark'", NULL}; */
  /* execve("/usr/bin/sh", (char*[]){"sh","-c", "echo Hello, $MYVAR. I'm form execve.", NULL}, envp ); */
  /* fflush(stdout); */
  /* perror("excel"); */

  int skfd = socket(AF_INET, SOCK_STREAM, 0); // 0 means the protocol is decided by kernel
  if (skfd == -1) {
    perror("socket");
    return (-1);
  }
  struct sockaddr_in addr = {
    .sin_family = AF_INET,
    .sin_addr = ntohl(INADDR_ANY),
    .sin_port = ntohs(8030)
  };
  socklen_t len = sizeof(addr);
  int bind_ret = bind(skfd, (struct sockaddr*)&addr, len);
  if (bind_ret == -1) {
    perror("bind");
    close(skfd);
  }
  listen(skfd, 10);
  printf("the bind port is %d\n", htons(addr.sin_port));
  struct sockaddr_in cliaddr;
  pid_t childpid;
  const char* response = "HTTP/1.1 200 OK\r\n"
                         "Content-Type: text/plain\r\n"
                         "Content-Length: 5\r\n"
                         "Connection: close\r\n"
                         "\r\n"
                         "Hello";
  for (;;) {
    int sknew_fd = accept(skfd, (struct sockaddr*)&cliaddr, &(socklen_t) { sizeof(cliaddr) });
    if (sknew_fd == -1) {
      perror("accept");
      close(skfd);
      break;
    }
    if ((childpid = fork()) == 0) {
      ssize_t nbytes;
      char buff[MAXLINE];
    again:
      while ((nbytes = read(sknew_fd, buff, MAXLINE)) > 0) {
        write(sknew_fd, buff, MAXLINE);
        fflush(stdout);
      }
      if (nbytes < 0 && errno == EINTR) {
        goto again;
      } else if (nbytes == -1) {
        perror("read");
      }
    }
    close(sknew_fd);
    exit((0));
  }
  return (EXIT_SUCCESS);
}
