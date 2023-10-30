

#include <godot_cpp/classes/ref.hpp>
#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/variant.hpp>


#include "image_utils.h"
#include "quad_tree_lod.h"


using namespace godot;


void  initialize_heightmap_types(ModuleInitializationLevel p_level)
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_CORE) {
		return;
	}

	ClassDB::register_class<godot::ImageUtils>();
	ClassDB::register_class<godot::QuadTreeLod>();
}

void uninitialize_heightmap_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_CORE) {
		return;
	}
}

extern "C"
{

	// Initialization.

	GDExtensionBool GDE_EXPORT heightmap_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(initialize_heightmap_types);
		init_obj.register_terminator(uninitialize_heightmap_types);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_CORE);

		return init_obj.init();
	}
}
