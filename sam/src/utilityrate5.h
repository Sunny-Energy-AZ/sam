#ifndef UTILITYRATE5_H
#define UTILITYRATE5_H

#include <node.h>
#include <node_object_wrap.h>
#include "../ssc/include/sscapi.h"

namespace SAM {

	class UtilityRate5 : public node::ObjectWrap {
	public:
		static void Init(v8::Local<v8::Object> exports);

	private:
		explicit UtilityRate5();
		~UtilityRate5();

		static void New(const v8::FunctionCallbackInfo<v8::Value>& args);

    //Number of years in analysis
		static void SetAnalysisPeriod(const v8::FunctionCallbackInfo<v8::Value>& args);

    //Lifetime hourly system outputs;
    // 0=hourly first year,1=hourly lifetime
    static void SetSystemUseLifetimeOutput(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetSystemPowerGenerated(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetElectricityLoad(const v8::FunctionCallbackInfo<v8::Value>& args);

    static void SetInflationRate(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetAnnualEnergyDegradation(const v8::FunctionCallbackInfo<v8::Value>& args);

    //0=Single meter with monthly rollover credits in kWh,1=Single meter with monthly rollover credits in $,2=Single meter with no monthly rollover credits (Net Billing),3=Single meter with monthly rollover credits in $ (Net Billing $),4=Two meters with all generation sold and all load purchased
    static void SetMeteringOption(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetYearEndSellRate(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetMonthlyFixedCharge(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetSellRateEqualToBuyRate(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetMonthlyMinimumCharge(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetAnnualMinimumCharge(const v8::FunctionCallbackInfo<v8::Value>& args);

    //Enable time step sell rates; 0/1
    static void EnableTimeStepSellRates(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetTimeStepSellRates(const v8::FunctionCallbackInfo<v8::Value>& args);

    static void SetEnergyChargeWeekdaySchedule(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetEnergyChargeWeekendSchedule(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetEnergyRatesTOUTable(const v8::FunctionCallbackInfo<v8::Value>& args);

    // Enable demand charge; 0/1
    static void EnableDemandCharge(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetDemandChargeWeekdaySchedule(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetDemandChargeWeekendSchedule(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetDemandRatesTOUTable(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetDemandRatesFlatTable(const v8::FunctionCallbackInfo<v8::Value>& args);

		static void Run(const v8::FunctionCallbackInfo<v8::Value>& args);

		static const char* ToCString(const v8::String::Utf8Value& value);
		static const v8::Local<v8::Array> GetV8ArrayFromOuput(const UtilityRate5* obj, v8::Isolate* isolate, const char* key);

		static v8::Persistent<v8::Function> constructor;
		ssc_data_t pdata_;
		ssc_module_t module_;
	};
}

#endif
