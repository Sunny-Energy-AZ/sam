#include "battwatts.h"
#include "../ssc/include/sscapi.h"
#include <iostream>

namespace SAM
{

  using v8::Array;
  using v8::Context;
  using v8::Exception;
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

  Persistent<Function> BattWatts::constructor;

  BattWatts::BattWatts()
  {
    pdata_ = ssc_data_create();
    module_ = ssc_module_create("battwatts");
  }

  BattWatts::~BattWatts()
  {
    ssc_module_free(module_);
    ssc_data_free(pdata_);
  }

  void BattWatts::Init(Local<Object> exports)
  {
    Isolate *isolate = exports->GetIsolate();

    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->SetClassName(String::NewFromUtf8(isolate, "BattWatts"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // Prototype
    NODE_SET_PROTOTYPE_METHOD(tpl, "setEnableBattery", SetEnableBattery);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setBatteryChemistry", SetBatteryChemistry);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setBatteryCapacity", SetBatteryCapacity);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setBatteryPower", SetBatteryPower);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setBatteryDispatch", SetBatteryDispatch);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setChargeFromPV", SetChargeFromPV);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setChargeFromGrid", SetChargeFromGrid);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setDischarge", SetDischarge);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setChargeFromGridPercentage", SetChargeFromGridPercentage);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setDischargePercentage", SetDischargePercentage);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setDispatchManualWeekdaySchedule", SetDispatchManualWeekdaySchedule);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setDispatchManualWeekendSchedule", SetDispatchManualWeekendSchedule);

    NODE_SET_PROTOTYPE_METHOD(tpl, "setElectricityLoad", SetElectricityLoad);

    NODE_SET_PROTOTYPE_METHOD(tpl, "setACPower", SetACPower);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setDCPower", SetDCPower);

    NODE_SET_PROTOTYPE_METHOD(tpl, "setInverterModel", SetInverterModel);
    NODE_SET_PROTOTYPE_METHOD(tpl, "setInverterEfficiency", SetInverterEfficiency);

    NODE_SET_PROTOTYPE_METHOD(tpl, "run", Run);

    constructor.Reset(isolate, tpl->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "BattWatts"),
                 tpl->GetFunction());
  }

  void BattWatts::New(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();

    if (args.IsConstructCall())
    {
      // Invoked as constructor: `new BattWatts(...)`
      BattWatts *obj = new BattWatts();
      obj->Wrap(args.This());
      args.GetReturnValue().Set(args.This());
    }
    else
    {
      // Invoked as plain function `BattWatts(...)`, turn into construct call.
      const int argc = 1;
      Local<Value> argv[argc] = {args[0]};
      Local<Context> context = isolate->GetCurrentContext();
      Local<Function> cons = Local<Function>::New(isolate, constructor);
      Local<Object> result =
          cons->NewInstance(context, argc, argv).ToLocalChecked();
      args.GetReturnValue().Set(result);
    }
  }

  void BattWatts::SetEnableBattery(const FunctionCallbackInfo<Value> &args)
  {

    Isolate *isolate = args.GetIsolate();
    if (args.Length() != 1 || !args[0]->IsNumber() || (args[0]->NumberValue() < 0 || args[0]->NumberValue() > 1))
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Please specify a valid battery enable type. 0: Disable, 1: Enable")));
      return;
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_number(obj->pdata_, "batt_simple_enable", args[0]->NumberValue());
  }

  void BattWatts::SetInverterModel(const FunctionCallbackInfo<Value> &args)
  {

    Isolate *isolate = args.GetIsolate();
    if (args.Length() != 1 || !args[0]->IsNumber() || (args[0]->NumberValue() < 0 || args[0]->NumberValue() > 4))
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Please specify a valid inverter model. 0: cec,1: datasheet, 2:partload, 3:coefficientgenerator, 4:generic")));
      return;
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_number(obj->pdata_, "inverter_model", args[0]->NumberValue());
  }

  void BattWatts::SetInverterEfficiency(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();
    if (args.Length() != 1 || !args[0]->IsNumber() || (args[0]->NumberValue() < 90 || args[0]->NumberValue() > 99.5))
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Please specify a valid inverter efficiency")));
      return;
    }
    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_number(obj->pdata_, "inverter_efficiency", args[0]->NumberValue());
  }

  void BattWatts::SetBatteryChemistry(const FunctionCallbackInfo<Value> &args)
  {

    Isolate *isolate = args.GetIsolate();
    if (args.Length() != 1 || !args[0]->IsNumber() || (args[0]->NumberValue() < 0 || args[0]->NumberValue() > 1))
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Please specify a valid battery chemistry. 0: Lead Acid, 1: Li-ion")));
      return;
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_number(obj->pdata_, "batt_simple_chemistry", args[0]->NumberValue());
  }

  void BattWatts::SetBatteryCapacity(const FunctionCallbackInfo<Value> &args)
  {

    Isolate *isolate = args.GetIsolate();
    if (args.Length() != 1 || !args[0]->IsNumber())
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Please specify a valid battery capacity")));
      return;
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_number(obj->pdata_, "batt_simple_kwh", args[0]->NumberValue());
  }

  void BattWatts::SetBatteryPower(const FunctionCallbackInfo<Value> &args)
  {

    Isolate *isolate = args.GetIsolate();
    if (args.Length() != 1 || !args[0]->IsNumber())
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Please specify a valid battery power")));
      return;
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_number(obj->pdata_, "batt_simple_kw", args[0]->NumberValue());
  }

  void BattWatts::SetBatteryDispatch(const FunctionCallbackInfo<Value> &args)
  {

    Isolate *isolate = args.GetIsolate();
    if (args.Length() != 1 || !args[0]->IsNumber() || (args[0]->NumberValue() < 0 || args[0]->NumberValue() > 4))
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Please specify a valid battery dispatch. 0: Peak shaving look ahead 1: Peak shaving look behind 4: Manual Dispatch")));
      return;
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_number(obj->pdata_, "batt_simple_dispatch", args[0]->NumberValue());
  }

  void BattWatts::SetChargeFromPV(const FunctionCallbackInfo<Value> &args)
  {

    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t *values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++)
    {
      values[i] = input->Get(i)->BooleanValue();
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_array(obj->pdata_, "dispatch_manual_charge", values, length);
    delete[] values;
  }

  void BattWatts::SetChargeFromGrid(const FunctionCallbackInfo<Value> &args)
  {

    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t *values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++)
    {
      values[i] = input->Get(i)->BooleanValue();
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_array(obj->pdata_, "dispatch_manual_gridcharge", values, length);
    delete[] values;
  }

  void BattWatts::SetDischarge(const FunctionCallbackInfo<Value> &args)
  {

    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t *values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++)
    {
      values[i] = input->Get(i)->BooleanValue();
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_array(obj->pdata_, "dispatch_manual_discharge", values, length);
    delete[] values;
  }

  void BattWatts::SetChargeFromGridPercentage(const FunctionCallbackInfo<Value> &args)
  {

    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t *values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++)
    {
      values[i] = input->Get(i)->NumberValue();
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_array(obj->pdata_, "dispatch_manual_percent_gridcharge", values, length);
    delete[] values;
  }

  void BattWatts::SetDischargePercentage(const FunctionCallbackInfo<Value> &args)
  {
    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t *values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++)
    {
      values[i] = input->Get(i)->NumberValue();
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_array(obj->pdata_, "dispatch_manual_percent_discharge", values, length);
    delete[] values;
  }

  void BattWatts::SetDispatchManualWeekdaySchedule(const FunctionCallbackInfo<Value> &args)
  {

    // count total elements
    unsigned int totalElements = 0;
    unsigned int nRows = 0;
    unsigned int nCols = 0;

    Local<Array> rows = Local<Array>::Cast(args[0]);
    nRows = rows->Length();

    for (unsigned int i = 0; i < nRows; i++)
    {
      Local<Array> cols = Local<Array>::Cast(rows->Get(i));
      nCols = cols->Length();
      for (unsigned int j = 0; j < nCols; j++)
      {
        totalElements++;
      }
    }

    unsigned int idx = 0;
    ssc_number_t *values = new ssc_number_t[totalElements];
    for (unsigned int i = 0; i < nRows; i++)
    {
      Local<Array> cols = Local<Array>::Cast(rows->Get(i));
      nCols = cols->Length();
      for (unsigned int j = 0; j < nCols; j++)
      {
        values[idx] = cols->Get(j)->NumberValue();
        idx++;
      }
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_matrix(obj->pdata_, "dispatch_manual_sched", values, nRows, nCols);
    delete[] values;
  }

  void BattWatts::SetDispatchManualWeekendSchedule(const FunctionCallbackInfo<Value> &args)
  {

    // count total elements
    unsigned int totalElements = 0;
    unsigned int nRows = 0;
    unsigned int nCols = 0;

    Local<Array> rows = Local<Array>::Cast(args[0]);
    nRows = rows->Length();

    for (unsigned int i = 0; i < nRows; i++)
    {
      Local<Array> cols = Local<Array>::Cast(rows->Get(i));
      nCols = cols->Length();
      for (unsigned int j = 0; j < nCols; j++)
      {
        totalElements++;
      }
    }

    unsigned int idx = 0;
    ssc_number_t *values = new ssc_number_t[totalElements];
    for (unsigned int i = 0; i < nRows; i++)
    {
      Local<Array> cols = Local<Array>::Cast(rows->Get(i));
      nCols = cols->Length();
      for (unsigned int j = 0; j < nCols; j++)
      {
        values[idx] = cols->Get(j)->NumberValue();
        idx++;
      }
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_matrix(obj->pdata_, "dispatch_manual_sched_weekend", values, nRows, nCols);
    delete[] values;
  }

  void BattWatts::SetElectricityLoad(const FunctionCallbackInfo<Value> &args)
  {

    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t *values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++)
    {
      values[i] = input->Get(i)->NumberValue();
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_array(obj->pdata_, "load", values, length);
    delete[] values;
  }

  void BattWatts::SetDCPower(const FunctionCallbackInfo<Value> &args)
  {

    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t *values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++)
    {
      values[i] = input->Get(i)->NumberValue();
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_array(obj->pdata_, "dc", values, length);
    delete[] values;
  }

  void BattWatts::SetACPower(const FunctionCallbackInfo<Value> &args)
  {

    Local<Array> input = Local<Array>::Cast(args[0]);
    unsigned int length = input->Length();

    ssc_number_t *values = new ssc_number_t[length];
    for (unsigned int i = 0; i < length; i++)
    {
      values[i] = input->Get(i)->NumberValue();
    }

    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    ssc_data_set_array(obj->pdata_, "ac", values, length);
    delete[] values;
  }

  void BattWatts::Run(const FunctionCallbackInfo<Value> &args)
  {

    Isolate *isolate = args.GetIsolate();
    BattWatts *obj = ObjectWrap::Unwrap<BattWatts>(args.Holder());
    if (ssc_module_exec(obj->module_, obj->pdata_) != 0)
    {

      Local<Object> response = Object::New(isolate);
      response->Set(String::NewFromUtf8(isolate, "electrictyToLoadFromPV"), GetV8ArrayFromOuput(obj, isolate, "pv_to_load"));
      response->Set(String::NewFromUtf8(isolate, "electrictyToLoadFromBattery"), GetV8ArrayFromOuput(obj, isolate, "batt_to_load"));
      response->Set(String::NewFromUtf8(isolate, "electrictyToBatteryFromPV"), GetV8ArrayFromOuput(obj, isolate, "pv_to_batt"));
      response->Set(String::NewFromUtf8(isolate, "electrictyToLoadFromGrid"), GetV8ArrayFromOuput(obj, isolate, "grid_to_load"));
      response->Set(String::NewFromUtf8(isolate, "electrictyToGridFromPV"), GetV8ArrayFromOuput(obj, isolate, "pv_to_grid"));
      response->Set(String::NewFromUtf8(isolate, "electrictyToGridFromBattery"), GetV8ArrayFromOuput(obj, isolate, "batt_to_grid"));
      response->Set(String::NewFromUtf8(isolate, "electrictyToBatteryFromGrid"), GetV8ArrayFromOuput(obj, isolate, "grid_to_batt"));
      response->Set(String::NewFromUtf8(isolate, "powerGenerated"), GetV8ArrayFromOuput(obj, isolate, "gen"));

      response->Set(String::NewFromUtf8(isolate, "monthlyElectrictyToLoadFromPV"), GetV8ArrayFromOuput(obj, isolate, "monthly_pv_to_load"));
      response->Set(String::NewFromUtf8(isolate, "monthlyElectrictyToLoadFromBattery"), GetV8ArrayFromOuput(obj, isolate, "monthly_batt_to_load"));
      response->Set(String::NewFromUtf8(isolate, "monthlyElectrictyToGridFromPV"), GetV8ArrayFromOuput(obj, isolate, "monthly_pv_to_grid"));
      response->Set(String::NewFromUtf8(isolate, "monthlyElectrictyToGridFromBattery"), GetV8ArrayFromOuput(obj, isolate, "monthly_batt_to_grid"));

      response->Set(String::NewFromUtf8(isolate, "batteryTotalCharge"), GetV8ArrayFromOuput(obj, isolate, "batt_q0"));
      response->Set(String::NewFromUtf8(isolate, "batteryAvailableCharge"), GetV8ArrayFromOuput(obj, isolate, "batt_q1"));
      response->Set(String::NewFromUtf8(isolate, "batteryBound"), GetV8ArrayFromOuput(obj, isolate, "batt_q2"));
      response->Set(String::NewFromUtf8(isolate, "batteryStateOfCharge"), GetV8ArrayFromOuput(obj, isolate, "batt_SOC"));
      response->Set(String::NewFromUtf8(isolate, "batteryDepthOfDischarge"), GetV8ArrayFromOuput(obj, isolate, "batt_DOD"));
      response->Set(String::NewFromUtf8(isolate, "batteryMaxCapacityAtCurrent"), GetV8ArrayFromOuput(obj, isolate, "batt_qmaxI"));
      response->Set(String::NewFromUtf8(isolate, "batteryMaxChargeWithDegradation"), GetV8ArrayFromOuput(obj, isolate, "batt_qmax"));
      response->Set(String::NewFromUtf8(isolate, "batteryMaxChargeAtTemperature"), GetV8ArrayFromOuput(obj, isolate, "batt_qmax_thermal"));

      args.GetReturnValue().Set(response);
    }
    else
    {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Something went wrong. Please ensure that you specify all the parameters")));
      return;
    }
  }

  const char *BattWatts::ToCString(const String::Utf8Value &value)
  {
    return *value ? *value : "<string conversion failed>";
  }

  const Local<Array> BattWatts::GetV8ArrayFromOuput(const BattWatts *obj, Isolate *isolate, const char *key)
  {

    int len = 0;
    ssc_number_t *data = ssc_data_get_array(obj->pdata_, key, &len);

    Local<Array> arr = Array::New(isolate, len);
    for (int i = 0; i < len; i++)
    {
      arr->Set(Number::New(isolate, i), Number::New(isolate, data[i]));
    }

    return arr;
  }
}
