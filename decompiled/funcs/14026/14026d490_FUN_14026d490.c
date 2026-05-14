// Address: 0x14026d490
// Ghidra name: FUN_14026d490
// ============ 0x14026d490 FUN_14026d490 (size=206) ============


undefined8

FUN_14026d490(longlong param_1,undefined4 param_2,longlong param_3,byte param_4,char param_5)



{

  char cVar1;

  int iVar2;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined1 local_28;

  

  iVar2 = 1;

  if (0 < *(int *)(param_1 + 0x1c)) {

    do {

      if ((param_3 == 0) && (param_4 != 0)) {

        return 0;

      }

      if (0x2f < param_4) {

        return 0;

      }

      local_28 = 0;

      uStack_50 = 0;

      local_58 = (ulonglong)CONCAT11((char)param_2,0x80);

      local_48 = 0;

      uStack_40 = 0;

      local_38 = 0;

      uStack_30 = 0;

      if (param_3 != 0) {

        FUN_1402f8e20((longlong)&local_58 + 2,param_3,param_4);

      }

      cVar1 = FUN_14026d3d0(param_1,&local_58,0x31);

      if ((cVar1 != '\0') &&

         ((param_5 == '\0' || (cVar1 = FUN_14026c8f0(param_1,param_2), cVar1 != '\0')))) {

        return 1;

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 <= *(int *)(param_1 + 0x1c));

  }

  return 0;

}




