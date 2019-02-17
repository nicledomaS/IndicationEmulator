#ifndef HANDLER_H
#define HANDLER_H

#include <memory>

namespace segnetics
{

class Event;

class Handler
{
public:
    virtual ~Handler() = default;

    virtual void handle(std::shared_ptr<Event> event) = 0;
};

} // segnetics

#endif // HANDLER_H
