#include <iostream>
#include <sstream>
using namespace std;

struct complex_t  {
 float real;
 float imag;
};

bool read( istream & stream , complex_t & complex)
{ char k;
  bool result= true;
  float real,imag ;
 
 
  if (stream >> k&&k == '(' && stream >> real && stream >> k&&k == ',' && stream >> imag && stream >> k&&k == ')' ) 
  
  {complex.real=real;
  complex.imag=imag;}
  
  else { result= false ;
         cout << "An error has occured while reading input data";}
  return result;
}

bool write( ostream &stream , complex_t complex)
 { return bool (stream << '(' << complex.real << ',' << complex.imag << ')' << endl );
   
 }

complex_t add(complex_t a, complex_t b)
   { complex_t complex;
       
        complex.real= a.real + b.real;
        complex.imag= a.imag + b.imag;
     
     return complex;
     
   }
 
  complex_t sub(complex_t a, complex_t b)
   { complex_t complex;
       
        complex.real= a.real - b.real;
        complex.imag= a.imag - b.imag;
     
     return complex;
   }
   
   
   complex_t mul(complex_t a, complex_t b)
   { complex_t complex;
       
        complex.real= (a.real * b.real- a.imag * b.imag)  ;
        complex.imag= (a.imag * b.real + a.real * b.imag);
     
     return complex;
   }
 
  complex_t div(complex_t a, complex_t b)
   { complex_t complex;
       
        complex.real= (a.real * a.real + a.imag * b.imag)/(b.real * b.real + b.imag * b.imag);
        complex.imag= (a.imag * b.real - a.real * b.imag)/(b.real * b.real + b.imag * b.imag);
     
     return complex;
   }
   int main()
   {
     complex_t a,b,res;
     string str;
     getline( cin , str );
      
    istringstream stream(str);
     char oper;
     
     if (read(stream,a) && stream >> oper && read(stream,b)) { switch (oper)
     { case '+': { res= add(a,b); break;}
      
       case '-': {res= sub(a,b); break;}
       
       case '*': {res= mul(a,b); break;}
       
       case '/': {res= div(a,b); break;}
        
        default: {cout << "error op" ;break;}
        
     }
      write(cout, res);
    }
     
   } 
