uint64_t* foo;
uint64_t* foo2;

int main(int argc, char** argv) {
    uint64_t  tid;
    
    alpha(50);

    foo = "Hello MAIN!  \n";
    foo2 = "Hello FORK!  \n";

    tid = fork();

    if (tid) {
        while(1){
            priority(20);
            write(1, foo, 15);
        }
    }
    else {
        while(1){
            priority(40);
            write(1, foo2, 15);
        }
    }

    return 1;
}


