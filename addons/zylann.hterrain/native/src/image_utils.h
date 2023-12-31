#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/image.hpp>

#include <string>
#include <vector>

namespace godot {

class ImageUtils : public RefCounted
{
    GDCLASS(ImageUtils, RefCounted);


protected:
	static void _bind_methods();
public:


    ImageUtils();
    ~ImageUtils();

    void _init();

    Vector2 get_red_range(Ref<Image> image_ref, Rect2 rect) const;
    float get_red_sum(Ref<Image> image_ref, Rect2 rect) const;
    float get_red_sum_weighted(Ref<Image> image_ref, Ref<Image> brush_ref, Vector2 p_pos, float factor) const;
    void add_red_brush(Ref<Image> image_ref, Ref<Image> brush_ref, Vector2 p_pos, float factor) const;
    void lerp_channel_brush(Ref<Image> image_ref, Ref<Image> brush_ref, Vector2 p_pos, float factor, float target_value, int channel) const;
    void lerp_color_brush(Ref<Image> image_ref, Ref<Image> brush_ref, Vector2 p_pos, float factor, Color target_value) const;
    float generate_gaussian_brush(Ref<Image> image_ref) const;
    void blur_red_brush(Ref<Image> image_ref, Ref<Image> brush_ref, Vector2 p_pos, float factor);
    void paint_indexed_splat(Ref<Image> index_map_ref, Ref<Image> weight_map_ref, Ref<Image> brush_ref, Vector2 p_pos, int texture_index, float factor);
    //void erode_red_brush(Ref<Image> image_ref, Ref<Image> brush_ref, Vector2 p_pos, float factor);

private:
    std::vector<float> _blur_buffer;
};

} // namespace godot

#endif // IMAGE_UTILS_H
