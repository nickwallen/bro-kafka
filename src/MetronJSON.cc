
#include <threading/Formatter.h>
#include "MetronJSON.h"

using metron::formatter::MetronJSON;
using threading::formatter::JSON;
using threading::MsgThread;
using threading::Field;
using threading::Value;

MetronJSON::MetronJSON(string sn, MsgThread* t, TimeFormat tf)
    : JSON(t, tf)
    , stream_name(sn)
{
}

MetronJSON::~MetronJSON() {}

bool MetronJSON::Describe(ODesc* desc, int num_fields,
    const Field* const* fields, Value** vals) const
{
    desc->AddRaw("{");

    // prepend the stream name
    desc->AddRaw("\"");
    desc->AddRaw(stream_name);
    desc->AddRaw("\", ");

    // append the JSON formatted log record itself
    JSON::Describe(desc, num_fields, fields, vals);

    desc->AddRaw("}");
    return true;
}
