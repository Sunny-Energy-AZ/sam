// @ts-ignore
import SAM = require("../../sam/build/Release/sam");
import { runBattWattsResp } from "../models/battWatts";

export class BattWattsWrapper {
  battWatts: SAM.BattWatts;

  constructor() {
    this.battWatts = new SAM.BattWatts();
  }

  /**
  * To depict whether the project has battery or not. Allowed values are :
  * - 0 - Disable
  * - 1 - Enable
  * 
  * @param {number} isBatteryEnabled requierd : true
  * @returns {void}
  */
  setEnableBattery(isBatteryEnabled: number): void {
    this.battWatts.setEnableBattery(isBatteryEnabled);
  }

  /**
  * Sets chemistry type of battery. Allowed values are :
  * - 0 - Lead Acid
  * - 1 - Li-ion
  * 
  * @param {number} batteryChemistryEnum requierd : true
  * @returns {void}
  */
  setBatteryChemistry(batteryChemistryEnum: number): void {
    this.battWatts.setBatteryChemistry(batteryChemistryEnum);
  }

  setBatteryCapacity(batteryCapacityInkWh: number): void {
    this.battWatts.setBatteryCapacity(batteryCapacityInkWh);
  }

  setBatteryPower(batteryPowerInkW: number): void {
    this.battWatts.setBatteryPower(batteryPowerInkW);
  }

  setBatteryDispatch(batteryDispatchEnum: number): void {
    this.battWatts.setBatteryDispatch(batteryDispatchEnum);
  }

  setChargeFromPV(chargeFromPV: number[]): void {
    this.battWatts.setChargeFromPV(chargeFromPV);
  }

  setChargeFromGrid(chargeFromGrid: number[]): void {
    this.battWatts.setChargeFromGrid(chargeFromGrid);
  }

  setDischarge(discharge: number[]): void {
    this.battWatts.setDischarge(discharge);
  }

  setChargeFromGridPercentage(chargeFromGridPercenrage: number[]): void {
    this.battWatts.setChargeFromGridPercentage(chargeFromGridPercenrage);
  }

  setDischargePercentage(dischargePercentage: number[]): void {
    this.battWatts.setDischargePercentage(dischargePercentage);
  }

  setDispatchManualWeekdaySchedule(manualDispatchWeekday: number[][]): void {
    this.battWatts.setDispatchManualWeekdaySchedule(manualDispatchWeekday);
  }

  setDispatchManualWeekendSchedule(manualDispatchWeekend: number[][]): void {
    this.battWatts.setDispatchManualWeekendSchedule(manualDispatchWeekend);
  }

  setDCPower(dcArrayPowerInW: number[]): void {
    this.battWatts.setDCPower(dcArrayPowerInW);
  }

  setACPower(hourlyEnergyInW: number[]): void {
    this.battWatts.setACPower(hourlyEnergyInW);
  }

  setInverterModel(inverterModel: number): void {
    this.battWatts.setInverterModel(inverterModel);
  }

  setInverterEfficiency(efficiency: number): void {
    this.battWatts.setInverterEfficiency(efficiency);
  }

  setElectricityLoad(hourlyUtilityElectricalLoadPreSolarInKWH: number): void {
    this.battWatts.setElectricityLoad(hourlyUtilityElectricalLoadPreSolarInKWH);
  }

  run(): runBattWattsResp {
    return this.battWatts.run();
  }
}
