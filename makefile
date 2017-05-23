###########################################################################
#
# 5/Aug/04: The /usr/lib/gcc-lib/i386-redhat-linux/2.96/libg2c.a library
#           is needed for the Fortran Interface. If this is used the 
#           mainAnalysis.o during linking must be BEFORE the -lg2c    --SP
#
# 3/Apr/05: Defined some static rules to simplify handling and output --LF
#
###########################################################################

# Root variables
ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs) -lMinuit  -lRooFit -lRooStats -lRooFitCore -lFoam -lHistFactory -lXMLParser 
#-lRooFit -lRooStats 
#-lg2c  
#FORTRANLIBS  := -L../lib/ -L/cern/pro/lib 
#-lkernlib

# Programs
CXX          = g++
CXXFLAGS     = -g -Wall -fPIC -Wno-deprecated 
LDFLAGS      = -g 
SOFLAGS      = -shared 

# Local Includes
INCDIR       = -IMain
INCDIR      += -IDataObject
INCDIR      += -IAnalysisTools
INCDIR      += -Isrc

# Direct to make the directories with the sources:
VPATH  = ./lib / ./bin ./src ./aux
VPATH += ./Main ./DataObject ./AnalysisTools

# Assign or Add variables
CXXFLAGS    += $(ROOTCFLAGS)
CXXFLAGS    += $(INCDIR)
LIBS        += $(ROOTLIBS)

# Data
CXXSRCS     +=  RecObject.cc DC2true.cc
CXXSRCS     +=  EG_Calo.cc EG_CaloTrack.cc EG_Track.cc
CXXSRCS     +=  RecMuons.cc
#CXXSRCS     +=  RecVtx.cc RecJet.cc RecTracks.cc 
#                RecMuMuons.cc RecIdMuons.cc TrueMuons.cc 

# Analysis tools and main code
CXXSRCS     +=  Particle.cc ArgManager.cc Analysis.cc
CXXSRCS     +=  HtoZZAnalysis.cc
#CXXSRCS     +=  TrackingUtils.cc
#CXXSRCS     +=  ConstraintFits.cc

CXXOBJS      = $(CXXSRCS:.cc=.o)
GARBAGE      = $(CXXOBJS) libana.so *~ lib/*.so lib/*.o ./*/*.o


############################################################################
# Build main.c compiling only the first prereq: ($<) means main.c
############################################################################
analysis : analysis.o output.o
signal_analysis : signal_analysis.o output.o
diphoton : diphoton.o output.o
singlephoton : singlephoton.o output.o
diphoton_noloosecut : diphoton_noloosecut.o output.o
singlephoton_noloosecut : singlephoton_noloosecut.o output.o

############################################################################
# General rules. The first two need not be specified due to implicit rules, 
# but redefined for the "echo"
############################################################################
%.o : %.cc %.hh
	@echo "compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< 

%.o : %.cc 
	@echo "compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< 

%    : %.o
	@echo "compiling and linking $@"
	@$(CXX) $(LDFLAGS) $^ \
	        $(FORTRANLIBS) $(ROOTLIBS)  -o $@
	@if [ `ls | grep "\.so"$ | wc -l` != 0 ]; then mv *.so lib/; fi
	@if [ `ls | grep "\.o"$  | wc -l` != 0 ]; then mv *.o  lib/; fi
	@mv $@ bin/

############################################################################
# Build libana.so compiling all prerequisites: ($^) means CXXOBJS 
# ($@) means the target libana.so
############################################################################
libana.so : $(CXXOBJS) 
	@echo "linking libana.so"
	@$(CXX) $(SOFLAGS) $(LDFLAGS) $^ -o $@


############################################################################
# Phony rules (no prerequisites)
############################################################################

.PHONY: clean cln print xemacs backup clnPM

clean :
	@rm -f $(GARBAGE)

cln :
	@rm -f *~ *.o */*~

clnPM :
	@rm -f usePM pairManager.o SingleElectron.o */*~

print :
	@echo compiler  : $(CXX)
	@echo c++ srcs  : $(CXXSRCS)
	@echo c++ objs  : $(CXXOBJS)
	@echo c++ flags : $(CXXFLAGS)
	@echo libs      : $(LIBS)
	@echo so flags  : $(SOFLAGS)
	@echo rootlibs  : $(ROOTLIBS)

xemacs:
	@xemacs -geometry 160x70+0+100 \
                ${PWD}/*/HtoZZAnalysis.*[hc] \
                ${PWD}/*/Particle.*[hc] &
	@xemacs -geometry 160x70+300+80 \
	        ${PWD}/*/Analysis.*[hc] &
	@xemacs -geometry 160x70+600+100 \
                ${PWD}/*/EG_CaloTrack*[hc] \
                ${PWD}/*/RecObject*[hc] &
#                ${PWD}/*/*Muon*[hc] \
	@xemacs -geometry 60x12+0+60 ${PWD}/TDR.par &

