#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>

int generate_rand()
int main() {
  int pid = getpid();
  printf("%d about to create 2 child processes.\n", pid);
  printf("");
  pid_t child1;
  pid_t child2;
  child1 = fork();
  child2 = fork();
  if (child1 < 0 || child2 < 0) {
    perror("did not fork");
  }
  else if (child1 == 0 || child2 == 0) {
	  
  }
  else {

  }

}
