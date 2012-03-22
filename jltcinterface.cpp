#include <QAudio>
#include <QtCore>
#include "jltcinterface.h"
#define FPS_NUM 25
#define FPS_DEN 1
#define BUFFER_SIZE 256
#define DF_DELIMITER ';' // drop frame timecode frame delimiter
#define NDF_DELIMITER ':' // non-drop frame timecode frame delimiter

SmpteLTCDecodeInterface::SmpteLTCDecodeInterface(QObject *parent) :
    QObject(parent)
{
    QAudioFormat format;
    // set up the format you want, eg.
    format.setFrequency(44100);
    format.setChannels(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning()<<"default format not supported try to use nearest";
        format = info.nearestFormat(format);
    }

    input = new QAudioInput(format, this);

    inputIO = input->start();
    connect(inputIO, SIGNAL(readyRead()), this, SLOT(readyRead()));
    FrameRate *fps;
    decoder = SMPTEDecoderCreate(format.sampleRate(),(fps=FR_create(FPS_NUM,FPS_DEN,FRF_NONE)),16,1);
    totalPos=0;
}
SmpteLTCDecodeInterface::~SmpteLTCDecodeInterface(){

}
void SmpteLTCDecodeInterface::readyRead(){
    SMPTEFrameExt frame;
    int errors;
    //if(inputIO->bytesAvailable()){//FIXME: Is it enough data avialable, or do we need a specific buffer size?
    QByteArray data = inputIO->readAll();
//    printf("GOTDATA%d\n", data.size());
    if(data.size()){
        SMPTEDecoderWrite(decoder, (sample_t*)data.constData(), data.size()/sizeof(sample_t), totalPos);
        totalPos+=data.size();
        if (SMPTEDecoderRead(decoder, &frame)) { // use while isteadof if here, if we want to process all packets
                               SMPTETime stime;
                               int ms;

                               SMPTEFrameToTime(&frame.base, &stime);
                               SMPTEDecoderFrameToMillisecs(decoder, &frame, &ms);
                               SMPTEDecoderErrors(decoder, &errors);
                               emit timeRecieved(stime);
                               QMap<QString,QVariant> mtime;
/*                               mtime["years"] = QVariant(stime.years);
                               mtime["months"] = QVariant(stime.months);
                               mtime["days"] = QVariant(stime.days);*/
                               mtime["hours"] = QVariant(stime.hours);
                               mtime["mins"] = QVariant(stime.mins);
                               mtime["secs"] = QVariant(stime.secs);
                               mtime["frame"] = QVariant(stime.frame);
                               mtime["startpos"] = QVariant((qulonglong)frame.startpos);
                               mtime["endpos"] = QVariant((qulonglong)frame.endpos);
                               mtime["delayed"] = QVariant(frame.delayed);
                               mtime["ms"]    = QVariant(ms);
                               QVariant qvtime;
                               emit timeRecieved(QVariant(mtime), QVariant(0));
                               emit timeRecieved(ms);

/*                               printf("%02d:%02d:%02d%c%02d %8d %8lu %8lu %4d\n",
                                          stime.hours, stime.mins,
                                          stime.secs,
                                          (frame.base.dfbit) ? DF_DELIMITER : NDF_DELIMITER,
                                          stime.frame,
                                          ms,                          // Timecode in milliseconds
                                          //total,                     // First sample of the current buffer
                                          frame.startpos,      // First sample of the LTC frame
                                          frame.endpos,        // Last(!) sample of the LTC frame
                                          //frame.endpos - ((ms - TEST_N_DEBUG_MS_OFFSET) * sampleRate / 1000), // TEST'n'DEBUG
                                          errors                       // Error count
                                          );*/

//                               prevRead = frame.endpos;
                       }
      
    }else{
        printf("RDRd%d\n", data.length());
    }
}
