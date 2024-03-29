2#!/bin/bash
# Exit immediately if a command exits with a non-zero status.
set -e
# Enable the globstar shell option
shopt -s globstar
# Make sure we are inside the github workspace
cd $GITHUB_WORKSPACE
# Create directories
mkdir $HOME/Arduino
mkdir $HOME/Arduino/libraries
mkdir $HOME/Arduino/Release
# Install Arduino IDE
export PATH=$PATH:$GITHUB_WORKSPACE/bin
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
arduino-cli config init
arduino-cli core update-index
# Install Arduino ESP32
arduino-cli core install esp32:esp32
# Link Arduino library
echo $HOME
ls -l $HOME
mv $GITHUB_WORKSPACE/libraries/* $HOME/Arduino/libraries/
ls -l $HOME/Arduino/libraries
# Compile all *.ino files for the Arduino esp32
arduino-cli compile -b esp32:esp32:esp32s3 --build-property build.partitions=min_spiffs ui/ui.ino --output-dir $HOME/Arduino/Release 
zip -r cd $GITHUB_WORKSPACE/Release.zip $HOME/Arduino/Release/*
ls -l $HOME/Arduino/Release


