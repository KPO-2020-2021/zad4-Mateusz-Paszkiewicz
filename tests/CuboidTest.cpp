TEST_CASE("Cuboid Class parametric Contructor Test")
{
  double arr[8][3]={{2,3,3},{22,3,3},{2,18,3},{22,18,3},{2,18,28},{22,18,28},{2,3,28},{22,3,3}};
  Cuboid test=Cuboid(arr);

    CHECK(test(0,0) == 2);

}
