# Linux Commands Practice

## File Commands

- `pwd` : display the current directory
- `ls -l` : list files with details
- `mkdir dir_name` : create a directory
- `rmdir dir_name` : remove an empty directory
- `touch file.txt` : create a new file
- `cp source.txt destination.txt` : copy a file
- `mv old.txt new.txt` : move or rename a file
- `rm file.txt` : delete a file
- `cat file.txt` : display file contents
- `vi file.txt` or `nano file.txt` : edit a file

## Process Management Commands

- `ps` : display current processes
- `ps -ef` : detailed process list
- `top` : live process monitoring
- `kill PID` : terminate a process
- `kill -9 PID` : force terminate a process
- `jobs` : show background jobs
- `bg` : resume a job in the background
- `fg` : bring a job to the foreground
- `nice -n 5 command` : start a process with priority
- `wait` : wait for child process completion

## File Permissions

- `ls -l` : view file permissions
- `chmod 755 file.sh` : set permissions using octal mode
- `chmod u+x file.sh` : add execute permission to user
- `chmod go-w file.txt` : remove write permission from group and others
- `chown user file.txt` : change file owner
- `chgrp group file.txt` : change file group
- `umask` : display default permission mask

## System Information

- `date` : show current date and time
- `cal` : show calendar
- `whoami` : show current user
- `who` : show logged in users
- `uname -a` : show system details
- `hostname` : show machine name
- `df -h` : show disk usage
- `free -h` : show memory usage
- `uptime` : show uptime and load average
- `lscpu` : show CPU information
