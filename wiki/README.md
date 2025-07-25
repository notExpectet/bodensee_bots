# Bodensee Bots Wiki

Diese Wiki liefert einen kurzen Überblick über den Roboter und die Software.

## Roboter-Spezifikationen

- **Basis:** LEGO Mindstorms EV3
- **Motoren**
  - `motorLinks` (Port A) – EV3 Large Motor
  - `motorRechts` (Port D) – EV3 Large Motor
  - `Dribbler` (Port B) – EV3 Medium Motor
- **Sensoren**
  - `Ult1` (Port S1) – Ultrasonic Sensor links
  - `Ult2` (Port S2) – Ultrasonic Sensor rechts
  - `Seeker` (Port S3) – HiTechnic IR Seeker
  - `Kompass` (Port S4) – HiTechnic Compass

## Code-Versionen

Im Ordner `code` befinden sich mehrere Entwicklungsstände. Die aktuell funktionsfähige Version ist:

- **`soccer_v7.c` – Soccerversion 7.0 STABLE RELEASE**


Das aktuellste Experiment befindet sich in `soccer_v8x.c` (Beta). Diese Version wurde zuletzt mit Commit `c9a520a` aktualisiert und enthält die neueste Logik, ist jedoch noch in der Erprobung.

## Verwendung

Die Programme sind mit ROBOTC entwickelt und können direkt dort kompiliert und auf den EV3 geladen werden. `soccer_v7.c` eignet sich für Spieleinsätze, während `soccer_v8x.c` nur zu Testzwecken genutzt werden sollte.

