#include "Products.h"

void Product_destroy (Product* prod) {
    prod->vtable->destroy_product(prod);
}

void Product_info (Product* prod) {
    prod->vtable->get_info(prod);
}
