# OS Lab Exam Programs

Programs are arranged in the same order as the syllabus shown in `tech.jpeg`.

## Order

1. `01_linux_commands.md`
2. `02_fork.c`
3. `03_pipe.c`, `03_shared_memory.c`
4. `04_fcfs.c`, `04_sjf.c`, `04_priority.c`, `04_round_robin.c`
5. `05_producer_consumer.c`
6. `06_dining_philosophers.c`
7. `07_bankers_avoidance.c`
8. `08_bankers_prevention.c`
9. `09_fifo_page_replacement.c`, `09_lru_page_replacement.c`
10. `10_disk_fcfs.c`, `10_disk_scan.c`, `10_disk_cscan.c`

## Compile

Regular C programs:

```bash
gcc file.c -o output
```

Thread-based programs:

```bash
gcc file.c -o output -pthread
```
*** Add File: OS/lab-exam/01_linux_commands.md
# Linux Commands Practice

## File Commands

- `pwd` : show present working directory
- `ls -l` : list files with details
- `mkdir dir_name` : create a directory
- `rmdir dir_name` : remove an empty directory
- `touch file.txt` : create an empty file
- `cp source.txt dest.txt` : copy a file
- `mv old.txt new.txt` : move or rename a file
- `rm file.txt` : remove a file
- `cat file.txt` : display file contents
- `nano file.txt` or `vi file.txt` : edit a file

## Process Management Commands

- `ps` : show running processes
- `ps -ef` : detailed process list
- `top` : real-time process monitor
- `kill PID` : terminate a process
- `kill -9 PID` : force terminate a process
- `bg` : resume a job in background
- `fg` : bring a background job to foreground
- `jobs` : list background jobs
- `nice -n 5 command` : start a process with priority
- `wait` : wait for child process completion

## File Permission Commands

- `ls -l` : view file permissions
- `chmod 755 file.sh` : change permissions using numeric mode
- `chmod u+x file.sh` : add execute permission for user
- `chmod go-w file.txt` : remove write permission for group and others
- `chown user file.txt` : change file owner
- `chgrp group file.txt` : change file group
- `umask` : view default permission mask

## System Information Commands

- `date` : show current date and time
- `cal` : show calendar
- `whoami` : show current user
- `who` : show logged in users
- `uname -a` : show kernel and system details
- `hostname` : show host name
- `df -h` : show disk usage
- `free -h` : show memory usage
- `uptime` : show system uptime and load
- `lscpu` : show CPU information
*** Add File: OS/lab-exam/02_fork.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  pid_t pid = fork();

  if (pid < 0) {
    perror("fork");
    return 1;
  }

  if (pid == 0) {
    printf("Child process\n");
    printf("PID: %d\n", getpid());
    printf("Parent PID: %d\n", getppid());
  } else {
    wait(NULL);
    printf("Parent process\n");
    printf("PID: %d\n", getpid());
    printf("Child PID: %d\n", pid);
  }

  return 0;
}
