#!/bin/bash

arg="$USER"

read -p "what is your name= " name  # input almak için

if [ "$arg" ]   # if else statement
then
	echo "Hello $name"
	#paket yükleme
	echo "Root pass: "
	su -
	apt-get install ufw
	apt install sudo
	sudo apt install ssh
	sudo apt-get install libpam-pwquality
else
	echo "Pleas add an argumant"
fi
