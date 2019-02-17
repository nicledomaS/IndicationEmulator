#include "IndicationController.h"
#include "Diod.h"
#include "Event.h"

namespace indicationEmulator
{

namespace
{

EventType getKey(const States& states)
{
    if(states.activeError)
    {
        return EventType::ActiveError;
    }
    else if(states.unacknowledgeError)
    {
        return EventType::UnacknowledgeError;
    }
    else if(states.usbDataExchange)
    {
        return EventType::UsbDataExchange;
    }
    else if(states.mainPower)
    {
        return EventType::MainPower;
    }
    else if(states.usbPower)
    {
        return EventType::UsbPower;
    }
    else
    {
        return EventType::Unknown;
    }
}

} // anonymous

IndicationController::IndicationController(std::shared_ptr<Diod> diod)
    : m_properties({
            {EventType::MainPower, {QColor(Qt::blue), 0, 0}},
            {EventType::UsbPower, {QColor(Qt::green), 0, 0}},
            {EventType::UsbDataExchange, {QColor(Qt::green), 10, 100}},
            {EventType::ActiveError, {QColor(Qt::red), 10, 100}},
            {EventType::UnacknowledgeError, {QColor(Qt::red), 10, 1000}}}),
      m_diod(std::move(diod)),
      m_states({false, false, false, false, false})
{

}

void IndicationController::setMainPower(bool value)
{
    m_states.mainPower = value;
}

void IndicationController::setUsbPower(bool value)
{
    m_states.usbPower = value;
}

void IndicationController::setUsbDataExchange(bool value)
{
    m_states.usbDataExchange = value;
}

void IndicationController::setActiveError(bool value)
{
    m_states.activeError = value;
}

void IndicationController::setUnacknowledgeError(bool value)
{
    m_states.unacknowledgeError = value;
}

void IndicationController::update()
{
    auto it = m_properties.find(getKey(m_states));

    if(it == m_properties.end())
    {
        m_diod->stopBlink();
        m_diod->setEnable(false);
    }
    else
    {
        auto property = it->second;
        m_diod->setColor(property.color);

        if(property.enableTime == 0 && property.disableTimme == 0)
        {
            m_diod->stopBlink();
            m_diod->setEnable(true);
        }
        else
        {
            m_diod->startBlink(property.enableTime, property.disableTimme);
        }
    }
}

} // indicationEmulator
