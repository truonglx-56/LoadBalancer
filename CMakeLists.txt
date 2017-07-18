cmake_minimum_required(VERSION 3.7)
project(libvmod_snw)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        autom4te.cache/output.0
        autom4te.cache/output.1
        autom4te.cache/output.2
        autom4te.cache/requests
        autom4te.cache/traces.0
        autom4te.cache/traces.1
        autom4te.cache/traces.2
        build-aux/ar-lib
        build-aux/compile
        build-aux/config.guess
        build-aux/config.sub
        build-aux/depcomp
        build-aux/install-sh
        build-aux/ltmain.sh
        build-aux/missing
        build-aux/test-driver
        m4/ax_pthread.m4
        m4/libtool.m4
        m4/ltoptions.m4
        m4/ltsugar.m4
        m4/ltversion.m4
        m4/lt~obsolete.m4
        src/tests/test01.vtc
        src/libvmod_snw.la
        src/Makefile
        src/Makefile.am
        src/Makefile.in
        src/vcc_snw_if.c
        src/vcc_snw_if.h
        src/vcc_snw_if.lo
        src/vmod_snw.3
        src/vmod_snw.c
        src/vmod_snw.lo
        src/vmod_snw.man.rst
        src/vmod_snw.rst
        src/vmod_snw.vcc
        aclocal.m4
        autogen.sh
        CHANGES.rst
        config.h
        config.h.in
        config.log
        config.status
        configure
        configure.ac
        COPYING
        libtool
        LICENSE
        Makefile
        Makefile.am
        Makefile.in
        README.rst
        stamp-h1 src/shard_manager.c)

add_executable(libvmod_snw ${SOURCE_FILES})