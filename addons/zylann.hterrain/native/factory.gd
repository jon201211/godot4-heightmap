@tool

const NATIVE_PATH = "res://addons/zylann.hterrain/native/"

const HT_ImageUtilsGeneric = preload("./image_utils_generic.gd")
const HT_QuadTreeLodGeneric = preload("./quad_tree_lod_generic.gd")

# No native code was ported when moving to Godot 4.
# It may be changed too using GDExtension.

# See https://docs.godotengine.org/en/stable/classes/class_os.html#class-os-method-get-name
const _supported_os = {
	# "Windows": true,
	# "X11": true,
	# "OSX": true
}
# See https://docs.godotengine.org/en/stable/tutorials/export/feature_tags.html
const _supported_archs = ["x86_64"]


static func get_image_utils():
	if ClassDB.class_exists("ImageUtils"):
		push_warning("ImageUtils use gdextension!!!")
		return ImageUtils.new()
	return HT_ImageUtilsGeneric.new()


static func get_quad_tree_lod():
	if ClassDB.class_exists("QuadTreeLod"):
		push_warning("QuadTreeLod use gdextension!!!")
		return QuadTreeLod.new()
	return HT_QuadTreeLodGeneric.new()
