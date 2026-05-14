// Address: 0x140169c90
// Ghidra name: FUN_140169c90
// ============ 0x140169c90 FUN_140169c90 (size=161) ============


undefined4 FUN_140169c90(int param_1,int param_2)



{

  undefined4 uVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  int local_18;

  int local_14;

  

  iVar3 = 0;

  if (0 < *(int *)(DAT_1403fc410 + 0x328)) {

    lVar4 = 0;

    do {

      uVar1 = **(undefined4 **)(lVar4 + *(longlong *)(DAT_1403fc410 + 0x330));

      cVar2 = FUN_14016d280(uVar1,&local_18);

      if (((cVar2 != '\0') && (param_1 == local_18)) && (param_2 == local_14)) {

        return uVar1;

      }

      iVar3 = iVar3 + 1;

      lVar4 = lVar4 + 8;

    } while (iVar3 < *(int *)(DAT_1403fc410 + 0x328));

  }

  return 0;

}




