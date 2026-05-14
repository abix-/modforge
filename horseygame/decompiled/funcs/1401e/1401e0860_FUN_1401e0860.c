// Address: 0x1401e0860
// Ghidra name: FUN_1401e0860
// ============ 0x1401e0860 FUN_1401e0860 (size=226) ============


undefined8 FUN_1401e0860(longlong *param_1,char *param_2)



{

  undefined4 uVar1;

  int iVar2;

  undefined8 uVar3;

  

  if ((*param_2 != '\0') && (*(longlong *)(param_2 + 0x20) != 0)) {

    if (*(longlong *)(param_2 + 0x18) == 0) {

      uVar1 = FUN_1401e0110(*(undefined4 *)(param_2 + 0x10));

      iVar2 = (**(code **)(*param_1 + 0xb8))

                        (param_1,*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),1,

                         *(undefined4 *)(param_2 + 0xc),uVar1,0,param_2 + 0x18,0);

      if (iVar2 < 0) {

        uVar3 = FUN_1401df290("CreateTexture(D3DPOOL_DEFAULT)",iVar2);

        return uVar3;

      }

    }

    iVar2 = (**(code **)(*param_1 + 0xf8))

                      (param_1,*(undefined8 *)(param_2 + 0x20),*(undefined8 *)(param_2 + 0x18));

    if (iVar2 < 0) {

      uVar3 = FUN_1401df290("UpdateTexture()",iVar2);

      return uVar3;

    }

    *param_2 = '\0';

  }

  return 1;

}




