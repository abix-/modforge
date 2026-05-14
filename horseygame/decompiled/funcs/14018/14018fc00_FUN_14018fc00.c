// Address: 0x14018fc00
// Ghidra name: FUN_14018fc00
// ============ 0x14018fc00 FUN_14018fc00 (size=168) ============


undefined4 FUN_14018fc00(ulonglong param_1,uint param_2,ushort *param_3,undefined8 param_4)



{

  int iVar1;

  UINT UVar2;

  ushort uVar3;

  bool bVar4;

  

  uVar3 = (byte)(param_1 >> 0x10) & 0xff7f;

  *(bool *)param_4 = (param_1 & 0x7f0000) == 0;

  if ((param_1 & 0x7f0000) == 0) {

    iVar1 = FUN_1401a99d0();

    UVar2 = 4;

    if (iVar1 != 0) {

      UVar2 = 0;

    }

    UVar2 = MapVirtualKeyW(param_2 & 0xffff,UVar2);

    bVar4 = (ushort)UVar2 == 0xe11d;

    uVar3 = (ushort)UVar2;

  }

  else {

    if (((ushort)(param_1 >> 0x10) >> 8 & 1) != 0) {

      uVar3 = uVar3 | 0xe000;

      goto LAB_14018fc71;

    }

    bVar4 = uVar3 == 0x45;

  }

  if (bVar4) {

    uVar3 = 0xe046;

  }

LAB_14018fc71:

  *param_3 = uVar3;

  return *(undefined4 *)

          (&DAT_140339bd0 +

          ((ulonglong)(-(uint)((uVar3 & 0xff00) != 0) & 0x80) | (ulonglong)(byte)uVar3) * 4);

}




