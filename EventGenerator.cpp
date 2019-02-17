#include "EventGenerator.h"
#include "Handler.h"
#include "Event.h"

EventGenerator::EventGenerator(std::shared_ptr<segnetics::Handler> handler, QObject *parent)
    : QObject(parent),
      m_handler(std::move(handler))
{

}

void EventGenerator::eventMainPower(bool value)
{
    m_handler->handle(std::make_shared<segnetics::Event>(segnetics::EventType::MainPower, value));
}

void EventGenerator::eventUsbPower(bool value)
{
    m_handler->handle(std::make_shared<segnetics::Event>(segnetics::EventType::UsbPower, value));
}

void EventGenerator::eventUsbDataExchange(bool value)
{
    m_handler->handle(std::make_shared<segnetics::Event>(segnetics::EventType::UsbDataExchange, value));
}

void EventGenerator::eventActiveError(bool value)
{
    m_handler->handle(std::make_shared<segnetics::Event>(segnetics::EventType::ActiveError, value));
}

void EventGenerator::eventUnacknowledgeError(bool value)
{
    m_handler->handle(std::make_shared<segnetics::Event>(segnetics::EventType::UnacknowledgeError, value));
}
