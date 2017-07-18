AM_CFLAGS = $(VARNISHAPI_CFLAGS) -Wall -Werror
AM_LDFLAGS = $(VARNISHAPI_LIBS) $(VMOD_LDFLAGS)

LIBS = -lthrift_c_glib `pkg-config --libs glib-2.0 gobject-2.0`
THRIFT = thrift --gen c_glib
CLISRC = vmod_snw.c snw_shard_service.c snw_shard_service_types.c

vmod_LTLIBRARIES = libvmod_snw.la

libvmod_snw_la_SOURCES = \
	vmod_snw.c

nodist_libvmod_snw_la_SOURCES = \
	vcc_snw_if.c \
	vcc_snw_if.h \
	snw_shard_service_types.c \
	snw_shard_service_types.h \
	snw_shard_service.c \
	snw_shard_service.h

dist_man_MANS = vmod_snw.3

@BUILD_VMOD_SNW@

AM_TESTS_ENVIRONMENT = \
	PATH="$(VMOD_TEST_PATH)" \
	LD_LIBRARY_PATH="$(VARNISH_LIBRARY_PATH)"
TEST_EXTENSIONS = .vtc
VTC_LOG_COMPILER = varnishtest -v
AM_VTC_LOG_FLAGS = -Dvmod_snw="$(VMOD_SNW)"

TESTS = @VMOD_TESTS@

EXTRA_DIST = \
	vmod_snw.vcc \
	$(VMOD_TESTS)
