#!/bin/sh

# sudo socat pty,link=/dev/ttyTCP0,ignoreeof,user=apechinsky,group=dialout,mode=777,raw,echo=0 tcp:192.168.100.150:23
# sudo socat pty,link=/dev/ttyTCP0,user=apechinsky tcp:192.168.100.150:23

while `true`; do 
    echo "ready" 
    sudo socat pty,link=/dev/ttyTCP99,raw,wait-slave,user=apechinsky,group=dialout tcp:192.168.100.150:23 
    # sudo socat pty,link=/dev/ttyACM99,raw,wait-slave,user=apechinsky,group=dialout tcp:192.168.100.150:23 
done
