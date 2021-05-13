// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../external/doctest/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <limits>

#include "lacze_do_gnuplota.hh"
#include "exampleConfig.h"
#include "handling.hh"
#include "vector.hh"
#include "matrix.hh"
#include "rectangle.hh"
#include "cuboid.hh"






int main() {
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;
  // std::system("cat ../LICENSE");
  // do zadania Rotacja 2D



  std::cout<<"2D GNUPlot rectangle Translation program."<<std::endl;  //introduction
  std::cout<<"Press h for help."<<std::endl;



  int Mode;
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

  //Our objects initialization:
  Cuboid ObjectCub=Cuboid();
  Rectangle ObjectRect=Rectangle();


  std::cout<<"Select, your mode:"<<std::endl;
  std::cout<<"1 - 2D mode"<<std::endl;
  std::cout<<"2 - 3D mode"<<std::endl;

  std::cin>>Mode;

  if(Mode==2){
    Lacze.DodajNazwePliku("../datasets/figure.dat",PzG::RR_Ciagly,3);
    Lacze.DodajNazwePliku("../datasets/figure.dat",PzG::RR_Punktowy,3);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    CoordsReadFromFile("../datasets/figure.dat", ObjectCub);
  }
  else
  if(Mode==1){
    Lacze.DodajNazwePliku("../datasets/figure.dat",PzG::RR_Ciagly,2);
    Lacze.DodajNazwePliku("../datasets/figure.dat",PzG::RR_Punktowy,2);
    Lacze.ZmienTrybRys(PzG::TR_2D);
    CoordsReadFromFile("../datasets/figure.dat", ObjectRect);
  }
  else {
    std::cout<<"Error! Mode not recognized"<<std::endl;
    std::cout<<"setting to 2D as default"<<std::endl;
    Lacze.DodajNazwePliku("../datasets/figure.dat",PzG::RR_Ciagly,2);
    Lacze.DodajNazwePliku("../datasets/figure.dat",PzG::RR_Punktowy,2);
    Lacze.ZmienTrybRys(PzG::TR_2D);
    CoordsReadFromFile("../datasets/figure.dat", ObjectRect);
  }


  char option;

  Menu:

  std::cout<<"Please select option:  ";

  std::cin>>option;
  std::cout<<std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

  switch (option) {
    case 'm':
    {
      std::cout<<"Change mode to:"<<std::endl;
      std::cout<<"1 - 2D mode"<<std::endl;
      std::cout<<"2 - 3D mode"<<std::endl;

      std::cin>>Mode;

      if(Mode==1) {
        Lacze.DodajNazwePliku("../datasets/figure.dat",PzG::RR_Ciagly,2);
        Lacze.DodajNazwePliku("../datasets/figure.dat",PzG::RR_Punktowy,2);
        Lacze.ZmienTrybRys(PzG::TR_2D);

        std::cout<<"Changed mode to 2D"<<std::endl;

        goto Menu;
      }
      if(Mode==2) {
        Lacze.DodajNazwePliku("../datasets/figure.dat",PzG::RR_Ciagly,3);
        Lacze.DodajNazwePliku("../datasets/figure.dat",PzG::RR_Punktowy,3);
        Lacze.ZmienTrybRys(PzG::TR_3D);

        std::cout<<"Changed mode to 3D"<<std::endl;

        goto Menu;
      }
      else
        std::cout<<"Error! Mode not recognized."<<std::endl;

      goto Menu;

    }
    case 'h':
    {
      std::cout<<"v - vector translation "<<std::endl;
      std::cout<<"a - isometric translation "<<std::endl;
      std::cout<<"d - display figure in GNUPlot "<<std::endl;
      std::cout<<"s - display coordinates of the figure "<<std::endl;
      std::cout<<"q - exit "<<std::endl;

      goto Menu;
    }
    case 'v':
    {
      if(Mode==1){
        double input[2];

        std::cout<<"please pass the vector values [x,y]:"<<std::endl;

        std::cin>>input[0]; std::cin>>input[1];
        Vector<double,2> vec= Vector<double, 2>(input);

        ObjectRect=ObjectRect+vec;

        if (!SaveCoordsToFile("../datasets/figure.dat",ObjectRect))
          std::cerr<<"Err: Cannot save coords to file";
          else
          {
            std::cout<<std::endl;
            std::cout<<"Done!"<<std::endl<<std::endl;
          }
        }
        else{
          double input[3];

          std::cout<<"please pass the vector values [x,y,z]:"<<std::endl;

          std::cin>>input[0]; std::cin>>input[1]; std::cin>>input[2];
          Vector<double,3> vec= Vector<double, 3>(input);

          ObjectCub=ObjectCub+vec;

          if (!SaveCoordsToFile("../datasets/figure.dat",ObjectCub))
            std::cerr<<"Err: Cannot save coords to file";
            else
            {
              std::cout<<std::endl;
              std::cout<<"Done!"<<std::endl<<std::endl;
            }
        }

      goto Menu;
    }

    case 'a':
    {
      double angle;
      char axis;


      if(Mode==1){
        std::cout<<"Please pass the value of angle:";
        std::cin>>angle;

        ObjectRect.AngleTrans(angle*M_PI/180);

        if (!SaveCoordsToFile("../datasets/figure.dat",ObjectRect))
          std::cerr<<"Err: Cannot save coords to file";
          else
          {
            std::cout<<std::endl;
            std::cout<<"Done!"<<std::endl<<std::endl;
          }
      }
      else{
        std::cout<<"Please pass axis (x, y or z) and the value of angle:";
        std::cin>>axis;
        std::cin>>angle;

        ObjectCub.AngleTrans(angle*M_PI/180,axis);

        if (!SaveCoordsToFile("../datasets/figure.dat",ObjectCub))
          std::cerr<<"Err: Cannot save coords to file";
          else
          {
            std::cout<<std::endl;
            std::cout<<"Done!"<<std::endl<<std::endl;
          }
      }



      goto Menu;
    }

    case 'd':
    {
      std::cout<<std::endl;
      std::cout<<"Displaying..."<<std::endl<<std::endl;
      Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
      goto Menu;
    }
    case 's':
    {
      std::cout<<std::endl;
      std::cout<<"Displaying coords..."<<std::endl<<std::endl;

      if(Mode==1)
        CoordsToStream(std::cout, ObjectRect);
      else
        CoordsToStream(std::cout, ObjectCub);

      goto Menu;
    }
    case 'q':
    {
      exit(0);
    }
    default:
    {
      std::cout<<"Option selected not recognized, please try again.";
      goto Menu;
    }
  }

}
