# Minitalk - Communication Program Using UNIX Signals

Minitalk is a communication program that consists of a client and a server. The server must be started first and, after its launch, it prints its Process ID (PID). The client takes two parameters: the server PID and the string to send. The client sends the string passed as a parameter to the server using UNIX signals. Once the string is received by the server, it must be printed.

## Learning Goals
Minitalk provided an opportunity to understand inter-process communication using UNIX signals. The project focused on signal handling, process IDs, and implementing a simple client-server model. The learning goals of the project include:

1. **UNIX Signals:** Understanding and implementing communication between processes using UNIX signals, specifically SIGUSR1 and SIGUSR2.

2. **Signal Handling:** Learning to handle signals and their associated actions using sigaction.

3. **Process IDs (PID):** Understanding the concept of process IDs and how they can be used to identify processes.

4. **Error Handling and Memory Management:** Thoroughly handling errors and memory management to avoid unexpected program termination and memory leaks.

## Details
The mandatory part of the Minitalk project allowed the use of the following functions:

- write: Used for outputting data to a file descriptor (in this case, to send data from the client to the server).

- ft_printf (and any equivalent YOU coded): A custom implementation of the printf function that can be used for printing formatted output (not limited to displaying the server PID).

- signal: Used for setting up signal handlers to handle incoming signals.

- sigemptyset, sigaddset: Used for manipulating signal sets, particularly in setting up signal masks for signal handling.

- sigaction: Used to specify and handle signals with more control over the signal behavior.

- kill: Used to send signals to processes.

- getpid: Used to retrieve the PID of the calling process.

- malloc, free: Used for dynamic memory allocation and deallocation.

- pause, sleep, usleep: Used for controlling process execution and time delays.

- exit: Used to terminate a process.

## Reflection
Minitalk was a challenging project that deepened my understanding of inter-process communication using UNIX signals. I enjoyed working on this project as it involved creating a simple client-server model and implementing signal handling mechanisms.

Implementing the signal communication and handling logic efficiently was crucial to ensuring smooth communication between the client and server. Error handling and memory management were also critical aspects to prevent unexpected program termination and memory leaks.

This project provided valuable insights into low-level inter-process communication and the importance of proper signal handling in real-world scenarios. It was an excellent exercise in managing processes, signal communication, and memory in a multi-process environment.

Overall, Minitalk was an engaging project that enriched my understanding of UNIX signals and inter-process communication, contributing to my growth as a developer.
