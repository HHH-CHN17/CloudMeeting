#pragma once

#include <QObject>
#include <QAudioInput>
#include <QIODevice>
//录音功能，与摄像头camera一起使用，不过camera在qt里面自带，所以不需要写camera的源码
class AudioInput : public QObject
{
	Q_OBJECT
private:
	QAudioInput *audio;
	QIODevice* inputdevice;
	char* recvbuf;
public:
	AudioInput(QObject *par = 0);
	~AudioInput();
private slots:
	void onreadyRead();
	void handleStateChanged(QAudio::State);
	QString errorString();
	void setVolumn(int);
public slots:
	void startCollect();
	void stopCollect();
signals:
	void audioinputerror(QString);
};
