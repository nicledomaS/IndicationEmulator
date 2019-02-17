#ifndef DIOD_H
#define DIOD_H

#include <QObject>
#include <QColor>

class Diod : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color CONSTANT)
    Q_PROPERTY(bool enabled READ isEnabled CONSTANT)

public:
    explicit Diod(QObject *parent = nullptr);

    void setColor(const QColor& color);
    QColor color() const;

    void setEnable(bool enable);
    bool isEnabled() const;


    void startBlink(int enT, int dT);
    void stopBlink();

signals:
    void dataChanged();

private:
    void blink();

private:
    QColor m_color;
    bool m_enable;
    bool m_blinkEnable;
    int m_enT;
    int m_dT;
};

#endif // DIOD_H
