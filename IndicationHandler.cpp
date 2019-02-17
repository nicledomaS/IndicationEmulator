#include "IndicationHandler.h"

#include "Event.h"
#include "IndicationController.h"

namespace segnetics
{

std::shared_ptr<Handler> createHandler(const std::shared_ptr<IndicationController>& controller)
{
    auto handler = std::make_shared<IndicationHandler>();
    handler->processorRegistration(EventType::MainPower, [controller](bool enable)
    {
        controller->setMainPower(enable);
        controller->update();
    });
    handler->processorRegistration(EventType::UsbPower, [controller](bool enable)
    {
        controller->setUsbPower(enable);
        controller->update();
    });
    handler->processorRegistration(EventType::UsbDataExchange, [controller](bool enable)
    {
        controller->setUsbDataExchange(enable);
        controller->update();
    });
    handler->processorRegistration(EventType::ActiveError, [controller](bool enable)
    {
        controller->setActiveError(enable);
        controller->update();
    });
    handler->processorRegistration(EventType::UnacknowledgeError, [controller](bool enable)
    {
        controller->setUnacknowledgeError(enable);
        controller->update();
    });

    return std::move(handler);
}

void IndicationHandler::processorRegistration(EventType type, Function func)
{
    processors.insert({type, func});
}

void IndicationHandler::handle(std::shared_ptr<Event> event)
{
    auto it = processors.find(event->type());
    if(it != processors.end())
    {
        auto func = it->second;
        func(event->state());
    }
}

} // segnetics
