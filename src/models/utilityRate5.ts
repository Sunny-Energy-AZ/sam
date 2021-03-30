export type runUtilityRate5Resp = {
    electricityBillYear1WithSystem: number;
    monthlyElectricityBillYear1WithSystem: number[];
    monthlyDemandChargeTOUWithSystem: number[];
    monthlyPeakDemandWithSystem: number[];
    monthlyDemandChargeFlatWithSystem: number[];
    electricityBillYear1WithoutSystem: number;
    monthlyElectricityBillYear1WithoutSystem: number[];
    touHourlyDemandChargeSchedule: number[];
    touHourlyEnergyChargeSchedule: number[];
};
