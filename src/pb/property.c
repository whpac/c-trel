#include "property.h"

struct Property {
    uint64 fieldId;
    uint64 valueSize;
    byte* value;
    Property* nextProperty;
};

Property* newProperty(uint64 field_id){
    Property* prop = malloc(sizeof(Property));

    prop->fieldId = field_id;
    prop->valueSize = 0;
    prop->value = NULL;
    prop->nextProperty = NULL;

    return prop;
}

void disposeOfProperty(Property* property){
    free(property);
}

void setNextProperty(Property* this_property, Property* next_property){
    this_property->nextProperty = next_property;
}