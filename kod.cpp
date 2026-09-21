const int lZ = 2, lC = 3, pZ = 4, pC = 5;
unsigned long czas = 0;
int stan = 0;

void setup() {
  pinMode(lZ, OUTPUT); 
  pinMode(lC, OUTPUT);
  pinMode(pZ, OUTPUT); 
  pinMode(pC, OUTPUT);
  
  //stan startowy - lewa zielona, prawa czerwona
  digitalWrite(lZ, HIGH); 
  digitalWrite(lC, LOW);
  digitalWrite(pZ, LOW); 
  digitalWrite(pC, HIGH);
}

void loop() {
  unsigned long teraz = millis();

  if (stan == 0 && teraz - czas >= 4000) { 
    //koniec lewej zielonej -> przerwa obie czerowna na 2 sek
    digitalWrite(lZ, LOW); 
    digitalWrite(lC, HIGH);
    digitalWrite(pZ, LOW); 
    digitalWrite(pC, HIGH);
    czas = teraz;
    stan = 1;
  }
  else if (stan == 1 && teraz - czas >= 2000) { 
    //koniec przerwy -> prawa zielona, lewa czerwona
    digitalWrite(lZ, LOW); 
    digitalWrite(lC, HIGH);
    digitalWrite(pZ, HIGH); 
    digitalWrite(pC, LOW);
    czas = teraz;
    stan = 2;
  }
  else if (stan == 2 && teraz - czas >= 4000) { 
    //koniec prawej zielonej -> przerwa obie czerwone na 2 sek
    digitalWrite(lZ, LOW); 
    digitalWrite(lC, HIGH);
    digitalWrite(pZ, LOW); 
    digitalWrite(pC, HIGH);
    czas = teraz;
    stan = 3;
  }
  else if (stan == 3 && teraz - czas >= 2000) { 
    //koniec przerwy -> powrot do lewej zielonej
    digitalWrite(lZ, HIGH); 
    digitalWrite(lC, LOW);
    digitalWrite(pZ, LOW); 
    digitalWrite(pC, HIGH);
    czas = teraz;
    stan = 0;
  }
}