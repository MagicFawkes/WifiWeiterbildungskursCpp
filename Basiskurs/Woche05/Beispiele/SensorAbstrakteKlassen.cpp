#include <iostream>
using namespace std;

// ==========================
// Abstrakte Basisklasse Sensor
// ==========================
class Sensor {
public:
    virtual float readValue() = 0; // analoger Rückgabewert
    virtual bool readState() = 0;  // digitaler Zustand (ON/OFF)
    virtual ~Sensor() {}
};

// ==========================
// Binärsensor (Liefert nur ON/OFF)
// ==========================
class BinarySensor : public Sensor {
    bool state;   // true = ON, false = OFF
public:
    BinarySensor(bool initial = false) : state(initial) {}

    // liefert keinen echten analogen Wert
    float readValue() override {
        return state ? 1.0f : 0.0f;
    }

    bool readState() override {
        return state;
    }

    void setState(bool s) {
        state = s;
    }
};

// ==========================
// Analogsensor (z.B. Temperatur)
// ==========================
class AnalogSensor : public Sensor {
    float value;
public:
    AnalogSensor(float initial = 0.0f) : value(initial) {}

    float readValue() override {
        return value;
    }

    bool readState() override {
        return value > 0.5f; // Beispielschwelle
    }

    void setValue(float v) {
        value = v;
    }
};

// ==========================
// Abstrakte Aktuator-Basisklasse
// ==========================
class Aktuator {
public:
    virtual void activate(bool on) = 0;   // ON/OFF
    virtual bool isActive() = 0;
    virtual ~Aktuator() {}
};

// ==========================
// LED
// ==========================
class LED : public Aktuator {
    bool active = false;
public:
    void activate(bool on) override {
        active = on;
        cout << "LED: " << (active ? "AN" : "AUS") << endl;
    }

    bool isActive() override {
        return active;
    }
};

// ==========================
// Motor
// ==========================
class Motor : public Aktuator {
    bool active = false;
public:
    void activate(bool on) override {
        active = on;
        cout << "Motor: " << (active ? "läuft" : "gestoppt") << endl;
    }

    bool isActive() override {
        return active;
    }
};

// ==========================
// Greifer
// ==========================
class Gripper : public Aktuator {
    bool active = false;
public:
    void activate(bool on) override {
        active = on;
        cout << "Greifer: " << (active ? "geschlossen" : "offen") << endl;
    }

    bool isActive() override {
        return active;
    }
};

// ==========================
// main()
// ==========================
int main()
{
    // Sensor-Beispiele
    BinarySensor bs(true);
    AnalogSensor as(0.75f);

    cout << "BinarySensor: " << bs.readState() << endl;
    cout << "AnalogSensor-Wert: " << as.readValue() << endl;
    cout << "AnalogSensor-State: " << as.readState() << endl;

    // Aktuatoren
    LED led;
    Motor motor;
    Gripper grip;

    led.activate(true);
    motor.activate(true);
    grip.activate(false);

    return 0;
}
