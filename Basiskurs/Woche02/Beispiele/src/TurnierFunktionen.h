#ifndef BINARYFUNKTIONEN_H
#define BINARYFUNKTIONEN_H

#ifdef __cplusplus
extern "C" {
#endif 

int eingabe(const char* message);

struct Teilnehmer
{
    char name[40];
    int punkte;
};

#ifdef __cplusplus
}
#endif

#endif