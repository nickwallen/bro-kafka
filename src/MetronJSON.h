
#ifndef BRO_PLUGIN_METRON_KAFKA_METRONJSON_H
#define BRO_PLUGIN_METRON_KAFKA_METRONJSON_H

#include <string>
#include <threading/Formatter.h>
#include <threading/formatters/JSON.h>

using threading::Field;
using threading::Value;
using threading::formatter::JSON;

namespace metron {
namespace formatter {

 /**
  * A formatter that produces bro records in a format accepted by
  * Metron. Specifically, the stream ID is prepended to each JSON
  * formatted log record.
  *
  * {"conn": { ... }}
  * {"dns":  { ... }}
  */
    class MetronJSON : public JSON {

    public:
        MetronJSON(string stream_name, threading::MsgThread* t, TimeFormat tf);
        virtual ~MetronJSON();
        virtual bool Describe(ODesc* desc, int num_fields, const Field* const* fields,
            Value** vals) const;

    private:
        string stream_name;
    };
}
}

#endif
