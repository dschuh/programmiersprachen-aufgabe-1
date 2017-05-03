#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

double mileToKilometer(double miles){
  return miles*1.609344;
}
TEST_CASE ("describe_mileToKilometer", "[mileToKilometer]")
{
  REQUIRE (mileToKilometer(1)==1.609344);
  REQUIRE (mileToKilometer(7654)==12317.918976);
  REQUIRE (mileToKilometer(561)==902.841984);
}

int main(int argc, char* argv[])
{
  std::cout << "Bitte geben Sie die umzurechnende Anzahl an Meilen ein :\n";
  double miles;
  std::cin >> miles;
  std::cout << miles << " Meilen sind " << mileToKilometer(miles) << " Kilometer \n" ;
  return Catch::Session().run(argc, argv);
}