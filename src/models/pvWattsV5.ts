export type runPVWattsV5Resp = {
    annualEnergyInkWh: number;
    hourlyEnergyInW: number[];
    monthlyEnergyInkWh: number[];
    dcArrayPowerInW: number[];
}
