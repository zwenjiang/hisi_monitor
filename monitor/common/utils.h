#ifndef UTILS_H_
#define UTILS_H_

#include "common/res_code.h"
#include "common/config.h"

namespace nvr
{
class Utils
{
public:
    static inline int Align(int num, int align)
    {
        return (num + align - 1) & ~(align - 1);
    }

    static int CalcPicVbBlkSize(int align = ALIGN)
    {
        int32_t vb_pic_header_size;
        int32_t align_width = Align(1920, align);
        int32_t align_height = Align(1080, align);
        VB_PIC_HEADER_SIZE(align_width, align_height, PIXEL_FORMAT, vb_pic_header_size);
        return vb_pic_header_size + ((align_width * align_height) * 3 >> 1);
    }
};
} // namespace nvr

#endif