#include "builder.h"
#include "string.h"
#include "../memory/allocator.h"
#include "../pb/parser.h"

FeedMessage* buildFeedMessage(Object* obj){
    FeedMessage* msg = getMemory(sizeof(FeedMessage));
    msg->header = NULL;
    msg->entity = NULL;
    msg->entityCount = 0;

    Property* p;
    while(NULL != (p = getObjectFirstProperty(obj))){
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

        removeObjectFirstProperty(obj);
    }

    disposeOfObject(obj);
    return msg;
}

FeedHeader* buildFeedHeader(Object* obj){
    FeedHeader* hdr = getMemory(sizeof(FeedHeader));
    hdr->gtfsVersion = NULL;

    Property* p;
    while(NULL != (p = getObjectFirstProperty(obj))){
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

        removeObjectFirstProperty(obj);
    }

    disposeOfObject(obj);
    return hdr;
}

FeedEntity* buildFeedEntity(Object* obj){
    FeedEntity* entity = getMemory(sizeof(FeedEntity));
    entity->id = NULL;
    entity->vehiclePosition = NULL;
    entity->next = NULL;

    Property* p;
    while(NULL != (p = getObjectFirstProperty(obj))){
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
            case 4: {
                Object* vehicle_position_obj = readObjectFromStream(value, sz);
                entity->vehiclePosition = buildVehiclePosition(vehicle_position_obj);
                break;
            }
        }

        removeObjectFirstProperty(obj);
    }

    disposeOfObject(obj);
    return entity;
}

VehiclePosition* buildVehiclePosition(Object* obj){
    VehiclePosition* vp = getMemory(sizeof(VehiclePosition));
    vp->trip = NULL;
    vp->position = NULL;
    vp->vehicle = NULL;
    vp->stopId = NULL;

    Property* p;
    while(NULL != (p = getObjectFirstProperty(obj))){
        uint64 id = getPropertyFieldId(p);
        uint64 sz = getPropertyValueSize(p);
        void* value = getPropertyValue(p);

        switch(id){
            case 1: {
                Object* trip_descriptor_obj = readObjectFromStream(value, sz);
                vp->trip = buildTripDescriptor(trip_descriptor_obj);
                break;
            }
            case 2:
                vp->position = NULL;
                break;
            case 3:
                vp->currentStopSeq = *(uint32*)value;
                break;
            case 4:
                vp->currentStatus = *(uint32*)value;
                break;
            case 5:
                vp->timestamp = *(uint64*)value;
                break;
            case 7:
                vp->stopId = getMemory(sz);
                memcpy(vp->stopId, value, sz);
                break;
            case 8:
                vp->vehicle = NULL;
                break;
        }

        removeObjectFirstProperty(obj);
    }

    disposeOfObject(obj);
    return vp;
}

TripDescriptor* buildTripDescriptor(Object* obj){
    TripDescriptor* td = getMemory(sizeof(TripDescriptor));
    td->tripId = NULL;
    td->routeId = NULL;
    td->startDate = NULL;
    td->startTime = NULL;

    Property* p;
    while(NULL != (p = getObjectFirstProperty(obj))){
        uint64 id = getPropertyFieldId(p);
        uint64 sz = getPropertyValueSize(p);
        void* value = getPropertyValue(p);

        switch(id){
            case 1:
                td->tripId = getMemory(sz);
                memcpy(td->tripId, value, sz);
                break;
            case 2:
                td->startTime = getMemory(sz);
                memcpy(td->startTime, value, sz);
                break;
            case 3:
                td->startDate = getMemory(sz);
                memcpy(td->startDate, value, sz);
                break;
            case 4:
                td->scheduleRelationship = *(int*)value;
                break;
            case 5:
                td->routeId = getMemory(sz);
                memcpy(td->routeId, value, sz);
                break;
            case 6:
                td->directionId = *(uint32*)value;
                break;
        }

        removeObjectFirstProperty(obj);
    }

    disposeOfObject(obj);
    return td;
}