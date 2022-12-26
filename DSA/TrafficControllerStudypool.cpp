#include <iostream>
using namespace std;

// Creating the Struct named Month to store traffic counts for three of the area's trans-bayBridge bridges
struct month
{
    double goldenGateBridge, bayBridge, sanMateoBridge;
};

int main()
{
    // Creating an array of 3 months because we want to store data for three months

    month months[3];
    int i;

    // INPUT
    // Getting the traffic counts for each bridge for each month

    for (i = 0; i < 3; i++)
    {
        cout << "Enter month " << i + 1 << " traffic across the Golden Gate Bridge: ";
        cin >> months[i].goldenGateBridge;
        cout << "Enter month " << i + 1 << " traffic across the bayBridge Bridge: ";
        cin >> months[i].bayBridge;
        cout << "Enter month " << i + 1 << " traffic across the San Mateo Bridge: ";
        cin >> months[i].sanMateoBridge;
    }

    // Processing
    // Calculating the average traffic counts for each bridge
    
    double goldenGateBridge = 0, bayBridge = 0, sanMateoBridge = 0, max = months[0].goldenGateBridge;

    for (i = 0; i < 3; i++)
    {
        goldenGateBridge += months[i].goldenGateBridge;
        bayBridge += months[i].bayBridge;
        sanMateoBridge += months[i].sanMateoBridge;
        if (months[i].goldenGateBridge > max)
            max = months[i].goldenGateBridge;
        if (months[i].bayBridge > max)
            max = months[i].bayBridge;
        if (months[i].sanMateoBridge > max)
            max = months[i].sanMateoBridge;
    }

    // OUTPUT
    // Displaying the average traffic counts for each bridge

    printf("Average traffic across Golden Gate bridge: %.2lf\n", goldenGateBridge / 3);
    printf("Average traffic across bayBridge bridge: %.2lf\n", bayBridge / 3);
    printf("Average traffic across San Mateo bridge: %.2lf\n", sanMateoBridge / 3);
    printf("Highest traffic across all bridges: %.2lf\n", max);
    return 0;
}