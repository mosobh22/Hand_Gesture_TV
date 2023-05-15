#include<IRLibSendBase.h>
#include<IRLib_HashRaw.h>
#define RawDataLength  68

/// Raw Data ///////////////////////////
uint16_t RawON_OFF[RawDataLength] = { 8962 ,4478 ,574 ,538 ,586 ,554 ,570 ,542 ,
586 ,550 ,574 ,538 ,586 ,554 ,574 ,1674 ,
570 ,554 ,570 ,1662 ,586 ,1674 ,570 ,1662 ,
586 ,1658 ,586 ,1658 ,590 ,1674 ,570 ,554 ,
574 ,1658 ,586 ,554 ,570 ,1674 ,574 ,550 ,
574 ,554 ,570 ,1674 ,574 ,550 ,574 ,554 ,
570 ,554 ,570 ,1662 ,586 ,554 ,570 ,1658 ,
590 ,1674 ,570 ,554 ,574 ,1654 ,590 ,1658 ,
590 ,1654 ,590 ,1000};
uint16_t RawNext_Channal[RawDataLength] = { 8942 ,4482 ,570 ,538 ,586 ,538 ,590 ,538 ,
586 ,538 ,586 ,538 ,586 ,562 ,562 ,1686 ,
562 ,538 ,586 ,1662 ,586 ,1658 ,590 ,1658 ,
586 ,1658 ,590 ,1658 ,586 ,1662 ,586 ,538 ,
586 ,1662 ,586 ,1658 ,590 ,1678 ,566 ,538 ,
586 ,1682 ,566 ,1658 ,586 ,542 ,586 ,538 ,
586 ,538 ,590 ,538 ,586 ,538 ,586 ,1662 ,
586 ,538 ,586 ,562 ,562 ,1662 ,586 ,1682 ,
562 ,1662 ,586 ,1000};

uint16_t Rawprev_Channal[RawDataLength] = { 8946 ,4482 ,574 ,538 ,590 ,538 ,586 ,554 ,
570 ,538 ,586 ,554 ,574 ,554 ,570 ,1658 ,
590 ,554 ,570 ,1674 ,574 ,1658 ,586 ,1658 ,
586 ,1662 ,586 ,1658 ,590 ,1674 ,570 ,554 ,
574 ,1658 ,586 ,1658 ,590 ,1658 ,590 ,1658 ,
586 ,1674 ,574 ,1658 ,586 ,558 ,570 ,538 ,
586 ,554 ,570 ,538 ,590 ,550 ,574 ,550 ,
574 ,554 ,574 ,534 ,590 ,1658 ,586 ,1662 ,
586 ,1658 ,586 ,1000};

uint16_t RawVolum_UP[RawDataLength] = { 8962 ,4462 ,590 ,538 ,586 ,538 ,586 ,554 ,
570 ,538 ,590 ,538 ,586 ,550 ,574 ,1658 ,
590 ,550 ,574 ,1658 ,586 ,1674 ,574 ,1658 ,
590 ,1654 ,590 ,1658 ,590 ,1658 ,586 ,538 ,
590 ,1658 ,586 ,538 ,586 ,1662 ,586 ,538 ,
586 ,1658 ,590 ,1658 ,590 ,550 ,574 ,538 ,
586 ,538 ,590 ,1658 ,586 ,554 ,574 ,1658 ,
586 ,554 ,574 ,534 ,590 ,1658 ,586 ,1658 ,
590 ,1658 ,590 ,1000};
uint16_t RawVolum_DOWN[RawDataLength] = { 8962 ,4462 ,586 ,538 ,586 ,554 ,574 ,538 ,
586 ,538 ,586 ,538 ,590 ,538 ,586 ,1658 ,
586 ,538 ,590 ,1654 ,590 ,1658 ,590 ,1658 ,
586 ,1658 ,586 ,1674 ,574 ,1658 ,590 ,534 ,
586 ,1662 ,586 ,538 ,590 ,1658 ,586 ,1658 ,
586 ,1658 ,590 ,1658 ,586 ,538 ,590 ,538 ,
586 ,538 ,586 ,1658 ,590 ,538 ,586 ,538 ,
586 ,538 ,586 ,538 ,590 ,1658 ,586 ,1658 ,
590 ,1658 ,586 ,1000};
/////////////////////////////////


IRsendRaw mysender;
char serialData = '0';
//int flage = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
    if(Serial.available() > 0){
     ///Serial.println(serialData);
     // reciving data from python code after the detection     
     serialData = Serial.read();
    //Serial.println(serialData);
    if(serialData == 'o'){
      // close and open  tv
      mysender.send(RawON_OFF,RawDataLength,38);
    }
    else if(serialData == 'a'){
      // next channel
      mysender.send(RawNext_Channal,RawDataLength,38);
      
      
    }else if(serialData == 'b'){
      // previous channel
      mysender.send(Rawprev_Channal,RawDataLength,38);
     }
     else if(serialData == 'c'){
      // Volum UP
      mysender.send(RawVolum_UP,RawDataLength,38);
     }
     else if(serialData == 'd'){
      //Volum Down
      mysender.send(RawVolum_DOWN,RawDataLength,38);
      //Serial.print("low");
     }else{
       // here we do nothing 
     }
      
    }
    delay(7);
  
}
