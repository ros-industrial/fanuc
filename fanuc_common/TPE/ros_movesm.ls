/PROG  ROS_MOVESM
/ATTR
OWNER		= MNEDITOR;
COMMENT		= "ROS-I MoveSM";
PROG_SIZE	= 434;
CREATE		= DATE 12-10-02  TIME 12:08:46;
MODIFIED	= DATE 12-10-02  TIME 12:08:46;
FILE_NAME	= ;
VERSION		= 0;
LINE_COUNT	= 24;
MEMORY_SIZE	= 862;
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
   2:  !Not busy ;
   3:  F[2]=(OFF) ;
   4:   ;
   5:  LBL[1] ;
   6:   ;
   7:  !Wait for new pos from relay ;
   8:  WAIT (F[1])    ;
   9:   ;
  10:  !Signal busy ;
  11:  F[2]=(ON) ;
  12:   ;
  13:  !Copy it to temp p-reg ;
  14:  PR[2]=PR[1]    ;
  15:   ;
  16:  !Not busy ;
  17:  F[1]=(OFF) ;
  18:  F[2]=(OFF) ;
  19:   ;
  20:  !Perform actual move ;
  21:J PR[2] R[1]% CNT R[2]    ;
  22:   ;
  23:  !Repeat ;
  24:  JMP LBL[1] ;
/POS
/END
