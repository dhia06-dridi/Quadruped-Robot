# Quadruped Robot

## Description
This project involves the design and implementation of a **bionic quadruped robot**, inspired by a dog, capable of autonomous movement and remote control via **Wi-Fi**. It is equipped with servomotors for locomotion and an HC-SR04 ultrasonic sensor for obstacle detection. Control is managed by an **ESP8266** and a mobile interface created with **RemoteXY**.

## Features
- **Controlled movement** via joystick (forward, turn left/right).
- **Pre-programmed actions**: jump and salute.
- **Obstacle detection** using the HC-SR04 sensor.
- **Wi-Fi connectivity** via ESP8266 for remote control with RemoteXY.

## Hardware Used
- **ESP8266 (NodeMCU)**: Main microcontroller.
- **4 Tower Pro SG90 Servomotors**: Controls the legs.
- **HC-SR04 Sensor**: Detects obstacles.
- **Power Supply**: 3.7V Li-Po battery with voltage regulator.
- **Acrylic chassis**: Supports electronic components.

## Software and Technologies
- **Arduino IDE**: Microcontroller programming.
- **RemoteXY**: Mobile control interface.
- **ROS2 & Isaac Sim**: Advanced simulation and testing.
- **URDF**: Robot modeling for ROS.

## Installation and Usage
### 1. Download the Code
Clone this GitHub repository onto your machine:
```bash
$ git clone https://github.com/dhia06-dridi/Quadruped-Robot.git
$ cd Quadruped-Robot
```

### 2. ESP8266 Configuration
- Install **Arduino IDE** and add the ESP8266WiFi library.
- Upload the **Quadruped_Robot.ino** file to the ESP8266.
- Configure the **Wi-Fi SSID and password** in the code.

### 3. Connect to RemoteXY
- Install the RemoteXY app on your mobile device.
- Connect to the robot's Wi-Fi network.
- Control movements via the graphical interface.

## Repository Structure
```
Quadruped-Robot/
│── 
│   ├── Quadruped_Robot.ino    # Arduino source code
│   ├── RemoteXY.h             # Interface configuration
│   ├── Servo.h                # Servo motor library
│
│── docs/
│   ├── rapport_robot_bionique.pdf   # Detailed project report
│   ├── images/                      # Screenshots and schematics
│
│── README.md   # This file
```

## Code Summary
The **Quadruped_Robot.ino** file contains the main functionalities:
- **Movement management** (forward, turn, jump, salute).
- **HC-SR04 sensor reading** for obstacle detection.
- **Interface with RemoteXY** for Wi-Fi control.
- **Reset servomotors** after each action.
![4a1afc2540a94449be1a5f592d336d9c](https://github.com/user-attachments/assets/ac93f5b9-cf55-4ac1-a56a-1048e6d787a6)

## Command Examples
- **Move forward**: Moves the robot forward.
- **Turn left/right**: Adjusts direction.
- **Jump**: Simulates a jumping motion.
- ![75249550-3cbf-431f-ac0c-012ca557ed17](https://github.com/user-attachments/assets/36452c92-2c14-4787-9ba4-0a575930b9de)

- **Obstacle detection**: Stops the robot if an object is detected within 10 cm.
![robot](https://github.com/user-attachments/assets/fa09eb65-4020-4d62-b175-4dd90389d712)

## Simulation and Testing
- **real world** create a real prototype.
- ![22](https://github.com/user-attachments/assets/edeca72e-1b9f-4eb2-b868-a1f6f3d8cb00)


## Future Improvements
- **Adding a camera** for onboard vision.
- **Optimizing walking algorithms** for smoother movement.
- **Developing a native mobile app** instead of using RemoteXY.

## Author
Developed by **Dhia Dridi & Akrem Azizi** as part of the **Master RAIA** program at the **Higher Institute of Technological Studies of Bizerte (ISET Bizerte)**.

https://youtube.com/shorts/DmwWN7flZXs
## License
This project is licensed under the **MIT** License - see the [LICENSE](LICENSE) file for details.

---
> 🔗 **GitHub Repository**: [https://github.com/dhia06-dridi/Quadruped-Robot](https://github.com/dhia06-dridi/Quadruped-Robot)

