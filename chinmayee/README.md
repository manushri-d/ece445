## Chinmayee Worklog

## 2024-09-09 Initial Idea
Researched the LED strips and what kind of heart rate sensor we would have to use, 

## 2024-09-16 Parts research
Looked into the heart rate sensor and what kind of signal it would require. Also looked into the ESP-32 chip. 

## 2024-09-23 Design Document work
We started working on the design document. Worked on the power management subsystem for the wearable parts and the LED control subsystem as well as their requirement verification parts. 

## 2024-09-30 Proposal Regrade work
Changed the format of the proposal with TA feedback about high-level requirements. 

## 2024-10-7 Design Document feedback
Presented to Ta’s and professor and got feedback on systems and to be more specific with the high-level requirements. Also considered how the heart rate sensor would be placed on a users hand properly. 

## 2024-10-14 to 2024-10-28 Initial PCB work
We finalized the schematic and started working on specific parts. I worked on the microphone, LEDs, and USB components of the PCB design. 

## 2024-11-6 PCB update
Fixed some errors in the schematic and updated the PCB to include other parts such as the antenna and crystal components. We hope this PCB which made the round 4 deadline will have newer updates and work better. 

## 2024-11-11 PCB update
It is now the final round of our PCB. We have finalized the design and also ordered it through PCBway on our way as we made some additional changes to the schematic and realized a couple areas were not connected correctly. Shown below is our final schematic. 
<img width="854" alt="PNG image" src="https://github.com/user-attachments/assets/d3eb6df0-45a8-4665-aed4-86c2cd2d9a89" />
This is our wearable system which includes the heart rate sensor that the user must touch to be used as the data to change the brightness of our lighting strip.
<img width="847" alt="Screenshot 2024-12-11 at 3 27 10 PM" src="https://github.com/user-attachments/assets/38d7426d-4319-488c-9976-a83280f31fce" />
Here is a picture of the final mounted subsystem schematic which is what the LED strip is mounted on and will also read in tbe background noise of whatever media the user is consuming. 

## 2024-11-18 Mock Demo Week
We realized we were slightly behind on this project and just got 3 separate red, green, and blue LEDs to blink according to the background noise. We were having a hard time getting our heart rate sensor the read the heart rate data accurately. 

## 2024-11-18 Thanksgiving Break
My partner did some of the code for the ESP-32 over break (great job Anusha).

## 2024-11-18 Demo Week
We were able to get the heart rate data to work which can be verified with the Apple Watch shown below. 
<img width="340" alt="Screenshot 2024-12-11 at 3 35 59 PM" src="https://github.com/user-attachments/assets/77844744-b4ea-4da6-b6cc-f26e9f26951a" />
We were also able to get the lights to change with the change of music which can be shown in a video and will be included in our final presentation. We had some trouble with finding the right parts but we got our breadboard to work even if our PCB didn't. While my partners were working on the ESP32 code, I was soldering the parts onto the PCB. A couple parts such as the crystal and USB connector did not fit accordingly so our PCB did not ultimately work. My partner also 3D printed an enclosure for both our wearable and mounted subsystem which is shown below. 
![IMG_7931](https://github.com/user-attachments/assets/fbb38299-b87d-4086-ab24-61d1dffdbd96)
![IMG_7942](https://github.com/user-attachments/assets/4b9ab48e-7f8e-44cc-b184-1436b1c584c3)





