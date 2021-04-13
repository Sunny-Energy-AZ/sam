// @ts-ignore
import SAM = require("../../sam/build/Release/sam");
import { UtilityRate5Resp } from "../models/utility-rate-5";

/**
 * Reatil electricity bill calculator.
 *
 */
export class UtilityRate5Wrapper {
  utilityRate5: SAM.UtilityRate5;

  /**
   * Creates a new instance of `SAM.UtilityRate5` and assigns it to class property `utilityRate5`.
   *
   * @param {void}
   * @returns {void}
   */
  constructor() {
    this.utilityRate5 = new SAM.UtilityRate5();
  }

  /**
   * Sets number of years in analysis.
   *
   * @param {number} analysisPeriod requierd : true
   * @returns {void}
   */
  setAnalysisPeriod(analysisPeriod: number): void {
    this.utilityRate5.setAnalysisPeriod(analysisPeriod);
  }

  /**
   * Sets lifetime hourly system outputs. Allowed valiues are :
   * - 0 - hourly first year
   * - 1 - hourly lifetime
   *
   * @param {number} systemUseLifetimeOutput requierd : true
   * @returns {void}
   */
  setSystemUseLifetimeOutput(systemUseLifetimeOutput: number): void {
    this.utilityRate5.setSystemUseLifetimeOutput(systemUseLifetimeOutput);
  }

  /**
   * Sets system power generated (in kW).
   *
   * @param {number[]} systemPower requierd : true
   * @returns {void}
   */
  setSystemPowerGenerated(systemPower: number[]): void {
    this.utilityRate5.setSystemPowerGenerated(systemPower);
  }

  /**
   * Sets electricity load (year 1) (in kW).
   *
   * @param {number[]} electricalLoad requierd : true
   * @returns {void}
   */
  setElectricityLoad(electricalLoad: number[]): void {
    this.utilityRate5.setElectricityLoad(electricalLoad);
  }

  /**
   * Sets inflation rate (in %).
   *
   * @param {number} inflationRate requierd : true
   * @returns {void}
   */
  setInflationRate(inflationRate: number): void {
    this.utilityRate5.setInflationRate(inflationRate);
  }

  /**
   * Sets annual energy degradation (in %).
   *
   * @param {number[]} annualEnergyDegradation requierd : true
   * @returns {void}
   */
  setAnnualEnergyDegradation(annualEnergyDegradation: number[]): void {
    this.utilityRate5.setAnnualEnergyDegradation(annualEnergyDegradation);
  }

  /**
   * Sets net metering monthly excess. Allowed values are :
   * - 0 - net energy metering
   * - 1 - net energy metering with $ credits
   * - 2 - net billing
   * - 3 - net billing with carryover to next month
   * - 4 - buy all - sell all
   *
   * @param {number} selectedMonthlyAccountOfExcessGeneration requierd : true
   * @returns {void}
   */
  setMeteringOption(selectedMonthlyAccountOfExcessGeneration: number): void {
    this.utilityRate5.setMeteringOption(
      selectedMonthlyAccountOfExcessGeneration
    );
  }

  /**
   * Sets net metering true-up credit sell rate (in $/kWh).
   *
   * @param {number} yearEndSellRate requierd : true
   * @returns {void}
   */
  setYearEndSellRate(yearEndSellRate: number): void {
    this.utilityRate5.setYearEndSellRate(yearEndSellRate);
  }

  /**
   * Sets monthly fixed charge.
   *
   * @param {number} monthlyFixedCharge requierd : true
   * @returns {void}
   */
  setMonthlyFixedCharge(monthlyFixedCharge: number): void {
    this.utilityRate5.setMonthlyFixedCharge(monthlyFixedCharge);
  }

  /**
   * Sets monthly minimum charge.
   *
   * @param {number} monthlyMinCharge requierd : true
   * @returns {void}
   */
  setMonthlyMinimumCharge(monthlyMinCharge: number): void {
    this.utilityRate5.setMonthlyMinimumCharge(monthlyMinCharge);
  }

  /**
   * Sets annual minimum charge.
   *
   * @param {number} annualMinCharge requierd : true
   * @returns {void}
   */
  setAnnualMinimumCharge(annualMinCharge: number): void {
    this.utilityRate5.setAnnualMinimumCharge(annualMinCharge);
  }

  /**
   * Sets sell rate equal to buy rate. Allowed values are :
   * - 0 - FALSE
   * - 1 - TRUE
   *
   * @param {number} useNetMetering requierd : true
   * @returns {void}
   */
  setSellRateEqualToBuyRate(useNetMetering: number): void {
    this.utilityRate5.setSellRateEqualToBuyRate(useNetMetering);
  }

  /**
   * Sets whether time step sell rates are enabled or not. Allowed values are :
   * - 0 - Disable
   * - 1 - Enable
   *
   * @param {number} isTimeStepSellRatesEnabled requierd : true
   * @returns {void}
   */
  enableTimeStepSellRates(isTimeStepSellRatesEnabled: number): void {
    this.utilityRate5.enableTimeStepSellRates(isTimeStepSellRatesEnabled);
  }

  /**
   * Sets time step sell rates.
   * - Required if `isTimeStepSellRatesEnabled = 0`
   * - Constraints: Array of BOOLEAN (0/1)
   *
   * @param {number[]} timeStepSellRates requierd : true
   * @returns {void}
   */
  setTimeStepSellRates(timeStepSellRates: number[]): void {
    this.utilityRate5.setTimeStepSellRates(timeStepSellRates);
  }

  /**
   * Sets energy charge weekday schedule (12 x 24).
   *
   * @param {number[][]} energyweekdayschedule requierd : true
   * @returns {void}
   */
  setEnergyChargeWeekdaySchedule(energyweekdayschedule: number[][]): void {
    this.utilityRate5.setEnergyChargeWeekdaySchedule(energyweekdayschedule);
  }

  /**
   * Sets energy charge weekend schedule (12 x 24).
   *
   * @param {number[][]} energyweekendschedule requierd : true
   * @returns {void}
   */
  setEnergyChargeWeekendSchedule(energyweekendschedule: number[][]): void {
    this.utilityRate5.setEnergyChargeWeekendSchedule(energyweekendschedule);
  }

  /**
   * Sets energy rates table.
   *
   * @param {number[][]} energyratestructure requierd : true
   * @returns {void}
   */
  setEnergyRatesTOUTable(energyratestructure: number[][]): void {
    this.utilityRate5.setEnergyRatesTOUTable(energyratestructure);
  }

  /**
   * Sets whether demand charge is enabled or not. Allowed values are :
   * - 0 - Disable
   * - 1 - Enable
   *
   * @param {number} isDemandChargeEnabled requierd : true
   * @returns {void}
   */
  enableDemandCharge(isDemandChargeEnabled: number): void {
    this.utilityRate5.enableDemandCharge(isDemandChargeEnabled);
  }

  /**
   * Sets demand charge weekday schedule (12 x 24).
   *
   * @param {number[][]} demandweekdayschedule requierd : true
   * @returns {void}
   */
  setDemandChargeWeekdaySchedule(demandweekdayschedule: number[][]): void {
    this.utilityRate5.setDemandChargeWeekdaySchedule(demandweekdayschedule);
  }

  /**
   * Sets demand charge weekend schedule (12 x 24).
   *
   * @param {number[][]} demandweekendschedule requierd : true
   * @returns {void}
   */
  setDemandChargeWeekendSchedule(demandweekendschedule: number[][]): void {
    this.utilityRate5.setDemandChargeWeekendSchedule(demandweekendschedule);
  }

  /**
   * Sets demand rates (TOU) table.
   * - Required if `isDemandChargeEnabled = 1`
   *
   * @param {number[][]} demandratestructure requierd : true
   * @returns {void}
   */
  setDemandRatesTOUTable(demandratestructure: number[][]): void {
    this.utilityRate5.setDemandRatesTOUTable(demandratestructure);
  }

  /**
   * Sets demand rates (flat) table.
   * - Required if `isDemandChargeEnabled = 1`
   *
   * @param {number[][]} flatdemandstructure requierd : true
   * @returns {void}
   */
  setDemandRatesFlatTable(flatdemandstructure: number[][]): void {
    this.utilityRate5.setDemandRatesFlatTable(flatdemandstructure);
  }

  /**
   * Executes simulation and returns retail electricity bill estimation.
   *
   * @param {void}
   * @returns {UtilityRate5Resp}
   */
  run(): UtilityRate5Resp {
    return this.utilityRate5.run();
  }
}
