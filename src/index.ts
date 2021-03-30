import { BattWattsWrapper } from "./wrappers/battWattsWrapper";
import { PVWattsV5Wrapper } from "./wrappers/pvWattsV5Wrapper";
import { UtilityRate5Wrapper } from "./wrappers/utilityRate5Wrapper";

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
