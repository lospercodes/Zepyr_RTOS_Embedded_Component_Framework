#pragma once

#include <unordered_map>
#include <unordered_map>
#include <string>
#include <mutex>
#include <shared_mutex>

enum class EventType {
    TEMP_HUMIDITY_DATA,
    ALTIMETER_DATA
};

struct Event {
    EventType type;
    char payload[64];
};

