// @ts-ignore
import SAM = require("../../sam/build/Release/sam");
import { PVWattsV5Resp } from "../models/pv-watts-v5";

/**
 * Photovoltaic system model with simple inputs.
 * - Some input parameters are interdependent but the equations that enforce consistency are not available in this module. Therefore, the onus is on the user to check that interdependencies are correctly handled.
 *
 */
export class PVWattsV5Response {
  pvWatts: SAM.PVWattsV5;

  /**
   * Creates a new instance of `SAM.PVWattsV5` and assigns it to class property `pvWatts`.
   *
   * @param {void}
   * @returns {void}
   */
  constructor() {
    this.pvWatts = new SAM.PVWattsV5();
  }

  /**
   * Sets weather data file path
   *
   * @param {string} localWeatherFile requierd : true
   * @returns {void}
   */
  setSolarWeatherDataFilePath(localWeatherFile: string): void {
    this.pvWatts.setSolarWeatherDataFilePath(localWeatherFile);
  }

  /**
   * Sets system size (DC nameplate) (in kW).
   *
   * @param {number} systemSizeInKW requierd : true
   * @returns {void}
   */
  setSystemCapacityInKW(systemSizeInKW: number): void {
    this.pvWatts.setSystemCapacityInKW(systemSizeInKW);
  }

  /**
   * Sets tilt angle (in degree).
   * - Constraints: Min (H): 0 or Max (V): 90
   *
   * @param {number} systemConfigItemTilt requierd : true
   * @returns {void}
   */
  setTiltInDegree(systemConfigItemTilt: number): void {
    this.pvWatts.setTiltInDegree(systemConfigItemTilt);
  }

  /**
   * Sets azimuth angle (in degree).
   * - Constraints: Min (H): 0 or Max (V): 360 with E:90, S: 180, W:270
   *
   * @param {number} systemConfigItemAzimuth requierd : true
   * @returns {void}
   */
  setAzimuthInDegree(systemConfigItemAzimuth: number): void {
    this.pvWatts.setAzimuthInDegree(systemConfigItemAzimuth);
  }

  /**
   * Sets DC to AC ratio.
   * - Constraints: POSITIVE
   *
   * @param {number} globalSettingsDcToAcRatio requierd : true
   * @returns {void}
   */
  setDCToACRatio(globalSettingsDcToAcRatio: number): void {
    this.pvWatts.setDCToACRatio(globalSettingsDcToAcRatio);
  }

  /**
   * Sets inverter efficiency at rated power (in %).
   * - Constraints: MIN = 90, MAX = 99.5
   *
   * @param {number} selectedInverterEfficiency requierd : true
   * @returns {void}
   */
  setInverterEfficiencyAtRatedPowerInPercentage(
    selectedInverterEfficiency: number
  ): void {
    this.pvWatts.setInverterEfficiencyAtRatedPowerInPercentage(
      selectedInverterEfficiency
    );
  }

  /**
   * Sets ground coverage ratio.
   * - Constraints: MIN = 0, MAX = 3
   *
   * @param {number} globalSettingsGroundCoverageRatio requierd : true
   * @returns {void}
   */
  setGroundCoverageRatio(globalSettingsGroundCoverageRatio: number): void {
    this.pvWatts.setGroundCoverageRatio(globalSettingsGroundCoverageRatio);
  }

  /**
   * Sets ground coverage ratio.
   * - Constraints: MIN = 0, MAX = 3
   *
   * @param {number} loss requierd : true
   * @returns {void}
   */
  setLossesInPercentage(loss: number): void {
    this.pvWatts.setLossesInPercentage(loss);
  }

  /**
   * Sets module type. Allowed values are :
   * - 0 - Standard
   * - 1 - Premium
   * - 2 - Thin film
   *
   * @param {number} moduleTypeEnum requierd : true
   * @returns {void}
   */
  setModuleType(moduleTypeEnum: number): void {
    this.pvWatts.setModuleType(moduleTypeEnum);
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
    this.pvWatts.setEnableBattery(isBatteryEnabled);
  }

  /**
   * Sets array type. Allowed values are :
   * - 0 - Fixed Open Rack
   * - 1 - Fixed Open Mount
   * - 2 - 1 Axis Tracking
   * - 3 - 2 Axis Backtracking
   * - 4 - 2 Axis Tracking
   *
   * @param {number} arrayTypeEnum requierd : true
   * @returns {void}
   */
  setArrayType(arrayTypeEnum: number): void {
    this.pvWatts.setArrayType(arrayTypeEnum);
  }

  /**
   * Sets constant loss adjustment (in %).
   * - Constraints: MAX = 100
   *
   * @param {number} constantLossAdjustment requierd : true
   * @returns {void}
   */
  setConstantLossAdjustmentInPercentage(constantLossAdjustment: number): void {
    this.pvWatts.setConstantLossAdjustmentInPercentage(constantLossAdjustment);
  }

  /**
   * Executes simulation and returns photovoltaic system model.
   *
   * @param {void}
   * @returns {PVWattsV5Resp}
   */
  run(): PVWattsV5Resp {
    return this.pvWatts.run();
  }
}
