#ifndef GEOMETRIE_H
#define GEOMETRIE_H

#ifdef __cplusplus
extern "C" {
#endif

    void quadratBerechnung(float* umfang, float* flaeche, float a);
    void dreieckBerechnung(float* umfang, float* flaeche, float a, float b, float c);
    void rechteckBerechnung(float* umfang, float* flaeche, float a, float b);
    void kreisBerechnung(float* umfang, float* flaeche, float durchmesser);

#ifdef __cplusplus
}
#endif

#endif // GEOMETRIE_H