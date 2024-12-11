## Manushri Worklog

## 2024-09-09 Initial Idea
Did some preliminary research on the idea. Looked into how to modify led lights, and if it is possible to take external inputs.

## 2024-09-16 Parts research
Looked into ESP32-C3 to be a big component of project. This would work with bluetooth and sending the data from wearable system to mounted system.

## 2024-09-23 Design Document work
Started working on the design document. Created a visual aid to show how we would use both microphone and heart rate sensor to then be computed and come up with an output.   
<img width="379" alt="Screenshot 2024-12-10 at 11 43 12 PM" src="https://github.com/user-attachments/assets/d9f2d158-949a-4aef-af93-4c2b5ca66a78">  
Also created a block diagram to show the overall interactions between all of the subsystems.  
<img width="324" alt="Screenshot 2024-12-10 at 11 44 03 PM" src="https://github.com/user-attachments/assets/123faa32-3b4b-49ba-91b9-c2e5a957f37c">

## 2024-09-30 Proposal Regrade work
Changed entire format of document to be more professional. Did research into parts needed, and reevaluated use of them in the circuit schematics. Also redrew visual aids to work with TA feedback.

## 2024-10-7 Design Document feedback
After receiving feedback on the design document, we have moved on to modifying our priorities. Both TAs, Prof and Peer feedback are useful to change up some things. Working on solidifying components for both wearable and mounted subsystem.

## 2024-10-14 to 2024-10-28 Initial PCB work
Finalized circuit schematic and started working on PCB. Split the PCB work in round robin style, with each person working on it at one time. We have 2 PCBs, but I mostly worked on the wearable component. Successfully made order by audit. TA feedback consisted of improving the PCB to make it sleeker.

## 2024-11-6 PCB update
Realized we were lacking flash, crystal, and antenna, all crucial parts of the PCB. Wish we had used ESP32 Wroom instead of ESP32C3. This design setback is quite major, but I am confident we can overcome it. I started redoing the wearable system circuit schematic, and did initial connections for the PCB aspect of it. Also organized it to make it seem more professional and easy to follow. Made order after a long day!

## 2024-11-13 Starting Arduino code with breadboard
Our work session this week consisted of us starting to work on breadboard after getting the modules. Starting the Arduino code was difficult, as none of us had prior experience. I searched up a lot of initial Arduino tutorials to learn how the software worked. Played around with flashing the ESP32 Wroom module for the first time. Searched up libraries for the heart rate sensor and the led strip.
<img width="614" alt="Screenshot 2024-12-08 at 1 33 47 PM" src="https://github.com/user-attachments/assets/9b854590-bca4-4c7f-a538-b19266c7a80c">

TA feedback consisted of working with modules instead of PCB in case PCB won't be able to come in time (since we were nearing Round 5 deadline at this point).

## 2024-11-20 Battery Life
Started inital work on LED strip connections on breadboard as per TA feedback from the week prior. Tried using MOSFETs to connect. Connected 9V battery to the led strips. Thought of potential issues if this was made into a actual product that consumers could use, and decided that battery life is a major point of concern. Looking into online resources, I found an equation: Runtime (hours) = Battery Capacity (mAh) / (Current Draw (mA)) * Efficiency Factor). We have a 9V battery with a 500 miliampere-hours capacity, and our led strip has a 5W power rating which can be converted to a 560 mA draw. Based on the MOSFET efficiency of 90%, I found that the runtime after calculations would be about 1 hour. The runtime is quite short, so try to figure out how to increase the runtime to the length of a movie.

## 2024-11-27 Thanksgiving Break
We got the new PCBs over Thanksgiving break. We will attach the parts for the PCB next week. Big thanks to my partners for working on this project over break. We all did equal work but they started on the ESP32 code instead of the testing that we were doing initially. We wouldn't have been able to do the project without everyone's effort.

## 2024-12-1 3D printing enclosure
I realized that we needed a 3D printed enclosure for the mounted and wearable system. I started working on designs and decided that making two boxes with holes for the wires would be our best bet. I used Autodesk Fusion to design the box and associated lid.   <img width="995" alt="Screenshot 2024-12-11 at 12 01 55 AM" src="https://github.com/user-attachments/assets/3b94a4c6-e88b-4192-bf87-ad5b26214baa">
I then used Bambu studio to print them out. I had to play around with the filament options because different types of filament ran out when I was trying to print.   <img width="1188" alt="Screenshot 2024-12-11 at 12 03 00 AM" src="https://github.com/user-attachments/assets/7bef62b0-7ebe-4fc4-9b69-b0d8cc01d682">
I had never used CAD software before so this was a good experience. I've included a picture of the 3D printed enclosure for the wearable system. ![IMG_7928](https://github.com/user-attachments/assets/a1ad217e-0b3e-413b-aef6-fe76179b6b23)

## 2024-12-2 PCB missing parts
Realized that we were missing parts. Too late to get more parts in time for demo. Got the breadboard components fully working for demo. Included a video of the colors moving in the attachments. I also decided to tweak the visual aids and the block diagrams in time for the final demo so we knew exactly what we changed from the start of the project to now. This is our new visual aid (where we moved to WiFi connection instead of Bluetooth connection).   
<img width="526" alt="Screenshot 2024-12-10 at 11 45 36 PM" src="https://github.com/user-attachments/assets/5843032d-5dda-41a6-b9ca-f65ade615f30">  
This is our new block diagram (where we added the 9V battery to power the LED strips and got rid of the LED drivers). 
  <img width="444" alt="Screenshot 2024-12-10 at 11 46 23 PM" src="https://github.com/user-attachments/assets/e33d97e3-3b2d-47e0-94b4-a99663fb9232">

## 2024-12-3 Final Verifications
Our breadboard is now completely working, but our PCB isn't due to lack of parts. Regardless we decided to test our verifications. Here is one example of the heart rate sensor that we ended up testing. One of our requirements was that we want our heart rate to fall in within 10 BPM range of a known workable heart rate monitor (aka Apple Watch). We got this requirement working!  
<img width="280" alt="Screenshot 2024-12-10 at 11 52 24 PM" src="https://github.com/user-attachments/assets/c246a273-6b84-4e7f-a622-8f03bea1f463">

## 2024-12-4 Final Takeaways
Demo went well. We also filmed the extra credit video which I included. I started working on the presentation for our mock presentation.
https://github.com/user-attachments/assets/a4e72ede-3543-401a-9fdf-084e24d0d647

## 2024-12-10 Final Presentation and Partner Summaries
All of us worked on similar sections throughout the entire project. We did stick to the schedule mentioned in the Design Document and now the Final Report, but we also focused on a lot of collaborative effort. We all worked on one part together, because racking our brains together was the best way we could understand the problems that we were facing. In addition, I finished working on presentation, and got good feedback from the Mock Presentation that I then used to change the actual presentation. It was a good presentation! We also wrapped up the Final Report. Thanks for a great semester! I learned a lot in this class!
