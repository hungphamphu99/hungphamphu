# Attempting to save the document again
doc = Document()

# Title
doc.add_heading('Network Programming Assignment', 0)

# Chapter 4 Summary
doc.add_heading('Summary of Chapter 4: Elementary TCP Sockets', level=1)

# Key Functions and Their Usage
doc.add_heading('Key Functions and Their Usage', level=2)

functions = [
    ("socket", "Creates a new socket.", "int socket(int domain, int type, int protocol);", "int sockfd = socket(AF_INET, SOCK_STREAM, 0);"),
    ("connect", "Initiates a connection on a socket.", "int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);", "connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));"),
    ("bind", "Assigns an address to the socket.", "int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);", "bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));"),
    ("listen", "Prepares the socket to accept connections.", "int listen(int sockfd, int backlog);", "listen(listenfd, LISTENQ);"),
    ("accept", "Accepts a connection on a socket.", "int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);", "connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);"),
    ("fork", "Creates a new process.", "pid_t fork(void);", "if (fork() == 0) { /* child process code */ }"),
    ("close", "Closes a file descriptor.", "int close(int fd);", "close(sockfd);"),
    ("getsockname", "Gets the current address to which the socket is bound.", "int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);", "getsockname(sockfd, (struct sockaddr *)&localaddr, &addrlen);"),
    ("getpeername", "Gets the address of the peer connected to the socket.", "int getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen);", "getpeername(connfd, (struct sockaddr *)&peeraddr, &addrlen);"),
    ("signal", "Sets a signal handler for a signal.", "void (*signal(int sig, void (*func)(int)))(int);", "signal(SIGCHLD, sig_chld);"),
    ("sigaction", "Examine and change a signal action.", "int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);", "sigaction(SIGCHLD, &sa, NULL);"),
    ("wait", "Waits for a child process to change state.", "pid_t wait(int *status);", "wait(&status);"),
    ("waitpid", "Waits for a specific child process to change state.", "pid_t waitpid(pid_t pid, int *status, int options);", "waitpid(pid, &status, 0);")
]

for name, purpose, usage, example in functions:
    doc.add_heading(name, level=3)
    doc.add_paragraph(f"Purpose: {purpose}")
    doc.add_paragraph(f"Usage: {usage}")
    doc.add_paragraph(f"Example: {example}")

# Chapter 5 Summary
doc.add_heading('Summary of Chapter 5: TCP Client/Server Example', level=1)

# TCP Echo Server and Client
doc.add_heading('TCP Echo Server and Client', level=2)

doc.add_heading('TCP Echo Server: Main Function', level=3)
doc.add_paragraph('Initialization: Create a socket, bind it, and start listening.\nConcurrency: Use fork() to handle multiple clients simultaneously.\nSignal Handling: Use signal() to handle SIGCHLD and prevent zombie processes.')

doc.add_heading('TCP Echo Server: str_echo Function', level=3)
doc.add_paragraph('Purpose: Reads data from the client and sends it back.\nLoop: Continues reading from and writing to the client until the connection is closed.')

doc.add_heading('TCP Echo Client: Main Function', level=3)
doc.add_paragraph('Initialization: Create a socket and connect it to the server.\nInteraction: Read input from the user, send it to the server, and print the server\'s response.')

doc.add_heading('TCP Echo Client: str_cli Function', level=3)
doc.add_paragraph('Purpose: Manages the client-side communication.\nLoop: Continuously reads user input, sends it to the server, and prints the server\'s response.')

# Practical Steps
doc.add_heading('Practical Steps to Compile and Run TCP Echo Application', level=2)

steps = [
    "Create the Server and Client Programs: Write the server and client code as outlined in Chapter 5. Ensure that the server can handle multiple clients using fork().",
    "Compile the Programs: Use gcc to compile the server and client programs.\nExample: gcc -o server tcp_server.c unp.c -lunp and gcc -o client tcp_client.c unp.c -lunp",
    "Run the Server: Start the server on a designated port.\nExample: ./server",
    "Run the Client: Start the client and connect it to the server.\nExample: ./client <server_ip_address>",
    "Testing Concurrency and Signal Handling: Open multiple client connections to test the server's ability to handle concurrent connections. Implement signal handling to manage child processes and prevent zombie processes."
]

for step in steps:
    doc.add_paragraph(step, style='List Bullet')

# TCP Echo Server Code with Fork and Signal Handling
doc.add_heading('Example of TCP Echo Server Code with Fork and Signal Handling', level=2)

server_code = """
#include "unp.h"
#include <sys/wait.h>

void sig_chld(int signo) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
    return;
}

void str_echo(int sockfd) {
    ssize_t n;
    char buf[MAXLINE];
    while ((n = read(sockfd, buf, MAXLINE)) > 0) {
        writen(sockfd, buf, n);
    }
}

int main(int argc, char **argv) {
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    Signal(SIGCHLD, sig_chld);

    for ( ; ; ) {
        clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (SA *) &cliaddr, &clilen)) < 0) {
            if (errno == EINTR)
                continue;
            else
                err_sys("accept error");
        }

        if ((childpid = Fork()) == 0) {
            Close(listenfd);
            str_echo(connfd);
            Close(connfd);
            exit(0);
        }
        Close(connfd);
    }
}
"""
doc.add_paragraph(server_code)

# TCP Echo Client Code
doc.add_heading('Example of TCP Echo Client Code', level=2)

client_code = """
#include "unp.h"

void str_cli(FILE *fp, int sockfd) {
    char sendline[MAXLINE], recvline[MAXLINE];
    while (Fgets(sendline, MAXLINE, fp) != NULL) {
        Writen(sockfd, sendline, strlen(sendline));
        if (Readline(sockfd, recvline, MAXLINE) == 0)
            err_quit("str_cli: server terminated prematurely");
        Fputs(recvline, stdout);
    }
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2)
        err_quit("usage: tcpcli <IPaddress>");

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

    str_cli(stdin, sockfd);

    exit(0);
}
"""
doc.add_paragraph(client_code)

# Save the document
file_path = "Network_Programming_Assignment.doc"
doc.save(file_path)

file_path
