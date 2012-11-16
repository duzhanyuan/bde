// bsls_buildtarget.h                                                 -*-C++-*-
#ifndef INCLUDED_BSLS_BUILDTARGET
#define INCLUDED_BSLS_BUILDTARGET

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide build-target information in the object file.
//
//@CLASSES:
//  bsls::ExcBuildTarget: type name for identifying exception builds
//  bsls::MtBuildTarget: type name for identifying multi-threaded builds
//
//@MACROS:
//  BDE_BUILD_TARGET_EXC: flag for exception-enabled builds
//  BDE_BUILD_TARGET_MT:  flag for multi-threaded builds
//
//@DESCRIPTION: The purpose of this component is to cause a link-time error
// when trying to link an executable with incompatible libraries.  This
// component defines type names that indicate the build target parameters.
// These parameters include whether this build was exception-enabled (which is
// the case unless overridden by defining the 'BDE_BUILD_TARGET_NO_EXC' macro),
// and whether it was multi-threaded or not (it is enabled unless overridden by
// defining the 'BDE_BUILD_TARGET_NO_MT' macro).  The types defined by this
// component should not be used directly.

#ifndef INCLUDED_BSLS_PLATFORM
#include <bsls_platform.h>
#endif

namespace BloombergLP {

// Default to an exception-enabled build unless 'BDE_BUILD_TARGET_NO_EXC' is
// defined.
#ifndef BDE_BUILD_TARGET_NO_EXC

#ifndef BDE_BUILD_TARGET_EXC
#define BDE_BUILD_TARGET_EXC
#endif

namespace bsls {

struct YesExcBuildTarget {
    static const int d_isExcBuildTarget;
};
typedef YesExcBuildTarget ExcBuildTarget;

}  // close package namespace


#else

#ifdef BDE_BUILD_TARGET_EXC
#error Do not define both BDE_BUILD_TARGET_EXC and BDE_BUILD_TARGET_NO_EXC
#endif

namespace bsls {

struct NoExcBuildTarget {
    static const int d_isExcBuildTarget;
};
typedef NoExcBuildTarget ExcBuildTarget;

}  // close package namespace


#endif

// Default to a threaded (MT) build unless 'BDE_BUILD_TARGET_NO_MT' is defined.
#ifndef BDE_BUILD_TARGET_NO_MT

#ifndef BDE_BUILD_TARGET_MT
#define BDE_BUILD_TARGET_MT
#endif

namespace bsls {

struct YesMtBuildTarget {
    static const int d_isMtBuildTarget;
};
typedef YesMtBuildTarget MtBuildTarget;

}  // close package namespace


#else

#ifdef BDE_BUILD_TARGET_MT
#error Do not define both BDE_BUILD_TARGET_MT and BDE_BUILD_TARGET_NO_MT
#endif

namespace bsls {

struct NoMtBuildTarget {
    static const int d_isMtBuildTarget;
};
typedef NoMtBuildTarget MtBuildTarget;

}  // close package namespace


#endif

#ifdef BSLS_PLATFORM_CPU_64_BIT

namespace bsls {

struct Yes64BitBuildTarget {
    static const int d_is64BitBuildTarget;
};

}  // close package namespace


#else

namespace bsls {

struct No64BitBuildTarget {
    static const int d_is64BitBuildTarget;
};

}  // close package namespace


#endif

// Force linker to pull in this component's object file.

#if defined(BSLS_PLATFORM_CMP_IBM)
static const int *bsls_buildtarget_assertion1 =
                                     &bsls::ExcBuildTarget::d_isExcBuildTarget;
static const int *bsls_buildtarget_assertion2 =
                                       &bsls::MtBuildTarget::d_isMtBuildTarget;
#else
namespace {
    extern const int *const bsls_buildtarget_assertion1 =
                                     &bsls::ExcBuildTarget::d_isExcBuildTarget;
    extern const int *const bsls_buildtarget_assertion2 =
                                       &bsls::MtBuildTarget::d_isMtBuildTarget;
}
#endif


}  // close enterprise namespace

#endif

// ----------------------------------------------------------------------------
// Copyright (C) 2012 Bloomberg L.P.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------- END-OF-FILE ----------------------------------
