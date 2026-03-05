#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]){
int *currentBreak = sbrk(0);
printf("%p\n",currentBreak);
}