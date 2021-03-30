#include "utilityrate5.h"
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

	Persistent<Function> UtilityRate5::constructor;

	UtilityRate5::UtilityRate5(){
		pdata_ = ssc_data_create();
		module_ = ssc_module_create("utilityrate5");
	}

	UtilityRate5::~UtilityRate5() {
		ssc_module_free(module_);
		ssc_data_free(pdata_);
	}

	void UtilityRate5::Init(Local<Object> exports) {
		Isolate* isolate = exports->GetIsolate();

		// Prepare constructor template
		Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
		tpl->SetClassName(String::NewFromUtf8(isolate, "UtilityRate5"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1);

		// Prototype
		NODE_SET_PROTOTYPE_METHOD(tpl, "setAnalysisPeriod", SetAnalysisPeriod);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setSystemUseLifetimeOutput", SetSystemUseLifetimeOutput);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setSystemPowerGenerated", SetSystemPowerGenerated);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setElectricityLoad", SetElectricityLoad);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setInflationRate", SetInflationRate);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setAnnualEnergyDegradation", SetAnnualEnergyDegradation);

    NODE_SET_PROTOTYPE_METHOD(tpl, "setMeteringOption", SetMeteringOption);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setYearEndSellRate", SetYearEndSellRate);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setMonthlyFixedCharge", SetMonthlyFixedCharge);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setSellRateEqualToBuyRate", SetSellRateEqualToBuyRate);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setMonthlyMinimumCharge", SetMonthlyMinimumCharge);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setAnnualMinimumCharge", SetAnnualMinimumCharge);

    NODE_SET_PROTOTYPE_METHOD(tpl, "enableTimeStepSellRates", EnableTimeStepSellRates);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setTimeStepSellRates", SetTimeStepSellRates);

    NODE_SET_PROTOTYPE_METHOD(tpl, "setEnergyChargeWeekdaySchedule", SetEnergyChargeWeekdaySchedule);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setEnergyChargeWeekendSchedule", SetEnergyChargeWeekendSchedule);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setEnergyRatesTOUTable", SetEnergyRatesTOUTable);

    NODE_SET_PROTOTYPE_METHOD(tpl, "enableDemandCharge", EnableDemandCharge);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setDemandChargeWeekdaySchedule", SetDemandChargeWeekdaySchedule);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setDemandChargeWeekendSchedule", SetDemandChargeWeekendSchedule);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setDemandRatesTOUTable", SetDemandRatesTOUTable);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setDemandRatesFlatTable", SetDemandRatesFlatTable);

		NODE_SET_PROTOTYPE_METHOD(tpl, "run", Run);

		constructor.Reset(isolate, tpl->GetFunction());
		exports->Set(String::NewFromUtf8(isolate, "UtilityRate5"),
		tpl->GetFunction());
	}

	void UtilityRate5::New(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();

		if (args.IsConstructCall()) {
			// Invoked as constructor: `new UtilityRate5(...)`
			UtilityRate5* obj = new UtilityRate5();
			obj->Wrap(args.This());
			args.GetReturnValue().Set(args.This());
		} else {
			// Invoked as plain function `UtilityRate5(...)`, turn into construct call.
			const int argc = 1;
			Local<Value> argv[argc] = {args[0]};
			Local<Context> context = isolate->GetCurrentContext();
			Local<Function> cons = Local<Function>::New(isolate, constructor);
			Local<Object> result =
				cons->NewInstance(context, argc, argv).ToLocalChecked();
			args.GetReturnValue().Set(result);
		}
	}

	void UtilityRate5::SetAnalysisPeriod(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid analysis period")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"analysis_period", args[0]->NumberValue());
	}
	void UtilityRate5::SetSystemUseLifetimeOutput(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify a valid analysis period")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"system_use_lifetime_output", args[0]->NumberValue());
	}
	void UtilityRate5::SetSystemPowerGenerated(const FunctionCallbackInfo<Value>& args) {
    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t* values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++) {
      values[i]=input->Get(i)->NumberValue();
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_array(obj->pdata_,"gen", values, length);
    delete[] values;
	}
	void UtilityRate5::SetElectricityLoad(const FunctionCallbackInfo<Value>& args) {

    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t* values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++) {
      values[i]=input->Get(i)->NumberValue();
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_array(obj->pdata_,"load", values, length);
    delete[] values;
	}
	void UtilityRate5::SetInflationRate(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify valid inflation rate")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"inflation_rate", args[0]->NumberValue());
	}

  void UtilityRate5::SetAnnualEnergyDegradation(const FunctionCallbackInfo<Value>& args) {

    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t* values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++) {
      values[i]=input->Get(i)->NumberValue();
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_array(obj->pdata_,"degradation", values, length);
    delete[] values;
	}

	void UtilityRate5::SetMeteringOption(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify valid metering option")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"ur_metering_option", args[0]->NumberValue());
	}
	void UtilityRate5::SetYearEndSellRate(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify valid year end sell rate")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"ur_nm_yearend_sell_rate", args[0]->NumberValue());
	}
	void UtilityRate5::SetMonthlyFixedCharge(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify valid monthly fixed charge")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"ur_monthly_fixed_charge", args[0]->NumberValue());
	}
	void UtilityRate5::SetSellRateEqualToBuyRate(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify 0 or 1 to set sell rate as equal to buy rate")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"ur_sell_eq_buy", args[0]->NumberValue());
	}
	void UtilityRate5::SetMonthlyMinimumCharge(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify valid monthly minimum charge")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"ur_monthly_min_charge", args[0]->NumberValue());
	}
	void UtilityRate5::SetAnnualMinimumCharge(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify valid annual minimum charge")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"ur_annual_min_charge", args[0]->NumberValue());
	}

	void UtilityRate5::EnableTimeStepSellRates(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify 0 or 1 to enable or disable time step sell rates")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"ur_en_ts_sell_rate", args[0]->NumberValue());
	}
	void UtilityRate5::SetTimeStepSellRates(const FunctionCallbackInfo<Value>& args) {

    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t* values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++) {
      values[i]=input->Get(i)->NumberValue();
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_array(obj->pdata_,"ur_ts_sell_rate", values, length);
    delete[] values;
	}

	void UtilityRate5::SetEnergyChargeWeekdaySchedule(const FunctionCallbackInfo<Value>& args) {

    // count total elements
    unsigned int totalElements=0;
    unsigned int nRows=0;
    unsigned int nCols=0;

    Local<Array> rows = Local<Array>::Cast(args[0]);
    nRows=rows->Length();

    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        totalElements++;
      }
    }

    unsigned int idx=0;
    ssc_number_t* values = new ssc_number_t[totalElements];
    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        values[idx]=cols->Get(j)->NumberValue();
        idx++;
      }
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_matrix(obj->pdata_,"ur_ec_sched_weekday", values, nRows, nCols);
    delete[] values;
	}
	void UtilityRate5::SetEnergyChargeWeekendSchedule(const FunctionCallbackInfo<Value>& args) {

    // count total elements
    unsigned int totalElements=0;
    unsigned int nRows=0;
    unsigned int nCols=0;

    Local<Array> rows = Local<Array>::Cast(args[0]);
    nRows=rows->Length();

    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        totalElements++;
      }
    }

    unsigned int idx=0;
    ssc_number_t* values = new ssc_number_t[totalElements];
    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        values[idx]=cols->Get(j)->NumberValue();
        idx++;
      }
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_matrix(obj->pdata_,"ur_ec_sched_weekend", values, nRows, nCols);
    delete[] values;
	}
	void UtilityRate5::SetEnergyRatesTOUTable(const FunctionCallbackInfo<Value>& args) {

    // count total elements
    unsigned int totalElements=0;
    unsigned int nRows=0;
    unsigned int nCols=0;

    Local<Array> rows = Local<Array>::Cast(args[0]);
    nRows=rows->Length();

    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        totalElements++;
      }
    }

    unsigned int idx=0;
    ssc_number_t* values = new ssc_number_t[totalElements];
    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        values[idx]=cols->Get(j)->NumberValue();
        idx++;
      }
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_matrix(obj->pdata_,"ur_ec_tou_mat", values, nRows, nCols);
    delete[] values;
	}

  void UtilityRate5::EnableDemandCharge(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
		if (args.Length() != 1
		|| !args[0]->IsNumber()) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Please specify 0 or 1 to enable or disable demand charge")));
			return;
		}

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_number(obj->pdata_,"ur_dc_enable", args[0]->NumberValue());
	}
	void UtilityRate5::SetDemandChargeWeekdaySchedule(const FunctionCallbackInfo<Value>& args) {

    // count total elements
    unsigned int totalElements=0;
    unsigned int nRows=0;
    unsigned int nCols=0;

    Local<Array> rows = Local<Array>::Cast(args[0]);
    nRows=rows->Length();

    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        totalElements++;
      }
    }

    unsigned int idx=0;
    ssc_number_t* values = new ssc_number_t[totalElements];
    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        values[idx]=cols->Get(j)->NumberValue();
        idx++;
      }
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_matrix(obj->pdata_,"ur_dc_sched_weekday", values, nRows, nCols);
    delete[] values;
	}
	void UtilityRate5::SetDemandChargeWeekendSchedule(const FunctionCallbackInfo<Value>& args) {

    // count total elements
    unsigned int totalElements=0;
    unsigned int nRows=0;
    unsigned int nCols=0;

    Local<Array> rows = Local<Array>::Cast(args[0]);
    nRows=rows->Length();

    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        totalElements++;
      }
    }

    unsigned int idx=0;
    ssc_number_t* values = new ssc_number_t[totalElements];
    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        values[idx]=cols->Get(j)->NumberValue();
        idx++;
      }
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_matrix(obj->pdata_,"ur_dc_sched_weekend", values, nRows, nCols);
    delete[] values;
	}
	void UtilityRate5::SetDemandRatesTOUTable(const FunctionCallbackInfo<Value>& args) {

    // count total elements
    unsigned int totalElements=0;
    unsigned int nRows=0;
    unsigned int nCols=0;

    Local<Array> rows = Local<Array>::Cast(args[0]);
    nRows=rows->Length();

    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        totalElements++;
      }
    }

    unsigned int idx=0;
    ssc_number_t* values = new ssc_number_t[totalElements];
    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        values[idx]=cols->Get(j)->NumberValue();
        idx++;
      }
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_matrix(obj->pdata_,"ur_dc_tou_mat", values, nRows, nCols);
    delete[] values;
	}
	void UtilityRate5::SetDemandRatesFlatTable(const FunctionCallbackInfo<Value>& args) {

    // count total elements
    unsigned int totalElements=0;
    unsigned int nRows=0;
    unsigned int nCols=0;

    Local<Array> rows = Local<Array>::Cast(args[0]);
    nRows=rows->Length();

    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        totalElements++;
      }
    }

    unsigned int idx=0;
    ssc_number_t* values = new ssc_number_t[totalElements];
    for(unsigned int i=0;i<nRows;i++){
      Local<Array> cols=Local<Array>::Cast(rows->Get(i));
      nCols=cols->Length();
      for(unsigned int j=0;j<nCols;j++){
        values[idx]=cols->Get(j)->NumberValue();
        idx++;
      }
    }

		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		ssc_data_set_matrix(obj->pdata_,"ur_dc_flat_mat", values, nRows, nCols);
    delete[] values;
	}

	void UtilityRate5::Run(const FunctionCallbackInfo<Value>& args) {

		Isolate* isolate = args.GetIsolate();
		UtilityRate5* obj = ObjectWrap::Unwrap<UtilityRate5>(args.Holder());
		if (ssc_module_exec(obj->module_, obj->pdata_) !=0){

			Local<Object> response = Object::New(isolate);

			ssc_number_t value=0;

			ssc_data_get_number(obj->pdata_,"elec_cost_with_system_year1", &value);
			response->Set(String::NewFromUtf8(isolate, "electricityBillYear1WithSystem"), Number::New(isolate,value));
      response->Set(String::NewFromUtf8(isolate, "monthlyElectricityBillYear1WithSystem"), GetV8ArrayFromOuput(obj,isolate,"year1_monthly_utility_bill_w_sys"));

      response->Set(String::NewFromUtf8(isolate, "monthlyDemandChargeTOUWithSystem"), GetV8ArrayFromOuput(obj,isolate,"year1_monthly_dc_tou_with_system"));
      response->Set(String::NewFromUtf8(isolate, "monthlyPeakDemandWithSystem"), GetV8ArrayFromOuput(obj,isolate,"year1_monthly_peak_w_system"));
      response->Set(String::NewFromUtf8(isolate, "monthlyDemandChargeFlatWithSystem"), GetV8ArrayFromOuput(obj,isolate,"year1_monthly_dc_fixed_with_system"));

			ssc_data_get_number(obj->pdata_,"elec_cost_without_system_year1", &value);
			response->Set(String::NewFromUtf8(isolate, "electricityBillYear1WithoutSystem"), Number::New(isolate,value));
      response->Set(String::NewFromUtf8(isolate, "monthlyElectricityBillYear1WithoutSystem"), GetV8ArrayFromOuput(obj,isolate,"year1_monthly_utility_bill_wo_sys"));

      response->Set(String::NewFromUtf8(isolate, "touHourlyDemandChargeSchedule"), GetV8ArrayFromOuput(obj,isolate,"year1_hourly_dc_tou_schedule"));
      response->Set(String::NewFromUtf8(isolate, "touHourlyEnergyChargeSchedule"), GetV8ArrayFromOuput(obj,isolate,"year1_hourly_ec_tou_schedule"));

			args.GetReturnValue().Set(response);
		}else{
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Something went wrong. Please ensure that you specify all the parameters")));
			return;
		}
	}

	const char* UtilityRate5::ToCString(const String::Utf8Value& value) {
		return *value ? *value : "<string conversion failed>";
	}
	const Local<Array> UtilityRate5::GetV8ArrayFromOuput(const UtilityRate5* obj, Isolate* isolate, const char* key){

		int len = 0;
		ssc_number_t *data = ssc_data_get_array(obj->pdata_, key, &len);

		Local<Array> arr = Array::New(isolate, len);
		for (int i = 0; i < len; i++) {
			arr->Set(Number::New(isolate, i), Number::New(isolate, data[i]));
		}

		return arr;
	}
}
