// Address: 0x140277070
// Ghidra name: FUN_140277070
// ============ 0x140277070 FUN_140277070 (size=251) ============


int FUN_140277070(longlong param_1,longlong param_2,int param_3)



{

  undefined1 uVar1;

  int iVar2;

  int iVar3;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined4 local_28;

  

  iVar3 = 0;

  iVar2 = -1;

  if (*(char *)(param_1 + 0x54) == '\0') {

    do {

      iVar2 = FUN_140193880(*(undefined8 *)(param_1 + 0x80),param_2,0x41);

      if (-1 < iVar2) {

        return iVar2;

      }

      thunk_FUN_140184480(500000);

      iVar3 = iVar3 + 1;

    } while (iVar3 < 0x32);

  }

  else {

    param_2 = param_2 + 1;

    if (0 < param_3) {

      param_3 = param_3 + -1;

      while (0 < param_3) {

        iVar2 = param_3;

        if (0x12 < param_3) {

          iVar2 = 0x12;

        }

        param_3 = param_3 - iVar2;

        local_28 = 0;

        uStack_30 = 0;

        local_38 = 3;

        uVar1 = FUN_140276ab0(iVar3,param_3 == 0);

        local_38._0_2_ = CONCAT11(uVar1,(undefined1)local_38);

        FUN_1402f8e20((longlong)&local_38 + 2,param_2,(longlong)iVar2);

        param_2 = param_2 + iVar2;

        iVar3 = iVar3 + 1;

        iVar2 = FUN_140193880(*(undefined8 *)(param_1 + 0x80),&local_38,0x14);

      }

    }

  }

  return iVar2;

}




