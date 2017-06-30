#include <stdio.h>
#include <sys/utsname.h>

int main() {
  struct utsname ver;
  // linux system call
  uname(&ver);
  printf("%s", ver.release);
  return 0;
}