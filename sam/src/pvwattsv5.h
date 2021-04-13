#ifndef PVWATTSV5_H
#define PVWATTSV5_H

#include <node.h>
#include <node_object_wrap.h>
#include "../ssc/include/sscapi.h"

namespace SAM
{

	class PVWattsV5 : public node::ObjectWrap
	{
	public:
		static void Init(v8::Local<v8::Object> exports);

	private:
		explicit PVWattsV5();
		~PVWattsV5();

		static void New(const v8::FunctionCallbackInfo<v8::Value> &args);

		/*** location and resource ***/
		static void SetSolarWeatherDataFilePath(const v8::FunctionCallbackInfo<v8::Value> &args);

		/*** system design ***/
		static void SetSystemCapacityInKW(const v8::FunctionCallbackInfo<v8::Value> &args);
		// 0: Standard, 1: Premium, 2: Thin film
		static void SetModuleType(const v8::FunctionCallbackInfo<v8::Value> &args);

		// 0 to disable, 1 to enable
		static void SetEnableBattery(const v8::FunctionCallbackInfo<v8::Value> &args);

		static void SetDCToACRatio(const v8::FunctionCallbackInfo<v8::Value> &args);
		static void SetInverterEfficiencyAtRatedPowerInPercentage(const v8::FunctionCallbackInfo<v8::Value> &args);
		static void SetGroundCoverageRatio(const v8::FunctionCallbackInfo<v8::Value> &args);
		// 0: Fixed Open Rack. 1: Fixed Open Mount, 2: 1 Axis Tracking, 3: 2 Axis Backtracking, 4: 2 Axis Tracking
		static void SetArrayType(const v8::FunctionCallbackInfo<v8::Value> &args);
		static void SetTiltInDegree(const v8::FunctionCallbackInfo<v8::Value> &args);
		static void SetAzimuthInDegree(const v8::FunctionCallbackInfo<v8::Value> &args);

		static void SetLossesInPercentage(const v8::FunctionCallbackInfo<v8::Value> &args);
		static void SetConstantLossAdjustmentInPercentage(const v8::FunctionCallbackInfo<v8::Value> &args);
		static void Run(const v8::FunctionCallbackInfo<v8::Value> &args);

		static const char *ToCString(const v8::String::Utf8Value &value);
		static const v8::Local<v8::Array> GetV8ArrayFromOuput(const PVWattsV5 *obj, v8::Isolate *isolate, const char *key);

		static v8::Persistent<v8::Function> constructor;
		ssc_data_t pdata_;
		ssc_module_t module_;
	};
}

#endif
