#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <sys/wait.h>

void child_proc() {
  int child_pid = getpid();
  srand(child_pid);
  int num = 1 + rand() % 5;
  printf("%d %dsec\n", child_pid, num);
  sleep(num);
  printf("%d finished after %dsec\n", child_pid, num);
  exit(num);
}
int main() {
  int pid = getpid();
  printf("%d about to create 2 child processes\n", pid);
  pid_t child1;
  child1 = fork();
  if (child1 > 0) { // parent
    pid_t child2;
    child2 = fork();
    if (child2 < 0) {
      perror("did not fork\n");
    }
    else if (child2 == 0) {
      child_proc();
    }
    else {
    int status;
    int child_pid = wait(&status);
    int sleep = WEXITSTATUS(status);
    printf("Main Process %d is done. Child %d slept for %dsec\n", pid, child_pid, sleep);
  }
}
  else if (child1 < 0) {
    perror("did not fork\n");
  }
  else {
    child_proc();
  }


}
