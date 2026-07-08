#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;


int main(){
    std::string inputFileName = "spring_data.txt";
    const float g = 9.81f; // Acceleration due to gravity in m/s^2

    ifstream inputFile(inputFileName);
    ofstream outputFile("spring_output.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file: " << inputFileName << endl;
        return 1;
    }

    std::string line;
         float sumFx = 0.0f;
    float sumF = 0.0f;
    float sumX = 0.0f;
    float sumX2 = 0.0f;
    size_t count = 0;

    float slope = 0.0f;
    float intercept = 0.0f;
    std::getline(inputFile, line); // Read the header line
    while(!inputFile.eof()) {
        float mass = 0.0f;
        float extension = 0.0f;

        // Parse the line to extract mass and extension values
        inputFile >> mass >> extension;
        float force = mass * g; // Calculate the force using F = m * g
        cout << "Mass: " << mass << ", Extension: " << extension << ", Force: " << force << endl;
         sumFx += force * extension;
         sumF += force;
         sumX += extension;
         sumX2 += extension * extension;
         count++;
    }

    if(count == 0) {
        cout << "No data to process." << endl;
        return 1;
    }

    // Calculate the slope (k) and intercept (b) of the linear regression line
    slope =(count * sumFx - sumF * sumX) / (count * sumX2 - sumX * sumX);
    intercept = (sumF - slope * sumX) / count;
    cout << "Slope (k): " << slope << endl;
    cout << "Intercept (b): " << intercept << endl;

    cout<<"Predicting extension for a 0.5kg mass using the linear regression model."<<endl;

    float ForceForPrediction = 0.5f * g; // Force for a 0.5kg mass
    float predictedExtension = (ForceForPrediction - intercept) / slope; // Predict the extension
    cout << "Predicted Extension: " << predictedExtension << endl;

    outputFile << "Slope (k): " << slope << endl;
    outputFile << "Intercept (b): " << intercept << endl;
    outputFile << "Predicted Extension: " << predictedExtension << endl;

    outputFile.close();
    inputFile.close();
    return 0;
}