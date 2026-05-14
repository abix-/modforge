// Address: 0x140183200
// Ghidra name: FUN_140183200
// ============ 0x140183200 FUN_140183200 (size=139) ============


void FUN_140183200(int param_1,ulonglong param_2,char param_3)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined8 uVar3;

  

  if (param_3 == '\0') {

    FUN_1401829a0(DAT_1403fcaf0,param_1,param_2 & 0xffff);

  }

  else {

    lVar2 = FUN_1401831d0(0);

    uVar3 = 0;

    if (((((DAT_1403fcaf8 & 2) != 0) && (lVar2 != 0)) && (*(char *)(lVar2 + 0x16) != '\0')) &&

       (uVar3 = 0, param_1 - 0x1eU < 10)) {

      uVar3 = 3;

    }

    uVar1 = FUN_1401829a0(lVar2,param_1,uVar3);

    if ((DAT_1403fcaf8 & 1) != 0) {

      FUN_140182f10(uVar1,(byte)(param_2 >> 8) >> 4 & 1);

      return;

    }

  }

  return;

}




