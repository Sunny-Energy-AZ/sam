import { BattWattsWrapper } from "./wrappers/batt-watts-wrapper";
import { PVWattsV5Wrapper } from "./wrappers/pv-watts-v5-wrapper";
import { UtilityRate5Wrapper } from "./wrappers/utility-rate-5-wrapper";

export class SAM {
  public PVWattsV5(): PVWattsV5Wrapper {
    return new PVWattsV5Wrapper();
  }
  public BattWatts(): BattWattsWrapper {
    return new BattWattsWrapper();
  }
  public UtilityRate5(): UtilityRate5Wrapper {
    return new UtilityRate5Wrapper();
  }
}
