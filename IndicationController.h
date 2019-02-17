#ifndef INDICATIONCONTROLLER_H
#define INDICATIONCONTROLLER_H

#include <memory>
#include <map>

#include <QColor>

class Diod;

namespace indicationEmulator
{

enum class EventType;

struct States
{
    bool mainPower;
    bool usbPower;
    bool usbDataExchange;
    bool activeError;
    bool unacknowledgeError;
};

struct Property
{
    QColor color;
    int enableTime;
    int disableTimme;
};

bool operator<(const States& lhs, const States& rhs);

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
    std::map<EventType, Property> m_properties;
    std::shared_ptr<Diod> m_diod;    
    States m_states;
};

} // indicationEmulator

#endif // INDICATIONCONTROLLER_H
