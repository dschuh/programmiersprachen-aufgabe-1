#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES
#include <catch.hpp>
#include <cmath>
#include <cstdint>

int number1_3 (){ // berechnet die kleinste Zahl die durch die Zahlen 1 bis 20 teilbar sind
  int number=0;
  bool done = false;
  while (done==false){
      if (number !=0 && number%2==0 && number%3==0 && number%4==0 && number%5==0 && number%6==0 && number%7==0 && number%8==0 
       && number%9==0 && number%10==0 && number%11==0 && number%12==0 && number%13==0 && number%14==0
       && number%15==0 && number%16==0 && number%17==0 && number%18==0 && number%19==0 && number%20==0){
        done=true;
        std :: cout << "Die kleinste Zahl, welche durch die Zahlen 1 bis 20 teilbar ist, ist :" << number << "\n";
        } 
     number+=20;
  }
}

int gcd (int a ,int b){    //berechnet den größten geminsamen Teiler zweier Zahlen
if (b==0)
return a;
else
return gcd(b, a%b);
}
TEST_CASE ("describe_gcd" , "[gcd]" )
{
  REQUIRE ( gcd (2 ,4) == 2);
  REQUIRE ( gcd (9 ,6) == 3);
  REQUIRE ( gcd (3 ,7) == 1);
}

int checksum (int a){ //berechnet die Quersumme einer Zahl
  int quersumme=0;
  while (a > 0) {
    quersumme += a % 10;
    a /= 10;
  }
return quersumme;
}
TEST_CASE ("describe_checksum" , "[checksum]" )
{
  REQUIRE ( checksum (116236) == 19);
  REQUIRE ( checksum (111111) == 6);
  REQUIRE ( checksum (287346) == 30);
}

int sumMultiples(){ //addiert alle Zahlen von 1 bis einschließlich 1000 auf, die durch 3 oder 5 teilbar sind
  int sum=0;
  for(int i=1; i<1001; i++){
    if(i%3==0 || i%5==0){
      sum += i;
    }
  }
  return sum;
}

double fract (double in){
  while (in>1){
    in -= 1;
  }
  return in;
}
TEST_CASE ("describe_fract", "[fract]")
{
  REQUIRE (fract(123.456)==Approx(0.456));
  REQUIRE (fract(84793.34456)==Approx(0.34456));
  REQUIRE (fract(4896.7343)==Approx(0.7343));
}

double cylinder_getSurfaceArea(double heighth, double radius){
  return 2*M_PI*radius*(radius + heighth);
}
TEST_CASE ("describe_cylinder_getSurfaceArea", "[cylinder_getSurfaceArea]")
{
  REQUIRE (cylinder_getSurfaceArea(2, 5)==Approx(219.91148));
}

double cylinder_getVolume(double heighth, double radius){
  return pow(radius, 2)*M_PI*heighth;
}
TEST_CASE ("describe_cylinder_getVolume", "[cylinder_getVolume]")
{
  REQUIRE (cylinder_getVolume(2, 5)==Approx(157.08));
}

int64_t factorial(int64_t n){
  if(n<1) return 1;
    else   return n * factorial(n-1); 
}
TEST_CASE ("describe_factorial", "[factorial]")
{
  REQUIRE (factorial(5)==120);
  REQUIRE (factorial(9)==362880);
  REQUIRE (factorial(13)==6227020800);
}

int64_t binomial (int64_t n, int64_t k){
  return factorial(n)/(factorial(n-k)*factorial(k));
}
TEST_CASE ("describe_binomial", "[binomial]")
{
  REQUIRE (binomial(10, 6)==210);
  REQUIRE (binomial(13, 3)==286);
  REQUIRE (binomial(18, 7)==31824);
  REQUIRE (binomial(4, 0)==1); //test n über 0 ==1
}

bool is_prime(int p){
  if (p <= 2) {return (p == 2);}
      for (long i = 2; i * i <= p; i++) {
         if (p % i == 0) {return false;}
        }
    return true; 
}
TEST_CASE ("describe_is_prime", "[is_prime]")
{
  REQUIRE (is_prime(13)==true);
  REQUIRE (is_prime(49)==false);
  REQUIRE (is_prime(561)==false);
}

int main(int argc, char* argv[])
{
  number1_3();
  std::cout << "Die Summe der durch 3 und 5 teilbaren Zahlen von 1 bis 1000 ist: " << sumMultiples() << "\n";
  return Catch::Session().run(argc, argv);
}
