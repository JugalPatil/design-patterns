#ifndef PRODUCTS_H_INCLUDED
#define PRODUCTS_H_INCLUDED

#include <stdio.h>

typedef struct Vtable_product {
    void (*destroy_product) (void *);
    void (*get_info)        (void *);
} product_vtable;

typedef struct Product {
    char product_name[50];
    product_vtable *vtable;
    // Product* __this;

    // void (*destory_product) (Product* __this);
    // int  (*create_product)  (Product* __this);
    // void (*get_info)        (Product* __this);
} Product;

void Product_destroy (Product* prod); 
// {
//     prod->vtable->destroy_product(prod);
// }

void Product_info (Product* prod); 
// {
//     prod->vtable->get_info(prod);
// }

#endif /* PRODUCTS_H_INCLUDED */