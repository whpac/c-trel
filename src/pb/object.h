#ifndef PB_OBJECT_H
#define PB_OBJECT_H

#include<malloc.h>
#include "../typedefs.h"
#include "property.h"

typedef struct Object Object;

/**
 * Creates a new object
 */
Object* newObject();

/**
 * Disposes of the object
 * @param object The object to destroy
 */
void disposeOfObject(Object* object);

/**
 * Adds a property to the object. The new one is inserted at the front of the list.
 * @param object The object to add the property to
 * @param property The property to add
 */
void addPropertyToObject(Object* object, Property* property);

/**
 * Returns the first property of an object
 * @param object The object
 */
Property* getObjectFirstProperty(Object* object);

#endif