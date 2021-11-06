#include "object.h"

struct Object {
    struct Property* firstProperty;
};

Object* newObject(){
    return malloc(sizeof(Object));
}

void disposeOfObject(Object* object){
    free(object);
}

void addProperty(Object* object, Property* property){
    Property* first_prop;
    setNextProperty(property, first_prop);
    object->firstProperty = property;
}