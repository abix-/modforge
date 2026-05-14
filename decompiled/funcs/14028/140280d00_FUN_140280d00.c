// Address: 0x140280d00
// Ghidra name: FUN_140280d00
// ============ 0x140280d00 FUN_140280d00 (size=354) ============


byte FUN_140280d00(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  ulonglong uVar3;

  longlong lVar4;

  undefined1 local_58 [64];

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  lVar4 = 0;

  uVar3 = FUN_140149350();

  if (0 < *(int *)(param_1 + 0x8c)) {

    lVar4 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  }

  if (((*(short *)(param_1 + 0x20) == 0x37d7) && (lVar4 != 0)) &&

     ((*(ulonglong *)(lVar1 + 0x30) == 0 || (*(ulonglong *)(lVar1 + 0x30) <= uVar3)))) {

    FUN_140282360(param_1,1);

    FUN_1402823d0(param_1);

    *(ulonglong *)(lVar1 + 0x30) = uVar3 + 30000;

  }

  iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_58,0x40,0);

  while (0 < iVar2) {

    *(ulonglong *)(lVar1 + 0x38) = uVar3;

    if (*(short *)(param_1 + 0x20) == 0x4b4) {

      FUN_140280fb0();

    }

    else {

      FUN_140280fd0(lVar4,lVar1,local_58,iVar2);

    }

    iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),local_58,0x40,0);

  }

  if ((*(short *)(param_1 + 0x20) == 0x37d7) && (*(longlong *)(lVar1 + 0x38) + 100U <= uVar3)) {

    *(ulonglong *)(lVar1 + 0x30) = uVar3;

  }

  if ((iVar2 < 0) && (0 < *(int *)(param_1 + 0x8c))) {

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

  return (byte)((uint)iVar2 >> 0x1f) ^ 1;

}




