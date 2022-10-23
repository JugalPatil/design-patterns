#include <stdio.h>
#include "ConcreteCreators.h"

void user (Creator *creator) {
    char* res;
    printf("doing operation on creator, I am not aware of creator type \n");
    res = operation(creator);
    printf("Output : %s \n", res);
}

void main () {
    Creator* creator1 = (Creator*) new_creatorA();
    user(creator1);
    printf("\n");

    Creator* creator2 = (Creator*) new_creatorB();
    user(creator2);
    printf("\n");
}