#ifndef EVENT_H
#define EVENT_H

namespace segnetics
{

enum class EventType : int
{
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

} // segnetics

#endif // EVENT_H
