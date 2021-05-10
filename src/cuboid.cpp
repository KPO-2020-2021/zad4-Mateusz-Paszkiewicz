#include<cmath>

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
    for(int i=0, m=0; m<3; i++ && m++)
      for(int j=0; j<3; j++){
        point[i][j]=point[i][j]*tmp(m, 0)+point[i][j+1]*tmp(m, 1)+point[i][j+2]*tmp(m, 2); }

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


double &Cuboid::operator () (unsigned int pointNum, unsigned int axis)
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


Cuboid Cuboid::AngleTrans(double Angle, char axis)
{
  if(axis=='x')
    {
      double TransX[][3]={{cos(Angle),-sin(Angle),0},{sin(Angle),cos(Angle),0},{0,0,1}};
      Matrix<double, 3> TransMat=Matrix<double, 3>(TransX);

      (*this)=(*this)*TransMat;
    }
  else if(axis=='y')
    {
      double TransY[][3]={{cos(Angle),0,sin(Angle)},{sin(Angle),cos(Angle),0},{0,0,1}};
      Matrix<double, 3> TransMat=Matrix<double, 3>(TransY);

      (*this)=(*this)*TransMat;
    }
  else if(axis=='z')
  {
    double TransZ[][3]={{1,0,0},{0,cos(Angle),-sin(Angle)},{0,sin(Angle),cos(Angle)}};
    Matrix<double, 3> TransMat=Matrix<double, 3>(TransZ);

    (*this)=(*this)*TransMat;
  }
  else
    {
      std::cerr<<"Error! Wrong axis argument (Neither x, y or z)"<<std::endl;
      return 0;
    }

  return (*this);

}
