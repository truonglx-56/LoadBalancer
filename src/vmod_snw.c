#include "config.h"
#include <stdio.h>
#include <glib.h>
#include <stdlib.h>
#include <glib-object.h>

#include "vcl.h"
#include "vrt.h"
#include "cache/cache.h"
#include "vtim.h"
#include "vcc_snw_if.h"

#include <thrift/c_glib/processor/thrift_dispatch_processor.h>
#include <thrift/c_glib/transport/thrift_transport.h>
#include <thrift/c_glib/transport/thrift_socket.h>
#include <thrift/c_glib/transport/thrift_buffered_transport.h>
#include <thrift/c_glib/protocol/thrift_binary_protocol.h>

#include "snw_shard_service.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdarg.h>
#include <pthread.h>

#include "vas.h"
#include "vsa.h"
#include "vtcp.h"
#include "vdef.h"
#include "vsb.h"
#include "cache/cache_director.h"
#include "cache/cache_backend.h"
#include "vapi/vsl.h"

#define _POSIX_C_SOURCE 200809L

const size_t infosz = 64;
char *info;
GHashTable *table;
/*
 * handle vmod internal state, vmod init/fini and/or varnish callback
 * (un)registration here.
 *
 * malloc'ing the info buffer is only indended as a demonstration, for any
 * real-world vmod, a fixed-sized buffer should be a global variable
 */

int __match_proto__( vmod_event_f)

event_function( VRT_CTX, struct vmod_priv *priv, enum vcl_event_e e) {
	char ts[VTIM_FORMAT_SIZE];
	const char *event = NULL;

	(void) ctx;
	(void) priv;

	switch (e) {
	case VCL_EVENT_LOAD:
		info = malloc(infosz);
		if (!info)
			return (-1);
		event = "loaded";
		break;
	case VCL_EVENT_WARM:
		event = "warmed";
		break;
	case VCL_EVENT_COLD:
		event = "cooled";
		break;
	case VCL_EVENT_DISCARD:
		free(info);
		return (0);
		break;
	default:
		return (0);
	}
	AN(event);

	VTIM_format(VTIM_real(), ts

	);
	snprintf(info, infosz, "vmod_snw %s at %s", event, ts);

	return (0);
}

VCL_STRING vmod_info( VRT_CTX) {
//    ShardServiceIf *serviceIf;
//    shard_service_client_shard_map(serviceIf);
	(void) ctx;

	return (info);
}

VCL_STRING vmod_hello( VRT_CTX, VCL_STRING name) {
	char *p;
	unsigned u, v;

	u = WS_Reserve(ctx->ws, 0); /* Reserve some work space */
	p = ctx->ws->f; /* Front of workspace area */
	v = snprintf(p, u, "Helyulo, %p", (ctx->req));
	v++;
	if (v > u) {
		/* No space, reset and leave */
		WS_Release(ctx->ws, 0);
		return (NULL);
	}
	/* Update work space with what we've used */
	WS_Release(ctx->ws, v);
	return (p);
}

//overide
VCL_BACKEND vmod_app( VRT_CTX) {

	//vmod_create(ctx,priv,"TruongLX","127.0.0.1","8080",,)
	//shard_service_client_get_type();
	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	return (NULL);
}

VCL_INT vmod_get_objectId( VRT_CTX) {
	return (0);
}

static int get_server( VRT_CTX) {
	ThriftSocket *socket;
	ThriftTransport *transport;
	ThriftProtocol *protocol;

	//helloSvcIf *client;
	snwShardServiceIf *client;
	gboolean success;
	//gboolean tmp;
	gchar *type = "database";
	gchar *token = "123456789";    //Token
	GhashTable *table1 = g_hash_table_new_full(g_direct_hash, g_direct_equal,
			NULL, NULL);
	table = &(*table1);
	GError *error = NULL;
	//gdouble *version = 0;
	snwInvalidOperation *snwInvalid = NULL;

#if (!GLIB_CHECK_VERSION (2, 36, 0))
	g_type_init ();
#endif

	socket = g_object_new(THRIFT_TYPE_SOCKET, "hostname", "10.2.22.140", "port",
			9090, NULL);
	transport = g_object_new(THRIFT_TYPE_BUFFERED_TRANSPORT, "transport",
			socket, NULL);
	protocol = g_object_new(THRIFT_TYPE_BINARY_PROTOCOL, "transport", transport,
			NULL);

	client = g_object_new(SNW_TYPE_SHARD_SERVICE_CLIENT, "input_protocol",
			protocol, "output_protocol", protocol, NULL);
	success = thrift_transport_open(transport, &error)
			&& snw_shard_service_if_shard_map(client, &table, type, 1.0, token,
					&snwInvalid, &error);
	//hello_svc_if_get_message (client, &message, "world!", &error);
	//	gboolean snw_shard_service_if_shard_map (snwShardServiceIf *iface, GHashTable ** _return,
	//			const gchar * type, const gdouble version, const gchar * token,
	//			snwInvalidOperation ** ouch, GError **error);

	//gboolean tmp = snw_shard_service_if_shard_map(client, &table, type, 0.0, message, &snwInvalid, &error);

	//printf ("TruongLX-Status: %d, from client\n", tmp);
	if (success) {
		printf("truonglx: %d \n", g_hash_table_size(table));
		//====================
		// g_hash_table_foreach( table, printKeyValue, NULL );

		// puts (&table);
		//g_free (table);
	} else {
		fprintf(stderr, "Client caught an exception: %s\n", error->message);
		g_clear_error(&error);
	}

	thrift_transport_close(transport, &error);
	success = success && (error == NULL);

	g_clear_error(&error);

	g_object_unref(client);

	g_object_unref(protocol);
	g_object_unref(transport);
	g_object_unref(socket);

	return (success ? g_hash_table_size(table) : 0);
}
VCL_INT vmod_get_token( VRT_CTX) {
	return get_server(ctx);
}
////////////////////////////////////////////////////
//Backen Dynamic
//==================================================

#define IPBUFSIZ (VTCP_ADDRBUFSIZE + VTCP_PORTBUFSIZE + 2)

struct bentry {
	unsigned magic;
#define BENTRY_MAGIC 0x51ced5b5
	struct director *be;
VTAILQ_ENTRY(bentry) bentry;
};

struct belist {
unsigned magic;
#define BELIST_MAGIC 0x66d0afdb
VTAILQ_HEAD(behead, bentry)
*behead;
pthread_rwlock_t lock;
};

static void free_belist(void *priv) {
struct belist *belist;
struct bentry *bentry;

if (priv == NULL)
	return;
CAST_OBJ(belist, priv, BELIST_MAGIC);
AZ(pthread_rwlock_destroy(&belist->lock));
AN(belist->behead);
bentry = VTAILQ_FIRST(belist->behead);
while (bentry != NULL) {
	struct bentry *next;

	CHECK_OBJ(bentry, BENTRY_MAGIC);
	next = VTAILQ_NEXT(bentry, bentry);
	FREE_OBJ(bentry);
	bentry = next;
}
FREE_OBJ(belist);
}

static void errmsg( VRT_CTX, const char *fmt, ...) {
va_list args;

va_start(args, fmt);
if (ctx->method == VCL_MET_INIT) {
	AN(ctx->msg);
	VSB_vprintf(ctx->msg, fmt, args);
	VRT_handling(ctx, VCL_RET_FAIL);
} else {
	AN(ctx->vsl);
	VSLbv(ctx->vsl, SLT_VCL_Error, fmt, args);
}
va_end(args);
}

static struct suckaddr *
get_suckaddr(VCL_STRING host, VCL_STRING port, int family) {
struct addrinfo hints, *res = NULL;
struct suckaddr *sa = NULL;

memset(&hints, 0, sizeof(hints));
hints.ai_socktype = SOCK_STREAM;
hints.ai_family = family;
if (getaddrinfo(host, port, &hints, &res) != 0)
	return NULL;
if (res->ai_next != NULL)
	return NULL;
sa = VSA_Malloc(res->ai_addr, res->ai_addrlen);
AN(sa);
assert(VSA_Sane(sa));
assert(VSA_Get_Proto(sa) == family);
freeaddrinfo(res);
return sa;
}

static void get_addrname(char *addr, struct suckaddr *sa) {
char a[VTCP_ADDRBUFSIZE], p[VTCP_PORTBUFSIZE];

VTCP_name(sa, a, sizeof(a), p, sizeof(p));
snprintf(addr, IPBUFSIZ, "%s:%s", a, p);
}

VCL_BOOL vmod_create( VRT_CTX, struct vmod_priv *priv, VCL_STRING vcl_name,
	VCL_STRING host, VCL_STRING port, VCL_PROBE probe, VCL_STRING host_header,
	VCL_DURATION connect_timeout, VCL_DURATION first_byte_timeout,
	VCL_DURATION between_bytes_timeout, VCL_INT max_connections,
	VCL_INT proxy_header) {
struct belist *belist;
struct bentry *bentry;
struct director *dir;
struct vrt_backend be = { .magic = VRT_BACKEND_MAGIC };
struct suckaddr *sa4 = NULL, *sa6 = NULL;
char ipv4_addr[IPBUFSIZ] = "", ipv6_addr[IPBUFSIZ] = "";
const char *hosthdr = host_header;

CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
AN(priv);
AN(vcl_name);
AN(host);
AN(port);
AN(hosthdr);

if (vcl_name[0] == '\0') {
	errmsg(ctx, "vmod backend_dyn error: name must be non-empty");
	return 0;
}
if (host[0] == '\0') {
	errmsg(ctx, "vmod backend_dyn error: host must be non-empty");
	return 0;
}
if (proxy_header < 0 || proxy_header > 2) {
	errmsg(ctx, "vmod backend_dyn error: proxy_header must be 0, 1"
			"or 2");
	return 0;
}
if (hosthdr[0] == '\0')
	hosthdr = host;

/* XXX: check that name does not already exist in ctx->vcl */

if (priv->priv == NULL) {
	ALLOC_OBJ(belist, BELIST_MAGIC);
	AN(belist);
	AZ(pthread_rwlock_init(&belist->lock, NULL));
	belist->behead = malloc(sizeof(belist->behead));
	AN(belist->behead);
	VTAILQ_INIT(belist->behead);
	priv->priv = belist;
	priv->free = free_belist;
} else {
	int redefined = 0;
	CAST_OBJ(belist, priv->priv, BELIST_MAGIC);
	AN(belist->behead);
	AZ(pthread_rwlock_rdlock(&belist->lock));
	VTAILQ_FOREACH(bentry, belist->behead, bentry)
	{
		CHECK_OBJ_NOTNULL(bentry, BENTRY_MAGIC);
		CHECK_OBJ_NOTNULL(bentry->be, DIRECTOR_MAGIC);
		if (strcmp(bentry->be->vcl_name, vcl_name) == 0) {
			redefined = 1;
			break;
		}
	}
	AZ(pthread_rwlock_unlock(&belist->lock));
	if (redefined) {
		errmsg(ctx, "Backend %s redefined", vcl_name);
		return 0;
	}
}

sa4 = get_suckaddr(host, port, AF_INET);
sa6 = get_suckaddr(host, port, AF_INET6);
if (sa4 == NULL && sa6 == NULL) {
	errmsg(ctx, "vmod backend_dyn error: "
			"Cannot resolve %s:%s as a unique IPv4 or IPv6 address", host,
			port);
	return 0;
}
if (sa4 != NULL)
	get_addrname(ipv4_addr, sa4);
if (sa6 != NULL)
	get_addrname(ipv6_addr, sa6);

be.ipv4_suckaddr = sa4;
be.ipv6_suckaddr = sa6;
be.probe = probe;
#define DA(x) if (x != NULL && x[0] != '\0') be.x = strdup(x);
#define DN(x) be.x = x;
VRT_BACKEND_HANDLE();
#undef DA
#undef DN

dir = VRT_new_backend(ctx, &be);
CHECK_OBJ_NOTNULL(dir, DIRECTOR_MAGIC);

ALLOC_OBJ(bentry, BENTRY_MAGIC);
AN(bentry);
bentry->be = dir;
AZ(pthread_rwlock_wrlock(&belist->lock));
VTAILQ_INSERT_HEAD(belist->behead, bentry, bentry);
AZ(pthread_rwlock_unlock(&belist->lock));
return 1;
}

VCL_BACKEND vmod_by_name( VRT_CTX, struct vmod_priv *priv, VCL_STRING name) {
struct belist *belist;
struct bentry *bentry;
const struct director *dir = NULL;

CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
AN(priv);
AN(name);

if (priv->priv == NULL)
	return NULL;
CAST_OBJ_NOTNULL(belist, priv->priv, BELIST_MAGIC);
AN(belist->behead);
AZ(pthread_rwlock_rdlock(&belist->lock));
VTAILQ_FOREACH(bentry, belist->behead, bentry)
{
	CHECK_OBJ_NOTNULL(bentry, BENTRY_MAGIC);
	CHECK_OBJ_NOTNULL(bentry->be, DIRECTOR_MAGIC);
	if (strcmp(name, bentry->be->vcl_name) == 0) {
		dir = bentry->be;
		break;
	}
}
AZ(pthread_rwlock_unlock(&belist->lock));
return dir;
}

VCL_BOOL vmod_delete( VRT_CTX, struct vmod_priv *priv, VCL_BACKEND be) {
struct belist *belist;
struct bentry *bentry;
struct director *dir = NULL;

CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
AN(priv);
if (priv->priv == NULL)
	return 0;
if (be == NULL)
	return 0;
CHECK_OBJ(be, DIRECTOR_MAGIC);

CAST_OBJ(belist, priv->priv, BELIST_MAGIC);
AN(belist->behead);
AZ(pthread_rwlock_wrlock(&belist->lock));
VTAILQ_FOREACH(bentry, belist->behead, bentry)
{
	CHECK_OBJ_NOTNULL(bentry, BENTRY_MAGIC);
	CHECK_OBJ_NOTNULL(bentry->be, DIRECTOR_MAGIC);
	if (bentry->be == be) {
		dir = bentry->be;
		VTAILQ_REMOVE(belist->behead, bentry, bentry);
		break;
	}
}
AZ(pthread_rwlock_unlock(&belist->lock));
if (dir == NULL)
	return 0;
VRT_delete_backend(ctx, &dir);
AZ(dir);
return 1;
}

VCL_STRING vmod_version( VRT_CTX __attribute__((unused))) {
return VERSION;
}

