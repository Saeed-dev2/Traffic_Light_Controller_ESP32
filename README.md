# Traffic Signal Control System

This project simulates a traffic signal system using an ESP32 microcontroller. The system controls three LEDs (green, yellow, and red) connected to GPIO pins, mimicking the behavior of a real traffic light. The LEDs are activated in sequence with appropriate delays to represent the standard traffic signal cycle.

## Features

- **Green LED**: Represents the "Go" signal, stays on for 1 minute.
- **Yellow LED**: Represents the "Caution" signal, stays on for 3 seconds.
- **Red LED**: Represents the "Stop" signal, stays on for 1 minute.
- **Task-based Control**: Uses FreeRTOS tasks to manage the LED Sequence.

## Prerequisites

- **ESP32 Development Board**
- **ESP-IDF Framework**: Ensure you have the ESP-IDF development environment set up.
- **LEDs**: Green, Yellow, and Red LEDs in this project.
- **Resistors**: Appropriate resistors for each LED.
- **Breadboard and Jumper Wires**: For assembling the circuit.

## Installation

1. Clone this repository to your local machine:

    ```bash
    git clone https://github.com/Saeed-dev2/Traffic_Light_Controller_ESP32.git
    ```

2. Navigate to the project directory:

    ```bash
    cd traffic-signal-system
    ```

3. Build the project:

    ```bash
    idf.py build
    ```

4. Flash the firmware to the ESP32:

    ```bash
    idf.py flash
    ```

5. Monitor the output:

    ```bash
    idf.py monitor
    ```
    
    ` ctrl+] ` 

## Circuit Diagram

Connect the LEDs to the ESP32 GPIO pins as follows:

- **Green LED**: GPIO 2
- **Yellow LED**: GPIO 4
- **Red LED**: GPIO 5

Ensure each LED is connected in series with a current-limiting resistor.

## Usage

Once the firmware is flashed and the ESP32 is powered, the traffic signal system will automatically start. The LEDs will cycle through green, yellow, and red states, with the specified delays.

## Author
`M.Saeed`

## Acknowledgments

- **ESP-IDF**: For providing the development framework.
- **FreeRTOS**: For task management and scheduling.

