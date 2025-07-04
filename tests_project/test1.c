uint64_t* foo;
uint64_t* foo2;

int main(int argc, char** argv) {
    uint64_t  tid;
    
    //alpha(1);

    foo = "Hello MAIN!  \n";
    foo2 = "Hello FORK!  \n";

    sleep(10000000);

    //tid = fork();

    /*if (tid) {
        write(1, foo, 15);  
    }
    else {
        write(1, foo2, 15);
    }*/

    return 1;
}


