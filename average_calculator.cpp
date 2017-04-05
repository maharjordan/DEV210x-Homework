// Average Calculator
#include <iostream>
#include <limits>

using namespace std;

#define LIMIT 500

//Calculates the mean
double mean(int input[], int size){
    int sum = 0;
    
    for (int i = 0; i < size; i++){
        sum += input[i];
    }

    return double(sum) / size;
}

//Calculates the median
double median(int input[], int size){
    int temp{};
    for (int j = 0; j < size - 1; j++){
        for(int i = 0; i < size - j - 1; i++){
            if( input[i] > input[i + 1] ){
                temp = input[i + 1];
                input[i + 1] = input[i];
                input[i] = temp;
            }
        }
    }
    
    //If there is an even number of inputs
    if (size % 2 == 0){
        return ( (double)input[ size / 2 ] + (double)input[ ( size / 2 ) - 1 ] ) / 2;
    }
    //If there is an odd number of inputs
    else{
        return input[ (size / 2) ];
    }
}


int main()
{
  //Declare an array to hold the number inputs
  int input[LIMIT];
  
  cout << "Enter the numbers you want to calculate the average of. When finished, enter non-numeric character." << endl;
  
  //Put the inputs into an array
  int size = 0;
  cout << "Number: ";
  while( (cin >> input[size]) ){
       if(size > LIMIT) break;
       cout <<"Number: ";
       size ++;
  }
    //Check for inputs
    if (size == 0){
        cout <<"No numbers were entered" << endl;
        return 0;
    }
    
    //Prompt user for which type of average they would like calculated
    int option{ 0 };
    while (option != 1 && option != 2){
        cout << "What type of average would you like to calculate?"
        << endl
        << "1. Mean"
        << endl
        << "2. Median"
        << endl
        << "Option ";
        
        //If incorrect input is entered, prompt the user again
        cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while( !(cin >> option) ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            cout << "Incorrect Input."
            << endl
            <<"Option: ";
        }
    }
    
    double average{};
    if(option == 1) average = mean(input, size);
    else average = median(input, size);
    
    
    cout << "The average is " << average << endl;
    return 0;
}