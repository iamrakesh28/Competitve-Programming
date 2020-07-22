#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int agrc, char *argv[]) {
  //printf("%d %d %d\n", STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
  //return 0;
  int ch = fork();
  if (ch < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  if (ch == 0) {
    close(STDOUT_FILENO);
    open("txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    char *args[2];
    args[0] = strdup("./a.out");
    args[1] = NULL;
    execv(args[0], args);
  }
  else
    int wc = wait(NULL);
  return 0;
}
