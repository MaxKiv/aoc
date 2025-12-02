#!/bin/bash

read -rp "Enter day: " day
if [ -n "$day" ]; then
  aoc download -d "$day" -y 2025 --puzzle-file ./day_"$day"/puzzle.md --input-file ./day_"$day"/input
else
  echo "enter valid day"
fi
