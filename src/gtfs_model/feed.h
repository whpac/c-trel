#ifndef GTFSMODEL_FEED_H
#define GTFSMODEL_FEED_H

#include "../typedefs.h"

typedef struct FeedMessage {
    struct FeedHeader* header;
    struct FeedEntity* entity; // []
    int entityCount;
} FeedMessage;

typedef struct FeedHeader {
    char* gtfsVersion;
    int incrementality;
    uint64 timestamp;
} FeedHeader;

typedef struct FeedEntity {
    char* id;
    char isDeleted;
    struct VehiclePosition* vehiclePosition;
    struct FeedEntity* next;
} FeedEntity;

typedef struct VehiclePosition {
    struct TripDescriptor* trip;
    struct VehicleDescriptor* vehicle;
    struct Position* position;
    uint32 currentStopSeq;
    char* stopId;
    int currentStatus;
    uint64 timestamp;
} VehiclePosition;

typedef struct TripDescriptor {
    char* tripId;
    char* routeId;
    int directionId;
    char* startTime;
    char* startDate;
    int scheduleRelationship;
} TripDescriptor;

struct VehicleDescriptor {
    char* id;
    char* label;
    char* licensePlate;
};

struct Position {
    float latitude;
    float longitude;
    float bearing;
    double odometer;
    float speed;
};

#endif