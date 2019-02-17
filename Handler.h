#ifndef HANDLER_H
#define HANDLER_H

#include <memory>

namespace indicationEmulator
{

class Event;

class Handler
{
public:
    virtual ~Handler() = default;

    virtual void handle(std::shared_ptr<Event> event) = 0;
};

} // indicationEmulator

#endif // HANDLER_H
