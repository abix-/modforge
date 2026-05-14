// Address: 0x1401dcf20
// Ghidra name: FUN_1401dcf20
// ============ 0x1401dcf20 FUN_1401dcf20 (size=179) ============


ulonglong FUN_1401dcf20(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  longlong lVar3;

  ulonglong uVar4;

  longlong lVar5;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  lVar3 = FUN_1401841a0(1,0x38);

  uVar4 = 0;

  if (lVar3 != 0) {

    *(longlong *)(param_2 + 0x10) = lVar3;

    cVar2 = FUN_1401dd240(*(undefined8 *)(lVar1 + 0x10),lVar3,0,0x16362004,0x15,0x100,1);

    if (cVar2 != '\0') {

      lVar5 = 0;

      if (*(longlong *)(lVar1 + 0x198) != 0) {

        *(longlong *)(lVar3 + 0x30) = *(longlong *)(lVar1 + 0x198);

        lVar5 = *(longlong *)(lVar1 + 0x198);

        *(longlong *)(lVar5 + 0x28) = lVar3;

      }

      *(longlong *)(lVar1 + 0x198) = lVar3;

      return CONCAT71((int7)((ulonglong)lVar5 >> 8),1);

    }

    uVar4 = FUN_1401841e0(lVar3);

  }

  return uVar4 & 0xffffffffffffff00;

}




