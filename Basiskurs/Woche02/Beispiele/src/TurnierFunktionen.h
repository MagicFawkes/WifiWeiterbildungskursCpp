#ifndef BINARYFUNKTIONEN_H
#define BINARYFUNKTIONEN_H

#ifdef __cplusplus
extern "C" {
#endif 

struct Teilnehmer
{
    char name[40];
    int punkte;
};

int eingabe(const char* message);
struct Teilnehmer* erzeugeTeilnehmer(struct Teilnehmer* teilnehmer, int anzahlTeilnehmer);
struct Teilnehmer* entferneTeilnehmer(struct Teilnehmer* teilnehmer, int anzahlTeilnehmer);
struct Teilnehmer* sortiereTeilnehmer(struct Teilnehmer* teilnehmer, int anzahlTeilnehmer);

#ifdef __cplusplus
}
#endif

#endif