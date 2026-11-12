#include <assert.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <iso646.h>
#include <limits.h>
#include <linux/sched.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/cdefs.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define loop(index, len) \
  for (int i = index, i < len, i++)

#define innerloop(index, len) \
  for (int j = index, j < len, j++)

#define innerloop2(index, len) \
  for (int k = index, k < len, k++)

#define close_fd(fd)   \
  if (close(fd) == -1) \
  perror("close fd")

const char* file = "./file.txt";

int file_open()
{
  int fd = open(file, O_CREAT | O_WRONLY | O_APPEND);
  if (fd == -1) {
    perror("open");
  }
  return fd;
}

void file_create()
{
  int fd = creat(file, 0644);
  if (fd == -1) {
    perror("create");
  }
}

int locstrlen(const char* str)
{
  int len = 0;
  int idx = 0;
  while (1) {
    if (str[idx] == '\0')
      return len;
    len++;
    idx++;
  }
}

void file_write()
{
  int fd = file_open();
  char* buf = "a simple file context write at Sat 24 Oct.";

  int ret = write(fd, buf, locstrlen(buf));
  if (ret == -1) {
    perror("file_write");
  }
  close_fd(fd);
}

void file_read()
{
  char buf[255];
  int fd = open(file, O_RDONLY);
  while ((read(fd, buf, sizeof(buf))) > 0) {
    printf("context: %s", buf);
  }
  perror("file_read");
  close_fd(fd);
}
void file_read2()
{
  ssize_t ret;
  size_t len = 10;
  char buf[2];
  int fd = open(file, O_RDONLY);
  while (len != 0 && (ret = read(fd, buf, len)) != 0) {
    if (ret == -1) {
      if (errno == EINTR) {
        continue;
      }
      perror("read2");
      break;
    }
    len -= ret;
    ret += len;
  }
  close_fd(fd);
}

void file_seek()
{
  int fd = open(file, O_RDONLY);
  off_t posi = lseek(fd, (off_t)5, SEEK_CUR);
  /* lseek(fd, (off_t)5, SEEK_CUR); */
  char buf[255];
  int ret;
  while ((ret = read(fd, buf, 255) != 0)) {
    if (ret == -1) {
      perror("read");
      break;
    }
    puts(buf);
  }
  close_fd(fd);
}

void locpread()
{
  char buf[255];
  size_t nbytes = 255;
  off_t offset = 0;
  int fd = open(file, O_RDONLY);
  ssize_t ret;
  while (true) {
    ret = pread(fd, buf, nbytes, offset);
    if (ret == 0) {
      break;
    }
    if (ret == -1) {
      perror("pread");
      break;
    }
    puts(buf);
    offset += ret;
  }
  close_fd(fd);
}

struct block1 {
  double b;
  float c;
  int a;
  char * d;
};

void general()
{
  printf("%ld\n", SSIZE_MAX);
  const int iarr[3] = { 1, 3, 4 };
  int iarr2[3] = { 1, 3, 4 };
  const int* iptr;
  int a = 33;
  iptr = &a;
  printf("iptr &a: %p\n", iptr);
  int* const iptr2 = &a;
  int b = 11;
  iptr = &b;
  /* iptr2 = &b; */
  uintptr_t addr1 = (uintptr_t)iptr;
  uintptr_t addr2 = (uintptr_t)iptr2;
  uintptr_t distance = addr2 >= addr1
      ? addr2 - addr1
      : addr1 - addr2;
  printf("byte distance: %lu\n", distance);
  printf("iptr &b: %p\n", iptr);
  printf("iptr2: %p\n", iptr2);
  printf("iptr addr: %p\n", &iptr);
  printf("iptr2 addr: %p\n", &iptr2);
  printf("iptr2 + 2: %p\n", (&iptr2 + 2));
  int * pl = (int[]) {1, 9, 77};
  putchar('%'); 
  putchar('\n');
  struct block1 block = {
    .a = 3,
    .b = 8.11,
    .c = 2.91,
    .d = "a masseage in the block1"
  };
  struct block1 * bptr = &block;
  // obtain the offset of d in the struct block1
  int ret = offsetof(struct block1, d);
  printf("double size: %ld\n", sizeof(double));
  printf("int size: %ld\n", sizeof(int));
  printf("float size: %ld\n", sizeof(float));
  printf("offset of .d in the struct of block1: %d\n", ret);
  uintptr_t addr = (uintptr_t)bptr; 
  uintptr_t d_addr = addr + ret;
  printf("addr : %p\n", (void*)addr);
  printf("d_addr : %p\n", (void*)d_addr);
  printf("d_addr's value : %s\n", *(char**)d_addr);
}
int sump(int* start, int* end)
{
  int total = 0;
  while (start < end) {
    total += *start; // add value to total
    printf("strat: %d", *start);
    start++;
    // advance pointer to next element
  }
  return total;
}

int main(__attribute_maybe_unused__ int argc, __attribute_maybe_unused__ char** argv)
{
  /* file_create(); */
  /* file_write(); */
  /* file_read(); */
  /* file_read2(); */
  /* file_seek(); */
  /* locpread(); */
/* general(); */
  register int key;
  printf("%ld\n", sizeof(short));
  printf("%ld\n", sizeof(int));
  printf("%ld\n", sizeof(long));
  printf("%ld\n", sizeof(double));
  rand();
  return (EXIT_SUCCESS);
}
