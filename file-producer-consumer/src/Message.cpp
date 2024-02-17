//
// Created by mick on 2/17/24.
//

#include "../include/Message.h"

Message::Message(pid_t pid, std::string &payload) : pid(pid), payload(payload) {}
