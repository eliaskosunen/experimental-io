#pragma once

#define XIO_BEGIN_NAMESPACE \
    namespace xio {         \
    inline namespace v0 {
#define XIO_END_NAMESPACE \
    }                     \
    }

#define RANGES_NS ::std::experimental::ranges
