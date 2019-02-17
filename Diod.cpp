#include <QTimer>

#include "Diod.h"

Diod::Diod(QObject *parent)
    : QObject(parent),
      m_color(Qt::gray),
      m_enable(false),
      m_blinkEnable(false)
{

}

void Diod::setColor(const QColor &color)
{
    m_color = color;
    emit dataChanged();
}

QColor Diod::color() const
{
    return m_color;
}

void Diod::setEnable(bool enable)
{
    if(m_enable == enable)
    {
        return;
    }
    m_enable = enable;
    emit dataChanged();
}

bool Diod::isEnabled() const
{
    return m_enable;
}

void Diod::startBlink(int enT, int dT)
{
    m_enT = enT;
    m_dT = dT;
    if(!m_blinkEnable)
    {
        m_blinkEnable = true;
        blink();
    }
}

void Diod::stopBlink()
{
    m_blinkEnable = false;
}

void Diod::blink()
{
    if(m_blinkEnable)
    {
        setEnable(true);
        QTimer::singleShot(m_enT, [this]()
        {
            setEnable(false);
            QTimer::singleShot(m_dT, [this]()
            {
                blink();
            });
        });
    }
}
