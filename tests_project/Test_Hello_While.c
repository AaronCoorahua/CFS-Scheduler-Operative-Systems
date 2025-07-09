uint64_t* foo;
uint64_t* foo2;

int main(int argc, char** argv) {
    uint64_t  tid;
    uint64_t i;
    
    alpha(2);

    foo = "Hello MAIN!  \n";
    foo2 = "Hello FORK!  \n";

    tid = fork();

    if (tid) {
        priority(30);
        while(1){
            write(1, foo, 15);
        }
    }
    else {
        priority(10);
        while(1){
            write(1, foo2, 15);
        }
    }

    return 1;
}


