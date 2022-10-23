#ifndef CONCRETE_CREATOR_H_INCLUDED
#define CONCRETE_CREATOR_H_INCLUDED

#include <stdio.h>
#include "Creator.h"

typedef struct ConcreteCreatorA {
    Creator base_creator;
} ConcreteCreatorA;

ConcreteCreatorA* new_creatorA ();
void     creatorA_destroy (ConcreteCreatorA* __this);
void     creatorA_info    (ConcreteCreatorA* __this);
Product* factoryA         (ConcreteCreatorA* __this);


typedef struct ConcreteCreatorB {
    Creator base_creator;
} ConcreteCreatorB;

ConcreteCreatorB* new_creatorB ();
void     creatorB_destroy (ConcreteCreatorB* __this);
void     creatorB_info (ConcreteCreatorB* __this);
Product* factoryB (ConcreteCreatorB* __this);

#endif /* CONCRETE_CREATOR_H_INCLUDED */