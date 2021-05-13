#include<cmath>

#include"../include/cuboid.hh"

/*!
 * Konstruktor objektu klasy cuboid (bezparametryczny)
*
* \retval Cuboid Class object of coords 0
*/
Cuboid::Cuboid()
  {
    for(int i=0; i<8; i++)
      for(int j=0; j<3; j++)
        point[i][j]=0;
  }

  /*!
   * Konstruktor objektu klasy cuboid (parametryczny)
  *
  *\param[in] tmp[8][3] - array of coords where the row is
  *the point number and column is the axis
  *\retval Cuboid Class object of coords 0
  */
Cuboid::Cuboid(double tmp[8][3])
  {
    for(int i=0; i<8; i++)
      for(int j=0; j<3; j++)
        point[i][j]=tmp[i][j];
  }

  /*!
   * przeciazenie operatora mnozenia dla dwoch macierzy
  *
  *\param[in] (*this) - LHS operand of multiplication
  *\param[in] tmp - RHS operand of multiplication
  *\retval result of multiplication of (*this) and tmp
  */
Cuboid Cuboid::operator * (Matrix<double, 3> &tmp)
  {
    double temp1, temp2;

    for(int i=0; i<8; i++){
        temp1=point[i][0];
        temp2=point[i][1];

        point[i][0]=point[i][0]*tmp(0, 0)+point[i][1]*tmp(0, 1)+point[i][2]*tmp(0, 2);
        point[i][1]=temp1*tmp(1, 0)+point[i][1]*tmp(1, 1)+point[i][2]*tmp(1, 2);
        point[i][2]=temp1*tmp(2, 0)+temp2*tmp(2, 1)+point[i][2]*tmp(2, 2);
       }
    return (*this);
  }

  /*!
   * przeciazenie operatora dodawania dla dwoch macierzy
  *
  *\param[in] (*this) - LHS operand of addition
  *\param[in] tmp - RHS operand of addition
  *\retval result of addition of (*this) and tmp
  */
Cuboid Cuboid::operator + (Vector<double, 3> &tmp)
  {
    for(int i=0; i<8; i++) {
      for(int j=0; j<3; j++) {
          point[i][j]+=tmp[j];
      }
    }
      return (*this);
  }

  /*!
   * funktor () prostopadloscianu
  *
  *\param[in] (*this) cuboid of the coordinate to be extracted
  *\param[in] pointNum - number of the wanted point
  *\param[in] axis - axis of the wanted coordinate
  *\retval const value of the coordinate of indicated values
  */
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

/*!
 * funktor () prostopadloscianu
*
*\param[in] (*this) cuboid of the coordinate to be extracted
*\param[in] pointNum - number of the wanted point
*\param[in] axis - axis of the wanted coordinate
*\retval value of the coordinate of indicated values
*/
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

/*!
* funkcja izometrycznie transponujaca prostopadloscian wokol
*poczatku ukladu wspolrzednych
*
*\param[in] Angle - angle of the rotation
*\param[in] Axis - of the rotation
*\param[in] (*this) - the cuboid to be rotated
*\retval new coordinates of the rotated cuboid
*/
Cuboid Cuboid::AngleTrans(double Angle, char axis)
{
  if(axis=='z')
    {
      double TransX[][3]={{cos(Angle),-sin(Angle),0},{sin(Angle),cos(Angle),0},{0,0,1}};
      Matrix<double, 3> TransMat=Matrix<double, 3>(TransX);

      (*this)=(*this)*TransMat;
    }
  else if(axis=='y')
    {
      double TransY[][3]={{cos(Angle),0,-sin(Angle)},{0,1,0},{sin(Angle),0,cos(Angle)}};
      Matrix<double, 3> TransMat=Matrix<double, 3>(TransY);

      (*this)=(*this)*TransMat;
    }
  else if(axis=='x')
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
