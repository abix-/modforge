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

#include <acl/compression/compress.h>
#include <acl/compression/track_array.h>
#include <acl/compression/transform_error_metrics.h>
#include <acl/core/ansi_allocator.h>
#include <acl/core/compressed_tracks.h>
#include <acl/decompression/decompress.h>

#include <cstdint>
#include <cstring>

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
// sub-tracks of a non-additive clip. `step` 1 rounds the time down to a
// sample (UE's Step interpolation) instead of blending two samples, 2
// takes the nearest sample (to read the samples one by one).
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
    ctx.seek(time, step == 2   ? acl::sample_rounding_policy::nearest
                   : step != 0 ? acl::sample_rounding_policy::floor
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

// A new ACL buffer from raw bone transforms, for a non-additive clip,
// the way UE's ACL plugin compresses one (nfrechette/acl-ue4-plugin,
// ACLCompressionImpl / UAnimBoneCompressionCodec_ACLBase): every
// track's default sub-track value is its bone's reference pose (the
// decoder fills default sub-tracks with it), each track's parent is the
// track of its nearest tracked ancestor, the variable formats ACL's
// default settings use (the ones UE's default decompression settings
// read), the qvvf error metric, 0.01 cm precision on a 3 cm shell. No
// loop optimisation or keyframe stripping, so the sample count stays.
//
// raw: num_tracks * num_samples * 10 floats, track major (rotation x y
// z w, translation x y z, scale x y z). ref: num_tracks * 10 floats.
// parents: num_tracks track indices, -1 for none.
// Returns the buffer (free it with ueforge_acl_free) and its size in
// *out_size, or null with *out_size set to: 1 a bad argument, 2 the
// compression failed.
void* ueforge_acl_compress(const float* raw, const float* ref, const int32_t* parents,
                           uint32_t num_tracks, uint32_t num_samples, float sample_rate,
                           uint32_t* out_size) {
    *out_size = 1;
    if (raw == nullptr || ref == nullptr || parents == nullptr || num_tracks == 0 ||
        num_samples == 0 || !(sample_rate > 0.0F)) {
        return nullptr;
    }
    acl::ansi_allocator allocator;
    acl::track_array_qvvf list(allocator, num_tracks);
    for (uint32_t t = 0; t < num_tracks; ++t) {
        const float* r = ref + t * 10;
        acl::track_desc_transformf desc;
        desc.output_index = t;
        desc.parent_index = parents[t] < 0 ? acl::k_invalid_track_index
                                           : static_cast<uint32_t>(parents[t]);
        desc.precision = 0.01F;
        desc.shell_distance = 3.0F;
        desc.default_value = rtm::qvv_set(rtm::quat_set(r[0], r[1], r[2], r[3]),
                                          rtm::vector_set(r[4], r[5], r[6]),
                                          rtm::vector_set(r[7], r[8], r[9]));
        acl::track_qvvf track =
            acl::track_qvvf::make_reserve(desc, allocator, num_samples, sample_rate);
        for (uint32_t s = 0; s < num_samples; ++s) {
            const float* v = raw + (static_cast<size_t>(t) * num_samples + s) * 10;
            track[s] = rtm::qvv_set(rtm::quat_normalize(rtm::quat_set(v[0], v[1], v[2], v[3])),
                                    rtm::vector_set(v[4], v[5], v[6]),
                                    rtm::vector_set(v[7], v[8], v[9]));
        }
        list[t] = std::move(track);
    }
    acl::compression_settings settings = acl::get_default_compression_settings();
    settings.optimize_loops = false;
    settings.keyframe_stripping.strip_trivial = false;
    acl::qvvf_transform_error_metric metric;
    settings.error_metric = &metric;
    acl::compressed_tracks* out = nullptr;
    acl::output_stats stats;
    acl::error_result err = acl::compress_track_list(allocator, list, settings, out, stats);
    if (err.any() || out == nullptr) {
        *out_size = 2;
        return nullptr;
    }
    *out_size = out->get_size();
    return out;
}

// Frees a buffer from ueforge_acl_compress.
void ueforge_acl_free(void* buffer) {
    if (buffer == nullptr) {
        return;
    }
    acl::ansi_allocator allocator;
    const acl::compressed_tracks* t = static_cast<const acl::compressed_tracks*>(buffer);
    allocator.deallocate(buffer, t->get_size());
}

}  // extern "C"
