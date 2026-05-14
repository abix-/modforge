// Address: 0x140172630
// Ghidra name: FUN_140172630
// ============ 0x140172630 FUN_140172630 (size=104) ============


byte FUN_140172630(longlong param_1,longlong *param_2)



{

  uint uVar1;

  longlong lVar2;

  byte bVar3;

  

  lVar2 = *(longlong *)(param_1 + 0x1a8);

  bVar3 = (byte)(*(uint *)(param_1 + 0x48) >> 9) & 1;

  uVar1 = *(uint *)(lVar2 + 0x48);

  while (((uVar1 & 0xc0000) != 0 &&

         (((*(int *)(lVar2 + 0x48) < 0 || (*(char *)(lVar2 + 0x109) != '\0')) ||

          (*(char *)(lVar2 + 0x10f) != '\0'))))) {

    lVar2 = *(longlong *)(lVar2 + 0x1a8);

    if (bVar3 == 0) {

      bVar3 = (byte)(*(uint *)(lVar2 + 0x48) >> 9) & 1;

    }

    uVar1 = *(uint *)(lVar2 + 0x48);

  }

  *param_2 = lVar2;

  return bVar3;

}




