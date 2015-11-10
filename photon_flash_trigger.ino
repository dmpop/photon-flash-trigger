const int statusPin = D7; // status LED pin
const int flashPin = D1; // flash pin
const int ldrPin = A0; // select the input pin for the LDR
const int pwrPin = A2; // power pin
int ldrValue = 0; // variable to store the value coming from the LDR
int ldrThreshold = 950;

void setup()
{
    Particle.function("SetThreshold",  setThreshold);

    pinMode(ldrPin,INPUT);
    pinMode(statusPin, OUTPUT);
    pinMode(flashPin, OUTPUT);
    pinMode(pwrPin, OUTPUT);
}

void loop()
{
    digitalWrite(pwrPin, HIGH);
    ldrValue = analogRead(ldrPin); // read the value from the LDR
    if(ldrValue > ldrThreshold)
    {
        digitalWrite(statusPin, HIGH);
        digitalWrite(flashPin, HIGH);
        delay(10);
    } else {
        digitalWrite(statusPin, LOW);
        digitalWrite(flashPin, LOW);
    }
}

int setThreshold(String param)
{
    ldrThreshold = param.toInt();
    return ldrThreshold;
}