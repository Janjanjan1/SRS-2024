# WIFI Reciever:

- this is from the video i watched here: https://www.youtube.com/watch?v=rOtnq7H2-5o . WIFI Packet Capturing. this is also in the Discord. 
- the first step to getting any of the gre-802.11 stuff working is to install the package such that GNU radio is able to pick it up. If i recall correctly the gre-802.11 package is available through yay or pacman. Use the command below:
- ```yay -S gr-ieee802-11-git net-tools```
- secondly when you get into the gre-802.11 folder you have to go to app and run the script. to run the script you need the shell program ifconfig downloaded which you have to download through net-tools. this is included in the yay command above. 
- then you run the script.
- ```cd GR-IEE80211/apps && sudo ./rx_demo.sh```
- if you dont get any error messages and then GNU radio stuff pops up with an instance of wireshark (i had to run the script as sudo) then you are good 
- increase the sample rate to 20 ie. the max and go to a wifi channel/band that has active traffic. the constellation daigrams should cluster if you have an active band and you shall see things there. 



# Radio Attack:
- here i plan on merging the GR-IEE80211 and the VPN Attack together. Replacing the send and sniff methods with something that interfaces with our SDR. 

