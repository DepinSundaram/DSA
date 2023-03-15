#include <iostream>


int main(int argc , char *argv[])
{
    printf("\n%d", argc);
    //printf("\n%c",**++argv);
    //printf("\n%c", *(argv + 1));
    printf("\n%c", **++argv);
}

//++argv = *(argv + 1)