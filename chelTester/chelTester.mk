##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=chelTester
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Chel/source/chelDoc
ProjectPath            :=C:/Users/Chel/source/chelDoc/chelTester
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Chel
Date                   :=20/10/2017
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="chelTester.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW_GCC_7.1/mingw32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)chelTypes $(LibrarySwitch)chelMath 
ArLibs                 :=  "chelTypes.dll" "chelMath.dll" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../chelTypes/Debug $(LibraryPathSwitch)../chelMath/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW_GCC_7.1/mingw32/bin/ar.exe rcu
CXX      := C:/MinGW_GCC_7.1/mingw32/bin/g++.exe
CC       := C:/MinGW_GCC_7.1/mingw32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall  -fconcepts  -D DEBUG $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW_GCC_7.1/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/CTestCase.cpp$(ObjectSuffix) $(IntermediateDirectory)/Test_TestExample.cpp$(ObjectSuffix) $(IntermediateDirectory)/Test_Test_CHMap.cpp$(ObjectSuffix) $(IntermediateDirectory)/Test_Test_Map.cpp$(ObjectSuffix) $(IntermediateDirectory)/Test_Test_CXMLTree.cpp$(ObjectSuffix) 



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
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTester/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/CTestCase.cpp$(ObjectSuffix): CTestCase.cpp $(IntermediateDirectory)/CTestCase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTester/CTestCase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CTestCase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CTestCase.cpp$(DependSuffix): CTestCase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CTestCase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CTestCase.cpp$(DependSuffix) -MM CTestCase.cpp

$(IntermediateDirectory)/CTestCase.cpp$(PreprocessSuffix): CTestCase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CTestCase.cpp$(PreprocessSuffix) CTestCase.cpp

$(IntermediateDirectory)/Test_TestExample.cpp$(ObjectSuffix): Test/TestExample.cpp $(IntermediateDirectory)/Test_TestExample.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTester/Test/TestExample.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test_TestExample.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test_TestExample.cpp$(DependSuffix): Test/TestExample.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test_TestExample.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Test_TestExample.cpp$(DependSuffix) -MM Test/TestExample.cpp

$(IntermediateDirectory)/Test_TestExample.cpp$(PreprocessSuffix): Test/TestExample.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test_TestExample.cpp$(PreprocessSuffix) Test/TestExample.cpp

$(IntermediateDirectory)/Test_Test_CHMap.cpp$(ObjectSuffix): Test/Test_CHMap.cpp $(IntermediateDirectory)/Test_Test_CHMap.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTester/Test/Test_CHMap.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test_Test_CHMap.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test_Test_CHMap.cpp$(DependSuffix): Test/Test_CHMap.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test_Test_CHMap.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Test_Test_CHMap.cpp$(DependSuffix) -MM Test/Test_CHMap.cpp

$(IntermediateDirectory)/Test_Test_CHMap.cpp$(PreprocessSuffix): Test/Test_CHMap.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test_Test_CHMap.cpp$(PreprocessSuffix) Test/Test_CHMap.cpp

$(IntermediateDirectory)/Test_Test_Map.cpp$(ObjectSuffix): Test/Test_Map.cpp $(IntermediateDirectory)/Test_Test_Map.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTester/Test/Test_Map.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test_Test_Map.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test_Test_Map.cpp$(DependSuffix): Test/Test_Map.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test_Test_Map.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Test_Test_Map.cpp$(DependSuffix) -MM Test/Test_Map.cpp

$(IntermediateDirectory)/Test_Test_Map.cpp$(PreprocessSuffix): Test/Test_Map.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test_Test_Map.cpp$(PreprocessSuffix) Test/Test_Map.cpp

$(IntermediateDirectory)/Test_Test_CXMLTree.cpp$(ObjectSuffix): Test/Test_CXMLTree.cpp $(IntermediateDirectory)/Test_Test_CXMLTree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/chelTester/Test/Test_CXMLTree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test_Test_CXMLTree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test_Test_CXMLTree.cpp$(DependSuffix): Test/Test_CXMLTree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test_Test_CXMLTree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Test_Test_CXMLTree.cpp$(DependSuffix) -MM Test/Test_CXMLTree.cpp

$(IntermediateDirectory)/Test_Test_CXMLTree.cpp$(PreprocessSuffix): Test/Test_CXMLTree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test_Test_CXMLTree.cpp$(PreprocessSuffix) Test/Test_CXMLTree.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


