// Address: 0x140267d00
// Ghidra name: FUN_140267d00
// ============ 0x140267d00 FUN_140267d00 (size=316) ============


bool FUN_140267d00(longlong *param_1,byte param_2,undefined1 param_3,undefined1 param_4,

                  undefined8 param_5,int param_6,char param_7,undefined8 param_8,undefined8 param_9)



{

  char cVar1;

  int iVar2;

  bool bVar3;

  byte local_818 [2064];

  

  local_818[0] = param_2;

  local_818[1] = param_3;

  local_818[2] = param_4;

  FUN_1402f94c0(local_818 + 3,0,0x803);

  if (param_6 < 0) {

    FUN_14012e2e0(7,"GIP: Invalid message length %d",param_6);

LAB_140267d5a:

    bVar3 = false;

  }

  else {

    if (*(int *)(&DAT_14037df70 + (ulonglong)(param_2 >> 5) * 4) < param_6) {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(7,

                    "Attempted to send a message that requires fragmenting, which is not yet supported."

                   );

    }

    iVar2 = FUN_140265280((longlong)param_6,local_818 + 3,0x803);

    if (0 < param_6) {

      FUN_1402f8e20(local_818 + (iVar2 + 3),param_5,(longlong)param_6);

    }

    param_6 = param_6 + iVar2 + 3;

    if (param_7 == '\0') {

      iVar2 = FUN_140195730(*(undefined8 *)(*param_1 + 0x80),local_818,(longlong)param_6);

    }

    else {

      cVar1 = FUN_1402843f0();

      if (cVar1 == '\0') goto LAB_140267d5a;

      iVar2 = FUN_140284670(*param_1,local_818,param_6,param_8,param_9);

    }

    bVar3 = iVar2 == param_6;

  }

  return bVar3;

}




