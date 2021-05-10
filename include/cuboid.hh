#pragma once

#include"matrix.hh"

//    CUBOID OBJECT :
//
//    point[punkt][1]=x_punktu
//    point[punkt][2]=y_punktu
//    point[punkt][3]=z_punktu
//
//        *------------* 4
//      / | 6        / |
//    *------------* 5 |
//    | 7 | 0      |   |
//    |   *--------|---* 2
//    | / 1        | /
//    *------------* 3
//


class Cuboid{
public:

  double point[8][3];

  Cuboid();

  Cuboid(double [8][3]);

  Cuboid operator * (Matrix<double, 3> &);

  Cuboid operator + (Vector<double, 3> &);

  const double &operator () (unsigned int, unsigned int) const;

  double &operator () (unsigned int, unsigned int);

  Cuboid AngleTrans(double Angle, char axis);

};
