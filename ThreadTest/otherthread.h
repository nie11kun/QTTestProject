#ifndef OTHERTHREAD_H
#define OTHERTHREAD_H

#include <QObject>

class OtherThread : public QObject
{
    Q_OBJECT
public:
    explicit OtherThread(QObject *parent = nullptr);

public slots:
    void function();

signals:

};

#endif // OTHERTHREAD_H
