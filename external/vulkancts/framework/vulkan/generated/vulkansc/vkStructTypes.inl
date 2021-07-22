/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 */
struct VkExtent2D
{
	uint32_t	width;
	uint32_t	height;
};

struct VkExtent3D
{
	uint32_t	width;
	uint32_t	height;
	uint32_t	depth;
};

struct VkOffset2D
{
	int32_t	x;
	int32_t	y;
};

struct VkOffset3D
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
};

struct VkRect2D
{
	VkOffset2D	offset;
	VkExtent2D	extent;
};

struct VkBaseInStructure
{
	VkStructureType					sType;
	const struct VkBaseInStructure*	pNext;
};

struct VkBaseOutStructure
{
	VkStructureType				sType;
	struct VkBaseOutStructure*	pNext;
};

struct VkBufferMemoryBarrier
{
	VkStructureType	sType;
	const void*		pNext;
	VkAccessFlags	srcAccessMask;
	VkAccessFlags	dstAccessMask;
	uint32_t		srcQueueFamilyIndex;
	uint32_t		dstQueueFamilyIndex;
	VkBuffer		buffer;
	VkDeviceSize	offset;
	VkDeviceSize	size;
};

struct VkDispatchIndirectCommand
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	z;
};

struct VkDrawIndexedIndirectCommand
{
	uint32_t	indexCount;
	uint32_t	instanceCount;
	uint32_t	firstIndex;
	int32_t		vertexOffset;
	uint32_t	firstInstance;
};

struct VkDrawIndirectCommand
{
	uint32_t	vertexCount;
	uint32_t	instanceCount;
	uint32_t	firstVertex;
	uint32_t	firstInstance;
};

struct VkImageSubresourceRange
{
	VkImageAspectFlags	aspectMask;
	uint32_t			baseMipLevel;
	uint32_t			levelCount;
	uint32_t			baseArrayLayer;
	uint32_t			layerCount;
};

struct VkImageMemoryBarrier
{
	VkStructureType			sType;
	const void*				pNext;
	VkAccessFlags			srcAccessMask;
	VkAccessFlags			dstAccessMask;
	VkImageLayout			oldLayout;
	VkImageLayout			newLayout;
	uint32_t				srcQueueFamilyIndex;
	uint32_t				dstQueueFamilyIndex;
	VkImage					image;
	VkImageSubresourceRange	subresourceRange;
};

struct VkMemoryBarrier
{
	VkStructureType	sType;
	const void*		pNext;
	VkAccessFlags	srcAccessMask;
	VkAccessFlags	dstAccessMask;
};

struct VkAllocationCallbacks
{
	void*									pUserData;
	PFN_vkAllocationFunction				pfnAllocation;
	PFN_vkReallocationFunction				pfnReallocation;
	PFN_vkFreeFunction						pfnFree;
	PFN_vkInternalAllocationNotification	pfnInternalAllocation;
	PFN_vkInternalFreeNotification			pfnInternalFree;
};

struct VkApplicationInfo
{
	VkStructureType	sType;
	const void*		pNext;
	const char*		pApplicationName;
	uint32_t		applicationVersion;
	const char*		pEngineName;
	uint32_t		engineVersion;
	uint32_t		apiVersion;
};

struct VkFormatProperties
{
	VkFormatFeatureFlags	linearTilingFeatures;
	VkFormatFeatureFlags	optimalTilingFeatures;
	VkFormatFeatureFlags	bufferFeatures;
};

struct VkImageFormatProperties
{
	VkExtent3D			maxExtent;
	uint32_t			maxMipLevels;
	uint32_t			maxArrayLayers;
	VkSampleCountFlags	sampleCounts;
	VkDeviceSize		maxResourceSize;
};

struct VkInstanceCreateInfo
{
	VkStructureType				sType;
	const void*					pNext;
	VkInstanceCreateFlags		flags;
	const VkApplicationInfo*	pApplicationInfo;
	uint32_t					enabledLayerCount;
	const char* const*			ppEnabledLayerNames;
	uint32_t					enabledExtensionCount;
	const char* const*			ppEnabledExtensionNames;
};

struct VkMemoryHeap
{
	VkDeviceSize		size;
	VkMemoryHeapFlags	flags;
};

struct VkMemoryType
{
	VkMemoryPropertyFlags	propertyFlags;
	uint32_t				heapIndex;
};

struct VkPhysicalDeviceFeatures
{
	VkBool32	robustBufferAccess;
	VkBool32	fullDrawIndexUint32;
	VkBool32	imageCubeArray;
	VkBool32	independentBlend;
	VkBool32	geometryShader;
	VkBool32	tessellationShader;
	VkBool32	sampleRateShading;
	VkBool32	dualSrcBlend;
	VkBool32	logicOp;
	VkBool32	multiDrawIndirect;
	VkBool32	drawIndirectFirstInstance;
	VkBool32	depthClamp;
	VkBool32	depthBiasClamp;
	VkBool32	fillModeNonSolid;
	VkBool32	depthBounds;
	VkBool32	wideLines;
	VkBool32	largePoints;
	VkBool32	alphaToOne;
	VkBool32	multiViewport;
	VkBool32	samplerAnisotropy;
	VkBool32	textureCompressionETC2;
	VkBool32	textureCompressionASTC_LDR;
	VkBool32	textureCompressionBC;
	VkBool32	occlusionQueryPrecise;
	VkBool32	pipelineStatisticsQuery;
	VkBool32	vertexPipelineStoresAndAtomics;
	VkBool32	fragmentStoresAndAtomics;
	VkBool32	shaderTessellationAndGeometryPointSize;
	VkBool32	shaderImageGatherExtended;
	VkBool32	shaderStorageImageExtendedFormats;
	VkBool32	shaderStorageImageMultisample;
	VkBool32	shaderStorageImageReadWithoutFormat;
	VkBool32	shaderStorageImageWriteWithoutFormat;
	VkBool32	shaderUniformBufferArrayDynamicIndexing;
	VkBool32	shaderSampledImageArrayDynamicIndexing;
	VkBool32	shaderStorageBufferArrayDynamicIndexing;
	VkBool32	shaderStorageImageArrayDynamicIndexing;
	VkBool32	shaderClipDistance;
	VkBool32	shaderCullDistance;
	VkBool32	shaderFloat64;
	VkBool32	shaderInt64;
	VkBool32	shaderInt16;
	VkBool32	shaderResourceResidency;
	VkBool32	shaderResourceMinLod;
	VkBool32	sparseBinding;
	VkBool32	sparseResidencyBuffer;
	VkBool32	sparseResidencyImage2D;
	VkBool32	sparseResidencyImage3D;
	VkBool32	sparseResidency2Samples;
	VkBool32	sparseResidency4Samples;
	VkBool32	sparseResidency8Samples;
	VkBool32	sparseResidency16Samples;
	VkBool32	sparseResidencyAliased;
	VkBool32	variableMultisampleRate;
	VkBool32	inheritedQueries;
};

struct VkPhysicalDeviceLimits
{
	uint32_t			maxImageDimension1D;
	uint32_t			maxImageDimension2D;
	uint32_t			maxImageDimension3D;
	uint32_t			maxImageDimensionCube;
	uint32_t			maxImageArrayLayers;
	uint32_t			maxTexelBufferElements;
	uint32_t			maxUniformBufferRange;
	uint32_t			maxStorageBufferRange;
	uint32_t			maxPushConstantsSize;
	uint32_t			maxMemoryAllocationCount;
	uint32_t			maxSamplerAllocationCount;
	VkDeviceSize		bufferImageGranularity;
	VkDeviceSize		sparseAddressSpaceSize;
	uint32_t			maxBoundDescriptorSets;
	uint32_t			maxPerStageDescriptorSamplers;
	uint32_t			maxPerStageDescriptorUniformBuffers;
	uint32_t			maxPerStageDescriptorStorageBuffers;
	uint32_t			maxPerStageDescriptorSampledImages;
	uint32_t			maxPerStageDescriptorStorageImages;
	uint32_t			maxPerStageDescriptorInputAttachments;
	uint32_t			maxPerStageResources;
	uint32_t			maxDescriptorSetSamplers;
	uint32_t			maxDescriptorSetUniformBuffers;
	uint32_t			maxDescriptorSetUniformBuffersDynamic;
	uint32_t			maxDescriptorSetStorageBuffers;
	uint32_t			maxDescriptorSetStorageBuffersDynamic;
	uint32_t			maxDescriptorSetSampledImages;
	uint32_t			maxDescriptorSetStorageImages;
	uint32_t			maxDescriptorSetInputAttachments;
	uint32_t			maxVertexInputAttributes;
	uint32_t			maxVertexInputBindings;
	uint32_t			maxVertexInputAttributeOffset;
	uint32_t			maxVertexInputBindingStride;
	uint32_t			maxVertexOutputComponents;
	uint32_t			maxTessellationGenerationLevel;
	uint32_t			maxTessellationPatchSize;
	uint32_t			maxTessellationControlPerVertexInputComponents;
	uint32_t			maxTessellationControlPerVertexOutputComponents;
	uint32_t			maxTessellationControlPerPatchOutputComponents;
	uint32_t			maxTessellationControlTotalOutputComponents;
	uint32_t			maxTessellationEvaluationInputComponents;
	uint32_t			maxTessellationEvaluationOutputComponents;
	uint32_t			maxGeometryShaderInvocations;
	uint32_t			maxGeometryInputComponents;
	uint32_t			maxGeometryOutputComponents;
	uint32_t			maxGeometryOutputVertices;
	uint32_t			maxGeometryTotalOutputComponents;
	uint32_t			maxFragmentInputComponents;
	uint32_t			maxFragmentOutputAttachments;
	uint32_t			maxFragmentDualSrcAttachments;
	uint32_t			maxFragmentCombinedOutputResources;
	uint32_t			maxComputeSharedMemorySize;
	uint32_t			maxComputeWorkGroupCount[3];
	uint32_t			maxComputeWorkGroupInvocations;
	uint32_t			maxComputeWorkGroupSize[3];
	uint32_t			subPixelPrecisionBits;
	uint32_t			subTexelPrecisionBits;
	uint32_t			mipmapPrecisionBits;
	uint32_t			maxDrawIndexedIndexValue;
	uint32_t			maxDrawIndirectCount;
	float				maxSamplerLodBias;
	float				maxSamplerAnisotropy;
	uint32_t			maxViewports;
	uint32_t			maxViewportDimensions[2];
	float				viewportBoundsRange[2];
	uint32_t			viewportSubPixelBits;
	size_t				minMemoryMapAlignment;
	VkDeviceSize		minTexelBufferOffsetAlignment;
	VkDeviceSize		minUniformBufferOffsetAlignment;
	VkDeviceSize		minStorageBufferOffsetAlignment;
	int32_t				minTexelOffset;
	uint32_t			maxTexelOffset;
	int32_t				minTexelGatherOffset;
	uint32_t			maxTexelGatherOffset;
	float				minInterpolationOffset;
	float				maxInterpolationOffset;
	uint32_t			subPixelInterpolationOffsetBits;
	uint32_t			maxFramebufferWidth;
	uint32_t			maxFramebufferHeight;
	uint32_t			maxFramebufferLayers;
	VkSampleCountFlags	framebufferColorSampleCounts;
	VkSampleCountFlags	framebufferDepthSampleCounts;
	VkSampleCountFlags	framebufferStencilSampleCounts;
	VkSampleCountFlags	framebufferNoAttachmentsSampleCounts;
	uint32_t			maxColorAttachments;
	VkSampleCountFlags	sampledImageColorSampleCounts;
	VkSampleCountFlags	sampledImageIntegerSampleCounts;
	VkSampleCountFlags	sampledImageDepthSampleCounts;
	VkSampleCountFlags	sampledImageStencilSampleCounts;
	VkSampleCountFlags	storageImageSampleCounts;
	uint32_t			maxSampleMaskWords;
	VkBool32			timestampComputeAndGraphics;
	float				timestampPeriod;
	uint32_t			maxClipDistances;
	uint32_t			maxCullDistances;
	uint32_t			maxCombinedClipAndCullDistances;
	uint32_t			discreteQueuePriorities;
	float				pointSizeRange[2];
	float				lineWidthRange[2];
	float				pointSizeGranularity;
	float				lineWidthGranularity;
	VkBool32			strictLines;
	VkBool32			standardSampleLocations;
	VkDeviceSize		optimalBufferCopyOffsetAlignment;
	VkDeviceSize		optimalBufferCopyRowPitchAlignment;
	VkDeviceSize		nonCoherentAtomSize;
};

struct VkPhysicalDeviceMemoryProperties
{
	uint32_t		memoryTypeCount;
	VkMemoryType	memoryTypes[VK_MAX_MEMORY_TYPES];
	uint32_t		memoryHeapCount;
	VkMemoryHeap	memoryHeaps[VK_MAX_MEMORY_HEAPS];
};

struct VkPhysicalDeviceSparseProperties
{
	VkBool32	residencyStandard2DBlockShape;
	VkBool32	residencyStandard2DMultisampleBlockShape;
	VkBool32	residencyStandard3DBlockShape;
	VkBool32	residencyAlignedMipSize;
	VkBool32	residencyNonResidentStrict;
};

struct VkPhysicalDeviceProperties
{
	uint32_t							apiVersion;
	uint32_t							driverVersion;
	uint32_t							vendorID;
	uint32_t							deviceID;
	VkPhysicalDeviceType				deviceType;
	char								deviceName[VK_MAX_PHYSICAL_DEVICE_NAME_SIZE];
	uint8_t								pipelineCacheUUID[VK_UUID_SIZE];
	VkPhysicalDeviceLimits				limits;
	VkPhysicalDeviceSparseProperties	sparseProperties;
};

struct VkQueueFamilyProperties
{
	VkQueueFlags	queueFlags;
	uint32_t		queueCount;
	uint32_t		timestampValidBits;
	VkExtent3D		minImageTransferGranularity;
};

struct VkDeviceQueueCreateInfo
{
	VkStructureType				sType;
	const void*					pNext;
	VkDeviceQueueCreateFlags	flags;
	uint32_t					queueFamilyIndex;
	uint32_t					queueCount;
	const float*				pQueuePriorities;
};

struct VkDeviceCreateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkDeviceCreateFlags				flags;
	uint32_t						queueCreateInfoCount;
	const VkDeviceQueueCreateInfo*	pQueueCreateInfos;
	uint32_t						enabledLayerCount;
	const char* const*				ppEnabledLayerNames;
	uint32_t						enabledExtensionCount;
	const char* const*				ppEnabledExtensionNames;
	const VkPhysicalDeviceFeatures*	pEnabledFeatures;
};

struct VkExtensionProperties
{
	char		extensionName[VK_MAX_EXTENSION_NAME_SIZE];
	uint32_t	specVersion;
};

struct VkLayerProperties
{
	char		layerName[VK_MAX_EXTENSION_NAME_SIZE];
	uint32_t	specVersion;
	uint32_t	implementationVersion;
	char		description[VK_MAX_DESCRIPTION_SIZE];
};

struct VkSubmitInfo
{
	VkStructureType				sType;
	const void*					pNext;
	uint32_t					waitSemaphoreCount;
	const VkSemaphore*			pWaitSemaphores;
	const VkPipelineStageFlags*	pWaitDstStageMask;
	uint32_t					commandBufferCount;
	const VkCommandBuffer*		pCommandBuffers;
	uint32_t					signalSemaphoreCount;
	const VkSemaphore*			pSignalSemaphores;
};

struct VkMappedMemoryRange
{
	VkStructureType	sType;
	const void*		pNext;
	VkDeviceMemory	memory;
	VkDeviceSize	offset;
	VkDeviceSize	size;
};

struct VkMemoryAllocateInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkDeviceSize	allocationSize;
	uint32_t		memoryTypeIndex;
};

struct VkMemoryRequirements
{
	VkDeviceSize	size;
	VkDeviceSize	alignment;
	uint32_t		memoryTypeBits;
};

struct VkImageSubresource
{
	VkImageAspectFlags	aspectMask;
	uint32_t			mipLevel;
	uint32_t			arrayLayer;
};

struct VkFenceCreateInfo
{
	VkStructureType		sType;
	const void*			pNext;
	VkFenceCreateFlags	flags;
};

struct VkSemaphoreCreateInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkSemaphoreCreateFlags	flags;
};

struct VkEventCreateInfo
{
	VkStructureType		sType;
	const void*			pNext;
	VkEventCreateFlags	flags;
};

struct VkQueryPoolCreateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkQueryPoolCreateFlags			flags;
	VkQueryType						queryType;
	uint32_t						queryCount;
	VkQueryPipelineStatisticFlags	pipelineStatistics;
};

struct VkBufferCreateInfo
{
	VkStructureType		sType;
	const void*			pNext;
	VkBufferCreateFlags	flags;
	VkDeviceSize		size;
	VkBufferUsageFlags	usage;
	VkSharingMode		sharingMode;
	uint32_t			queueFamilyIndexCount;
	const uint32_t*		pQueueFamilyIndices;
};

struct VkBufferViewCreateInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkBufferViewCreateFlags	flags;
	VkBuffer				buffer;
	VkFormat				format;
	VkDeviceSize			offset;
	VkDeviceSize			range;
};

struct VkImageCreateInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkImageCreateFlags		flags;
	VkImageType				imageType;
	VkFormat				format;
	VkExtent3D				extent;
	uint32_t				mipLevels;
	uint32_t				arrayLayers;
	VkSampleCountFlagBits	samples;
	VkImageTiling			tiling;
	VkImageUsageFlags		usage;
	VkSharingMode			sharingMode;
	uint32_t				queueFamilyIndexCount;
	const uint32_t*			pQueueFamilyIndices;
	VkImageLayout			initialLayout;
};

struct VkSubresourceLayout
{
	VkDeviceSize	offset;
	VkDeviceSize	size;
	VkDeviceSize	rowPitch;
	VkDeviceSize	arrayPitch;
	VkDeviceSize	depthPitch;
};

struct VkComponentMapping
{
	VkComponentSwizzle	r;
	VkComponentSwizzle	g;
	VkComponentSwizzle	b;
	VkComponentSwizzle	a;
};

struct VkImageViewCreateInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkImageViewCreateFlags	flags;
	VkImage					image;
	VkImageViewType			viewType;
	VkFormat				format;
	VkComponentMapping		components;
	VkImageSubresourceRange	subresourceRange;
};

struct VkPipelineCacheCreateInfo
{
	VkStructureType				sType;
	const void*					pNext;
	VkPipelineCacheCreateFlags	flags;
	size_t						initialDataSize;
	const void*					pInitialData;
};

struct VkSpecializationMapEntry
{
	uint32_t	constantID;
	uint32_t	offset;
	size_t		size;
};

struct VkSpecializationInfo
{
	uint32_t						mapEntryCount;
	const VkSpecializationMapEntry*	pMapEntries;
	size_t							dataSize;
	const void*						pData;
};

struct VkPipelineShaderStageCreateInfo
{
	VkStructureType						sType;
	const void*							pNext;
	VkPipelineShaderStageCreateFlags	flags;
	VkShaderStageFlagBits				stage;
	VkShaderModule						module;
	const char*							pName;
	const VkSpecializationInfo*			pSpecializationInfo;
};

struct VkComputePipelineCreateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkPipelineCreateFlags			flags;
	VkPipelineShaderStageCreateInfo	stage;
	VkPipelineLayout				layout;
	VkPipeline						basePipelineHandle;
	int32_t							basePipelineIndex;
};

struct VkVertexInputBindingDescription
{
	uint32_t			binding;
	uint32_t			stride;
	VkVertexInputRate	inputRate;
};

struct VkVertexInputAttributeDescription
{
	uint32_t	location;
	uint32_t	binding;
	VkFormat	format;
	uint32_t	offset;
};

struct VkPipelineVertexInputStateCreateInfo
{
	VkStructureType								sType;
	const void*									pNext;
	VkPipelineVertexInputStateCreateFlags		flags;
	uint32_t									vertexBindingDescriptionCount;
	const VkVertexInputBindingDescription*		pVertexBindingDescriptions;
	uint32_t									vertexAttributeDescriptionCount;
	const VkVertexInputAttributeDescription*	pVertexAttributeDescriptions;
};

struct VkPipelineInputAssemblyStateCreateInfo
{
	VkStructureType							sType;
	const void*								pNext;
	VkPipelineInputAssemblyStateCreateFlags	flags;
	VkPrimitiveTopology						topology;
	VkBool32								primitiveRestartEnable;
};

struct VkPipelineTessellationStateCreateInfo
{
	VkStructureType							sType;
	const void*								pNext;
	VkPipelineTessellationStateCreateFlags	flags;
	uint32_t								patchControlPoints;
};

struct VkViewport
{
	float	x;
	float	y;
	float	width;
	float	height;
	float	minDepth;
	float	maxDepth;
};

struct VkPipelineViewportStateCreateInfo
{
	VkStructureType						sType;
	const void*							pNext;
	VkPipelineViewportStateCreateFlags	flags;
	uint32_t							viewportCount;
	const VkViewport*					pViewports;
	uint32_t							scissorCount;
	const VkRect2D*						pScissors;
};

struct VkPipelineRasterizationStateCreateInfo
{
	VkStructureType							sType;
	const void*								pNext;
	VkPipelineRasterizationStateCreateFlags	flags;
	VkBool32								depthClampEnable;
	VkBool32								rasterizerDiscardEnable;
	VkPolygonMode							polygonMode;
	VkCullModeFlags							cullMode;
	VkFrontFace								frontFace;
	VkBool32								depthBiasEnable;
	float									depthBiasConstantFactor;
	float									depthBiasClamp;
	float									depthBiasSlopeFactor;
	float									lineWidth;
};

struct VkPipelineMultisampleStateCreateInfo
{
	VkStructureType							sType;
	const void*								pNext;
	VkPipelineMultisampleStateCreateFlags	flags;
	VkSampleCountFlagBits					rasterizationSamples;
	VkBool32								sampleShadingEnable;
	float									minSampleShading;
	const VkSampleMask*						pSampleMask;
	VkBool32								alphaToCoverageEnable;
	VkBool32								alphaToOneEnable;
};

struct VkStencilOpState
{
	VkStencilOp	failOp;
	VkStencilOp	passOp;
	VkStencilOp	depthFailOp;
	VkCompareOp	compareOp;
	uint32_t	compareMask;
	uint32_t	writeMask;
	uint32_t	reference;
};

struct VkPipelineDepthStencilStateCreateInfo
{
	VkStructureType							sType;
	const void*								pNext;
	VkPipelineDepthStencilStateCreateFlags	flags;
	VkBool32								depthTestEnable;
	VkBool32								depthWriteEnable;
	VkCompareOp								depthCompareOp;
	VkBool32								depthBoundsTestEnable;
	VkBool32								stencilTestEnable;
	VkStencilOpState						front;
	VkStencilOpState						back;
	float									minDepthBounds;
	float									maxDepthBounds;
};

struct VkPipelineColorBlendAttachmentState
{
	VkBool32				blendEnable;
	VkBlendFactor			srcColorBlendFactor;
	VkBlendFactor			dstColorBlendFactor;
	VkBlendOp				colorBlendOp;
	VkBlendFactor			srcAlphaBlendFactor;
	VkBlendFactor			dstAlphaBlendFactor;
	VkBlendOp				alphaBlendOp;
	VkColorComponentFlags	colorWriteMask;
};

struct VkPipelineColorBlendStateCreateInfo
{
	VkStructureType								sType;
	const void*									pNext;
	VkPipelineColorBlendStateCreateFlags		flags;
	VkBool32									logicOpEnable;
	VkLogicOp									logicOp;
	uint32_t									attachmentCount;
	const VkPipelineColorBlendAttachmentState*	pAttachments;
	float										blendConstants[4];
};

struct VkPipelineDynamicStateCreateInfo
{
	VkStructureType						sType;
	const void*							pNext;
	VkPipelineDynamicStateCreateFlags	flags;
	uint32_t							dynamicStateCount;
	const VkDynamicState*				pDynamicStates;
};

struct VkGraphicsPipelineCreateInfo
{
	VkStructureType									sType;
	const void*										pNext;
	VkPipelineCreateFlags							flags;
	uint32_t										stageCount;
	const VkPipelineShaderStageCreateInfo*			pStages;
	const VkPipelineVertexInputStateCreateInfo*		pVertexInputState;
	const VkPipelineInputAssemblyStateCreateInfo*	pInputAssemblyState;
	const VkPipelineTessellationStateCreateInfo*	pTessellationState;
	const VkPipelineViewportStateCreateInfo*		pViewportState;
	const VkPipelineRasterizationStateCreateInfo*	pRasterizationState;
	const VkPipelineMultisampleStateCreateInfo*		pMultisampleState;
	const VkPipelineDepthStencilStateCreateInfo*	pDepthStencilState;
	const VkPipelineColorBlendStateCreateInfo*		pColorBlendState;
	const VkPipelineDynamicStateCreateInfo*			pDynamicState;
	VkPipelineLayout								layout;
	VkRenderPass									renderPass;
	uint32_t										subpass;
	VkPipeline										basePipelineHandle;
	int32_t											basePipelineIndex;
};

struct VkPushConstantRange
{
	VkShaderStageFlags	stageFlags;
	uint32_t			offset;
	uint32_t			size;
};

struct VkPipelineLayoutCreateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkPipelineLayoutCreateFlags		flags;
	uint32_t						setLayoutCount;
	const VkDescriptorSetLayout*	pSetLayouts;
	uint32_t						pushConstantRangeCount;
	const VkPushConstantRange*		pPushConstantRanges;
};

struct VkSamplerCreateInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkSamplerCreateFlags	flags;
	VkFilter				magFilter;
	VkFilter				minFilter;
	VkSamplerMipmapMode		mipmapMode;
	VkSamplerAddressMode	addressModeU;
	VkSamplerAddressMode	addressModeV;
	VkSamplerAddressMode	addressModeW;
	float					mipLodBias;
	VkBool32				anisotropyEnable;
	float					maxAnisotropy;
	VkBool32				compareEnable;
	VkCompareOp				compareOp;
	float					minLod;
	float					maxLod;
	VkBorderColor			borderColor;
	VkBool32				unnormalizedCoordinates;
};

struct VkCopyDescriptorSet
{
	VkStructureType	sType;
	const void*		pNext;
	VkDescriptorSet	srcSet;
	uint32_t		srcBinding;
	uint32_t		srcArrayElement;
	VkDescriptorSet	dstSet;
	uint32_t		dstBinding;
	uint32_t		dstArrayElement;
	uint32_t		descriptorCount;
};

struct VkDescriptorBufferInfo
{
	VkBuffer		buffer;
	VkDeviceSize	offset;
	VkDeviceSize	range;
};

struct VkDescriptorImageInfo
{
	VkSampler		sampler;
	VkImageView		imageView;
	VkImageLayout	imageLayout;
};

struct VkDescriptorPoolSize
{
	VkDescriptorType	type;
	uint32_t			descriptorCount;
};

struct VkDescriptorPoolCreateInfo
{
	VkStructureType				sType;
	const void*					pNext;
	VkDescriptorPoolCreateFlags	flags;
	uint32_t					maxSets;
	uint32_t					poolSizeCount;
	const VkDescriptorPoolSize*	pPoolSizes;
};

struct VkDescriptorSetAllocateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkDescriptorPool				descriptorPool;
	uint32_t						descriptorSetCount;
	const VkDescriptorSetLayout*	pSetLayouts;
};

struct VkDescriptorSetLayoutBinding
{
	uint32_t			binding;
	VkDescriptorType	descriptorType;
	uint32_t			descriptorCount;
	VkShaderStageFlags	stageFlags;
	const VkSampler*	pImmutableSamplers;
};

struct VkDescriptorSetLayoutCreateInfo
{
	VkStructureType						sType;
	const void*							pNext;
	VkDescriptorSetLayoutCreateFlags	flags;
	uint32_t							bindingCount;
	const VkDescriptorSetLayoutBinding*	pBindings;
};

struct VkWriteDescriptorSet
{
	VkStructureType					sType;
	const void*						pNext;
	VkDescriptorSet					dstSet;
	uint32_t						dstBinding;
	uint32_t						dstArrayElement;
	uint32_t						descriptorCount;
	VkDescriptorType				descriptorType;
	const VkDescriptorImageInfo*	pImageInfo;
	const VkDescriptorBufferInfo*	pBufferInfo;
	const VkBufferView*				pTexelBufferView;
};

struct VkAttachmentDescription
{
	VkAttachmentDescriptionFlags	flags;
	VkFormat						format;
	VkSampleCountFlagBits			samples;
	VkAttachmentLoadOp				loadOp;
	VkAttachmentStoreOp				storeOp;
	VkAttachmentLoadOp				stencilLoadOp;
	VkAttachmentStoreOp				stencilStoreOp;
	VkImageLayout					initialLayout;
	VkImageLayout					finalLayout;
};

struct VkAttachmentReference
{
	uint32_t		attachment;
	VkImageLayout	layout;
};

struct VkFramebufferCreateInfo
{
	VkStructureType				sType;
	const void*					pNext;
	VkFramebufferCreateFlags	flags;
	VkRenderPass				renderPass;
	uint32_t					attachmentCount;
	const VkImageView*			pAttachments;
	uint32_t					width;
	uint32_t					height;
	uint32_t					layers;
};

struct VkSubpassDescription
{
	VkSubpassDescriptionFlags		flags;
	VkPipelineBindPoint				pipelineBindPoint;
	uint32_t						inputAttachmentCount;
	const VkAttachmentReference*	pInputAttachments;
	uint32_t						colorAttachmentCount;
	const VkAttachmentReference*	pColorAttachments;
	const VkAttachmentReference*	pResolveAttachments;
	const VkAttachmentReference*	pDepthStencilAttachment;
	uint32_t						preserveAttachmentCount;
	const uint32_t*					pPreserveAttachments;
};

struct VkSubpassDependency
{
	uint32_t				srcSubpass;
	uint32_t				dstSubpass;
	VkPipelineStageFlags	srcStageMask;
	VkPipelineStageFlags	dstStageMask;
	VkAccessFlags			srcAccessMask;
	VkAccessFlags			dstAccessMask;
	VkDependencyFlags		dependencyFlags;
};

struct VkRenderPassCreateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkRenderPassCreateFlags			flags;
	uint32_t						attachmentCount;
	const VkAttachmentDescription*	pAttachments;
	uint32_t						subpassCount;
	const VkSubpassDescription*		pSubpasses;
	uint32_t						dependencyCount;
	const VkSubpassDependency*		pDependencies;
};

struct VkCommandPoolCreateInfo
{
	VkStructureType				sType;
	const void*					pNext;
	VkCommandPoolCreateFlags	flags;
	uint32_t					queueFamilyIndex;
};

struct VkCommandBufferAllocateInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkCommandPool			commandPool;
	VkCommandBufferLevel	level;
	uint32_t				commandBufferCount;
};

struct VkCommandBufferInheritanceInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkRenderPass					renderPass;
	uint32_t						subpass;
	VkFramebuffer					framebuffer;
	VkBool32						occlusionQueryEnable;
	VkQueryControlFlags				queryFlags;
	VkQueryPipelineStatisticFlags	pipelineStatistics;
};

struct VkCommandBufferBeginInfo
{
	VkStructureType							sType;
	const void*								pNext;
	VkCommandBufferUsageFlags				flags;
	const VkCommandBufferInheritanceInfo*	pInheritanceInfo;
};

struct VkBufferCopy
{
	VkDeviceSize	srcOffset;
	VkDeviceSize	dstOffset;
	VkDeviceSize	size;
};

struct VkImageSubresourceLayers
{
	VkImageAspectFlags	aspectMask;
	uint32_t			mipLevel;
	uint32_t			baseArrayLayer;
	uint32_t			layerCount;
};

struct VkBufferImageCopy
{
	VkDeviceSize				bufferOffset;
	uint32_t					bufferRowLength;
	uint32_t					bufferImageHeight;
	VkImageSubresourceLayers	imageSubresource;
	VkOffset3D					imageOffset;
	VkExtent3D					imageExtent;
};

union VkClearColorValue
{
	float		float32[4];
	int32_t		int32[4];
	uint32_t	uint32[4];
};

struct VkClearDepthStencilValue
{
	float		depth;
	uint32_t	stencil;
};

union VkClearValue
{
	VkClearColorValue			color;
	VkClearDepthStencilValue	depthStencil;
};

struct VkClearAttachment
{
	VkImageAspectFlags	aspectMask;
	uint32_t			colorAttachment;
	VkClearValue		clearValue;
};

struct VkClearRect
{
	VkRect2D	rect;
	uint32_t	baseArrayLayer;
	uint32_t	layerCount;
};

struct VkImageBlit
{
	VkImageSubresourceLayers	srcSubresource;
	VkOffset3D					srcOffsets[2];
	VkImageSubresourceLayers	dstSubresource;
	VkOffset3D					dstOffsets[2];
};

struct VkImageCopy
{
	VkImageSubresourceLayers	srcSubresource;
	VkOffset3D					srcOffset;
	VkImageSubresourceLayers	dstSubresource;
	VkOffset3D					dstOffset;
	VkExtent3D					extent;
};

struct VkImageResolve
{
	VkImageSubresourceLayers	srcSubresource;
	VkOffset3D					srcOffset;
	VkImageSubresourceLayers	dstSubresource;
	VkOffset3D					dstOffset;
	VkExtent3D					extent;
};

struct VkRenderPassBeginInfo
{
	VkStructureType		sType;
	const void*			pNext;
	VkRenderPass		renderPass;
	VkFramebuffer		framebuffer;
	VkRect2D			renderArea;
	uint32_t			clearValueCount;
	const VkClearValue*	pClearValues;
};

struct VkPhysicalDeviceSubgroupProperties
{
	VkStructureType			sType;
	void*					pNext;
	uint32_t				subgroupSize;
	VkShaderStageFlags		supportedStages;
	VkSubgroupFeatureFlags	supportedOperations;
	VkBool32				quadOperationsInAllStages;
};

struct VkBindBufferMemoryInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkBuffer		buffer;
	VkDeviceMemory	memory;
	VkDeviceSize	memoryOffset;
};

struct VkBindImageMemoryInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkImage			image;
	VkDeviceMemory	memory;
	VkDeviceSize	memoryOffset;
};

struct VkPhysicalDevice16BitStorageFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		storageBuffer16BitAccess;
	VkBool32		uniformAndStorageBuffer16BitAccess;
	VkBool32		storagePushConstant16;
	VkBool32		storageInputOutput16;
};

struct VkMemoryDedicatedRequirements
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		prefersDedicatedAllocation;
	VkBool32		requiresDedicatedAllocation;
};

struct VkMemoryDedicatedAllocateInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkImage			image;
	VkBuffer		buffer;
};

struct VkMemoryAllocateFlagsInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkMemoryAllocateFlags	flags;
	uint32_t				deviceMask;
};

struct VkDeviceGroupRenderPassBeginInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		deviceMask;
	uint32_t		deviceRenderAreaCount;
	const VkRect2D*	pDeviceRenderAreas;
};

struct VkDeviceGroupCommandBufferBeginInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		deviceMask;
};

struct VkDeviceGroupSubmitInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		waitSemaphoreCount;
	const uint32_t*	pWaitSemaphoreDeviceIndices;
	uint32_t		commandBufferCount;
	const uint32_t*	pCommandBufferDeviceMasks;
	uint32_t		signalSemaphoreCount;
	const uint32_t*	pSignalSemaphoreDeviceIndices;
};

struct VkBindBufferMemoryDeviceGroupInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		deviceIndexCount;
	const uint32_t*	pDeviceIndices;
};

struct VkBindImageMemoryDeviceGroupInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		deviceIndexCount;
	const uint32_t*	pDeviceIndices;
	uint32_t		splitInstanceBindRegionCount;
	const VkRect2D*	pSplitInstanceBindRegions;
};

struct VkPhysicalDeviceGroupProperties
{
	VkStructureType		sType;
	void*				pNext;
	uint32_t			physicalDeviceCount;
	VkPhysicalDevice	physicalDevices[VK_MAX_DEVICE_GROUP_SIZE];
	VkBool32			subsetAllocation;
};

struct VkDeviceGroupDeviceCreateInfo
{
	VkStructureType			sType;
	const void*				pNext;
	uint32_t				physicalDeviceCount;
	const VkPhysicalDevice*	pPhysicalDevices;
};

struct VkBufferMemoryRequirementsInfo2
{
	VkStructureType	sType;
	const void*		pNext;
	VkBuffer		buffer;
};

struct VkImageMemoryRequirementsInfo2
{
	VkStructureType	sType;
	const void*		pNext;
	VkImage			image;
};

struct VkMemoryRequirements2
{
	VkStructureType			sType;
	void*					pNext;
	VkMemoryRequirements	memoryRequirements;
};

struct VkPhysicalDeviceFeatures2
{
	VkStructureType				sType;
	void*						pNext;
	VkPhysicalDeviceFeatures	features;
};

struct VkPhysicalDeviceProperties2
{
	VkStructureType				sType;
	void*						pNext;
	VkPhysicalDeviceProperties	properties;
};

struct VkFormatProperties2
{
	VkStructureType		sType;
	void*				pNext;
	VkFormatProperties	formatProperties;
};

struct VkImageFormatProperties2
{
	VkStructureType			sType;
	void*					pNext;
	VkImageFormatProperties	imageFormatProperties;
};

struct VkPhysicalDeviceImageFormatInfo2
{
	VkStructureType		sType;
	const void*			pNext;
	VkFormat			format;
	VkImageType			type;
	VkImageTiling		tiling;
	VkImageUsageFlags	usage;
	VkImageCreateFlags	flags;
};

struct VkQueueFamilyProperties2
{
	VkStructureType			sType;
	void*					pNext;
	VkQueueFamilyProperties	queueFamilyProperties;
};

struct VkPhysicalDeviceMemoryProperties2
{
	VkStructureType						sType;
	void*								pNext;
	VkPhysicalDeviceMemoryProperties	memoryProperties;
};

struct VkPhysicalDevicePointClippingProperties
{
	VkStructureType			sType;
	void*					pNext;
	VkPointClippingBehavior	pointClippingBehavior;
};

struct VkInputAttachmentAspectReference
{
	uint32_t			subpass;
	uint32_t			inputAttachmentIndex;
	VkImageAspectFlags	aspectMask;
};

struct VkRenderPassInputAttachmentAspectCreateInfo
{
	VkStructureType							sType;
	const void*								pNext;
	uint32_t								aspectReferenceCount;
	const VkInputAttachmentAspectReference*	pAspectReferences;
};

struct VkImageViewUsageCreateInfo
{
	VkStructureType		sType;
	const void*			pNext;
	VkImageUsageFlags	usage;
};

struct VkPipelineTessellationDomainOriginStateCreateInfo
{
	VkStructureType				sType;
	const void*					pNext;
	VkTessellationDomainOrigin	domainOrigin;
};

struct VkRenderPassMultiviewCreateInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		subpassCount;
	const uint32_t*	pViewMasks;
	uint32_t		dependencyCount;
	const int32_t*	pViewOffsets;
	uint32_t		correlationMaskCount;
	const uint32_t*	pCorrelationMasks;
};

struct VkPhysicalDeviceMultiviewFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		multiview;
	VkBool32		multiviewGeometryShader;
	VkBool32		multiviewTessellationShader;
};

struct VkPhysicalDeviceMultiviewProperties
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		maxMultiviewViewCount;
	uint32_t		maxMultiviewInstanceIndex;
};

struct VkPhysicalDeviceVariablePointersFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		variablePointersStorageBuffer;
	VkBool32		variablePointers;
};

struct VkPhysicalDeviceProtectedMemoryFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		protectedMemory;
};

struct VkPhysicalDeviceProtectedMemoryProperties
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		protectedNoFault;
};

struct VkDeviceQueueInfo2
{
	VkStructureType				sType;
	const void*					pNext;
	VkDeviceQueueCreateFlags	flags;
	uint32_t					queueFamilyIndex;
	uint32_t					queueIndex;
};

struct VkProtectedSubmitInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkBool32		protectedSubmit;
};

struct VkSamplerYcbcrConversionCreateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkFormat						format;
	VkSamplerYcbcrModelConversion	ycbcrModel;
	VkSamplerYcbcrRange				ycbcrRange;
	VkComponentMapping				components;
	VkChromaLocation				xChromaOffset;
	VkChromaLocation				yChromaOffset;
	VkFilter						chromaFilter;
	VkBool32						forceExplicitReconstruction;
};

struct VkSamplerYcbcrConversionInfo
{
	VkStructureType				sType;
	const void*					pNext;
	VkSamplerYcbcrConversion	conversion;
};

struct VkBindImagePlaneMemoryInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkImageAspectFlagBits	planeAspect;
};

struct VkImagePlaneMemoryRequirementsInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkImageAspectFlagBits	planeAspect;
};

struct VkPhysicalDeviceSamplerYcbcrConversionFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		samplerYcbcrConversion;
};

struct VkSamplerYcbcrConversionImageFormatProperties
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		combinedImageSamplerDescriptorCount;
};

struct VkExternalMemoryProperties
{
	VkExternalMemoryFeatureFlags	externalMemoryFeatures;
	VkExternalMemoryHandleTypeFlags	exportFromImportedHandleTypes;
	VkExternalMemoryHandleTypeFlags	compatibleHandleTypes;
};

struct VkPhysicalDeviceExternalImageFormatInfo
{
	VkStructureType						sType;
	const void*							pNext;
	VkExternalMemoryHandleTypeFlagBits	handleType;
};

struct VkExternalImageFormatProperties
{
	VkStructureType				sType;
	void*						pNext;
	VkExternalMemoryProperties	externalMemoryProperties;
};

struct VkPhysicalDeviceExternalBufferInfo
{
	VkStructureType						sType;
	const void*							pNext;
	VkBufferCreateFlags					flags;
	VkBufferUsageFlags					usage;
	VkExternalMemoryHandleTypeFlagBits	handleType;
};

struct VkExternalBufferProperties
{
	VkStructureType				sType;
	void*						pNext;
	VkExternalMemoryProperties	externalMemoryProperties;
};

struct VkPhysicalDeviceIDProperties
{
	VkStructureType	sType;
	void*			pNext;
	uint8_t			deviceUUID[VK_UUID_SIZE];
	uint8_t			driverUUID[VK_UUID_SIZE];
	uint8_t			deviceLUID[VK_LUID_SIZE];
	uint32_t		deviceNodeMask;
	VkBool32		deviceLUIDValid;
};

struct VkExternalMemoryImageCreateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkExternalMemoryHandleTypeFlags	handleTypes;
};

struct VkExternalMemoryBufferCreateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkExternalMemoryHandleTypeFlags	handleTypes;
};

struct VkExportMemoryAllocateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkExternalMemoryHandleTypeFlags	handleTypes;
};

struct VkPhysicalDeviceExternalFenceInfo
{
	VkStructureType						sType;
	const void*							pNext;
	VkExternalFenceHandleTypeFlagBits	handleType;
};

struct VkExternalFenceProperties
{
	VkStructureType					sType;
	void*							pNext;
	VkExternalFenceHandleTypeFlags	exportFromImportedHandleTypes;
	VkExternalFenceHandleTypeFlags	compatibleHandleTypes;
	VkExternalFenceFeatureFlags		externalFenceFeatures;
};

struct VkExportFenceCreateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	VkExternalFenceHandleTypeFlags	handleTypes;
};

struct VkExportSemaphoreCreateInfo
{
	VkStructureType						sType;
	const void*							pNext;
	VkExternalSemaphoreHandleTypeFlags	handleTypes;
};

struct VkPhysicalDeviceExternalSemaphoreInfo
{
	VkStructureType							sType;
	const void*								pNext;
	VkExternalSemaphoreHandleTypeFlagBits	handleType;
};

struct VkExternalSemaphoreProperties
{
	VkStructureType						sType;
	void*								pNext;
	VkExternalSemaphoreHandleTypeFlags	exportFromImportedHandleTypes;
	VkExternalSemaphoreHandleTypeFlags	compatibleHandleTypes;
	VkExternalSemaphoreFeatureFlags		externalSemaphoreFeatures;
};

struct VkPhysicalDeviceMaintenance3Properties
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		maxPerSetDescriptors;
	VkDeviceSize	maxMemoryAllocationSize;
};

struct VkDescriptorSetLayoutSupport
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		supported;
};

struct VkPhysicalDeviceShaderDrawParametersFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		shaderDrawParameters;
};

struct VkPhysicalDeviceVulkan11Features
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		storageBuffer16BitAccess;
	VkBool32		uniformAndStorageBuffer16BitAccess;
	VkBool32		storagePushConstant16;
	VkBool32		storageInputOutput16;
	VkBool32		multiview;
	VkBool32		multiviewGeometryShader;
	VkBool32		multiviewTessellationShader;
	VkBool32		variablePointersStorageBuffer;
	VkBool32		variablePointers;
	VkBool32		protectedMemory;
	VkBool32		samplerYcbcrConversion;
	VkBool32		shaderDrawParameters;
};

struct VkPhysicalDeviceVulkan11Properties
{
	VkStructureType			sType;
	void*					pNext;
	uint8_t					deviceUUID[VK_UUID_SIZE];
	uint8_t					driverUUID[VK_UUID_SIZE];
	uint8_t					deviceLUID[VK_LUID_SIZE];
	uint32_t				deviceNodeMask;
	VkBool32				deviceLUIDValid;
	uint32_t				subgroupSize;
	VkShaderStageFlags		subgroupSupportedStages;
	VkSubgroupFeatureFlags	subgroupSupportedOperations;
	VkBool32				subgroupQuadOperationsInAllStages;
	VkPointClippingBehavior	pointClippingBehavior;
	uint32_t				maxMultiviewViewCount;
	uint32_t				maxMultiviewInstanceIndex;
	VkBool32				protectedNoFault;
	uint32_t				maxPerSetDescriptors;
	VkDeviceSize			maxMemoryAllocationSize;
};

struct VkPhysicalDeviceVulkan12Features
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		samplerMirrorClampToEdge;
	VkBool32		drawIndirectCount;
	VkBool32		storageBuffer8BitAccess;
	VkBool32		uniformAndStorageBuffer8BitAccess;
	VkBool32		storagePushConstant8;
	VkBool32		shaderBufferInt64Atomics;
	VkBool32		shaderSharedInt64Atomics;
	VkBool32		shaderFloat16;
	VkBool32		shaderInt8;
	VkBool32		descriptorIndexing;
	VkBool32		shaderInputAttachmentArrayDynamicIndexing;
	VkBool32		shaderUniformTexelBufferArrayDynamicIndexing;
	VkBool32		shaderStorageTexelBufferArrayDynamicIndexing;
	VkBool32		shaderUniformBufferArrayNonUniformIndexing;
	VkBool32		shaderSampledImageArrayNonUniformIndexing;
	VkBool32		shaderStorageBufferArrayNonUniformIndexing;
	VkBool32		shaderStorageImageArrayNonUniformIndexing;
	VkBool32		shaderInputAttachmentArrayNonUniformIndexing;
	VkBool32		shaderUniformTexelBufferArrayNonUniformIndexing;
	VkBool32		shaderStorageTexelBufferArrayNonUniformIndexing;
	VkBool32		descriptorBindingUniformBufferUpdateAfterBind;
	VkBool32		descriptorBindingSampledImageUpdateAfterBind;
	VkBool32		descriptorBindingStorageImageUpdateAfterBind;
	VkBool32		descriptorBindingStorageBufferUpdateAfterBind;
	VkBool32		descriptorBindingUniformTexelBufferUpdateAfterBind;
	VkBool32		descriptorBindingStorageTexelBufferUpdateAfterBind;
	VkBool32		descriptorBindingUpdateUnusedWhilePending;
	VkBool32		descriptorBindingPartiallyBound;
	VkBool32		descriptorBindingVariableDescriptorCount;
	VkBool32		runtimeDescriptorArray;
	VkBool32		samplerFilterMinmax;
	VkBool32		scalarBlockLayout;
	VkBool32		imagelessFramebuffer;
	VkBool32		uniformBufferStandardLayout;
	VkBool32		shaderSubgroupExtendedTypes;
	VkBool32		separateDepthStencilLayouts;
	VkBool32		hostQueryReset;
	VkBool32		timelineSemaphore;
	VkBool32		bufferDeviceAddress;
	VkBool32		bufferDeviceAddressCaptureReplay;
	VkBool32		bufferDeviceAddressMultiDevice;
	VkBool32		vulkanMemoryModel;
	VkBool32		vulkanMemoryModelDeviceScope;
	VkBool32		vulkanMemoryModelAvailabilityVisibilityChains;
	VkBool32		shaderOutputViewportIndex;
	VkBool32		shaderOutputLayer;
	VkBool32		subgroupBroadcastDynamicId;
};

struct VkConformanceVersion
{
	uint8_t	major;
	uint8_t	minor;
	uint8_t	subminor;
	uint8_t	patch;
};

struct VkPhysicalDeviceVulkan12Properties
{
	VkStructureType						sType;
	void*								pNext;
	VkDriverId							driverID;
	char								driverName[VK_MAX_DRIVER_NAME_SIZE];
	char								driverInfo[VK_MAX_DRIVER_INFO_SIZE];
	VkConformanceVersion				conformanceVersion;
	VkShaderFloatControlsIndependence	denormBehaviorIndependence;
	VkShaderFloatControlsIndependence	roundingModeIndependence;
	VkBool32							shaderSignedZeroInfNanPreserveFloat16;
	VkBool32							shaderSignedZeroInfNanPreserveFloat32;
	VkBool32							shaderSignedZeroInfNanPreserveFloat64;
	VkBool32							shaderDenormPreserveFloat16;
	VkBool32							shaderDenormPreserveFloat32;
	VkBool32							shaderDenormPreserveFloat64;
	VkBool32							shaderDenormFlushToZeroFloat16;
	VkBool32							shaderDenormFlushToZeroFloat32;
	VkBool32							shaderDenormFlushToZeroFloat64;
	VkBool32							shaderRoundingModeRTEFloat16;
	VkBool32							shaderRoundingModeRTEFloat32;
	VkBool32							shaderRoundingModeRTEFloat64;
	VkBool32							shaderRoundingModeRTZFloat16;
	VkBool32							shaderRoundingModeRTZFloat32;
	VkBool32							shaderRoundingModeRTZFloat64;
	uint32_t							maxUpdateAfterBindDescriptorsInAllPools;
	VkBool32							shaderUniformBufferArrayNonUniformIndexingNative;
	VkBool32							shaderSampledImageArrayNonUniformIndexingNative;
	VkBool32							shaderStorageBufferArrayNonUniformIndexingNative;
	VkBool32							shaderStorageImageArrayNonUniformIndexingNative;
	VkBool32							shaderInputAttachmentArrayNonUniformIndexingNative;
	VkBool32							robustBufferAccessUpdateAfterBind;
	VkBool32							quadDivergentImplicitLod;
	uint32_t							maxPerStageDescriptorUpdateAfterBindSamplers;
	uint32_t							maxPerStageDescriptorUpdateAfterBindUniformBuffers;
	uint32_t							maxPerStageDescriptorUpdateAfterBindStorageBuffers;
	uint32_t							maxPerStageDescriptorUpdateAfterBindSampledImages;
	uint32_t							maxPerStageDescriptorUpdateAfterBindStorageImages;
	uint32_t							maxPerStageDescriptorUpdateAfterBindInputAttachments;
	uint32_t							maxPerStageUpdateAfterBindResources;
	uint32_t							maxDescriptorSetUpdateAfterBindSamplers;
	uint32_t							maxDescriptorSetUpdateAfterBindUniformBuffers;
	uint32_t							maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
	uint32_t							maxDescriptorSetUpdateAfterBindStorageBuffers;
	uint32_t							maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
	uint32_t							maxDescriptorSetUpdateAfterBindSampledImages;
	uint32_t							maxDescriptorSetUpdateAfterBindStorageImages;
	uint32_t							maxDescriptorSetUpdateAfterBindInputAttachments;
	VkResolveModeFlags					supportedDepthResolveModes;
	VkResolveModeFlags					supportedStencilResolveModes;
	VkBool32							independentResolveNone;
	VkBool32							independentResolve;
	VkBool32							filterMinmaxSingleComponentFormats;
	VkBool32							filterMinmaxImageComponentMapping;
	uint64_t							maxTimelineSemaphoreValueDifference;
	VkSampleCountFlags					framebufferIntegerColorSampleCounts;
};

struct VkImageFormatListCreateInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		viewFormatCount;
	const VkFormat*	pViewFormats;
};

struct VkAttachmentDescription2
{
	VkStructureType					sType;
	const void*						pNext;
	VkAttachmentDescriptionFlags	flags;
	VkFormat						format;
	VkSampleCountFlagBits			samples;
	VkAttachmentLoadOp				loadOp;
	VkAttachmentStoreOp				storeOp;
	VkAttachmentLoadOp				stencilLoadOp;
	VkAttachmentStoreOp				stencilStoreOp;
	VkImageLayout					initialLayout;
	VkImageLayout					finalLayout;
};

struct VkAttachmentReference2
{
	VkStructureType		sType;
	const void*			pNext;
	uint32_t			attachment;
	VkImageLayout		layout;
	VkImageAspectFlags	aspectMask;
};

struct VkSubpassDescription2
{
	VkStructureType					sType;
	const void*						pNext;
	VkSubpassDescriptionFlags		flags;
	VkPipelineBindPoint				pipelineBindPoint;
	uint32_t						viewMask;
	uint32_t						inputAttachmentCount;
	const VkAttachmentReference2*	pInputAttachments;
	uint32_t						colorAttachmentCount;
	const VkAttachmentReference2*	pColorAttachments;
	const VkAttachmentReference2*	pResolveAttachments;
	const VkAttachmentReference2*	pDepthStencilAttachment;
	uint32_t						preserveAttachmentCount;
	const uint32_t*					pPreserveAttachments;
};

struct VkSubpassDependency2
{
	VkStructureType			sType;
	const void*				pNext;
	uint32_t				srcSubpass;
	uint32_t				dstSubpass;
	VkPipelineStageFlags	srcStageMask;
	VkPipelineStageFlags	dstStageMask;
	VkAccessFlags			srcAccessMask;
	VkAccessFlags			dstAccessMask;
	VkDependencyFlags		dependencyFlags;
	int32_t					viewOffset;
};

struct VkRenderPassCreateInfo2
{
	VkStructureType					sType;
	const void*						pNext;
	VkRenderPassCreateFlags			flags;
	uint32_t						attachmentCount;
	const VkAttachmentDescription2*	pAttachments;
	uint32_t						subpassCount;
	const VkSubpassDescription2*	pSubpasses;
	uint32_t						dependencyCount;
	const VkSubpassDependency2*		pDependencies;
	uint32_t						correlatedViewMaskCount;
	const uint32_t*					pCorrelatedViewMasks;
};

struct VkSubpassBeginInfo
{
	VkStructureType		sType;
	const void*			pNext;
	VkSubpassContents	contents;
};

struct VkSubpassEndInfo
{
	VkStructureType	sType;
	const void*		pNext;
};

struct VkPhysicalDevice8BitStorageFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		storageBuffer8BitAccess;
	VkBool32		uniformAndStorageBuffer8BitAccess;
	VkBool32		storagePushConstant8;
};

struct VkPhysicalDeviceDriverProperties
{
	VkStructureType			sType;
	void*					pNext;
	VkDriverId				driverID;
	char					driverName[VK_MAX_DRIVER_NAME_SIZE];
	char					driverInfo[VK_MAX_DRIVER_INFO_SIZE];
	VkConformanceVersion	conformanceVersion;
};

struct VkPhysicalDeviceShaderAtomicInt64Features
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		shaderBufferInt64Atomics;
	VkBool32		shaderSharedInt64Atomics;
};

struct VkPhysicalDeviceShaderFloat16Int8Features
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		shaderFloat16;
	VkBool32		shaderInt8;
};

struct VkPhysicalDeviceFloatControlsProperties
{
	VkStructureType						sType;
	void*								pNext;
	VkShaderFloatControlsIndependence	denormBehaviorIndependence;
	VkShaderFloatControlsIndependence	roundingModeIndependence;
	VkBool32							shaderSignedZeroInfNanPreserveFloat16;
	VkBool32							shaderSignedZeroInfNanPreserveFloat32;
	VkBool32							shaderSignedZeroInfNanPreserveFloat64;
	VkBool32							shaderDenormPreserveFloat16;
	VkBool32							shaderDenormPreserveFloat32;
	VkBool32							shaderDenormPreserveFloat64;
	VkBool32							shaderDenormFlushToZeroFloat16;
	VkBool32							shaderDenormFlushToZeroFloat32;
	VkBool32							shaderDenormFlushToZeroFloat64;
	VkBool32							shaderRoundingModeRTEFloat16;
	VkBool32							shaderRoundingModeRTEFloat32;
	VkBool32							shaderRoundingModeRTEFloat64;
	VkBool32							shaderRoundingModeRTZFloat16;
	VkBool32							shaderRoundingModeRTZFloat32;
	VkBool32							shaderRoundingModeRTZFloat64;
};

struct VkDescriptorSetLayoutBindingFlagsCreateInfo
{
	VkStructureType					sType;
	const void*						pNext;
	uint32_t						bindingCount;
	const VkDescriptorBindingFlags*	pBindingFlags;
};

struct VkPhysicalDeviceDescriptorIndexingFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		shaderInputAttachmentArrayDynamicIndexing;
	VkBool32		shaderUniformTexelBufferArrayDynamicIndexing;
	VkBool32		shaderStorageTexelBufferArrayDynamicIndexing;
	VkBool32		shaderUniformBufferArrayNonUniformIndexing;
	VkBool32		shaderSampledImageArrayNonUniformIndexing;
	VkBool32		shaderStorageBufferArrayNonUniformIndexing;
	VkBool32		shaderStorageImageArrayNonUniformIndexing;
	VkBool32		shaderInputAttachmentArrayNonUniformIndexing;
	VkBool32		shaderUniformTexelBufferArrayNonUniformIndexing;
	VkBool32		shaderStorageTexelBufferArrayNonUniformIndexing;
	VkBool32		descriptorBindingUniformBufferUpdateAfterBind;
	VkBool32		descriptorBindingSampledImageUpdateAfterBind;
	VkBool32		descriptorBindingStorageImageUpdateAfterBind;
	VkBool32		descriptorBindingStorageBufferUpdateAfterBind;
	VkBool32		descriptorBindingUniformTexelBufferUpdateAfterBind;
	VkBool32		descriptorBindingStorageTexelBufferUpdateAfterBind;
	VkBool32		descriptorBindingUpdateUnusedWhilePending;
	VkBool32		descriptorBindingPartiallyBound;
	VkBool32		descriptorBindingVariableDescriptorCount;
	VkBool32		runtimeDescriptorArray;
};

struct VkPhysicalDeviceDescriptorIndexingProperties
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		maxUpdateAfterBindDescriptorsInAllPools;
	VkBool32		shaderUniformBufferArrayNonUniformIndexingNative;
	VkBool32		shaderSampledImageArrayNonUniformIndexingNative;
	VkBool32		shaderStorageBufferArrayNonUniformIndexingNative;
	VkBool32		shaderStorageImageArrayNonUniformIndexingNative;
	VkBool32		shaderInputAttachmentArrayNonUniformIndexingNative;
	VkBool32		robustBufferAccessUpdateAfterBind;
	VkBool32		quadDivergentImplicitLod;
	uint32_t		maxPerStageDescriptorUpdateAfterBindSamplers;
	uint32_t		maxPerStageDescriptorUpdateAfterBindUniformBuffers;
	uint32_t		maxPerStageDescriptorUpdateAfterBindStorageBuffers;
	uint32_t		maxPerStageDescriptorUpdateAfterBindSampledImages;
	uint32_t		maxPerStageDescriptorUpdateAfterBindStorageImages;
	uint32_t		maxPerStageDescriptorUpdateAfterBindInputAttachments;
	uint32_t		maxPerStageUpdateAfterBindResources;
	uint32_t		maxDescriptorSetUpdateAfterBindSamplers;
	uint32_t		maxDescriptorSetUpdateAfterBindUniformBuffers;
	uint32_t		maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
	uint32_t		maxDescriptorSetUpdateAfterBindStorageBuffers;
	uint32_t		maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
	uint32_t		maxDescriptorSetUpdateAfterBindSampledImages;
	uint32_t		maxDescriptorSetUpdateAfterBindStorageImages;
	uint32_t		maxDescriptorSetUpdateAfterBindInputAttachments;
};

struct VkDescriptorSetVariableDescriptorCountAllocateInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		descriptorSetCount;
	const uint32_t*	pDescriptorCounts;
};

struct VkDescriptorSetVariableDescriptorCountLayoutSupport
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		maxVariableDescriptorCount;
};

struct VkSubpassDescriptionDepthStencilResolve
{
	VkStructureType					sType;
	const void*						pNext;
	VkResolveModeFlagBits			depthResolveMode;
	VkResolveModeFlagBits			stencilResolveMode;
	const VkAttachmentReference2*	pDepthStencilResolveAttachment;
};

struct VkPhysicalDeviceDepthStencilResolveProperties
{
	VkStructureType		sType;
	void*				pNext;
	VkResolveModeFlags	supportedDepthResolveModes;
	VkResolveModeFlags	supportedStencilResolveModes;
	VkBool32			independentResolveNone;
	VkBool32			independentResolve;
};

struct VkPhysicalDeviceScalarBlockLayoutFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		scalarBlockLayout;
};

struct VkImageStencilUsageCreateInfo
{
	VkStructureType		sType;
	const void*			pNext;
	VkImageUsageFlags	stencilUsage;
};

struct VkSamplerReductionModeCreateInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkSamplerReductionMode	reductionMode;
};

struct VkPhysicalDeviceSamplerFilterMinmaxProperties
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		filterMinmaxSingleComponentFormats;
	VkBool32		filterMinmaxImageComponentMapping;
};

struct VkPhysicalDeviceVulkanMemoryModelFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		vulkanMemoryModel;
	VkBool32		vulkanMemoryModelDeviceScope;
	VkBool32		vulkanMemoryModelAvailabilityVisibilityChains;
};

struct VkPhysicalDeviceImagelessFramebufferFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		imagelessFramebuffer;
};

struct VkFramebufferAttachmentImageInfo
{
	VkStructureType		sType;
	const void*			pNext;
	VkImageCreateFlags	flags;
	VkImageUsageFlags	usage;
	uint32_t			width;
	uint32_t			height;
	uint32_t			layerCount;
	uint32_t			viewFormatCount;
	const VkFormat*		pViewFormats;
};

struct VkFramebufferAttachmentsCreateInfo
{
	VkStructureType							sType;
	const void*								pNext;
	uint32_t								attachmentImageInfoCount;
	const VkFramebufferAttachmentImageInfo*	pAttachmentImageInfos;
};

struct VkRenderPassAttachmentBeginInfo
{
	VkStructureType		sType;
	const void*			pNext;
	uint32_t			attachmentCount;
	const VkImageView*	pAttachments;
};

struct VkPhysicalDeviceUniformBufferStandardLayoutFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		uniformBufferStandardLayout;
};

struct VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		shaderSubgroupExtendedTypes;
};

struct VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		separateDepthStencilLayouts;
};

struct VkAttachmentReferenceStencilLayout
{
	VkStructureType	sType;
	void*			pNext;
	VkImageLayout	stencilLayout;
};

struct VkAttachmentDescriptionStencilLayout
{
	VkStructureType	sType;
	void*			pNext;
	VkImageLayout	stencilInitialLayout;
	VkImageLayout	stencilFinalLayout;
};

struct VkPhysicalDeviceHostQueryResetFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		hostQueryReset;
};

struct VkPhysicalDeviceTimelineSemaphoreFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		timelineSemaphore;
};

struct VkPhysicalDeviceTimelineSemaphoreProperties
{
	VkStructureType	sType;
	void*			pNext;
	uint64_t		maxTimelineSemaphoreValueDifference;
};

struct VkSemaphoreTypeCreateInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkSemaphoreType	semaphoreType;
	uint64_t		initialValue;
};

struct VkTimelineSemaphoreSubmitInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		waitSemaphoreValueCount;
	const uint64_t*	pWaitSemaphoreValues;
	uint32_t		signalSemaphoreValueCount;
	const uint64_t*	pSignalSemaphoreValues;
};

struct VkSemaphoreWaitInfo
{
	VkStructureType			sType;
	const void*				pNext;
	VkSemaphoreWaitFlags	flags;
	uint32_t				semaphoreCount;
	const VkSemaphore*		pSemaphores;
	const uint64_t*			pValues;
};

struct VkSemaphoreSignalInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkSemaphore		semaphore;
	uint64_t		value;
};

struct VkPhysicalDeviceBufferDeviceAddressFeatures
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		bufferDeviceAddress;
	VkBool32		bufferDeviceAddressCaptureReplay;
	VkBool32		bufferDeviceAddressMultiDevice;
};

struct VkBufferDeviceAddressInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkBuffer		buffer;
};

struct VkBufferOpaqueCaptureAddressCreateInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint64_t		opaqueCaptureAddress;
};

struct VkMemoryOpaqueCaptureAddressAllocateInfo
{
	VkStructureType	sType;
	const void*		pNext;
	uint64_t		opaqueCaptureAddress;
};

struct VkDeviceMemoryOpaqueCaptureAddressInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkDeviceMemory	memory;
};

struct VkPhysicalDeviceVulkanSC10Features
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		pipelineIdentifier;
	VkBool32		shaderAtomicInstructions;
};

struct VkPhysicalDeviceVulkanSC10Properties
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		deviceNoDynamicHostAllocations;
	VkBool32		deviceDestroyFreesMemory;
	VkBool32		commandPoolMultipleCommandBuffersRecording;
	VkBool32		commandPoolResetCommandBuffer;
	VkBool32		commandBufferSimultaneousUse;
	VkBool32		secondaryCommandBufferNullFramebuffer;
	VkBool32		descriptorPoolFreeDescriptorSets;
	VkBool32		recyclePipelineMemory;
	uint32_t		maxRenderPassSubpasses;
	uint32_t		maxRenderPassDependencies;
	uint32_t		maxSubpassInputAttachments;
	uint32_t		maxSubpassPreserveAttachments;
	uint32_t		maxFramebufferAttachments;
	uint32_t		maxDescriptorSetLayoutBindings;
	uint32_t		maxQueryFaultCount;
	uint32_t		maxCallbackFaultCount;
};

struct VkPipelinePoolSize
{
	VkStructureType	sType;
	const void*		pNext;
	VkDeviceSize	poolEntrySize;
	uint32_t		poolEntryCount;
};

struct VkDeviceObjectReservationCreateInfo
{
	VkStructureType						sType;
	const void*							pNext;
	uint32_t							pipelineCacheCreateInfoCount;
	const VkPipelineCacheCreateInfo*	pPipelineCacheCreateInfos;
	uint32_t							pipelinePoolSizeCount;
	const VkPipelinePoolSize*			pPipelinePoolSizes;
	uint32_t							semaphoreRequestCount;
	uint32_t							commandBufferRequestCount;
	uint32_t							fenceRequestCount;
	uint32_t							deviceMemoryRequestCount;
	uint32_t							bufferRequestCount;
	uint32_t							imageRequestCount;
	uint32_t							eventRequestCount;
	uint32_t							queryPoolRequestCount;
	uint32_t							bufferViewRequestCount;
	uint32_t							imageViewRequestCount;
	uint32_t							layeredImageViewRequestCount;
	uint32_t							pipelineCacheRequestCount;
	uint32_t							pipelineLayoutRequestCount;
	uint32_t							renderPassRequestCount;
	uint32_t							graphicsPipelineRequestCount;
	uint32_t							computePipelineRequestCount;
	uint32_t							descriptorSetLayoutRequestCount;
	uint32_t							samplerRequestCount;
	uint32_t							descriptorPoolRequestCount;
	uint32_t							descriptorSetRequestCount;
	uint32_t							framebufferRequestCount;
	uint32_t							commandPoolRequestCount;
	uint32_t							samplerYcbcrConversionRequestCount;
	uint32_t							surfaceRequestCount;
	uint32_t							swapchainRequestCount;
	uint32_t							displayModeRequestCount;
	uint32_t							subpassDescriptionRequestCount;
	uint32_t							attachmentDescriptionRequestCount;
	uint32_t							descriptorSetLayoutBindingRequestCount;
	uint32_t							descriptorSetLayoutBindingLimit;
	uint32_t							maxImageViewMipLevels;
	uint32_t							maxImageViewArrayLayers;
	uint32_t							maxLayeredImageViewMipLevels;
	uint32_t							maxOcclusionQueriesPerPool;
	uint32_t							maxPipelineStatisticsQueriesPerPool;
	uint32_t							maxTimestampQueriesPerPool;
};

struct VkCommandPoolMemoryReservationCreateInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkDeviceSize	commandPoolReservedSize;
	uint32_t		commandPoolMaxCommandBuffers;
};

struct VkCommandPoolMemoryConsumption
{
	VkStructureType	sType;
	void*			pNext;
	VkDeviceSize	commandPoolAllocated;
	VkDeviceSize	commandPoolReservedSize;
	VkDeviceSize	commandBufferAllocated;
};

struct VkPipelinePoolEntrySizeCreateInfo
{
	VkStructureType	sType;
	const void*		pNext;
	VkDeviceSize	poolEntrySize;
};

struct VkFaultData
{
	VkStructureType	sType;
	void*			pNext;
	VkFaultLevel	faultLevel;
	VkFaultType		faultType;
};

struct VkFaultCallbackInfo
{
	VkStructureType				sType;
	void*						pNext;
	VkFaultData*				pFaults;
	PFN_vkFaultCallbackFunction	pfnFaultCallback;
};

struct VkPipelineIdentifierInfo
{
	VkStructureType			sType;
	const void*				pNext;
	uint8_t					pipelineIdentifier[VK_UUID_SIZE];
	VkPipelineMatchControl	matchControl;
};

struct VkSurfaceCapabilitiesKHR
{
	uint32_t						minImageCount;
	uint32_t						maxImageCount;
	VkExtent2D						currentExtent;
	VkExtent2D						minImageExtent;
	VkExtent2D						maxImageExtent;
	uint32_t						maxImageArrayLayers;
	VkSurfaceTransformFlagsKHR		supportedTransforms;
	VkSurfaceTransformFlagBitsKHR	currentTransform;
	VkCompositeAlphaFlagsKHR		supportedCompositeAlpha;
	VkImageUsageFlags				supportedUsageFlags;
};

struct VkSurfaceFormatKHR
{
	VkFormat		format;
	VkColorSpaceKHR	colorSpace;
};

struct VkSwapchainCreateInfoKHR
{
	VkStructureType					sType;
	const void*						pNext;
	VkSwapchainCreateFlagsKHR		flags;
	VkSurfaceKHR					surface;
	uint32_t						minImageCount;
	VkFormat						imageFormat;
	VkColorSpaceKHR					imageColorSpace;
	VkExtent2D						imageExtent;
	uint32_t						imageArrayLayers;
	VkImageUsageFlags				imageUsage;
	VkSharingMode					imageSharingMode;
	uint32_t						queueFamilyIndexCount;
	const uint32_t*					pQueueFamilyIndices;
	VkSurfaceTransformFlagBitsKHR	preTransform;
	VkCompositeAlphaFlagBitsKHR		compositeAlpha;
	VkPresentModeKHR				presentMode;
	VkBool32						clipped;
	VkSwapchainKHR					oldSwapchain;
};

struct VkPresentInfoKHR
{
	VkStructureType			sType;
	const void*				pNext;
	uint32_t				waitSemaphoreCount;
	const VkSemaphore*		pWaitSemaphores;
	uint32_t				swapchainCount;
	const VkSwapchainKHR*	pSwapchains;
	const uint32_t*			pImageIndices;
	VkResult*				pResults;
};

struct VkImageSwapchainCreateInfoKHR
{
	VkStructureType	sType;
	const void*		pNext;
	VkSwapchainKHR	swapchain;
};

struct VkBindImageMemorySwapchainInfoKHR
{
	VkStructureType	sType;
	const void*		pNext;
	VkSwapchainKHR	swapchain;
	uint32_t		imageIndex;
};

struct VkAcquireNextImageInfoKHR
{
	VkStructureType	sType;
	const void*		pNext;
	VkSwapchainKHR	swapchain;
	uint64_t		timeout;
	VkSemaphore		semaphore;
	VkFence			fence;
	uint32_t		deviceMask;
};

struct VkDeviceGroupPresentCapabilitiesKHR
{
	VkStructureType						sType;
	const void*							pNext;
	uint32_t							presentMask[VK_MAX_DEVICE_GROUP_SIZE];
	VkDeviceGroupPresentModeFlagsKHR	modes;
};

struct VkDeviceGroupPresentInfoKHR
{
	VkStructureType						sType;
	const void*							pNext;
	uint32_t							swapchainCount;
	const uint32_t*						pDeviceMasks;
	VkDeviceGroupPresentModeFlagBitsKHR	mode;
};

struct VkDeviceGroupSwapchainCreateInfoKHR
{
	VkStructureType						sType;
	const void*							pNext;
	VkDeviceGroupPresentModeFlagsKHR	modes;
};

struct VkDisplayModeParametersKHR
{
	VkExtent2D	visibleRegion;
	uint32_t	refreshRate;
};

struct VkDisplayModeCreateInfoKHR
{
	VkStructureType				sType;
	const void*					pNext;
	VkDisplayModeCreateFlagsKHR	flags;
	VkDisplayModeParametersKHR	parameters;
};

struct VkDisplayModePropertiesKHR
{
	VkDisplayModeKHR			displayMode;
	VkDisplayModeParametersKHR	parameters;
};

struct VkDisplayPlaneCapabilitiesKHR
{
	VkDisplayPlaneAlphaFlagsKHR	supportedAlpha;
	VkOffset2D					minSrcPosition;
	VkOffset2D					maxSrcPosition;
	VkExtent2D					minSrcExtent;
	VkExtent2D					maxSrcExtent;
	VkOffset2D					minDstPosition;
	VkOffset2D					maxDstPosition;
	VkExtent2D					minDstExtent;
	VkExtent2D					maxDstExtent;
};

struct VkDisplayPlanePropertiesKHR
{
	VkDisplayKHR	currentDisplay;
	uint32_t		currentStackIndex;
};

struct VkDisplayPropertiesKHR
{
	VkDisplayKHR				display;
	const char*					displayName;
	VkExtent2D					physicalDimensions;
	VkExtent2D					physicalResolution;
	VkSurfaceTransformFlagsKHR	supportedTransforms;
	VkBool32					planeReorderPossible;
	VkBool32					persistentContent;
};

struct VkDisplaySurfaceCreateInfoKHR
{
	VkStructureType					sType;
	const void*						pNext;
	VkDisplaySurfaceCreateFlagsKHR	flags;
	VkDisplayModeKHR				displayMode;
	uint32_t						planeIndex;
	uint32_t						planeStackIndex;
	VkSurfaceTransformFlagBitsKHR	transform;
	float							globalAlpha;
	VkDisplayPlaneAlphaFlagBitsKHR	alphaMode;
	VkExtent2D						imageExtent;
};

struct VkDisplayPresentInfoKHR
{
	VkStructureType	sType;
	const void*		pNext;
	VkRect2D		srcRect;
	VkRect2D		dstRect;
	VkBool32		persistent;
};

struct VkImportMemoryFdInfoKHR
{
	VkStructureType						sType;
	const void*							pNext;
	VkExternalMemoryHandleTypeFlagBits	handleType;
	int									fd;
};

struct VkMemoryFdPropertiesKHR
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		memoryTypeBits;
};

struct VkMemoryGetFdInfoKHR
{
	VkStructureType						sType;
	const void*							pNext;
	VkDeviceMemory						memory;
	VkExternalMemoryHandleTypeFlagBits	handleType;
};

struct VkImportSemaphoreFdInfoKHR
{
	VkStructureType							sType;
	const void*								pNext;
	VkSemaphore								semaphore;
	VkSemaphoreImportFlags					flags;
	VkExternalSemaphoreHandleTypeFlagBits	handleType;
	int										fd;
};

struct VkSemaphoreGetFdInfoKHR
{
	VkStructureType							sType;
	const void*								pNext;
	VkSemaphore								semaphore;
	VkExternalSemaphoreHandleTypeFlagBits	handleType;
};

struct VkRectLayerKHR
{
	VkOffset2D	offset;
	VkExtent2D	extent;
	uint32_t	layer;
};

struct VkPresentRegionKHR
{
	uint32_t				rectangleCount;
	const VkRectLayerKHR*	pRectangles;
};

struct VkPresentRegionsKHR
{
	VkStructureType				sType;
	const void*					pNext;
	uint32_t					swapchainCount;
	const VkPresentRegionKHR*	pRegions;
};

struct VkSharedPresentSurfaceCapabilitiesKHR
{
	VkStructureType		sType;
	void*				pNext;
	VkImageUsageFlags	sharedPresentSupportedUsageFlags;
};

struct VkImportFenceFdInfoKHR
{
	VkStructureType						sType;
	const void*							pNext;
	VkFence								fence;
	VkFenceImportFlags					flags;
	VkExternalFenceHandleTypeFlagBits	handleType;
	int									fd;
};

struct VkFenceGetFdInfoKHR
{
	VkStructureType						sType;
	const void*							pNext;
	VkFence								fence;
	VkExternalFenceHandleTypeFlagBits	handleType;
};

struct VkPhysicalDevicePerformanceQueryFeaturesKHR
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		performanceCounterQueryPools;
	VkBool32		performanceCounterMultipleQueryPools;
};

struct VkPhysicalDevicePerformanceQueryPropertiesKHR
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		allowCommandBufferQueryCopies;
};

struct VkPerformanceCounterKHR
{
	VkStructureType					sType;
	const void*						pNext;
	VkPerformanceCounterUnitKHR		unit;
	VkPerformanceCounterScopeKHR	scope;
	VkPerformanceCounterStorageKHR	storage;
	uint8_t							uuid[VK_UUID_SIZE];
};

struct VkPerformanceCounterDescriptionKHR
{
	VkStructureType							sType;
	const void*								pNext;
	VkPerformanceCounterDescriptionFlagsKHR	flags;
	char									name[VK_MAX_DESCRIPTION_SIZE];
	char									category[VK_MAX_DESCRIPTION_SIZE];
	char									description[VK_MAX_DESCRIPTION_SIZE];
};

struct VkQueryPoolPerformanceCreateInfoKHR
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		queueFamilyIndex;
	uint32_t		counterIndexCount;
	const uint32_t*	pCounterIndices;
};

union VkPerformanceCounterResultKHR
{
	int32_t		int32;
	int64_t		int64;
	uint32_t	uint32;
	uint64_t	uint64;
	float		float32;
	double		float64;
};

struct VkAcquireProfilingLockInfoKHR
{
	VkStructureType					sType;
	const void*						pNext;
	VkAcquireProfilingLockFlagsKHR	flags;
	uint64_t						timeout;
};

struct VkPerformanceQuerySubmitInfoKHR
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		counterPassIndex;
};

struct VkPerformanceQueryReservationInfoKHR
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		maxPerformanceQueriesPerPool;
};

struct VkPhysicalDeviceSurfaceInfo2KHR
{
	VkStructureType	sType;
	const void*		pNext;
	VkSurfaceKHR	surface;
};

struct VkSurfaceCapabilities2KHR
{
	VkStructureType				sType;
	void*						pNext;
	VkSurfaceCapabilitiesKHR	surfaceCapabilities;
};

struct VkSurfaceFormat2KHR
{
	VkStructureType		sType;
	void*				pNext;
	VkSurfaceFormatKHR	surfaceFormat;
};

struct VkDisplayProperties2KHR
{
	VkStructureType			sType;
	void*					pNext;
	VkDisplayPropertiesKHR	displayProperties;
};

struct VkDisplayPlaneProperties2KHR
{
	VkStructureType				sType;
	void*						pNext;
	VkDisplayPlanePropertiesKHR	displayPlaneProperties;
};

struct VkDisplayModeProperties2KHR
{
	VkStructureType				sType;
	void*						pNext;
	VkDisplayModePropertiesKHR	displayModeProperties;
};

struct VkDisplayPlaneInfo2KHR
{
	VkStructureType		sType;
	const void*			pNext;
	VkDisplayModeKHR	mode;
	uint32_t			planeIndex;
};

struct VkDisplayPlaneCapabilities2KHR
{
	VkStructureType					sType;
	void*							pNext;
	VkDisplayPlaneCapabilitiesKHR	capabilities;
};

struct VkPhysicalDeviceShaderClockFeaturesKHR
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		shaderSubgroupClock;
	VkBool32		shaderDeviceClock;
};

struct VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		shaderTerminateInvocation;
};

struct VkFragmentShadingRateAttachmentInfoKHR
{
	VkStructureType					sType;
	const void*						pNext;
	const VkAttachmentReference2*	pFragmentShadingRateAttachment;
	VkExtent2D						shadingRateAttachmentTexelSize;
};

struct VkPipelineFragmentShadingRateStateCreateInfoKHR
{
	VkStructureType						sType;
	const void*							pNext;
	VkExtent2D							fragmentSize;
	VkFragmentShadingRateCombinerOpKHR	combinerOps[2];
};

struct VkPhysicalDeviceFragmentShadingRateFeaturesKHR
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		pipelineFragmentShadingRate;
	VkBool32		primitiveFragmentShadingRate;
	VkBool32		attachmentFragmentShadingRate;
};

struct VkPhysicalDeviceFragmentShadingRatePropertiesKHR
{
	VkStructureType			sType;
	void*					pNext;
	VkExtent2D				minFragmentShadingRateAttachmentTexelSize;
	VkExtent2D				maxFragmentShadingRateAttachmentTexelSize;
	uint32_t				maxFragmentShadingRateAttachmentTexelSizeAspectRatio;
	VkBool32				primitiveFragmentShadingRateWithMultipleViewports;
	VkBool32				layeredShadingRateAttachments;
	VkBool32				fragmentShadingRateNonTrivialCombinerOps;
	VkExtent2D				maxFragmentSize;
	uint32_t				maxFragmentSizeAspectRatio;
	uint32_t				maxFragmentShadingRateCoverageSamples;
	VkSampleCountFlagBits	maxFragmentShadingRateRasterizationSamples;
	VkBool32				fragmentShadingRateWithShaderDepthStencilWrites;
	VkBool32				fragmentShadingRateWithSampleMask;
	VkBool32				fragmentShadingRateWithShaderSampleMask;
	VkBool32				fragmentShadingRateWithConservativeRasterization;
	VkBool32				fragmentShadingRateWithFragmentShaderInterlock;
	VkBool32				fragmentShadingRateWithCustomSampleLocations;
	VkBool32				fragmentShadingRateStrictMultiplyCombiner;
};

struct VkPhysicalDeviceFragmentShadingRateKHR
{
	VkStructureType		sType;
	void*				pNext;
	VkSampleCountFlags	sampleCounts;
	VkExtent2D			fragmentSize;
};

struct VkRefreshObjectKHR
{
	VkObjectType			objectType;
	uint64_t				objectHandle;
	VkRefreshObjectFlagsKHR	flags;
};

struct VkRefreshObjectListKHR
{
	VkStructureType				sType;
	const void*					pNext;
	uint32_t					objectCount;
	const VkRefreshObjectKHR*	pObjects;
};

struct VkMemoryBarrier2KHR
{
	VkStructureType				sType;
	const void*					pNext;
	VkPipelineStageFlags2KHR	srcStageMask;
	VkAccessFlags2KHR			srcAccessMask;
	VkPipelineStageFlags2KHR	dstStageMask;
	VkAccessFlags2KHR			dstAccessMask;
};

struct VkBufferMemoryBarrier2KHR
{
	VkStructureType				sType;
	const void*					pNext;
	VkPipelineStageFlags2KHR	srcStageMask;
	VkAccessFlags2KHR			srcAccessMask;
	VkPipelineStageFlags2KHR	dstStageMask;
	VkAccessFlags2KHR			dstAccessMask;
	uint32_t					srcQueueFamilyIndex;
	uint32_t					dstQueueFamilyIndex;
	VkBuffer					buffer;
	VkDeviceSize				offset;
	VkDeviceSize				size;
};

struct VkImageMemoryBarrier2KHR
{
	VkStructureType				sType;
	const void*					pNext;
	VkPipelineStageFlags2KHR	srcStageMask;
	VkAccessFlags2KHR			srcAccessMask;
	VkPipelineStageFlags2KHR	dstStageMask;
	VkAccessFlags2KHR			dstAccessMask;
	VkImageLayout				oldLayout;
	VkImageLayout				newLayout;
	uint32_t					srcQueueFamilyIndex;
	uint32_t					dstQueueFamilyIndex;
	VkImage						image;
	VkImageSubresourceRange		subresourceRange;
};

struct VkDependencyInfoKHR
{
	VkStructureType						sType;
	const void*							pNext;
	VkDependencyFlags					dependencyFlags;
	uint32_t							memoryBarrierCount;
	const VkMemoryBarrier2KHR*			pMemoryBarriers;
	uint32_t							bufferMemoryBarrierCount;
	const VkBufferMemoryBarrier2KHR*	pBufferMemoryBarriers;
	uint32_t							imageMemoryBarrierCount;
	const VkImageMemoryBarrier2KHR*		pImageMemoryBarriers;
};

struct VkSemaphoreSubmitInfoKHR
{
	VkStructureType				sType;
	const void*					pNext;
	VkSemaphore					semaphore;
	uint64_t					value;
	VkPipelineStageFlags2KHR	stageMask;
	uint32_t					deviceIndex;
};

struct VkCommandBufferSubmitInfoKHR
{
	VkStructureType	sType;
	const void*		pNext;
	VkCommandBuffer	commandBuffer;
	uint32_t		deviceMask;
};

struct VkSubmitInfo2KHR
{
	VkStructureType						sType;
	const void*							pNext;
	VkSubmitFlagsKHR					flags;
	uint32_t							waitSemaphoreInfoCount;
	const VkSemaphoreSubmitInfoKHR*		pWaitSemaphoreInfos;
	uint32_t							commandBufferInfoCount;
	const VkCommandBufferSubmitInfoKHR*	pCommandBufferInfos;
	uint32_t							signalSemaphoreInfoCount;
	const VkSemaphoreSubmitInfoKHR*		pSignalSemaphoreInfos;
};

struct VkPhysicalDeviceSynchronization2FeaturesKHR
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		synchronization2;
};

struct VkQueueFamilyCheckpointProperties2NV
{
	VkStructureType				sType;
	void*						pNext;
	VkPipelineStageFlags2KHR	checkpointExecutionStageMask;
};

struct VkCheckpointData2NV
{
	VkStructureType				sType;
	void*						pNext;
	VkPipelineStageFlags2KHR	stage;
	void*						pCheckpointMarker;
};

struct VkBufferCopy2KHR
{
	VkStructureType	sType;
	const void*		pNext;
	VkDeviceSize	srcOffset;
	VkDeviceSize	dstOffset;
	VkDeviceSize	size;
};

struct VkCopyBufferInfo2KHR
{
	VkStructureType			sType;
	const void*				pNext;
	VkBuffer				srcBuffer;
	VkBuffer				dstBuffer;
	uint32_t				regionCount;
	const VkBufferCopy2KHR*	pRegions;
};

struct VkImageCopy2KHR
{
	VkStructureType				sType;
	const void*					pNext;
	VkImageSubresourceLayers	srcSubresource;
	VkOffset3D					srcOffset;
	VkImageSubresourceLayers	dstSubresource;
	VkOffset3D					dstOffset;
	VkExtent3D					extent;
};

struct VkCopyImageInfo2KHR
{
	VkStructureType			sType;
	const void*				pNext;
	VkImage					srcImage;
	VkImageLayout			srcImageLayout;
	VkImage					dstImage;
	VkImageLayout			dstImageLayout;
	uint32_t				regionCount;
	const VkImageCopy2KHR*	pRegions;
};

struct VkBufferImageCopy2KHR
{
	VkStructureType				sType;
	const void*					pNext;
	VkDeviceSize				bufferOffset;
	uint32_t					bufferRowLength;
	uint32_t					bufferImageHeight;
	VkImageSubresourceLayers	imageSubresource;
	VkOffset3D					imageOffset;
	VkExtent3D					imageExtent;
};

struct VkCopyBufferToImageInfo2KHR
{
	VkStructureType					sType;
	const void*						pNext;
	VkBuffer						srcBuffer;
	VkImage							dstImage;
	VkImageLayout					dstImageLayout;
	uint32_t						regionCount;
	const VkBufferImageCopy2KHR*	pRegions;
};

struct VkCopyImageToBufferInfo2KHR
{
	VkStructureType					sType;
	const void*						pNext;
	VkImage							srcImage;
	VkImageLayout					srcImageLayout;
	VkBuffer						dstBuffer;
	uint32_t						regionCount;
	const VkBufferImageCopy2KHR*	pRegions;
};

struct VkImageBlit2KHR
{
	VkStructureType				sType;
	const void*					pNext;
	VkImageSubresourceLayers	srcSubresource;
	VkOffset3D					srcOffsets[2];
	VkImageSubresourceLayers	dstSubresource;
	VkOffset3D					dstOffsets[2];
};

struct VkBlitImageInfo2KHR
{
	VkStructureType			sType;
	const void*				pNext;
	VkImage					srcImage;
	VkImageLayout			srcImageLayout;
	VkImage					dstImage;
	VkImageLayout			dstImageLayout;
	uint32_t				regionCount;
	const VkImageBlit2KHR*	pRegions;
	VkFilter				filter;
};

struct VkImageResolve2KHR
{
	VkStructureType				sType;
	const void*					pNext;
	VkImageSubresourceLayers	srcSubresource;
	VkOffset3D					srcOffset;
	VkImageSubresourceLayers	dstSubresource;
	VkOffset3D					dstOffset;
	VkExtent3D					extent;
};

struct VkResolveImageInfo2KHR
{
	VkStructureType				sType;
	const void*					pNext;
	VkImage						srcImage;
	VkImageLayout				srcImageLayout;
	VkImage						dstImage;
	VkImageLayout				dstImageLayout;
	uint32_t					regionCount;
	const VkImageResolve2KHR*	pRegions;
};

struct VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		textureCompressionASTC_HDR;
};

struct VkImageViewASTCDecodeModeEXT
{
	VkStructureType	sType;
	const void*		pNext;
	VkFormat		decodeMode;
};

struct VkPhysicalDeviceASTCDecodeFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		decodeModeSharedExponent;
};

struct VkSurfaceCapabilities2EXT
{
	VkStructureType					sType;
	void*							pNext;
	uint32_t						minImageCount;
	uint32_t						maxImageCount;
	VkExtent2D						currentExtent;
	VkExtent2D						minImageExtent;
	VkExtent2D						maxImageExtent;
	uint32_t						maxImageArrayLayers;
	VkSurfaceTransformFlagsKHR		supportedTransforms;
	VkSurfaceTransformFlagBitsKHR	currentTransform;
	VkCompositeAlphaFlagsKHR		supportedCompositeAlpha;
	VkImageUsageFlags				supportedUsageFlags;
	VkSurfaceCounterFlagsEXT		supportedSurfaceCounters;
};

struct VkDisplayPowerInfoEXT
{
	VkStructureType			sType;
	const void*				pNext;
	VkDisplayPowerStateEXT	powerState;
};

struct VkDeviceEventInfoEXT
{
	VkStructureType			sType;
	const void*				pNext;
	VkDeviceEventTypeEXT	deviceEvent;
};

struct VkDisplayEventInfoEXT
{
	VkStructureType			sType;
	const void*				pNext;
	VkDisplayEventTypeEXT	displayEvent;
};

struct VkSwapchainCounterCreateInfoEXT
{
	VkStructureType				sType;
	const void*					pNext;
	VkSurfaceCounterFlagsEXT	surfaceCounters;
};

struct VkPhysicalDeviceDiscardRectanglePropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		maxDiscardRectangles;
};

struct VkPipelineDiscardRectangleStateCreateInfoEXT
{
	VkStructureType									sType;
	const void*										pNext;
	VkPipelineDiscardRectangleStateCreateFlagsEXT	flags;
	VkDiscardRectangleModeEXT						discardRectangleMode;
	uint32_t										discardRectangleCount;
	const VkRect2D*									pDiscardRectangles;
};

struct VkPhysicalDeviceConservativeRasterizationPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	float			primitiveOverestimationSize;
	float			maxExtraPrimitiveOverestimationSize;
	float			extraPrimitiveOverestimationSizeGranularity;
	VkBool32		primitiveUnderestimation;
	VkBool32		conservativePointAndLineRasterization;
	VkBool32		degenerateTrianglesRasterized;
	VkBool32		degenerateLinesRasterized;
	VkBool32		fullyCoveredFragmentShaderInputVariable;
	VkBool32		conservativeRasterizationPostDepthCoverage;
};

struct VkPipelineRasterizationConservativeStateCreateInfoEXT
{
	VkStructureType											sType;
	const void*												pNext;
	VkPipelineRasterizationConservativeStateCreateFlagsEXT	flags;
	VkConservativeRasterizationModeEXT						conservativeRasterizationMode;
	float													extraPrimitiveOverestimationSize;
};

struct VkPhysicalDeviceDepthClipEnableFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		depthClipEnable;
};

struct VkPipelineRasterizationDepthClipStateCreateInfoEXT
{
	VkStructureType										sType;
	const void*											pNext;
	VkPipelineRasterizationDepthClipStateCreateFlagsEXT	flags;
	VkBool32											depthClipEnable;
};

struct VkXYColorEXT
{
	float	x;
	float	y;
};

struct VkHdrMetadataEXT
{
	VkStructureType	sType;
	const void*		pNext;
	VkXYColorEXT	displayPrimaryRed;
	VkXYColorEXT	displayPrimaryGreen;
	VkXYColorEXT	displayPrimaryBlue;
	VkXYColorEXT	whitePoint;
	float			maxLuminance;
	float			minLuminance;
	float			maxContentLightLevel;
	float			maxFrameAverageLightLevel;
};

struct VkDebugUtilsLabelEXT
{
	VkStructureType	sType;
	const void*		pNext;
	const char*		pLabelName;
	float			color[4];
};

struct VkDebugUtilsObjectNameInfoEXT
{
	VkStructureType	sType;
	const void*		pNext;
	VkObjectType	objectType;
	uint64_t		objectHandle;
	const char*		pObjectName;
};

struct VkDebugUtilsMessengerCallbackDataEXT
{
	VkStructureType								sType;
	const void*									pNext;
	VkDebugUtilsMessengerCallbackDataFlagsEXT	flags;
	const char*									pMessageIdName;
	int32_t										messageIdNumber;
	const char*									pMessage;
	uint32_t									queueLabelCount;
	const VkDebugUtilsLabelEXT*					pQueueLabels;
	uint32_t									cmdBufLabelCount;
	const VkDebugUtilsLabelEXT*					pCmdBufLabels;
	uint32_t									objectCount;
	const VkDebugUtilsObjectNameInfoEXT*		pObjects;
};

struct VkDebugUtilsMessengerCreateInfoEXT
{
	VkStructureType							sType;
	const void*								pNext;
	VkDebugUtilsMessengerCreateFlagsEXT		flags;
	VkDebugUtilsMessageSeverityFlagsEXT		messageSeverity;
	VkDebugUtilsMessageTypeFlagsEXT			messageType;
	PFN_vkDebugUtilsMessengerCallbackEXT	pfnUserCallback;
	void*									pUserData;
};

struct VkDebugUtilsObjectTagInfoEXT
{
	VkStructureType	sType;
	const void*		pNext;
	VkObjectType	objectType;
	uint64_t		objectHandle;
	uint64_t		tagName;
	size_t			tagSize;
	const void*		pTag;
};

struct VkSampleLocationEXT
{
	float	x;
	float	y;
};

struct VkSampleLocationsInfoEXT
{
	VkStructureType				sType;
	const void*					pNext;
	VkSampleCountFlagBits		sampleLocationsPerPixel;
	VkExtent2D					sampleLocationGridSize;
	uint32_t					sampleLocationsCount;
	const VkSampleLocationEXT*	pSampleLocations;
};

struct VkAttachmentSampleLocationsEXT
{
	uint32_t					attachmentIndex;
	VkSampleLocationsInfoEXT	sampleLocationsInfo;
};

struct VkSubpassSampleLocationsEXT
{
	uint32_t					subpassIndex;
	VkSampleLocationsInfoEXT	sampleLocationsInfo;
};

struct VkRenderPassSampleLocationsBeginInfoEXT
{
	VkStructureType							sType;
	const void*								pNext;
	uint32_t								attachmentInitialSampleLocationsCount;
	const VkAttachmentSampleLocationsEXT*	pAttachmentInitialSampleLocations;
	uint32_t								postSubpassSampleLocationsCount;
	const VkSubpassSampleLocationsEXT*		pPostSubpassSampleLocations;
};

struct VkPipelineSampleLocationsStateCreateInfoEXT
{
	VkStructureType				sType;
	const void*					pNext;
	VkBool32					sampleLocationsEnable;
	VkSampleLocationsInfoEXT	sampleLocationsInfo;
};

struct VkPhysicalDeviceSampleLocationsPropertiesEXT
{
	VkStructureType		sType;
	void*				pNext;
	VkSampleCountFlags	sampleLocationSampleCounts;
	VkExtent2D			maxSampleLocationGridSize;
	float				sampleLocationCoordinateRange[2];
	uint32_t			sampleLocationSubPixelBits;
	VkBool32			variableSampleLocations;
};

struct VkMultisamplePropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkExtent2D		maxSampleLocationGridSize;
};

struct VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		advancedBlendCoherentOperations;
};

struct VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		advancedBlendMaxColorAttachments;
	VkBool32		advancedBlendIndependentBlend;
	VkBool32		advancedBlendNonPremultipliedSrcColor;
	VkBool32		advancedBlendNonPremultipliedDstColor;
	VkBool32		advancedBlendCorrelatedOverlap;
	VkBool32		advancedBlendAllOperations;
};

struct VkPipelineColorBlendAdvancedStateCreateInfoEXT
{
	VkStructureType		sType;
	const void*			pNext;
	VkBool32			srcPremultiplied;
	VkBool32			dstPremultiplied;
	VkBlendOverlapEXT	blendOverlap;
};

struct VkDrmFormatModifierPropertiesEXT
{
	uint64_t				drmFormatModifier;
	uint32_t				drmFormatModifierPlaneCount;
	VkFormatFeatureFlags	drmFormatModifierTilingFeatures;
};

struct VkDrmFormatModifierPropertiesListEXT
{
	VkStructureType						sType;
	void*								pNext;
	uint32_t							drmFormatModifierCount;
	VkDrmFormatModifierPropertiesEXT*	pDrmFormatModifierProperties;
};

struct VkPhysicalDeviceImageDrmFormatModifierInfoEXT
{
	VkStructureType	sType;
	const void*		pNext;
	uint64_t		drmFormatModifier;
	VkSharingMode	sharingMode;
	uint32_t		queueFamilyIndexCount;
	const uint32_t*	pQueueFamilyIndices;
};

struct VkImageDrmFormatModifierListCreateInfoEXT
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		drmFormatModifierCount;
	const uint64_t*	pDrmFormatModifiers;
};

struct VkImageDrmFormatModifierExplicitCreateInfoEXT
{
	VkStructureType				sType;
	const void*					pNext;
	uint64_t					drmFormatModifier;
	uint32_t					drmFormatModifierPlaneCount;
	const VkSubresourceLayout*	pPlaneLayouts;
};

struct VkImageDrmFormatModifierPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	uint64_t		drmFormatModifier;
};

struct VkPhysicalDeviceImageViewImageFormatInfoEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkImageViewType	imageViewType;
};

struct VkFilterCubicImageViewImageFormatPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		filterCubic;
	VkBool32		filterCubicMinmax;
};

struct VkDeviceQueueGlobalPriorityCreateInfoEXT
{
	VkStructureType				sType;
	const void*					pNext;
	VkQueueGlobalPriorityEXT	globalPriority;
};

struct VkImportMemoryHostPointerInfoEXT
{
	VkStructureType						sType;
	const void*							pNext;
	VkExternalMemoryHandleTypeFlagBits	handleType;
	void*								pHostPointer;
};

struct VkMemoryHostPointerPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		memoryTypeBits;
};

struct VkPhysicalDeviceExternalMemoryHostPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkDeviceSize	minImportedHostPointerAlignment;
};

struct VkCalibratedTimestampInfoEXT
{
	VkStructureType	sType;
	const void*		pNext;
	VkTimeDomainEXT	timeDomain;
};

struct VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		maxVertexAttribDivisor;
};

struct VkVertexInputBindingDivisorDescriptionEXT
{
	uint32_t	binding;
	uint32_t	divisor;
};

struct VkPipelineVertexInputDivisorStateCreateInfoEXT
{
	VkStructureType										sType;
	const void*											pNext;
	uint32_t											vertexBindingDivisorCount;
	const VkVertexInputBindingDivisorDescriptionEXT*	pVertexBindingDivisors;
};

struct VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		vertexAttributeInstanceRateDivisor;
	VkBool32		vertexAttributeInstanceRateZeroDivisor;
};

struct VkPhysicalDevicePCIBusInfoPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		pciDomain;
	uint32_t		pciBus;
	uint32_t		pciDevice;
	uint32_t		pciFunction;
};

struct VkPhysicalDeviceSubgroupSizeControlFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		subgroupSizeControl;
	VkBool32		computeFullSubgroups;
};

struct VkPhysicalDeviceSubgroupSizeControlPropertiesEXT
{
	VkStructureType		sType;
	void*				pNext;
	uint32_t			minSubgroupSize;
	uint32_t			maxSubgroupSize;
	uint32_t			maxComputeWorkgroupSubgroups;
	VkShaderStageFlags	requiredSubgroupSizeStages;
};

struct VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		requiredSubgroupSize;
};

struct VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		shaderImageInt64Atomics;
	VkBool32		sparseImageInt64Atomics;
};

struct VkPhysicalDeviceMemoryBudgetPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkDeviceSize	heapBudget[VK_MAX_MEMORY_HEAPS];
	VkDeviceSize	heapUsage[VK_MAX_MEMORY_HEAPS];
};

struct VkValidationFeaturesEXT
{
	VkStructureType							sType;
	const void*								pNext;
	uint32_t								enabledValidationFeatureCount;
	const VkValidationFeatureEnableEXT*		pEnabledValidationFeatures;
	uint32_t								disabledValidationFeatureCount;
	const VkValidationFeatureDisableEXT*	pDisabledValidationFeatures;
};

struct VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		fragmentShaderSampleInterlock;
	VkBool32		fragmentShaderPixelInterlock;
	VkBool32		fragmentShaderShadingRateInterlock;
};

struct VkPhysicalDeviceYcbcrImageArraysFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		ycbcrImageArrays;
};

struct VkHeadlessSurfaceCreateInfoEXT
{
	VkStructureType					sType;
	const void*						pNext;
	VkHeadlessSurfaceCreateFlagsEXT	flags;
};

struct VkPhysicalDeviceLineRasterizationFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		rectangularLines;
	VkBool32		bresenhamLines;
	VkBool32		smoothLines;
	VkBool32		stippledRectangularLines;
	VkBool32		stippledBresenhamLines;
	VkBool32		stippledSmoothLines;
};

struct VkPhysicalDeviceLineRasterizationPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		lineSubPixelPrecisionBits;
};

struct VkPipelineRasterizationLineStateCreateInfoEXT
{
	VkStructureType				sType;
	const void*					pNext;
	VkLineRasterizationModeEXT	lineRasterizationMode;
	VkBool32					stippledLineEnable;
	uint32_t					lineStippleFactor;
	uint16_t					lineStipplePattern;
};

struct VkPhysicalDeviceShaderAtomicFloatFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		shaderBufferFloat32Atomics;
	VkBool32		shaderBufferFloat32AtomicAdd;
	VkBool32		shaderBufferFloat64Atomics;
	VkBool32		shaderBufferFloat64AtomicAdd;
	VkBool32		shaderSharedFloat32Atomics;
	VkBool32		shaderSharedFloat32AtomicAdd;
	VkBool32		shaderSharedFloat64Atomics;
	VkBool32		shaderSharedFloat64AtomicAdd;
	VkBool32		shaderImageFloat32Atomics;
	VkBool32		shaderImageFloat32AtomicAdd;
	VkBool32		sparseImageFloat32Atomics;
	VkBool32		sparseImageFloat32AtomicAdd;
};

struct VkPhysicalDeviceIndexTypeUint8FeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		indexTypeUint8;
};

struct VkPhysicalDeviceExtendedDynamicStateFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		extendedDynamicState;
};

struct VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		shaderDemoteToHelperInvocation;
};

struct VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		texelBufferAlignment;
};

struct VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkDeviceSize	storageTexelBufferOffsetAlignmentBytes;
	VkBool32		storageTexelBufferOffsetSingleTexelAlignment;
	VkDeviceSize	uniformTexelBufferOffsetAlignmentBytes;
	VkBool32		uniformTexelBufferOffsetSingleTexelAlignment;
};

struct VkPhysicalDeviceRobustness2FeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		robustBufferAccess2;
	VkBool32		robustImageAccess2;
	VkBool32		nullDescriptor;
};

struct VkPhysicalDeviceRobustness2PropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkDeviceSize	robustStorageBufferAccessSizeAlignment;
	VkDeviceSize	robustUniformBufferAccessSizeAlignment;
};

struct VkSamplerCustomBorderColorCreateInfoEXT
{
	VkStructureType		sType;
	const void*			pNext;
	VkClearColorValue	customBorderColor;
	VkFormat			format;
};

struct VkPhysicalDeviceCustomBorderColorPropertiesEXT
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		maxCustomBorderColorSamplers;
};

struct VkPhysicalDeviceCustomBorderColorFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		customBorderColors;
	VkBool32		customBorderColorWithoutFormat;
};

struct VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		ycbcr2plane444Formats;
};

struct VkPhysicalDeviceImageRobustnessFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		robustImageAccess;
};

struct VkPhysicalDevice4444FormatsFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		formatA4R4G4B4;
	VkBool32		formatA4B4G4R4;
};

struct VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		vertexInputDynamicState;
};

struct VkVertexInputBindingDescription2EXT
{
	VkStructureType		sType;
	void*				pNext;
	uint32_t			binding;
	uint32_t			stride;
	VkVertexInputRate	inputRate;
	uint32_t			divisor;
};

struct VkVertexInputAttributeDescription2EXT
{
	VkStructureType	sType;
	void*			pNext;
	uint32_t		location;
	uint32_t		binding;
	VkFormat		format;
	uint32_t		offset;
};

struct VkPhysicalDeviceExtendedDynamicState2FeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		extendedDynamicState2;
	VkBool32		extendedDynamicState2LogicOp;
	VkBool32		extendedDynamicState2PatchControlPoints;
};

struct VkPhysicalDeviceColorWriteEnableFeaturesEXT
{
	VkStructureType	sType;
	void*			pNext;
	VkBool32		colorWriteEnable;
};

struct VkPipelineColorWriteCreateInfoEXT
{
	VkStructureType	sType;
	const void*		pNext;
	uint32_t		attachmentCount;
	const VkBool32*	pColorWriteEnables;
};

typedef VkPhysicalDeviceVariablePointersFeatures VkPhysicalDeviceVariablePointerFeatures;

typedef VkPhysicalDeviceShaderDrawParametersFeatures VkPhysicalDeviceShaderDrawParameterFeatures;

