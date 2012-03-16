#ifndef JLTCINTERFACE_H
#define JLTCINTERFACE_H

#include <QObject>
#include <QVariant>
#include <QAudioInput>
extern "C"{
#include <ltcsmpte/ltcsmpte.h>
#include <stdint.h>
}
class SmpteLTCDecodeInterface : public QObject
{
    Q_OBJECT
public:
    explicit SmpteLTCDecodeInterface(QObject *parent = 0);
    ~SmpteLTCDecodeInterface();

signals:
    void timeRecieved(SMPTETime time);
    void timeRecieved(QVariant time);
    void timeRecieved(int time);
public slots:
   void readyRead();
protected:
    QAudioInput* input;
    QIODevice* inputIO;
    SMPTEDecoder* decoder;
    uint64_t totalPos;
};

#endif // JLTCINTERFACE_H
