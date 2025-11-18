#include <iostream>
#include <vector>
using namespace std;

class Sensor {
public:
    virtual void readValue() const = 0;  // reine virtuelle Funktion
    virtual ~Sensor() {}
};

class BinarySensor : public Sensor {
private:
    bool on;
public:
    BinarySensor(bool on) {
        this->on = on;
    }

    void on_() {          // anderer Name, um Verwechslung zu vermeiden
        on = true;
    }

    void off() {
        on = false;
    }

    void readValue() const override {
        cout << "BinarySensor, Wert (on): " << on << endl;
    }
};

class AnalogSensor : public Sensor {
private:
    int x;
public:
    AnalogSensor(int x) {
        this->x = x;
    }

    void setValue(int x) {
        this->x = x;
    }

    void readValue() const override {
        cout << "AnalogSensor, Wert: " << x << endl;
    }
};

int main()
{
    // Konkrete Objekte
    BinarySensor bs1(true);
    BinarySensor bs2(false);
    AnalogSensor as1(10);
    AnalogSensor as2(99);

    // Polymorph: über Sensor*-Zeiger
    vector<Sensor*> sensors = { &bs1, &bs2, &as1, &as2 };

    cout << "=== Anfangszustand ===" << endl;
    for (Sensor* s : sensors) {
        s->readValue();
    }

    cout << "\n=== Zustände ändern ===" << endl;
    bs1.off();        // war true -> jetzt false
    bs2.on_();        // war false -> jetzt true
    as1.setValue(42); // neuen Analogwert setzen
    as2.setValue(7);

    cout << "\n=== Nach Änderung ===" << endl;
    for (Sensor* s : sensors) {
        s->readValue();
    }

    return 0;
}
