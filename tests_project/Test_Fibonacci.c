uint64_t* foo;
uint64_t* foo2;

uint64_t* foo3;
uint64_t* foo4;

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
    
    foo = "FINISH MAIN!\n";
    foo2 = "FINISH FORK!\n";
    foo3 = "STARTS MAIN!\n";
    foo4 = "STARTS FORK!\n";
    
    tid = fork();

    if (tid) {
        // PRIO 40 TERMINA FORK ANTES
        // PRIO 80 TERMINA MAIN ANTES
        // PRIO 160 MAIN MONOPOLIZA EJECUCIÓN
        priority(80); 
        //write(1, foo3, 14);
        fib_result = fibonacci(30);
        //write(1, foo, 14);
    } else {
        priority(10);
        //write(1, foo4, 14);
        fib_result = fibonacci(26);
        //write(1, foo2, 14);
    }
        
    return fib_result;
}