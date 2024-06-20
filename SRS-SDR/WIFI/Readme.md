# WIFI Reciever:

- this is from the video i watched here: https://www.youtube.com/watch?v=rOtnq7H2-5o . WIFI Packet Capturing. also sent in Discord. 
- the first step to getting any of the gre-802.11 stuff working is to install the package such that GNU radio is able to pick it up. If i recall correctly the gre-802.11 package is available through yay or pacman but you have to install that first. 
- secondly when you get into the gre-802.11 folder you have to go to app and run the script. to run the script you need the shell program ifconfig downloaded which you have to download through net-tools. 
- then you run the script.
- if you dont get any error messages and then GNU radio stuff pops up with an instance of wireshark (i had to run the script as sudo) then you are good 
- increase the sample rate to 20 ie. the max and go to a wifi channel/band that has active traffic. the constellation daigrams should cluster if you have an active band and you shall see things there. 

