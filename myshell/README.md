Everything you need to know to start coding your own shell

Exercises
0. getppid
Write a program that prints the PID of the parent process. Run your program several times within the same shell. It should be the same. Does echo $$ print the same value? Why?

1. /proc/sys/kernel/pid_max
Write a shell script that prints the maximum value a process ID can be.

0. av
Write a program that prints all the arguments, without using ac.

1. Read line
Write a program that prints "$ ", wait for the user to enter a command, prints it on the next line.

2. command line to av
Write a function that splits a string and returns an array of each word of the string.

man strtok

#advanced: Write the function without strtok

Write a program that executes the command ls -l /tmp in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child. fork + wait + execve

Using everything we saw, write a first version of a super simple shell that can run commands with their full path, without any argument. super simple shell

Write a program that looks for files in the current PATH.

Usage: _which filename ...find a file in the PATH


