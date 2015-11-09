const int statusPin = D7; // status LED pin
const int flashPin = D1; // flash pin
const int sensorPin = A0; // select the input pin for the LDR
const int pwrPin = A2; // power pin
int sensorValue = 0; // variable to store the value coming from the LDR
int sensorThreshold = 950;
int overrideValue = 0;


void setup()
{
    Particle.function("SetOverride", setSensorOverride);
    Particle.function("SetThreshold",  setSensorThreshold);

    pinMode(sensorPin,INPUT);
    pinMode(statusPin, OUTPUT);
    pinMode(flashPin, OUTPUT);
    pinMode(pwrPin, OUTPUT);
}

void loop()
{
    digitalWrite(pwrPin, HIGH);

    if (overrideValue > 0)
        sensorValue = overrideValue;
    else
        sensorValue = analogRead(sensorPin); // read the value from the LDR

    if(sensorValue > sensorThreshold)
    { // you might need to adjust the default 950 value for better results
        digitalWrite(statusPin, HIGH);
        digitalWrite(flashPin, HIGH);
        delay(10);
    } else {
        digitalWrite(statusPin, LOW);
        digitalWrite(flashPin, LOW);
    }
}

int setSensorOverride(String param)
{
    overrideValue = param.toInt();
    return overrideValue;
}

int setSensorThreshold(String param)
{
    sensorThreshold = param.toInt();
    return sensorThreshold;
}