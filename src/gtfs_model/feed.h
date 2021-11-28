#ifndef GTFSMODEL_FEED_H
#define GTFSMODEL_FEED_H

typedef struct FeedMessage {
    struct FeedHeader* header;
    struct FeedEntity* entity; // []
    int entityCount;
} FeedMessage;

typedef struct FeedHeader {
    char* gtfsVersion;
    int incrementality;
    long long timestamp;
} FeedHeader;

typedef struct FeedEntity {
    char* id;
    char isDeleted;
    struct VehiclePosition* vehiclePosition;
    struct FeedEntity* next;
} FeedEntity;

struct VehiclePosition {
    struct TripDescriptor* trip;
    struct VehicleDescriptor* vehicle;
    struct Position* position;
    int currentStopSeq;
    char* stopId;
    int currentStatus;
    long long timestamp;
};

struct TripDescriptor {
    char* tripId;
    char* routeId;
    int directionId;
    char* startTime;
    char* startDate;
    int scheduleRelationship;
};

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