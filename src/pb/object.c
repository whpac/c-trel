#include "object.h"

struct Object {
    struct Property* firstProperty;
};

Object* newObject(){
    return (Object*)getMemory(sizeof(Object));
}

void disposeOfObject(Object* object){
    freeMemory(object);
}

void addPropertyToObject(Object* object, Property* property){
    Property* first_prop = object->firstProperty;
    setNextProperty(property, first_prop);
    object->firstProperty = property;
}

Property* getObjectFirstProperty(Object* object){
    return object->firstProperty;
}