#include <stdio.h>

void call_by(int value, int *referrence)
{
    value *= 2;
    (*referrence) *= 2;
}

int main()
{
    int value = 10, referrence = 20;
    call_by(value, &referrence);
    printf("%d %d", value, referrence);
}