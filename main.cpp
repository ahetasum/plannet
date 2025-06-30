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
#include <vector>

class SolarSystem {
private:
    string systemName;
    vector<Planet> planets;
    Star centralStar;

public:
    SolarSystem(string name, string starName) 
        : systemName(name), centralStar(starName) {}

    void addPlanet(Planet p) {
        planets.push_back(p);
        cout << "Added " << p.getName() << " to " << systemName << endl;
    }

    void showSystem() {
        cout << "\n=== " << systemName << " ===" << endl;
        centralStar.describe();
        cout << "Planets in this system:" << endl;

        for (int i = 0; i < planets.size(); i++) {
            cout << (i+1) << ". ";
            planets[i].displayInfo();
        }
    }

    Planet& operator[](int index) {
        return planets[index];
    }

    int getPlanetCount() { return planets.size(); }
};
SolarSystem ourSystem("Solar System", "Sun");
ourSystem.addPlanet(Planet("Mercury", 4879, 0));
ourSystem.addPlanet(Planet("Venus", 12104, 0));
ourSystem.addPlanet(earth);
ourSystem.showSystem();

cout << "\n=== 6. OPERATOR OVERLOADING ===" << endl;
cout << "Second planet using []: " << ourSystem[1].getName() << endl;


class PlanetCounter {
private:
    static int totalPlanets;

public:
    static void addPlanet() {
        totalPlanets++;
    }

    static int getTotalPlanets() {
        return totalPlanets;
    }

    static void showStats() {
        cout << "Total planets created: " << totalPlanets << endl;
    }
};

int PlanetCounter::totalPlanets = 0;
cout << "\n=== 7. STATIC MEMBERS (Shared Data) ===" << endl;
PlanetCounter::addPlanet();
PlanetCounter::addPlanet();
PlanetCounter::addPlanet();
PlanetCounter::showStats();

template<class T>
class SimpleContainer {
private:
    vector<T> items;

public:
    void add(T item) {
        items.push_back(item);
    }

    void showAll() {
        cout << "Container contents:" << endl;
        for (int i = 0; i < items.size(); i++) {
            cout << "- " << items[i] << endl;
        }
    }

    int size() { return items.size(); }
};
cout << "\n=== 8. TEMPLATES (Generic Programming) ===" << endl;
SimpleContainer<string> planetNames;
planetNames.add("Earth");
planetNames.add("Mars");
planetNames.add("Venus");
planetNames.showAll();

bool isBigger(Planet& p1, Planet& p2) {
    return p1.getSize() > p2.getSize();
}

cout << "\n=== 9. FRIEND FUNCTION ===" << endl;
Planet jupiter("Jupiter", 139820, 79);
if (isBigger(jupiter, mars)) {  
    cout << "Jupiter is bigger than Mars!" << endl;
}


