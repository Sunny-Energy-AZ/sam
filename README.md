# node-sam

## Summary

JavaScript library for creating renewable energy system models using SAM Simulation Core (SSC).

`node-sam` is a wrapper for the National Renewable Energy Laboratory’s [System Advisor Model](https://sam.nrel.gov) (SAM), a simulator for renewable energy.

SAM is a performance and financial model designed to facilitate decision making for people involved in the renewable energy industry.

[SAM](https://github.com/nrel/sam) is open-source. `node-sam` provides JavaScript class-object for the models found in SAM Simulation Core, ([SSC](https://github.com/nrel/ssc)).

`node-sam` enables developers to run the underlying unit modules that make up a simulation in SAM. A single simulation may comprise a single module or a process chaining together multiple unit modules. `node-sam` exposes these unit modules in JavaScript class-object so that they can be customized and embedded in software applications.

### Limitation

- For now, this npm package works with Linux and MacOS only.

- This package supports these three models :
  - PVWattsV5 - Integrated hourly weather reader and PV system simulator.
  - BattWatts - Simplified battery storage model.
  - UtilityRate5 - Retail electricity bill calculator.

## Installation

Using npm:

```
$ npm i -g npm
$ npm i node-sam
```

Note: add --save if you are using npm < 5.0.0

In Node.js:

```
// Load the full build.
var SAM = require('node-sam');
```
