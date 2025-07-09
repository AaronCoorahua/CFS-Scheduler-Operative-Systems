uint64_t* foo;
uint64_t* foo2;

int main(int argc, char** argv) {
    uint64_t  tid;
    alpha(1);

    foo = "Hello Mainn!    ";
    foo2 = "Hella Forkk!    ";


    tid = fork();

    if (tid) {
        priority(80);
        while (*foo != 0) {
            write(1, foo, 8);
            foo = foo + 1;
        }
        
    }
    else {
        priority(20);
        while (*foo2 != 0) {
            write(1, foo2, 8);
            foo2 = foo2 + 1;
        }
    }
    return 1;
}


