/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef SNW_SHARD_SERVICE_TYPES_H
#define SNW_SHARD_SERVICE_TYPES_H

/* base includes */
#include <glib-object.h>
#include <thrift/c_glib/thrift_struct.h>
#include <thrift/c_glib/protocol/thrift_protocol.h>

/* custom thrift includes */

/* begin types */

struct _snwInvalidOperation
{ 
  ThriftStruct parent; 

  /* public */
  gint32 whatOp;
  gboolean __isset_whatOp;
  gchar * why;
  gboolean __isset_why;
};
typedef struct _snwInvalidOperation snwInvalidOperation;

struct _snwInvalidOperationClass
{
  ThriftStructClass parent;
};
typedef struct _snwInvalidOperationClass snwInvalidOperationClass;

GType snw_invalid_operation_get_type (void);
#define SNW_TYPE_INVALID_OPERATION (snw_invalid_operation_get_type())
#define SNW_INVALID_OPERATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SNW_TYPE_INVALID_OPERATION, snwInvalidOperation))
#define SNW_INVALID_OPERATION_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), SNW__TYPE_INVALID_OPERATION, snwInvalidOperationClass))
#define SNW_IS_INVALID_OPERATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SNW_TYPE_INVALID_OPERATION))
#define SNW_IS_INVALID_OPERATION_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), SNW_TYPE_INVALID_OPERATION))
#define SNW_INVALID_OPERATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SNW_TYPE_INVALID_OPERATION, snwInvalidOperationClass))

/* exception */
typedef enum
{
  SNW_INVALID_OPERATION_ERROR_CODE
} snwInvalidOperationError;

GQuark snw_invalid_operation_error_quark (void);
#define SNW_INVALID_OPERATION_ERROR (snw_invalid_operation_error_quark())


/* constants */

/* struct ShardServiceShardMapArgs */
struct _snwShardServiceShardMapArgs
{ 
  ThriftStruct parent; 

  /* public */
  gchar * type;
  gboolean __isset_type;
  gdouble version;
  gboolean __isset_version;
  gchar * token;
  gboolean __isset_token;
};
typedef struct _snwShardServiceShardMapArgs snwShardServiceShardMapArgs;

struct _snwShardServiceShardMapArgsClass
{
  ThriftStructClass parent;
};
typedef struct _snwShardServiceShardMapArgsClass snwShardServiceShardMapArgsClass;

GType snw_shard_service_shard_map_args_get_type (void);
#define SNW_TYPE_SHARD_SERVICE_SHARD_MAP_ARGS (snw_shard_service_shard_map_args_get_type())
#define SNW_SHARD_SERVICE_SHARD_MAP_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SNW_TYPE_SHARD_SERVICE_SHARD_MAP_ARGS, snwShardServiceShardMapArgs))
#define SNW_SHARD_SERVICE_SHARD_MAP_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), SNW__TYPE_SHARD_SERVICE_SHARD_MAP_ARGS, snwShardServiceShardMapArgsClass))
#define SNW_IS_SHARD_SERVICE_SHARD_MAP_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SNW_TYPE_SHARD_SERVICE_SHARD_MAP_ARGS))
#define SNW_IS_SHARD_SERVICE_SHARD_MAP_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), SNW_TYPE_SHARD_SERVICE_SHARD_MAP_ARGS))
#define SNW_SHARD_SERVICE_SHARD_MAP_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SNW_TYPE_SHARD_SERVICE_SHARD_MAP_ARGS, snwShardServiceShardMapArgsClass))

/* struct ShardServiceShardMapResult */
struct _snwShardServiceShardMapResult
{ 
  ThriftStruct parent; 

  /* public */
  GHashTable * success;
  gboolean __isset_success;
  snwInvalidOperation * ouch;
  gboolean __isset_ouch;
};
typedef struct _snwShardServiceShardMapResult snwShardServiceShardMapResult;

struct _snwShardServiceShardMapResultClass
{
  ThriftStructClass parent;
};
typedef struct _snwShardServiceShardMapResultClass snwShardServiceShardMapResultClass;

GType snw_shard_service_shard_map_result_get_type (void);
#define SNW_TYPE_SHARD_SERVICE_SHARD_MAP_RESULT (snw_shard_service_shard_map_result_get_type())
#define SNW_SHARD_SERVICE_SHARD_MAP_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SNW_TYPE_SHARD_SERVICE_SHARD_MAP_RESULT, snwShardServiceShardMapResult))
#define SNW_SHARD_SERVICE_SHARD_MAP_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), SNW__TYPE_SHARD_SERVICE_SHARD_MAP_RESULT, snwShardServiceShardMapResultClass))
#define SNW_IS_SHARD_SERVICE_SHARD_MAP_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SNW_TYPE_SHARD_SERVICE_SHARD_MAP_RESULT))
#define SNW_IS_SHARD_SERVICE_SHARD_MAP_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), SNW_TYPE_SHARD_SERVICE_SHARD_MAP_RESULT))
#define SNW_SHARD_SERVICE_SHARD_MAP_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SNW_TYPE_SHARD_SERVICE_SHARD_MAP_RESULT, snwShardServiceShardMapResultClass))

/* struct ShardServiceGetObjectIdArgs */
struct _snwShardServiceGetObjectIdArgs
{ 
  ThriftStruct parent; 

  /* public */
  gchar * message;
  gboolean __isset_message;
  gdouble version;
  gboolean __isset_version;
  gchar * token;
  gboolean __isset_token;
};
typedef struct _snwShardServiceGetObjectIdArgs snwShardServiceGetObjectIdArgs;

struct _snwShardServiceGetObjectIdArgsClass
{
  ThriftStructClass parent;
};
typedef struct _snwShardServiceGetObjectIdArgsClass snwShardServiceGetObjectIdArgsClass;

GType snw_shard_service_get_object_id_args_get_type (void);
#define SNW_TYPE_SHARD_SERVICE_GET_OBJECT_ID_ARGS (snw_shard_service_get_object_id_args_get_type())
#define SNW_SHARD_SERVICE_GET_OBJECT_ID_ARGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SNW_TYPE_SHARD_SERVICE_GET_OBJECT_ID_ARGS, snwShardServiceGetObjectIdArgs))
#define SNW_SHARD_SERVICE_GET_OBJECT_ID_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), SNW__TYPE_SHARD_SERVICE_GET_OBJECT_ID_ARGS, snwShardServiceGetObjectIdArgsClass))
#define SNW_IS_SHARD_SERVICE_GET_OBJECT_ID_ARGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SNW_TYPE_SHARD_SERVICE_GET_OBJECT_ID_ARGS))
#define SNW_IS_SHARD_SERVICE_GET_OBJECT_ID_ARGS_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), SNW_TYPE_SHARD_SERVICE_GET_OBJECT_ID_ARGS))
#define SNW_SHARD_SERVICE_GET_OBJECT_ID_ARGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SNW_TYPE_SHARD_SERVICE_GET_OBJECT_ID_ARGS, snwShardServiceGetObjectIdArgsClass))

/* struct ShardServiceGetObjectIdResult */
struct _snwShardServiceGetObjectIdResult
{ 
  ThriftStruct parent; 

  /* public */
  gchar * success;
  gboolean __isset_success;
  snwInvalidOperation * ouch;
  gboolean __isset_ouch;
};
typedef struct _snwShardServiceGetObjectIdResult snwShardServiceGetObjectIdResult;

struct _snwShardServiceGetObjectIdResultClass
{
  ThriftStructClass parent;
};
typedef struct _snwShardServiceGetObjectIdResultClass snwShardServiceGetObjectIdResultClass;

GType snw_shard_service_get_object_id_result_get_type (void);
#define SNW_TYPE_SHARD_SERVICE_GET_OBJECT_ID_RESULT (snw_shard_service_get_object_id_result_get_type())
#define SNW_SHARD_SERVICE_GET_OBJECT_ID_RESULT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SNW_TYPE_SHARD_SERVICE_GET_OBJECT_ID_RESULT, snwShardServiceGetObjectIdResult))
#define SNW_SHARD_SERVICE_GET_OBJECT_ID_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), SNW__TYPE_SHARD_SERVICE_GET_OBJECT_ID_RESULT, snwShardServiceGetObjectIdResultClass))
#define SNW_IS_SHARD_SERVICE_GET_OBJECT_ID_RESULT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SNW_TYPE_SHARD_SERVICE_GET_OBJECT_ID_RESULT))
#define SNW_IS_SHARD_SERVICE_GET_OBJECT_ID_RESULT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), SNW_TYPE_SHARD_SERVICE_GET_OBJECT_ID_RESULT))
#define SNW_SHARD_SERVICE_GET_OBJECT_ID_RESULT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), SNW_TYPE_SHARD_SERVICE_GET_OBJECT_ID_RESULT, snwShardServiceGetObjectIdResultClass))

#endif /* SNW_SHARD_SERVICE_TYPES_H */