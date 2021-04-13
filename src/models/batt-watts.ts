/**
 * Battery storage model response.
 *
 */
export type BattWattsResp = {
  electrictyToLoadFromPV: number[];
  electrictyToLoadFromBattery: number[];
  electrictyToBatteryFromPV: number[];
  electrictyToLoadFromGrid: number[];
  electrictyToGridFromPV: number[];
  electrictyToGridFromBattery: number[];
  electrictyToBatteryFromGrid: number[];
  powerGenerated: number[];

  monthlyElectrictyToLoadFromPV: number[];
  monthlyElectrictyToLoadFromBattery: number[];
  monthlyElectrictyToGridFromPV: number[];
  monthlyElectrictyToGridFromBattery: number[];

  batteryTotalCharge: number[];
  batteryAvailableCharge: number[];
  batteryBound: number[];
  batteryStateOfCharge: number[];
  batteryDepthOfDischarge: number[];
  batteryMaxCapacityAtCurrent: number[];
  batteryMaxChargeWithDegradation: number[];
  batteryMaxChargeAtTemperature: number[];
};
