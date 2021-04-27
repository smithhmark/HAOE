#! /bin/bash

gcc -o notetaker notetaker.c

# uncomment for Linux
#sudo chown root:root ./notetaker 
# uncomment for Mac
#sudo chown root:admin ./notetaker
sudo chmod u+s ./notetaker
