// superclass patch types first
#import "QCThreadPatch.h"

#import "QCEventPatch.h"
#import "QCFakePatch.h"
#import "QCNetworkPatch.h"
#import "QCOSCPatch.h"
#import "QCPlugInPatch.h"
#import "QCProgrammablePatch.h"
#import "QCRenderingPatch.h"
#import "QCRunLoopPatch.h"

#import "QCDownloadPatch.h"


// then actual patches
#import "QCAnchorPosition.h"
#import "QCAppleRemote.h"
#import "QCBillboard.h"
#import "QCBillboardUI.h"
#import "QCBonjourServices.h"
#import "QCBonjourServicesUI.h"
#import "QCCamera.h"
#import "QCClear.h"
#import "QCClearUI.h"
#import "QCClock.h"
#import "QCColorFromComponents.h"
#import "QCColorMask.h"
#import "QCColorMixer.h"
#import "QCColorToComponents.h"
#import "QCColorTransform.h"
#import "QCConditional.h"
#import "QCCore3DLoader.h"
#import "QCCore3DLoaderUI.h"
#import "QCCounter.h"
#import "QCCube.h"
#import "QCDateFormatter.h"
#import "QCDateFormatterUI.h"
#import "QCDemultiplexer.h"
#import "QCDemultiplexerUI.h"
#import "QCDifferentialValue.h"
#import "QCDirectoryScanner.h"
#import "QCDirectoryScannerUI.h"
#import "QCExpression.h"
#import "QCExpressionUI.h"
#import "QCFlameImage.h"
#import "QCFlameImageUI.h"
#import "QCFog.h"
#import "QCFPSDisplay.h"
#import "QCGLSLShader.h"
#import "QCGLSLShaderUI.h"
#import "QCGradient.h"
#import "QCGrid.h"
#import "QCHIDInput.h"
#import "QCHIDInputUI.h"
#import "QCHostInfo.h"
#import "QCHotZone.h"
#import "QCImageAccumulator.h"
#import "QCImageAccumulatorUI.h"
#import "QCImageColorMatchingProperties.h"
#import "QCImageCrop.h"
#import "QCImageDimensions.h"
#import "QCImageDownloader.h"
#import "QCImageDownloaderUI.h"
#import "QCImageFilter.h"
#import "QCImageHistogram.h"
#import "QCImageInfo.h"
#import "QCImageKernel.h"
#import "QCImageKernelUI.h"
#import "QCImageLoader.h"
#import "QCImageLoaderUI.h"
#import "QCImageOrigin.h"
#import "QCImagePixel.h"
#import "QCImageResize.h"
#import "QCImageTexturingProperties.h"
#import "QCImageTransform.h"
#import "QCInfo.h"
#import "QCInterpolation.h"
#import "QCInterpolationUI.h"
#import "QCIterator.h"
#import "QCIteratorVariables.h"
#import "QCKeyboard.h"
#import "QCKeyboardTableView.h"
#import "QCKeyboardUI.h"
#import "QCLFO.h"
#import "QCLighting.h"
#import "QCLine.h"
#import "QCLines.h"
#import "QCLog.h"
#import "QCLogic.h"
#import "QCMath.h"
#import "QCMouse.h"
#import "QCMouseInteraction.h"
#import "QCMultiplexer.h"
#import "QCMultiplexerUI.h"
#import "QCNetworkBroadcaster.h"
#import "QCNetworkBroadcasterUI.h"
#import "QCNetworkPatchUI.h"
#import "QCNetworkReceiver.h"
#import "QCNetworkReceiverUI.h"
#import "QCNetworkSynchronizer.h"
#import "QCNetworkSynchronizerUI.h"
#import "QCNoise.h"
#import "QCNumberFormatter.h"
#import "QCNumberFormatterUI.h"
#import "QCNumericalFormatter.h"
#import "QCOpenGLInfo.h"
#import "QCOpenGLInfoUI.h"
#import "QCOSCBroadcaster.h"
#import "QCOSCBroadcasterUI.h"
#import "QCOSCPatchUI.h"
#import "QCOSCReceiver.h"
#import "QCOSCReceiverUI.h"
#import "QCParticleSystem.h"
#import "QCParticleSystemUI.h"
#import "QCPatchInfo.h"
#import "QCPatchRenderer.h"
#import "QCPatchRendererUI.h"
#import "QCPhysics.h"
#import "QCPhysicsEffect.h"
#import "QCPlasmaImage.h"
#import "QCPlasmaImageUI.h"
#import "QCProjection.h"
#import "QCPsychedelic.h"
#import "QCPsychedelicUI.h"
#import "QCPulse.h"
#import "QCQuadric.h"
#import "QCQuadricUI.h"
#import "QCQueue.h"
#import "QCRandom.h"
#import "QCRangeValue.h"
#import "QCRecursor.h"
#import "QCRenderInImage.h"
#import "QCRenderInImageUI.h"
#import "QCReplicator.h"
#import "QCRepositoryCompositions.h"
#import "QCRoundValue.h"
#import "QCSampleHold.h"
#import "QCScreenInfo.h"
#import "QCScreenInfoUI.h"
#import "QCSignal.h"
#import "QCSmooth.h"
#import "QCSplitter.h"
#import "QCSplitterUI.h"
#import "QCSpotlight.h"
#import "QCSprite.h"
#import "QCStringCase.h"
#import "QCStringCompare.h"
#import "QCStringComponents.h"
#import "QCStringFormat.h"
#import "QCStringLength.h"
#import "QCStringMD5.h"
#import "QCStringRange.h"
#import "QCStringReplace.h"
#import "QCStringTimecode.h"
#import "QCStringTruncate.h"
#import "QCStructureCount.h"
#import "QCStructureMember.h"
#import "QCStructureRange.h"
#import "QCStructureReverse.h"
#import "QCStructureSort.h"
#import "QCSystemTime.h"
#import "QCTablet.h"
#import "QCTeapot.h"
#import "QCTextImage.h"
#import "QCTextImageUI.h"
#import "QCTime.h"
#import "QCTimeLine.h"
#import "QCTimeLineEditorView.h"
#import "QCTimeLineLegendColorWell.h"
#import "QCTimeLineLegendTextField.h"
#import "QCTimeLineUI.h"
#import "QCTimeLineView.h"
#import "QCTimeLoop.h"
#import "QCTrackBall.h"
#import "QCTrackBallUI.h"
#import "QCWatcher.h"
#import "QCWatcherUI.h"
#import "QCXMLDownloader.h"

// SnowLeopard-only patches
#if MAC_OS_X_VERSION_MAX_ALLOWED >= 1060
#import "QCOpenCL.h"
#import "QCOpenCLConverter.h"
#import "QCOpenCLInfo.h"
#import "QCOpenCLUI.h"
#import "QCMeshCreator.h"
#import "QCMeshMaterialGetter.h"
#import "QCMeshMaterialSetter.h"
#import "QCMeshPropertyGetter.h"
#import "QCMeshPropertySetter.h"
#import "QCMeshRenderer.h"
#import "QCMeshTransform.h"

#endif