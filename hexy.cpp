#include <iostream>
#include <cstdlib>
#include <math.h>

void help() {
  std::cout << "\033[1;31mUsage: BLAH!\033[0m\n"; 
  exit(-1);
}

void deid(std::string msg)
{
  std::cout << "\033[1;31m" << msg << "\033[0m\n"; 
  exit(-1);
}

int getVal(char chhar)
{
  int numVal = (int)chhar;
  if (numVal > 47 && numVal < 58)
      return numVal - 48;
  if (numVal > 64 && numVal < 71)
      return numVal - 55;
  if (numVal > 96 && numVal < 103)
      return numVal - 87;
  deid("That's no a hex number, ya fanny");
}
           
int main(int argc, char **argv)
{
  using namespace std;
  cout << "\n\033[38;5;47mHexy Hex Me!\033[0m\n" << endl; 
  if ( argc != 2 ) 
    help();

  string hexstring;
  hexstring = argv[1];
  int i, lenny = hexstring.size();
  if ( hexstring[0] != '0' || !(hexstring[1] == 'x' || hexstring[1] == 'X') )
    deid("That's no a hex number, ya fanny");

  int decimalTotal = 0;

  for ( i = 2; i < lenny ; i++ ) {
    decimalTotal += pow(16.0, (lenny - i - 1)) * getVal(hexstring[i]);
  }
  cout << "Decimal: " << decimalTotal << endl;

  return 0;
}
