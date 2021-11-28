#include "builder.h"
#include "string.h"
#include "../memory/allocator.h"
#include "../pb/parser.h"

FeedMessage* buildFeedMessage(Object* obj){
    FeedMessage* msg = getMemory(sizeof(FeedMessage));
    msg->entity = NULL;
    msg->entityCount = 0;

    Property* p = getObjectFirstProperty(obj);
    while(p != NULL){
        uint64 id = getPropertyFieldId(p);
        uint64 sz = getPropertyValueSize(p);
        void* value = getPropertyValue(p);

        switch(id){
            case 1: {
                Object* header_obj = readObjectFromStream(value, sz);
                msg->header = buildFeedHeader(header_obj);
                break;
            }
            case 2: {
                Object* entity_obj = readObjectFromStream(value, sz);
                FeedEntity* entity = buildFeedEntity(entity_obj);
                entity->next = msg->entity;
                msg->entity = entity;
                msg->entityCount++;
                break;
            }
        }

        // freeMemory(v);
        Property* p2 = getNextProperty(p);
        disposeOfProperty(p);
        p = p2;
    }

    disposeOfObject(obj);
    return msg;
}

FeedHeader* buildFeedHeader(Object* obj){
    FeedHeader* hdr = getMemory(sizeof(FeedHeader));
    Property* p = getObjectFirstProperty(obj);
    while(p != NULL){
        uint64 id = getPropertyFieldId(p);
        uint64 sz = getPropertyValueSize(p);
        void* value = getPropertyValue(p);

        switch(id){
            case 1:
                hdr->gtfsVersion = getMemory(sz);
                memcpy(hdr->gtfsVersion, value, sz);
                break;
            case 2:
                hdr->incrementality = *((int*)value);
                break;
            case 3:
                hdr->timestamp = *((uint64*)value);
                break;
        }

        // freeMemory(v);
        Property* p2 = getNextProperty(p);
        disposeOfProperty(p);
        p = p2;
    }

    disposeOfObject(obj);
    return hdr;
}

FeedEntity* buildFeedEntity(Object* obj){
    FeedEntity* entity = getMemory(sizeof(FeedEntity));
    entity->next = NULL;
    Property* p = getObjectFirstProperty(obj);
    while(p != NULL){
        uint64 id = getPropertyFieldId(p);
        uint64 sz = getPropertyValueSize(p);
        void* value = getPropertyValue(p);

        switch(id){
            case 1:
                entity->id = getMemory(sz);
                memcpy(entity->id, value, sz);
                break;
            case 2:
                entity->isDeleted = *((char*)value);
                break;
            case 4:
                //entity->vehiclePosition = *((uint64*)value);
                break;
        }

        // freeMemory(v);
        Property* p2 = getNextProperty(p);
        disposeOfProperty(p);
        p = p2;
    }

    disposeOfObject(obj);
    return entity;
}