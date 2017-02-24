const int ContactGenerator = 7; // controleaza releul de jos de 12V pentru contact generator (default OFF)

const int ContactSursa12V = 2; // controleaza releul 1 care porneste sursa de alementare la 12V (cablul verde ATX)
const int ContactRetea220V = 3; // controleaza releul 2 care porneste reteau de 220V - ATENTIE PERICOL DE ELECTROCUTARE !!!!

const int ContactDemaror12V = 8; // controleaza releul de sus de 12V pentru contact demaror (default OFF) - ATENTIE CONTACTUL NU TREBUIE SA DUREZE

// Atentie, default Borna rosie = -, Borna neagra = -; Daca se cupleaza ambele relee ambele borne vor fi pe + !!!
const int ActuatorNormal = 6; // (fir mov) controleaza releul 1 actuator (contact + la +) => Borna rosie = +, Borna neagra = -
const int ActuatorInversat = 5; // (fir verde) controleaza releul 2 actuator (contact + la -) => Borna neagra = +, Borna rosie = -

const int ButonNegru = 9;// controleaza pornirea demararii generatorului

void setup() {
  Serial.begin(115200);
  
  // OUTPUT PINS
  pinMode(ContactGenerator, OUTPUT);
  pinMode(ActuatorNormal, OUTPUT);
  pinMode(ActuatorInversat, OUTPUT);
  pinMode(ContactSursa12V, OUTPUT);
  pinMode(ContactRetea220V, OUTPUT);
  pinMode(ContactDemaror12V, OUTPUT);
  
  //digitalWrite(ContactGenerator, LOW);
  digitalWrite(ActuatorNormal, HIGH);
  digitalWrite(ActuatorInversat, HIGH);
  digitalWrite(ContactSursa12V, HIGH);
  digitalWrite(ContactRetea220V, HIGH);
  //digitalWrite(ContactDemaror12V, LOW);


  // INPUT PINS
  pinMode(ButonNegru, INPUT);
}

int prevStateButonNegru = 0;
void loop() {

Serial.println(digitalRead(ButonNegru));

  if(digitalRead(ButonNegru) == HIGH && prevStateButonNegru == LOW)
  {

    digitalWrite(ContactGenerator, LOW);
    delay(1000);
    digitalWrite(ContactGenerator, HIGH);
    delay(1000);
    digitalWrite(ContactGenerator, LOW);

    delay(1000);
    digitalWrite(ActuatorNormal, LOW);
    delay(1000);
    digitalWrite(ActuatorNormal, HIGH);
    delay(1000);
    digitalWrite(ActuatorNormal, LOW);
    delay(1000);

    delay(1000);
    digitalWrite(ActuatorInversat, LOW);
    delay(1000);
    digitalWrite(ActuatorInversat, HIGH);
    delay(1000);
    digitalWrite(ActuatorInversat, LOW);
    delay(1000);

    delay(1000);
    digitalWrite(ContactSursa12V, HIGH);
    delay(1000);
    digitalWrite(ContactSursa12V, LOW);
    delay(1000);
    digitalWrite(ContactSursa12V, HIGH);
    delay(1000);

    delay(1000);
    digitalWrite(ContactRetea220V, LOW);
    delay(1000);
    digitalWrite(ContactRetea220V, HIGH);
    delay(1000);
    digitalWrite(ContactRetea220V, LOW);
    delay(1000);

    delay(1000);
    digitalWrite(ContactDemaror12V, LOW);
    delay(1000);
    digitalWrite(ContactDemaror12V, HIGH);
    delay(1000);
    digitalWrite(ContactDemaror12V, LOW);
    delay(1000);
  }

  prevStateButonNegru = digitalRead(ButonNegru);
  delay(500);
}
