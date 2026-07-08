# Challenge 1: Hooke's Law Spring Constant Analysis

This repository contains a C++ script designed to process experimental spring data, calculate applied forces, execute a linear regression analysis, and predict future mechanical behaviors based on Hooke's Law (\(F = k \cdot x\)).

## Table of Contents
* [Overview](#overview)
* [File Structure](#file-structure)
* [Prerequisites](#prerequisites)
* [Data Format](#data-format)
* [How to Run the Code](#how-to-run-the-code)
* [Expected Outputs](#expected-outputs)

## Overview
The program automates physical data analysis by performing the following core operations:
1. **Parses data** from an external data sheet while automatically skipping the text headers.
2. **Converts mass variables** into force vectors using standard acceleration due to gravity (\(g = 9.81 \, \text{m/s}^2\)).
3. **Applies a linear least-squares regression** mapping Force vs. Extension to extract the slope, which directly represents the **Spring Constant (\(k\))** in Newtons per meter (\(\text{N/m}\)).
4. **Predicts the structural extension** profile if a new \(0.5 \, \text{kg}\) load were suspended from the system.
5. **Generates an export manifest** summarizing all calculations inside a structured text file.

## File Structure
Ensure your working directory contains the following file placement before launching execution:
* `spring.cpp` — The core C++ execution script.
* `spring_data.txt` — The plain-text source sheet containing experiment values.
* `spring_output.txt` — *(Auto-generated)* The destination report created after running the script.


## Data Format
The input file `spring_data.txt` must utilize single-space or tab delimiters with a text header. Ensure it matches this design pattern:

```text
Mass(kg) Extension(m)
0.05 0.012
0.10 0.024
0.15 0.036
0.20 0.049
0.25 0.061
0.30 0.073
0.35 0.085
0.40 0.098
```

## How to Run the Code

1. Place your target data into a text file named exactly `spring_data.txt` in the script directory.
2. Open your command prompt or terminal environment.
3. Execute the script file by running:

```bash
g++ spring.cpp -o spring
```

4. Run the executable file generated
```bash
 ./spring
```


## Expected Outputs



### Generated Results
A new file named `spring_output.txt` will appear instantly in your workspace. Using the provided sample dataset, your calculation metrics will resolve to the following values:

```text
Slope (k): 39.998
Intercept (b): 0.0173588
Predicted Extension: 0.122197

```
