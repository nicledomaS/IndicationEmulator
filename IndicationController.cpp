#include "IndicationController.h"
#include "Diod.h"

namespace segnetics
{

IndicationController::IndicationController(std::shared_ptr<Diod> diod)
    : m_diod(std::move(diod)),
      m_mainPower(false),
      m_usbPower(false),
      m_usbDataExchange(false),
      m_activeError(false),
      m_unacknowledgeError(false)
{

}

void IndicationController::setMainPower(bool value)
{
    m_mainPower = value;
}

void IndicationController::setUsbPower(bool value)
{
    m_usbPower = value;
}

void IndicationController::setUsbDataExchange(bool value)
{
    m_usbDataExchange = value;
}

void IndicationController::setActiveError(bool value)
{
    m_activeError = value;
}

void IndicationController::setUnacknowledgeError(bool value)
{
    m_unacknowledgeError = value;
}

void IndicationController::update()
{
    if(m_activeError)
    {
        m_diod->setColor(QColor(Qt::red));
        m_diod->startBlink(10, 100);
    }
    else if(m_unacknowledgeError)
    {
        m_diod->setColor(QColor(Qt::red));
        m_diod->startBlink(10, 1000);
    }
    else if(m_usbDataExchange)
    {
        m_diod->setColor(QColor(Qt::green));
        m_diod->startBlink(10, 100);
    }
    else if(m_mainPower)
    {
        m_diod->stopBlink();
        m_diod->setColor(QColor(Qt::blue));
        m_diod->setEnable(true);
    }
    else if(m_usbPower)
    {
        m_diod->stopBlink();
        m_diod->setColor(QColor(Qt::green));
        m_diod->setEnable(true);
    }
    else
    {
        m_diod->stopBlink();
        m_diod->setEnable(false);
    }
}

} // segnetics
