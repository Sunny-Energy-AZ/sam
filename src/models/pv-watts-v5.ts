export type PVWattsV5Resp = {
  annualEnergyInkWh: number;
  hourlyEnergyInW: number[];
  monthlyEnergyInkWh: number[];
  dcArrayPowerInW: number[];
};
