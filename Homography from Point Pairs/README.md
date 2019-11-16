# Homography from Point Pairs

## ⚙️ Task

### English

For 4 arbitrarily given points (no three of which lie on a straight line) calculate the parameters of projective transformation (homography) that convert these points into vertices of a rectangle with a given aspect ratio. Perform the necessary image conversion (input - image, height to width ratio and 4-point coordinates on the output, rectified image at the output).
The program is expected in C ++ without the use of libraries to calculate the conversion parameters and perform the conversion itself.

### Ukraininan

По 4-х заданих у довільному порядку точках (жодні три з яких не лежать на одній прямій) розрахувати параметри проективного перетворення, яке перетворює ці точки у вершини прямокутника із заданим співвідношенням сторін. Виконати необхідне перетворення зображення (на вході - зображення, співвідношення висоти до ширини та координати 4-х точок на ньому, на виході - ректифіковане зображення).
Програма очікується на C++, без використання бібліотек для обчислення параметрів перетворення і проведення самого перетворення.

## ▶️ Requirements

- [ ] **C++**
  - [**Eigen**](http://eigen.tuxfamily.org/index.php?title=Main_Page) is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms
  - [**Boost**](https://www.boost.org) library
- [ ] **Pybind11** — Seamless operability between C++11 and Python
  - [GitHub](https://github.com/pybind/pybind11)
  - [Documentation](https://pybind11.readthedocs.io/en/master/)
