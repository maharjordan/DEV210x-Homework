// Powers and Sine
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

//Takes two integers greater than or equal to zero.
//Returns the result of base to the power of exp
//Returns -1 if the exponent is negative
//Returns -2 if an error occurred
//Warning: Does not check for integer overflow
int pow(int base, int exp){

    if( exp == 0 ){
        return 1;
    }
    
    else if( exp < 0 ){
        return -1;
    }
    
    int total{ 1 };
    
    for( int i = 0; i < exp; i++){
        total *= base;
    }
    
    return total;
}

//Takes the opposite and hypotenuse sides of a triangle
//Returns the sine of the triange
//Returns -1 for zero and negative inputs
//Returns -2 if the opp is greater than the hyp
double sin(double opp, double hyp){
    if( opp <= 0 || hyp <= 0 ){
        return -1;
    }
    
    //The opposite side cannot be longer than the hypotenuse by definition
    if(opp > hyp){
        return -2;    
    }
    
    return opp/hyp;
}

int main()
{
    //Prompt the user as to which function they want
    int option{ 0 };
    while (option != 1 && option != 2){
        cout << "What would you like to calculate?"
        << endl
        << "1. Power"
        << endl
        << "2. Sine"
        << endl
        << "Option ";
        
        //If incorrect input is entered, prompt the user again
        while( !(cin >> option) ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cout << "Incorrect Input."
            << endl
            <<"Option: ";
        }
    }
    
    //Exponent
    if( option == 1){
        
        int base { -1 };
        int exp { -1 };
        
        while(1){
            //Ask for the base
            cout << "What is the base? ";
                
            while( !(cin >> base) ){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                cout << "Incorrect Input."
                << endl
                <<"What is the base? ";
            }
            
            //In case the user enters a decimal input and the value gets truncated
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //Ask for the exponent
            while( exp < 0 ){
                cout << "What is the exponent? ";
                
                while( !(cin >> exp) ){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    cout << "Incorrect Input."
                    << endl
                    <<"What is the exponent? ";
                }
            }
            
            //Check for overflow
            //Max int size if 2,147,483,647. Round down.
            //Therefore, the maximum values occur where exp * ln(base) < ln( 2,100,000,000 )
            if( ( exp * log(base) ) > log(2100000000) ){
                cout << "Resulting Number is too large."
                << endl;
                base = -1;
                exp = -1;
            }
            else{
                break;   
            }
        }
        cout << "The result is " << pow(base, exp) << endl;
    }
    
    
    //Sine
    else{
        double opp{ 0 };
        double hyp{ 0 };
        
        while(1){
            //Ask for the base
            while( opp <= 0 ){
                cout << "What is the opposite side length? ";
                
                while( !(cin >> opp) ){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    cout << "Incorrect Input."
                    << endl
                    <<"What is the opposite side length? ";
                }
            }
            
            //Ask for the exponent
            while( hyp <= 0 ){
                cout << "What is the hypotenuse side length? ";
                
                while( !(cin >> hyp) ){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    cout << "Incorrect Input."
                    << endl
                    <<"What is the hypotenuse side length ? ";
                }
            }
            
            //Make sure it doesnt violate definition of triangle
            if(opp > hyp){
                cout << "Incorrect input. The opposite cannot be longer than the hypotenuse."
                << endl;
                opp = 0;
                hyp = 0;
            }
            else{
                break;
            }
        }
        cout << "The result is " << sin(opp, hyp) << endl;
    }
}
