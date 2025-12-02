#!/bin/bash

for i in {1..25}
do
    cargo new day_$i
    aoc download -d $i -y 2024 --puzzle-file ./day_$i/puzzle.md --input-file ./day_$i/input
done
