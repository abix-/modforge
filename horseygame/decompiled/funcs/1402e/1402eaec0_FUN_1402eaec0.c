// Address: 0x1402eaec0
// Ghidra name: FUN_1402eaec0
// ============ 0x1402eaec0 FUN_1402eaec0 (size=139) ============


int FUN_1402eaec0(uint param_1,undefined4 param_2,undefined4 param_3,longlong param_4)



{

  byte *pbVar1;

  int iVar2;

  longlong lVar3;

  

  lVar3 = FUN_1402f4f90(param_1);

  if (lVar3 == -1) {

    *(undefined1 *)(param_4 + 0x30) = 1;

    *(undefined4 *)(param_4 + 0x2c) = 9;

  }

  else {

    iVar2 = FUN_1402eaffc(lVar3,param_2,param_3,param_4);

    if (iVar2 != -1) {

      pbVar1 = (byte *)((&DAT_1403ff160)[(longlong)(int)param_1 >> 6] + 0x38 +

                       (ulonglong)(param_1 & 0x3f) * 0x48);

      *pbVar1 = *pbVar1 & 0xfd;

      return iVar2;

    }

  }

  return -1;

}




