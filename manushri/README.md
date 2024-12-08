## Manushri Worklog

## 2024-09-09 Initial Idea
Did some preliminary research on the idea. Looked into how to modify led lights, and if it is possible to take external inputs.

## 2024-09-16 Parts research
Looked into ESP32-C3 to be a big component of project. This would work with bluetooth and sending the data from wearable system to mounted system.

## 2024-09-23 Design Document work
Started working on the design document. Created a visual aid to show how we would use both microphone and heart rate sensor to then be computed and come up with an output

## 2024-09-30 Proposal Regrade work
Changed entire format of document to be more professional. Did research into parts needed, and reevaluated use of them in the circuit schematics. Also redrew visual aids to work with TA feedback.

## 2024-10-7 Design Document feedback
After receiving feedback on the design document, we have moved on to modifying our priorities. Both TAs, Prof and Peer feedback are useful to change up some things. Working on solidifying components for both wearable and mounted subsystem

## 2024-10-14 to 2024-10-28 Initial PCB work
Finalized circuit schematic and started working on PCB. Split the PCB work in round robin style, with each person working on it at one time. We have 2 PCBs, but I mostly worked on the wearable component. Successfully made order by audit

## 2024-11-6 PCB update
Realized we were lacking flash, crystal, and antenna, all crucial parts of the PCB. I started redoing the wearable system circuit schematic, and did initial connections for the PCB aspect of it. Also organized it to make it seem more professional and easy to follow. Made order after a long day!

## 2024-11-13 Starting Arduino code with breadboard
Started working on breadboard after getting the modules. Starting the Arduino code was difficult, as none of us had prior experience. I searched up a lot of initial Arduino tutorials to learn how the software worked. Played around with flashig the ESP32 Wroom module for the first time.

## 2024-11-20 Battery Life
Started inital work on LED strip connections on breadboard. Tried using MOSFETs to connect. Connected 9V battery to the led strips. Thought of potential issues if this was made into a actual product that consumers could use, and decided that battery life is a major point of concern. Looking into online resources, I found an equation: Runtime (hours) = Battery Capacity (mAh) / (Current Draw (mA)) * Efficiency Factor). We have a 9V battery with a 500 miliampere-hours capacity, and our led strip has a 5W power rating which can be converted to a 560 mA draw. Based on the MOSFET efficiency of 90%, I found that the runtime after calculations would be about 1 hour. The runtime is quite short, so try to figure out how to increase the runtime to the length of a movie.

## 2024-11-27 Thanksgiving Break
We got the new PCBs over Thanksgiving break. We will attach the parts for the PCB next week.

## 2024-12-1 3D printing enclosure
I realized that we needed a 3D printed enclosure for the mounted and wearable system. I started working on designs and decided that making two boxes with holes for the wires would be our best bet. I used Autodesk Fusion to design the box and associated lid. I had never used CAD software before so this was a good experience. I've included a picture of the 3D printed enclosure for the wearable system. ![IMG_7928](https://github.com/user-attachments/assets/a1ad217e-0b3e-413b-aef6-fe76179b6b23)

## 2024-12-2 PCB missing parts
Realized that we were missing parts. Too late to get more parts in time for demo. Got the breadboard components fully working for demo. Included a video of the colors moving. 

## 2024-12-4 Final Takeaways
Demo went well. We also filmed the extra credit video which I included. I started working on the presentation for our mock presentation.
