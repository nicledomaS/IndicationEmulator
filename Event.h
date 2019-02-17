#ifndef EVENT_H
#define EVENT_H

namespace indicationEmulator
{

enum class EventType : int
{
    Unknown,
    MainPower,
    UsbPower,
    UsbDataExchange,
    ActiveError,
    UnacknowledgeError
};

class Event
{
public:
    Event(EventType type, bool state);

    EventType type() const;
    bool state() const;

private:
    EventType m_type;
    bool m_state;
};

} // indicationEmulator

#endif // EVENT_H
