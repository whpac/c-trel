#include "property.h"

struct Property {
    uint64 fieldId;
    uint64 valueSize;
    void* value;
    Property* nextProperty;
};

Property* newProperty(uint64 field_id){
    Property* prop = (Property*)malloc(sizeof(Property));

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

void setPropertyValue(Property* property, void* value, uint64 value_size){
    property->value = value;
    property->valueSize = value_size;
}

uint64 getPropertyFieldId(Property* property){
    return property->fieldId;
}

uint64 getPropertyValueSize(Property* property){
    return property->valueSize;
}

void* getPropertyValue(Property* property){
    return property->value;
}

Property* getNextProperty(Property* property){
    return property->nextProperty;
}