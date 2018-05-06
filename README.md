# PID Control

[//]: # (Image References)

[image1]: ./examples/result.GIF "Results"

## Overview

In this application, Self Driving Car is controlled successfully by PID control method. Control is an important topic that makes the vehicle to work in desired conditions (velocity, steering angle, throttle etc.). In this scenario, only steering angle is adjusted during the simulation. As it can be seen above, the car doesn't leave the drivable portion in the map and it successfully completes track. In the near future work, a better controller which is Model Predictive Controller will be developed by considering the dynamics of the car.

## Prerequisites

The project has the following dependencies :

* cmake >= 3.5
* make >= 4.1
* gcc/g++ >= 5.4
* Udacity's simulator (can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases) )

In order to install necessary libraries on Windows, [install-ubuntu.sh](./install-ubuntu.sh) needs to be executed.

## Controller Design

A proportional–integral–derivative controller (PID controller or three term controller) is a control loop feedback mechanism widely used in industrial control systems and a variety of other applications requiring continuously modulated control. A PID controller continuously calculates an error value `e(t)` as the difference between a desired setpoint (SP) and a measured process variable (PV) and applies a correction based on proportional, integral, and derivative terms (denoted P, I, and D respectively) which give the controller its name.[1]

There are many studies on tuning PID parameters in the literature. There are many different methods that optimizes the controller result. Model dynamics is required to execute the many of tuning methods. Here, a simple error based controller is utilized and it gave good control performance. 

Tuning process begins with the adjusting `K_p` parameter. An appropriate value that makes the model stable is chosen but it ends up with high oscillation. To overcome this problem, `K_d` parameter comes into play. `K_d` eliminates the oscillation and it gives a smoother trajectory considering the change of error. If there still exists steady state error, `K_i` parameter is added to the model. `K_i` should be much smaller than `K_p` and `K_d`. Because it has a huge effect on the model, due to the fact that it is multiplied with the summation of the error.

PID Coefficients
- `K<sub>p</sub> - 0.3`
- `K<sub>i</sub> - 0.00001`
- `K<sub>d</sub> - 10.0`

## Compilation and Execution the Project

* Clone the repo and cd to it on a Terminal.
* Create a build file and cd to it `mkdir build && cd build`
* Compile it `cmake .. && make`
* Execute it `./pid`

## Results

![alt text][image1]


[1] https://en.wikipedia.org/wiki/PID_controller



