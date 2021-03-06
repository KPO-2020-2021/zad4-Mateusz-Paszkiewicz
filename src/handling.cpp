#include<iostream>

#include"../include/handling.hh"

/*!
 * Funkcja odczytu zestawu punktow prostokata
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 *\param[in] Rect - objekt klasy rectangle do ktorego zapisane zostana dane
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool CoordsReadFromFile(const char *sNazwaPliku, Rectangle &Rect)
{
    std::ifstream  fin;

  fin.open(sNazwaPliku);
  if (!fin.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
   << ":(  nie powiodla sie." << std::endl;
    return false;
    }

  fin >> Rect(0,0);   fin >> Rect(0,1);
  fin >> Rect(1,0);   fin >> Rect(1,1);
  fin >> Rect(2,0);   fin >> Rect(2,1);
  fin >> Rect(3,0);   fin >> Rect(3,1);
  fin >> Rect(0,0);   fin >> Rect(0,1);

  return true;
}


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow prostokata do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool CoordsReadFromFile(const char *sNazwaPliku, Cuboid &Cub)
{
    std::ifstream  fin;

  fin.open(sNazwaPliku);
  if (!fin.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
   << ":(  nie powiodla sie." << std::endl;
    return false;
    }

  fin >> Cub(0,0);   fin >> Cub(0,1);   fin >> Cub(0,2);
  fin >> Cub(1,0);   fin >> Cub(1,1);   fin >> Cub(1,2);
  fin >> Cub(2,0);   fin >> Cub(2,1);   fin >> Cub(2,2);
  fin >> Cub(3,0);   fin >> Cub(3,1);   fin >> Cub(3,2);
  fin >> Cub(4,0);   fin >> Cub(4,1);   fin >> Cub(4,2);
  fin >> Cub(5,0);   fin >> Cub(5,1);   fin >> Cub(5,2);
  fin >> Cub(6,0);   fin >> Cub(6,1);   fin >> Cub(6,2);
  fin >> Cub(7,0);   fin >> Cub(7,1);   fin >> Cub(7,2);

  fin.close();
  return true;
}




/*!
 * Przyklad zapisu wspolrzednych zbioru punktow prostopadloscianu do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void CoordsToStream( std::ostream& StrmWy, Rectangle &Rect)
{

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Rect(0,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Rect(0,1) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Rect(1,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Rect(1,1) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Rect(2,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Rect(2,1) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Rect(3,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Rect(3,1) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Rect(0,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Rect(0,1) << std::endl;
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}



/*!
 * Funkcja zapisu zestawu punktow prostopadloscianu do strumienia
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 *\param[in] Cub - objekt klasy cuboid do ktorego zapisane zostana dane
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void CoordsToStream( std::ostream& StrmWy, Cuboid &Cub)
{

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Cub(0,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(0,1)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(0,2) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Cub(1,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(1,1)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(1,2) << std::endl;
        StrmWy<<std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Cub(2,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(2,1)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(2,2) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Cub(3,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(3,1)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(3,2) << std::endl;
         StrmWy<<std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Cub(4,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(4,1)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(4,2) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Cub(5,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(5,1)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(5,2) << std::endl;
         StrmWy<<std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Cub(6,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(6,1)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(6,2) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Cub(7,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(7,1)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(7,2) << std::endl;
         StrmWy<<std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Cub(0,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(0,1)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(0,2) << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Cub(1,0)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(1,1)
         << std::setw(16) << std::fixed << std::setprecision(10) << Cub(1,2) << std::endl;
         StrmWy<<std::endl;
                             // Jeszcze raz zapisujemy pierwsze dwa punkt,
                             // aby gnuplot narysowal zamkniętą figure.
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool SaveCoordsToFile( const char *sNazwaPliku,  Rectangle &Rect)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  CoordsToStream(StrmPlikowy, Rect);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool SaveCoordsToFile( const char *sNazwaPliku,  Cuboid &Cub)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  CoordsToStream(StrmPlikowy, Cub);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}
