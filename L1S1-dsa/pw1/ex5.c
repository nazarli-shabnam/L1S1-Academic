#include <stdio.h>
#include <math.h>

// Write an algorithm, a flow chart (and a C program) to help user to choose which
// rent is more benefit for him if he want to go from Paris to Strasbourg (500km):
//  Rent a Mercedes cost 100$ per day with 250 free km and 1$ for each extra km;
//  Rent a BMW cost 80$ per day with 300 free km and 1.2$ for each extra km;
//  Rent a Tesla cost 180$ per day with 250 free km and 20$ per charge (each charge can
// do 200km).
// Test your algorithm/flow chart by hand before writing your C code!

int main()
{
    const int distance = 500;
    const float mercedesCostPerDay = 100.0;
    const float bmwCostPerDay = 80.0;
    const float teslaCostPerDay = 180.0;
    const int mercedesFreeKm = 250;
    const int bmwFreeKm = 300;
    const int teslaFreeKm = 250;
    const float mercedesExtraKmCost = 1.0;
    const float bmwExtraKmCost = 1.2;
    const float teslaChargeCost = 20.0;
    const int teslaChargeDistance = 200;

    float totalCostMercedes, totalCostBMW, totalCostTesla;
    if (distance <= mercedesFreeKm)
    {
        totalCostMercedes = mercedesCostPerDay;
    }
    else
    {
        int extraKm = distance - mercedesFreeKm;
        totalCostMercedes = mercedesCostPerDay + (extraKm * mercedesExtraKmCost);
    }

    if (distance <= bmwFreeKm)
    {
        totalCostBMW = bmwCostPerDay;
    }
    else
    {
        int extraKm = distance - bmwFreeKm;
        totalCostBMW = bmwCostPerDay + (extraKm * bmwExtraKmCost);
    }
    if (distance <= teslaFreeKm)
    {
        totalCostTesla = teslaCostPerDay;
    }
    else
    {
        int extraKm = distance - teslaFreeKm;
        int chargesNeeded = (int)ceil(extraKm / (float)teslaChargeDistance);
        totalCostTesla = teslaCostPerDay + (chargesNeeded * teslaChargeCost);
    }
    if (totalCostMercedes < totalCostBMW && totalCostMercedes < totalCostTesla)
    {
        printf("Rent a Mercedes: $%.2f\n", totalCostMercedes);
    }
    else if (totalCostBMW < totalCostMercedes && totalCostBMW < totalCostTesla)
    {
        printf("Rent a BMW: $%.2f\n", totalCostBMW);
    }
    else
    {
        printf("Rent a Tesla: $%.2f\n", totalCostTesla);
    }

    return 0;
}

// Algorithm
/*
1. Start
2. Define Constants:
   distance = 500 km
   mercedesCostPerDay = 100
   bmwCostPerDay = 80
   teslaCostPerDay = 180
   mercedesFreeKm = 250
   bmwFreeKm = 300
   teslaFreeKm = 250
   mercedesExtraKmCost = 1
   bmwExtraKmCost = 1.2
   teslaChargeCost = 20
   teslaChargeDistance = 200
3. Calculate Costs:
   For Mercedes:
      If distance <= mercedesFreeKm:
        totalCostMercedes = mercedesCostPerDay
      Else:
        extraKm = distance - mercedesFreeKm
        totalCostMercedes = mercedesCostPerDay + (extraKm * mercedesExtraKmCost)
   For BMW:
      If distance <= bmwFreeKm:
        totalCostBMW = bmwCostPerDay
      Else:
        extraKm = distance - bmwFreeKm
        totalCostBMW = bmwCostPerDay + (extraKm * bmwExtraKmCost)
   For Tesla:
      If distance <= teslaFreeKm:
        totalCostTesla = teslaCostPerDay
      Else:
        extraKm = distance - teslaFreeKm
        Calculate number of charges needed:
           chargesNeeded = ceil(extraKm / teslaChargeDistance)
           totalCostTesla = teslaCostPerDay + (chargesNeeded * teslaChargeCost)
4. Compare Costs:
    If totalCostMercedes < totalCostBMW and totalCostMercedes < totalCostTesla:
        Print "Rent a Mercedes"
    Else if totalCostBMW < totalCostMercedes and totalCostBMW < totalCostTesla:
        Print "Rent a BMW"
    Else:
        Print "Rent a Tesla"
5. End
*/

/*
                                    Flow chart
Start (Oval)

    Input total distance (D = 500 km) (Parallelogram)

    Calculate the cost for Mercedes:
    Free km = 250
    If D > 250, extra km = D - 250
        Extra cost = Extra km * $1
        Total cost = $100 (daily) + extra cost (Rectangle)

    Calculate the cost for BMW:
    Free km = 300
    If D > 300, extra km = D - 300
        Extra cost = Extra km * $1.2
        Total cost = $80 (daily) + extra cost (Rectangle)

    Calculate the cost for Tesla:
    Free km = 250
    If D > 250, extra km = D - 250
        Number of extra charges = ceil(Extra km / 200)
        Charging cost = Number of charges * $20
        Total cost = $180 (daily) + Charging cost (Rectangle)
    Compare the costs (Diamond)

    If Mercedes is the lowest, choose Mercedes.
    If BMW is the lowest, choose BMW.
    If Tesla is the lowest, choose Tesla.
    Display the lowest cost option (Parallelogram)

End (Oval)*/