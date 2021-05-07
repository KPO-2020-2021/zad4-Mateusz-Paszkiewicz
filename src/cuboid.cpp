#include"../include/cuboid.hh"


Cuboid::Cuboid()
  {
    for(int i=0; i<8; i++)
      for(int j=0; j<3; j++)
        point[i][j]=0;
  }

Cuboid::Cuboid(double tmp[8][3])
  {
    for(int i=0; i<8; i++)
      for(int j=0; j<3; j++)
        point[i][j]=tmp[i][j];
  }

Cuboid Cuboid::operator * (Matrix<double, 3> &tmp)
  {
    for(int i=0; i<8; i++)
      for(int j=0; j<3; j++)
        for(int k=0; k<3; k++)
          point[i][j]+=point[i][j]*tmp(i, k);

    return (*this);
  }


Cuboid Cuboid::operator + (Vector<double, 3> &tmp)
  {
    for(int i=0; i<8; i++) {
      for(int j=0; j<3; j++) {
        for(int k=0; k<3; k++) {
          point[i][j]+=tmp[j];
        }
      }
    }
      return (*this);
  }


const double &Cuboid::operator () (unsigned int pointNum, unsigned int axis) const
{
    if (axis >= 3) {
        std::cout << "Error: Wrong parameter. Only 3 axis in a solid";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }
      if (pointNum >= 8) {
        std::cout << "Error: Wrong parameter. Only 8 points in a cuboid";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }
      return point[pointNum][axis];
}
