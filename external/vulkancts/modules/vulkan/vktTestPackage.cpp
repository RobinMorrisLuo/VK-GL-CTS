/*-------------------------------------------------------------------------
 * Vulkan Conformance Tests
 * ------------------------
 *
 * Copyright (c) 2015 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *//*!
 * \file
 * \brief Vulkan Test Package
 *//*--------------------------------------------------------------------*/

#include "vktTestPackage.hpp"

#include "qpDebugOut.h"

#include "tcuPlatform.hpp"
#include "tcuTestCase.hpp"
#include "tcuTestLog.hpp"
#include "tcuCommandLine.hpp"
#include "tcuWaiverUtil.hpp"

#include "vkPlatform.hpp"
#include "vkPrograms.hpp"
#include "vkBinaryRegistry.hpp"
#include "vkShaderToSpirV.hpp"
#include "vkDebugReportUtil.hpp"
#include "vkQueryUtil.hpp"
#include "vkApiVersion.hpp"
#include "vkRenderDocUtil.hpp"
#include "vkResourceInterface.hpp"

#include "deUniquePtr.hpp"
#include "deSharedPtr.hpp"
#ifdef CTS_USES_VULKANSC
	#include "deProcess.h"
#endif // CTS_USES_VULKANSC

#include "vktTestGroupUtil.hpp"
#include "vktApiTests.hpp"
#include "vktPipelineTests.hpp"
#include "vktBindingModelTests.hpp"
#include "vktSpvAsmTests.hpp"
#include "vktShaderLibrary.hpp"
#include "vktRenderPassTests.hpp"
#include "vktMemoryTests.hpp"
#include "vktShaderRenderBuiltinVarTests.hpp"
#include "vktShaderRenderDerivateTests.hpp"
#include "vktShaderRenderDiscardTests.hpp"
#include "vktShaderRenderIndexingTests.hpp"
#include "vktShaderRenderInvarianceTests.hpp"
#include "vktShaderRenderLimitTests.hpp"
#include "vktShaderRenderLoopTests.hpp"
#include "vktShaderRenderMatrixTests.hpp"
#include "vktShaderRenderOperatorTests.hpp"
#include "vktShaderRenderReturnTests.hpp"
#include "vktShaderRenderStructTests.hpp"
#include "vktShaderRenderSwitchTests.hpp"
#include "vktShaderRenderTextureFunctionTests.hpp"
#include "vktShaderRenderTextureGatherTests.hpp"
#include "vktShaderBuiltinTests.hpp"
#include "vktOpaqueTypeIndexingTests.hpp"
#include "vktAtomicOperationTests.hpp"
#include "vktUniformBlockTests.hpp"
#include "vktDynamicStateTests.hpp"
#include "vktSSBOLayoutTests.hpp"
#include "vktQueryPoolTests.hpp"
#include "vktDrawTests.hpp"
#include "vktComputeTests.hpp"
#include "vktConditionalTests.hpp"
#include "vktImageTests.hpp"
#include "vktInfoTests.hpp"
#include "vktWsiTests.hpp"
#include "vktSynchronizationTests.hpp"
#include "vktSparseResourcesTests.hpp"
#include "vktTessellationTests.hpp"
#include "vktRasterizationTests.hpp"
#include "vktClippingTests.hpp"
#include "vktFragmentOperationsTests.hpp"
#include "vktTextureTests.hpp"
#include "vktGeometryTests.hpp"
#include "vktRobustnessTests.hpp"
#include "vktMultiViewTests.hpp"
#include "vktSubgroupsTests.hpp"
#include "vktYCbCrTests.hpp"
#include "vktProtectedMemTests.hpp"
#include "vktDeviceGroupTests.hpp"
#include "vktMemoryModelTests.hpp"
#include "vktAmberGraphicsFuzzTests.hpp"
#include "vktAmberGlslTests.hpp"
#include "vktImagelessFramebufferTests.hpp"
#include "vktTransformFeedbackTests.hpp"
#include "vktDescriptorIndexingTests.hpp"
#include "vktImagelessFramebufferTests.hpp"
#include "vktFragmentShaderInterlockTests.hpp"
#include "vktShaderClockTests.hpp"
#include "vktModifiersTests.hpp"
#include "vktRayTracingTests.hpp"
#include "vktRayQueryTests.hpp"
#include "vktPostmortemTests.hpp"
#include "vktFragmentShadingRateTests.hpp"
#include "vktReconvergenceTests.hpp"

#include <vector>
#include <sstream>

namespace vkt
{

using std::vector;
using de::UniquePtr;
using de::SharedPtr;
using de::MovePtr;
using tcu::TestLog;

// TestCaseExecutor

class TestCaseExecutor : public tcu::TestCaseExecutor
{
public:
												TestCaseExecutor	(tcu::TestContext& testCtx);
												~TestCaseExecutor	(void);

	void										init				(tcu::TestCase* testCase, const std::string& path) override;
	void										deinit				(tcu::TestCase* testCase) override;

	tcu::TestNode::IterateResult				iterate				(tcu::TestCase* testCase) override;

	void										deinitTestPackage	(tcu::TestContext& testCtx) override;
	bool										usesLocalStatus		() override;
	void										updateGlobalStatus	(tcu::TestRunStatus& status) override;

private:
	void										logUnusedShaders	(tcu::TestCase* testCase);

	void										runTestsInSubprocess(tcu::TestContext& testCtx);

	bool										spirvVersionSupported(vk::SpirvVersion);

	vk::BinaryCollection						m_progCollection;
	vk::BinaryRegistryReader					m_prebuiltBinRegistry;

	const UniquePtr<vk::Library>				m_library;
	MovePtr<Context>							m_context;

	const UniquePtr<vk::RenderDocUtil>			m_renderDoc;
	SharedPtr<vk::ResourceInterface>			m_resourceInterface;
	vk::VkPhysicalDeviceProperties				m_deviceProperties;
	tcu::WaiverUtil								m_waiverMechanism;

	TestInstance*								m_instance;			//!< Current test case instance
	std::vector<std::string>					m_testsForSubprocess;
	tcu::TestRunStatus							m_status;
};

static MovePtr<vk::Library> createLibrary (tcu::TestContext& testCtx)
{
	return MovePtr<vk::Library>(testCtx.getPlatform().getVulkanPlatform().createLibrary());
}

static vk::VkPhysicalDeviceProperties getPhysicalDeviceProperties(vkt::Context& context)
{
	const vk::InstanceInterface&	vki				= context.getInstanceInterface();
	const vk::VkPhysicalDevice		physicalDevice	= context.getPhysicalDevice();

	vk::VkPhysicalDeviceProperties	properties;
	vki.getPhysicalDeviceProperties(physicalDevice, &properties);
	return properties;
}

TestCaseExecutor::TestCaseExecutor (tcu::TestContext& testCtx)
	: m_prebuiltBinRegistry	(testCtx.getArchive(), "vulkan/prebuilt")
	, m_library				(createLibrary(testCtx))
	, m_renderDoc			(testCtx.getCommandLine().isRenderDocEnabled()
							 ? MovePtr<vk::RenderDocUtil>(new vk::RenderDocUtil())
							 : MovePtr<vk::RenderDocUtil>(DE_NULL))
#ifndef CTS_USES_VULKAN
	, m_resourceInterface	(new vk::ResourceInterfaceStandard(testCtx))
#else // TODO: for now Vulkan SC uses the same method to access resources. In M3 we will create new subclass for Vulkan SC
	, m_resourceInterface	(new vk::ResourceInterfaceStandard(testCtx))
#endif // CTS_USES_VULKAN
	, m_instance			(DE_NULL)
{
#ifdef CTS_USES_VULKANSC
	if (testCtx.getCommandLine().isSubProcess())
	{
		std::vector<int> caseFraction = testCtx.getCommandLine().getCaseFraction();
		std::ostringstream jsonFileName;
		if (caseFraction.empty())
			jsonFileName << "pipeline_data.json";
		else
			jsonFileName << "pipeline_data_" << caseFraction[0] << ".json";
		m_resourceInterface->importDataFromFile(jsonFileName.str());
	}
#endif // CTS_USES_VULKANSC

	m_context			= MovePtr<Context>(new Context(testCtx, m_library->getPlatformInterface(), m_progCollection, m_resourceInterface));
	m_deviceProperties	= getPhysicalDeviceProperties(*m_context);

	tcu::SessionInfo sessionInfo(m_deviceProperties.vendorID,
								 m_deviceProperties.deviceID,
								 testCtx.getCommandLine().getInitialCmdLine());
	m_waiverMechanism.setup(testCtx.getCommandLine().getWaiverFileName(),
							"dEQP-VK",
							m_deviceProperties.vendorID,
							m_deviceProperties.deviceID,
							sessionInfo);
	testCtx.getLog().writeSessionInfo(sessionInfo.get());

#ifdef CTS_USES_VULKANSC
	// Real Vulkan SC tests are performed in subprocess.
	// Tests run in main process are only used to collect data required by Vulkan SC.
	// That's why we turn off any output in main process and copy output from subprocess when subprocess tests are performed
	if (!testCtx.getCommandLine().isSubProcess())
	{
		qpSuppressOutput(1);
		m_context->getTestContext().getLog().supressLogging(true);
	}
#endif // CTS_USES_VULKANSC
}

TestCaseExecutor::~TestCaseExecutor (void)
{
	delete m_instance;
}

void TestCaseExecutor::init (tcu::TestCase* testCase, const std::string& casePath)
{
	TestCase*					vktCase						= dynamic_cast<TestCase*>(testCase);
	tcu::TestLog&				log							= m_context->getTestContext().getLog();
	const deUint32				usedVulkanVersion			= m_context->getUsedApiVersion();
	const vk::SpirvVersion		baselineSpirvVersion		= vk::getBaselineSpirvVersion(usedVulkanVersion);
	vk::ShaderBuildOptions		defaultGlslBuildOptions		(usedVulkanVersion, baselineSpirvVersion, 0u);
	vk::ShaderBuildOptions		defaultHlslBuildOptions		(usedVulkanVersion, baselineSpirvVersion, 0u);
	vk::SpirVAsmBuildOptions	defaultSpirvAsmBuildOptions	(usedVulkanVersion, baselineSpirvVersion);
	vk::SourceCollections		sourceProgs					(usedVulkanVersion, defaultGlslBuildOptions, defaultHlslBuildOptions, defaultSpirvAsmBuildOptions);
	const tcu::CommandLine&		commandLine					= m_context->getTestContext().getCommandLine();
	const bool					doShaderLog					= commandLine.isLogDecompiledSpirvEnabled() && log.isShaderLoggingEnabled();

	if (!vktCase)
		TCU_THROW(InternalError, "Test node not an instance of vkt::TestCase");

	if (!m_context->getTestContext().getCommandLine().isSubProcess())
	{
		m_testsForSubprocess.push_back(casePath);
		m_resourceInterface->initTestCase(casePath);
	}

	if (m_waiverMechanism.isOnWaiverList(casePath))
		throw tcu::TestException("Waived test", QP_TEST_RESULT_WAIVER);

	vktCase->checkSupport(*m_context);

	vktCase->delayedInit();

	m_progCollection.clear();
	vktCase->initPrograms(sourceProgs);

	for (vk::GlslSourceCollection::Iterator progIter = sourceProgs.glslSources.begin(); progIter != sourceProgs.glslSources.end(); ++progIter)
	{
		if (!spirvVersionSupported(progIter.getProgram().buildOptions.targetVersion))
			TCU_THROW(NotSupportedError, "Shader requires SPIR-V higher than available");

		const vk::ProgramBinary* const binProg = m_resourceInterface->buildProgram<glu::ShaderProgramInfo, vk::GlslSourceCollection::Iterator>(casePath, progIter, m_prebuiltBinRegistry, &m_progCollection);

		if (doShaderLog)
		{
			try
			{
				std::ostringstream disasm;

				vk::disassembleProgram(*binProg, &disasm);

				log << vk::SpirVAsmSource(disasm.str());
			}
			catch (const tcu::NotSupportedError& err)
			{
				log << err;
			}
		}
	}

	for (vk::HlslSourceCollection::Iterator progIter = sourceProgs.hlslSources.begin(); progIter != sourceProgs.hlslSources.end(); ++progIter)
	{
		if (!spirvVersionSupported(progIter.getProgram().buildOptions.targetVersion))
			TCU_THROW(NotSupportedError, "Shader requires SPIR-V higher than available");

		const vk::ProgramBinary* const binProg = m_resourceInterface->buildProgram<glu::ShaderProgramInfo, vk::HlslSourceCollection::Iterator>(casePath, progIter, m_prebuiltBinRegistry, &m_progCollection);

		if (doShaderLog)
		{
			try
			{
				std::ostringstream disasm;

				vk::disassembleProgram(*binProg, &disasm);

				log << vk::SpirVAsmSource(disasm.str());
			}
			catch (const tcu::NotSupportedError& err)
			{
				log << err;
			}
		}
	}

	for (vk::SpirVAsmCollection::Iterator asmIterator = sourceProgs.spirvAsmSources.begin(); asmIterator != sourceProgs.spirvAsmSources.end(); ++asmIterator)
	{
		if (!spirvVersionSupported(asmIterator.getProgram().buildOptions.targetVersion))
			TCU_THROW(NotSupportedError, "Shader requires SPIR-V higher than available");

		m_resourceInterface->buildProgram<vk::SpirVProgramInfo, vk::SpirVAsmCollection::Iterator>(casePath, asmIterator, m_prebuiltBinRegistry, &m_progCollection);
	}

	if (m_renderDoc) m_renderDoc->startFrame(m_context->getInstance());

	DE_ASSERT(!m_instance);
	m_instance = vktCase->createInstance(*m_context);
	m_context->resultSetOnValidation(false);
}

void TestCaseExecutor::deinit (tcu::TestCase* testCase)
{
	delete m_instance;
	m_instance = DE_NULL;

	if (m_renderDoc) m_renderDoc->endFrame(m_context->getInstance());

	// Collect and report any debug messages
#ifndef CTS_USES_VULKANSC
	if (m_context->hasDebugReportRecorder())
		collectAndReportDebugMessages(m_context->getDebugReportRecorder(), *m_context);
#endif // CTS_USES_VULKANSC

	if (testCase != DE_NULL)
		logUnusedShaders(testCase);

#ifdef CTS_USES_VULKANSC
	if (!m_context->getTestContext().getCommandLine().isSubProcess())
	{
		if (m_testsForSubprocess.size() >= std::size_t(m_context->getTestContext().getCommandLine().getSubprocessTestCount()) )
		{
			runTestsInSubprocess(m_context->getTestContext());

			// Clean up data after performing tests in subprocess and prepare system for another batch of tests
			m_testsForSubprocess.clear();
			m_resourceInterface->resetObjects();
			const vk::DeviceInterface&				vkd						= m_context->getDeviceInterface();
			const vk::DeviceDriverSC*				dds						= dynamic_cast<const vk::DeviceDriverSC*>(&vkd);
			if (dds == DE_NULL)
				TCU_THROW(InternalError, "Undefined device driver for Vulkan SC");
			dds->resetStatistics();

			qpSuppressOutput(1);
			m_context->getTestContext().getLog().supressLogging(true);
		}
	}
#endif // CTS_USES_VULKANSC
}

void TestCaseExecutor::logUnusedShaders (tcu::TestCase* testCase)
{
	const qpTestResult	testResult	= testCase->getTestContext().getTestResult();

	if (testResult == QP_TEST_RESULT_PASS || testResult == QP_TEST_RESULT_QUALITY_WARNING || testResult == QP_TEST_RESULT_COMPATIBILITY_WARNING)
	{
		bool	unusedShaders	= false;

		for (vk::BinaryCollection::Iterator it = m_progCollection.begin(); it != m_progCollection.end(); ++it)
		{
			if (!it.getProgram().getUsed())
			{
				unusedShaders = true;

				break;
			}
		}

		if (unusedShaders)
		{
			std::string message;

			for (vk::BinaryCollection::Iterator it = m_progCollection.begin(); it != m_progCollection.end(); ++it)
			{
				if (!it.getProgram().getUsed())
					message += it.getName() + ",";
			}

			message.resize(message.size() - 1);

			message = std::string("Unused shaders: ") + message;

			m_context->getTestContext().getLog() << TestLog::Message << message << TestLog::EndMessage;
		}
	}
}

tcu::TestNode::IterateResult TestCaseExecutor::iterate (tcu::TestCase*)
{
	DE_ASSERT(m_instance);

	const tcu::TestStatus	result	= m_instance->iterate();

	if (result.isComplete())
	{
		// Vulkan tests shouldn't set result directly except when using a debug report messenger to catch validation errors.
		DE_ASSERT(m_context->getTestContext().getTestResult() == QP_TEST_RESULT_LAST || m_context->resultSetOnValidation());

		// Override result if not set previously by a debug report messenger.
		if (!m_context->resultSetOnValidation())
			m_context->getTestContext().setTestResult(result.getCode(), result.getDescription().c_str());
		return tcu::TestNode::STOP;
	}
	else
		return tcu::TestNode::CONTINUE;
}

void TestCaseExecutor::deinitTestPackage (tcu::TestContext& testCtx)
{
#ifdef CTS_USES_VULKANSC
	if (!testCtx.getCommandLine().isSubProcess())
	{
		if (!m_testsForSubprocess.empty())
		{
			runTestsInSubprocess(testCtx);

			// Clean up data after performing tests in subprocess and prepare system for another batch of tests
			m_testsForSubprocess.clear();
			const vk::DeviceInterface&				vkd						= m_context->getDeviceInterface();
			const vk::DeviceDriverSC*				dds						= dynamic_cast<const vk::DeviceDriverSC*>(&vkd);
			if (dds == DE_NULL)
				TCU_THROW(InternalError, "Undefined device driver for Vulkan SC");
			dds->resetStatistics();
			m_resourceInterface->resetObjects();
		}
		// Tests are finished. Next tests ( if any ) will come from other test package and test executor
		qpSuppressOutput(0);
		m_context->getTestContext().getLog().supressLogging(false);
	}
#else
	DE_UNREF(testCtx);
#endif // CTS_USES_VULKANSC
}

bool TestCaseExecutor::usesLocalStatus ()
{
#ifdef CTS_USES_VULKANSC
	return !m_context->getTestContext().getCommandLine().isSubProcess();
#else
	return false;
#endif
}

void TestCaseExecutor::updateGlobalStatus(tcu::TestRunStatus& status)
{
	status.numExecuted					+= m_status.numExecuted;
	status.numPassed					+= m_status.numPassed;
	status.numNotSupported				+= m_status.numNotSupported;
	status.numWarnings					+= m_status.numWarnings;
	status.numWaived					+= m_status.numWaived;
	status.numFailed					+= m_status.numFailed;
	m_status.clear();
}

void TestCaseExecutor::runTestsInSubprocess (tcu::TestContext& testCtx)
{
#ifdef CTS_USES_VULKANSC
	if (testCtx.getCommandLine().isSubProcess())
		TCU_THROW(TestError, "Cannot run subprocess inside subprocess : ");

	if (m_testsForSubprocess.empty())
		return;

	std::vector<int>	caseFraction	= testCtx.getCommandLine().getCaseFraction();
	std::ostringstream	jsonFileName, qpaFileName;
	if (caseFraction.empty())
	{
		jsonFileName	<< "pipeline_data.json";
		qpaFileName		<< "sub.qpa";
	}
	else
	{
		jsonFileName	<< "pipeline_data_" << caseFraction[0] << ".json";
		qpaFileName		<< "sub_" << caseFraction[0] << ".qpa";
	}

	// export data collected during statistics gathering to JSON file ( VkDeviceObjectReservationCreateInfo, SPIR-V shaders, pipelines )
	{
		const vk::DeviceInterface&				vkd						= m_context->getDeviceInterface();
		const vk::DeviceDriverSC*				dds						= dynamic_cast<const vk::DeviceDriverSC*>(&vkd);
		if (dds == DE_NULL)
			TCU_THROW(InternalError, "Undefined device driver for Vulkan SC");
		vk::VkDeviceObjectReservationCreateInfo	memoryReservation		= dds->getStatistics();
		std::string								jsonMemoryReservation	= writeJSON_VkDeviceObjectReservationCreateInfo(memoryReservation);

		m_resourceInterface->removeRedundantObjects();
		m_resourceInterface->exportDataToFile(jsonFileName.str(), jsonMemoryReservation);
	}

	// collect current application name, add it to new commandline with subprocess parameters
	std::string								newCmdLine;
	{
		std::string appName = testCtx.getCommandLine().getApplicationName();
		if (appName.empty())
			TCU_THROW(TestError, "Application name is not defined");
		// add --deqp-subprocess option to inform deqp-vksc process that it works as slave process
		newCmdLine = appName + " --deqp-subprocess=enable --deqp-log-filename=" + qpaFileName.str();
	}

	// collect parameters, remove parameters associated with case filter and case fraction. We will provide our own case list
	{
		std::string							originalCmdLine		= testCtx.getCommandLine().getInitialCmdLine();
		std::stringstream					ss					(originalCmdLine);
		std::string item;
		std::vector<std::string>			skipElements		= {
			"--deqp-case",
			"--deqp-stdin-caselist",
			"--deqp-log-filename"
		};
		while (std::getline(ss, item, ' '))
		{
			bool skipElement = false;
			for (const auto& elem : skipElements)
				if (item.rfind(elem, 0) == 0)
				{
					skipElement = true;
					break;
				}
			if (skipElement)
				continue;
			newCmdLine = newCmdLine + " " + item;
		}
	}

	// create --deqp-case list from tests collected in m_testsForSubprocess
	std::string subprocessTestList;
	for (auto it = begin(m_testsForSubprocess); it != end(m_testsForSubprocess); ++it)
	{
		auto nit = it; ++nit;

		subprocessTestList += *it;
		if (nit != end(m_testsForSubprocess))
			subprocessTestList += ",";
	}
	newCmdLine = newCmdLine + " --deqp-case=" + subprocessTestList;

	// restore cout and cerr
	qpSuppressOutput(0);

	// create subprocess which will perform real tests
	{
		deProcess*	process			= deProcess_create();
		if (deProcess_start(process, newCmdLine.c_str(), ".") != DE_TRUE)
		{
			std::string err = deProcess_getLastError(process);
			deProcess_destroy(process);
			process = DE_NULL;
			TCU_THROW(TestError, "Error while running subprocess : " + err);
		}

		deFile*		subOutput		= deProcess_getStdOut(process);
		char		outBuffer[128]	= { 0 };
		deInt64		numRead			= 0;
		while (deFile_read(subOutput, outBuffer, sizeof(outBuffer) - 1, &numRead) == DE_FILERESULT_SUCCESS)
		{
			outBuffer[numRead] = 0;
			qpPrint(outBuffer);
		}
		deProcess_waitForFinish(process);
		deProcess_destroy(process);
	}

	// restore logging
	testCtx.getLog().supressLogging(false);

	// copy test information from sub.qpa to main log
	{
		deFile*				subQpa			= deFile_create(qpaFileName.str().c_str(), DE_FILEMODE_OPEN | DE_FILEMODE_READ);
		deInt64				subQpaSize		= deFile_getSize(subQpa);
		std::vector<char>	subQpaContents	(static_cast<std::size_t>(subQpaSize));
		deInt64				numRead			= 0;

		deFile_read(subQpa, subQpaContents.data(), subQpaSize, &numRead);
		std::string			subQpaText		(subQpaContents.data(), std::size_t(subQpaSize));
		deFile_destroy(subQpa);

		{
			std::string			beginText		("#beginTestCaseResult");
			std::string			endText			("#endTestCaseResult");
			std::size_t			beginPos		= subQpaText.find(beginText);
			std::size_t			endPos			= subQpaText.rfind(endText);
			if (beginPos == std::string::npos || endPos == std::string::npos)
				TCU_THROW(TestError, "Couldn't match tags from " + qpaFileName.str());

			std::string		subQpaCopy = "\n" + std::string(subQpaText.begin() + beginPos, subQpaText.begin() + endPos + endText.size()) + "\n";
			testCtx.getLog().writeRaw(subQpaCopy.c_str());
		}

		{
			std::string			beginStat		("#SubProcessStatus");
			std::size_t			beginPos		= subQpaText.find(beginStat);
			if (beginPos == std::string::npos)
				TCU_THROW(TestError, "Couldn't match #SubProcessStatus tag from " + qpaFileName.str());

			std::string			subQpaStat		(subQpaText.begin() + beginPos + beginStat.size(), subQpaText.end());

			std::istringstream	str(subQpaStat);
			int					numExecuted, numPassed, numNotSupported, numWarnings, numWaived, numFailed;
			str >> numExecuted >> numPassed >> numNotSupported >> numWarnings >> numWaived >> numFailed;

			m_status.numExecuted				+= numExecuted;
			m_status.numPassed					+= numPassed;
			m_status.numNotSupported			+= numNotSupported;
			m_status.numWarnings				+= numWarnings;
			m_status.numWaived					+= numWaived;
			m_status.numFailed					+= numFailed;
		}
		deDeleteFile(qpaFileName.str().c_str());
	}
#else
	DE_UNREF(testCtx);
#endif // CTS_USES_VULKANSC
}

bool TestCaseExecutor::spirvVersionSupported (vk::SpirvVersion spirvVersion)
{
	if (spirvVersion <= vk::getMaxSpirvVersionForVulkan(m_context->getUsedApiVersion()))
		return true;

	if (spirvVersion <= vk::SPIRV_VERSION_1_4)
		return m_context->isDeviceFunctionalitySupported("VK_KHR_spirv_1_4");

	return false;
}

// GLSL shader tests

#ifndef CTS_USES_VULKANSC

void createGlslTests (tcu::TestCaseGroup* glslTests)
{
	tcu::TestContext&	testCtx		= glslTests->getTestContext();

	// ShaderLibrary-based tests
	static const struct
	{
		const char*		name;
		const char*		description;
	} s_es310Tests[] =
	{
		{ "arrays",						"Arrays"					},
		{ "conditionals",				"Conditional statements"	},
		{ "constant_expressions",		"Constant expressions"		},
		{ "constants",					"Constants"					},
		{ "conversions",				"Type conversions"			},
		{ "functions",					"Functions"					},
		{ "linkage",					"Linking"					},
		{ "scoping",					"Scoping"					},
		{ "swizzles",					"Swizzles"					},
	};

	for (int ndx = 0; ndx < DE_LENGTH_OF_ARRAY(s_es310Tests); ndx++)
		glslTests->addChild(createShaderLibraryGroup(testCtx,
													 s_es310Tests[ndx].name,
													 s_es310Tests[ndx].description,
													 std::string("vulkan/glsl/es310/") + s_es310Tests[ndx].name + ".test").release());

	static const struct
	{
		const char*		name;
		const char*		description;
	} s_440Tests[] =
	{
		{ "linkage",					"Linking"					},
	};

	de::MovePtr<tcu::TestCaseGroup> glsl440Tests = de::MovePtr<tcu::TestCaseGroup>(new tcu::TestCaseGroup(testCtx, "440", ""));

	for (int ndx = 0; ndx < DE_LENGTH_OF_ARRAY(s_440Tests); ndx++)
		glsl440Tests->addChild(createShaderLibraryGroup(testCtx,
													 s_440Tests[ndx].name,
													 s_440Tests[ndx].description,
													 std::string("vulkan/glsl/440/") + s_440Tests[ndx].name + ".test").release());

	glslTests->addChild(glsl440Tests.release());

	// ShaderRenderCase-based tests
	glslTests->addChild(sr::createDerivateTests			(testCtx));
	glslTests->addChild(sr::createDiscardTests			(testCtx));
	glslTests->addChild(sr::createDemoteTests			(testCtx));
	glslTests->addChild(sr::createIndexingTests			(testCtx));
	glslTests->addChild(sr::createShaderInvarianceTests	(testCtx));
	glslTests->addChild(sr::createLimitTests			(testCtx));
	glslTests->addChild(sr::createLoopTests				(testCtx));
	glslTests->addChild(sr::createMatrixTests			(testCtx));
	glslTests->addChild(sr::createOperatorTests			(testCtx));
	glslTests->addChild(sr::createReturnTests			(testCtx));
	glslTests->addChild(sr::createStructTests			(testCtx));
	glslTests->addChild(sr::createSwitchTests			(testCtx));
	glslTests->addChild(sr::createTextureFunctionTests	(testCtx));
	glslTests->addChild(sr::createTextureGatherTests	(testCtx));
	glslTests->addChild(sr::createBuiltinVarTests		(testCtx));

	// ShaderExecutor-based tests
	glslTests->addChild(shaderexecutor::createBuiltinTests				(testCtx));
	glslTests->addChild(shaderexecutor::createOpaqueTypeIndexingTests	(testCtx));
	glslTests->addChild(shaderexecutor::createAtomicOperationTests		(testCtx));
	glslTests->addChild(shaderexecutor::createShaderClockTests			(testCtx));

	// Amber GLSL tests.
	glslTests->addChild(cts_amber::createCombinedOperationsGroup		(testCtx));
}

#endif // CTS_USES_VULKANSC

// TestPackage

BaseTestPackage::BaseTestPackage (tcu::TestContext& testCtx, const char* name, const char* desc)
	: tcu::TestPackage(testCtx, name, desc)
{
}

BaseTestPackage::~BaseTestPackage (void)
{
}

#ifdef CTS_USES_VULKAN

TestPackage::TestPackage (tcu::TestContext& testCtx)
	: BaseTestPackage(testCtx, "dEQP-VK", "dEQP Vulkan Tests")
{
}

TestPackage::~TestPackage (void)
{
}

ExperimentalTestPackage::ExperimentalTestPackage (tcu::TestContext& testCtx)
	: BaseTestPackage(testCtx, "dEQP-VK-experimental", "dEQP Vulkan Experimental Tests")
{
}

ExperimentalTestPackage::~ExperimentalTestPackage (void)
{
}

#endif

#ifdef CTS_USES_VULKANSC

TestPackageSC::TestPackageSC (tcu::TestContext& testCtx)
	: BaseTestPackage(testCtx, "dEQP-VKSC", "dEQP Vulkan SC Tests")
{
}

TestPackageSC::~TestPackageSC (void)
{
}

#endif // CTS_USES_VULKANSC

tcu::TestCaseExecutor* BaseTestPackage::createExecutor (void) const
{
	return new TestCaseExecutor(m_testCtx);
}

#ifdef CTS_USES_VULKAN

void TestPackage::init (void)
{
	addChild(createTestGroup					(m_testCtx, "info", "Build and Device Info Tests", createInfoTests));
	addChild(api::createTests					(m_testCtx));
	addChild(memory::createTests				(m_testCtx));
	addChild(pipeline::createTests				(m_testCtx));
	addChild(BindingModel::createTests			(m_testCtx));
	addChild(SpirVAssembly::createTests			(m_testCtx));
	addChild(createTestGroup					(m_testCtx, "glsl", "GLSL shader execution tests", createGlslTests));
	addChild(createRenderPassTests				(m_testCtx));
	addChild(createRenderPass2Tests				(m_testCtx));
	addChild(ubo::createTests					(m_testCtx));
	addChild(DynamicState::createTests			(m_testCtx));
	addChild(ssbo::createTests					(m_testCtx));
	addChild(QueryPool::createTests				(m_testCtx));
	addChild(Draw::createTests					(m_testCtx));
	addChild(compute::createTests				(m_testCtx));
	addChild(image::createTests					(m_testCtx));
	addChild(wsi::createTests					(m_testCtx));
	addChild(createSynchronizationTests			(m_testCtx));
	addChild(createSynchronization2Tests		(m_testCtx));
	addChild(sparse::createTests				(m_testCtx));
	addChild(tessellation::createTests			(m_testCtx));
	addChild(rasterization::createTests			(m_testCtx));
	addChild(clipping::createTests				(m_testCtx));
	addChild(FragmentOperations::createTests	(m_testCtx));
	addChild(texture::createTests				(m_testCtx));
	addChild(geometry::createTests				(m_testCtx));
	addChild(robustness::createTests			(m_testCtx));
	addChild(MultiView::createTests				(m_testCtx));
	addChild(subgroups::createTests				(m_testCtx));
	addChild(ycbcr::createTests					(m_testCtx));
	addChild(ProtectedMem::createTests			(m_testCtx));
	addChild(DeviceGroup::createTests			(m_testCtx));
	addChild(MemoryModel::createTests			(m_testCtx));
	addChild(conditional::createTests			(m_testCtx));
	addChild(cts_amber::createGraphicsFuzzTests	(m_testCtx));
	addChild(imageless::createTests				(m_testCtx));
	addChild(TransformFeedback::createTests		(m_testCtx));
	addChild(DescriptorIndexing::createTests	(m_testCtx));
	addChild(FragmentShaderInterlock::createTests(m_testCtx));
	addChild(modifiers::createTests				(m_testCtx));
	addChild(RayTracing::createTests			(m_testCtx));
	addChild(RayQuery::createTests				(m_testCtx));
	addChild(FragmentShadingRate::createTests	(m_testCtx));
	addChild(Reconvergence::createTests			(m_testCtx, false));
}

void ExperimentalTestPackage::init (void)
{
	addChild(postmortem::createTests			(m_testCtx));
	addChild(Reconvergence::createTests			(m_testCtx, true));
}

#endif

#ifdef CTS_USES_VULKANSC

void TestPackageSC::init (void)
{
	addChild(createTestGroup					(m_testCtx, "info", "Build and Device Info Tests", createInfoTests));
	addChild(api::createTests					(m_testCtx));
//	addChild(memory::createTests				(m_testCtx));
//	addChild(pipeline::createTests				(m_testCtx));
//	addChild(BindingModel::createTests			(m_testCtx));
//	addChild(SpirVAssembly::createTests			(m_testCtx));
//	addChild(createTestGroup					(m_testCtx, "glsl", "GLSL shader execution tests", createGlslTests));
//	addChild(createRenderPassTests				(m_testCtx));
//	addChild(createRenderPass2Tests				(m_testCtx));
//	addChild(ubo::createTests					(m_testCtx));
//	addChild(DynamicState::createTests			(m_testCtx));
//	addChild(ssbo::createTests					(m_testCtx));
//	addChild(QueryPool::createTests				(m_testCtx));
//	addChild(Draw::createTests					(m_testCtx));
//	addChild(compute::createTests				(m_testCtx));
//	addChild(image::createTests					(m_testCtx));
//	addChild(wsi::createTests					(m_testCtx));
//	addChild(synchronization::createTests		(m_testCtx));
//	addChild(sparse::createTests				(m_testCtx));
//	addChild(tessellation::createTests			(m_testCtx));
//	addChild(rasterization::createTests			(m_testCtx));
//	addChild(clipping::createTests				(m_testCtx));
//	addChild(FragmentOperations::createTests	(m_testCtx));
//	addChild(texture::createTests				(m_testCtx));
//	addChild(geometry::createTests				(m_testCtx));
//	addChild(robustness::createTests			(m_testCtx));
//	addChild(MultiView::createTests				(m_testCtx));
//	addChild(subgroups::createTests				(m_testCtx));
//	addChild(ycbcr::createTests					(m_testCtx));
//	addChild(ProtectedMem::createTests			(m_testCtx));
//	addChild(DeviceGroup::createTests			(m_testCtx));
//	addChild(MemoryModel::createTests			(m_testCtx));
//	addChild(conditional::createTests			(m_testCtx));
//	addChild(cts_amber::createGraphicsFuzzTests	(m_testCtx));
//	addChild(imageless::createTests				(m_testCtx));
//	addChild(TransformFeedback::createTests		(m_testCtx));
//	addChild(DescriptorIndexing::createTests	(m_testCtx));
//	addChild(FragmentShaderInterlock::createTests(m_testCtx));
//	addChild(modifiers::createTests				(m_testCtx));
//	addChild(RayTracing::createTests			(m_testCtx));
//	addChild(RayQuery::createTests				(m_testCtx));
}

#endif // CTS_USES_VULKANSC

} // vkt
