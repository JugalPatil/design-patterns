#include <stdio.h>
#include <string.h>
#include "Creator.h"

void Creator_destroy (Creator* creator) {
    creator->vtable->destroy_creator(creator);
}

void Creator_info (Creator* creator) {
    creator->vtable->get_info(creator);
}

Product* factory_method (Creator* creator) {
    creator->vtable->factory(creator);
}

char* operation (Creator* creator) {
    //CONCATENATE STRINGS
    Product* curr_prod = factory_method(creator);
    strncat(creator->creator_name, curr_prod->product_name, 50);

    return creator->creator_name;
}