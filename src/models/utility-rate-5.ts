/**
 * Retail electricity bill response
 *
 */
export type UtilityRate5Resp = {
  electricityBillYear1WithoutSystem: number;
  electricityBillYear1WithSystem: number;
  monthlyDemandChargeFlatWithSystem: number[];
  monthlyDemandChargeTOUWithSystem: number[];
  monthlyElectricityBillYear1WithoutSystem: number[];
  monthlyElectricityBillYear1WithSystem: number[];
  monthlyPeakDemandWithSystem: number[];
  touHourlyDemandChargeSchedule: number[];
  touHourlyEnergyChargeSchedule: number[];
};
