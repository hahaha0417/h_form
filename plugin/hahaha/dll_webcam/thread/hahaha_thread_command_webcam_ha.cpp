//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
#include <functional>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <processing_unit\base\hahaha_processing_unit_base.h>
#include <processing_unit\base\hahaha_processing_unit_region.h>
#include <processing_unit\base\hahaha_processing_unit_strategy.h>
//---------------------------------------------------------------------------
#include <structure\hahaha_structure_main.h>
#include <structure\hahaha_structure_sub.h>
#include <pointer\hahaha_pointer_main.h>
#include <pointer\hahaha_pointer_sub.h>
//---------------------------------------------------------------------------
#include <define\hahaha_define_ho.h>
//---------------------------------------------------------------------------
#include <thread\base\hahaha_thread_command_command.h>

#include <lock\hahaha_mutex.h>
#include <capture\webcam\direct_show\hahaha_capture_webcam_direct_show_item.h>
#include <capture\webcam\hahaha_capture_webcam_direct_show_origin_ha.h>
#include <image_view\hahaha_image_view_base.h>
#include <image_view\hahaha_form_image_view.h>
#include <mutex>
#include <form\hahaha_main_form.h>
#include <thread\hahaha_thread_command_ui.h>
#include <ui\hahaha_ui_message.h>
#include <image_process\color\hahaha_image_process_color.h>
#include <image_process_composite\color\hahaha_image_process_composite_color.h>
#include <image_process\wrap_affine\hahaha_image_process_wrap_affine_rotate.h>
//---------------------------------------------------------------------------
#include "hahaha_thread_command_webcam_ha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahaha
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha::hahaha_thread_command_webcam_ha()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha::~hahaha_thread_command_webcam_ha()
{

}
//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha::hahaha_thread_command_webcam_ha(const hahaha_thread_command_webcam_ha& htcwh)
{
    Reset();
	Copy(htcwh);
}
//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha::hahaha_thread_command_webcam_ha(hahaha_thread_command_webcam_ha&& htcwh) noexcept
{
    Move(std::move(htcwh));
}
//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha& hahaha_thread_command_webcam_ha::operator=(const hahaha_thread_command_webcam_ha& htcwh)
{
	Copy(htcwh);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_command_webcam_ha& hahaha_thread_command_webcam_ha::operator=(hahaha_thread_command_webcam_ha&& htcwh) noexcept
{
	if (this != &htcwh)
    {
        Move(std::move(htcwh));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_command_webcam_ha::Copy(const hahaha_thread_command_webcam_ha& htcwh)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_command_webcam_ha::Move(hahaha_thread_command_webcam_ha&& htcwh) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_thread_command_webcam_ha::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int hahaha_thread_command_webcam_ha::Handle(std::unique_ptr<hahahalib::hahaha_thread_command_command>& command)
{
	if(command->Command_ == (int)hahaha_thread_command_command_command::ADD_GRAB)
	{
        hahaha::hahaha_thread_command_parameter_webcam* p_ = (hahaha::hahaha_thread_command_parameter_webcam*)command->Parameter_;
		On_Grab(p_->Webcam_);
        delete p_;
	}

	return 0;
}
//---------------------------------------------------------------------------

void YUY2_to_ARGB_SSE2(
    const unsigned char* src,
    unsigned char* dst,
    int width,
    int height
)
{
    const int stride = width * 2;      // YUY2 = 2 bytes per pixel
    const int out_stride = width * 4;  // ARGB = 4 bytes per pixel

    for (int y = 0; y < height; y++)
    {
        const unsigned char* s = src + y * stride;
        unsigned char* d = dst + y * out_stride;

        for (int x = 0; x < width; x += 8)
        {
            // Load 16 bytes = 8 pixels (YUY2)
            __m128i yuy2 = _mm_loadu_si128((__m128i*)(s + x * 2));

            // Separate Y and UV
            __m128i y_mask = _mm_set1_epi16(0x00FF);
            __m128i y_vals = _mm_and_si128(yuy2, y_mask);

            __m128i uv_vals = _mm_srli_epi16(yuy2, 8);

            // Extract U and V
            __m128i u_vals = _mm_and_si128(uv_vals, _mm_set1_epi16(0x00FF));
            __m128i v_vals = _mm_srli_epi16(uv_vals, 8);

            // Duplicate U and V for each pixel
            u_vals = _mm_unpacklo_epi8(_mm_packus_epi16(u_vals, u_vals), _mm_packus_epi16(u_vals, u_vals));
            v_vals = _mm_unpacklo_epi8(_mm_packus_epi16(v_vals, v_vals), _mm_packus_epi16(v_vals, v_vals));

            // Convert to signed
            __m128i y16 = _mm_sub_epi16(_mm_unpacklo_epi8(_mm_packus_epi16(y_vals, y_vals), _mm_setzero_si128()), _mm_set1_epi16(16));
            __m128i u16 = _mm_sub_epi16(_mm_unpacklo_epi8(u_vals, _mm_setzero_si128()), _mm_set1_epi16(128));
            __m128i v16 = _mm_sub_epi16(_mm_unpacklo_epi8(v_vals, _mm_setzero_si128()), _mm_set1_epi16(128));

            // YUV → RGB
            __m128i c = _mm_mullo_epi16(y16, _mm_set1_epi16(298));

            __m128i r = _mm_srai_epi16(_mm_add_epi16(c, _mm_mullo_epi16(v16, _mm_set1_epi16(409))), 8);
            __m128i g = _mm_srai_epi16(_mm_sub_epi16(_mm_sub_epi16(c, _mm_mullo_epi16(u16, _mm_set1_epi16(100))), _mm_mullo_epi16(v16, _mm_set1_epi16(208))), 8);
            __m128i b = _mm_srai_epi16(_mm_add_epi16(c, _mm_mullo_epi16(u16, _mm_set1_epi16(516))), 8);

            // Clamp to 0–255
            __m128i zero = _mm_setzero_si128();
            __m128i maxv = _mm_set1_epi16(255);

            r = _mm_min_epi16(_mm_max_epi16(r, zero), maxv);
            g = _mm_min_epi16(_mm_max_epi16(g, zero), maxv);
            b = _mm_min_epi16(_mm_max_epi16(b, zero), maxv);

            // Pack to 8-bit
            __m128i r8 = _mm_packus_epi16(r, r);
            __m128i g8 = _mm_packus_epi16(g, g);
            __m128i b8 = _mm_packus_epi16(b, b);

            // Interleave to ARGB
            __m128i a8 = _mm_set1_epi8((char)255);

            __m128i rg = _mm_unpacklo_epi8(r8, g8);
            __m128i ba = _mm_unpacklo_epi8(b8, a8);

            __m128i argb0 = _mm_unpacklo_epi16(rg, ba);
            __m128i argb1 = _mm_unpackhi_epi16(rg, ba);

            // Store 8 pixels (32 bytes)
            _mm_storeu_si128((__m128i*)(d + x * 4), argb0);
            _mm_storeu_si128((__m128i*)(d + x * 4 + 16), argb1);
        }
    }
}

void YUY2_To_ARGB_Direct(
    const unsigned char* src,
    int src_stride,
    unsigned char* dst,
    int dst_stride,
    int width,
    int height
)
{
    for (int y = 0; y < height; y++)
    {
        const unsigned char* s = src + y * src_stride;
        unsigned char* d = dst + y * dst_stride;

        for (int x = 0; x < width; x += 2)
        {
            // YUY2 = Y0 U0 Y1 V0
            unsigned char Y0 = s[0];
            unsigned char U  = s[1];
            unsigned char Y1 = s[2];
            unsigned char V  = s[3];

            int C0 = Y0 - 16;
            int C1 = Y1 - 16;
            int D  = U  - 128;
            int E  = V  - 128;

            // Pixel 0
            int R0 = (298 * C0 + 409 * E + 128) >> 8;
            int G0 = (298 * C0 - 100 * D - 208 * E + 128) >> 8;
            int B0 = (298 * C0 + 516 * D + 128) >> 8;

            // Pixel 1
            int R1 = (298 * C1 + 409 * E + 128) >> 8;
            int G1 = (298 * C1 - 100 * D - 208 * E + 128) >> 8;
            int B1 = (298 * C1 + 516 * D + 128) >> 8;

            // Clamp
            R0 = R0 < 0 ? 0 : (R0 > 255 ? 255 : R0);
            G0 = G0 < 0 ? 0 : (G0 > 255 ? 255 : G0);
            B0 = B0 < 0 ? 0 : (B0 > 255 ? 255 : B0);

            R1 = R1 < 0 ? 0 : (R1 > 255 ? 255 : R1);
            G1 = G1 < 0 ? 0 : (G1 > 255 ? 255 : G1);
            B1 = B1 < 0 ? 0 : (B1 > 255 ? 255 : B1);

            // Write ARGB
            d[0] = B0;
            d[1] = G0;
            d[2] = R0;
            d[3] = 255;

            d[4] = B1;
            d[5] = G1;
            d[6] = R1;
            d[7] = 255;

            s += 4;
            d += 8;
        }
    }
}


//#include <immintrin.h>
//#include <cstdint>
//
//#pragma clang attribute push (__attribute__((target("avx2"))), apply_to=function)
//
//class YUY2Converter
//{
//public:
//    static void Convert(
//        const uint8_t* src,
//        int src_stride,
//        uint8_t* dst,
//        int dst_stride,
//        int width,
//        int height
//    ) {
//        if (hasAVX2())
//            Convert_AVX2(src, src_stride, dst, dst_stride, width, height);
//        else
//            Convert_Scalar(src, src_stride, dst, dst_stride, width, height);
//    }
//
//    static bool hasAVX2()
//    {
//#if defined(__GNUC__) || defined(__clang__)
//        return __builtin_cpu_supports("avx2");
//#elif defined(_MSC_VER)
//        int cpuInfo[4];
//        __cpuid(cpuInfo, 7);
//        return (cpuInfo[1] & (1 << 5)) != 0;
//#else
//        return false;
//#endif
//    }
//
//    // ---------------- Scalar（你的原始正確版） ----------------
//    static void Convert_Scalar(
//        const uint8_t* src,
//        int src_stride,
//        uint8_t* dst,
//        int dst_stride,
//        int width,
//        int height
//    ) {
//        for (int y = 0; y < height; y++)
//        {
//            const uint8_t* s = src + y * src_stride;
//            uint8_t* d = dst + y * dst_stride;
//
//            for (int x = 0; x < width; x += 2)
//            {
//                uint8_t Y0 = s[0];
//                uint8_t U  = s[1];
//                uint8_t Y1 = s[2];
//                uint8_t V  = s[3];
//
//                int C0 = Y0 - 16;
//                int C1 = Y1 - 16;
//                int D  = U  - 128;
//                int E  = V  - 128;
//
//                int R0 = (298 * C0 + 409 * E + 128) >> 8;
//                int G0 = (298 * C0 - 100 * D - 208 * E + 128) >> 8;
//                int B0 = (298 * C0 + 516 * D + 128) >> 8;
//
//                int R1 = (298 * C1 + 409 * E + 128) >> 8;
//                int G1 = (298 * C1 - 100 * D - 208 * E + 128) >> 8;
//                int B1 = (298 * C1 + 516 * D + 128) >> 8;
//
//                R0 = R0 < 0 ? 0 : (R0 > 255 ? 255 : R0);
//                G0 = G0 < 0 ? 0 : (G0 > 255 ? 255 : G0);
//                B0 = B0 < 0 ? 0 : (B0 > 255 ? 255 : B0);
//
//                R1 = R1 < 0 ? 0 : (R1 > 255 ? 255 : R1);
//                G1 = G1 < 0 ? 0 : (G1 > 255 ? 255 : G1);
//                B1 = B1 < 0 ? 0 : (B1 > 255 ? 255 : B1);
//
//                d[0] = B0; d[1] = G0; d[2] = R0; d[3] = 255;
//                d[4] = B1; d[5] = G1; d[6] = R1; d[7] = 255;
//
//                s += 4;
//                d += 8;
//            }
//        }
//    }
//
//    // ---------------- AVX2 精準版（顏色對齊 Scalar） ----------------
//    static void Convert_AVX2(
//        const uint8_t* src,
//        int src_stride,
//        uint8_t* dst,
//        int dst_stride,
//        int width,
//        int height
//    ) {
//        const int step = 16; // 一次處理 16 pixels
//
//        const __m256i y_shuffle = _mm256_set_epi8(
//            14,12,10,8,6,4,2,0,
//            14,12,10,8,6,4,2,0,
//            14,12,10,8,6,4,2,0,
//            14,12,10,8,6,4,2,0
//        );
//
//        const __m256i u_shuffle = _mm256_set_epi8(
//            13,13, 9, 9, 5, 5, 1, 1,
//            13,13, 9, 9, 5, 5, 1, 1,
//            13,13, 9, 9, 5, 5, 1, 1,
//            13,13, 9, 9, 5, 5, 1, 1
//        );
//
//        const __m256i v_shuffle = _mm256_set_epi8(
//            15,15,11,11, 7, 7, 3, 3,
//            15,15,11,11, 7, 7, 3, 3,
//            15,15,11,11, 7, 7, 3, 3,
//            15,15,11,11, 7, 7, 3, 3
//        );
//
//        const __m256i c16  = _mm256_set1_epi16(16);
//        const __m256i c128 = _mm256_set1_epi16(128);
//
//        for (int y = 0; y < height; y++)
//        {
//            const uint8_t* s = src + y * src_stride;
//            uint8_t* d = dst + y * dst_stride;
//
//            int x = 0;
//
//            for (; x <= width - step; x += step)
//            {
//                const uint8_t* sp = s + x * 2; // YUY2: 2 bytes per pixel
//                __m256i yuy2 = _mm256_loadu_si256((const __m256i*)sp);
//
//                __m256i y_bytes = _mm256_shuffle_epi8(yuy2, y_shuffle);
//                __m256i u_bytes = _mm256_shuffle_epi8(yuy2, u_shuffle);
//                __m256i v_bytes = _mm256_shuffle_epi8(yuy2, v_shuffle);
//
//                __m128i y_lo_8 = _mm256_castsi256_si128(y_bytes);
//                __m128i y_hi_8 = _mm256_extracti128_si256(y_bytes, 1);
//
//                __m128i u_lo_8 = _mm256_castsi256_si128(u_bytes);
//                __m128i u_hi_8 = _mm256_extracti128_si256(u_bytes, 1);
//
//                __m128i v_lo_8 = _mm256_castsi256_si128(v_bytes);
//                __m128i v_hi_8 = _mm256_extracti128_si256(v_bytes, 1);
//
//                __m256i y_lo = _mm256_sub_epi16(_mm256_cvtepu8_epi16(y_lo_8), c16);
//                __m256i y_hi = _mm256_sub_epi16(_mm256_cvtepu8_epi16(y_hi_8), c16);
//
//                __m256i u_lo = _mm256_sub_epi16(_mm256_cvtepu8_epi16(u_lo_8), c128);
//                __m256i u_hi = _mm256_sub_epi16(_mm256_cvtepu8_epi16(u_hi_8), c128);
//
//                __m256i v_lo = _mm256_sub_epi16(_mm256_cvtepu8_epi16(v_lo_8), c128);
//                __m256i v_hi = _mm256_sub_epi16(_mm256_cvtepu8_epi16(v_hi_8), c128);
//
//                process8(d + x * 4 + 0,  y_lo, u_lo, v_lo);
//                process8(d + x * 4 + 32, y_hi, u_hi, v_hi);
//            }
//
//            if (x < width)
//            {
//                Convert_Scalar(
//                    s + x * 2,
//                    src_stride,
//                    d + x * 4,
//                    dst_stride,
//                    width - x,
//                    1
//                );
//            }
//        }
//    }
//
//private:
//    // 8 pixels，32-bit 精準版，BGRA
//    static inline void process8(
//        uint8_t* dst,
//        __m256i y16,
//        __m256i u16,
//        __m256i v16
//    ) {
//        __m128i y_lo16 = _mm256_castsi256_si128(y16);
//        __m128i u_lo16 = _mm256_castsi256_si128(u16);
//        __m128i v_lo16 = _mm256_castsi256_si128(v16);
//
//        __m256i y32 = _mm256_cvtepi16_epi32(y_lo16);
//        __m256i u32 = _mm256_cvtepi16_epi32(u_lo16);
//        __m256i v32 = _mm256_cvtepi16_epi32(v_lo16);
//
//        const __m256i k298 = _mm256_set1_epi32(298);
//        const __m256i k409 = _mm256_set1_epi32(409);
//        const __m256i k100 = _mm256_set1_epi32(100);
//        const __m256i k208 = _mm256_set1_epi32(208);
//        const __m256i k516 = _mm256_set1_epi32(516);
//        const __m256i bias = _mm256_set1_epi32(128);
//
//        __m256i c = _mm256_mullo_epi32(y32, k298);
//
//        __m256i r32 = _mm256_srai_epi32(
//            _mm256_add_epi32(
//                _mm256_add_epi32(c, _mm256_mullo_epi32(v32, k409)),
//                bias
//            ), 8);
//
//        __m256i g32 = _mm256_srai_epi32(
//            _mm256_add_epi32(
//                _mm256_sub_epi32(
//                    _mm256_sub_epi32(c, _mm256_mullo_epi32(u32, k100)),
//                    _mm256_mullo_epi32(v32, k208)
//                ),
//                bias
//            ), 8);
//
//        __m256i b32 = _mm256_srai_epi32(
//            _mm256_add_epi32(
//                _mm256_add_epi32(c, _mm256_mullo_epi32(u32, k516)),
//                bias
//            ), 8);
//
//        const __m256i zero32 = _mm256_set1_epi32(0);
//        const __m256i max32  = _mm256_set1_epi32(255);
//
//        r32 = _mm256_min_epi32(_mm256_max_epi32(r32, zero32), max32);
//        g32 = _mm256_min_epi32(_mm256_max_epi32(g32, zero32), max32);
//        b32 = _mm256_min_epi32(_mm256_max_epi32(b32, zero32), max32);
//
//        __m128i r16 = _mm_packus_epi32(_mm256_castsi256_si128(r32),
//                                       _mm256_extracti128_si256(r32, 1));
//        __m128i g16 = _mm_packus_epi32(_mm256_castsi256_si128(g32),
//                                       _mm256_extracti128_si256(g32, 1));
//        __m128i b16 = _mm_packus_epi32(_mm256_castsi256_si128(b32),
//                                       _mm256_extracti128_si256(b32, 1));
//
//        __m128i r8 = _mm_packus_epi16(r16, r16);
//        __m128i g8 = _mm_packus_epi16(g16, g16);
//        __m128i b8 = _mm_packus_epi16(b16, b16);
//
//        __m128i a8 = _mm_set1_epi8((char)255);
//
//        __m128i bg = _mm_unpacklo_epi8(b8, g8);
//        __m128i ra = _mm_unpacklo_epi8(r8, a8);
//
//        __m128i bgra0 = _mm_unpacklo_epi16(bg, ra);
//        __m128i bgra1 = _mm_unpackhi_epi16(bg, ra);
//
//        _mm_storeu_si128((__m128i*)(dst +  0), bgra0);
//        _mm_storeu_si128((__m128i*)(dst + 16), bgra1);
//    }
//};
//
//#pragma clang attribute pop

#include <immintrin.h>
#include <cstdint>
#include <vector>
#include <cstdio>

#pragma clang attribute push (__attribute__((target("avx2"))), apply_to=function)

class YUY2Converter
{
public:
    static void Convert(
        const uint8_t* src,
        int src_stride,
        uint8_t* dst,
        int dst_stride,
        int width,
        int height
    ) {
        if (hasAVX2())
            Convert_AVX2(src, src_stride, dst, dst_stride, width, height);
        else
            Convert_Scalar(src, src_stride, dst, dst_stride, width, height);
    }

    static bool hasAVX2()
    {
#if defined(__GNUC__) || defined(__clang__)
        return __builtin_cpu_supports("avx2");
#elif defined(_MSC_VER)
        int cpuInfo[4];
        __cpuid(cpuInfo, 7);
        return (cpuInfo[1] & (1 << 5)) != 0;
#else
        return false;
#endif
    }

    // ---------------- Scalar（正確基準版） ----------------
    static void Convert_Scalar(
        const uint8_t* src,
        int src_stride,
        uint8_t* dst,
        int dst_stride,
        int width,
        int height
    ) {
        for (int y = 0; y < height; y++)
        {
            const uint8_t* s = src + y * src_stride;
            uint8_t* d = dst + y * dst_stride;

            for (int x = 0; x < width; x += 2)
            {
                uint8_t Y0 = s[0];
                uint8_t U  = s[1];
                uint8_t Y1 = s[2];
                uint8_t V  = s[3];

                int C0 = Y0 - 16;
                int C1 = Y1 - 16;
                int D  = U  - 128;
                int E  = V  - 128;

                int R0 = (298 * C0 + 409 * E + 128) >> 8;
                int G0 = (298 * C0 - 100 * D - 208 * E + 128) >> 8;
                int B0 = (298 * C0 + 516 * D + 128) >> 8;

                int R1 = (298 * C1 + 409 * E + 128) >> 8;
                int G1 = (298 * C1 - 100 * D - 208 * E + 128) >> 8;
                int B1 = (298 * C1 + 516 * D + 128) >> 8;

                R0 = R0 < 0 ? 0 : (R0 > 255 ? 255 : R0);
                G0 = G0 < 0 ? 0 : (G0 > 255 ? 255 : G0);
                B0 = B0 < 0 ? 0 : (B0 > 255 ? 255 : B0);

                R1 = R1 < 0 ? 0 : (R1 > 255 ? 255 : R1);
                G1 = G1 < 0 ? 0 : (G1 > 255 ? 255 : G1);
                B1 = B1 < 0 ? 0 : (B1 > 255 ? 255 : B1);

                d[0] = B0; d[1] = G0; d[2] = R0; d[3] = 255;
                d[4] = B1; d[5] = G1; d[6] = R1; d[7] = 255;

                s += 4;
                d += 8;
            }
        }
    }

    // ---------------- AVX2（與 Scalar 顏色對齊的版本） ----------------
    static void Convert_AVX2(
        const uint8_t* src,
        int src_stride,
        uint8_t* dst,
        int dst_stride,
        int width,
        int height
    ) {
        const int step = 16; // 一次處理 16 pixels

        const __m256i y_shuffle = _mm256_set_epi8(
            14,12,10,8,6,4,2,0,
            14,12,10,8,6,4,2,0,
            14,12,10,8,6,4,2,0,
            14,12,10,8,6,4,2,0
        );

        const __m256i u_shuffle = _mm256_set_epi8(
            13,13, 9, 9, 5, 5, 1, 1,
            13,13, 9, 9, 5, 5, 1, 1,
            13,13, 9, 9, 5, 5, 1, 1,
            13,13, 9, 9, 5, 5, 1, 1
        );

        const __m256i v_shuffle = _mm256_set_epi8(
            15,15,11,11, 7, 7, 3, 3,
            15,15,11,11, 7, 7, 3, 3,
            15,15,11,11, 7, 7, 3, 3,
            15,15,11,11, 7, 7, 3, 3
        );

        const __m256i c16  = _mm256_set1_epi16(16);
        const __m256i c128 = _mm256_set1_epi16(128);

        for (int y = 0; y < height; y++)
        {
            const uint8_t* s = src + y * src_stride;
            uint8_t* d = dst + y * dst_stride;

            int x = 0;

            for (; x <= width - step; x += step)
            {
                const uint8_t* sp = s + x * 2; // YUY2: 2 bytes per pixel
                __m256i yuy2 = _mm256_loadu_si256((const __m256i*)sp);

                __m256i y_bytes = _mm256_shuffle_epi8(yuy2, y_shuffle);
                __m256i u_bytes = _mm256_shuffle_epi8(yuy2, u_shuffle);
                __m256i v_bytes = _mm256_shuffle_epi8(yuy2, v_shuffle);

                __m128i y_lo_8 = _mm256_castsi256_si128(y_bytes);
                __m128i y_hi_8 = _mm256_extracti128_si256(y_bytes, 1);

                __m128i u_lo_8 = _mm256_castsi256_si128(u_bytes);
                __m128i u_hi_8 = _mm256_extracti128_si256(u_bytes, 1);

                __m128i v_lo_8 = _mm256_castsi256_si128(v_bytes);
                __m128i v_hi_8 = _mm256_extracti128_si256(v_bytes, 1);

                __m256i y_lo = _mm256_sub_epi16(_mm256_cvtepu8_epi16(y_lo_8), c16);
                __m256i y_hi = _mm256_sub_epi16(_mm256_cvtepu8_epi16(y_hi_8), c16);

                __m256i u_lo = _mm256_sub_epi16(_mm256_cvtepu8_epi16(u_lo_8), c128);
                __m256i u_hi = _mm256_sub_epi16(_mm256_cvtepu8_epi16(u_hi_8), c128);

                __m256i v_lo = _mm256_sub_epi16(_mm256_cvtepu8_epi16(v_lo_8), c128);
                __m256i v_hi = _mm256_sub_epi16(_mm256_cvtepu8_epi16(v_hi_8), c128);

                process8(d + x * 4 + 0,  y_lo, u_lo, v_lo);
                process8(d + x * 4 + 32, y_hi, u_hi, v_hi);
            }

            if (x < width)
            {
                Convert_Scalar(
                    s + x * 2,
                    src_stride,
                    d + x * 4,
                    dst_stride,
                    width - x,
                    1
                );
            }
        }
    }

private:
    // 8 pixels，32-bit 精準版，BGRA（與 Scalar 對齊）
    static inline void process8(
        uint8_t* dst,
        __m256i y16,
        __m256i u16,
        __m256i v16
    ) {
        static const __m256i k298 = _mm256_set1_epi32(298);
        static const __m256i k409 = _mm256_set1_epi32(409);
        static const __m256i k100 = _mm256_set1_epi32(100);
        static const __m256i k208 = _mm256_set1_epi32(208);
        static const __m256i k516 = _mm256_set1_epi32(516);
        static const __m256i bias = _mm256_set1_epi32(128);
        static const __m256i zero32 = _mm256_set1_epi32(0);
        static const __m256i max32  = _mm256_set1_epi32(255);

        __m128i y_lo16 = _mm256_castsi256_si128(y16);
        __m128i u_lo16 = _mm256_castsi256_si128(u16);
        __m128i v_lo16 = _mm256_castsi256_si128(v16);

        __m256i y32 = _mm256_cvtepi16_epi32(y_lo16);
        __m256i u32 = _mm256_cvtepi16_epi32(u_lo16);
        __m256i v32 = _mm256_cvtepi16_epi32(v_lo16);

        __m256i c = _mm256_mullo_epi32(y32, k298);

        __m256i r32 = _mm256_srai_epi32(
            _mm256_add_epi32(
                _mm256_add_epi32(c, _mm256_mullo_epi32(v32, k409)),
                bias
            ), 8);

        __m256i g32 = _mm256_srai_epi32(
            _mm256_add_epi32(
                _mm256_sub_epi32(
                    _mm256_sub_epi32(c, _mm256_mullo_epi32(u32, k100)),
                    _mm256_mullo_epi32(v32, k208)
                ),
                bias
            ), 8);

        __m256i b32 = _mm256_srai_epi32(
            _mm256_add_epi32(
                _mm256_add_epi32(c, _mm256_mullo_epi32(u32, k516)),
                bias
            ), 8);

        r32 = _mm256_min_epi32(_mm256_max_epi32(r32, zero32), max32);
        g32 = _mm256_min_epi32(_mm256_max_epi32(g32, zero32), max32);
        b32 = _mm256_min_epi32(_mm256_max_epi32(b32, zero32), max32);

        __m128i r16 = _mm_packus_epi32(_mm256_castsi256_si128(r32),
                                       _mm256_extracti128_si256(r32, 1));
        __m128i g16 = _mm_packus_epi32(_mm256_castsi256_si128(g32),
                                       _mm256_extracti128_si256(g32, 1));
        __m128i b16 = _mm_packus_epi32(_mm256_castsi256_si128(b32),
                                       _mm256_extracti128_si256(b32, 1));

        __m128i r8 = _mm_packus_epi16(r16, r16);
        __m128i g8 = _mm_packus_epi16(g16, g16);
        __m128i b8 = _mm_packus_epi16(b16, b16);

        __m128i a8 = _mm_set1_epi8((char)255);

        __m128i bg = _mm_unpacklo_epi8(b8, g8);
        __m128i ra = _mm_unpacklo_epi8(r8, a8);

        __m128i bgra0 = _mm_unpacklo_epi16(bg, ra);
        __m128i bgra1 = _mm_unpackhi_epi16(bg, ra);

        _mm_storeu_si128((__m128i*)(dst +  0), bgra0);
        _mm_storeu_si128((__m128i*)(dst + 16), bgra1);
    }

public:
    // ---------------- 驗證：AVX2 與 Scalar 是否完全一致 ----------------
    static void Verify(const uint8_t* src, int src_stride,
                       int width, int height)
    {
        std::vector<uint8_t> ref(height * width * 4);
        std::vector<uint8_t> test(height * width * 4);

        Convert_Scalar(src, src_stride,
                       ref.data(), width * 4,
                       width, height);

        Convert_AVX2(src, src_stride,
                     test.data(), width * 4,
                     width, height);

        for (int i = 0; i < width * height * 4; i++)
        {
            if (ref[i] != test[i])
            {
                std::printf("Mismatch at %d: ref=%d test=%d\n",
                            i, ref[i], test[i]);
                return;
            }
        }

        std::printf("OK: AVX2 matches Scalar\n");
    }
};

#pragma clang attribute pop



int hahaha_thread_command_webcam_ha::On_Grab(hahahalib::hahaha_capture_webcam_direct_show_origin* webcam)
{
//    // 建立暫存 Bitmap
//    std::unique_ptr<halib::bitmap_alloc_yuy2> bitmap_yuy2_ha_temp_;
//    if(bitmap_yuy2_ha_temp_.get() == NULL)
//    {
//        bitmap_yuy2_ha_temp_.reset(new halib::bitmap_alloc_yuy2);
//    }
//
//    bitmap_yuy2_ha_temp_->Resize(ha::Bitmap_Yuy2_Ha_->Width_, ha::Bitmap_Yuy2_Ha_->Height_);
//
//    // 抓圖
//    int result_ = webcam->Grab(*bitmap_yuy2_ha_temp_);
//
//
//
//    std::unique_ptr<halib::bitmap_alloc_argb> bitmap_argb_ha_temp_;
//    if(bitmap_argb_ha_temp_.get() == NULL)
//    {
//        bitmap_argb_ha_temp_.reset(new halib::bitmap_alloc_argb);
//    }
//
//    bitmap_argb_ha_temp_->Resize(ha::Bitmap_Argb_Ha_->Width_, ha::Bitmap_Argb_Ha_->Height_);
//
//
//
//    YUY2Converter::Convert(
//        bitmap_yuy2_ha_temp_->Image_Ptr_,
//        bitmap_yuy2_ha_temp_->Stride_,
//        bitmap_argb_ha_temp_->Image_Ptr_,
//        bitmap_argb_ha_temp_->Stride_,
//        ha::Bitmap_Argb_Ha_->Width_, ha::Bitmap_Argb_Ha_->Height_
//    );
//
//
//    if(result_ == 0)
//	{
//        // 將暫存 Bitmap 移動到 queue（thread-safe）
//        {
//            std::lock_guard<std::mutex> lock(Bitmap_Buffer_Mutex_);
//            Bitmap_Buffer_.push(std::move(bitmap_argb_ha_temp_));
//        }
//
////		hahahalib::hahaha_ui_message ui_;
////		ui_.Handle_ = ha::Pointer_Main_->Form_Main_->Handle;
////        ui_.Send_Message(MESSAGE_UI, 0,
//		ha::Pointer_Main_->Command_UI_->Add_Sync(
//            new std::function<void()>(
//				[this]()
//                {
//                    std::unique_ptr<halib::bitmap_alloc_argb> bitmap_;
//
//                    {
//                        std::lock_guard<std::mutex> lock(Bitmap_Buffer_Mutex_);
//                        if (!Bitmap_Buffer_.empty())
//						{
//							bitmap_ = std::move(Bitmap_Buffer_.front());
//                            Bitmap_Buffer_.pop();
//                        }
//					}
//
//					Bitmap_Old_.reset();   // ✔ 正確：會 delete
//
//					if (bitmap_)
//					{
//						ha::Image_View_Ha_->Bitmap_ = bitmap_.get();
//					}
//
////                    if (bitmap_)
////					{
////						ha::Image_View_Ha_->Is_View_Thumbnail_ = false;
////						ha::Image_View_Ha_->Is_Repaint_ = true;
////						ha::Image_View_Ha_->Is_Repaint_View_Image_ = true;
////						ha::Image_View_Ha_->Repaint();
////
////					}
//
//                    if (bitmap_)
//					{
//						ha::Structure_Main_->Image_View_->Bitmap_ = bitmap_.get();
//					}
//
//                    if (bitmap_)
//					{
//						ha::Structure_Main_->Image_View_->Is_View_Thumbnail_ = false;
//						ha::Structure_Main_->Image_View_->Is_Repaint_ = true;
//						ha::Structure_Main_->Image_View_->Is_Repaint_View_Image_ = true;
//						ha::Structure_Main_->Image_View_->Repaint();
////
//					}
//
//
//
//					Bitmap_Old_ = std::move(bitmap_);
//				}
//            )
//
//        );
//
//    }




    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_command_webcam_ha::Add_Grab(hahahalib::hahaha_capture_webcam_direct_show_origin* webcam)
{
	Mutex_->Lock();

    std::unique_ptr<hahahalib::hahaha_thread_command_command> command_;
    command_.reset(new hahahalib::hahaha_thread_command_command);

    hahaha::hahaha_thread_command_parameter_webcam* p_ = new hahaha::hahaha_thread_command_parameter_webcam;
    p_->Webcam_ = webcam;

//
	command_->Command_ = (int)hahaha_thread_command_command_command::ADD_GRAB;
    command_->Parameter_ = p_;
//
	Queue_Command_.push(std::move(command_));
    SetEvent(Event_Run_);

	Mutex_->Un_Lock();
	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahaha
//---------------------------------------------------------------------------