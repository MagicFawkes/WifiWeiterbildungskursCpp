#ifndef GEOMETRIE_H
#define GEOMETRIE_H

#ifdef _WIN32
  #ifdef MYMATH_EXPORTS
    // Beim Bauen der DLL definieren (Compiler-Flag): -DMYMATH_EXPORTS
    #define MYMATH_API __declspec(dllexport)
  #else
    // Beim Nutzen der DLL: kein Import-Attribut nötig
	#define MYMATH_API __declspec(dllimport)
  #endif
#else
  // Auf Linux/macOS kein Attribut nötig (sofern du nicht -fvisibility=hidden nutzt)
  #define MYMATH_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

    // ASCII-Bezeichner (keine Umlaute)
    MYMATH_API void quadratBerechnung(float* umfang, float* flaeche, float a);
    MYMATH_API void dreieckBerechnung(float* umfang, float* flaeche, float a, float b, float c);
    MYMATH_API void rechteckBerechnung(float* umfang, float* flaeche, float a, float b);
    MYMATH_API void kreisBerechnung(float* umfang, float* flaeche, float durchmesser);

#ifdef __cplusplus
}
#endif

#endif // GEOMETRIE_H
