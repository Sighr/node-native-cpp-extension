#define NAPI_CPP_EXCEPTIONS
#include "node_modules/node-addon-api/napi.h"

int previous = 0;
int current = 1;

int get()
{
    int temp = current;
    current += previous;
    previous = temp;
    return temp;
}

Napi::Number GetWrapped(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();
  Napi::Number returnValue = Napi::Number::New(env, get());

  return returnValue;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "get"), Napi::Function::New(env, GetWrapped));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
