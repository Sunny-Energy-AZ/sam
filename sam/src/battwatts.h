#ifndef BATT_WATTS_H
#define BATT_WATTS_H

#include <node.h>
#include <node_object_wrap.h>
#include "../ssc/include/sscapi.h"

namespace SAM {

	class BattWatts : public node::ObjectWrap {
	public:
		static void Init(v8::Local<v8::Object> exports);

	private:
		explicit BattWatts();
		~BattWatts();

		static void New(const v8::FunctionCallbackInfo<v8::Value>& args);

		// 0 to disable, 1 to enable
    static void SetEnableBattery(const v8::FunctionCallbackInfo<v8::Value>& args);

    // 0 to Lead Acid, 1 Li ion
    static void SetBatteryChemistry(const v8::FunctionCallbackInfo<v8::Value>& args);

    //kWh
    static void SetBatteryCapacity(const v8::FunctionCallbackInfo<v8::Value>& args);

    //kW
    static void SetBatteryPower(const v8::FunctionCallbackInfo<v8::Value>& args);

    // 0=peak shaving look ahead/1=peak shaving look behind
    static void SetBatteryDispatch(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetChargeFromPV(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetChargeFromGrid(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetDischarge(const v8::FunctionCallbackInfo<v8::Value>& args);

    static void SetChargeFromGridPercentage(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetDischargePercentage(const v8::FunctionCallbackInfo<v8::Value>& args);

    static void SetDispatchManualWeekdaySchedule(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetDispatchManualWeekendSchedule(const v8::FunctionCallbackInfo<v8::Value>& args);

    static void SetElectricityLoad(const v8::FunctionCallbackInfo<v8::Value>& args);

    static void SetDCPower(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetACPower(const v8::FunctionCallbackInfo<v8::Value>& args);

    //0=cec,1=datasheet,2=partload,3=coefficientgenerator,4=generic
    static void SetInverterModel(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void SetInverterEfficiency(const v8::FunctionCallbackInfo<v8::Value>& args);


		static void Run(const v8::FunctionCallbackInfo<v8::Value>& args);

		static const char* ToCString(const v8::String::Utf8Value& value);
		static const v8::Local<v8::Array> GetV8ArrayFromOuput(const BattWatts* obj, v8::Isolate* isolate, const char* key);

		static v8::Persistent<v8::Function> constructor;
		ssc_data_t pdata_;
		ssc_module_t module_;
	};
}

#endif
