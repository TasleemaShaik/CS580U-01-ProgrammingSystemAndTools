#!/usr/bin/bash

# Check to see if CUnit is installed
if [ "$(dpkg -l | awk '/libcunit1-ncurses-dev/ {print }'|wc -l)" -ge 1 ]; then
  echo "libcunit1-ncurses-dev installed"
else
	if [ "$(dpkg -l | awk '/libcunit1-dev/ {print }'|wc -l)" -ge 1 ]; then
		echo "libcunit1-dev installed"
	else
		echo "installing libcunit1-dev"
		sudo apt update && sudo apt install libcunit1-dev
	fi
fi

# Check to see if Wordnet is installed
if [ "$(dpkg -l | awk '/wordnet-dev/ {print }'|wc -l)" -ge 1 ]; then
  echo "wordnet-dev installed"
else
	echo "installing wordnet-dev"
	sudo apt update && sudo apt install wordnet-dev
fi