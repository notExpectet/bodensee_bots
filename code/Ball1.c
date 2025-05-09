#include "hitechnic-compass.h"  // include-Pfad muss passen
#include "hitechnic-irseeker-v2.h"

// Kompass an Port S1   !!Achtung: nicht in #pragma config Sektion auflisten!!!! Hitechnic-Sensor macht Probleme
// IR-Seeker an Port S4 !!Achtung: nicht in #pragma config Sektion auflisten!!!! Hitechnic-Sensor macht Probleme
#define KompassPort S4
#define SeekerPort S3

tHTMC kompass;   // Datenstruktur für Kompass auf Port S1
int Torrichtung = 0;
//long irsensorAlt = 0; // globale Variable für Ballsucher auf Port S4
tHTIRS2 irsensor;
long ballDirection = 0;


task main()
{
	sensorReset(KompassPort);
	sensorReset(SeekerPort);
	setSensorMode(SeekerPort, DSP_1200);

   initSensor (&kompass, KompassPort);
   readSensor (&kompass);
   initSensor (&irsensor, SeekerPort);
   readSensor (&irsensor);
   Torrichtung = kompass.heading;
   kompass.offset = Torrichtung;  // originale Ausrichtung = Torrichtung

   sleep(200);

   while (true)
   {
       eraseDisplay ();

       readSensor (&kompass);
//       irsensorAlt = SensorValue(SeekerPort);
       readSensor (&irsensor);
       ballDirection = irsensor.acDirection;


       displayBigTextLine (2, "Tor: %d", Torrichtung);
       displayBigTextLine (4, "Abw.: %d", kompass.relativeHeading);
//       displayBigTextLine (6, "BallIR: %d", irsensorAlt);
       displayBigTextLine (6, "BallIR: %d", ballDirection);

       //Ball stalken
       wait1Msec(100);
   }
}
