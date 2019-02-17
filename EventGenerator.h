#ifndef EVENTGENERATOR_H
#define EVENTGENERATOR_H

#include <memory>

#include <QObject>

namespace segnetics
{

class Handler;

}

class EventGenerator : public QObject
{
    Q_OBJECT

public:
    explicit EventGenerator(std::shared_ptr<segnetics::Handler> handler, QObject *parent = nullptr);

public slots:
    void eventMainPower(bool value);
    void eventUsbPower(bool value);
    void eventUsbDataExchange(bool value);
    void eventActiveError(bool value);
    void eventUnacknowledgeError(bool value);

private:
    bool m_mainPower;
    std::shared_ptr<segnetics::Handler> m_handler;
};

#endif // EVENTGENERATOR_H
