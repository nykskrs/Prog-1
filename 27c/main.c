#include <stdio.h>

/*3 -------------------*/
void print_out(const char *p, const int x)
{
    printf("p is \"%s\" and x is %i\n", p, x);
}

int main()
{
    /*1 -------------------*/
    printf("Hello World!\n");

    /*2 -------------------*/
    char *hello = "Hello";
    char *world = "World";
    printf("%s %s\n", hello, world);

    /*3 -------------------*/
    print_out("foo", 7);
    print_out("hello", 12);
    print_out("world", 1);
}