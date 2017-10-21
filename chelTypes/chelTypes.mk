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
Date                   :=20/10/2017
CodeLitePath           :="F:/Program Files/CodeLite"
LinkerName             :=F:/MinGW_GCC_7.1/bin/g++.exe
SharedObjectLinkerName :=F:/MinGW_GCC_7.1/bin/g++.exe -shared -fPIC
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
RcCompilerName         :=F:/MinGW_GCC_7.1/bin/windres.exe
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
AR       := F:/MinGW_GCC_7.1/bin/ar.exe rcu
CXX      := F:/MinGW_GCC_7.1/bin/g++.exe
CC       := F:/MinGW_GCC_7.1/bin/gcc.exe
CXXFLAGS :=  -g  -std=c++1z  -fconcepts  -D DEBUG $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := F:/MinGW_GCC_7.1/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=F:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/String_String.cpp$(ObjectSuffix) $(IntermediateDirectory)/String_Character.cpp$(ObjectSuffix) $(IntermediateDirectory)/String_CStringCase.cpp$(ObjectSuffix) $(IntermediateDirectory)/DebugTools_Assertions.cpp$(ObjectSuffix) $(IntermediateDirectory)/Globals_GArgs.cpp$(ObjectSuffix) $(IntermediateDirectory)/Fields_CBitfield.cpp$(ObjectSuffix) $(IntermediateDirectory)/ObjectFactory_CNameable.cpp$(ObjectSuffix) $(IntermediateDirectory)/ObjectFactory_GNameList.cpp$(ObjectSuffix) $(IntermediateDirectory)/FileIO_CStringScanner.cpp$(ObjectSuffix) $(IntermediateDirectory)/XML_CXMLTree.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Templates_Networks_CTree.cpp$(ObjectSuffix) $(IntermediateDirectory)/Console_ConVar_ConVar.cpp$(ObjectSuffix) 



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

$(IntermediateDirectory)/String_Character.cpp$(ObjectSuffix): String/Character.cpp $(IntermediateDirectory)/String_Character.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/String/Character.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/String_Character.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/String_Character.cpp$(DependSuffix): String/Character.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/String_Character.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/String_Character.cpp$(DependSuffix) -MM String/Character.cpp

$(IntermediateDirectory)/String_Character.cpp$(PreprocessSuffix): String/Character.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/String_Character.cpp$(PreprocessSuffix) String/Character.cpp

$(IntermediateDirectory)/String_CStringCase.cpp$(ObjectSuffix): String/CStringCase.cpp $(IntermediateDirectory)/String_CStringCase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/String/CStringCase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/String_CStringCase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/String_CStringCase.cpp$(DependSuffix): String/CStringCase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/String_CStringCase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/String_CStringCase.cpp$(DependSuffix) -MM String/CStringCase.cpp

$(IntermediateDirectory)/String_CStringCase.cpp$(PreprocessSuffix): String/CStringCase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/String_CStringCase.cpp$(PreprocessSuffix) String/CStringCase.cpp

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

$(IntermediateDirectory)/Fields_CBitfield.cpp$(ObjectSuffix): Fields/CBitfield.cpp $(IntermediateDirectory)/Fields_CBitfield.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/Fields/CBitfield.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Fields_CBitfield.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Fields_CBitfield.cpp$(DependSuffix): Fields/CBitfield.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Fields_CBitfield.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Fields_CBitfield.cpp$(DependSuffix) -MM Fields/CBitfield.cpp

$(IntermediateDirectory)/Fields_CBitfield.cpp$(PreprocessSuffix): Fields/CBitfield.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Fields_CBitfield.cpp$(PreprocessSuffix) Fields/CBitfield.cpp

$(IntermediateDirectory)/ObjectFactory_CNameable.cpp$(ObjectSuffix): ObjectFactory/CNameable.cpp $(IntermediateDirectory)/ObjectFactory_CNameable.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/ObjectFactory/CNameable.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ObjectFactory_CNameable.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ObjectFactory_CNameable.cpp$(DependSuffix): ObjectFactory/CNameable.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ObjectFactory_CNameable.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ObjectFactory_CNameable.cpp$(DependSuffix) -MM ObjectFactory/CNameable.cpp

$(IntermediateDirectory)/ObjectFactory_CNameable.cpp$(PreprocessSuffix): ObjectFactory/CNameable.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ObjectFactory_CNameable.cpp$(PreprocessSuffix) ObjectFactory/CNameable.cpp

$(IntermediateDirectory)/ObjectFactory_GNameList.cpp$(ObjectSuffix): ObjectFactory/GNameList.cpp $(IntermediateDirectory)/ObjectFactory_GNameList.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/ObjectFactory/GNameList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ObjectFactory_GNameList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ObjectFactory_GNameList.cpp$(DependSuffix): ObjectFactory/GNameList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ObjectFactory_GNameList.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ObjectFactory_GNameList.cpp$(DependSuffix) -MM ObjectFactory/GNameList.cpp

$(IntermediateDirectory)/ObjectFactory_GNameList.cpp$(PreprocessSuffix): ObjectFactory/GNameList.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ObjectFactory_GNameList.cpp$(PreprocessSuffix) ObjectFactory/GNameList.cpp

$(IntermediateDirectory)/FileIO_CStringScanner.cpp$(ObjectSuffix): FileIO/CStringScanner.cpp $(IntermediateDirectory)/FileIO_CStringScanner.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/FileIO/CStringScanner.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FileIO_CStringScanner.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FileIO_CStringScanner.cpp$(DependSuffix): FileIO/CStringScanner.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FileIO_CStringScanner.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FileIO_CStringScanner.cpp$(DependSuffix) -MM FileIO/CStringScanner.cpp

$(IntermediateDirectory)/FileIO_CStringScanner.cpp$(PreprocessSuffix): FileIO/CStringScanner.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FileIO_CStringScanner.cpp$(PreprocessSuffix) FileIO/CStringScanner.cpp

$(IntermediateDirectory)/XML_CXMLTree.cpp$(ObjectSuffix): XML/CXMLTree.cpp $(IntermediateDirectory)/XML_CXMLTree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/XML/CXMLTree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/XML_CXMLTree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/XML_CXMLTree.cpp$(DependSuffix): XML/CXMLTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/XML_CXMLTree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/XML_CXMLTree.cpp$(DependSuffix) -MM XML/CXMLTree.cpp

$(IntermediateDirectory)/XML_CXMLTree.cpp$(PreprocessSuffix): XML/CXMLTree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/XML_CXMLTree.cpp$(PreprocessSuffix) XML/CXMLTree.cpp

$(IntermediateDirectory)/Templates_Networks_CTree.cpp$(ObjectSuffix): Templates/Networks/CTree.cpp $(IntermediateDirectory)/Templates_Networks_CTree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/Templates/Networks/CTree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Templates_Networks_CTree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Templates_Networks_CTree.cpp$(DependSuffix): Templates/Networks/CTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Templates_Networks_CTree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Templates_Networks_CTree.cpp$(DependSuffix) -MM Templates/Networks/CTree.cpp

$(IntermediateDirectory)/Templates_Networks_CTree.cpp$(PreprocessSuffix): Templates/Networks/CTree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Templates_Networks_CTree.cpp$(PreprocessSuffix) Templates/Networks/CTree.cpp

$(IntermediateDirectory)/Console_ConVar_ConVar.cpp$(ObjectSuffix): Console/ConVar/ConVar.cpp $(IntermediateDirectory)/Console_ConVar_ConVar.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/chelTypes/Console/ConVar/ConVar.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Console_ConVar_ConVar.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Console_ConVar_ConVar.cpp$(DependSuffix): Console/ConVar/ConVar.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Console_ConVar_ConVar.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Console_ConVar_ConVar.cpp$(DependSuffix) -MM Console/ConVar/ConVar.cpp

$(IntermediateDirectory)/Console_ConVar_ConVar.cpp$(PreprocessSuffix): Console/ConVar/ConVar.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Console_ConVar_ConVar.cpp$(PreprocessSuffix) Console/ConVar/ConVar.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


