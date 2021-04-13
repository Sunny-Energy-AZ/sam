import { BattWattsWrapper } from "./wrappers/batt-watts-wrapper";
import { PVWattsV5Wrapper } from "./wrappers/pv-watts-v5-wrapper";
import { UtilityRate5Wrapper } from "./wrappers/utility-rate-5-wrapper";

/**
 * Wrapper class for the National Renewable Energy Laboratory’s System Advisor Model (SAM), a simulator for renewable energy. This module includes functionalities for these three modules :
 * - PVWattsV5 - Integrated hourly weather reader and PV system simulator.
 * - BattWatts - Simplified battery storage model.
 * - UtilityRate5 - Retail electricity bill calculator.
 *
 */
export class SAM {
  /**
   * Creates and returns a new instance of `PVWattsV5Wrapper`
   *
   * @param {void}
   * @returns {PVWattsV5Wrapper}
   */
  public PVWattsV5(): PVWattsV5Wrapper {
    return new PVWattsV5Wrapper();
  }

  /**
   * Creates and returns a new instance of `BattWattsWrapper`
   *
   * @param {void}
   * @returns {BattWattsWrapper}
   */
  public BattWatts(): BattWattsWrapper {
    return new BattWattsWrapper();
  }

  /**
   * Creates and returns a new instance of `UtilityRate5Wrapper`
   *
   * @param {void}
   * @returns {UtilityRate5Wrapper}
   */
  public UtilityRate5(): UtilityRate5Wrapper {
    return new UtilityRate5Wrapper();
  }
}
