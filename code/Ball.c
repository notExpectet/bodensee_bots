#pragma config(Sensor, S1,     Ult1,           sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     Ult2,           sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          motorLinks,    tmotorEV3_Large, PIDControl, reversed, encoder)
#pragma config(Motor,  motorB,          Dribbler,      tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorD,          motorRechts,   tmotorEV3_Large, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-compass.h"
#include "hitechnic-irseeker-v2.h"

#define SeekerPort S3
#define KompassPort S4

tHTMC Kompass;
tHTIRS2 Seeker;

long TorRichtung;
long Abweichung;

long BallRichtung;


task main();
{
	setMotorSpeed(Dribbler, 100);

	// Senorinitialisierung
	initSensor (&Kompass, KompassPort);
	readSensor (&Kompass);
	TorRichtung = Kompass.heading;
	Kompass.offset = TorRichtung;

	initSensor (&Seeker, SeekerPort);

	while (true)
	{

		//Sensorwerte auslesen
		readSensor (&Kompass);
		Abweichung = Kompass.relativeHeading;

		readSensor (&Seeker);
		BallRichtung = Seeker.acDirection;

		//Sensorwerte anzeigen
		eraseDisplay ();
		displayBigTextLine (0, "Abweich:%d", Abweichung);
		displayBigTextLine (2, "Ball   :%d", BallRichtung);
		displayBigTextLine (8, "Start   :%d", TorRichtung);
		displayBigTextLine (4, "Dribbler   :%d", getMotorSpeed(Dribbler));
		displayBigTextLine (6, "RPM   :%d", getMotorRPM(Dribbler));


		//Ball suchen
		if (BallRichtung == 4)
		{
			setMotorSpeed (motorLinks, -10);
			setMotorSpeed (motorRechts, 10);
		}
		if (BallRichtung == 6)
		{
			setMotorSpeed (motorLinks, 10);
			setMotorSpeed (motorRechts, -10);
		}
		if (BallRichtung > 6)
		{
			setMotorSpeed (motorLinks, 20);
			setMotorSpeed (motorRechts, -20);
		}
		if (BallRichtung < 4)
		{
			setMotorSpeed (motorLinks, -20);
			setMotorSpeed (motorRechts, 20);
		}
		//auf Ball fahren
		if (BallRichtung == 5)
		{
			setMotorSpeed (motorLinks, 20);
			setMotorSpeed (motorRechts, 20);
		}

		//Tor ausrichten

		int DribblerS = getMotorRPM(Dribbler);

		if ((DribblerS < 169) && (DribblerS > 150))
		{
			setMotorSpeed(motorLinks, 5);
			setMotorSpeed(motorRechts, -5);
			wait1Msec(20);

			if ((Abweichung < 5) && (Abweichung > -5))
			{
				setMotorSpeed(motorLinks, 32);
				setMotorSpeed(motorRechts, 30);
				wait10Msec(1000);
			}
		}





		//zum Tor fahren

		wait1Msec (100);
	}



	//Ball stalken

}
