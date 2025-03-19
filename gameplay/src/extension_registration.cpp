//
// Copyright (c) 2023 Paper Cranes Ltd.
// All rights reserved.
//
#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <movement.h>

void register_gameplay_types(godot::ModuleInitializationLevel p_level) {
  if (p_level != godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE) {
	return;
  }

  godot::ClassDB::register_class<godot::Movement>();
}

void unregister_gameplay_types(godot::ModuleInitializationLevel p_level) {
}

extern "C" {
	// Initialization.
	GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization) {
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(register_gameplay_types);
		init_obj.register_terminator(unregister_gameplay_types);
		init_obj.set_minimum_library_initialization_level(godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}





