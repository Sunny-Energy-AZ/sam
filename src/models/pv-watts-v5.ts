/**
 * Photovoltaic system model response
 *
 */
export type PVWattsV5Resp = {
  annualEnergyInkWh: number;
  dcArrayPowerInW: number[];
  hourlyEnergyInW: number[];
  monthlyEnergyInkWh: number[];
};
