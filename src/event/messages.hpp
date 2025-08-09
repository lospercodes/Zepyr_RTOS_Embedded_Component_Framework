#ifndef MESSAGES_H
#define MESSAGES_H

// Message types enum for identification
typedef enum {
    MSG_TEMPERATURE = 1,
    MSG_IMU = 2,
    MSG_ALARM = 3,
    MSG_TIMER = 4,
    MSG_TIMING_EVENT = 5
}MessageType_t;

// Simple message structure - no inheritance, no virtual functions
struct Message {
    MessageType_t type;
    union {
        bool alarm_state;
        struct {
            void* data;
            int data_type;
        } event_data;
    } payload;
};

#endif