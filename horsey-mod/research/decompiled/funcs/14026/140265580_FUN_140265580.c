// Address: 0x140265580
// Ghidra name: FUN_140265580
// ============ 0x140265580 FUN_140265580 (size=143) ============


undefined8 FUN_140265580(undefined8 *param_1,longlong param_2,char *param_3,int param_4)



{

  undefined8 uVar1;

  ulonglong uVar2;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined1 local_18;

  

  uVar1 = 0;

  local_18 = 0;

  local_38 = 0;

  uStack_30 = 0;

  local_28 = 0;

  uStack_20 = 0;

  if (1 < param_4) {

    if (*param_3 != '\x04') {

      FUN_14012e080(7,"GIP: Extended message type %02x",*param_3);

      return 0;

    }

    if ((param_3[1] == '\0') && ((*(byte *)(param_2 + 1) & 7) == 0)) {

      uVar2 = (longlong)param_4 - 2;

      if (0x20 < uVar2) {

        uVar2 = 0x20;

      }

      FUN_1402f8e20(&local_38,param_3 + 2,uVar2);

      FUN_140208490(*(undefined8 *)*param_1,&local_38);

    }

    uVar1 = 1;

  }

  return uVar1;

}




