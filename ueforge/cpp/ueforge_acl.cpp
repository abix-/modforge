// Reads UE animation bone data straight from its ACL compressed tracks,
// the same way UE's ACL plugin does (nfrechette/acl-ue4-plugin,
// ACLPlugin/Source/ACLPlugin/Private/ACLDecompressionImpl.h): ACL v2.1.0
// (cpp/acl, the version UE 5 stores: compressed tracks version 10), a
// decompression context seeked to a time, and a track writer that fills
// every default sub-track with the skeleton's reference pose when the
// clip is not additive (default scale != 0), as the plugin's
// FUEOutputWriter<true> does. Asked 2026-11-22: "the right way is the
// framework upgrade to read the animation data directly".
//
// Rust side: src/anim_data.rs.

#include <acl/core/compressed_tracks.h>
#include <acl/decompression/decompress.h>

#include <cstdint>

namespace {

// Every format allowed (the plugin's UEDebugDecompressionSettings /
// UECustomDecompressionSettings): a clip compressed with any setting
// decodes.
struct Settings : public acl::debug_transform_decompression_settings {
    static constexpr acl::compressed_tracks_version16 version_supported() {
        return acl::compressed_tracks_version16::v02_01_00;
    }
};

// 10 floats per track: rotation x y z w, translation x y z, scale x y z.
// ref holds the same 10 floats per track (the reference pose of the
// track's bone); only rotation and translation are read from it, as the
// plugin's writer does (scale uses ACL's legacy default).
template <bool UseRef>
struct Writer final : public acl::track_writer {
    const float* ref;
    float* out;

    static constexpr acl::default_sub_track_mode get_default_rotation_mode() {
        return UseRef ? acl::default_sub_track_mode::variable
                      : acl::default_sub_track_mode::constant;
    }
    static constexpr acl::default_sub_track_mode get_default_translation_mode() {
        return UseRef ? acl::default_sub_track_mode::variable
                      : acl::default_sub_track_mode::constant;
    }
    static constexpr acl::default_sub_track_mode get_default_scale_mode() {
        return acl::default_sub_track_mode::legacy;
    }

    rtm::quatf RTM_SIMD_CALL get_variable_default_rotation(uint32_t t) const {
        const float* r = ref + t * 10;
        return rtm::quat_set(r[0], r[1], r[2], r[3]);
    }
    rtm::vector4f RTM_SIMD_CALL get_variable_default_translation(uint32_t t) const {
        const float* r = ref + t * 10 + 4;
        return rtm::vector_set(r[0], r[1], r[2]);
    }

    void RTM_SIMD_CALL write_rotation(uint32_t t, rtm::quatf_arg0 q) {
        float* o = out + t * 10;
        o[0] = rtm::quat_get_x(q);
        o[1] = rtm::quat_get_y(q);
        o[2] = rtm::quat_get_z(q);
        o[3] = rtm::quat_get_w(q);
    }
    void RTM_SIMD_CALL write_translation(uint32_t t, rtm::vector4f_arg0 v) {
        float* o = out + t * 10 + 4;
        o[0] = rtm::vector_get_x(v);
        o[1] = rtm::vector_get_y(v);
        o[2] = rtm::vector_get_z(v);
    }
    void RTM_SIMD_CALL write_scale(uint32_t t, rtm::vector4f_arg0 v) {
        float* o = out + t * 10 + 7;
        o[0] = rtm::vector_get_x(v);
        o[1] = rtm::vector_get_y(v);
        o[2] = rtm::vector_get_z(v);
    }
};

const acl::compressed_tracks* tracks_of(const void* buffer) {
    acl::error_result err;
    const acl::compressed_tracks* t = acl::make_compressed_tracks(buffer, &err);
    if (t == nullptr || err.any()) {
        return nullptr;
    }
    return t;
}

}  // namespace

extern "C" {

// The header of an ACL buffer: track count, samples per track, sample
// rate, duration in seconds, track type (12 = qvvf, bone transforms),
// default scale (0 = additive). Returns 0, or -1 when it is not a valid
// ACL v2.1 buffer.
int32_t ueforge_acl_info(const void* buffer, uint32_t* num_tracks, uint32_t* num_samples,
                         float* sample_rate, float* duration, uint32_t* track_type,
                         int32_t* default_scale) {
    const acl::compressed_tracks* t = tracks_of(buffer);
    if (t == nullptr) {
        return -1;
    }
    *num_tracks = t->get_num_tracks();
    *num_samples = t->get_num_samples_per_track();
    *sample_rate = t->get_sample_rate();
    *duration = t->get_duration();
    *track_type = static_cast<uint32_t>(t->get_track_type());
    *default_scale = t->get_default_scale();
    return 0;
}

// Every track's local transform at `time` seconds into the clip, 10
// floats per track into `out` (num_tracks * 10). `ref` holds the
// reference pose per track, same layout, used for the default
// sub-tracks of a non-additive clip. `step` rounds the time down to a
// sample (UE's Step interpolation) instead of blending two samples.
// Returns 0; -1 not a valid buffer, -2 not bone transforms, -3 the track
// count differs, -4 the context did not initialize.
int32_t ueforge_acl_sample(const void* buffer, float time, int32_t step, const float* ref,
                           float* out, uint32_t num_tracks) {
    const acl::compressed_tracks* t = tracks_of(buffer);
    if (t == nullptr) {
        return -1;
    }
    if (t->get_track_type() != acl::track_type8::qvvf) {
        return -2;
    }
    if (t->get_num_tracks() != num_tracks) {
        return -3;
    }
    acl::decompression_context<Settings> ctx;
    if (!ctx.initialize(*t)) {
        return -4;
    }
    ctx.seek(time, step != 0 ? acl::sample_rounding_policy::floor
                             : acl::sample_rounding_policy::none);
    if (t->get_default_scale() != 0) {
        Writer<true> w;
        w.ref = ref;
        w.out = out;
        ctx.decompress_tracks(w);
    } else {
        Writer<false> w;
        w.ref = ref;
        w.out = out;
        ctx.decompress_tracks(w);
    }
    return 0;
}

}  // extern "C"
