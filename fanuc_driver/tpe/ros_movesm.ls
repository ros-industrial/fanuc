/PROG  ROS_MOVESM
/ATTR
OWNER		= MNEDITOR;
COMMENT		= "r3";
PROG_SIZE	= 548;
CREATE		= DATE 12-10-02  TIME 12:08:46;
MODIFIED	= DATE 19-10-08  TIME 20:04:26;
FILE_NAME	= ;
VERSION		= 0;
LINE_COUNT	= 25;
MEMORY_SIZE	= 952;
PROTECT		= READ_WRITE;
TCD:  STACK_SIZE	= 0,
      TASK_PRIORITY	= 50,
      TIME_SLICE	= 0,
      BUSY_LAMP_OFF	= 0,
      ABORT_REQUEST	= 0,
      PAUSE_REQUEST	= 0;
DEFAULT_GROUP	= 1,*,*,*,*;
CONTROL_CODE	= 00000000 00000000;
/MN
   1:   ;
   2:  !init: not rdy, no ack ;
   3:  F[1:ROS-I rdy]=(OFF) ;
   4:  F[2:ROS-I drdy]=(OFF) ;
   5:   ;
   6:  LBL[10] ;
   7:   ;
   8:  !we're ready for new point ;
   9:  F[1:ROS-I rdy]=(ON) ;
  10:   ;
  11:  !wait for relay ;
  12:  WAIT (F[2:ROS-I drdy])    ;
  13:   ;
  14:  !cache in temp preg ;
  15:  PR[2:ROS-I p cache]=PR[1:ROS-I pos]    ;
  16:   ;
  17:  !first rdy low, then ack copy ;
  18:  F[1:ROS-I rdy]=(OFF) ;
  19:  F[2:ROS-I drdy]=(OFF) ;
  20:   ;
  21:  !move to point ;
  22:J PR[2:ROS-I p cache] R[1:ROS-I spd]% CNT R[2:ROS-I cnt]    ;
  23:   ;
  24:  !done, repeat ;
  25:  JMP LBL[10] ;
/POS
/END
