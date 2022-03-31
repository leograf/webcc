#include <cassert>
#include <iostream>

#include "webcc/client_session.h"
#include "webcc/logger.h"
#include "webcc/string.h"

int main() {
  WEBCC_LOG_INIT("", webcc::LOG_CONSOLE);

  webcc::ClientSession session;

  webcc::ResponsePtr r;

  try {
    r = session.Send(webcc::RequestBuilder{}.
                     Get("http://httpbin.org/get").
                     Query("name", webcc::Utf16To8(L"顾春庭"), true)
                     ());

    assert(r->status() == webcc::status_codes::kOK);

  } catch (const webcc::Error& error) {
    std::cerr << error << std::endl;
    return 1;
  }

  return 0;
}
