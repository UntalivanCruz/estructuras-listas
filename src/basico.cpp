#include <iostream>
#include <string>
using namespace std;

struct Persona{
    int id;
    string nombre;
    int edad;
    float Ingresos;
    int *apt;
};

struct Cliente{
    int id;
    Persona *per;
};

//class Persona{}

int main(){
    int var1;
    Persona var2;
    
    var1=10;

    var2.id= 1001;
    var2.nombre="Juan";
    var2.apt=&var1;

    Cliente c1;

    c1.id=1;
    c1.per=&var2;
    
 //   cout<<var2.id<<endl<<var2.nombre<<endl;
 //   cout<<var2.apt<<endl;
 //   cout<<*(var2.apt)<<endl;
    cout<<c1.id<<endl;
    cout<<c1.per->nombre<<endl;
    cout<<*(c1.per->apt)<<endl;
    return 0;
}