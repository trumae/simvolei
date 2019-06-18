[![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](https://lbesson.mit-license.org/)
[![Build Status](https://travis-ci.org/trumae/simvolei.svg?branch=master)](https://travis-ci.org/trumae/simvolei)

# Motivation

In a talk with my oldest son, I wanted to show how much the details are important in the volleyball games. Then i made an little test using a simple simulation. 

# Features

- Simple Monte-Carlo simulation
- Based only on single point probability

# How it works

Based on probability of each team do one point, an entire game was simulated *n* times.

# Examples

## 50% team1 - 50% team2
```
➜  build git:(master) ✗ ./simvolei 0.5 100000
[##################################################] 100% 0.818s
Done! 49817  50183
```

## 51% team1 - 49% team2
```
➜  build git:(master) ✗ ./simvolei 0.51 100000
[##################################################] 100% 0.82s
Done! 60127  39873
```

## 55% team1 - 45% team2
```
➜  build git:(master) ✗ ./simvolei 0.55 100000
[##################################################] 100% 0.744s
Done! 90229  9771
```
