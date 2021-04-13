/**
 * Battery storage model response.
 *
 */
export type BattWattsResp = {
  batteryAvailableCharge: number[];
  batteryBound: number[];
  batteryDepthOfDischarge: number[];
  batteryMaxCapacityAtCurrent: number[];
  batteryMaxChargeAtTemperature: number[];
  batteryMaxChargeWithDegradation: number[];
  batteryStateOfCharge: number[];
  batteryTotalCharge: number[];

  electrictyToBatteryFromGrid: number[];
  electrictyToBatteryFromPV: number[];
  electrictyToGridFromBattery: number[];
  electrictyToGridFromPV: number[];
  electrictyToLoadFromBattery: number[];
  electrictyToLoadFromGrid: number[];
  electrictyToLoadFromPV: number[];

  monthlyElectrictyToGridFromBattery: number[];
  monthlyElectrictyToGridFromPV: number[];
  monthlyElectrictyToLoadFromBattery: number[];
  monthlyElectrictyToLoadFromPV: number[];

  powerGenerated: number[];
};
