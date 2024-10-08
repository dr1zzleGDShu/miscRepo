#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;

/*
Design doc

// im ignoring this bcs it make no sense it being this explicitly declared, making my head hurt

variables:
  [float] input price
  [float] output price
  [const int] discount percent
  [float] discount value



psudo:
  produceDiscountedPrice
    [float] input price
    [float] output price
    [const int] discount percent
    [float] discount value

feedback: shouldnt allow neg inputs and % needs to be 0-100

*/


float produceDiscountedPrice(tuple<float, float>);
tuple<float, float> getDiscountValues();


float myFloatClamp(float varIn, float minVar, float maxVar){
  if (varIn < minVar){
    return minVar;
  }else if (varIn > maxVar){
    return maxVar;
  }
  return varIn;
}


int discountCalcMain(){
  cout << produceDiscountedPrice(getDiscountValues());
  cout << endl;
  return 0;
}


tuple<float, float> getDiscountValues(){
  cout << "Input the value to discount\n£ ";

  float origPrice;
  cin >> origPrice;
  cout << "Input the percent to discount\n";
  float discountPercent;
  cin >> discountPercent;

  origPrice = abs(origPrice);
  
  discountPercent = myFloatClamp(discountPercent, 0, 100);

  return tuple<float,float> (origPrice,discountPercent);
}


float produceDiscountedPrice(tuple<float, float> inVars){

  float priceIn = get<0>(inVars);  float discountPercentIn = get<1>(inVars);

  float priceOut, discountValue;
  discountValue = priceIn*(discountPercentIn*0.01); 
  priceOut = priceIn-discountValue;

  priceOut = roundf(priceOut* 100) / 100; // round to nearest penny
  cout << "Final value after discount £"; // amazing bodge to get the formatting right
  return priceOut;
}
