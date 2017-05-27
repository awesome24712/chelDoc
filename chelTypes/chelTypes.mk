##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=chelTypes
ConfigurationName      :=Debug
WorkspacePath          :=F:/Users/Awesome/chelDoc
ProjectPath            :=F:/Users/Awesome/chelDoc/chelTypes
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Awesome
Date                   :=26/05/2017
CodeLitePath           :="F:/Program Files/CodeLite"
LinkerName             :=F:/MinGW/bin/g++.exe
SharedObjectLinkerName :=F:/MinGW/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="chelTypes.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=F:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := F:/MinGW/bin/ar.exe rcu
CXX      := F:/MinGW/bin/g++.exe
CC       := F:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g  -std=c++14  -D DEBUG $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := F:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=F:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/String_String.cpp$(ObjectSuffix) $(IntermediateDirectory)/DebugTools_Assertions.cpp$(ObjectSuffix) $(IntermediateDirectory)/Globals_GArgs.cpp$(ObjectSuffix) $(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "F:\Users\Awesome\chelDoc/.build-debug"
	@echo rebuilt > "F:\Users\Awesome\chelDoc/.build-debug/chelTypes"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/String_String.cpp$(ObjectSuffix): String/String.cpp $(IntermediateDirectory)/String_String.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/String/String.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/String_String.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/String_String.cpp$(DependSuffix): String/String.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/String_String.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/String_String.cpp$(DependSuffix) -MM String/String.cpp

$(IntermediateDirectory)/String_String.cpp$(PreprocessSuffix): String/String.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/String_String.cpp$(PreprocessSuffix) String/String.cpp

$(IntermediateDirectory)/DebugTools_Assertions.cpp$(ObjectSuffix): DebugTools/Assertions.cpp $(IntermediateDirectory)/DebugTools_Assertions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/DebugTools/Assertions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DebugTools_Assertions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DebugTools_Assertions.cpp$(DependSuffix): DebugTools/Assertions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DebugTools_Assertions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DebugTools_Assertions.cpp$(DependSuffix) -MM DebugTools/Assertions.cpp

$(IntermediateDirectory)/DebugTools_Assertions.cpp$(PreprocessSuffix): DebugTools/Assertions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DebugTools_Assertions.cpp$(PreprocessSuffix) DebugTools/Assertions.cpp

$(IntermediateDirectory)/Globals_GArgs.cpp$(ObjectSuffix): Globals/GArgs.cpp $(IntermediateDirectory)/Globals_GArgs.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/Globals/GArgs.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Globals_GArgs.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Globals_GArgs.cpp$(DependSuffix): Globals/GArgs.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Globals_GArgs.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Globals_GArgs.cpp$(DependSuffix) -MM Globals/GArgs.cpp

$(IntermediateDirectory)/Globals_GArgs.cpp$(PreprocessSuffix): Globals/GArgs.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Globals_GArgs.cpp$(PreprocessSuffix) Globals/GArgs.cpp

$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(ObjectSuffix): Templates/Fields/CBitfield.cpp $(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/Templates/Fields/CBitfield.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(DependSuffix): Templates/Fields/CBitfield.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(DependSuffix) -MM Templates/Fields/CBitfield.cpp

$(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(PreprocessSuffix): Templates/Fields/CBitfield.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Templates_Fields_CBitfield.cpp$(PreprocessSuffix) Templates/Fields/CBitfield.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


