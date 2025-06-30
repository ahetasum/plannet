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
