#include <node.h>
#include "pvwattsv5.h"
#include "utilityrate5.h"
#include "battwatts.h"

namespace SAM {

	using v8::Local;
	using v8::Object;

	void Initialize(Local<Object> exports) {
		PVWattsV5::Init(exports);
    UtilityRate5::Init(exports);
    BattWatts::Init(exports);
	}

	NODE_MODULE(sam, Initialize)
}
