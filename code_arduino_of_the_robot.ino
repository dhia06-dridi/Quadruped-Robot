// Déclaration des pins pour HC-SR04
#define TRIG_PIN 11
#define ECHO_PIN 7

// RemoteXY Configuration
#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT

#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 115200
#define REMOTEXY_WIFI_SSID "bionic_robot"
#define REMOTEXY_WIFI_PASSWORD "1234567d"
#define REMOTEXY_SERVER_PORT 6377

#include <RemoteXY.h>
#include <Servo.h>

// RemoteXY GUI Configuration
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = 
{ 255,5,0,0,0,97,0,19,0,0,0,0,21,1,106,200,1,1,5,0,
  5,24,139,60,60,21,204,16,31,2,28,36,53,23,0,6,16,16,8,115,
  116,97,114,116,0,115,116,111,112,0,129,7,9,97,17,64,6,66,105,111,
  110,105,99,32,82,111,98,111,116,0,10,69,81,24,24,48,6,26,31,79,
  78,0,31,79,70,70,0,10,16,82,24,24,48,4,26,31,79,78,0,31,
  79,70,70,0 };
  
struct {
  int8_t joystick_01_x;
  int8_t joystick_01_y;
  uint8_t start_stop;
  uint8_t saut_on_off;
  uint8_t salut_button;
  uint8_t connect_flag;
} RemoteXY;
#pragma pack(pop)

// Déclaration des servos
Servo servo1; // Avant gauche
Servo servo2; // Avant droit
Servo servo3; // Arrière gauche
Servo servo4; // Arrière droit

// Fonction pour mesurer la distance du capteur HC-SR04
long getDistance() {
  // Envoi du signal sur le pin TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Lecture du signal écho
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = (duration / 2) * 0.0344;  // Conversion de la durée en distance (cm)
  
  return distance;
}

// Fonction setup
void setup() {
  RemoteXY_Init();
  Serial.begin(115200);

  servo1.attach(9);
  servo2.attach(3);
  servo3.attach(10);
  servo4.attach(6);

  pinMode(TRIG_PIN, OUTPUT); // Pin TRIG en sortie
  pinMode(ECHO_PIN, INPUT);  // Pin ECHO en entrée

  resetPosition();
}

// Fonction principale
void loop() {
  RemoteXY_Handler();

  long distance = getDistance(); // Mesure la distance
  
  // Si la distance est inférieure ou égale à 10 cm, on arrête le programme (start_stop = 0)
  if (distance <= 10) {
    RemoteXY.start_stop = 0;  // Stoppe le robot si la distance est <= 10 cm
    resetPosition();          // Réinitialise la position des servos
  }

  if (RemoteXY.start_stop == 1) {
    handleSalut();
    handleSaut();
    handleJoystick();
  } else {
    resetPosition(); // Réinitialiser les servos si Stop
  }
}

// Fonction de gestion du bouton "Salut"
void handleSalut() {
  if (RemoteXY.salut_button == 1) {
    servo2.write(120); // Mouvements du bras "Salut"
    delay(300);
    servo2.write(170);
    delay(300);
  }
}

// Fonction de gestion du bouton "Saut"
void handleSaut() {
  if (RemoteXY.saut_on_off == 1) {
    servo1.write(60);
    servo2.write(120);
    delay(500);
    servo3.write(60);
    servo4.write(120);
    delay(500);

    servo1.write(120);
    servo2.write(60);
    delay(500);
    servo3.write(120);
    servo4.write(60);
    delay(500);

    resetPosition();
  }
}

// Fonction de gestion du joystick
void handleJoystick() {
  if (RemoteXY.joystick_01_y > 20) {
    avancer();
  } else if (RemoteXY.joystick_01_x > 20) {
    tournerDroite();
  } else if (RemoteXY.joystick_01_x < -20) {
    tournerGauche();
  } else {
    resetPosition();
  }
}

// Fonctions de mouvement
void avancer() {
    servo1.write(70);
    servo4.write(70);
    delay(200);
    servo1.write(110);
    servo4.write(110);
    delay(200);
    servo1.write(90);
    servo4.write(90);
    delay(200);
    servo2.write(70);
    servo3.write(70);
    delay(200);
    servo2.write(110);
    servo3.write(110);
    delay(200);
    servo2.write(90);
    servo3.write(90);
    delay(200);
}

void tournerGauche() {
    servo2.write(70); // Lève la jambe droite
    servo3.write(70); // Lève la jambe gauche arrière
    delay(100);
    servo1.write(110); // Pousse la jambe gauche
    servo4.write(110); // Pousse la jambe droite arrière
    delay(200);
    resetPosition();
}

void tournerDroite() {
    servo1.write(70); // Lève la jambe gauche
    servo4.write(70); // Lève la jambe droite arrière
    delay(100);
    servo2.write(110); // Pousse la jambe droite
    servo3.write(110); // Pousse la jambe gauche arrière
    delay(200);
    resetPosition(); 
}

// Fonction pour réinitialiser les servos
void resetPosition() {
  servo1.write(90);
  servo2.write(90);
  servo3.write(95);
  servo4.write(85);
}
