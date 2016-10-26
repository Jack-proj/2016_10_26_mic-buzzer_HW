

#include "pitches.h"


int melody[] = {
  NOTE_F6,
  NOTE_G6,
  NOTE_C6,
  NOTE_D6,
  NOTE_C6,
  NOTE_G5,
  NOTE_E5,
  NOTE_G5,
  NOTE_C6,
  NOTE_D6,
  NOTE_C6,
  NOTE_G5,
  NOTE_D5,
  NOTE_G5,
 NOTE_C6,
  NOTE_D6,
  NOTE_C6,
  NOTE_G5,
  NOTE_C6
};


int noteDurations[] = {
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,4
};
  
  

void play(){
  for (int thisNote = 0; thisNote < 19; thisNote++) {


    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

   
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
   
    noTone(8);
  }
}


int MIC_PIN = A0;



void setup() {
  pinMode(MIC_PIN, INPUT); 
  
  for(int i=0;i<19;i++)
{
  noteDurations[i]=noteDurations[i]*1.25;
}
}

void loop() {
  int mic = analogRead(MIC_PIN); 
  if(mic >= 400)
  {
    play();
    delay(10);
  }
  
}
