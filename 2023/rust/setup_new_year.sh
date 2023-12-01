#!/bin/bash

cargo new shared
for i in {1..25}
do
    cargo new day_$i
done
