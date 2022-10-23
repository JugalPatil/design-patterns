#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ConcreteProducts.h"

product_vtable ConcreteProductA_vtable = {
    (void (*)(void *)) productA_destroy,
    (void (*)(void *)) productA_info
};

ConcreteProductA* new_productA () {
    ConcreteProductA *prodA = malloc(sizeof(ConcreteProductA));
    strncpy(prodA->base_product.product_name, "ProductA", 50);
    prodA->base_product.vtable = &ConcreteProductA_vtable;
    return prodA;
}

void productA_destroy (ConcreteProductA* __this) {
    printf("deleting product A");
    free(__this);
}

void productA_info (ConcreteProductA* __this) {
    printf("Product info from prod A : %s \n", __this->base_product.product_name);
}

product_vtable ConcreteProductB_vtable = {
    (void (*)(void *)) productB_destroy,
    (void (*)(void *)) productB_info
};

ConcreteProductB* new_productB () {
    ConcreteProductB *prodB = malloc(sizeof(ConcreteProductB));
    strncpy(prodB->base_product.product_name, "ProductB", 50);
    prodB->base_product.vtable = &ConcreteProductB_vtable;
    return prodB;
}

void productB_destroy (ConcreteProductB* __this) {
    printf("deleting product B");
    free(__this);
}

void productB_info (ConcreteProductB* __this) {
    printf("Product info from prod B : %s \n", __this->base_product.product_name);
}


