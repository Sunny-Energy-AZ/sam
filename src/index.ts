import { BattWattsResponse } from "./wrappers/batt-watts-wrapper";
import { PVWattsV5Response } from "./wrappers/pv-watts-v5-wrapper";
import { UtilityRate5Response } from "./wrappers/utility-rate-5-wrapper";

/**
 * Wrapper class for the National Renewable Energy Laboratory’s System Advisor Model (SAM), a simulator for renewable energy. This module includes functionalities for these three modules :
 * - PVWattsV5 - Integrated hourly weather reader and PV system simulator.
 * - BattWatts - Simplified battery storage model.
 * - UtilityRate5 - Retail electricity bill calculator.
 *
 */
export class SAM {
  /**
   * Creates and returns a new instance of `PVWattsV5Response`
   *
   * @param {void}
   * @returns {PVWattsV5Response}
   */
  public pvWattsV5(): PVWattsV5Response {
    return new PVWattsV5Response();
  }

  /**
   * Creates and returns a new instance of `BattWattsResponse`
   *
   * @param {void}
   * @returns {BattWattsResponse}
   */
  public battWatts(): BattWattsResponse {
    return new BattWattsResponse();
  }

  /**
   * Creates and returns a new instance of `UtilityRate5Response`
   *
   * @param {void}
   * @returns {UtilityRate5Response}
   */
  public utilityRate5(): UtilityRate5Response {
    return new UtilityRate5Response();
  }
}
