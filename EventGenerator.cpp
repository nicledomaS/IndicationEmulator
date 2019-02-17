#include "EventGenerator.h"
#include "Handler.h"
#include "Event.h"

EventGenerator::EventGenerator(std::shared_ptr<indicationEmulator::Handler> handler, QObject *parent)
    : QObject(parent),
      m_handler(std::move(handler))
{

}

void EventGenerator::eventMainPower(bool value)
{
    m_handler->handle(std::make_shared<indicationEmulator::Event>(indicationEmulator::EventType::MainPower, value));
}

void EventGenerator::eventUsbPower(bool value)
{
    m_handler->handle(std::make_shared<indicationEmulator::Event>(indicationEmulator::EventType::UsbPower, value));
}

void EventGenerator::eventUsbDataExchange(bool value)
{
    m_handler->handle(std::make_shared<indicationEmulator::Event>(indicationEmulator::EventType::UsbDataExchange, value));
}

void EventGenerator::eventActiveError(bool value)
{
    m_handler->handle(std::make_shared<indicationEmulator::Event>(indicationEmulator::EventType::ActiveError, value));
}

void EventGenerator::eventUnacknowledgeError(bool value)
{
    m_handler->handle(std::make_shared<indicationEmulator::Event>(indicationEmulator::EventType::UnacknowledgeError, value));
}
