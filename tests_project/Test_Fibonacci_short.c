uint64_t* msg_main;
uint64_t* msg_fork;
uint64_t* msg_result_main;
uint64_t* msg_result_fork;
uint64_t* msg_newline;

uint64_t fibonacci(uint64_t n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char** argv) {
    uint64_t tid;
    uint64_t fib_main_n;
    uint64_t fib_fork_n;
    uint64_t fib_result;
    uint64_t fib_result2;

    alpha(1);

    fib_main_n = 5;
    fib_fork_n = 3;
    
    msg_main        = "Parent starts...\n";
    msg_fork        = "Child starts...\n";
    msg_result_main = "MAIN has finished!\n";
    msg_result_fork = "FORK has finished!\n";
    
    tid = fork();

    if (tid) {
        priority(20); 
        write(1, msg_main, 18);
        fib_result = fibonacci(fib_main_n);
        write(1, msg_result_main, 20);
    } else {
        priority(10);
        write(1, msg_fork, 17);
        fib_result2 = fibonacci(fib_fork_n);
        write(1, msg_result_fork, 20);
    }
        
    return 1;
}