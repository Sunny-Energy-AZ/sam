#include "pvwattsv5.h"
#include "../ssc/include/sscapi.h"

namespace SAM {

	using v8::Exception;
	using v8::Context;
	using v8::Function;
	using v8::FunctionCallbackInfo;
	using v8::FunctionTemplate;
	using v8::Isolate;
	using v8::Local;
	using v8::Number;
	using v8::Object;
	using v8::Persistent;
	using v8::String;
	using v8::Value;
	using v8::Array;

	Persistent<Function> PVWattsV5::constructor;

	PVWattsV5::PVWattsV5(){
		pdata_ = ssc_data_create();
		module_ = ssc_module_create("pvwattsv5");
	}

	PVWattsV5::~PVWattsV5() {
		ssc_module_free(module_);
		ssc_data_free(pdata_);
	}

	void PVWattsV5::Init(Local<Object> exports) {
		Isolate* isolate = exports->GetIsolate();

		// Prepare constructor template
		Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
		tpl->SetClassName(String::NewFromUtf8(isolate, "PVWattsV5"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1);

		// Prototype
		NODE_SET_PROTOTYPE_METHOD(tpl, "setSolarWeatherDataFilePath", SetSolarWeatherDataFilePath);

		NODE_SET_PROTOTYPE_METHOD(tpl, "setSystemCapacityInKW", SetSystemCapacityInKW);
		NODE_SET_PROTOTYPE_METHOD(tpl, "setModuleType", SetModuleType);
  	NODE_SET_PROTOTYPE_METHOD(tpl, "setEnableBattery", SetEnableBattery);

		NODE_SET_PROTOTYPE_METHOD(tpl, "setDCToACRatio", SetDCToACRatio);
		NODE_SET_PROTOTYPE_METHOD(tpl, "setInverterEfficiencyAtRatedPowerInPercentage", SetInverterEfficiencyAtRatedPowerInPercentage);
		NODE_SET_PROTOTYPE_METHOD(tpl, "setGroundCoverageRatio", SetGroundCoverageRatio);
		NODE_SET_PROTOTYPE_METHOD(tpl, "setLossesInPercentage", SetLossesInPercentage);
		NODE_SET_PROTOTYPE_METHOD(tpl, "setArrayType", SetArrayType);
		NODE_SET_PROTOTYPE_METHOD(tpl, "setTiltInDegree", SetTiltInDegree);
		NODE_SET_PROTOTYPE_METHOD(tpl, "setAzimuthInDegree", SetAzimuthInDegree);
		NODE_SET_PROTOTYPE_METHOD(tpl, "setConstantLossAdjustmentInPercentage", SetConstantLossAdjustmentInPercentage);

		NODE_SET_PROTOTYPE_METHOD(tpl, "run", Run);

		constructor.Reset(isolate, tpl->GetFunction());
		exports->Set(String::NewFromUtf8(isolate, "PVWattsV5"),
		tpl->GetFunction());
	}

	void PVWattsV5::New(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();

		if (args.IsConstructCall()) {
			// Invoked as constructor: `new PVWattsV5(...)`
			PVWattsV5* obj = new PVWattsV5();
			obj->Wrap(args.This());
			args.GetReturnValue().Set(args.This());
		} else {
			// Invoked as plain function `PVWattsV5(...)`, turn into construct call.
			const int argc = 1;
			Local<Value> argv[argc] = {args[0]};
			Local<Context> context = isolate->GetCurrentContext();
			Local<Function> cons = Local<Function>::New(isolate, constructor);
			Local<Object> result =
				cons->NewInstance(context, argc, argv).ToLocalChecked();
			args.GetReturnValue().Set(result);
		}
	}

	void PVWattsV5::SetSolarWeatherDataFilePath(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsString()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid solar weather data file path")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		String::Utf8Value str(args[0]->ToString());

		ssc_data_set_string(obj->pdata_,"solar_resource_file", ToCString(str));
	}

	void PVWattsV5::SetSystemCapacityInKW(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid system capacity")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"system_capacity", args[0]->NumberValue());
	}

	void PVWattsV5::SetModuleType(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
			|| !args[0]->IsNumber()
		|| (args[0]->NumberValue()<0 || args[0]->NumberValue()>2)) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid module type. 0: Standard, 1: Premium, 2: Thin film")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"module_type", args[0]->NumberValue());
	}

	void PVWattsV5::SetEnableBattery(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
			|| !args[0]->IsNumber()
		|| (args[0]->NumberValue()<0 || args[0]->NumberValue()>1)) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid battery enable type. 0: Disable, 1: Enable")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"batt_simple_enable", args[0]->NumberValue());
	}

	void PVWattsV5::SetDCToACRatio(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
			|| !args[0]->IsNumber()
		|| (args[0]->NumberValue()<0)) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid dc to ac ratio.")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"dc_ac_ratio", args[0]->NumberValue());
	}

	void PVWattsV5::SetInverterEfficiencyAtRatedPowerInPercentage(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
			|| !args[0]->IsNumber()
		|| (args[0]->NumberValue()<90 || args[0]->NumberValue()>99.5)) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid inverter efficient at rated power")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"inv_eff", args[0]->NumberValue());
	}

	void PVWattsV5::SetArrayType(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
			|| !args[0]->IsNumber()
		|| (args[0]->NumberValue() <0 || args[0]->NumberValue()>4)) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid array type. Possible values are: 0: Fixed Open Rack. 1: Fixed Open Mount, 2: 1 Axis Tracking, 3: 2 Axis Backtracking, 4: 2 Axis Tracking")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"array_type", args[0]->NumberValue());
	}

	void PVWattsV5::SetTiltInDegree(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
			|| !args[0]->IsNumber()
		|| (args[0]->NumberValue() <0 || args[0]->NumberValue()>90)) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid tilt. Min (H): 0 or Max (V): 90")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"tilt", args[0]->NumberValue());
	}

	void PVWattsV5::SetAzimuthInDegree(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
			|| !args[0]->IsNumber()
		|| (args[0]->NumberValue() <0 || args[0]->NumberValue()>360)) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid azimuth. Min (H): 0 or Max (V): 360 with E:90, S: 180, W:270")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"azimuth", args[0]->NumberValue());
	}

	void PVWattsV5::SetGroundCoverageRatio(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
			|| !args[0]->IsNumber()
		|| (args[0]->NumberValue() <0 || args[0]->NumberValue()>3)) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid ground coverage ratio. Min 0. Max: 3")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"gcr", args[0]->NumberValue());
	}

	void PVWattsV5::SetLossesInPercentage(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
			|| !args[0]->IsNumber()
		|| (args[0]->NumberValue()<-5 || args[0]->NumberValue()>99)) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid system loss value. Min: -5, Max: 99")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"losses", args[0]->NumberValue());
	}

	void PVWattsV5::SetConstantLossAdjustmentInPercentage(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
			|| !args[0]->IsNumber()
		|| (args[0]->NumberValue() > 100)) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid constant loss adjustment. Max 100.")));
			return;
		}

		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"adjust:constant", args[0]->NumberValue());
	}

	void PVWattsV5::Run(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		PVWattsV5* obj = ObjectWrap::Unwrap<PVWattsV5>(args.Holder());
		if (ssc_module_exec(obj->module_, obj->pdata_) !=0){

			Local<Object> response = Object::New(isolate);
			response->Set(String::NewFromUtf8(isolate, "dcArrayPowerInW"), GetV8ArrayFromOuput(obj,isolate,"dc"));
			response->Set(String::NewFromUtf8(isolate, "hourlyEnergyInW"), GetV8ArrayFromOuput(obj,isolate,"ac"));
			//response->Set(String::NewFromUtf8(isolate, "dcMonthlyArrayPowerInkWh"), GetV8ArrayFromOuput(obj,isolate,"dc_monthly"));
			//response->Set(String::NewFromUtf8(isolate, "acMonthlyInverterPowerInkWh"), GetV8ArrayFromOuput(obj,isolate,"ac_monthly"));
			response->Set(String::NewFromUtf8(isolate, "monthlyEnergyInkWh"), GetV8ArrayFromOuput(obj,isolate,"monthly_energy"));

			ssc_number_t value=0;
			//ssc_data_get_number(obj->pdata_,"ac_annual", &value);
			//response->Set(String::NewFromUtf8(isolate, "acAnnualSystemOutputInkWH"), Number::New(isolate,value));

			ssc_data_get_number(obj->pdata_,"annual_energy", &value);
			response->Set(String::NewFromUtf8(isolate, "annualEnergyInkWh"), Number::New(isolate,value));

			args.GetReturnValue().Set(response);
		}else{
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Something went wrong. Please ensure that you specify all the parameters")));
			return;
		}
	}

	const char* PVWattsV5::ToCString(const String::Utf8Value& value) {
		return *value ? *value : "<string conversion failed>";
	}

	const Local<Array> PVWattsV5::GetV8ArrayFromOuput(const PVWattsV5* obj, Isolate* isolate, const char* key){

		int len = 0;
		ssc_number_t *data = ssc_data_get_array(obj->pdata_, key, &len);

		Local<Array> arr = Array::New(isolate, len);
		for (int i = 0; i < len; i++) {
			arr->Set(Number::New(isolate, i), Number::New(isolate, data[i]));
		}

		return arr;
	}
}
