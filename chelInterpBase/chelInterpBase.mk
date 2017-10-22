##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=chelInterpBase
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Chel/source/chelDoc
ProjectPath            :=C:/Users/Chel/source/chelDoc/chelInterpBase
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
ObjectsFileList        :="chelInterpBase.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW_GCC_7.1/mingw32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)chelTypes $(LibrarySwitch)chelMath $(LibrarySwitch)chelDocBase 
ArLibs                 :=  "chelTypes.dll" "chelMath.dll" "chelDocBase.dll" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../chelTypes/Debug $(LibraryPathSwitch)../chelMath/Debug $(LibraryPathSwitch)../chelDocBase/Debug 

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
Objects0=$(IntermediateDirectory)/IInterp_IInterp.cpp$(ObjectSuffix) 



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
	@echo rebuilt > "C:\Users\Chel\source\chelDoc/.build-debug/chelInterpBase"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/IInterp_IInterp.cpp$(ObjectSuffix): IInterp/IInterp.cpp $(IntermediateDirectory)/IInterp_IInterp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelInterpBase/IInterp/IInterp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IInterp_IInterp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IInterp_IInterp.cpp$(DependSuffix): IInterp/IInterp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IInterp_IInterp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IInterp_IInterp.cpp$(DependSuffix) -MM IInterp/IInterp.cpp

$(IntermediateDirectory)/IInterp_IInterp.cpp$(PreprocessSuffix): IInterp/IInterp.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IInterp_IInterp.cpp$(PreprocessSuffix) IInterp/IInterp.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


