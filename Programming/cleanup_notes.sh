#! /bin/bash

sudo rm $(grep NOTES_PATH hacking.h | cut -d\" -f2)
sudo rm notetaker
