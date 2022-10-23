#ifndef CREATOR_H_INCLUDED
#define CREATOR_H_INCLUDED

#include <stdio.h>
#include "Products.h"

typedef struct Vtable_creator {
    void     (*destroy_creator)  (void *);
    void     (*get_info)         (void *);
    Product* (*factory)          (void *);
    // char*    (*operation)        (void *);
} creator_vtable;

typedef struct Creator {
    char creator_name[50];
    creator_vtable *vtable;
    // Creator* __this;

    // void     (*destroy_creator) (Creator* __this);
    // void     (*create_creator)  (Creator* __this);
    // void     (*get_info)        (Creator* __this);
    // Product* (*factory)         (Creator* __this);
    // char*    (*operation)       (void* __this);
} Creator;

char* operation (Creator* creator);

#endif /* CREATOR_H_INCLUDED */