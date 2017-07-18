/*
 * NB:  This file is machine generated, DO NOT EDIT!
 *
 * Edit vmod.vcc and run make instead
 */

struct vmod_priv;

extern const struct vmod_data Vmod_snw_Data;

#ifdef VCL_MET_MAX
vmod_event_f event_function;
#endif
VCL_STRING vmod_info(VRT_CTX);
VCL_STRING vmod_hello(VRT_CTX, VCL_STRING);
VCL_BACKEND vmod_app(VRT_CTX);
VCL_INT vmod_get_token(VRT_CTX);
VCL_INT vmod_get_objectId(VRT_CTX);
VCL_BOOL vmod_create(VRT_CTX, struct vmod_priv *, VCL_STRING,
    VCL_STRING, VCL_STRING, VCL_PROBE, VCL_STRING, VCL_DURATION,
    VCL_DURATION, VCL_DURATION, VCL_INT, VCL_INT);
VCL_BACKEND vmod_by_name(VRT_CTX, struct vmod_priv *,
    VCL_STRING);
VCL_BOOL vmod_delete(VRT_CTX, struct vmod_priv *, VCL_BACKEND);
VCL_STRING vmod_version(VRT_CTX);
