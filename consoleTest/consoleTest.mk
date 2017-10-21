##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=consoleTest
ConfigurationName      :=Debug
<<<<<<< .mine
WorkspacePath          :=F:/Users/Awesome/chelDoc
ProjectPath            :=F:/Users/Awesome/chelDoc/consoleTest
=======
WorkspacePath          :=C:/Users/Chel/source/chelDoc
ProjectPath            :=C:/Users/Chel/source/chelDoc/consoleTest
>>>>>>> .r11
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
<<<<<<< .mine
User                   :=Awesome
Date                   :=17/10/2017
CodeLitePath           :="F:/Program Files/CodeLite"
LinkerName             :=F:/MinGW_GCC_7.1/bin/g++.exe
SharedObjectLinkerName :=F:/MinGW_GCC_7.1/bin/g++.exe -shared -fPIC
=======
User                   :=Chel
Date                   :=20/10/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW_GCC_7.1/mingw32/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW_GCC_7.1/mingw32/bin/g++.exe -shared -fPIC
>>>>>>> .r11
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
ObjectsFileList        :="consoleTest.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
<<<<<<< .mine
RcCompilerName         :=F:/MinGW_GCC_7.1/bin/windres.exe
=======
RcCompilerName         :=C:/MinGW_GCC_7.1/mingw32/bin/windres.exe
>>>>>>> .r11
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)../chelTypes 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)chelTypes $(LibrarySwitch)chelMath 
ArLibs                 :=  "chelTypes.dll" "chelMath.dll" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../chelTypes/Debug $(LibraryPathSwitch)../chelMath/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
<<<<<<< .mine
AR       := F:/MinGW_GCC_7.1/bin/ar.exe rcu
CXX      := F:/MinGW_GCC_7.1/bin/g++.exe
CC       := F:/MinGW_GCC_7.1/bin/gcc.exe
=======
AR       := C:/MinGW_GCC_7.1/mingw32/bin/ar.exe rcu
CXX      := C:/MinGW_GCC_7.1/mingw32/bin/g++.exe
CC       := C:/MinGW_GCC_7.1/mingw32/bin/gcc.exe
>>>>>>> .r11
CXXFLAGS :=  -g -O0 -Wall -std=c++1z  -fconcepts  -D DEBUG $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
<<<<<<< .mine
AS       := F:/MinGW_GCC_7.1/bin/as.exe
=======
AS       := C:/MinGW_GCC_7.1/mingw32/bin/as.exe
>>>>>>> .r11


##
## User defined environment variables
##
<<<<<<< .mine
CodeLiteDir:=F:\Program Files\CodeLite
=======
CodeLiteDir:=C:\Program Files\CodeLite
>>>>>>> .r11
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



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
<<<<<<< .mine
	$(CXX) $(IncludePCH) $(SourceSwitch) "F:/Users/Awesome/chelDoc/consoleTest/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
=======
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chel/source/chelDoc/consoleTest/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
>>>>>>> .r11
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


