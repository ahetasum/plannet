#include "PlanetOopSimulation.cpp" // or use headers appropriately if split
#include <cassert>
#include <iostream>
using namespace std;

void testPlanet() {
    Planet p("Neptune", 49244, 14);
    assert(p.getName() == "Neptune");
    assert(p.getSize() == 49244);
    assert(p.getMoons() == 14);
    
    p.addMoon();
    assert(p.getMoons() == 15);
    p.addMoon(5);
    assert(p.getMoons() == 20);

    p.setSize(50000);
    assert(p.getSize() == 50000);

    cout << "testPlanet passed!\n";
}

void testEarth() {
    Earth e(16.5);
    assert(e.getName() == "Earth");
    assert(e.getMoons() == 1);
    e.displayInfo();
    e.checkLife();

    cout << "testEarth passed!\n";
}

void testMission() {
    Planet mars("Mars", 6779, 2);
    SpaceMission m("Test Mission", &mars);
    m.launchMission();

    cout << "testMission passed!\n";
}

void testSolarSystem() {
    SolarSystem s("TestSystem", "TestStar");
    Planet p1("Test1", 1000, 1);
    Planet p2("Test2", 2000, 2);

    s.addPlanet(p1);
    s.addPlanet(p2);

    assert(s.getPlanetCount() == 2);
    assert(s[1].getName() == "Test2");

    s.showSystem();
    cout << "testSolarSystem passed!\n";
}

void testStaticCounter() {
    int before = PlanetCounter::getTotalPlanets();
    PlanetCounter::addPlanet();
    PlanetCounter::addPlanet();
    assert(PlanetCounter::getTotalPlanets() == before + 2);
    cout << "testStaticCounter passed!\n";
}

void testTemplateContainer() {
    SimpleContainer<string> c;
    c.add("Mercury");
    c.add("Venus");
    assert(c.size() == 2);
    c.showAll();
    cout << "testTemplateContainer passed!\n";
}

void testComparison() {
    Planet a("Small", 1000, 1);
    Planet b("Big", 2000, 1);
    assert(isBigger(b, a) == true);
    cout << "testComparison passed!\n";
}

void testException() {
    try {
        Planet bad("Error", -500, 0);
        if (bad.getSize() < 0) throw PlanetError("Size negative");
    } catch (PlanetError& e) {
        cout << "Caught expected error: " << e.getMessage() << endl;
        cout << "testException passed!\n";
        return;
    }
    assert(false); // Should not reach here
}

int main() {
    testPlanet();
    testEarth();
    testMission();
    testSolarSystem();
    testStaticCounter();
    testTemplateContainer();
    testComparison();
    testException();

    cout << "\nAll tests passed successfully!\n";
    return 0;
}
