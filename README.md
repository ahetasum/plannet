# 🌍 Planet Simulation Project

This C++ project simulates a planetary system with classes for planets, stars, moons, space missions, and more. It demonstrates core Object-Oriented Programming (OOP) concepts such as:

* Inheritance
* Encapsulation
* Operator Overloading
* Static members
* Templates
* Exception handling
* Polymorphism
* Friend functions

## 📁 Project Structure

```
.
├── main.cpp              # Main simulation code
├── test_planet.cpp       # Unit tests for core features
```

## 🛠️ Compilation & Execution

### Compile Main Program

```bash
g++ main.cpp -o planet_sim
./planet_sim
```

### Compile Test File

```bash
g++ test_planet.cpp -o test_planet
./test_planet
```

*Make sure you're using a C++11+ compatible compiler.*

---

## 📆 Features

### ✔️ `Planet` and `Earth` Classes

* Tracks name, size, and moon count.
* Earth adds temperature and life-checking.

### ✔️ `SpaceMission`

* Simulates launching a mission to a planet.

### ✔️ `SolarSystem`

* Holds multiple `Planet` objects and a `Star`.
* Uses operator overloading `[]`.

### ✔️ `PlanetCounter`

* Demonstrates static data sharing.

### ✔️ `SimpleContainer<T>`

* Template-based container for storing any type.

### ✔️ Exception Handling

* Custom `PlanetError` class throws and catches invalid data.

### ✔️ Virtual Functions & Polymorphism

* `CelestialBody`, `Star`, and `Moon` use virtual `describe()`.

---

## 🧪 Tests Include:

* Planet moon addition
* Earth life and display
* Space mission to Mars
* SolarSystem planet list and access
* Static counter validation
* Friend function comparison
* Template container output
* Custom exception for invalid planet size

---

## 🧰 Dependencies

* Standard C++ Library only (no external dependencies)

---

## 🤝 Contributions

Pull requests and suggestions are welcome!

---

