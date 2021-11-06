#ifndef PB_PROPERTY_H
#define PB_PROPERTY_H

#include<malloc.h>
#include "../typedefs.h"

typedef struct Property Property;

/**
 * Creates a new property with the specified id
 * @param field_id The id of the field
 */
Property* newProperty(uint64 field_id);

/**
 * Disposes of the property
 * @param property The property to destroy
 */
void disposeOfProperty(Property* property);

/**
 * Sets the next property for the specified one
 * @param this_property The altered property
 * @param next_property The next property
 */
void setNextProperty(Property* this_property, Property* next_property);

#endif