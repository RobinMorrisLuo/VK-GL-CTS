/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 * This file was generated by /scripts/gen_framework.py
 */


bool checkVersion(uint32_t major, uint32_t minor, const uint32_t testedApiVersion)
{
	uint32_t testedMajor = VK_API_VERSION_MAJOR(testedApiVersion);
	uint32_t testedMinor = VK_API_VERSION_MINOR(testedApiVersion);
	// return true when tested api version is greater
	// or equal to version represented by two uints
	if (major == testedMajor)
		return minor <= testedMinor;
	return major < testedMajor;
}

bool extensionIsSupported(const std::vector<std::string> extNames, const std::string& ext)
{
	for (const std::string& supportedExtension : extNames)
	{
		if (supportedExtension == ext) return true;
	}
	return false;
}

void getInstanceExtensionFunctions (uint32_t apiVersion, const std::vector<std::string> vIEP, const std::vector<std::string> vDEP, const std::string extName, ::std::vector<const char*>& functions)
{
	(void)vIEP;
(void)vDEP;
	if (extName == "VK_KHR_surface")
	{
		functions.push_back("vkDestroySurfaceKHR");
		functions.push_back("vkGetPhysicalDeviceSurfaceSupportKHR");
		functions.push_back("vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
		functions.push_back("vkGetPhysicalDeviceSurfaceFormatsKHR");
		functions.push_back("vkGetPhysicalDeviceSurfacePresentModesKHR");
		return;
	}
	if (extName == "VK_KHR_swapchain")
	{
		// Dependencies: VK_VERSION_1_1
		if (checkVersion(1, 1, apiVersion)) {
			if(apiVersion >= VK_API_VERSION_1_1) functions.push_back("vkGetPhysicalDevicePresentRectanglesKHR");
		}
		return;
	}
	if (extName == "VK_KHR_display")
	{
		functions.push_back("vkGetPhysicalDeviceDisplayPropertiesKHR");
		functions.push_back("vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
		functions.push_back("vkGetDisplayPlaneSupportedDisplaysKHR");
		functions.push_back("vkGetDisplayModePropertiesKHR");
		functions.push_back("vkCreateDisplayModeKHR");
		functions.push_back("vkGetDisplayPlaneCapabilitiesKHR");
		functions.push_back("vkCreateDisplayPlaneSurfaceKHR");
		return;
	}
	if (extName == "VK_KHR_display_swapchain")
	{
		return;
	}
	if (extName == "VK_EXT_depth_range_unrestricted")
	{
		return;
	}
	if (extName == "VK_NV_private_vendor_info")
	{
		return;
	}
	if (extName == "VK_EXT_texture_compression_astc_hdr")
	{
		return;
	}
	if (extName == "VK_EXT_astc_decode_mode")
	{
		return;
	}
	if (extName == "VK_KHR_external_memory_fd")
	{
		return;
	}
	if (extName == "VK_KHR_external_semaphore_fd")
	{
		return;
	}
	if (extName == "VK_KHR_incremental_present")
	{
		return;
	}
	if (extName == "VK_EXT_direct_mode_display")
	{
		functions.push_back("vkReleaseDisplayEXT");
		return;
	}
	if (extName == "VK_EXT_display_surface_counter")
	{
		functions.push_back("vkGetPhysicalDeviceSurfaceCapabilities2EXT");
		return;
	}
	if (extName == "VK_EXT_display_control")
	{
		return;
	}
	if (extName == "VK_EXT_discard_rectangles")
	{
		return;
	}
	if (extName == "VK_EXT_conservative_rasterization")
	{
		return;
	}
	if (extName == "VK_EXT_depth_clip_enable")
	{
		return;
	}
	if (extName == "VK_EXT_swapchain_colorspace")
	{
		return;
	}
	if (extName == "VK_EXT_hdr_metadata")
	{
		return;
	}
	if (extName == "VK_KHR_shared_presentable_image")
	{
		return;
	}
	if (extName == "VK_KHR_external_fence_fd")
	{
		return;
	}
	if (extName == "VK_KHR_performance_query")
	{
		functions.push_back("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
		functions.push_back("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
		return;
	}
	if (extName == "VK_KHR_get_surface_capabilities2")
	{
		functions.push_back("vkGetPhysicalDeviceSurfaceCapabilities2KHR");
		functions.push_back("vkGetPhysicalDeviceSurfaceFormats2KHR");
		return;
	}
	if (extName == "VK_KHR_get_display_properties2")
	{
		functions.push_back("vkGetPhysicalDeviceDisplayProperties2KHR");
		functions.push_back("vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
		functions.push_back("vkGetDisplayModeProperties2KHR");
		functions.push_back("vkGetDisplayPlaneCapabilities2KHR");
		return;
	}
	if (extName == "VK_EXT_external_memory_dma_buf")
	{
		return;
	}
	if (extName == "VK_EXT_queue_family_foreign")
	{
		return;
	}
	if (extName == "VK_EXT_debug_utils")
	{
		functions.push_back("vkCreateDebugUtilsMessengerEXT");
		functions.push_back("vkDestroyDebugUtilsMessengerEXT");
		functions.push_back("vkSubmitDebugUtilsMessageEXT");
		return;
	}
	if (extName == "VK_EXT_shader_stencil_export")
	{
		return;
	}
	if (extName == "VK_EXT_sample_locations")
	{
		functions.push_back("vkGetPhysicalDeviceMultisamplePropertiesEXT");
		return;
	}
	if (extName == "VK_EXT_blend_operation_advanced")
	{
		return;
	}
	if (extName == "VK_EXT_post_depth_coverage")
	{
		return;
	}
	if (extName == "VK_EXT_image_drm_format_modifier")
	{
		return;
	}
	if (extName == "VK_EXT_filter_cubic")
	{
		return;
	}
	if (extName == "VK_EXT_external_memory_host")
	{
		return;
	}
	if (extName == "VK_KHR_shader_clock")
	{
		return;
	}
	if (extName == "VK_KHR_global_priority")
	{
		return;
	}
	if (extName == "VK_KHR_swapchain_mutable_format")
	{
		return;
	}
	if (extName == "VK_EXT_pci_bus_info")
	{
		return;
	}
	if (extName == "VK_KHR_shader_terminate_invocation")
	{
		return;
	}
	if (extName == "VK_EXT_subgroup_size_control")
	{
		return;
	}
	if (extName == "VK_KHR_fragment_shading_rate")
	{
		functions.push_back("vkGetPhysicalDeviceFragmentShadingRatesKHR");
		return;
	}
	if (extName == "VK_EXT_shader_image_atomic_int64")
	{
		return;
	}
	if (extName == "VK_EXT_memory_budget")
	{
		return;
	}
	if (extName == "VK_EXT_validation_features")
	{
		return;
	}
	if (extName == "VK_EXT_fragment_shader_interlock")
	{
		return;
	}
	if (extName == "VK_EXT_ycbcr_image_arrays")
	{
		return;
	}
	if (extName == "VK_EXT_headless_surface")
	{
		functions.push_back("vkCreateHeadlessSurfaceEXT");
		return;
	}
	if (extName == "VK_EXT_line_rasterization")
	{
		return;
	}
	if (extName == "VK_EXT_shader_atomic_float")
	{
		return;
	}
	if (extName == "VK_EXT_index_type_uint8")
	{
		return;
	}
	if (extName == "VK_EXT_extended_dynamic_state")
	{
		return;
	}
	if (extName == "VK_EXT_shader_demote_to_helper_invocation")
	{
		return;
	}
	if (extName == "VK_EXT_texel_buffer_alignment")
	{
		return;
	}
	if (extName == "VK_EXT_robustness2")
	{
		return;
	}
	if (extName == "VK_EXT_custom_border_color")
	{
		return;
	}
	if (extName == "VK_KHR_object_refresh")
	{
		functions.push_back("vkGetPhysicalDeviceRefreshableObjectTypesKHR");
		return;
	}
	if (extName == "VK_KHR_synchronization2")
	{
		return;
	}
	if (extName == "VK_EXT_ycbcr_2plane_444_formats")
	{
		return;
	}
	if (extName == "VK_EXT_image_robustness")
	{
		return;
	}
	if (extName == "VK_KHR_copy_commands2")
	{
		return;
	}
	if (extName == "VK_EXT_4444_formats")
	{
		return;
	}
	if (extName == "VK_NV_acquire_winrt_display")
	{
		functions.push_back("vkAcquireWinrtDisplayNV");
		functions.push_back("vkGetWinrtDisplayNV");
		return;
	}
	if (extName == "VK_EXT_vertex_input_dynamic_state")
	{
		return;
	}
	if (extName == "VK_NV_external_sci_sync")
	{
		functions.push_back("vkGetPhysicalDeviceSciSyncAttributesNV");
		return;
	}
	if (extName == "VK_NV_external_memory_sci_buf")
	{
		functions.push_back("vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV");
		functions.push_back("vkGetPhysicalDeviceSciBufAttributesNV");
		return;
	}
	if (extName == "VK_EXT_extended_dynamic_state2")
	{
		return;
	}
	if (extName == "VK_EXT_color_write_enable")
	{
		return;
	}
	if (extName == "VK_EXT_application_parameters")
	{
		return;
	}
	if (extName == "VK_NV_external_sci_sync2")
	{
		functions.push_back("vkGetPhysicalDeviceSciSyncAttributesNV");
		return;
	}
	if (extName == "VK_EXT_layer_settings")
	{
		return;
	}
	if (extName == "VK_KHR_vertex_attribute_divisor")
	{
		return;
	}
	if (extName == "VK_QNX_external_memory_screen_buffer")
	{
		return;
	}
	if (extName == "VK_KHR_index_type_uint8")
	{
		return;
	}
	if (extName == "VK_KHR_line_rasterization")
	{
		return;
	}
	if (extName == "VK_KHR_calibrated_timestamps")
	{
		functions.push_back("vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
		return;
	}
	if (extName == "VK_NV_device_diagnostic_checkpoints")
	{
		return;
	}
	if (extName == "VK_KHR_format_feature_flags2")
	{
		return;
	}
	if (extName == "VK_EXT_vertex_attribute_divisor")
	{
		return;
	}
	if (extName == "VK_EXT_global_priority")
	{
		return;
	}
	if (extName == "VK_EXT_calibrated_timestamps")
	{
		functions.push_back("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
		return;
	}
	DE_FATAL("Extension name not found");
}

void getDeviceExtensionFunctions (uint32_t apiVersion, const std::vector<std::string> vIEP, const std::vector<std::string> vDEP, const std::string extName, ::std::vector<const char*>& functions)
{
	(void)vIEP;
(void)vDEP;
	if (extName == "VK_KHR_surface")
	{
		return;
	}
	if (extName == "VK_KHR_swapchain")
	{
		functions.push_back("vkCreateSwapchainKHR");
		functions.push_back("vkGetSwapchainImagesKHR");
		functions.push_back("vkAcquireNextImageKHR");
		functions.push_back("vkQueuePresentKHR");
		// Dependencies: VK_VERSION_1_1
		if (checkVersion(1, 1, apiVersion)) {
			if(apiVersion >= VK_API_VERSION_1_1) functions.push_back("vkGetDeviceGroupPresentCapabilitiesKHR");
			if(apiVersion >= VK_API_VERSION_1_1) functions.push_back("vkGetDeviceGroupSurfacePresentModesKHR");
			if(apiVersion >= VK_API_VERSION_1_1) functions.push_back("vkAcquireNextImage2KHR");
		}
		return;
	}
	if (extName == "VK_KHR_display")
	{
		return;
	}
	if (extName == "VK_KHR_display_swapchain")
	{
		functions.push_back("vkCreateSharedSwapchainsKHR");
		return;
	}
	if (extName == "VK_EXT_depth_range_unrestricted")
	{
		return;
	}
	if (extName == "VK_NV_private_vendor_info")
	{
		return;
	}
	if (extName == "VK_EXT_texture_compression_astc_hdr")
	{
		return;
	}
	if (extName == "VK_EXT_astc_decode_mode")
	{
		return;
	}
	if (extName == "VK_KHR_external_memory_fd")
	{
		functions.push_back("vkGetMemoryFdKHR");
		functions.push_back("vkGetMemoryFdPropertiesKHR");
		return;
	}
	if (extName == "VK_KHR_external_semaphore_fd")
	{
		functions.push_back("vkImportSemaphoreFdKHR");
		functions.push_back("vkGetSemaphoreFdKHR");
		return;
	}
	if (extName == "VK_KHR_incremental_present")
	{
		return;
	}
	if (extName == "VK_EXT_direct_mode_display")
	{
		return;
	}
	if (extName == "VK_EXT_display_surface_counter")
	{
		return;
	}
	if (extName == "VK_EXT_display_control")
	{
		functions.push_back("vkDisplayPowerControlEXT");
		functions.push_back("vkRegisterDeviceEventEXT");
		functions.push_back("vkRegisterDisplayEventEXT");
		functions.push_back("vkGetSwapchainCounterEXT");
		return;
	}
	if (extName == "VK_EXT_discard_rectangles")
	{
		functions.push_back("vkCmdSetDiscardRectangleEXT");
		functions.push_back("vkCmdSetDiscardRectangleEnableEXT");
		functions.push_back("vkCmdSetDiscardRectangleModeEXT");
		return;
	}
	if (extName == "VK_EXT_conservative_rasterization")
	{
		return;
	}
	if (extName == "VK_EXT_depth_clip_enable")
	{
		return;
	}
	if (extName == "VK_EXT_swapchain_colorspace")
	{
		return;
	}
	if (extName == "VK_EXT_hdr_metadata")
	{
		functions.push_back("vkSetHdrMetadataEXT");
		return;
	}
	if (extName == "VK_KHR_shared_presentable_image")
	{
		functions.push_back("vkGetSwapchainStatusKHR");
		return;
	}
	if (extName == "VK_KHR_external_fence_fd")
	{
		functions.push_back("vkImportFenceFdKHR");
		functions.push_back("vkGetFenceFdKHR");
		return;
	}
	if (extName == "VK_KHR_performance_query")
	{
		functions.push_back("vkAcquireProfilingLockKHR");
		functions.push_back("vkReleaseProfilingLockKHR");
		return;
	}
	if (extName == "VK_KHR_get_surface_capabilities2")
	{
		return;
	}
	if (extName == "VK_KHR_get_display_properties2")
	{
		return;
	}
	if (extName == "VK_EXT_external_memory_dma_buf")
	{
		return;
	}
	if (extName == "VK_EXT_queue_family_foreign")
	{
		return;
	}
	if (extName == "VK_EXT_debug_utils")
	{
		functions.push_back("vkSetDebugUtilsObjectNameEXT");
		functions.push_back("vkSetDebugUtilsObjectTagEXT");
		functions.push_back("vkQueueBeginDebugUtilsLabelEXT");
		functions.push_back("vkQueueEndDebugUtilsLabelEXT");
		functions.push_back("vkQueueInsertDebugUtilsLabelEXT");
		functions.push_back("vkCmdBeginDebugUtilsLabelEXT");
		functions.push_back("vkCmdEndDebugUtilsLabelEXT");
		functions.push_back("vkCmdInsertDebugUtilsLabelEXT");
		return;
	}
	if (extName == "VK_EXT_shader_stencil_export")
	{
		return;
	}
	if (extName == "VK_EXT_sample_locations")
	{
		functions.push_back("vkCmdSetSampleLocationsEXT");
		return;
	}
	if (extName == "VK_EXT_blend_operation_advanced")
	{
		return;
	}
	if (extName == "VK_EXT_post_depth_coverage")
	{
		return;
	}
	if (extName == "VK_EXT_image_drm_format_modifier")
	{
		functions.push_back("vkGetImageDrmFormatModifierPropertiesEXT");
		return;
	}
	if (extName == "VK_EXT_filter_cubic")
	{
		return;
	}
	if (extName == "VK_EXT_external_memory_host")
	{
		functions.push_back("vkGetMemoryHostPointerPropertiesEXT");
		return;
	}
	if (extName == "VK_KHR_shader_clock")
	{
		return;
	}
	if (extName == "VK_KHR_global_priority")
	{
		return;
	}
	if (extName == "VK_KHR_swapchain_mutable_format")
	{
		return;
	}
	if (extName == "VK_EXT_pci_bus_info")
	{
		return;
	}
	if (extName == "VK_KHR_shader_terminate_invocation")
	{
		return;
	}
	if (extName == "VK_EXT_subgroup_size_control")
	{
		return;
	}
	if (extName == "VK_KHR_fragment_shading_rate")
	{
		functions.push_back("vkCmdSetFragmentShadingRateKHR");
		return;
	}
	if (extName == "VK_EXT_shader_image_atomic_int64")
	{
		return;
	}
	if (extName == "VK_EXT_memory_budget")
	{
		return;
	}
	if (extName == "VK_EXT_validation_features")
	{
		return;
	}
	if (extName == "VK_EXT_fragment_shader_interlock")
	{
		return;
	}
	if (extName == "VK_EXT_ycbcr_image_arrays")
	{
		return;
	}
	if (extName == "VK_EXT_headless_surface")
	{
		return;
	}
	if (extName == "VK_EXT_line_rasterization")
	{
		functions.push_back("vkCmdSetLineStippleEXT");
		return;
	}
	if (extName == "VK_EXT_shader_atomic_float")
	{
		return;
	}
	if (extName == "VK_EXT_index_type_uint8")
	{
		return;
	}
	if (extName == "VK_EXT_extended_dynamic_state")
	{
		functions.push_back("vkCmdSetCullModeEXT");
		functions.push_back("vkCmdSetFrontFaceEXT");
		functions.push_back("vkCmdSetPrimitiveTopologyEXT");
		functions.push_back("vkCmdSetViewportWithCountEXT");
		functions.push_back("vkCmdSetScissorWithCountEXT");
		functions.push_back("vkCmdBindVertexBuffers2EXT");
		functions.push_back("vkCmdSetDepthTestEnableEXT");
		functions.push_back("vkCmdSetDepthWriteEnableEXT");
		functions.push_back("vkCmdSetDepthCompareOpEXT");
		functions.push_back("vkCmdSetDepthBoundsTestEnableEXT");
		functions.push_back("vkCmdSetStencilTestEnableEXT");
		functions.push_back("vkCmdSetStencilOpEXT");
		return;
	}
	if (extName == "VK_EXT_shader_demote_to_helper_invocation")
	{
		return;
	}
	if (extName == "VK_EXT_texel_buffer_alignment")
	{
		return;
	}
	if (extName == "VK_EXT_robustness2")
	{
		return;
	}
	if (extName == "VK_EXT_custom_border_color")
	{
		return;
	}
	if (extName == "VK_KHR_object_refresh")
	{
		functions.push_back("vkCmdRefreshObjectsKHR");
		return;
	}
	if (extName == "VK_KHR_synchronization2")
	{
		functions.push_back("vkCmdSetEvent2KHR");
		functions.push_back("vkCmdResetEvent2KHR");
		functions.push_back("vkCmdWaitEvents2KHR");
		functions.push_back("vkCmdPipelineBarrier2KHR");
		functions.push_back("vkCmdWriteTimestamp2KHR");
		functions.push_back("vkQueueSubmit2KHR");
		return;
	}
	if (extName == "VK_EXT_ycbcr_2plane_444_formats")
	{
		return;
	}
	if (extName == "VK_EXT_image_robustness")
	{
		return;
	}
	if (extName == "VK_KHR_copy_commands2")
	{
		functions.push_back("vkCmdCopyBuffer2KHR");
		functions.push_back("vkCmdCopyImage2KHR");
		functions.push_back("vkCmdCopyBufferToImage2KHR");
		functions.push_back("vkCmdCopyImageToBuffer2KHR");
		functions.push_back("vkCmdBlitImage2KHR");
		functions.push_back("vkCmdResolveImage2KHR");
		return;
	}
	if (extName == "VK_EXT_4444_formats")
	{
		return;
	}
	if (extName == "VK_NV_acquire_winrt_display")
	{
		return;
	}
	if (extName == "VK_EXT_vertex_input_dynamic_state")
	{
		functions.push_back("vkCmdSetVertexInputEXT");
		return;
	}
	if (extName == "VK_NV_external_sci_sync")
	{
		functions.push_back("vkGetFenceSciSyncFenceNV");
		functions.push_back("vkGetFenceSciSyncObjNV");
		functions.push_back("vkImportFenceSciSyncFenceNV");
		functions.push_back("vkImportFenceSciSyncObjNV");
		functions.push_back("vkGetSemaphoreSciSyncObjNV");
		functions.push_back("vkImportSemaphoreSciSyncObjNV");
		return;
	}
	if (extName == "VK_NV_external_memory_sci_buf")
	{
		functions.push_back("vkGetMemorySciBufNV");
		return;
	}
	if (extName == "VK_EXT_extended_dynamic_state2")
	{
		functions.push_back("vkCmdSetPatchControlPointsEXT");
		functions.push_back("vkCmdSetRasterizerDiscardEnableEXT");
		functions.push_back("vkCmdSetDepthBiasEnableEXT");
		functions.push_back("vkCmdSetLogicOpEXT");
		functions.push_back("vkCmdSetPrimitiveRestartEnableEXT");
		return;
	}
	if (extName == "VK_EXT_color_write_enable")
	{
		functions.push_back("vkCmdSetColorWriteEnableEXT");
		return;
	}
	if (extName == "VK_EXT_application_parameters")
	{
		return;
	}
	if (extName == "VK_NV_external_sci_sync2")
	{
		functions.push_back("vkCreateSemaphoreSciSyncPoolNV");
		functions.push_back("vkGetFenceSciSyncFenceNV");
		functions.push_back("vkGetFenceSciSyncObjNV");
		functions.push_back("vkImportFenceSciSyncFenceNV");
		functions.push_back("vkImportFenceSciSyncObjNV");
		return;
	}
	if (extName == "VK_EXT_layer_settings")
	{
		return;
	}
	if (extName == "VK_KHR_vertex_attribute_divisor")
	{
		return;
	}
	if (extName == "VK_QNX_external_memory_screen_buffer")
	{
		functions.push_back("vkGetScreenBufferPropertiesQNX");
		return;
	}
	if (extName == "VK_KHR_index_type_uint8")
	{
		return;
	}
	if (extName == "VK_KHR_line_rasterization")
	{
		functions.push_back("vkCmdSetLineStippleKHR");
		return;
	}
	if (extName == "VK_KHR_calibrated_timestamps")
	{
		functions.push_back("vkGetCalibratedTimestampsKHR");
		return;
	}
	if (extName == "VK_NV_device_diagnostic_checkpoints")
	{
		functions.push_back("vkCmdSetCheckpointNV");
		functions.push_back("vkGetQueueCheckpointDataNV");
		// Dependencies: VK_VERSION_1_3,VK_KHR_synchronization2
		if (checkVersion(1, 3, apiVersion) || (checkVersion(1, 3, apiVersion) || extensionIsSupported(vDEP, "VK_KHR_synchronization2"))) {
			functions.push_back("vkGetQueueCheckpointData2NV");
		}
		return;
	}
	if (extName == "VK_KHR_format_feature_flags2")
	{
		return;
	}
	if (extName == "VK_EXT_vertex_attribute_divisor")
	{
		return;
	}
	if (extName == "VK_EXT_global_priority")
	{
		return;
	}
	if (extName == "VK_EXT_calibrated_timestamps")
	{
		functions.push_back("vkGetCalibratedTimestampsEXT");
		return;
	}
	DE_FATAL("Extension name not found");
}

::std::string instanceExtensionNames[] =
{
	"VK_KHR_surface",
	"VK_KHR_display",
	"VK_EXT_direct_mode_display",
	"VK_EXT_display_surface_counter",
	"VK_EXT_swapchain_colorspace",
	"VK_KHR_get_surface_capabilities2",
	"VK_KHR_get_display_properties2",
	"VK_EXT_debug_utils",
	"VK_EXT_validation_features",
	"VK_EXT_headless_surface",
	"VK_EXT_application_parameters",
	"VK_EXT_layer_settings",
};

::std::string deviceExtensionNames[] =
{
	"VK_KHR_swapchain",
	"VK_KHR_display_swapchain",
	"VK_EXT_depth_range_unrestricted",
	"VK_NV_private_vendor_info",
	"VK_EXT_texture_compression_astc_hdr",
	"VK_EXT_astc_decode_mode",
	"VK_KHR_external_memory_fd",
	"VK_KHR_external_semaphore_fd",
	"VK_KHR_incremental_present",
	"VK_EXT_display_control",
	"VK_EXT_discard_rectangles",
	"VK_EXT_conservative_rasterization",
	"VK_EXT_depth_clip_enable",
	"VK_EXT_hdr_metadata",
	"VK_KHR_shared_presentable_image",
	"VK_KHR_external_fence_fd",
	"VK_KHR_performance_query",
	"VK_EXT_external_memory_dma_buf",
	"VK_EXT_queue_family_foreign",
	"VK_EXT_shader_stencil_export",
	"VK_EXT_sample_locations",
	"VK_EXT_blend_operation_advanced",
	"VK_EXT_post_depth_coverage",
	"VK_EXT_image_drm_format_modifier",
	"VK_EXT_filter_cubic",
	"VK_EXT_external_memory_host",
	"VK_KHR_shader_clock",
	"VK_KHR_global_priority",
	"VK_KHR_swapchain_mutable_format",
	"VK_EXT_pci_bus_info",
	"VK_KHR_shader_terminate_invocation",
	"VK_EXT_subgroup_size_control",
	"VK_KHR_fragment_shading_rate",
	"VK_EXT_shader_image_atomic_int64",
	"VK_EXT_memory_budget",
	"VK_EXT_fragment_shader_interlock",
	"VK_EXT_ycbcr_image_arrays",
	"VK_EXT_line_rasterization",
	"VK_EXT_shader_atomic_float",
	"VK_EXT_index_type_uint8",
	"VK_EXT_extended_dynamic_state",
	"VK_EXT_shader_demote_to_helper_invocation",
	"VK_EXT_texel_buffer_alignment",
	"VK_EXT_robustness2",
	"VK_EXT_custom_border_color",
	"VK_KHR_object_refresh",
	"VK_KHR_synchronization2",
	"VK_EXT_ycbcr_2plane_444_formats",
	"VK_EXT_image_robustness",
	"VK_KHR_copy_commands2",
	"VK_EXT_4444_formats",
	"VK_NV_acquire_winrt_display",
	"VK_EXT_vertex_input_dynamic_state",
	"VK_NV_external_sci_sync",
	"VK_NV_external_memory_sci_buf",
	"VK_EXT_extended_dynamic_state2",
	"VK_EXT_color_write_enable",
	"VK_NV_external_sci_sync2",
	"VK_KHR_vertex_attribute_divisor",
	"VK_QNX_external_memory_screen_buffer",
	"VK_KHR_index_type_uint8",
	"VK_KHR_line_rasterization",
	"VK_KHR_calibrated_timestamps",
	"VK_NV_device_diagnostic_checkpoints",
	"VK_KHR_format_feature_flags2",
	"VK_EXT_vertex_attribute_divisor",
	"VK_EXT_global_priority",
	"VK_EXT_calibrated_timestamps",
};
