#!/usr/bin/env python

import socket
import time
from scapy.all import *

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
    frame = Dot11FCS(addr1='ff:ff:ff:ff:ff:ff', addr2='23:23:23:23:23:23', addr3='23:23:23:23:23:23')\
        / Dot11Beacon()/Dot11Elt(ID='SSID', info='GR WLAN')

    sock.sendto(bytes(frame), ("127.0.0.1", 52001))
    time.sleep(0.2)


# client = '9c:b6:d0:e1:44:e5'
# bssid = '94:44:52:51:9d:b0'

# frame = Dot11FCS(addr1=bssid,addr2=client,addr3=bssid)\
#        /Dot11Deauth()
#
# sock.sendto(bytes(frame), ("127.0.0.1", 52001))
# time.sleep(0.2)
#
#
# frame = Dot11FCS(addr1=client,addr2=bssid,addr3=bssid)\
#        /Dot11Deauth()
