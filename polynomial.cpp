#include<iostream>
#include<cmath>
using namespace std;

class Term{
    public:
        int coefficient;
        int power;
        Term(){
            coefficient = 0;
            power = 0;
        }
        Term(int coeff, int pow){
            coefficient = coeff;
            power = pow;
        }
};
class polynomial{
    public:
        int *coefficient;
        int *power;
        int capacity;
        int size;

        polynomial(){
            capacity = 4;   // 0 rakha tha pehle — capacity 0 se new int[0] bekaar hai, kam se kam 1 chahiye
            size = 0;
            coefficient = new int[capacity];
            power = new int[capacity];
        }

        // parameters mein type likhna zaroori tha (coeff,pow,c,s bina type ke compile nahi hote)
        polynomial(int coeff, int pow, int c, int s){
            capacity = c;
            size = s;
            coefficient = new int[capacity];
            power = new int[capacity];
            for(int i = 0; i < size; i++){
                coefficient[i] = coeff;
                power[i] = pow;
            }
        }
        void resize(){
            capacity = capacity * 2;
            int *newCoeff = new int[capacity];
            int *newPow = new int[capacity];
            for(int i = 0; i < size; i++){
                newCoeff[i] = coefficient[i];
                newPow[i] = power[i];
            }
            delete[] coefficient;
            delete[] power;
            coefficient = newCoeff;
            power = newPow;
        }
        void addterms(int coeff, int pow){
            if(size >= capacity){       
                resize();
            }
            coefficient[size] = coeff;  
            size++;                     
		   }

        int getdegree(){
            int maxdegree = power[0];
            for(int i = 0; i < size; i++){
                if(power[i] > maxdegree){
                    maxdegree = power[i];
                }
            }
            return maxdegree;
        }
        int getcoefficient(int pow){
            for(int i = 0; i < size; i++){
                if(power[i] == pow)
                    return coefficient[i];
            }
            return 0; 
        }
        int operator()(int x){
            int result = 0; // "rssult" typo bhi tha
            for(int i = 0; i < size; i++){
                result = result + coefficient[i] * (int)pow(x, power[i]);
            }
            return result;
        }

        ~polynomial(){
            delete[] coefficient;
            delete[] power;
        }

        polynomial(const polynomial &p1){
            size = p1.size;
            capacity = p1.capacity;
            coefficient = new int[capacity];
            power = new int[capacity];
            for(int i = 0; i < size; i++){
                coefficient[i] = p1.coefficient[i];  // pehle p1.coefficient (bina index) tha
                power[i] = p1.power[i];
            }
        }
       

        polynomial& operator=(const polynomial &p1){
            if(this == &p1){
                return *this;
            }
            delete[] coefficient;
            delete[] power;
            size = p1.size;       
            capacity = p1.capacity;
            coefficient = new int[capacity];
            power = new int[capacity];
            for(int i = 0; i < size; i++){
                coefficient[i] = p1.coefficient[i];
                power[i] = p1.power[i];
            }
            return *this;
        }

        polynomial operator+(const polynomial &p1){
            polynomial result;
            for(int i = 0; i < size; i++){
                int newcoeff = coefficient[i] + p1.coefficient[i];
                result.addterms(newcoeff, power[i]);
            }
            return result;
        }

        polynomial operator*(polynomial &p1){
            polynomial result;
            for(int i = 0; i < size; i++){
                int newcoeff = coefficient[i] * p1.coefficient[i];
                int newpow = power[i] + p1.power[i];
                result.addterms(newcoeff, newpow);
            }
            return result;
        }

        polynomial operator-(polynomial &p1){
            polynomial result;
            for(int i = 0; i < size; i++){
                int newcoeff = coefficient[i] - p1.coefficient[i];
                result.addterms(newcoeff, power[i]); // subtraction mein bhi power same rehta hai
            }
            return result;
        }

        polynomial derivative(){
            polynomial result;
            for(int i = 0; i < size; i++){
                int newcoeff = coefficient[i] * power[i];
                int newpow = power[i] - 1;
                if(power[i] != 0)             // constant term (power 0) ki derivative 0 hoti hai, skip
                    result.addterms(newcoeff, newpow);
            }
            return result;
        }

        polynomial antiderivative(){
            polynomial result;
            for(int i = 0; i < size; i++){
                int newpow = power[i] + 1;         // pehle power INCREMENT karke phir usi se divide
                int newcoeff = coefficient[i] / newpow; // karna tha (old power se divide karna ghalat tha)
                result.addterms(newcoeff, newpow);
            }
            return result;
        }

        void clear(){
            for(int i = 0; i < size; i++){
                coefficient[i] = 0;
                power[i] = 0;    
            }
            size = 0;               
        }

        void setcoefficient(int coeff, int pow){
            for(int i = 0; i < size; i++){
                if(power[i] == pow){
                    coefficient[i] = coeff;   
                    return;
                }
            }
            addterms(coeff, pow);            
        }
        friend ostream& operator<<(ostream &out, const polynomial &p){
            for(int i = 0; i < p.size; i++){
                out << p.coefficient[i] << "*x^" << p.power[i];
                if(i != p.size - 1) out << " + ";
            }
            return out;
        }
};