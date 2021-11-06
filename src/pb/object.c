#include "object.h"

struct Object {
    struct Property* firstProperty;
};

Object* newObject(){
    return (Object*)malloc(sizeof(Object));
}

void disposeOfObject(Object* object){
    free(object);
}

void addPropertyToObject(Object* object, Property* property){
    Property* first_prop;
    setNextProperty(property, first_prop);
    object->firstProperty = property;
}

Property* getObjectFirstProperty(Object* object){
    return object->firstProperty;
}