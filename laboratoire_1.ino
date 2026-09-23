// Le code minimal

#include <Arduino.h>
#include <Bounce2.h>
Bounce2::Button bouton1; //classe bouton 
Bounce2::Button bouton2; //classe bouton 

#define BROCHE_DEL2 7 //05 SUR ARDUINO
#define BROCHE_DEL1 5 //03 SUR ARDUINO

#define BROCHE_BOUTON1 6 //02 SUR ARDUINO
#define BROCHE_BOUTON2 8 //04 SUR ARDUINO

bool etatDel = LOW;
bool etatDel2 = LOW;


void setup() {
    Serial.begin(115200); //Initalize la vitesse de communication
      // Configuration de la DEL
    pinMode(BROCHE_DEL1, OUTPUT);
    digitalWrite(BROCHE_DEL1, LOW);

    pinMode(BROCHE_DEL2, OUTPUT);
    digitalWrite(BROCHE_DEL2, LOW);

    // Configuration du bouton
    bouton1.attach(BROCHE_BOUTON1, INPUT_PULLUP);
    bouton1.setPressedState(LOW);

    bouton2.attach(BROCHE_BOUTON2, INPUT_PULLUP);
    bouton2.setPressedState(LOW);
}

void loop() {
    bouton1.update();
    bouton2.update();

    if (bouton1.isPressed()) {

        digitalWrite(BROCHE_DEL1, HIGH);
        Serial.print("bouton6"); //description du bouton
        Serial.print(" "); // espace
        Serial.print(1); // valeur
        Serial.println(); // saut de ligne
    } else {
        digitalWrite(BROCHE_DEL1, LOW);
    }


    if (bouton2.pressed()) {

        digitalWrite(BROCHE_DEL2, HIGH); //lumière est allumée
        Serial.print("bouton8"); // Descripteur
        Serial.print(" "); // Espace
        Serial.print(1); // Valeur
        Serial.println(); // Saut de ligne

        if ( etatDel2 == 0 ) {
            etatDel2 = 1;

        } else {
            etatDel2 = 0;    
        }
    }
    else
    {
        digitalWrite(BROCHE_DEL2, etatDel2); //lumière est éteinte
    }

}
