// @ts-ignore
import SAM = require("../../sam/build/Release/sam");
import { runUtilityRate5Resp } from "../models/utilityRate5";

export class UtilityRate5Wrapper {
  utilityRate5: SAM.UtilityRate5;

  constructor() {
    this.utilityRate5 = new SAM.UtilityRate5();
  }

  setAnalysisPeriod(analysisPeriod: number): void {
    this.utilityRate5.setAnalysisPeriod(analysisPeriod);
  }

  setSystemUseLifetimeOutput(systemUseLifetimeOutput: number): void {
    this.utilityRate5.setSystemUseLifetimeOutput(systemUseLifetimeOutput);
  }

  setSystemPowerGenerated(systemPower: number[]): void {
    this.utilityRate5.setSystemPowerGenerated(systemPower);
  }

  setElectricityLoad(electricalLoad: number[]): void {
    this.utilityRate5.setElectricityLoad(electricalLoad);
  }

  setInflationRate(inflationRate: number): void {
    this.utilityRate5.setInflationRate(inflationRate);
  }

  setAnnualEnergyDegradation(annualEnergyDegradation: number[]): void {
    this.utilityRate5.setAnnualEnergyDegradation(annualEnergyDegradation);
  }

  setMeteringOption(selectedMonthlyAccountOfExcessGeneration: number): void {
    this.utilityRate5.setMeteringOption(
      selectedMonthlyAccountOfExcessGeneration
    );
  }

  setYearEndSellRate(yearEndSellRate: number): void {
    this.utilityRate5.setYearEndSellRate(yearEndSellRate);
  }

  setMonthlyFixedCharge(monthlyFixedCharge: number): void {
    this.utilityRate5.setMonthlyFixedCharge(monthlyFixedCharge);
  }

  setMonthlyMinimumCharge(monthlyMinCharge: number): void {
    this.utilityRate5.setMonthlyMinimumCharge(monthlyMinCharge);
  }

  setAnnualMinimumCharge(annualMinCharge: number): void {
    this.utilityRate5.setAnnualMinimumCharge(annualMinCharge);
  }

  setSellRateEqualToBuyRate(useNetMetering: number): void {
    this.utilityRate5.setSellRateEqualToBuyRate(useNetMetering);
  }

  enableTimeStepSellRates(isTimeStepSellRatesEnabled: number): void {
    this.utilityRate5.enableTimeStepSellRates(isTimeStepSellRatesEnabled);
  }

  setTimeStepSellRates(timeStepSellRates: number[]): void {
    this.utilityRate5.setTimeStepSellRates(timeStepSellRates);
  }

  setEnergyChargeWeekdaySchedule(energyweekdayschedule: number[][]): void {
    this.utilityRate5.setEnergyChargeWeekdaySchedule(energyweekdayschedule);
  }

  setEnergyChargeWeekendSchedule(energyweekendschedule: number[][]): void {
    this.utilityRate5.setEnergyChargeWeekendSchedule(energyweekendschedule);
  }

  setEnergyRatesTOUTable(energyratestructure: number[][]): void {
    this.utilityRate5.setEnergyRatesTOUTable(energyratestructure);
  }

  enableDemandCharge(isDemandChargeEnabled: number): void {
    this.utilityRate5.enableDemandCharge(isDemandChargeEnabled);
  }

  setDemandChargeWeekdaySchedule(demandweekdayschedule: number[][]): void {
    this.utilityRate5.setDemandChargeWeekdaySchedule(demandweekdayschedule);
  }

  setDemandChargeWeekendSchedule(demandweekdayschedule: number[][]): void {
    this.utilityRate5.setDemandChargeWeekendSchedule(demandweekdayschedule);
  }

  setDemandRatesTOUTable(demandratestructure: number[][]): void {
    this.utilityRate5.setDemandRatesTOUTable(demandratestructure);
  }

  setDemandRatesFlatTable(flatdemandstructure: number[][]): void {
    this.utilityRate5.setDemandRatesFlatTable(flatdemandstructure);
  }

  run(): runUtilityRate5Resp {
    return this.utilityRate5.run();
  }
}
