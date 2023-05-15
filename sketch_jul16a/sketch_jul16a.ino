#include <IRLibRecvPCI.h> 
// reciving on pin number 2 in the Arduino uno
IRrecvPCI reciver(2);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  reciver.enableIRIn();
  Serial.print("ready\n");

}

void loop() {
  // this code using to recive Raw Data from the remote controller
  if(reciver.getResults()){
    Serial.print("#define RawDataLength  ");
    Serial.println(recvGlobal.recvLength,DEC);
    Serial.print("uint16_t Name[RawDataLength] = ");
    Serial.print("{ ");
    for(bufIndex_t i = 1; i < recvGlobal.recvLength; ++i){
      Serial.print(recvGlobal.recvBuffer[i],DEC);
      Serial.print(" ," );
      if((i%8) == 0){
        Serial.println();
      }
    }
    Serial.println("1000}");
    reciver.enableIRIn();
    
  }
  

}
