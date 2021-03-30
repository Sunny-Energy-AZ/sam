// @ts-ignore
import SAM = require("../../sam/build/Release/sam");
import { runPVWattsV5Resp } from "../models/pvWattsV5";

export class PVWattsV5Wrapper {
  pvWatts: SAM.PVWattsV5;

  constructor() {
    this.pvWatts = new SAM.PVWattsV5();
  }

  setSolarWeatherDataFilePath(localWeatherFile: string): void {
    this.pvWatts.setSolarWeatherDataFilePath(localWeatherFile);
  }

  setSystemCapacityInKW(systemSizeInKW: number): void {
    this.pvWatts.setSystemCapacityInKW(systemSizeInKW);
  }

  setTiltInDegree(systemConfigItemTilt: number): void {
    this.pvWatts.setTiltInDegree(systemConfigItemTilt);
  }

  setAzimuthInDegree(systemConfigItemAzimuth: number): void {
    this.pvWatts.setAzimuthInDegree(systemConfigItemAzimuth);
  }

  setDCToACRatio(globalSettingsDcToAcRatio: number): void {
    this.pvWatts.setDCToACRatio(globalSettingsDcToAcRatio);
  }

  setInverterEfficiencyAtRatedPowerInPercentage(
    selectedInverterEfficiency: number
  ): void {
    this.pvWatts.setInverterEfficiencyAtRatedPowerInPercentage(
      selectedInverterEfficiency
    );
  }

  setGroundCoverageRatio(globalSettingsGroundCoverageRatio: number): void {
    this.pvWatts.setGroundCoverageRatio(globalSettingsGroundCoverageRatio);
  }

  setLossesInPercentage(loss: number): void {
    this.pvWatts.setLossesInPercentage(loss);
  }

  setModuleType(moduleTypeEnum: number): void {
    this.pvWatts.setModuleType(moduleTypeEnum);
  }

  setEnableBattery(isBatteryEnabled: number): void {
    this.pvWatts.setEnableBattery(isBatteryEnabled);
  }

  setArrayType(arrayTypeEnum: number): void {
    this.pvWatts.setArrayType(arrayTypeEnum);
  }

  setConstantLossAdjustmentInPercentage(constantLossAdjustment: number): void {
    this.pvWatts.setConstantLossAdjustmentInPercentage(constantLossAdjustment);
  }

  run(): runPVWattsV5Resp {
    return this.pvWatts.run();
  }
}
