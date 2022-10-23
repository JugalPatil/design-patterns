#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ConcreteCreators.h"
#include "ConcreteProducts.h"

creator_vtable ConcreteCreatorA_vtable = {
    (void (*)(void *)) creatorA_destroy,
    (void (*)(void *)) creatorA_info,
    (Product * (*)(void *)) factoryA
};

ConcreteCreatorA* new_creatorA () {
    ConcreteCreatorA *creatorA = malloc(sizeof(ConcreteCreatorA));
    strncpy(creatorA->base_creator.creator_name, "CreatorA created : ", 50);
    creatorA->base_creator.vtable = &ConcreteCreatorA_vtable;
    return creatorA;
}

void creatorA_destroy (ConcreteCreatorA* __this) {
    printf("deleting creator A");
    free(__this);
}

void creatorA_info (ConcreteCreatorA* __this) {
    printf("Creator info from creator A : %s \n", __this->base_creator.creator_name);
}

Product* factoryA (ConcreteCreatorA* __this) {
    return (Product*) new_productA();
}

creator_vtable ConcreteCreatorB_vtable = {
    (void (*)(void *)) creatorB_destroy,
    (void (*)(void *)) creatorB_info,
    (Product * (*)(void *)) factoryB
};

ConcreteCreatorB* new_creatorB () {
    ConcreteCreatorB *creatorB = malloc(sizeof(ConcreteCreatorB));
    strncpy(creatorB->base_creator.creator_name, "CreatorB created : ", 50);
    creatorB->base_creator.vtable = &ConcreteCreatorB_vtable;
    return creatorB;
}

void creatorB_destroy (ConcreteCreatorB* __this) {
    printf("deleting creator B");
    free(__this);
}

void creatorB_info (ConcreteCreatorB* __this) {
    printf("Creator info from creator B : %s \n", __this->base_creator.creator_name);
}

Product* factoryB (ConcreteCreatorB* __this) {
    return (Product*)new_productB();
}
