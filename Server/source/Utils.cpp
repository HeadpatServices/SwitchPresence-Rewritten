#include "Utils.h"
#include <cstring>

namespace Utils
{
const char *getAppName(u64 application_id)
{
    static NsApplicationControlData appControlData;
    size_t appControlDataSize = 0;
    NacpLanguageEntry *languageEntry = nullptr;

    memset(&appControlData, 0x00, sizeof(NsApplicationControlData));

    if (R_FAILED(nsGetApplicationControlData(NsApplicationControlSource_Storage, application_id, &appControlData, sizeof(NsApplicationControlData), &appControlDataSize)))
        goto final;

    if (R_FAILED(nacpGetLanguageEntry(&appControlData.nacp, &languageEntry)))
        goto final;

    final:
    if (languageEntry == nullptr)
        return "A Game";
    else
        return languageEntry->name;
}
} // namespace Utils
