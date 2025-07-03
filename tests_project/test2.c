uint64_t* foo;
uint64_t* foo2;

int main(int argc, char** argv) {
    uint64_t  tid;

    sched_class(1);
    foo = "Hello MAIN!  ";
    foo2 = "Hello FORK!  ";

    tid = fork();

    if (tid) {
        write(1, foo, 13);
    }
    else {
        write(1, foo2, 13);
    }

    return 1;
}


