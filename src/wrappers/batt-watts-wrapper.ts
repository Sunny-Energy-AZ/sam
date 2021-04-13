// @ts-ignore
import SAM = require("../../sam/build/Release/sam");
import { BattWattsResp } from "../models/batt-watts";

/**
 * Detailed battery storage model.
 * - Some input parameters are interdependent but the equations that enforce consistency are not available in this module. Therefore, the onus is on the user to check that interdependencies are correctly handled.
 *
 */
export class BattWattsWrapper {
  battWatts: SAM.BattWatts;

  /**
   * Creates a new instance of `SAM.BattWatts` and assigns it to class property `battWatts`.
   *
   * @param {void}
   * @returns {void}
   */
  constructor() {
    this.battWatts = new SAM.BattWatts();
  }

  /**
   * Sets the flag to depict whether the project has battery or not. Allowed values are :
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

  /**
   * Sets battery capacity (in kWh).
   *
   * @param {number} batteryCapacityInkWh requierd : true
   * @returns {void}
   */
  setBatteryCapacity(batteryCapacityInkWh: number): void {
    this.battWatts.setBatteryCapacity(batteryCapacityInkWh);
  }

  /**
   * Sets battery power (in kw).
   *
   * @param {number} batteryPowerInkW requierd : true
   * @returns {void}
   */
  setBatteryPower(batteryPowerInkW: number): void {
    this.battWatts.setBatteryPower(batteryPowerInkW);
  }

  /**
   * Sets dispatch controller option (for system that respond to time-varying power prices). Allowed values are :
   * - 0 - Peak shaving look ahead
   * - 1 - Peak shaving look behind
   * - 4 - Manual Dispatch (where you provide a schedule or time-series instructions for when to charge and discharge the battery)
   *
   * @param {number} batteryDispatchEnum requierd : true
   * @returns {void}
   */
  setBatteryDispatch(batteryDispatchEnum: number): void {
    this.battWatts.setBatteryDispatch(batteryDispatchEnum);
  }

  /**
   * Sets whether Periods 1-6 charging from system allowed or not.
   * - Required if isBatteryEnabled: 1 and batteryDispatchEnum: 4
   *
   * @param {number[]} chargeFromPV requierd : true
   * @returns {void}
   */
  setChargeFromPV(chargeFromPV: number[]): void {
    this.battWatts.setChargeFromPV(chargeFromPV);
  }

  /**
   * Sets whether Periods 1-6 grid charging allowed or not.
   * - Required if isBatteryEnabled: 1 and batteryDispatchEnum: 4
   * - This variable may need to be updated if the values of `chargeFromGridPercenrage` have changed.
   *
   * @param {number[]} chargeFromGrid requierd : true
   * @returns {void}
   */
  setChargeFromGrid(chargeFromGrid: number[]): void {
    this.battWatts.setChargeFromGrid(chargeFromGrid);
  }

  /**
   * Sets whether Periods 1-6 discharging allowed or not.
   * - Required if isBatteryEnabled: 1 and batteryDispatchEnum: 4
   * - This variable may need to be updated if the values of `dischargePercentage` have changed.
   *
   * @param {number[]} discharge requierd : true
   * @returns {void}
   */
  setDischarge(discharge: number[]): void {
    this.battWatts.setDischarge(discharge);
  }

  /**
   * Sets Periods 1-6 gridcharge percent (in %).
   * - Required if isBatteryEnabled: 1 and batteryDispatchEnum: 4
   * - This variable may need to be updated if the values of `chargeFromGrid` have changed.
   *
   * @param {number[]} chargeFromGridPercenrage requierd : true
   * @returns {void}
   */
  setChargeFromGridPercentage(chargeFromGridPercenrage: number[]): void {
    this.battWatts.setChargeFromGridPercentage(chargeFromGridPercenrage);
  }

  /**
   * Sets Periods 1-6 discharge percent (in %).
   * - Required if isBatteryEnabled: 1 and batteryDispatchEnum: 4
   * - This variable may need to be updated if the values of `discharge` have changed.
   *
   * @param {number[]} dischargePercentage requierd : true
   * @returns {void}
   */
  setDischargePercentage(dischargePercentage: number[]): void {
    this.battWatts.setDischargePercentage(dischargePercentage);
  }

  /**
   * Sets Battery dispatch schedule for weekday.
   * - Required if isBatteryEnabled: 1 and batteryDispatchEnum: 4
   *
   * @param {number[][]} manualDispatchWeekday requierd : true
   * @returns {void}
   */
  setDispatchManualWeekdaySchedule(manualDispatchWeekday: number[][]): void {
    this.battWatts.setDispatchManualWeekdaySchedule(manualDispatchWeekday);
  }

  /**
   * Sets Battery dispatch schedule for weekend.
   * - Required if isBatteryEnabled: 1 and batteryDispatchEnum: 4
   *
   * @param {number[][]} manualDispatchWeekend requierd : true
   * @returns {void}
   */
  setDispatchManualWeekendSchedule(manualDispatchWeekend: number[][]): void {
    this.battWatts.setDispatchManualWeekendSchedule(manualDispatchWeekend);
  }

  /**
   * Sets DC array power (in W).
   *
   * @param {number[]} dcArrayPowerInW requierd : true
   * @returns {void}
   */
  setDCPower(dcArrayPowerInW: number[]): void {
    this.battWatts.setDCPower(dcArrayPowerInW);
  }

  /**
   * Sets AC inverter power (in W).
   *
   * @param {number[]} hourlyEnergyInW requierd : true
   * @returns {void}
   */
  setACPower(hourlyEnergyInW: number[]): void {
    this.battWatts.setACPower(hourlyEnergyInW);
  }

  /**
   * Sets Inverter model specifier. Allowed values are :
   * - 0 - cec
   * - 1 - datasheet
   * - 2 - partload
   * - 3 - coefficientgenerator
   * - 4 - generic
   *
   * @param {number} inverterModel requierd : true
   * @returns {void}
   */
  setInverterModel(inverterModel: number): void {
    this.battWatts.setInverterModel(inverterModel);
  }

  /**
   * Sets Inverter Efficiency (in %).
   * - Constraints: MIN=90, MAX=99.5
   *
   * @param {number} efficiency requierd : true
   * @returns {void}
   */
  setInverterEfficiency(efficiency: number): void {
    this.battWatts.setInverterEfficiency(efficiency);
  }

  /**
   * Sets Electricity load (year 1) (in kW).
   *
   * @param {number[]} hourlyUtilityElectricalLoadPreSolarInKWH requierd : true
   * @returns {void}
   */
  setElectricityLoad(hourlyUtilityElectricalLoadPreSolarInKWH: number[]): void {
    this.battWatts.setElectricityLoad(hourlyUtilityElectricalLoadPreSolarInKWH);
  }

  /**
   * Executes simulation and returns battery storage model.
   *
   * @param {void}
   * @returns {BattWattsResp}
   */
  run(): BattWattsResp {
    return this.battWatts.run();
  }
}
