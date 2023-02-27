#include <iostream>
#include <fstream>

using namespace std;

// Function to calculate the total cost for in-patients
double calculateTotalCost(int numDays, double dailyRate, double medCost, double serviceCost) {
    return numDays * dailyRate + medCost + serviceCost;
}

// Function to calculate the total cost for out-patients
double calculateTotalCost(double medCost, double serviceCost) {
    return medCost + serviceCost;
}

int main() {
    char patientType;
    int numDays;
    double dailyRate, medCost, serviceCost, totalCost;

    cout << "Enter patient type (I for in-patient, O for out-patient): ";
    cin >> patientType;

    if (patientType == 'I' || patientType == 'i') {
        // In-patient information input
        cout << "Enter number of days in hospital: ";
        cin >> numDays;
        cout << "Enter daily rate: ";
        cin >> dailyRate;
        cout << "Enter medication cost: ";
        cin >> medCost;
        cout << "Enter service cost: ";
        cin >> serviceCost;

        // Calculate total cost for in-patients
        totalCost = calculateTotalCost(numDays, dailyRate, medCost, serviceCost);
    }
    else if (patientType == 'O' || patientType == 'o') {
        // Out-patient information input
        cout << "Enter medication cost: ";
        cin >> medCost;
        cout << "Enter service cost: ";
        cin >> serviceCost;

        // Calculate total cost for out-patients
        totalCost = calculateTotalCost(medCost, serviceCost);
    }
    else {
        cout << "Invalid patient type entered." << endl;
        return 0;
    }

    // Output total cost
    cout << "Total cost: $" << totalCost << endl;

    // Write report to file
    ofstream report("report.txt");
    report << "Patient type: " << patientType << endl;
    if (patientType == 'I' || patientType == 'i') {
        report << "Number of days in hospital: " << numDays << endl;
        report << "Daily rate: $" << dailyRate << endl;
    }
    report << "Medication cost: $" << medCost << endl;
    report << "Service cost: $" << serviceCost << endl;
    report << "Total cost: $" << totalCost << endl;
    report.close();

    return 0;
}
