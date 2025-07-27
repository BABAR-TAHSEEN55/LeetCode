
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/* int main() { */
/*   int pid = fork(); */
/*   if (pid < 0) { */
/*     exit(1); */
/*   } else if (pid == 0) { */
/*     printf("I am a Child Process\n"); */
/*     printf("My ID : %d\n", getpid()); */
/*     printf("My ParentID : %d\n", getppid()); */
/*   } else { */
/*     wait(NULL); */
/*     printf("I am Parent Process\n"); */
/*     printf("My ID : %d\n", getpid()); */
/*     printf("My Parent ID : %d\n", getppid()); */
/*     printf("My Child : %d\n", pid); */
/*   } */
/* } */
int main() {}
