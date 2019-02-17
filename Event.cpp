#include "Event.h"

namespace indicationEmulator
{

Event::Event(EventType type, bool state)
    : m_type(type),
      m_state(state)
{

}

EventType Event::type() const
{
    return m_type;
}

bool Event::state() const
{
    return m_state;
}

} // indicationEmulator
