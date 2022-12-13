#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
int tPin = 22;

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    for (int i=9; i>=0; i--) {
        digitalWrite(LED_BUILTIN, i % 2 ? HIGH : LOW);
        delay(50);
    }
    mySwitch.enableTransmit(tPin); // Using Pin #D22
    Serial.printf("DBG RF Initialized.\n");
    //mySwitch.setRepeatTransmit(1);
}

void loop() {
    String serialCommand;

    while (Serial.available() > 0) {
        char serialChar = Serial.read();
        serialCommand += serialChar; 

        if (serialChar == '\n') {
            processCommand(serialCommand);
            serialCommand = "";
        }
    }
}


void processCommand(String command) {
    command.trim();
    command.toUpperCase();

    // Serial.println("DBG Received command: " + command);
    if (command.startsWith("SEND_SIGNAL ")) {
        int signalTmp = command.substring(12).toInt();
        mySwitch.send(signalTmp, 24);
        Serial.println("Signal send");
        delay(1000);
    }
    else{
      Serial.println("ERR Unknown command.");
    }
}
