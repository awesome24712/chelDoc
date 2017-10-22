##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=chelInterp
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Chel/source/chelDoc
ProjectPath            :=C:/Users/Chel/source/chelDoc/chelInterp
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Chel
Date                   :=22/10/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW_GCC_7.1/mingw32/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW_GCC_7.1/mingw32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).dll
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="chelInterp.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW_GCC_7.1/mingw32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)chelTypes $(LibrarySwitch)chelMath $(LibrarySwitch)chelDocBase $(LibrarySwitch)chelInterpBase $(LibrarySwitch)chelProjectScanner 
ArLibs                 :=  "chelTypes.dll" "chelMath.dll" "chelDocBase.dll" "chelInterpBase.dll" "chelProjectScanner.dll" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../chelTypes/Debug $(LibraryPathSwitch)../chelMath/Debug $(LibraryPathSwitch)../chelDocBase/Debug $(LibraryPathSwitch)../chelInterpBase/Debug $(LibraryPathSwitch)../chelProjectScanner/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW_GCC_7.1/mingw32/bin/ar.exe rcu
CXX      := C:/MinGW_GCC_7.1/mingw32/bin/g++.exe
CC       := C:/MinGW_GCC_7.1/mingw32/bin/gcc.exe
CXXFLAGS :=  -g  -std=c++1z  -fconcepts  -D DEBUG $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW_GCC_7.1/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/DynamicLoad_NDynamicLoad.cpp$(ObjectSuffix) $(IntermediateDirectory)/Dispatcher_Dispatcher.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "C:\Users\Chel\source\chelDoc/.build-debug"
	@echo rebuilt > "C:\Users\Chel\source\chelDoc/.build-debug/chelInterp"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/DynamicLoad_NDynamicLoad.cpp$(ObjectSuffix): DynamicLoad/NDynamicLoad.cpp $(IntermediateDirectory)/DynamicLoad_NDynamicLoad.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelInterp/DynamicLoad/NDynamicLoad.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DynamicLoad_NDynamicLoad.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DynamicLoad_NDynamicLoad.cpp$(DependSuffix): DynamicLoad/NDynamicLoad.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DynamicLoad_NDynamicLoad.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DynamicLoad_NDynamicLoad.cpp$(DependSuffix) -MM DynamicLoad/NDynamicLoad.cpp

$(IntermediateDirectory)/DynamicLoad_NDynamicLoad.cpp$(PreprocessSuffix): DynamicLoad/NDynamicLoad.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DynamicLoad_NDynamicLoad.cpp$(PreprocessSuffix) DynamicLoad/NDynamicLoad.cpp

$(IntermediateDirectory)/Dispatcher_Dispatcher.cpp$(ObjectSuffix): Dispatcher/Dispatcher.cpp $(IntermediateDirectory)/Dispatcher_Dispatcher.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelInterp/Dispatcher/Dispatcher.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Dispatcher_Dispatcher.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Dispatcher_Dispatcher.cpp$(DependSuffix): Dispatcher/Dispatcher.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Dispatcher_Dispatcher.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Dispatcher_Dispatcher.cpp$(DependSuffix) -MM Dispatcher/Dispatcher.cpp

$(IntermediateDirectory)/Dispatcher_Dispatcher.cpp$(PreprocessSuffix): Dispatcher/Dispatcher.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Dispatcher_Dispatcher.cpp$(PreprocessSuffix) Dispatcher/Dispatcher.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


