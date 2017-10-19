#include "SUSYxsec.hh"
map<string,double>DSinfo( int Run )
{
  // cross sections are shown in pb
  // https://twiki.cern.ch/twiki/bin/view/LHCPhysics/SUSYCrossSections8TeVgluglu

  int mg  = -9 , mx = -9, t = -9999; double xs = -9 , er = -9;

  if( Run ==404880 ) { mg = 1400  ; mx =  600  ; t =  100  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404881 ) { mg = 1400  ; mx =  600  ; t =  10  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404882 ) { mg = 1000  ; mx =  200  ; t =  2  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404883 ) { mg = 1000  ; mx =  600  ; t =  2  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404884 ) { mg = 1000  ; mx =  800  ; t =  2  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404885 ) { mg = 1400  ; mx =  200  ; t =  2  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404886 ) { mg = 1400  ; mx =  600  ; t =  2  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404887 ) { mg = 1400  ; mx =  1200  ; t =  2  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404888 ) { mg = 1800  ; mx =  200  ; t =  2  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404889 ) { mg = 1800  ; mx =  600  ; t =  2  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
 if( Run ==404890 ) { mg = 1800  ; mx =  1600  ; t =  2  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"];  }
if( Run ==404891 ) { mg = 1400  ; mx =  600  ; t =  0.5  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404892 ) { mg = 1000  ; mx =  200  ; t =  6  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404893 ) { mg = 1000  ; mx =  600  ; t =  6  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404894 ) { mg = 1000  ; mx =  800  ; t =  6  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404895 ) { mg = 1400  ; mx =  200  ; t =  6  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404896 ) { mg = 1400  ; mx =  600  ; t =  6  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404897 ) { mg = 1400  ; mx =  1200  ; t =  6  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404898 ) { mg = 1800  ; mx =  200  ; t =  6  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404899 ) { mg = 1800  ; mx =  600  ; t =  6  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }
if( Run ==404900 ) { mg = 1800  ; mx =  1600  ; t =  6  ;  xs = SUSYxsec(mg)["xs"] ; er = SUSYxsec(mg)["er"]; }



 map<string,double> result;
 result["mg"] = mg ;
 result["mx"] = mx ;
 result["t"] = t ;
 result["xs"] = xs ;
 result["er"] = er/100.0 ;

 return result;

}
