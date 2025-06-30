#include <iostream>
#include <string>
using namespace std;

class Planet {
private:
    string name;
    double size;
    int moons;

public:
    Planet(string n, double s, int m) {
        name = n;
        size = s;
        moons = m;
    }

    string getName() { return name; }
    double getSize() { return size; }
    int getMoons() { return moons; }

    void setName(string n) { name = n; }
    void setSize(double s) {
        if (s > 0) size = s;
    }

    void displayInfo() {
        cout << "Planet: " << name << ", Size: " << size 
             << ", Moons: " << moons << endl;
    }

    void addMoon() { moons++; }
    void addMoon(int count) { moons += count; }
};

int main() {
    Planet mars("Mars", 6779, 2);
    mars.displayInfo();
    mars.addMoon();
    mars.addMoon(2);
    cout << "After adding moons: " << mars.getMoons() << endl;
    return 0;
}
Earth earth(15.0);
earth.checkLife();
earth.displayInfo();


class Earth : public Planet {
private:
    bool hasLife;
    double temperature;

public:
    Earth(double temp) : Planet("Earth", 12742, 1) {
        hasLife = true;
        temperature = temp;
    }

    void checkLife() {
        if (hasLife) {
            cout << "Earth has life!" << endl;
        }
    }

    void displayInfo() {
        cout << "Planet: " << getName() << " (Our Home!)" << endl;
        cout << "Size: " << getSize() << " km" << endl;
        cout << "Moons: " << getMoons() << endl;
        cout << "Temperature: " << temperature << "°C" << endl;
        cout << "Has Life: " << (hasLife ? "Yes" : "No") << endl;
    }
};

class SpaceMission {
private:
    string missionName;
    Planet* targetPlanet;

public:
    SpaceMission(string name, Planet* target) {
        missionName = name;
        targetPlanet = target;
    }

    void launchMission() {
        cout << "\nLaunching " << missionName << "!" << endl;
        cout << "Target: " << targetPlanet->getName() << endl;
        performComplexCalculations();
        cout << "Mission launched successfully!" << endl;
    }

private:
    void performComplexCalculations() {
        cout << "Calculating trajectory..." << endl;
        cout << "Checking fuel requirements..." << endl;
        cout << "Verifying communication systems..." << endl;
    }
};

class CelestialBody {
public:
    string name;

    CelestialBody(string n) : name(n) {}

    virtual void describe() {
        cout << "I am a celestial body named " << name << endl;
    }

    virtual ~CelestialBody() {}
};

class Star : public CelestialBody {
public:
    Star(string n) : CelestialBody(n) {}

    void describe() override {
        cout << "I am a star named " << name << " - I shine bright! ⭐" << endl;
    }
};

class Moon : public CelestialBody {
public:
    Moon(string n) : CelestialBody(n) {}

    void describe() override {
        cout << "I am a moon named " << name << " - I orbit planets! 🌙" << endl;
    }
};

