#ifndef INDICATIONCONTROLLER_H
#define INDICATIONCONTROLLER_H

#include <memory>

class Diod;

namespace segnetics
{

class IndicationController
{
public:
    explicit IndicationController(std::shared_ptr<Diod> diod);

    void setMainPower(bool value);
    void setUsbPower(bool value);
    void setUsbDataExchange(bool value);
    void setActiveError(bool value);
    void setUnacknowledgeError(bool value);

    void update();

private:
    std::shared_ptr<Diod> m_diod;
    bool m_mainPower;
    bool m_usbPower;
    bool m_usbDataExchange;
    bool m_activeError;
    bool m_unacknowledgeError;
    bool m_enabled;
};

} // segnetics

#endif // INDICATIONCONTROLLER_H
