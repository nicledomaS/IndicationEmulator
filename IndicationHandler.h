#ifndef INDICATIONHANDLER_H
#define INDICATIONHANDLER_H

#include <map>
#include <functional>

#include "Handler.h"

namespace indicationEmulator
{

class IndicationController;
enum class EventType;

using Function = std::function<void(bool)>;

class IndicationHandler : public Handler
{
public:
    void processorRegistration(EventType type, Function func);
    void handle(std::shared_ptr<Event> event);

private:
    std::map<EventType, Function> processors;
};

std::shared_ptr<Handler> createHandler(const std::shared_ptr<IndicationController>& controller);

} // indicationEmulator

#endif // INDICATIONHANDLER_H
