#ifndef PB_PROPERTY_H
#define PB_PROPERTY_H

#include "../memory/allocator.h"
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

/**
 * Sets value for the given property
 * @param property The property for which set the value
 * @param value A pointer to the value
 * @param value_size Size of the value in bytes
 */
void setPropertyValue(Property* property, void* value, uint64 value_size);

/**
 * Returns the field id of the property
 * @param property The property
 */
uint64 getPropertyFieldId(Property* property);

/**
 * Returns the size of the value stored in the property
 * @param property The property
 */
uint64 getPropertyValueSize(Property* property);

/**
 * Returns the value stored in the property
 * @param property The property
 */
void* getPropertyValue(Property* property);

/**
 * Returns the next property for an object.
 * @param property The current property
 */
Property* getNextProperty(Property* property);

#endif