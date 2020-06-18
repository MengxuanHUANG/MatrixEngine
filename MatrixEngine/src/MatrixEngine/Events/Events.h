#pragma once
#include "Event.h"
#include "ApplicationEvents.h"
#include "MouseEvents.h"
#include "KeyBoardEvents.h"

#define MX_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)