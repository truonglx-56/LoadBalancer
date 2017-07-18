/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit vmod.vcc and run make instead
 */

#include "config.h"
#include <stdio.h>
#include "vdef.h"
#include "vcl.h"
#include "vrt.h"
#include "vcc_snw_if.h"
#include "vmod_abi.h"

typedef VCL_STRING td_snw_info(VRT_CTX);
typedef VCL_STRING td_snw_hello(VRT_CTX, VCL_STRING);
typedef VCL_BACKEND td_snw_app(VRT_CTX);
typedef VCL_INT td_snw_get_token(VRT_CTX);
typedef VCL_INT td_snw_get_objectId(VRT_CTX);
typedef VCL_BOOL td_snw_create(VRT_CTX, struct vmod_priv *,
    VCL_STRING, VCL_STRING, VCL_STRING, VCL_PROBE, VCL_STRING,
    VCL_DURATION, VCL_DURATION, VCL_DURATION, VCL_INT, VCL_INT);
typedef VCL_BACKEND td_snw_by_name(VRT_CTX, struct vmod_priv *,
    VCL_STRING);
typedef VCL_BOOL td_snw_delete(VRT_CTX, struct vmod_priv *,
    VCL_BACKEND);
typedef VCL_STRING td_snw_version(VRT_CTX);

struct Vmod_snw_Func {
	vmod_event_f			*_event;
	td_snw_info			*info;
	td_snw_hello			*hello;
	td_snw_app			*app;
	td_snw_get_token		*get_token;
	td_snw_get_objectId		*get_objectId;
	td_snw_create			*create;
	td_snw_by_name			*by_name;
	td_snw_delete			*delete;
	td_snw_version			*version;
};

/*lint -esym(754, Vmod_snw_Func::*) */

static const struct Vmod_snw_Func Vmod_Func = {
	event_function,
	vmod_info,
	vmod_hello,
	vmod_app,
	vmod_get_token,
	vmod_get_objectId,
	vmod_create,
	vmod_by_name,
	vmod_delete,
	vmod_version,
};

static const char Vmod_Proto[] =
	"/* Functions */\n"
	"typedef VCL_STRING td_snw_info(VRT_CTX);\n"
	"typedef VCL_STRING td_snw_hello(VRT_CTX, VCL_STRING);\n"
	"typedef VCL_BACKEND td_snw_app(VRT_CTX);\n"
	"typedef VCL_INT td_snw_get_token(VRT_CTX);\n"
	"typedef VCL_INT td_snw_get_objectId(VRT_CTX);\n"
	"typedef VCL_BOOL td_snw_create(VRT_CTX, struct vmod_priv *,\n"
	"    VCL_STRING, VCL_STRING, VCL_STRING, VCL_PROBE, VCL_STRING,\n"
	"    VCL_DURATION, VCL_DURATION, VCL_DURATION, VCL_INT, VCL_INT);\n"
	"typedef VCL_BACKEND td_snw_by_name(VRT_CTX, struct vmod_priv *,\n"
	"    VCL_STRING);\n"
	"typedef VCL_BOOL td_snw_delete(VRT_CTX, struct vmod_priv *,\n"
	"    VCL_BACKEND);\n"
	"typedef VCL_STRING td_snw_version(VRT_CTX);\n"
	"\n"
	"struct Vmod_snw_Func {\n"
	"	vmod_event_f			*_event;\n"
	"	td_snw_info			*info;\n"
	"	td_snw_hello			*hello;\n"
	"	td_snw_app			*app;\n"
	"	td_snw_get_token		*get_token;\n"
	"	td_snw_get_objectId		*get_objectId;\n"
	"	td_snw_create			*create;\n"
	"	td_snw_by_name			*by_name;\n"
	"	td_snw_delete			*delete;\n"
	"	td_snw_version			*version;\n"
	"};\n"
	"static struct Vmod_snw_Func Vmod_snw_Func;";

/*lint -save -e786 -e840 */
static const char * const Vmod_Spec[] = {
	"$EVENT\0"
	    "Vmod_snw_Func._event",

	"$FUNC\0"	"snw.info\0"

	    "STRING\0"
	    "Vmod_snw_Func.info\0"
		"\0"
	    "\0",

	"$FUNC\0"	"snw.hello\0"

	    "STRING\0"
	    "Vmod_snw_Func.hello\0"
		"STRING\0"
		"\0"
	    "\0",

	"$FUNC\0"	"snw.app\0"

	    "BACKEND\0"
	    "Vmod_snw_Func.app\0"
		"\0"
	    "\0",

	"$FUNC\0"	"snw.get_token\0"

	    "INT\0"
	    "Vmod_snw_Func.get_token\0"
		"\0"
	    "\0",

	"$FUNC\0"	"snw.get_objectId\0"

	    "INT\0"
	    "Vmod_snw_Func.get_objectId\0"
		"\0"
	    "\0",

	"$FUNC\0"	"snw.create\0"

	    "BOOL\0"
	    "Vmod_snw_Func.create\0"
		"PRIV_VCL\0"
		"STRING\0"
		    "\2" "name\0"
		"STRING\0"
		    "\2" "host\0"
		"STRING\0"
		    "\2" "port\0"
		    "\3" "\"\"\0"
		"PROBE\0"
		    "\2" "probe\0"
		    "\3" "0\0"
		"STRING\0"
		    "\2" "host_header\0"
		    "\3" "\"\"\0"
		"DURATION\0"
		    "\2" "connect_timeout\0"
		    "\3" "0\0"
		"DURATION\0"
		    "\2" "first_byte_timeout\0"
		    "\3" "0\0"
		"DURATION\0"
		    "\2" "between_bytes_timeout\0"
		    "\3" "0\0"
		"INT\0"
		    "\2" "max_connections\0"
		    "\3" "0\0"
		"INT\0"
		    "\2" "proxy_header\0"
		    "\3" "0\0"
		"\0"
	    "\0",

	"$FUNC\0"	"snw.by_name\0"

	    "BACKEND\0"
	    "Vmod_snw_Func.by_name\0"
		"PRIV_VCL\0"
		"STRING\0"
		    "\2" "name\0"
		"\0"
	    "\0",

	"$FUNC\0"	"snw.delete\0"

	    "BOOL\0"
	    "Vmod_snw_Func.delete\0"
		"PRIV_VCL\0"
		"BACKEND\0"
		    "\2" "be\0"
		"\0"
	    "\0",

	"$FUNC\0"	"snw.version\0"

	    "STRING\0"
	    "Vmod_snw_Func.version\0"
		"\0"
	    "\0",

	0
};
/*lint -restore */

/*lint -esym(714, Vmod_snw_Data) */

/*lint -esym(759, Vmod_snw_Data) */

/*lint -esym(765, Vmod_snw_Data) */
const struct vmod_data Vmod_snw_Data = {
	.vrt_major =	VRT_MAJOR_VERSION,
	.vrt_minor =	VRT_MINOR_VERSION,
	.name =		"snw",
	.func =		&Vmod_Func,
	.func_len =	sizeof(Vmod_Func),
	.proto =	Vmod_Proto,
	.spec =		Vmod_Spec,
	.abi =		VMOD_ABI_Version,
	.file_id =	"YIIJBRSKMOOKHGEDCTIOIMH@TYMKPIGT",
};
