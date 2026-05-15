// Address: 0x140190560
// Ghidra name: thunk_FUN_1402e1d00
// ============ 0x140190560 thunk_FUN_1402e1d00 (size=5) ============


uint thunk_FUN_1402e1d00(uint param_1)



{

  bool bVar1;

  byte bVar2;

  uint uVar3;

  byte bVar4;

  uint uVar5;

  

  uVar3 = param_1 & 0x7fffffff;

  if (uVar3 < 0x4b000000) {

    if (uVar3 < 0x3f800000) {

      param_1 = param_1 & 0x80000000;

      if (0x3effffff < uVar3) {

        param_1 = param_1 | 0x3f800000;

      }

    }

    else {

      uVar5 = 0x96 - (uVar3 >> 0x17);

      bVar4 = (byte)uVar5;

      bVar2 = bVar4 & 0x1f;

      bVar1 = (uVar5 & 0x1f) != 0;

      param_1 = (param_1 >> bVar2) +

                (uint)(!bVar1 && 0x96 < uVar3 >> 0x17 || bVar1 && (param_1 >> bVar2 - 1 & 1) != 0)

                << (bVar4 & 0x1f);

    }

  }

  return param_1;

}




