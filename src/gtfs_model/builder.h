#ifndef GTFS_MODEL_BUILDER_H
#define GTFS_MODEL_BUILDER_H

#include "feed.h"
#include "../pb/object.h"

FeedMessage* buildFeedMessage(Object* obj);

FeedHeader* buildFeedHeader(Object* obj);

FeedEntity* buildFeedEntity(Object* obj);

#endif