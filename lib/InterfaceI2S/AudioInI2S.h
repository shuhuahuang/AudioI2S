#ifndef _AUDIO_IN_I2S_CLASS_H_INCLUDED
#define _AUDIO_IN_I2S_CLASS_H_INCLUDED

#include "AudioIn.h"
#include <I2S_SCK.h>
#include "ConstantsSound.h"

class AudioInI2SClass : public AudioIn
{
public:
  AudioInI2SClass();
  virtual ~AudioInI2SClass();

  int begin(long sampleRate, int bitsPerSample);
  virtual void end();
  //void SerialPrint(String ToPrint, int PrioFac, bool NewLine);//

  virtual long sampleRate();
  virtual int bitsPerSample();
  virtual int channels();
  virtual int datasize();
  void fftDone(int flag);

protected:
  virtual int begin();
  virtual int read(void* buffer, size_t size);
  virtual int reset();

private:
  void onReceive();

  static void onI2SReceive();

private:
  long _sampleRate;
  int _bitsPerSample;
  bool _callbackTriggered;
  int _datasize;
  int _fftDone;

};

extern AudioInI2SClass AudioInI2S;

#endif