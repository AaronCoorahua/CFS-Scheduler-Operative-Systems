uint64_t* foo;
uint64_t* foo2;

int main(int argc, char** argv) {
    uint64_t  tid;

    sched_class(1);
    foo = "Hello MAIN!     ";
    foo2 = "Hello FORK!     ";

    tid = fork();

    if (tid) {
        while (*foo != 0) {
            write(1, foo, 8);
            foo = foo + 1;
        }
    }
    else {
        while (*foo2 != 0) {
            write(1, foo2, 8);
            foo2 = foo2 + 1;
        }
    }

    return 1;
}


