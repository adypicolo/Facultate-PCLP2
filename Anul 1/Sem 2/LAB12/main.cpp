#include <assert.h>
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class vector
{
  int dim;
  T* buf;

  public:
     vector();
     vector(int , T*);
     vector(const vector&);
     vector & operator=(const vector &);
     ~vector();
	 T& operator[](int i);
     int getDim();

	 friend ostream & operator << (ostream & dev,  vector & v)
     {
	    dev << "Vector:" <<endl;
	    dev << "Nr Elem:" << v.dim << endl;
	    if (v.buf!=NULL)
	    for(int i = 0; i < v.dim; i++) {
		   dev << v.buf[i];//am nevoie de op<< pt T
		   if(i < v.dim-1)
		    	dev << ",   ";
		   else
		    	dev << "." << endl;
		}
        dev<<endl;
	    return dev;
     }

    friend const vector<T> operator+(const vector<T> &a, const vector<T> &b){
        vector<T> c;
        c.dim= a.dim + b.dim;
        c.buf = new T[c.dim];
        for (int i = 0; i < a.dim; i++)
            c[i] = a[i];
        for (int j = 0; j < b.dim; j++)
            c[a.dim+j+1] = b[j];

        return c;
    }

    vector<T>& operator+=(const vector<T> &a){
        *this = *this + a;
        return *this;
    }

    vector<T> getSet(){
        T *aux = new T[dim];
        int contor = 0;
        bool ok = true;
        aux[0] = buf[0];

        for (int i = 0; i < dim; i++){
            for (int j = 0; j < contor; j++)
                if (buf[i] != aux[j])
                    ok = true;
                else { ok = false; break; }

            if (ok == true){
                aux[contor-1] = buf[i];
                contor ++;
            }
            ok = false;
        }
    }


};

template <typename T>
vector<T>::vector( ){
	dim=0;
	buf=NULL;
}

template <typename T>
vector<T>::vector(int d, T*b){
       dim=d;
       if (b==NULL) buf = NULL;
	   else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
            buf[i]=b[i]; //op= in T
        }
     }


template <typename T>
vector<T>::vector(const vector<T>& v){
       dim=v.dim;
       if (v.buf==NULL) buf=NULL;
       else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
             buf[i]=v.buf[i]; //op= in T
        }
	 }


template <typename T>
vector<T>::~vector(){
        delete [] buf; //destr in T
}

template <typename T>
vector<T>&  vector<T>::operator=(const vector &v){
       dim=v.dim;
       if (buf!=NULL) delete [] buf; //destr in T
       if (v.buf==NULL) buf=NULL;
       else{
	      buf=new T[dim]; //constr fara param in T
          for (int i=0;i<dim;i++)
             buf[i]=v.buf[i]; //op= in T
		}
        return *this;
}

template <typename T>
T& vector<T>::operator[](int i){
      assert ((i>-1 && i<dim));
	  return buf[i];  //constr de copiere in T
}

template <typename T>
int vector<T>::getDim(){
   return dim;
}

class complex
{
    double re,im;
    public:
        complex(double r=0,double i=0):re(r),im(i){ }

        friend ostream& operator<<(ostream &d,complex x){

            d<<x.re<<" j"<<x.im;
            return d;
        }


};

template <typename X, typename Y>
class pereche {
 X elem1;
 Y elem2;
public:
pereche(const X &e1, const Y &e2){
 elem1=e1;
 elem2=e2; }

friend ostream& operator<<(ostream &d,const pereche &x){
 d<<x.elem1<<" si " << x.elem2<<endl;
 return d; }
};

int main(){
	 complex *b=new complex[2];
	 b[0]=complex(1,2);
     b[1]=complex(2,2);
	 vector<complex> v(2,b);
     cout<<v;

	 cout<<v[0];

	 v[1]=complex(5,5);
     cout<<v;

     vector<complex> v1(v);
     cout<<v1;

     v=v1;
     cout<<v;

     ///1.
     string *vs;
     vs = new string[3];
     vs[0] = "Am";
     vs[1] = "inca";
     vs[2] = "are";

     ///2.
     vector<string> vsx(3,vs);
     vector<string> b(3,vs);
     vector<string> c;
     c = vsx + b;
     cout << c;

     vector<string> d;
     d += c;

     d.getSet();
     cout << d;

     ///3.

     return 0;
}
