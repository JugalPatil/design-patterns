#ifndef CONCRETE_PRODUCTS_H_INCLUDED
#define CONCRETE_PRODUCTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Products.h"

typedef struct ConcreteProductA {
    Product base_product;
} ConcreteProductA;

ConcreteProductA* new_productA ();
void productA_destroy (ConcreteProductA* __this);
void productA_info (ConcreteProductA* __this);

typedef struct ConcreteProductB {
    Product base_product;
} ConcreteProductB;

ConcreteProductB* new_productB ();
void productB_destroy(ConcreteProductB* __this);
void productB_info(ConcreteProductB* __this);

#endif /* CONCRETE_PRODUCTS_H_INCLUDED */


