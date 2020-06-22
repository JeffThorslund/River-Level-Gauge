//This code relies on environment variables present in Particle Console

int analogVoltage = A0; //sets analog pin A0 to receive signal from sensor
int rangingSwitch = D0; //sets digital pin D0 to act as on/off switch

double rawRange; //range before calibration (mV)
char RangeStr[30];
double finalRange; //range after calibration (cm), factor of 3.2
double rangeSet[20];

void setup()
{
    pinMode(analogVoltage, INPUT);               // set to receive analog data
    pinMode(rangingSwitch, OUTPUT);              // set to transmit digital date
    Particle.variable("finalRange", finalRange); //creating a global variable of the raw range
    Particle.variable("RangeStr", RangeStr);     //creating a global variable of the raw range
}

void loop()
{
    digitalWrite(rangingSwitch, HIGH);    // ranges when pulled high, stops when pulled low
    rawRange = analogRead(analogVoltage); //reads the analog sensor reading and assigns it to variable rawRange
    finalRange = rawRange / 320;          //converts from mV to meters
    digitalWrite(rangingSwitch, LOW);     // sets the ranging OFF
    Particle.publish("googleDocs", "{\"level-monitor\":\"" + String(finalRange) + "\"}", 60, PRIVATE);
    delay(600000); // waits 10 minutes before collecting data again
}
